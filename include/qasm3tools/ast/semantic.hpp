/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2021 softwareQ Inc. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file qasm3tools/ast/semantic.hpp
 * \brief Semantic analysis for syntax trees
 */

#pragma once

#include "ast.hpp"
#include "visitor.hpp"
#include "../utils/templates.hpp"

#include <unordered_map>

namespace qasm3tools {
namespace ast {

/**
 * \class qasm3tools::ast::SemanticError
 * \brief Exception class for semantic errors
 */
class SemanticError : public std::exception {
  public:
    SemanticError() noexcept = default;
    ~SemanticError() = default;
    const char* what() const noexcept { return "Error(s) occurred"; }
};

/**
 * \class qasm3tools::ast::ConstExprChecker
 * \brief Checks that const expressions are only defined in terms of other
 * const expressions, and that const variables are not assigned to. Also
 * replaces occurences of const expressions with their values, e.g.
 *   const int[32] n = 8;
 *   qubit[n-1] q;
 *   int[16] i = n;
 * becomes
 *   const int[32] n = 8;
 *   qubit[7] q;
 *   int[16] i = int[32](8);
 * \see qasm3tools::ast::Visitor
 */
class ConstExprChecker final : public Visitor {
    /**
     * \brief Data struct denoting a constant variable
     */
    struct ConstVar {
        Expr* value;
        ClassicalType* type;
    };

    /**
     * \brief Data struct denoting a for-loop variable
     */
    struct LoopVar {};

    /**
     * \brief Data struct for all other variable types
     */
    struct OtherVar {};

