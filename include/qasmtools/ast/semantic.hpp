/*
 * This file is part of qasmtools.
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
 * \file qasmtools/ast/semantic.hpp
 * \brief Visitor interface for syntax trees
 */

#pragma once

#include "ast.hpp"
#include "visitor.hpp"
#include "../utils/templates.hpp"

#include <unordered_map>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::SemanticError
 * \brief Exception class for semantic errors
 */
class SemanticError : public std::exception {
  public:
    SemanticError() noexcept = default;
    ~SemanticError() = default;
    const char* what() const noexcept { return "Error(s) occurred"; }
};

/**
 * \class qasmtools::ast::ConstExprChecker
 * \brief Checks that const expressions are only defined in terms of other
 * const expressions, and that const variables are not assigned to. Also
 * replaces occurences of const expressions with their values, e.g.
 *   const int[32] n = 8;
 *   qubit[n] q;
 * becomes
 *   const int[32] n = 8;
 *   qubit[int[32](8)] q;
 * \see qasmtools::ast::Visitor
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
            std::visit(utils::overloaded{[this, &va](ConstVar&) {
                           std::cerr << va.pos() << ": error : constant variable \""
                                     << va.var() << "\" cannot be used as an argument\n";
                           error_ = true;
                       },
                       [this, &va](LoopVar&) {
                           std::cerr << va.pos() << ": error : loop variable \""
                                     << va.var() << "\" cannot be used as an argument\n";
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
    }
    void visit(NoDesignatorType&) override {}
    void visit(BitType& type) override { visit_optional_expr(type.size()); }
    void visit(ComplexType& type) override { type.subtype().accept(*this); }
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
            replacement_expr_ = ptr<Expr>(new CastExpr({}, object::clone(*var.type),
                                                       object::clone(*var.value)));
        } else if (expect_const_) {
            std::cerr << exp.pos() << ": error : identifier \""
                      << exp.var() << "\" is not a compile-time constant expression\n";
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
            std::cerr << stmt.pos() << ": error : cannot assign to constant variable \""
                      << stmt.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<LoopVar>(*entry)) {
            std::cerr << stmt.pos() << ": error : cannot assign to loop variable \""
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
        expect_const_ = true;
        visit_optional_expr(mod.n());
        expect_const_ = false;
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
    void visit(VarSet&) override {}
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
    void visit(QubitParam& param) override {
        visit_optional_expr(param.size());

        set(param.id(), OtherVar{}, param.pos());
    }
    void visit(SubroutineDecl& decl) override {
        push_scope();

        expect_const_ = true;
        for (auto& param : decl.params()) {
            param->accept(*this);
        }

        auto& ret_type = decl.return_type();
        if (ret_type) {
            (**ret_type).accept(*this);
        }
        expect_const_ = false;

        decl.body().accept(*this);

        pop_scope();

        set(decl.id(), OtherVar{}, decl.pos());
    }
    void visit(ExternDecl& decl) override {
        expect_const_ = true;
        for (auto& type : decl.param_types()) {
            type->accept(*this);
        }

        auto& ret_type = decl.return_type();
        if (ret_type) {
            (**ret_type).accept(*this);
        }
        expect_const_ = false;

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
    void visit(QuantumRegisterDecl& decl) override {
        expect_const_ = true;
        visit_optional_expr(decl.size());
        expect_const_ = false;
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
            set(decl.id(), ConstVar{decl.equalsexp()->get(),
                                    std::addressof(decl.type())}, decl.pos());
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
    bool expect_const_ = false; ///< true when traversing a compile-time constant
    std::list<std::unordered_map<ast::symbol, Type>> symbol_table_{
        {}}; ///< a stack of symbol tables
    std::optional<ptr<Expr>> replacement_expr_;

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
};

/**
 * \class qasmtools::ast::CallChecker
 * \brief Chaeck quantum gate, built-in math, casting, and subroutine calls
 * \see qasmtools::ast::Visitor
 */
class CallChecker final : public Visitor {
    enum class Types {
        None,
        Classical,
        QuantumBit,
        QuantumRegister
    };

    /**
     * \brief Data struct denoting a classical-type variable
     */
    struct ClassicalType {};

    /**
     * \brief Data struct denoting a quantum bit variable
     */
    struct QuantumBitType {};

