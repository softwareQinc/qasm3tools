/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2023 softwareQ Inc. All rights reserved.
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

#ifndef QASM3TOOLS_AST_SEMANTIC_HPP_
#define QASM3TOOLS_AST_SEMANTIC_HPP_

#include <unordered_map>

#include "../utils/templates.hpp"
#include "ast.hpp"
#include "visitor.hpp"

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
 *
 * Finally, also computes and sets the program's total number of qubits
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
    void visit(SingleIndex& index) override {
        index.index().accept(*this);
        if (replacement_expr_) {
            index.set_index(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(RangeIndex& index) override {
        visit_optional_expr(index.start());
        visit_optional_expr(index.step());
        visit_optional_expr(index.stop());
    }
    void visit(IndexEntityList& indices) override {
        indices.foreach_index(
            [this](IndexEntity& index) { index.accept(*this); });
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
    void visit(IndexId& indexid) override {
        auto entry = lookup(indexid.var());
        if (!entry) {
            std::cerr << indexid.pos() << ": error : undefined identifier \""
                      << indexid.var() << "\"\n";
            error_ = true;
        } else {
            std::visit(utils::overloaded{
                           [this, &indexid](ConstVar&) {
                               std::cerr << indexid.pos()
                                         << ": error : constant variable \""
                                         << indexid.var()
                                         << "\" cannot be used here\n";
                               error_ = true;
                           },
                           [this, &indexid](LoopVar&) {
                               std::cerr << indexid.pos()
                                         << ": error : loop variable \""
                                         << indexid.var()
                                         << "\" cannot be used here\n";
                               error_ = true;
                           },
                           [](auto) {}},
                       *entry);
        }
        indexid.foreach_index_op([this](IndexOp& op) { op.accept(*this); });
    }
    // Types
    void visit(SingleDesignatorType& type) override {
        visit_optional_expr(type.size());
        if (type.size()) {
            auto size = evaluate(**type.size());
            if (size) {
                if (*size <= 0) {
                    std::cerr << type.pos()
                              << ": error : designator size must be "
                                 "positive\n";
                    error_ = true;
                } else {
                    type.size() = ptr<Expr>(new IntExpr({}, *size));
                }
            } else {
                std::cerr << type.pos()
                          << ": error : designator size is not a "
                             "compile-time constant\n";
                error_ = true;
            }
        }
    }
    void visit(NoDesignatorType&) override {}
    void visit(ComplexType& type) override {
        if (type.subtype()) {
            (**type.subtype()).accept(*this);
        }
    }
    void visit(ArrayType& type) override {
        type.subtype().accept(*this);
        for (int i = 0; i < type.dims(); i++) {
            type.dim(i).accept(*this);
            if (replacement_expr_) {
                type.set_dim(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
            auto size = evaluate(type.dim(i));
            if (size) {
                if (*size <= 0) {
                    std::cerr << type.pos()
                              << ": error : array dimension size must be "
                                 "positive\n";
                    error_ = true;
                } else {
                    type.set_dim(i, ptr<Expr>(new IntExpr({}, *size)));
                }
            } else {
                std::cerr << type.pos()
                          << ": error : array dimension size is not a "
                             "compile-time constant\n";
                error_ = true;
            }
        }
    }
    void visit(ArrayRefType& type) override {
        type.subtype().accept(*this);
        std::visit(
            utils::overloaded{
                [this](std::vector<ptr<Expr>>& dims) {
                    for (auto& dim : dims) {
                        dim->accept(*this);
                        if (replacement_expr_) {
                            dim = std::move(*replacement_expr_);
                            replacement_expr_ = std::nullopt;
                        }
                        auto size = evaluate(*dim);
                        if (size) {
                            if (*size <= 0) {
                                std::cerr
                                    << dim->pos()
                                    << ": error : array dimension size must be "
                                       "positive\n";
                                error_ = true;
                            } else {
                                dim = ptr<Expr>(new IntExpr({}, *size));
                            }
                        } else {
                            std::cerr
                                << dim->pos()
                                << ": error : array dimension size is not a "
                                   "compile-time constant\n";
                            error_ = true;
                        }
                    }
                },
                [this](ptr<Expr>& dims) {
                    dims->accept(*this);
                    if (replacement_expr_) {
                        dims = std::move(*replacement_expr_);
                        replacement_expr_ = std::nullopt;
                    }
                    auto size = evaluate(*dims);
                    if (size) {
                        if (*size <= 0) {
                            std::cerr << dims->pos()
                                      << ": error : array dimension specifier "
                                         "must be "
                                         "positive\n";
                            error_ = true;
                        } else {
                            dims = ptr<Expr>(new IntExpr({}, *size));
                        }
                    } else {
                        std::cerr
                            << dims->pos()
                            << ": error : array dimension specifier is not a "
                               "compile-time constant\n";
                        error_ = true;
                    }
                }},
            type.dims());
    }
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
                } else {
                    type.size() = ptr<Expr>(new IntExpr({}, *size));
                    if (is_quantum_decl_) {
                        qubit_count_ += *size;
                    }
                }
            } else {
                std::cerr << type.pos()
                          << ": error : quantum register size is not a "
                             "compile-time constant\n";
                error_ = true;
            }
        } else {
            if (is_quantum_decl_) {
                qubit_count_ += 1;
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
    void visit(SizeofExpr& exp) override {
        bool expect_const_copy = expect_const_;
        expect_const_ = false;
        exp.arr().accept(*this);
        if (replacement_expr_) {
            exp.set_arr(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        if (exp.dim()) {
            (**exp.dim()).accept(*this);
            if (replacement_expr_) {
                exp.dim() = std::move(*replacement_expr_);
                replacement_expr_ = std::nullopt;
            }
        }
        expect_const_ = expect_const_copy;
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
        exp.index_op().accept(*this);
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
    void visit(BitString&) override {}
    void visit(ArrayInitExpr& exp) override {
        for (int i = 0; i < exp.size(); i++) {
            exp.at(i).accept(*this);
            if (replacement_expr_) {
                exp.set_at(i, std::move(*replacement_expr_));
                replacement_expr_ = std::nullopt;
            }
        }
    }
    void visit(TimeExpr&) override {}
    void visit(DurationofExpr& exp) override {
        push_scope();
        exp.block().accept(*this);
        pop_scope();
    }
    void visit(MeasureExpr& msmt) override { msmt.q_arg().accept(*this); }
    // Statements
    void visit(Annotation&) override {}
    void visit(ProgramBlock& block) override {
        block.foreach_stmt([this](Stmt& stmt) { stmt.accept(*this); });
    }
    void visit(ExprStmt& stmt) override {
        stmt.exp().accept(*this);
        if (replacement_expr_) {
            stmt.set_exp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(ResetStmt& stmt) override { stmt.q_arg().accept(*this); }
    void visit(BarrierStmt& stmt) override {
        stmt.foreach_arg([this](IndexId& arg) { arg.accept(*this); });
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
        if (stmt.value()) {
            (**stmt.value()).accept(*this);
            if (replacement_expr_) {
                stmt.value() = std::move(*replacement_expr_);
                replacement_expr_ = std::nullopt;
            }
        }
    }
    void visit(EndStmt&) override {}
    void visit(AliasStmt& stmt) override {
        stmt.foreach_reg([this](Expr& reg) { reg.accept(*this); });
        set(stmt.alias(), OtherVar{}, stmt.pos());
    }
    void visit(AssignmentStmt& stmt) override {
        stmt.lval().accept(*this);
        stmt.exp().accept(*this);
        if (replacement_expr_) {
            stmt.set_exp(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
    }
    void visit(PragmaStmt&) override {}
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
                } else {
                    mod.n() = ptr<Expr>(new IntExpr({}, *n));
                }
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
        for (auto& mod : gate.modifiers()) {
            mod->accept(*this);
        }
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
        for (auto& mod : gate.modifiers()) {
            mod->accept(*this);
        }
        gate.gamma().accept(*this);
        if (replacement_expr_) {
            gate.set_gamma(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        gate.foreach_qarg([this](IndexId& qarg) { qarg.accept(*this); });
    }
    void visit(DeclaredGate& gate) override {
        for (auto& mod : gate.modifiers()) {
            mod->accept(*this);
        }
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
        if (!set.start() || !set.stop()) {
            std::cerr
                << set.pos()
                << ": error : loop range must specify start and stop values\n";
            error_ = true;
            return;
        }
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
        stmt.var_type().accept(*this);
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
    // Timing Statements
    void visit(DelayStmt& delay) override {
        delay.duration().accept(*this);
        if (replacement_expr_) {
            delay.set_duration(std::move(*replacement_expr_));
            replacement_expr_ = std::nullopt;
        }
        for (int i = 0; i < delay.num_qargs(); i++) {
            delay.qarg(i).accept(*this);
        }
    }
    void visit(BoxStmt& box) override {
        visit_optional_expr(box.duration());
        push_scope();
        box.circuit().accept(*this);
        pop_scope();
    }
    // Declarations
    void visit(Param& param) override {
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
        is_quantum_decl_ = true;
        decl.type().accept(*this);
        is_quantum_decl_ = false;
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
    void visit(IODecl& decl) override {
        if (decl.is_input()) {
            input_count_ += 1;
        }
        decl.type().accept(*this);
        set(decl.id(), OtherVar{}, decl.pos());
    }
    // Program
    void visit(Program& prog) override {
        qubit_count_ = 0;
        input_count_ = 0;

        push_scope();
        prog.foreach_stmt([this](Stmt& stmt) { stmt.accept(*this); });
        pop_scope();

        prog.set_qubits(qubit_count_);
        prog.set_inputs(input_count_);
    }

  private:
    bool error_ = false; ///< whether errors have occurred
    bool expect_const_ =
        false; ///< true when traversing a compile-time constant
    bool is_quantum_decl_ = false; ///< true when traversing quantum declaration
    int qubit_count_ = 0;          ///< total number of qubits in the program
    int input_count_ = 0;          ///< total number of inputs in the program
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
        if (symbol_table_.empty()) {
            throw std::logic_error("No current symbol table!");
        } else if (lookup_local(id)) {
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
        void visit(SingleIndex&) override {}
        void visit(RangeIndex&) override {}
        void visit(IndexEntityList&) override {}
        void visit(ListSlice&) override {}
        void visit(IndexId&) override {}
        // Types
        void visit(SingleDesignatorType& type) override {
            cast_is_int_ =
                type.type() == SDType::Int || type.type() == SDType::Uint;
        }
        void visit(NoDesignatorType&) override { cast_is_int_ = false; }
        void visit(ComplexType&) override { cast_is_int_ = false; }
        void visit(ArrayType&) override { cast_is_int_ = false; }
        void visit(ArrayRefType&) override { cast_is_int_ = false; }
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
                        value_ = std::pow(*lexp, *rexp);
                        break;
                    default:
                        value_ = std::nullopt;
                }
            } else {
                value_ = std::nullopt;
            }
        }
        void visit(UExpr& exp) override {
            exp.subexp().accept(*this);
            auto subexp = value_;
            if (subexp && exp.op() == UnaryOp::Neg) {
                value_ = -(*subexp);
            } else {
                value_ = std::nullopt;
            }
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
        void visit(SizeofExpr&) override { value_ = std::nullopt; }
        void visit(FunctionCall&) override { value_ = std::nullopt; }
        void visit(AccessExpr&) override { value_ = std::nullopt; }
        void visit(ConstantExpr&) override { value_ = std::nullopt; }
        void visit(IntExpr& exp) override { value_ = exp.value(); }
        void visit(RealExpr&) override { value_ = std::nullopt; }
        void visit(ImagExpr&) override { value_ = std::nullopt; }
        void visit(BoolExpr&) override { value_ = std::nullopt; }
        void visit(VarExpr& exp) override { value_ = std::nullopt; }
        void visit(BitString&) override { value_ = std::nullopt; }
        void visit(ArrayInitExpr&) override { value_ = std::nullopt; }
        void visit(TimeExpr&) override { value_ = std::nullopt; }
        void visit(DurationofExpr&) override { value_ = std::nullopt; }
        void visit(MeasureExpr&) override { value_ = std::nullopt; }
        // Statements
        void visit(Annotation&) override {}
        void visit(ProgramBlock&) override {}
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
        // Timing Statements
        void visit(DelayStmt&) override {}
        void visit(BoxStmt&) override {}
        // Declarations
        void visit(Param&) override {}
        void visit(SubroutineDecl&) override {}
        void visit(ExternDecl&) override {}
        void visit(GateDecl&) override {}
        void visit(QuantumDecl&) override {}
        void visit(ClassicalDecl&) override {}
        void visit(IODecl&) override {}
        // Program
        void visit(Program&) override {}
    };

    /**
     * \brief Evaluate a constant integer expression
     *
     * \param exp Reference to the expression
     * \return Optional integer value
     */
    static std::optional<int> evaluate(Expr& exp) {
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
     * \brief None type
     */
    struct NoneType {};

    /**
     * \brief Standard (i.e. classical and quantum) types
     */
    enum class StdType {
        Bool,
        Int,
        Float,
        Angle,
        ClassicalBit,
        Duration,
        Complex,
        QuantumBit,
    };

    /**
     * \brief Data struct for array types
     */
    struct ArrType {
        StdType subtype;
        int dims;
        bool is_mutable = true;
    };

    /**
     * \brief OpenQASM expression types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using ExprType = std::variant<NoneType, StdType, ArrType>;

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
        std::vector<ExprType> param_types; ///< function signature
        ExprType return_type;              ///< return type
    };

    /**
     * \brief OpenQASM types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using Type = std::variant<ExprType, GateType, SubroutineType>;

    /**
     * \brief Extraction operator overload for NoneType class
     *
     * \param os Output stream passed by reference
     * \param _ TypeChecker::NoneType class
     * \return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const NoneType&) {
        os << "None";
        return os;
    }

    /**
     * \brief Extraction operator overload for TypeChecker::StdType enum class
     *
     * \param os Output stream passed by reference
     * \param type TypeChecker::StdType enum class
     * \return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const StdType& type) {
        switch (type) {
            case StdType::Bool:
                os << "bool";
                break;
            case StdType::Int:
                os << "int";
                break;
            case StdType::Float:
                os << "float";
                break;
            case StdType::Angle:
                os << "angle";
                break;
            case StdType::ClassicalBit:
                os << "bit";
                break;
            case StdType::Duration:
                os << "duration";
                break;
            case StdType::Complex:
                os << "complex";
                break;
            case StdType::QuantumBit:
                os << "qubit";
                break;
        }
        return os;
    }

    /**
     * \brief Extraction operator overload for ArrType class
     *
     * \param os Output stream passed by reference
     * \param type TypeChecker::ArrType class
     * \return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const ArrType& type) {
        os << "array[" << type.subtype << ", #dim = " << type.dims << "]";
        return os;
    }

    /**
     * \brief Extraction operator overload for ExprType variant class
     *
     * \param os Output stream passed by reference
     * \param type TypeChecker::ExprType class
     * \return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const ExprType& type) {
        std::visit([&os](auto&& arg) { os << arg; }, type);
        return os;
    }

  private:
    // static member functions
    /**
     * \brief Checks whether a data type is a quantum type
     *
     * \return True if the data type is a quantum type, false otherwise
     */
    static bool is_quantum(const ExprType& type) {
        if (std::holds_alternative<StdType>(type)) {
            return std::get<StdType>(type) == StdType::QuantumBit;
        } else if (std::holds_alternative<ArrType>(type)) {
            return std::get<ArrType>(type).subtype == StdType::QuantumBit;
        }
        return false;
    }

    /**
     * \brief Checks whether a data type is a classical bit or creg type
     *
     * \return True if the data type is a classical bit type, false otherwise
     */
    static bool is_classical_bit(const ExprType& type) {
        if (std::holds_alternative<StdType>(type)) {
            return std::get<StdType>(type) == StdType::ClassicalBit;
        } else if (std::holds_alternative<ArrType>(type)) {
            auto t = std::get<ArrType>(type);
            return t.dims == 1 && t.subtype == StdType::ClassicalBit;
        }
        return false;
    }

    /**
     * \brief Checks whether a data type is a classical type
     *
     * \return True if the data type is a classical type, false otherwise
     */
    static bool is_classical(const ExprType& type) {
        if (std::holds_alternative<StdType>(type)) {
            return std::get<StdType>(type) != StdType::QuantumBit;
        } else if (std::holds_alternative<ArrType>(type)) {
            return std::get<ArrType>(type).subtype != StdType::QuantumBit;
        }
        return false;
    }

    /**
     * \brief Checks whether a data type is mutable
     *
     * \return True if the data type is mutable, false otherwise
     */
    static bool is_mutable(const ExprType& type) {
        if (std::holds_alternative<StdType>(type)) {
            return true;
        } else if (std::holds_alternative<ArrType>(type)) {
            return std::get<ArrType>(type).is_mutable;
        }
        return false;
    }

    /**
     * \brief Checks whether a data type can be indexed
     *
     * \return True if the data type can be indexed, false otherwise
     */
    static bool is_indexable(const ExprType& type) {
        if (std::holds_alternative<StdType>(type)) {
            auto t = std::get<StdType>(type);
            return t == StdType::Int || t == StdType::Angle;
        } else if (std::holds_alternative<ArrType>(type)) {
            return true;
        }
        return false;
    }

    /**
     * \brief Checks whether the source type is castable to the target type
     *
     * \return True if the source type is castable to the target type
     */
    static bool castable(StdType source, StdType target) {
        switch (source) {
            case StdType::Bool:
                switch (target) {
                    case StdType::Bool:
                    case StdType::Int:
                    case StdType::Float:
                    case StdType::ClassicalBit:
                    case StdType::Complex:
                        return true;
                    default:
                        return false;
                }
            case StdType::Int:
                switch (target) {
                    case StdType::Bool:
                    case StdType::Int:
                    case StdType::Float:
                    // case StdType::ClassicalBit: // can only do INT -> CREG
                    case StdType::Complex:
                        return true;
                    default:
                        return false;
                }
            case StdType::Float:
                switch (target) {
                    case StdType::Bool:
                    case StdType::Int:
                    case StdType::Float:
                    case StdType::Angle:
                    case StdType::Complex:
                        return true;
                    default:
                        return false;
                }
            case StdType::Angle:
                switch (target) {
                    case StdType::Bool:
                    case StdType::Angle:
                        // case StdType::ClassicalBit: // can only do ANGLE ->
                        // CREG
                        return true;
                    default:
                        return false;
                }
            case StdType::ClassicalBit:
                switch (target) {
                    case StdType::Bool:
                    case StdType::Int: // can also do CREG -> INT
                    // case StdType::Angle: // can only do CREG -> ANGLE
                    case StdType::ClassicalBit:
                        return true;
                    default:
                        return false;
                }
            default:
                return source == target;
        }
    }

    /**
     * \brief Checks whether the source type is castable to the target type
     *
     * \return True if the source type is castable to the target type
     */
    static bool general_castable(const ExprType& source,
                                 const ExprType& target) {
        if (std::holds_alternative<StdType>(source) &&
            std::holds_alternative<StdType>(target)) {
            return castable(std::get<StdType>(source),
                            std::get<StdType>(target));
        } else if (std::holds_alternative<ArrType>(source) &&
                   std::holds_alternative<ArrType>(target)) {
            auto s = std::get<ArrType>(source);
            auto t = std::get<ArrType>(target);
            return s.dims == t.dims && castable(s.subtype, t.subtype);
        } else if (std::holds_alternative<StdType>(source) &&
                   std::holds_alternative<ArrType>(target)) {
            return (std::get<StdType>(source) == StdType::Int ||
                    std::get<StdType>(source) == StdType::Angle ||
                    std::get<StdType>(source) == StdType::ClassicalBit) &&
                   std::get<ArrType>(target).subtype == StdType::ClassicalBit;
        } else if (std::holds_alternative<ArrType>(source) &&
                   std::holds_alternative<StdType>(target)) {
            return (std::get<StdType>(target) == StdType::Int ||
                    std::get<StdType>(target) == StdType::Angle ||
                    std::get<StdType>(target) == StdType::ClassicalBit) &&
                   std::get<ArrType>(source).subtype == StdType::ClassicalBit;
        }
        return false;
    }

    /**
     * \brief Checks whether the two types are exactly the same
     *
     * \return True if the types are exactly the same
     */
    static bool is_same(const ExprType& source, const ExprType& target) {
        if (std::holds_alternative<StdType>(source) &&
            std::holds_alternative<StdType>(target)) {
            return std::get<StdType>(source) == std::get<StdType>(target);
        } else if (std::holds_alternative<ArrType>(source) &&
                   std::holds_alternative<ArrType>(target)) {
            return std::get<ArrType>(source).subtype ==
                       std::get<ArrType>(target).subtype &&
                   std::get<ArrType>(source).dims ==
                       std::get<ArrType>(target).dims;
        }
        return false;
    }

    /**
     * \brief Checks whether two types are both numeric, and the first is
     * a subtype of the second.
     *
     * int is subtype of float and complex; float is subtype of complex.
     * int, float, complex, angle are subtypes of themselves.
     * Any other combinations return false.
     */
    static bool is_numeric_subtype(const ExprType& subtype,
                                   const ExprType& suptype) {
        if (std::holds_alternative<StdType>(subtype) &&
            std::holds_alternative<StdType>(suptype)) {
            auto sub = std::get<StdType>(subtype);
            auto sup = std::get<StdType>(suptype);
            if ((sub == StdType::Int &&
                 (sup == StdType::Int || sup == StdType::Float ||
                  sup == StdType::Complex)) ||
                (sub == StdType::Float &&
                 (sup == StdType::Float || sup == StdType::Complex)) ||
                (sub == StdType::Complex && sup == StdType::Complex) ||
                (sub == StdType::Angle && sup == StdType::Angle)) {
                return true;
            }
        }
        return false;
    }

    /**
     * \brief Checks whether the 'actual' stmt type is a subtype of 'expected'
     *
     * \return True if 'actual' is a subtype of 'expected'
     */
    static bool is_stmt_subtype(Stmt::Type actual, Stmt::Type expected) {
        switch (expected) {
            case Stmt::Type::Regular:
                return actual == Stmt::Type::Regular ||
                       actual == Stmt::Type::Quantum;
            case Stmt::Type::Global:
                return true;
            case Stmt::Type::Quantum:
                return actual == Stmt::Type::Quantum;
        }
        return false;
    }

  public:
    bool run(Program& prog) {
        prog.accept(*this);
        return error_;
    }

    // Index identifiers
    void visit(SingleIndex& index) override {
        visit_classical_expr(index.index(), StdType::Int);
    }
    void visit(RangeIndex& index) override {
        visit_optional_classical_expr(index.start(), StdType::Int);
        visit_optional_classical_expr(index.step(), StdType::Int);
        visit_optional_classical_expr(index.stop(), StdType::Int);
    }
    void visit(IndexEntityList& indices) override {
        auto tmp = type_;
        if (!is_indexable(tmp)) {
            std::cerr << indices.pos()
                      << ": error : non-array type cannot be indexed\n";
            error_ = true;
            type_ = NONE;
            return;
        } else if (std::holds_alternative<StdType>(tmp)) {
            tmp = CREG;
        }
        if (indices.num_index_entities() > std::get<ArrType>(tmp).dims) {
            std::cerr << indices.pos()
                      << ": error : more index entities than dimensions\n";
            error_ = true;
        } else {
            std::get<ArrType>(tmp).dims -= indices.num_single_indices();
            if (std::get<ArrType>(tmp).dims == 0) {
                tmp = std::get<ArrType>(tmp).subtype;
            }
        }
        indices.foreach_index(
            [this](IndexEntity& index) { index.accept(*this); });
        type_ = tmp;
    }
    void visit(ListSlice& slice) override {
        auto tmp = type_;
        if (!is_indexable(tmp)) {
            std::cerr << slice.pos()
                      << ": error : non-array type cannot be indexed\n";
            error_ = true;
            type_ = NONE;
            return;
        } else if (std::holds_alternative<StdType>(tmp)) {
            tmp = CREG;
        }
        for (auto& index : slice.indices()) {
            visit_classical_expr(*index, StdType::Int);
        }
        type_ = tmp;
    }
    void visit(IndexId& indexid) override {
        auto entry = lookup(indexid.var());
        if (!entry) {
            std::cerr << indexid.pos() << ": error : undefined identifier \""
                      << indexid.var() << "\"\n";
            error_ = true;
            type_ = NONE;
        } else if (std::holds_alternative<ExprType>(*entry)) {
            type_ = std::get<ExprType>(*entry);
            indexid.foreach_index_op([this](IndexOp& op) { op.accept(*this); });
        } else {
            std::cerr << indexid.pos() << ": error : identifier \""
                      << indexid.var() << "\" is not an expression\n";
            error_ = true;
            type_ = NONE;
        }
    }
    // Types
    void visit(SingleDesignatorType& type) override {
        switch (type.type()) {
            case SDType::Bit: {
                if (type.size()) {
                    type_ = CREG;
                } else {
                    type_ = StdType::ClassicalBit;
                }
                break;
            }
            case SDType::Int:
                type_ = StdType::Int;
                break;
            case SDType::Uint:
                type_ = StdType::Int;
                break;
            case SDType::Float:
                type_ = StdType::Float;
                break;
            case SDType::Angle:
                type_ = StdType::Angle;
                break;
        }
    }
    void visit(NoDesignatorType& type) override {
        switch (type.type()) {
            case NDType::Bool:
                type_ = StdType::Bool;
                break;
            case NDType::Duration:
                type_ = StdType::Duration;
                break;
            case NDType::Stretch:
                type_ = StdType::Duration;
                break;
        }
    }
    void visit(ComplexType& type) override {
        if (type.subtype()) {
            (**type.subtype()).accept(*this);
            if (!is_same(type_, StdType::Float)) {
                std::cerr << type.pos()
                          << ": error : complex only accepts 'float' subtype\n";
                error_ = true;
            }
        }
        type_ = StdType::Complex;
    }
    void visit(ArrayType& type) override {
        type.subtype().accept(*this);
        if (std::holds_alternative<StdType>(type_)) {
            type_ = ArrType{std::get<StdType>(type_), type.dims()};
        } else {
            std::cerr << type.pos()
                      << ": error : invalid array subtype : " << type_ << "\n";
            error_ = true;
            type_ = NONE;
        }
    }
    void visit(ArrayRefType& type) override {
        int d;
        std::visit(utils::overloaded{
                       [&d](std::vector<ptr<Expr>>& dims) { d = dims.size(); },
                       [&d](ptr<Expr>& dims) {
                           auto expr = dynamic_cast<IntExpr*>(dims.get());
                           d = expr->value();
                       }},
                   type.dims());
        type.subtype().accept(*this);
        if (std::holds_alternative<StdType>(type_)) {
            type_ = ArrType{std::get<StdType>(type_), d, type.is_mutable()};
        } else {
            std::cerr << type.pos()
                      << ": error : invalid array subtype : " << type_ << "\n";
            error_ = true;
            type_ = NONE;
        }
    }
    void visit(QubitType& type) override {
        if (type.size()) {
            type_ = ArrType{StdType::QuantumBit, 1};
        } else {
            type_ = StdType::QuantumBit;
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
                if (general_castable(t1, StdType::Bool) &&
                    general_castable(t2, StdType::Bool)) {
                    type_ = StdType::Bool;
                    return;
                }
                break;
            case BinaryOp::BitOr:
            case BinaryOp::XOr:
            case BinaryOp::BitAnd:
                if ((is_same(t1, StdType::Bool) || is_same(t1, StdType::Int) ||
                     is_classical_bit(t1)) &&
                    is_same(t1, t2)) {
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
                if ((general_castable(t1, CREG) ||
                     is_same(t1, StdType::Float)) &&
                    (general_castable(t2, CREG) ||
                     is_same(t2, StdType::Float))) {
                    type_ = StdType::Bool;
                    return;
                }
                break;
            case BinaryOp::LeftBitShift:
            case BinaryOp::RightBitShift: {
                if (general_castable(t1, CREG) &&
                    general_castable(t2, StdType::Int)) {
                    type_ = t1;
                    return;
                }
                break;
            }
            case BinaryOp::Plus:
            case BinaryOp::Minus:
                if (is_same(t1, StdType::Duration) &&
                    is_same(t2, StdType::Duration)) {
                    type_ = StdType::Duration;
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
                if (is_same(t1, StdType::Duration) &&
                    is_numeric_subtype(t2, StdType::Float)) {
                    type_ = StdType::Duration;
                    return;
                } else if (exp.op() == BinaryOp::Times &&
                           is_same(t2, StdType::Duration) &&
                           is_numeric_subtype(t1, StdType::Float)) {
                    type_ = StdType::Duration;
                    return;
                } else if (exp.op() == BinaryOp::Divide &&
                           is_same(t1, StdType::Duration) &&
                           is_same(t2, StdType::Duration)) {
                    type_ = StdType::Float;
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
                if (general_castable(t1, StdType::Int) &&
                    general_castable(t2, StdType::Int)) {
                    type_ = StdType::Int;
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
        type_ = NONE;
    }
    void visit(UExpr& exp) override {
        exp.subexp().accept(*this);
        switch (exp.op()) {
            case UnaryOp::BitNot:
                if (is_same(type_, StdType::Bool) ||
                    is_same(type_, StdType::Int) || is_classical_bit(type_)) {
                    return; // type of ~x is same as type of x
                }
                break;
            case UnaryOp::LogicalNot:
                if (general_castable(type_, StdType::Bool)) {
                    type_ = StdType::Bool;
                    return;
                }
                break;
            case UnaryOp::Neg:
                if (is_numeric_subtype(type_, StdType::Complex)) {
                    return; // type of -x is same as type of x
                }
                break;
        }
        std::cerr << exp.pos() << ": error : invalid operand to unary operator "
                  << exp.op() << " : '" << type_ << "' \n";
        error_ = true;
        type_ = NONE;
    }
    void visit(MathExpr& exp) override {
        switch (exp.op()) {
            case MathOp::Arccos:
            case MathOp::Arcsin:
            case MathOp::Arctan:
            case MathOp::Ceiling:
            case MathOp::Cos:
            case MathOp::Floor:
            case MathOp::Log:
            case MathOp::Sin:
            case MathOp::Tan:
                if (exp.num_args() != 1) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects one argument, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = NONE;
                    return;
                }
                visit_numeric_expr(exp.arg(0));
                type_ = StdType::Float; // assume we accept & return float
                break;
            case MathOp::Exp:
            case MathOp::Sqrt:
                if (exp.num_args() != 1) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects one argument, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = NONE;
                    return;
                }
                visit_classical_expr(
                    exp.arg(0), StdType::Complex); // return same type as input
                break;
            case MathOp::Rotl:
            case MathOp::Rotr:
                if (exp.num_args() != 2) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects two arguments, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = NONE;
                    return;
                }
                visit_classical_expr(exp.arg(0), CREG);
                visit_classical_expr(exp.arg(1), StdType::Int);
                type_ = CREG;
                break;
            case MathOp::Popcount:
                if (exp.num_args() != 1) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects one argument, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = NONE;
                    return;
                }
                visit_classical_expr(exp.arg(0), CREG);
                type_ = StdType::Int;
                break;
            case MathOp::Mod:
            case MathOp::Pow: {
                if (exp.num_args() != 2) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects two arguments, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = NONE;
                    return;
                }
                visit_classical_expr(exp.arg(0), StdType::Complex);
                auto tmp = type_;
                visit_classical_expr(exp.arg(1), tmp);
                type_ = tmp; // return same type as first parameter
                break;
            }
            case MathOp::Real:
            case MathOp::Imag:
                if (exp.num_args() != 1) {
                    std::cerr << exp.pos() << ": error : " << exp.op()
                              << " expects one argument, but got "
                              << exp.num_args() << "\n";
                    error_ = true;
                    type_ = NONE;
                    return;
                }
                visit_classical_expr(exp.arg(0), StdType::Complex);
                type_ = StdType::Float; // return float component
                break;
        }
    }
    void visit(CastExpr& exp) override {
        exp.type().accept(*this);
        auto tmp = type_;
        exp.subexp().accept(*this);
        if (!general_castable(type_, tmp)) {
            std::cerr << exp.pos() << ": error : cannot cast '" << type_
                      << "' to '" << tmp << "' \n";
            error_ = true;
        }
        type_ = tmp;
    }
    void visit(SizeofExpr& exp) override {
        if (exp.dim()) {
            visit_classical_expr(**exp.dim(), StdType::Int);
        }
        exp.arr().accept(*this);
        if (!std::holds_alternative<ArrType>(type_)) {
            std::cerr << exp.pos()
                      << ": error : sizeof() expects array type, but got '"
                      << type_ << "' \n";
            error_ = true;
        }
        type_ = StdType::Int;
    }
    void visit(FunctionCall& exp) override {
        auto entry = lookup(exp.name());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.name() << "\"\n";
            error_ = true;
            type_ = NONE;
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
                    if (!general_castable(type_, subrtn_type.param_types[i])) {
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
            type_ = NONE;
        }
    }
    void visit(AccessExpr& exp) override {
        exp.exp().accept(*this);
        exp.index_op().accept(*this);
    }
    void visit(ConstantExpr&) override { type_ = StdType::Float; }
    void visit(IntExpr&) override { type_ = StdType::Int; }
    void visit(RealExpr&) override { type_ = StdType::Float; }
    void visit(ImagExpr&) override { type_ = StdType::Complex; }
    void visit(BoolExpr&) override { type_ = StdType::Bool; }
    void visit(VarExpr& exp) override {
        auto entry = lookup(exp.var());
        if (!entry) {
            std::cerr << exp.pos() << ": error : undefined identifier \""
                      << exp.var() << "\"\n";
            error_ = true;
            type_ = NONE;
        } else if (std::holds_alternative<ExprType>(*entry)) {
            type_ = std::get<ExprType>(*entry);
        } else {
            std::cerr << exp.pos() << ": error : invalid expression \""
                      << exp.var() << "\"\n";
            error_ = true;
            type_ = NONE;
        }
    }
    void visit(BitString&) override { type_ = CREG; }
    void visit(ArrayInitExpr& exp) override {
        auto tmp = std::get<ArrType>(expected_array_type_);
        if (tmp.dims > 1) {
            auto next_tmp = ArrType{tmp.subtype, tmp.dims - 1};
            expected_array_type_ = next_tmp;
            for (int i = 0; i < exp.size(); i++) {
                visit_classical_expr(exp.at(i), next_tmp);
            }
        } else {
            for (int i = 0; i < exp.size(); i++) {
                visit_classical_expr(exp.at(i), tmp.subtype);
            }
        }
        expected_array_type_ = tmp;
        type_ = tmp;
    }
    void visit(TimeExpr&) override { type_ = StdType::Duration; }
    void visit(DurationofExpr& exp) override {
        auto tmp = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Quantum;
        push_scope();
        exp.block().accept(*this);
        pop_scope();
        expected_stmt_type_ = tmp;
        type_ = StdType::Duration;
    }
    void visit(MeasureExpr& msmt) override {
        visit_quantum_indexid(msmt.q_arg());
        type_ = CREG;
    }
    // Statements
    void visit(Annotation&) override {}
    void visit(ProgramBlock& block) override {
        block.foreach_stmt([this](Stmt& stmt) {
            if (!is_stmt_subtype(stmt.stmt_type(), expected_stmt_type_)) {
                std::cerr << stmt.pos() << ": error : expected '"
                          << expected_stmt_type_ << "' but got '"
                          << stmt.stmt_type() << "'\n";
                error_ = true;
            }
            if (!stmt.annotations().empty()) {
                std::cerr << stmt.pos()
                          << ": warning : annotation(s) ignored by semantic "
                             "checker\n";
            }
            stmt.accept(*this);
        });
    }
    void visit(ExprStmt& stmt) override { stmt.exp().accept(*this); }
    void visit(ResetStmt& stmt) override {
        visit_quantum_indexid(stmt.q_arg());
    }
    void visit(BarrierStmt& stmt) override {
        stmt.foreach_arg([this](IndexId& arg) { visit_quantum_indexid(arg); });
    }
    void visit(IfStmt& stmt) override {
        visit_classical_expr(stmt.cond(), StdType::Bool);

        auto tmp = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Regular;
        push_scope();
        stmt.then().accept(*this);
        pop_scope();

        push_scope();
        stmt.els().accept(*this);
        pop_scope();
        expected_stmt_type_ = tmp;
    }
    void visit(BreakStmt& stmt) override {
        if (!in_loop_) {
            std::cerr << stmt.pos() << ": error : unexpected break statement\n";
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
        if (stmt.value()) {
            visit_classical_expr(**stmt.value(), *return_type_);
        } else {
            if (!std::holds_alternative<NoneType>(*return_type_)) {
                std::cerr << stmt.pos()
                          << ": error : non-void subroutine "
                             "should return a value\n";
                error_ = true;
            }
        }
    }
    void visit(EndStmt& stmt) override {
        if (return_type_) {
            std::cerr << stmt.pos()
                      << ": error : cannot end program inside a subroutine\n";
            error_ = true;
        }
    }
    void visit(AliasStmt& stmt) override {
        stmt.foreach_reg([this](Expr& reg) {
            reg.accept(*this);
            if (!is_quantum(type_)) {
                std::cerr << reg.pos() << ": error : expected quantum type\n";
                error_ = true;
            }
        });
        set(stmt.alias(), type_, stmt.pos());
    }
    void visit(AssignmentStmt& stmt) override {
        stmt.lval().accept(*this);
        auto tmp = type_;
        if (!is_classical(tmp)) {
            std::cerr << stmt.pos() << ": error : expected classical type\n";
            error_ = true;
            type_ = NONE;
            return;
        }
        check_mutable(stmt.lval());
        /* replace 'x [op]= y' with 'x = x [op] y' */
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
            auto lexp = ptr<Expr>(new VarExpr(stmt.pos(), stmt.lval().var()));
            stmt.lval().foreach_index_op([this, &lexp](IndexOp& op) {
                lexp = ptr<Expr>(
                    new AccessExpr({}, std::move(lexp), object::clone(op)));
            });
            stmt.set_exp(ptr<Expr>(new BExpr(stmt.pos(), std::move(lexp), bop,
                                             object::clone(stmt.exp()))));
            stmt.set_op(AssignOp::Equals);
        }
        visit_classical_expr(stmt.exp(), tmp);
    }
    void visit(PragmaStmt& stmt) override {
        std::cerr << stmt.pos()
                  << ": warning : pragma ignored by semantic checker\n";
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
        visit_classical_expr(mod.r(), StdType::Float);
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
        // assume type_ has been set to the loop variable type
        if (!is_same(type_, StdType::Int)) {
            std::cerr << set.pos()
                      << ": error : range set is incompatible with non-int "
                         "loop variable\n";
            error_ = true;
        }
        visit_optional_classical_expr(set.start(), StdType::Int);
        visit_optional_classical_expr(set.step(), StdType::Int);
        visit_optional_classical_expr(set.stop(), StdType::Int);
    }
    void visit(ListSet& set) override {
        // assume type_ has been set to the loop variable type
        auto tmp = type_;
        for (auto& index : set.indices()) {
            visit_classical_expr(*index, tmp);
        }
    }
    void visit(VarSet& vs) override {
        // assume type_ has been set to the loop variable type, and is StdType
        auto tmp = std::get<StdType>(type_);
        auto entry = lookup(vs.var());
        if (!entry) {
            std::cerr << vs.pos() << ": error : undefined identifier \""
                      << vs.var() << "\"\n";
            error_ = true;
        } else if (std::holds_alternative<ExprType>(*entry)) {
            if (!is_same(std::get<ExprType>(*entry), ArrType{tmp, 1})) {
                std::cerr << vs.pos() << ": error : identifier \"" << vs.var()
                          << "\" is not of type array[int, #dim = 1]\n";
                error_ = true;
            }
        } else {
            std::cerr << vs.pos() << ": error : cannot loop over identifier \""
                      << vs.var() << "\"\n";
            error_ = true;
        }
    }
    void visit(ForStmt& stmt) override {
        stmt.var_type().accept(*this);
        auto tmp = type_;
        if (!std::holds_alternative<StdType>(tmp)) {
            std::cerr << stmt.pos()
                      << ": error : loop variable must be non-array type\n";
            error_ = true;
            return;
        }
        stmt.index_set().accept(*this);

        bool was_in_loop = in_loop_;
        in_loop_ = true;

        auto tmp_stmt = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Regular;
        if (tmp_stmt == Stmt::Type::Quantum) { // maintain quantum stmt scope
            expected_stmt_type_ = Stmt::Type::Quantum;
        }
        push_scope();
        set(stmt.var(), tmp, stmt.pos());
        stmt.body().accept(*this);
        pop_scope();
        expected_stmt_type_ = tmp_stmt;

        in_loop_ = was_in_loop;
    }
    void visit(WhileStmt& stmt) override {
        visit_classical_expr(stmt.cond(), StdType::Bool);

        bool was_in_loop = in_loop_;
        in_loop_ = true;

        auto tmp = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Regular;
        if (tmp == Stmt::Type::Quantum) { // maintain quantum stmt scope
            expected_stmt_type_ = Stmt::Type::Quantum;
        }
        push_scope();
        stmt.body().accept(*this);
        pop_scope();
        expected_stmt_type_ = tmp;

        in_loop_ = was_in_loop;
    }
    // Timing Statements
    void visit(DelayStmt& delay) override {
        visit_classical_expr(delay.duration(), StdType::Duration);
        for (int i = 0; i < delay.num_qargs(); i++) {
            visit_quantum_indexid(delay.qarg(i));
        }
    }
    void visit(BoxStmt& box) override {
        visit_optional_classical_expr(box.duration(), StdType::Duration);
        auto tmp = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Quantum;
        push_scope();
        box.circuit().accept(*this);
        pop_scope();
        expected_stmt_type_ = tmp;
    }
    // Declarations
    void visit(Param& param) override { param.type().accept(*this); }
    void visit(SubroutineDecl& decl) override {
        // function signature
        std::vector<ExprType> param_types;
        std::vector<symbol> param_names;
        for (auto& param : decl.params()) {
            param->accept(*this);
            param_types.push_back(type_);
            param_names.push_back(param->id());
        }

        // return type
        type_ = NONE;
        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        // declare before visiting body to allow recursion
        set(decl.id(), SubroutineType{param_types, type_}, decl.pos());

        // add parameter declarations and visit body
        return_type_ = type_;
        auto tmp = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Regular;
        push_scope();

        for (int i = 0; i < param_types.size(); i++) {
            set(param_names[i], param_types[i], decl.pos());
        }
        decl.body().accept(*this);

        pop_scope();
        expected_stmt_type_ = tmp;
        return_type_ = std::nullopt;
    }
    void visit(ExternDecl& decl) override {
        std::vector<ExprType> param_types;

        for (auto& type : decl.param_types()) {
            type->accept(*this);
            param_types.push_back(type_);
        }

        type_ = NONE;
        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        set(decl.id(), SubroutineType{param_types, type_}, decl.pos());
    }
    void visit(GateDecl& decl) override {
        auto tmp = expected_stmt_type_;
        expected_stmt_type_ = Stmt::Type::Quantum;
        push_scope();

        for (const ast::symbol& param : decl.c_params()) {
            set(param, StdType::Float, decl.pos());
        }
        for (const ast::symbol& param : decl.q_params()) {
            set(param, StdType::QuantumBit, decl.pos());
        }
        decl.body().accept(*this);

        pop_scope();
        expected_stmt_type_ = tmp;

        set(decl.id(),
            GateType{(int)decl.c_params().size(), (int)decl.q_params().size()},
            decl.pos());
    }
    void visit(QuantumDecl& decl) override {
        decl.type().accept(*this);
        set(decl.id(), type_, decl.pos());
    }
    void visit(ClassicalDecl& decl) override {
        if (decl.is_const()) {
            // assume constants have already been substituted
            set(decl.id(), NONE, decl.pos());
        } else {
            decl.type().accept(*this);
            auto tmp = type_;
            set(decl.id(), tmp, decl.pos());
            if (std::holds_alternative<ArrType>(tmp)) {
                expected_array_type_ = std::get<ArrType>(tmp);
            }
            visit_optional_classical_expr(decl.equalsexp(), tmp);
            expected_array_type_ = NONE;
        }
    }
    void visit(IODecl& decl) override {
        decl.type().accept(*this);
        set(decl.id(), type_, decl.pos());
    }
    // Program
    void visit(Program& prog) override {
        expected_stmt_type_ = Stmt::Type::Global;
        push_scope();
        prog.foreach_stmt([this](Stmt& stmt) {
            if (!stmt.annotations().empty()) {
                std::cerr << stmt.pos()
                          << ": warning : annotation(s) ignored by semantic "
                             "checker\n";
            }
            stmt.accept(*this);
        });
        pop_scope();
    }

  private:
    const NoneType NONE{};
    const ArrType CREG{StdType::ClassicalBit, 1};

    bool error_ = false;   ///< whether errors have occurred
    bool in_loop_ = false; ///< whether we are in the body of a loop
    int control_bits_ = 0; ///< number of control bits from control modifiers
    std::list<std::unordered_map<ast::symbol, Type>> symbol_table_{
        {}};               ///< a stack of symbol tables
    ExprType type_ = NONE; ///< type of current expression
    std::optional<ExprType> return_type_ =
        std::nullopt; ///< return type of subroutine
    Stmt::Type expected_stmt_type_ = Stmt::Type::Global; ///< allowed stmt types
    ExprType expected_array_type_ = NONE; ///< allowed array types

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
        if (symbol_table_.empty()) {
            throw std::logic_error("No current symbol table!");
        } else if (lookup_local(id)) {
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
    void visit_classical_expr(Expr& exp, const ExprType& expected_type) {
        exp.accept(*this);
        if (!general_castable(type_, expected_type)) {
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
                                       const ExprType& expected_type) {
        if (exp) {
            visit_classical_expr(**exp, expected_type);
        }
    }

    /**
     * \brief Visit a classical expression in the AST with numeric type
     *
     * \param exp Reference to the expression
     */
    void visit_numeric_expr(Expr& exp) {
        exp.accept(*this);
        if (std::holds_alternative<StdType>(type_)) {
            auto t = std::get<StdType>(type_);
            if (t == StdType::Int || t == StdType::Float ||
                t == StdType::Angle) {
                return;
            }
        }
        std::cerr << exp.pos() << ": error : expected numeric type, but got '"
                  << type_ << "' type : \"" << exp << "\"\n";
        error_ = true;
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

    /**
     * \brief Check that an lvalue is mutable
     *
     * \param indexid Reference to the lvalue
     */
    void check_mutable(IndexId& lval) {
        auto entry = lookup(lval.var());
        if (entry && std::holds_alternative<ExprType>(*entry)) {
            auto tmp = std::get<ExprType>(*entry);
            if (std::holds_alternative<ArrType>(tmp)) {
                if (!std::get<ArrType>(tmp).is_mutable) {
                    std::cerr << lval.pos() << ": error : lvalue '"
                              << lval.var() << "' must be mutable\n";
                    error_ = true;
                }
            }
        }
    }
};

/**
 * \brief Checks a program for semantic errors
 */
inline void check_source(Program& prog) {
    if (ConstExprChecker().run(prog) || TypeChecker().run(prog)) {
        throw SemanticError();
    }
}

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_SEMANTIC_HPP_ */