    /**
     * \brief OpenQASM types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using Type = std::variant<ConstVar, LoopVar, OtherVar>;

  public:
    bool run(Program& prog) {
        prog.accept(*this);
        return error_;
    }

    // Index identifiers
    void visit(RangeSlice& slice) override {
        visit_optional_expr(slice.start());
        visit_optional_expr(slice.step());
        visit_optional_expr(slice.stop());
    }
    void visit(ListSlice& slice) override {
        for (auto& index : slice.indices()) {
            index->accept(*this);
            if (replacement_expr_) {
                index = std::move(*replacement_expr_);
                replacement_expr_ = std::nullopt;
            }
        }
    }
    void visit(VarAccess& va) override {
        auto entry = lookup(va.var());
        if (!entry) {
            std::cerr << va.pos() << ": error : undefined identifier \""
                      << va.var() << "\"\n";
            error_ = true;
        } else {
            std::visit(utils::overloaded{
                           [this, &va](ConstVar&) {
                               std::cerr
                                   << va.pos()
                                   << ": error : constant variable \""
                                   << va.var()
                                   << "\" cannot be used as an argument\n";
                               error_ = true;
                           },
                           [this, &va](LoopVar&) {
                               std::cerr
                                   << va.pos() << ": error : loop variable \""
                                   << va.var()
                                   << "\" cannot be used as an argument\n";
                               error_ = true;
                           },
                           [](auto) {}},
                       *entry);
        }
        if (va.slice())
            (**va.slice()).accept(*this);
    }
    void visit(Concat& c) override {
        c.lreg().accept(*this);
        c.rreg().accept(*this);
    }
    // Types
    void visit(SingleDesignatorType& type) override {
        type.size().accept(*this);
        if (replacement_expr_) {
            type.set_size(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        auto size = evaluate(type.size());
        if (size) {
            if (*size <= 0) {
                std::cerr << type.pos()
                          << ": error : designator size must be positive\n";
                error_ = true;
            } else
                type.set_size(ptr<Expr>(new IntExpr({}, *size)));
        } else {
            std::cerr
                << type.pos()
                << ": error : designator size is not a compile-time constant\n";
            error_ = true;
        }
    }
    void visit(NoDesignatorType&) override {}
    void visit(BitType& type) override {
        visit_optional_expr(type.size());
        if (type.size()) {
            auto size = evaluate(**type.size());
            if (size) {
                if (*size <= 0) {
                    std::cerr << type.pos()
                              << ": error : classical register size must be "
                                 "positive\n";
                    error_ = true;
                } else
                    type.size() = ptr<Expr>(new IntExpr({}, *size));
            } else {
                std::cerr << type.pos()
                          << ": error : classical register size is not a "
                             "compile-time constant\n";
                error_ = true;
            }
        }
    }
    void visit(ComplexType& type) override { type.subtype().accept(*this); }
    void visit(QubitType& type) override {
        visit_optional_expr(type.size());
        if (type.size()) {
            auto size = evaluate(**type.size());
            if (size) {
                if (*size <= 0) {
                    std::cerr << type.pos()
                              << ": error : quantum register size must be "
                                 "positive\n";
                    error_ = true;
                } else
                    type.size() = ptr<Expr>(new IntExpr({}, *size));
            } else {
                std::cerr << type.pos()
                          << ": error : quantum register size is not a "
                             "compile-time constant\n";
                error_ = true;
            }
        }
    }
    // Expressions
    void visit(BExpr& exp) override {
        exp.lexp().accept(*this);
        if (replacement_expr_) {
            exp.set_lexp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        exp.rexp().accept(*this);
        if (replacement_expr_) {
            exp.set_rexp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(UExpr& exp) override {
        exp.subexp().accept(*this);
        if (replacement_expr_) {
            exp.set_subexp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(MathExpr& exp) override {
        for (int i = 0; i < exp.num_args(); i++) {
            exp.arg(i).accept(*this);
            if (replacement_expr_) {
                exp.set_arg(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
        }
    }
    void visit(CastExpr& exp) override {
        exp.type().accept(*this);
        exp.subexp().accept(*this);
        if (replacement_expr_) {
            exp.set_subexp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(FunctionCall& exp) override {
        for (int i = 0; i < exp.num_args(); i++) {
            exp.arg(i).accept(*this);
            if (replacement_expr_) {
                exp.set_arg(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
        }
        if (expect_const_) {
            std::cerr
                << exp.pos()
                << ": error : function call is not a constant expression\n";
            error_ = true;
        }
    }
    void visit(AccessExpr& exp) override {
        exp.exp().accept(*this);
        if (replacement_expr_) {
            exp.set_exp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        exp.index().accept(*this);
        if (replacement_expr_) {
            exp.set_index(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(ConstantExpr&) override {}
    void visit(IntExpr&) override {}
    void visit(RealExpr&) override {}
    void visit(ImagExpr&) override {}
    void visit(BoolExpr&) override {}
    void visit(VarExpr& exp) override {
        auto entry = lookup(exp.var());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<ConstVar>(*entry)) {
            auto var = std::get<ConstVar>(*entry);
            replacement_expr_ = ptr<Expr>(new CastExpr(
                {}, object::clone(*var.type), object::clone(*var.value)));
        } else if (expect_const_) {
            std::cerr << exp.pos() << ": error : identifier \"" << exp.var()
                      << "\" is not a constant expression\n";
            error_ = true;
        }
    }
    void visit(StringExpr&) override {}
    void visit(TimeExpr&) override {}
    void visit(DurationGateExpr&) override {}
    void visit(DurationBlockExpr& exp) override {
        push_scope();
        exp.block().accept(*this);
        pop_scope();
    }
    // Statement components
    void visit(QuantumMeasurement& msmt) override {
        msmt.q_arg().accept(*this);
    }
    void visit(ProgramBlock& block) override {
        block.foreach_stmt([this](ProgramBlockStmt& pbstmt) {
            std::visit([this](auto& stmt) { stmt->accept(*this); }, pbstmt);
        });
    }
    void visit(QuantumBlock& block) override {
        block.foreach_stmt([this](QuantumBlockStmt& qbstmt) {
            std::visit([this](auto& stmt) { stmt->accept(*this); }, qbstmt);
        });
    }
    // Statements
    void visit(MeasureStmt& stmt) override { stmt.measurement().accept(*this); }
    void visit(MeasureAsgnStmt& stmt) override {
        stmt.measurement().accept(*this);
        stmt.c_arg().accept(*this);
    }
    void visit(ExprStmt& stmt) override {
        stmt.exp().accept(*this);
        if (replacement_expr_) {
            stmt.set_exp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(ResetStmt& stmt) override {
        for (int i = 0; i < stmt.num_args(); i++)
            stmt.arg(i).accept(*this);
    }
    void visit(BarrierStmt& stmt) override {
        for (int i = 0; i < stmt.num_args(); i++)
            stmt.arg(i).accept(*this);
    }
    void visit(IfStmt& stmt) override {
        stmt.cond().accept(*this);
        if (replacement_expr_) {
            stmt.set_cond(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }

        push_scope();
        stmt.then().accept(*this);
        pop_scope();

        push_scope();
        stmt.els().accept(*this);
        pop_scope();
    }
    void visit(BreakStmt&) override {}
    void visit(ContinueStmt&) override {}
    void visit(ReturnStmt& stmt) override {
        std::visit(utils::overloaded{[this](ptr<QuantumMeasurement>& qm) {
                                         qm->accept(*this);
                                     },
                                     [this](ptr<Expr>& exp) {
                                         exp->accept(*this);
                                         if (replacement_expr_) {
                                             exp =
                                                 std::move(*replacement_expr_);
                                             replacement_expr_ = std::nullopt;
                                         }
                                     },
                                     [](auto) {}},
                   stmt.value());
    }
    void visit(EndStmt&) override {}
    void visit(AliasStmt& stmt) override {
        stmt.qreg().accept(*this);
        set(stmt.alias(), OtherVar{}, stmt.pos());
    }
    void visit(AssignmentStmt& stmt) override {
        auto entry = lookup(stmt.var());
        if (!entry) {
            std::cerr << stmt.pos() << ": error : undefined identifier \""
                      << stmt.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<ConstVar>(*entry)) {
            std::cerr << stmt.pos()
                      << ": error : cannot assign to constant variable \""
                      << stmt.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<LoopVar>(*entry)) {
            std::cerr << stmt.pos()
                      << ": error : cannot assign to loop variable \""
                      << stmt.var() << "\"\n";
            error_ = true;
        }
        visit_optional_expr(stmt.index());
        stmt.exp().accept(*this);
        if (replacement_expr_) {
            stmt.set_exp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(PragmaStmt& stmt) override {
        push_scope();
        stmt.foreach_stmt([this](Stmt& s) { s.accept(*this); });
        pop_scope();
    }
    // Gates
    void visit(CtrlModifier& mod) override {
        visit_optional_expr(mod.n());
        if (mod.n()) {
            auto n = evaluate(**mod.n());
            if (n) {
                if (*n <= 0) {
                    std::cerr << mod.pos()
                              << ": error : number of control bits must be "
                                 "positive\n";
                    error_ = true;
                } else
                    mod.n() = ptr<Expr>(new IntExpr({}, *n));
            } else {
                std::cerr << mod.pos()
                          << ": error : number of control bits is not a "
                             "compile-time constant\n";
                error_ = true;
            }
        }
    }
    void visit(InvModifier&) override {}
    void visit(PowModifier& mod) override {
        mod.r().accept(*this);
        if (replacement_expr_) {
            mod.set_r(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(UGate& gate) override {
        for (auto& mod : gate.modifiers())
            mod->accept(*this);
        gate.theta().accept(*this);
        if (replacement_expr_) {
            gate.set_theta(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        gate.phi().accept(*this);
        if (replacement_expr_) {
            gate.set_phi(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        gate.lambda().accept(*this);
        if (replacement_expr_) {
            gate.set_lambda(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        gate.foreach_qarg([this](IndexId& qarg) { qarg.accept(*this); });
    }
    void visit(GPhase& gate) override {
        for (auto& mod : gate.modifiers())
            mod->accept(*this);
        gate.gamma().accept(*this);
        if (replacement_expr_) {
            gate.set_gamma(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        gate.foreach_qarg([this](IndexId& qarg) { qarg.accept(*this); });
    }
    void visit(DeclaredGate& gate) override {
        for (auto& mod : gate.modifiers())
            mod->accept(*this);
        for (int i = 0; i < gate.num_cargs(); i++) {
            gate.carg(i).accept(*this);
            if (replacement_expr_) {
                gate.set_carg(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
        }
        gate.foreach_qarg([this](IndexId& qarg) { qarg.accept(*this); });
    }
    // Loops
    void visit(RangeSet& set) override {
        visit_optional_expr(set.start());
        visit_optional_expr(set.step());
        visit_optional_expr(set.stop());
    }
    void visit(ListSet& set) override {
        for (auto& index : set.indices()) {
            index->accept(*this);
            if (replacement_expr_) {
                index = std::move(*replacement_expr_);
                replacement_expr_ = std::nullopt;
            }
        }
    }
    void visit(VarSet& set) override {
        auto entry = lookup(set.var());
        if (!entry) {
            std::cerr << set.pos() << ": error : undefined identifier \""
                      << set.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<ConstVar>(*entry)) {
            std::cerr << set.pos()
                      << ": error : cannot loop over constant variable \""
                      << set.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<LoopVar>(*entry)) {
            std::cerr << set.pos()
                      << ": error : cannot loop over loop variable \""
                      << set.var() << "\"\n";
            error_ = true;
        }
    }
    void visit(ForStmt& stmt) override {
        stmt.index_set().accept(*this);

        push_scope();
        set(stmt.var(), LoopVar{}, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();
    }
    void visit(WhileStmt& stmt) override {
        stmt.cond().accept(*this);
        if (replacement_expr_) {
            stmt.set_cond(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }

        push_scope();
        stmt.body().accept(*this);
        pop_scope();
    }
    void visit(QuantumForStmt& stmt) override {
        stmt.index_set().accept(*this);

        push_scope();
        set(stmt.var(), LoopVar{}, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();
    }
    void visit(QuantumWhileStmt& stmt) override {
        stmt.cond().accept(*this);
        if (replacement_expr_) {
            stmt.set_cond(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }

        push_scope();
        stmt.body().accept(*this);
        pop_scope();
    }
    // Timing Statements
    void visit(DelayStmt& delay) override {
        for (int i = 0; i < delay.num_cargs(); i++) {
            delay.carg(i).accept(*this);
            if (replacement_expr_) {
                delay.set_carg(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
        }
        delay.duration().accept(*this);
        if (replacement_expr_) {
            delay.set_duration(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        for (int i = 0; i < delay.num_qargs(); i++) {
            delay.qarg(i).accept(*this);
        }
    }
    void visit(RotaryStmt& rotary) override {
        for (int i = 0; i < rotary.num_cargs(); i++) {
            rotary.carg(i).accept(*this);
            if (replacement_expr_) {
                rotary.set_carg(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
        }
        rotary.duration().accept(*this);
        if (replacement_expr_) {
            rotary.set_duration(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        for (int i = 0; i < rotary.num_qargs(); i++) {
            rotary.qarg(i).accept(*this);
        }
    }
    void visit(BoxStmt& box) override {
        visit_optional_expr(box.duration());
        push_scope();
        box.circuit().accept(*this);
        pop_scope();
    }
    // Declarations
    void visit(ClassicalParam& param) override {
        param.type().accept(*this);

        set(param.id(), OtherVar{}, param.pos());
    }
    void visit(QuantumParam& param) override {
        param.type().accept(*this);

        set(param.id(), OtherVar{}, param.pos());
    }
    void visit(SubroutineDecl& decl) override {
        push_scope();

        for (auto& param : decl.params()) {
            param->accept(*this);
        }

        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        decl.body().accept(*this);

        pop_scope();

        set(decl.id(), OtherVar{}, decl.pos());
    }
    void visit(ExternDecl& decl) override {
        for (auto& type : decl.param_types()) {
            type->accept(*this);
        }

        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        set(decl.id(), OtherVar{}, decl.pos());
    }
    void visit(GateDecl& decl) override {
        push_scope();

        for (const ast::symbol& param : decl.c_params()) {
            set(param, OtherVar{}, decl.pos());
        }
        for (const ast::symbol& param : decl.q_params()) {
            set(param, OtherVar{}, decl.pos());
        }
        decl.body().accept(*this);

        pop_scope();

        set(decl.id(), OtherVar{}, decl.pos());
    }
    void visit(QuantumDecl& decl) override {
        decl.type().accept(*this);
        set(decl.id(), OtherVar{}, decl.pos());
    }
    void visit(ClassicalDecl& decl) override {
        if (decl.is_const()) {
            expect_const_ = true;
            decl.type().accept(*this);
            if (!decl.equalsexp()) {
                std::cerr << decl.pos() << ": error : constant identifier \""
                          << decl.id() << "\" must be initialized\n";
                error_ = true;
                expect_const_ = false;
                return;
            }
            (**decl.equalsexp()).accept(*this);
            if (replacement_expr_) {
                decl.equalsexp() = std::move(replacement_expr_);
                replacement_expr_ = std::nullopt;
            }
            expect_const_ = false;
            set(decl.id(),
                ConstVar{decl.equalsexp()->get(), std::addressof(decl.type())},
                decl.pos());
        } else {
            decl.type().accept(*this);
            visit_optional_expr(decl.equalsexp());
            set(decl.id(), OtherVar{}, decl.pos());
        }
    }
    void visit(CalGrammarDecl&) override {}
    void visit(CalibrationDecl&) override {} // need to implement when finalized
    // Program
    void visit(Program& prog) override {
        push_scope();

        prog.foreach_stmt([this](ProgramStmt& pstmt) {
            std::visit([this](auto& stmt) { stmt->accept(*this); }, pstmt);
        });

        pop_scope();
    }

  private:
    bool error_ = false; ///< whether errors have occurred
    bool expect_const_ =
        false; ///< true when traversing a compile-time constant
    std::list<std::unordered_map<ast::symbol, Type>> symbol_table_{
        {}};                                    ///< a stack of symbol tables
    std::optional<ptr<Expr>> replacement_expr_; ///< replace current expression

    /**
     * \brief Enters a new scope
     */
    void push_scope() { symbol_table_.push_front({}); }