    /**
     * \brief Data struct denoting a quantum register variable
     */
    struct QuantumRegisterType {};

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
        std::vector<Types> param_types; ///< function signature
        Types return_type; ///< whether the subroutine returns a value
    };

    /**
     * \brief Data struct denoting all other types
     */
    struct OtherType {};

    /**
     * \brief OpenQASM types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using Type = std::variant<ClassicalType, QuantumBitType,
        QuantumRegisterType, GateType, SubroutineType, OtherType>;

  public:
    bool run(Program& prog) {
        prog.accept(*this);
        return error_;
    }

    // Index identifiers
    void visit(RangeSlice& slice) override {
        visit_optional_classical_expr(slice.start());
        visit_optional_classical_expr(slice.step());
        visit_optional_classical_expr(slice.stop());
    }
    void visit(ListSlice& slice) override {
        for (auto& index : slice.indices()) {
            visit_classical_expr(*index);
        }
    }
    void visit(VarAccess& va) override {
        auto entry = lookup(va.var());
        if (!entry) {
            std::cerr << va.pos() << ": error : undefined identifier \""
                      << va.var() << "\"\n";
            error_ = true;
            type_ = Types::None;
        } else if (std::holds_alternative<QuantumRegisterType>(*entry)) {
            if (va.slice())
                (**va.slice()).accept(*this);
            type_ = Types::QuantumRegister;
        } else if (std::holds_alternative<QuantumBitType>(*entry)) {
            type_ = Types::QuantumBit;
            if (va.slice()) {
                std::cerr << va.pos() << ": error : quantum bit \""
                          << va.var() << "\" cannnot be indexed\n";
                error_ = true;
                type_ = Types::None;
            }
        } else if (std::holds_alternative<ClassicalType>(*entry)) {
            if (va.slice())
                (**va.slice()).accept(*this);
            type_ = Types::Classical;
        } else {
            std::cerr << va.pos() << ": error : identifier \""
                      << va.var() << "\" is not a quantum type\n";
            error_ = true;
            type_ = Types::None;
        }
    }
    void visit(Concat& c) override {
        c.lreg().accept(*this);
        auto t1 = type_;
        c.rreg().accept(*this);
        auto t2 = type_;
        if (t1 == Types::None || t2 == Types::None) {
            type_ = Types::None;
        } else if (t1 == Types::Classical && t2 == Types::Classical) {
            type_ = Types::Classical;
        } else if (t1 == Types::Classical || t2 == Types::Classical) {
            std::cerr << c.pos() << ": error : concatenation of classical and quantum register\n";
            error_ = true;
            type_ = Types::None;
        } else {
            type_ = Types::QuantumRegister;
        }
    }
    // Types
    void visit(SingleDesignatorType& type) override {
        visit_classical_expr(type.size());
    }
    void visit(NoDesignatorType&) override {}
    void visit(BitType& type) override {
        visit_optional_classical_expr(type.size());
    }
    void visit(ComplexType& type) override { type.subtype().accept(*this); }
    // Expressions
    void visit(BExpr& exp) override {
        exp.lexp().accept(*this);
        auto t1 = type_;
        exp.rexp().accept(*this);
        auto t2 = type_;
        if (t1 != Types::Classical || t2 != Types::Classical) {
            std::cerr << exp.pos() << ": error : binary expression expects classical type operands\n";
            error_ = true;
        }
        type_ = Types::Classical;
    }
    void visit(UExpr& exp) override {
        exp.subexp().accept(*this);
        if (type_ != Types::Classical) {
            std::cerr << exp.pos() << ": error : unary expression expects classical type operand\n";
            error_ = true;
            type_ = Types::None;
        }
        type_ = Types::Classical;
    }
    void visit(MathExpr& exp) override {
        for (int i = 0; i < exp.num_args(); i++) {
            visit_classical_expr(exp.arg(i));
        }
        type_ = Types::Classical;
    }
    void visit(CastExpr& exp) override {
        exp.type().accept(*this);
        visit_classical_expr(exp.subexp());
        type_ = Types::Classical;
    }
    void visit(FunctionCall& exp) override {
        auto entry = lookup(exp.name());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.name() << "\"\n";
            error_ = true;
            type_ = Types::None;
        } else if (std::holds_alternative<SubroutineType>(*entry)) {
            auto subrtn_type = std::get<SubroutineType>(*entry);
            if (subrtn_type.param_types.size() != exp.num_args()) {
                std::cerr << exp.pos() << ": error : subroutine \""
                          << exp.name() << "\" expects "
                          << subrtn_type.param_types.size()  << " arguments, but got "
                          << exp.num_args() << "\n";
                error_ = true;
            } else {
                for (int i = 0; i < exp.num_args(); i++) {
                    exp.arg(i).accept(*this);
                    if (type_ != subrtn_type.param_types[i]) {
                        std::cerr << exp.pos() << ": error : argument "
                                  << i << " is the wrong type\n";
                        error_ = true;
                    }
                }
            }
            type_ = subrtn_type.return_type;
        } else {
            std::cerr << exp.pos() << ": error : identifier \""
                      << exp.name() << "\" is not a subroutine\n";
            error_ = true;
            type_ = Types::None;
        }
    }
    void visit(AccessExpr& exp) override {
        exp.exp().accept(*this);
        auto tmp = type_;
        visit_classical_expr(exp.index());
        if (tmp == Types::Classical) {
            type_ = Types::Classical;
        } else if (tmp == Types::QuantumRegister) {
            type_ = Types::QuantumBit;
        } else if (tmp == Types::QuantumBit) {
            std::cerr << exp.exp().pos() << ": error : invalid access operator\n";
            error_ = true;
            type_ = Types::None;
        }
    }
    void visit(ConstantExpr&) override { type_ = Types::Classical; }
    void visit(IntExpr&) override { type_ = Types::Classical; }
    void visit(RealExpr&) override { type_ = Types::Classical; }
    void visit(ImagExpr&) override { type_ = Types::Classical; }
    void visit(BoolExpr&) override { type_ = Types::Classical; }
    void visit(VarExpr& exp) override {
        auto entry = lookup(exp.var());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.var() << "\"\n";
            error_ = true;
            type_ = Types::None;
        } else if (std::holds_alternative<ClassicalType>(*entry)) {
            type_ = Types::Classical;
        } else if (std::holds_alternative<QuantumBitType>(*entry)) {
            type_ = Types::QuantumBit;
        } else if (std::holds_alternative<QuantumRegisterType>(*entry)) {
            type_ = Types::QuantumRegister;
        } else {
            std::cerr << exp.pos() << ": error : invalid expression \""
                      << exp.var() << "\"\n";
            error_ = true;
            type_ = Types::None;
        }
    }
    void visit(StringExpr&) override { type_ = Types::Classical; }
    void visit(TimeExpr&) override { type_ = Types::Classical; }
    void visit(DurationGateExpr& exp) override {
        auto entry = lookup(exp.gate());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined gate \""
                      << exp.gate() << "\"\n";
            error_ = true;
        } else if (!std::holds_alternative<GateType>(*entry)) {
            std::cerr << exp.pos() << ": error : identifier \""
                      << exp.gate() << "\" is not a gate\n";
            error_ = true;
        }
        type_ = Types::Classical;
    }
    void visit(DurationBlockExpr& exp) override {
        push_scope();
        exp.block().accept(*this);
        pop_scope();
        type_ = Types::Classical;
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
        if (type_ == Types::QuantumBit || type_ == Types::QuantumRegister) {
            std::cerr << stmt.c_arg().pos() << ": error : expected classical register, but got quantum type\n";
            error_ = true;
        }
    }
    void visit(ExprStmt& stmt) override {
        stmt.exp().accept(*this);
    }
    void visit(ResetStmt& stmt) override {
        for (int i = 0; i < stmt.num_args(); i++)
            visit_quantum_indexid(stmt.arg(i));
    }
    void visit(BarrierStmt& stmt) override {
        for (int i = 0; i < stmt.num_args(); i++)
            visit_quantum_indexid(stmt.arg(i));
    }
    void visit(IfStmt& stmt) override {
        visit_classical_expr(stmt.cond());

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
                                         visit_classical_expr(*exp);
                                     },
                                     [](auto) {}},
                   stmt.value());
    }
    void visit(EndStmt&) override {}
    void visit(AliasStmt& stmt) override {
        visit_quantum_indexid(stmt.qreg());
        set(stmt.alias(), QuantumRegisterType{}, stmt.pos());
    }
    void visit(AssignmentStmt& stmt) override {
        auto entry = lookup(stmt.var());
        if (!entry) {
            std::cerr << stmt.pos() << ": error : undefined identifier \""
                      << stmt.var() << "\"\n";
            error_ = true;
        } else if (!std::holds_alternative<ClassicalType>(*entry)) {
            std::cerr << stmt.pos() << ": error : identifier \""
                      << stmt.var() << "\" is not a classical type\n";
            error_ = true;
        }
        visit_optional_classical_expr(stmt.index());
        visit_classical_expr(stmt.exp());
    }
    void visit(PragmaStmt& stmt) override {
        push_scope();
        stmt.foreach_stmt([this](Stmt& s) { s.accept(*this); });
        pop_scope();
    }
    // Gates
    void visit(CtrlModifier& mod) override {
        visit_optional_classical_expr(mod.n());
    }
    void visit(InvModifier&) override {}
    void visit(PowModifier& mod) override {
        visit_classical_expr(mod.r());
    }
    void visit(UGate& gate) override {
        for (auto& mod : gate.modifiers())
            mod->accept(*this);
        visit_classical_expr(gate.theta());
        visit_classical_expr(gate.phi());
        visit_classical_expr(gate.lambda());
        gate.foreach_qarg([this](IndexId& qarg) { visit_quantum_indexid(qarg); });
    }
    void visit(GPhase& gate) override {
        for (auto& mod : gate.modifiers())
            mod->accept(*this);
        visit_classical_expr(gate.gamma());
        gate.foreach_qarg([this](IndexId& qarg) { visit_quantum_indexid(qarg); });
    }
    void visit(DeclaredGate& gate) override {
        for (auto& mod : gate.modifiers())
            mod->accept(*this);
        for (int i = 0; i < gate.num_cargs(); i++) {
            visit_classical_expr(gate.carg(i));
        }
        gate.foreach_qarg([this](IndexId& qarg) { visit_quantum_indexid(qarg); });
    }
    // Loops
    void visit(RangeSet& set) override {
        visit_optional_classical_expr(set.start());
        visit_optional_classical_expr(set.step());
        visit_optional_classical_expr(set.stop());
    }
    void visit(ListSet& set) override {
        for (auto& index : set.indices()) {
            visit_classical_expr(*index);
        }
    }
    void visit(VarSet& vs) override {
        auto entry = lookup(vs.var());
        if (!entry) {
            std::cerr << vs.pos() << ": error : undefined identifier \""
                      << vs.var() << "\"\n";
            error_ = true;
        } else if (!std::holds_alternative<ClassicalType>(*entry)) {
            std::cerr << vs.pos() << ": error : identifier \""
                      << vs.var() << "\" is not a classical type\n";
            error_ = true;
        }
    }
    void visit(ForStmt& stmt) override {
        stmt.index_set().accept(*this);

        push_scope();
        set(stmt.var(), ClassicalType{}, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();
    }
    void visit(WhileStmt& stmt) override {
        visit_classical_expr(stmt.cond());

        push_scope();
        stmt.body().accept(*this);
        pop_scope();
    }
    void visit(QuantumForStmt& stmt) override {
        stmt.index_set().accept(*this);

        push_scope();
        set(stmt.var(), ClassicalType{}, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();
    }
    void visit(QuantumWhileStmt& stmt) override {
        visit_classical_expr(stmt.cond());

        push_scope();
        stmt.body().accept(*this);
        pop_scope();
    }
    // Timing Statements
    void visit(DelayStmt& delay) override {
        for (int i = 0; i < delay.num_cargs(); i++) {
            visit_classical_expr(delay.carg(i));
        }
        delay.duration().accept(*this);
        for (int i = 0; i < delay.num_qargs(); i++) {
            visit_quantum_indexid(delay.qarg(i));
        }
    }
    void visit(RotaryStmt& rotary) override {
        for (int i = 0; i < rotary.num_cargs(); i++) {
            visit_classical_expr(rotary.carg(i));
        }
        rotary.duration().accept(*this);
        for (int i = 0; i < rotary.num_qargs(); i++) {
            visit_quantum_indexid(rotary.qarg(i));
        }
    }
    void visit(BoxStmt& box) override {
        visit_optional_classical_expr(box.duration());
        push_scope();
        box.circuit().accept(*this);
        pop_scope();
    }
    // Declarations
    void visit(ClassicalParam& param) override {
        param.type().accept(*this);

        set(param.id(), ClassicalType{}, param.pos());
        type_ = Types::Classical;
    }
    void visit(QubitParam& param) override {
        visit_optional_classical_expr(param.size());
        if (param.size()) {
            set(param.id(), QuantumRegisterType{}, param.pos());
            type_ = Types::QuantumRegister;
        } else {
            set(param.id(), QuantumBitType{}, param.pos());
            type_ = Types::QuantumBit;
        }
    }
    void visit(SubroutineDecl& decl) override {
        push_scope();
        std::vector<Types> param_types;

        for (auto& param : decl.params()) {
            param->accept(*this);
            param_types.push_back(type_);
        }
        decl.body().accept(*this);

        pop_scope();

        auto& ret_type = decl.return_type();
        Types return_type = Types::None;
        if (ret_type) {
            (**ret_type).accept(*this);
            return_type = Types::Classical;
        }

        set(decl.id(), SubroutineType{param_types, return_type}, decl.pos());
    }
    void visit(ExternDecl& decl) override {
        std::vector<Types> param_types;

        for (auto& type : decl.param_types()) {
            type->accept(*this);
            param_types.push_back(Types::Classical); // always classical
        }

        auto& ret_type = decl.return_type();
        Types return_type = Types::None;
        if (ret_type) {
            (**ret_type).accept(*this);
            return_type = Types::Classical;
        }

        set(decl.id(), SubroutineType{param_types, return_type}, decl.pos());
    }
    void visit(GateDecl& decl) override {
        push_scope();

        for (const ast::symbol& param : decl.c_params()) {
            set(param, ClassicalType{}, decl.pos());
        }
        for (const ast::symbol& param : decl.q_params()) {
            set(param, QuantumBitType{}, decl.pos());
        }
        decl.body().accept(*this);

        pop_scope();

        set(decl.id(), GateType{(int) decl.c_params().size(),
                                (int) decl.q_params().size()}, decl.pos());
    }
    void visit(QuantumRegisterDecl& decl) override {
        visit_optional_classical_expr(decl.size());
        if (decl.size()) {
            set(decl.id(), QuantumRegisterType{}, decl.pos());
        } else {
            set(decl.id(), QuantumBitType{}, decl.pos());
        }
    }
    void visit(ClassicalDecl& decl) override {
        if (decl.is_const()) {
            // assume constants have already been substituted
            set(decl.id(), OtherType{}, decl.pos());
        } else {
            decl.type().accept(*this);
            visit_optional_classical_expr(decl.equalsexp());
            set(decl.id(), ClassicalType{}, decl.pos());
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
    std::list<std::unordered_map<ast::symbol, Type>> symbol_table_{
        {}}; ///< a stack of symbol tables
    Types type_ = Types::None;

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
     */
    void visit_classical_expr(Expr& exp) {
        exp.accept(*this);
        if (type_ != Types::Classical) {
            std::cerr << exp.pos() << ": error : expected classical expression, but got \"" << exp << "\"\n";
            error_ = true;
        }
    }

    /**
     * \brief Visit an optional classical expression in the AST
     *
     * \param exp Reference to the optional expression
     */
    void visit_optional_classical_expr(std::optional<ptr<Expr>>& exp) {
        if (exp)
            visit_classical_expr(**exp);
    }

    /**
     * \brief Visit a quantum register in the AST
     *
     * \param indexid Reference to the register
     */
    void visit_quantum_indexid(IndexId& indexid) {
        indexid.accept(*this);
        if (type_ == Types::Classical) {
            std::cerr << indexid.pos() << ": error : expected quantum register, but got classical type\n";
            error_ = true;
        }
    }
};

/**
 * \brief Checks a program for semantic errors
 */
inline void check_source(Program& prog) {
    if (ConstExprChecker().run(prog) || CallChecker().run(prog))
        throw SemanticError();
}

} // namespace ast
} // namespace qasmtools