    /**
     * \brief Exits the current scope
     */
    void pop_scope() { symbol_table_.pop_front(); }

    /**
     * \brief Looks up a symbol in the symbol table
     *
     * Lookup checks in each symbol table going backwards up the enclosing
     * scopes.
     *
     * \param id Const reference to a symbol
     * \return The type of the symbol, if found
     */
    std::optional<Type> lookup(const ast::symbol& id) {
        for (auto& table : symbol_table_) {
            if (auto it = table.find(id); it != table.end()) {
                return it->second;
            }
        }
        return std::nullopt;
    }

    /**
     * \brief Looks up a symbol in the local scope.
     *
     * \param id Const reference to a symbol
     * \return The type of the symbol, if found
     */
    std::optional<Type> lookup_local(const ast::symbol& id) {
        if (!(symbol_table_.empty())) {
            const auto& local = symbol_table_.front();
            if (auto it = local.find(id); it != local.end()) {
                return it->second;
            }
        }
        return std::nullopt;
    }

    /**
     * \brief Assigns a symbol in the current scope if it has not yet been
     * defined in the current scope
     *
     * \param id Const reference to a symbol
     * \param typ The type of the symbol
     */
    void set(const ast::symbol& id, Type typ, const parser::Position& pos) {
        if (symbol_table_.empty())
            throw std::logic_error("No current symbol table!");
        else if (lookup_local(id)) {
            std::cerr << pos << ": error : redefinition of \"" << id << "\"\n";
            error_ = true;
            return;
        }

        symbol_table_.front()[id] = typ;
    }

    /**
     * \brief Visit an optional expression in the AST
     *
     * \param exp Reference to the optional expression
     */
    void visit_optional_expr(std::optional<ptr<Expr>>& exp) {
        if (exp) {
            (**exp).accept(*this);
            if (replacement_expr_) {
                exp = std::move(replacement_expr_);
                replacement_expr_ = std::nullopt;
            }
        }
    }

    /**
     * \class qasm3tools::ast::ConstExprChecker::ConstIntEvaluator
     * \brief Evaluates constant integer expressions
     * \see qasm3tools::ast::Visitor
     */
    class ConstIntEvaluator final : public Visitor {
        std::optional<int> value_ = std::nullopt; ///< return value
        bool cast_is_int_ = false; ///< whether explicit cast is to int or uint

      public:
        std::optional<int> evaluate(Expr& exp) {
            exp.accept(*this);
            return value_;
        }

        // Index identifiers
        void visit(RangeSlice&) override {}
        void visit(ListSlice&) override {}
        void visit(VarAccess&) override {}
        void visit(Concat&) override {}
        // Types
        void visit(SingleDesignatorType& type) override {
            cast_is_int_ =
                type.type() == SDType::Int || type.type() == SDType::Uint;
        }
        void visit(NoDesignatorType&) override { cast_is_int_ = false; }
        void visit(BitType&) override { cast_is_int_ = false; }
        void visit(ComplexType&) override { cast_is_int_ = false; }
        void visit(QubitType&) override {}
        // Expressions
        void visit(BExpr& exp) override {
            exp.lexp().accept(*this);
            auto lexp = value_;
            exp.rexp().accept(*this);
            auto rexp = value_;
            if (lexp && rexp) {
                switch (exp.op()) {
                    case BinaryOp::Plus:
                        value_ = *lexp + *rexp;
                        break;
                    case BinaryOp::Minus:
                        value_ = *lexp - *rexp;
                        break;
                    case BinaryOp::Times:
                        value_ = *lexp * *rexp;
                        break;
                    case BinaryOp::Divide:
                        value_ = *lexp / *rexp;
                        break;
                    case BinaryOp::Pow:
                        value_ = pow(*lexp, *rexp);
                        break;
                    default:
                        value_ = std::nullopt;
                }
            } else
                value_ = std::nullopt;
        }
        void visit(UExpr& exp) override {
            exp.subexp().accept(*this);
            auto subexp = value_;
            if (subexp && exp.op() == UnaryOp::Neg) {
                value_ = -(*subexp);
            } else
                value_ = std::nullopt;
        }
        void visit(MathExpr&) override { value_ = std::nullopt; }
        void visit(CastExpr& exp) override {
            exp.type().accept(*this);
            if (cast_is_int_) {
                exp.subexp().accept(*this);
            } else {
                value_ = std::nullopt;
            }
        }
        void visit(FunctionCall&) override { value_ = std::nullopt; }
        void visit(AccessExpr&) override { value_ = std::nullopt; }
        void visit(ConstantExpr&) override { value_ = std::nullopt; }
        void visit(IntExpr& exp) override { value_ = exp.value(); }
        void visit(RealExpr&) override { value_ = std::nullopt; }
        void visit(ImagExpr&) override { value_ = std::nullopt; }
        void visit(BoolExpr&) override { value_ = std::nullopt; }
        void visit(VarExpr& exp) override { value_ = std::nullopt; }
        void visit(StringExpr&) override { value_ = std::nullopt; }
        void visit(TimeExpr&) override { value_ = std::nullopt; }
        void visit(DurationGateExpr&) override { value_ = std::nullopt; }
        void visit(DurationBlockExpr&) override { value_ = std::nullopt; }
        // Statement components
        void visit(QuantumMeasurement&) override {}
        void visit(ProgramBlock&) override {}
        void visit(QuantumBlock&) override {}
        // Statements
        void visit(MeasureStmt&) override {}
        void visit(MeasureAsgnStmt&) override {}
        void visit(ExprStmt&) override {}
        void visit(ResetStmt&) override {}
        void visit(BarrierStmt&) override {}
        void visit(IfStmt&) override {}
        void visit(BreakStmt&) override {}
        void visit(ContinueStmt&) override {}
        void visit(ReturnStmt&) override {}
        void visit(EndStmt&) override {}
        void visit(AliasStmt&) override {}
        void visit(AssignmentStmt&) override {}
        void visit(PragmaStmt&) override {}
        // Gates
        void visit(CtrlModifier&) override {}
        void visit(InvModifier&) override {}
        void visit(PowModifier&) override {}
        void visit(UGate&) override {}
        void visit(GPhase&) override {}
        void visit(DeclaredGate&) override {}
        // Loops
        void visit(RangeSet&) override {}
        void visit(ListSet&) override {}
        void visit(VarSet&) override {}
        void visit(ForStmt&) override {}
        void visit(WhileStmt&) override {}
        void visit(QuantumForStmt&) override {}
        void visit(QuantumWhileStmt&) override {}
        // Timing Statements
        void visit(DelayStmt&) override {}
        void visit(RotaryStmt&) override {}
        void visit(BoxStmt&) override {}
        // Declarations
        void visit(ClassicalParam&) override {}
        void visit(QuantumParam&) override {}
        void visit(SubroutineDecl&) override {}
        void visit(ExternDecl&) override {}
        void visit(GateDecl&) override {}
        void visit(QuantumDecl&) override {}
        void visit(ClassicalDecl&) override {}
        void visit(CalGrammarDecl&) override {}
        void visit(CalibrationDecl&) override {}
        // Program
        void visit(Program&) override {}
    };

    /**
     * \brief Evaluate a constant integer expression
     *
     * \param exp Reference to the expression
     * \return Optional integer value
     */
    std::optional<int> evaluate(Expr& exp) {
        return ConstIntEvaluator().evaluate(exp);
    }
};

/**
 * \class qasm3tools::ast::TypeChecker
 * \brief Type checking
 * \see qasm3tools::ast::Visitor
 */
class TypeChecker final : public Visitor {
  public:
    /**
     * \brief Classical and quantum types
     */
    enum class DataType {
        None,
        Bool,
        Int,
        Float,
        Angle,
        ClassicalBit,
        ClassicalRegister,
        Duration,
        Complex,
        QuantumBit,
        QuantumRegister
    };

    /**
     * \brief Extraction operator overload for TypeChecker::DataType enum class
     *
     * \param os Output stream passed by reference
     * \param data_type TypeChecker::DataType enum class
     * \return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os,
                                    const DataType& data_type) {
        switch (data_type) {
            case DataType::None:
                os << "None";
                break;
            case DataType::Bool:
                os << "bool";
                break;
            case DataType::Int:
                os << "int";
                break;
            case DataType::Float:
                os << "float";
                break;
            case DataType::Angle:
                os << "angle";
                break;
            case DataType::ClassicalBit:
                os << "bit";
                break;
            case DataType::ClassicalRegister:
                os << "bit[n]";
                break;
            case DataType::Duration:
                os << "duration";
                break;
            case DataType::Complex:
                os << "complex";
                break;
            case DataType::QuantumBit:
                os << "qubit";
                break;
            case DataType::QuantumRegister:
                os << "qubit[n]";
                break;
        }
        return os;
    }

  private:
    // static member functions
    /**
     * \brief Checks whether a data type is a quantum type
     *
     * \return True if the data type is a quantum type, false otherwise
     */
    static bool is_quantum(const DataType& type) {
        return type == DataType::QuantumBit ||
               type == DataType::QuantumRegister;
    }

    /**
     * \brief Checks whether the source type is castable to the target type
     *
     * \return True if the source type is castable to the target type
     */
    static bool is_castable(const DataType& source, const DataType& target) {
        switch (source) {
            case DataType::Bool:
            case DataType::Int:
                switch (target) {
                    case DataType::Bool:
                    case DataType::Int:
                    case DataType::Float:
                    case DataType::ClassicalBit:
                    case DataType::ClassicalRegister:
                    case DataType::Complex:
                        return true;
                    default:
                        return false;
                }
            case DataType::Float:
                switch (target) {
                    case DataType::Bool:
                    case DataType::Int:
                    case DataType::Float:
                    case DataType::Angle:
                    case DataType::Complex:
                        return true;
                    default:
                        return false;
                }
            case DataType::Angle:
                switch (target) {
                    case DataType::Bool:
                    case DataType::Angle:
                    case DataType::ClassicalBit:
                    case DataType::ClassicalRegister:
                        return true;
                    default:
                        return false;
                }
            case DataType::ClassicalBit:
            case DataType::ClassicalRegister:
                switch (target) {
                    case DataType::Bool:
                    case DataType::Int:
                    case DataType::Angle:
                    case DataType::ClassicalBit:
                    case DataType::ClassicalRegister:
                        return true;
                    default:
                        return false;
                }
            case DataType::Duration:
                switch (target) {
                    case DataType::Duration:
                        return true;
                    default:
                        return false;
                }
            case DataType::Complex:
                switch (target) {
                    case DataType::Complex:
                        return true;
                    default:
                        return false;
                }
            case DataType::QuantumBit:
                switch (target) {
                    case DataType::QuantumBit:
                        return true;
                    default:
                        return false;
                }
            case DataType::QuantumRegister:
                switch (target) {
                    case DataType::QuantumRegister:
                        return true;
                    default:
                        return false;
                }
            default:
                return false;
        }
    }

    /**
     * \brief Checks whether two types are both numeric, and the first is
     * a subtype of the second.
     *
     * int is subtype of float and complex; float is subtype of complex.
     * int, float, complex, angle are subtypes of themselves.
     * Any other combinations return false.
     */
    static bool is_numeric_subtype(const DataType& sub, const DataType& sup) {
        if ((sub == DataType::Int &&
             (sup == DataType::Int || sup == DataType::Float ||
              sup == DataType::Complex)) ||
            (sub == DataType::Float &&
             (sup == DataType::Float || sup == DataType::Complex)) ||
            (sub == DataType::Complex && sup == DataType::Complex) ||
            (sub == DataType::Angle && sup == DataType::Angle))
            return true;
        return false;
    }

    /**
     * \brief Data struct for quantum gate types
     */
    struct GateType {
        int num_c_params;
        int num_q_params;
    };

    /**
     * \brief Data struct for subroutine types
     */
    struct SubroutineType {
        std::vector<DataType> param_types; ///< function signature
        DataType return_type;              ///< return type (None if no return)
    };

    /**
     * \brief OpenQASM types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using Type = std::variant<DataType, GateType, SubroutineType>;

  public:
    bool run(Program& prog) {
        prog.accept(*this);
        return error_;
    }

    // Index identifiers
    void visit(RangeSlice& slice) override {
        visit_optional_classical_expr(slice.start(), DataType::Int);
        visit_optional_classical_expr(slice.step(), DataType::Int);
        visit_optional_classical_expr(slice.stop(), DataType::Int);
    }
    void visit(ListSlice& slice) override {
        for (auto& index : slice.indices()) {
            visit_classical_expr(*index, DataType::Int);
        }
    }
    void visit(VarAccess& va) override {
        auto entry = lookup(va.var());
        if (!entry) {
            std::cerr << va.pos() << ": error : undefined identifier \""
                      << va.var() << "\"\n";
            error_ = true;
            type_ = DataType::None;
        } else if (std::holds_alternative<DataType>(*entry)) {
            switch (std::get<DataType>(*entry)) {
                case DataType::QuantumRegister:
                    if (va.slice()) {
                        (**va.slice()).accept(*this);
                        if ((**va.slice()).is_single_index())
                            type_ = DataType::QuantumBit;
                        else
                            type_ = DataType::QuantumRegister;
                    } else {
                        type_ = DataType::QuantumRegister;
                    }
                    return;
                case DataType::QuantumBit:
                    type_ = DataType::QuantumBit;
                    if (va.slice()) {
                        std::cerr << va.pos() << ": error : quantum bit \""
                                  << va.var() << "\" cannnot be indexed\n";
                        error_ = true;
                    }
                    return;
                case DataType::Angle: // apparently allowed (see ipe.qasm)
                case DataType::ClassicalRegister:
                    if (va.slice()) {
                        (**va.slice()).accept(*this);
                        if ((**va.slice()).is_single_index())
                            type_ = DataType::ClassicalBit;
                        else
                            type_ = DataType::ClassicalRegister;
                    } else {
                        type_ = DataType::ClassicalRegister;
                    }
                    return;
                case DataType::ClassicalBit:
                    type_ = DataType::ClassicalBit;
                    if (va.slice()) {
                        std::cerr << va.pos() << ": error : classical bit \""
                                  << va.var() << "\" cannnot be indexed\n";
                        error_ = true;
                    }
                    return;
                default:;
            }
        }
        std::cerr << va.pos() << ": error : identifier \"" << va.var()
                  << "\" is not a register or bit type\n";
        error_ = true;
        type_ = DataType::None;
    }
    void visit(Concat& c) override {
        c.lreg().accept(*this);
        auto t1 = type_;
        c.rreg().accept(*this);
        auto t2 = type_;
        if (t1 == DataType::None || t2 == DataType::None) {
            type_ = DataType::None;
        } else if ((t1 == DataType::ClassicalBit ||
                    t1 == DataType::ClassicalRegister) &&
                   (t2 == DataType::ClassicalBit ||
                    t2 == DataType::ClassicalRegister)) {
            type_ = DataType::ClassicalRegister;
        } else if (is_quantum(t1) && is_quantum(t2)) {
            type_ = DataType::QuantumRegister;
        } else {
            std::cerr << c.pos()
                      << ": error : concatenation of classical and quantum "
                         "register\n";
            error_ = true;
            type_ = DataType::None;
        }
    }
    // Types
    void visit(SingleDesignatorType& type) override {
        switch (type.type()) {
            case SDType::Int:
                type_ = DataType::Int;
                break;
            case SDType::Uint:
                type_ = DataType::Int;
                break;
            case SDType::Float:
                type_ = DataType::Float;
                break;
            case SDType::Angle:
                type_ = DataType::Angle;
                break;
        }
    }
    void visit(NoDesignatorType& type) override {
        switch (type.type()) {
            case NDType::Bool:
                type_ = DataType::Bool;
                break;
            case NDType::Duration:
                type_ = DataType::Duration;
                break;
            case NDType::Stretch:
                type_ = DataType::Duration;
                break;
        }
    }
    void visit(BitType& type) override {
        if (type.size()) {
            type_ = DataType::ClassicalRegister;
        } else {
            type_ = DataType::ClassicalBit;
        }
    }
    void visit(ComplexType& type) override { type_ = DataType::Complex; }
    void visit(QubitType& type) override {
        if (type.size()) {
            type_ = DataType::QuantumRegister;
        } else {
            type_ = DataType::QuantumBit;
        }
    }
    // Expressions
    void visit(BExpr& exp) override {
        exp.lexp().accept(*this);
        auto t1 = type_;
        exp.rexp().accept(*this);
        auto t2 = type_;
        switch (exp.op()) {
            case BinaryOp::LogicalOr:
            case BinaryOp::LogicalAnd:
                if (is_castable(t1, DataType::Bool) &&
                    is_castable(t2, DataType::Bool)) {
                    type_ = DataType::Bool;
                    return;
                }
                break;
            case BinaryOp::BitOr:
            case BinaryOp::XOr:
            case BinaryOp::BitAnd:
                if (is_castable(t1, DataType::ClassicalRegister) && t1 == t2) {
                    type_ = t1;
                    return;
                }
                break;
            case BinaryOp::EQ:
            case BinaryOp::NEQ:
            case BinaryOp::GT:
            case BinaryOp::LT:
            case BinaryOp::GTE:
            case BinaryOp::LTE:
                if ((is_castable(t1, DataType::ClassicalRegister) ||
                     t1 == DataType::Float) &&
                    (is_castable(t2, DataType::ClassicalRegister) ||
                     t2 == DataType::Float)) {
                    type_ = DataType::Bool;
                    return;
                }
                break;
            case BinaryOp::LeftBitShift:
            case BinaryOp::RightBitShift: {
                if (is_castable(t1, DataType::ClassicalRegister) &&
                    is_castable(t2, DataType::Int)) {
                    type_ = t1;
                    return;
                }
                break;
            }
            case BinaryOp::Plus:
            case BinaryOp::Minus:
                if (t1 == DataType::Duration && t2 == DataType::Duration) {
                    type_ = DataType::Duration;
                    return;
                } else if (is_numeric_subtype(t1, t2)) {
                    type_ = t2;
                    return;
                } else if (is_numeric_subtype(t2, t1)) {
                    type_ = t1;
                    return;
                }
                break;
            case BinaryOp::Times:
            case BinaryOp::Divide:
                if (t1 == DataType::Duration &&
                    is_numeric_subtype(t2, DataType::Float)) {
                    type_ = DataType::Duration;
                    return;
                } else if (exp.op() == BinaryOp::Times &&
                           t2 == DataType::Duration &&
                           is_numeric_subtype(t1, DataType::Float)) {
                    type_ = DataType::Duration;
                    return;
                } else if (exp.op() == BinaryOp::Divide &&
                           t1 == DataType::Duration &&
                           t2 == DataType::Duration) {
                    type_ = DataType::Float;
                    return;
                } else if (is_numeric_subtype(t1, t2)) {
                    type_ = t2;
                    return;
                } else if (is_numeric_subtype(t2, t1)) {
                    type_ = t1;
                    return;
                }
                break;
            case BinaryOp::Mod:
                if (is_castable(t1, DataType::Int) &&
                    is_castable(t2, DataType::Int)) {
                    type_ = DataType::Int;
                    return;
                }
                break;
            case BinaryOp::Pow:
                if (is_numeric_subtype(t2, t1)) {
                    type_ = t1;
                    return;
                }
                break;
        }
        std::cerr << exp.pos()
                  << ": error : invalid operands to binary operator "
                  << exp.op() << " : '" << t1 << "' and '" << t2 << "' \n";
        error_ = true;
        type_ = DataType::None;
    }
    void visit(UExpr& exp) override {
        exp.subexp().accept(*this);
        switch (exp.op()) {
            case UnaryOp::BitNot:
                if (is_castable(type_, DataType::ClassicalRegister)) {
                    return; // type of ~x is same as type of x
                }
                break;
            case UnaryOp::LogicalNot:
                if (is_castable(type_, DataType::Bool)) {
                    type_ = DataType::Bool;
                    return;
                }
                break;
            case UnaryOp::Neg:
                if (is_numeric_subtype(type_, DataType::Complex)) {
                    return; // type of -x is same as type of x
                }
                break;
        }
        std::cerr << exp.pos() << ": error : invalid operand to unary operator "
                  << exp.op() << " : '" << type_ << "' \n";
        error_ = true;
        type_ = DataType::None;
    }
    void visit(MathExpr& exp) override {
        switch (exp.op()) {
            case MathOp::Arcsin:
            case MathOp::Sin:
            case MathOp::Arccos:
            case MathOp::Cos:
            case MathOp::Arctan:
            case MathOp::Tan:
            case MathOp::Exp:
            case MathOp::Ln:
            case MathOp::Sqrt:
                if (exp.num_args() != 1) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects one argument, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = DataType::None;
                    return;
                }
                visit_numeric_expr(exp.arg(0));
                type_ = DataType::Float; // assume we accept & return float
                break;
            case MathOp::Rotl:
            case MathOp::Rotr:
                if (exp.num_args() != 2) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects two arguments, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = DataType::None;
                    return;
                }
                visit_classical_expr(exp.arg(0), DataType::ClassicalRegister);
                visit_classical_expr(exp.arg(1), DataType::Int);
                type_ = DataType::ClassicalRegister;
                break;
            case MathOp::Popcount:
                if (exp.num_args() != 1) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects one argument, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = DataType::None;
                    return;
                }
                visit_classical_expr(exp.arg(0), DataType::ClassicalRegister);
                type_ = DataType::Int;
                break;
        }
    }
    void visit(CastExpr& exp) override {
        exp.type().accept(*this);
        auto tmp = type_;
        exp.subexp().accept(*this);
        if (!is_castable(type_, tmp)) {
            std::cerr << exp.pos() << ": error : cannot cast '" << type_
                      << "' to '" << tmp << "' \n";
            error_ = true;
        }
        type_ = tmp;
    }
    void visit(FunctionCall& exp) override {
        auto entry = lookup(exp.name());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.name() << "\"\n";
            error_ = true;
            type_ = DataType::None;
        } else if (std::holds_alternative<SubroutineType>(*entry)) {
            auto subrtn_type = std::get<SubroutineType>(*entry);
            if (subrtn_type.param_types.size() != exp.num_args()) {
                std::cerr << exp.pos() << ": error : subroutine \""
                          << exp.name() << "\" expects "
                          << subrtn_type.param_types.size()
                          << " arguments, but got " << exp.num_args() << "\n";
                error_ = true;
            } else {
                for (int i = 0; i < exp.num_args(); i++) {
                    exp.arg(i).accept(*this);
                    if (!is_castable(type_, subrtn_type.param_types[i])) {
                        std::cerr << exp.pos() << ": error : argument " << i
                                  << " is the wrong type : expected '"
                                  << subrtn_type.param_types[i] << "', got '"
                                  << type_ << "'\n";
                        error_ = true;
                    }
                }
            }
            type_ = subrtn_type.return_type;
        } else {
            std::cerr << exp.pos() << ": error : identifier \"" << exp.name()
                      << "\" is not a subroutine\n";
            error_ = true;
            type_ = DataType::None;
        }
    }
    void visit(AccessExpr& exp) override {
        exp.exp().accept(*this);
        auto tmp = type_;
        visit_classical_expr(exp.index(), DataType::Int);
        switch (tmp) {
            case DataType::Int: // apparently allowed (see adder.qasm)
            case DataType::ClassicalRegister:
                type_ = DataType::ClassicalBit;
                break;
            case DataType::QuantumRegister:
                type_ = DataType::QuantumBit;
                break;
            default:
                std::cerr << exp.pos() << ": error : expression of type '"
                          << tmp << "' cannot be indexed\n";
                error_ = true;
                type_ = DataType::None;
                break;
        }
    }
    void visit(ConstantExpr&) override { type_ = DataType::Float; }
    void visit(IntExpr&) override { type_ = DataType::Int; }
    void visit(RealExpr&) override { type_ = DataType::Float; }
    void visit(ImagExpr&) override { type_ = DataType::Complex; }
    void visit(BoolExpr&) override { type_ = DataType::Bool; }
    void visit(VarExpr& exp) override {
        auto entry = lookup(exp.var());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.var() << "\"\n";
            error_ = true;
            type_ = DataType::None;
        } else if (std::holds_alternative<DataType>(*entry)) {
            type_ = std::get<DataType>(*entry);
        } else {
            std::cerr << exp.pos() << ": error : invalid expression \""
                      << exp.var() << "\"\n";
            error_ = true;
            type_ = DataType::None;
        }
    }
    void visit(StringExpr&) override {
        type_ = DataType::ClassicalRegister; // assume string of 0s and 1s
    }
    void visit(TimeExpr&) override { type_ = DataType::Duration; }
    void visit(DurationGateExpr& exp) override {
        auto entry = lookup(exp.gate());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined gate \""
                      << exp.gate() << "\"\n";
            error_ = true;
        } else if (!std::holds_alternative<GateType>(*entry)) {
            std::cerr << exp.pos() << ": error : identifier \"" << exp.gate()
                      << "\" is not a gate\n";
            error_ = true;
        }
        type_ = DataType::Duration;
    }
    void visit(DurationBlockExpr& exp) override {
        push_scope();
        exp.block().accept(*this);
        pop_scope();
        type_ = DataType::Duration;
    }
    // Statement components
    void visit(QuantumMeasurement& msmt) override {
        visit_quantum_indexid(msmt.q_arg());
    }
    void visit(ProgramBlock& block) override {
        block.foreach_stmt([this](ProgramBlockStmt& pbstmt) {
            std::visit([this](auto& stmt) { stmt->accept(*this); }, pbstmt);
        });
    }
    void visit(QuantumBlock& block) override {
        block.foreach_stmt([this](QuantumBlockStmt& qbstmt) {
            std::visit([this](auto& stmt) { stmt->accept(*this); }, qbstmt);
        });
    }
    // Statements
    void visit(MeasureStmt& stmt) override { stmt.measurement().accept(*this); }
    void visit(MeasureAsgnStmt& stmt) override {
        stmt.measurement().accept(*this);
        stmt.c_arg().accept(*this);
        if (type_ != DataType::ClassicalBit &&
            type_ != DataType::ClassicalRegister) {
            std::cerr << stmt.c_arg().pos()
                      << ": error : expected classical register : \""
                      << stmt.c_arg() << "\"\n";
            error_ = true;
        }
    }
    void visit(ExprStmt& stmt) override { stmt.exp().accept(*this); }
    void visit(ResetStmt& stmt) override {
        for (int i = 0; i < stmt.num_args(); i++)
            visit_quantum_indexid(stmt.arg(i));
    }
    void visit(BarrierStmt& stmt) override {
        for (int i = 0; i < stmt.num_args(); i++)
            visit_quantum_indexid(stmt.arg(i));
    }
    void visit(IfStmt& stmt) override {
        visit_classical_expr(stmt.cond(), DataType::Bool);

        push_scope();
        stmt.then().accept(*this);
        pop_scope();

        push_scope();
        stmt.els().accept(*this);
        pop_scope();
    }
    void visit(BreakStmt& stmt) override {
        if (!in_loop_) {
            std::cerr << stmt.pos()
                      << ": error : unexpected break statement\n";
            error_ = true;
        }
    }
    void visit(ContinueStmt& stmt) override {
        if (!in_loop_) {
            std::cerr << stmt.pos()
                      << ": error : unexpected continue statement\n";
            error_ = true;
        }
    }
    void visit(ReturnStmt& stmt) override {
        if (!return_type_) {
            std::cerr << stmt.pos()
                      << ": error : unexpected return statement\n";
            error_ = true;
            return;
        }
        std::visit(
            utils::overloaded{
                [this](ptr<QuantumMeasurement>& qm) {
                    qm->accept(*this);
                    if (!is_castable(DataType::ClassicalRegister,
                                     *return_type_)) {
                        std::cerr
                            << qm->pos()
                            << ": error : incompatible return type : expected '"
                            << *return_type_ << "', got '"
                            << DataType::ClassicalRegister << "'\n";
                        error_ = true;
                    }
                },
                [this](ptr<Expr>& exp) {
                    visit_classical_expr(*exp, *return_type_);
                },
                [this, &stmt](auto) {
                    if (*return_type_ != DataType::None) {
                        std::cerr << stmt.pos()
                                  << ": error : non-void subroutine "
                                     "should return a value\n";
                        error_ = true;
                    }
                }},
            stmt.value());
    }
    void visit(EndStmt&) override {}
    void visit(AliasStmt& stmt) override {
        visit_quantum_indexid(stmt.qreg());
        set(stmt.alias(), type_, stmt.pos());
    }
    void visit(AssignmentStmt& stmt) override {
        /* first, replace 'x [op]= y' with 'x = x [op] y' */
        if (stmt.op() != AssignOp::Equals) {
            BinaryOp bop;
            switch (stmt.op()) {
                case AssignOp::Plus:
                    bop = BinaryOp::Plus;
                    break;
                case AssignOp::Minus:
                    bop = BinaryOp::Minus;
                    break;
                case AssignOp::Times:
                    bop = BinaryOp::Times;
                    break;
                case AssignOp::Div:
                    bop = BinaryOp::Divide;
                    break;
                case AssignOp::BitAnd:
                    bop = BinaryOp::BitAnd;
                    break;
                case AssignOp::BitOr:
                    bop = BinaryOp::BitOr;
                    break;
                case AssignOp::XOr:
                    bop = BinaryOp::XOr;
                    break;
                case AssignOp::LeftBitShift:
                    bop = BinaryOp::LeftBitShift;
                    break;
                case AssignOp::RightBitShift:
                    bop = BinaryOp::RightBitShift;
                    break;
                case AssignOp::Mod:
                    bop = BinaryOp::Mod;
                    break;
                case AssignOp::Pow:
                    bop = BinaryOp::Pow;
                    break;
                case AssignOp::Tilde:
                    std::cerr
                        << stmt.pos()
                        << ": error : unknown assignment operator \"~=\"\n";
                    error_ = true;
                    return;
                default:;
            }
            auto lexp = ptr<Expr>(new VarExpr(stmt.pos(), stmt.var()));
            if (stmt.index()) {
                lexp = ptr<Expr>(new AccessExpr(stmt.pos(), std::move(lexp),
                                                object::clone(**stmt.index())));
            }
            stmt.set_exp(ptr<Expr>(new BExpr(stmt.pos(), std::move(lexp), bop,
                                             object::clone(stmt.exp()))));
            stmt.set_op(AssignOp::Equals);
        }
        auto entry = lookup(stmt.var());
        if (!entry) {
            std::cerr << stmt.pos() << ": error : undefined identifier \""
                      << stmt.var() << "\"\n";
            error_ = true;
        } else if (!std::holds_alternative<DataType>(*entry)) {
            std::cerr << stmt.pos() << ": error : identifier \"" << stmt.var()
                      << "\" is not a classical type\n";
            error_ = true;
        } else {
            DataType type = std::get<DataType>(*entry);
            if (is_quantum(type)) {
                std::cerr << stmt.pos() << ": error : identifier \""
                          << stmt.var() << "\" is not a classical type\n";
                error_ = true;
                return;
            }
            if (stmt.index()) {
                visit_optional_classical_expr(stmt.index(), DataType::Int);
                if (type != DataType::ClassicalRegister) {
                    std::cerr << stmt.pos() << ": error : identifier \""
                              << stmt.var()
                              << "\" cannot be indexed because it is not a "
                                 "classical register type\n";
                    error_ = true;
                    return;
                }
                type = DataType::ClassicalBit;
            }
            visit_classical_expr(stmt.exp(), type);
        }
    }
    void visit(PragmaStmt& stmt) override {
        push_scope();
        stmt.foreach_stmt([this](Stmt& s) { s.accept(*this); });
        pop_scope();
    }
    // Gates
    void visit(CtrlModifier& mod) override {
        if (mod.n()) {
            auto expr = dynamic_cast<IntExpr*>(mod.n()->get());
            control_bits_ = expr->value();
        } else {
            control_bits_ = 1;
        }
    }
    void visit(InvModifier&) override {}
    void visit(PowModifier& mod) override {
        visit_classical_expr(mod.r(), DataType::Float);
    }
    void visit(UGate& gate) override {
        int total_control_bits = 0;
        for (auto& mod : gate.modifiers()) {
            control_bits_ = 0;
            mod->accept(*this);
            total_control_bits += control_bits_;
        }

        visit_numeric_expr(gate.theta());
        visit_numeric_expr(gate.phi());
        visit_numeric_expr(gate.lambda());

        if (gate.num_qargs() != 1 + total_control_bits) {
            std::cerr << gate.pos()
                      << ": error : gate \"U\" expects 1 quantum parameter";
            if (total_control_bits > 0) {
                std::cerr << " plus " << total_control_bits << " control bits";
            }
            std::cerr << ", but got " << gate.num_qargs() << "\n";
            error_ = true;
            return;
        }
        gate.foreach_qarg(
            [this](IndexId& qarg) { visit_quantum_indexid(qarg); });
    }
    void visit(GPhase& gate) override {
        int total_control_bits = 0;
        for (auto& mod : gate.modifiers()) {
            control_bits_ = 0;
            mod->accept(*this);
            total_control_bits += control_bits_;
        }

        visit_numeric_expr(gate.gamma());

        if (gate.num_qargs() != total_control_bits) {
            std::cerr << gate.pos() << ": error : gate \"gphase\" expects "
                      << total_control_bits << " quantum parameters, but got "
                      << gate.num_qargs() << "\n";
            error_ = true;
            return;
        }
        gate.foreach_qarg(
            [this](IndexId& qarg) { visit_quantum_indexid(qarg); });
    }
    void visit(DeclaredGate& gate) override {
        auto entry = lookup(gate.name());
        if (!entry) {
            std::cerr << gate.pos() << ": error : undefined gate \""
                      << gate.name() << "\"\n";
            error_ = true;
        } else if (!std::holds_alternative<GateType>(*entry)) {
            std::cerr << gate.pos() << ": error : identifier \"" << gate.name()
                      << "\" is not a gate\n";
            error_ = true;
        } else {
            auto gate_type = std::get<GateType>(*entry);

            int total_control_bits = 0;
            for (auto& mod : gate.modifiers()) {
                control_bits_ = 0;
                mod->accept(*this);
                total_control_bits += control_bits_;
            }

            if (gate.num_cargs() != gate_type.num_c_params) {
                std::cerr << gate.pos() << ": error : gate \"" << gate.name()
                          << "\" expects " << gate_type.num_c_params
                          << " classical parameters, but got "
                          << gate.num_cargs() << "\n";
                error_ = true;
                return;
            }
            gate.foreach_carg([this](Expr& carg) { visit_numeric_expr(carg); });

            if (gate.num_qargs() !=
                gate_type.num_q_params + total_control_bits) {
                std::cerr << gate.pos() << ": error : gate \"" << gate.name()
                          << "\" expects " << gate_type.num_q_params
                          << " quantum parameters";
                if (total_control_bits > 0) {
                    std::cerr << " plus " << total_control_bits
                              << " control bits";
                }
                std::cerr << ", but got " << gate.num_qargs() << "\n";
                error_ = true;
                return;
            }
            gate.foreach_qarg(
                [this](IndexId& qarg) { visit_quantum_indexid(qarg); });
        }
    }
    // Loops
    void visit(RangeSet& set) override {
        visit_optional_classical_expr(set.start(), DataType::Int);
        visit_optional_classical_expr(set.step(), DataType::Int);
        visit_optional_classical_expr(set.stop(), DataType::Int);
    }
    void visit(ListSet& set) override {
        for (auto& index : set.indices()) {
            visit_classical_expr(*index, DataType::Int);
        }
    }
    void visit(VarSet& vs) override {
        auto entry = lookup(vs.var());
        if (!entry) {
            std::cerr << vs.pos() << ": error : undefined identifier \""
                      << vs.var() << "\"\n";
            error_ = true;
        } else {
            std::cerr << vs.pos() << ": error : looping over identifier \""
                      << vs.var() << "\" is not supported\n";
            error_ = true;
        }
    }
    void visit(ForStmt& stmt) override {
        stmt.index_set().accept(*this);

        bool was_in_loop = in_loop_;
        in_loop_ = true;

        push_scope();
        set(stmt.var(), DataType::Int, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();

        in_loop_ = was_in_loop;
    }
    void visit(WhileStmt& stmt) override {
        visit_classical_expr(stmt.cond(), DataType::Bool);

        bool was_in_loop = in_loop_;
        in_loop_ = true;

        push_scope();
        stmt.body().accept(*this);
        pop_scope();

        in_loop_ = was_in_loop;
    }
    void visit(QuantumForStmt& stmt) override {
        stmt.index_set().accept(*this);

        bool was_in_loop = in_loop_;
        in_loop_ = true;

        push_scope();
        set(stmt.var(), DataType::Int, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();

        in_loop_ = was_in_loop;
    }
    void visit(QuantumWhileStmt& stmt) override {
        visit_classical_expr(stmt.cond(), DataType::Bool);

        bool was_in_loop = in_loop_;
        in_loop_ = true;

        push_scope();
        stmt.body().accept(*this);
        pop_scope();

        in_loop_ = was_in_loop;
    }
    // Timing Statements
    void visit(DelayStmt& delay) override {
        for (int i = 0; i < delay.num_cargs(); i++) {
            visit_classical_expr(delay.carg(i), DataType::Float);
        }
        visit_classical_expr(delay.duration(), DataType::Duration);
        for (int i = 0; i < delay.num_qargs(); i++) {
            visit_quantum_indexid(delay.qarg(i));
        }
    }
    void visit(RotaryStmt& rotary) override {
        for (int i = 0; i < rotary.num_cargs(); i++) {
            visit_classical_expr(rotary.carg(i), DataType::Float);
        }
        visit_classical_expr(rotary.duration(), DataType::Duration);
        for (int i = 0; i < rotary.num_qargs(); i++) {
            visit_quantum_indexid(rotary.qarg(i));
        }
    }
    void visit(BoxStmt& box) override {
        visit_optional_classical_expr(box.duration(), DataType::Duration);
        push_scope();
        box.circuit().accept(*this);
        pop_scope();
    }
    // Declarations
    void visit(ClassicalParam& param) override {
        param.type().accept(*this);

        set(param.id(), type_, param.pos());
    }
    void visit(QuantumParam& param) override {
        param.type().accept(*this);

        set(param.id(), type_, param.pos());
    }
    void visit(SubroutineDecl& decl) override {
        push_scope();
        std::vector<DataType> param_types;

        for (auto& param : decl.params()) {
            param->accept(*this);
            param_types.push_back(type_);
        }

        type_ = DataType::None;
        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        return_type_ = type_;
        decl.body().accept(*this);

        pop_scope();

        set(decl.id(), SubroutineType{param_types, *return_type_}, decl.pos());
        return_type_ = std::nullopt;
    }
    void visit(ExternDecl& decl) override {
        std::vector<DataType> param_types;

        for (auto& type : decl.param_types()) {
            type->accept(*this);
            param_types.push_back(type_);
        }

        type_ = DataType::None;
        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        set(decl.id(), SubroutineType{param_types, type_}, decl.pos());
    }
    void visit(GateDecl& decl) override {
        push_scope();

        for (const ast::symbol& param : decl.c_params()) {
            set(param, DataType::Float, decl.pos());
        }
        for (const ast::symbol& param : decl.q_params()) {
            set(param, DataType::QuantumBit, decl.pos());
        }
        decl.body().accept(*this);

        pop_scope();

        set(decl.id(),
            GateType{(int) decl.c_params().size(),
                     (int) decl.q_params().size()},
            decl.pos());
    }
    void visit(QuantumDecl& decl) override {
        decl.type().accept(*this);
        set(decl.id(), type_, decl.pos());
    }
    void visit(ClassicalDecl& decl) override {
        if (decl.is_const()) {
            // assume constants have already been substituted
            set(decl.id(), DataType::None, decl.pos());
        } else {
            decl.type().accept(*this);
            set(decl.id(), type_, decl.pos());
            visit_optional_classical_expr(decl.equalsexp(), type_);
        }
    }
    void visit(CalGrammarDecl&) override {}
    void visit(CalibrationDecl&) override {} // need to implement when finalized
    // Program
    void visit(Program& prog) override {
        push_scope();

        prog.foreach_stmt([this](ProgramStmt& pstmt) {
            std::visit([this](auto& stmt) { stmt->accept(*this); }, pstmt);
        });

        pop_scope();
    }

  private:
    bool error_ = false;   ///< whether errors have occurred
    bool in_loop_ = false; ///< whether we are in the body of a loop
    int control_bits_ = 0; ///< number of control bits from control modifiers
    std::list<std::unordered_map<ast::symbol, Type>> symbol_table_{
        {}};                         ///< a stack of symbol tables
    DataType type_ = DataType::None; ///< type of current expression
    std::optional<DataType> return_type_ =
        std::nullopt; ///< return type of subroutine

    /**
     * \brief Enters a new scope
     */
    void push_scope() { symbol_table_.push_front({}); }

    /**
     * \brief Exits the current scope
     */
    void pop_scope() { symbol_table_.pop_front(); }

    /**
     * \brief Looks up a symbol in the symbol table
     *
     * Lookup checks in each symbol table going backwards up the enclosing
     * scopes.
     *
     * \param id Const reference to a symbol
     * \return The type of the symbol, if found
     */
    std::optional<Type> lookup(const ast::symbol& id) {
        for (auto& table : symbol_table_) {
            if (auto it = table.find(id); it != table.end()) {
                return it->second;
            }
        }
        return std::nullopt;
    }

    /**
     * \brief Looks up a symbol in the local scope.
     *
     * \param id Const reference to a symbol
     * \return The type of the symbol, if found
     */
    std::optional<Type> lookup_local(const ast::symbol& id) {
        if (!(symbol_table_.empty())) {
            const auto& local = symbol_table_.front();
            if (auto it = local.find(id); it != local.end()) {
                return it->second;
            }
        }
        return std::nullopt;
    }

    /**
     * \brief Assigns a symbol in the current scope if it has not yet been
     * defined in the current scope
     *
     * \param id Const reference to a symbol
     * \param typ The type of the symbol
     */
    void set(const ast::symbol& id, Type typ, const parser::Position& pos) {
        if (symbol_table_.empty())
            throw std::logic_error("No current symbol table!");
        else if (lookup_local(id)) {
            std::cerr << pos << ": error : redefinition of \"" << id << "\"\n";
            error_ = true;
            return;
        }

        symbol_table_.front()[id] = typ;
    }

    /**
     * \brief Visit a classical expression in the AST
     *
     * \param exp Reference to the expression
     * \param expected_type Expected type of the expression
     */
    void visit_classical_expr(Expr& exp, DataType expected_type) {
        exp.accept(*this);
        if (!is_castable(type_, expected_type)) {
            std::cerr << exp.pos() << ": error : expected '" << expected_type
                      << "' type, but got '" << type_ << "' type : \"" << exp
                      << "\"\n";
            error_ = true;
        }
    }

    /**
     * \brief Visit an optional classical expression in the AST
     *
     * \param exp Reference to the optional expression
     * \param expected_type Expected type of the expression
     */
    void visit_optional_classical_expr(std::optional<ptr<Expr>>& exp,
                                       const DataType& expected_type) {
        if (exp)
            visit_classical_expr(**exp, expected_type);
    }

    /**
     * \brief Visit a classical expression in the AST with numeric type
     *
     * \param exp Reference to the expression
     */
    void visit_numeric_expr(Expr& exp) {
        exp.accept(*this);
        if (type_ != DataType::Int && type_ != DataType::Float &&
            type_ != DataType::Angle) {
            std::cerr << exp.pos()
                      << ": error : expected numeric type, but got '" << type_
                      << "' type : \"" << exp << "\"\n";
            error_ = true;
        }
    }

    /**
     * \brief Visit a quantum register in the AST
     *
     * \param indexid Reference to the register
     */
    void visit_quantum_indexid(IndexId& indexid) {
        indexid.accept(*this);
        if (!is_quantum(type_)) {
            std::cerr << indexid.pos()
                      << ": error : expected quantum type, but got '" << type_
                      << "' type : \"" << indexid << "\"\n";
            error_ = true;
        }
    }
};

/**
 * \brief Checks a program for semantic errors
 */
inline void check_source(Program& prog) {
    if (ConstExprChecker().run(prog) || TypeChecker().run(prog))
        throw SemanticError();
}

} // namespace ast
} // namespace qasm3tools
