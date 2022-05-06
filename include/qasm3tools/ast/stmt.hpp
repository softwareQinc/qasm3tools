/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2022 softwareQ Inc. All rights reserved.
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
 * \file qasm3tools/ast/stmt.hpp
 * \brief OpenQASM statements
 */

#pragma once

#include "../utils/templates.hpp"
#include "base.hpp"
#include "exprbase.hpp"
#include "indexid.hpp"
#include "stmtbase.hpp"
#include "stmtblock.hpp"

#include <functional>
#include <list>
#include <variant>
#include <vector>

namespace qasm3tools {
namespace ast {

/**
 * \class qasm3tools::ast::QuantumMeasurement
 * \brief Class for quantum measurements
 */
class QuantumMeasurement final : public ASTNode {
    ptr<IndexId> q_arg_; ///< the quantum bit|register

  public:
    /**
     * \brief Constructs a quantum measurement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     */
    QuantumMeasurement(parser::Position pos, ptr<IndexId> q_arg)
        : ASTNode(pos), q_arg_(std::move(q_arg)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<QuantumMeasurement> create(parser::Position pos,
                                          ptr<IndexId> q_arg) {
        return std::make_unique<QuantumMeasurement>(pos, std::move(q_arg));
    }

    /**
     * \brief Get the quantum argument
     *
     * \return Reference to the quantum argument
     */
    IndexId& q_arg() { return *q_arg_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "measure " << *q_arg_;
        return os;
    }

  protected:
    QuantumMeasurement* clone() const override {
        return new QuantumMeasurement(pos_, object::clone(*q_arg_));
    }
};

/**
 * \class qasm3tools::ast::MeasureStmt
 * \brief Class for quantum measurement statements
 * \see qasm3tools::ast::StmtBase
 */
class MeasureStmt final : public QuantumStmt {
    ptr<QuantumMeasurement> measurement_; ///< the quantum measurement

  public:
    /**
     * \brief Constructs a measurement statement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     */
    MeasureStmt(parser::Position pos, ptr<QuantumMeasurement> qm)
        : QuantumStmt(pos), measurement_(std::move(qm)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<MeasureStmt> create(parser::Position pos,
                                   ptr<QuantumMeasurement> qm) {
        return std::make_unique<MeasureStmt>(pos, std::move(qm));
    }

    /**
     * \brief Get the quantum measurement
     *
     * \return Reference to the quantum measurement
     */
    QuantumMeasurement& measurement() { return *measurement_; }

    /**
     * \brief Set the quantum argument
     *
     * \param arg Const reference to a new argument
     */
    void set_measurement(ptr<QuantumMeasurement> qm) {
        measurement_ = std::move(qm);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << *measurement_ << ";\n";
        return os;
    }

  protected:
    MeasureStmt* clone() const override {
        return new MeasureStmt(pos_, object::clone(*measurement_));
    }
};

/**
 * \class qasm3tools::ast::MeasureAsgnStmt
 * \brief Class for measurement assignment statements
 * \see qasm3tools::ast::StmtBase
 */
class MeasureAsgnStmt final : public Stmt {
    ptr<QuantumMeasurement> measurement_; ///< the quantum measurement
    ptr<IndexId> c_arg_;                  ///< the classical bit|register

  public:
    /**
     * \brief Constructs a measurement statement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     * \param c_arg Rvalue reference to the classical argument
     */
    MeasureAsgnStmt(parser::Position pos, ptr<QuantumMeasurement> qm,
                    ptr<IndexId> c_arg)
        : Stmt(pos), measurement_(std::move(qm)), c_arg_(std::move(c_arg)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<MeasureAsgnStmt> create(parser::Position pos,
                                       ptr<QuantumMeasurement> qm,
                                       ptr<IndexId> c_arg) {
        return std::make_unique<MeasureAsgnStmt>(pos, std::move(qm),
                                                 std::move(c_arg));
    }

    /**
     * \brief Get the quantum measurement
     *
     * \return Reference to the quantum measurement
     */
    QuantumMeasurement& measurement() { return *measurement_; }

    /**
     * \brief Get the classical argument
     *
     * \return Reference to the classical argument
     */
    IndexId& c_arg() { return *c_arg_; }

    /**
     * \brief Set the quantum measurement
     *
     * \param arg Const reference to a new measurement
     */
    void set_measurement(ptr<QuantumMeasurement> qm) {
        measurement_ = std::move(qm);
    }

    /**
     * \brief Set the classical argument
     *
     * \param arg Const reference to a new argument
     */
    void set_carg(ptr<IndexId> arg) { c_arg_ = std::move(arg); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << *c_arg_ << " = " << *measurement_ << ";\n";
        return os;
    }

  protected:
    MeasureAsgnStmt* clone() const override {
        return new MeasureAsgnStmt(pos_, object::clone(*measurement_),
                                   object::clone(*c_arg_));
    }
};

/**
 * \class qasm3tools::ast::ExprStmt
 * \brief Class for expression statements
 * \see qasm3tools::ast::StmtBase
 */
class ExprStmt final : public Stmt {
    ptr<Expr> exp_; ///< the expression

  public:
    /**
     * \brief Constructs an expression statement
     *
     * \param pos The source position
     * \param exp The expression
     */
    ExprStmt(parser::Position pos, ptr<Expr> exp)
        : Stmt(pos), exp_(std::move(exp)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ExprStmt> create(parser::Position pos, ptr<Expr> exp) {
        return std::make_unique<ExprStmt>(pos, std::move(exp));
    }

    /**
     * \brief Get the expression
     *
     * \return Reference to the expression
     */
    Expr& exp() { return *exp_; }

    /**
     * \brief Set the expression
     *
     * \param exp The new expression
     */
    void set_exp(ptr<Expr> exp) { exp_ = std::move(exp); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << *exp_ << ";\n";
        return os;
    }

  protected:
    ExprStmt* clone() const override {
        return new ExprStmt(pos_, object::clone(*exp_));
    }
};

/**
 * \class qasm3tools::ast::ResetStmt
 * \brief Class for reset statements
 * \see qasm3tools::ast::StmtBase
 */
class ResetStmt final : public QuantumStmt {
    ptr<IndexId> q_arg_; ///< the quantum bit|register

  public:
    /**
     * \brief Constructs a reset statement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     */
    ResetStmt(parser::Position pos, ptr<IndexId> q_arg)
        : QuantumStmt(pos), q_arg_(std::move(q_arg)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ResetStmt> create(parser::Position pos, ptr<IndexId> q_arg) {
        return std::make_unique<ResetStmt>(pos, std::move(q_arg));
    }

    /**
     * \brief Get the quantum argument
     *
     * \return Reference to the quantum argument
     */
    IndexId& q_arg() { return *q_arg_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "reset " << *q_arg_ << ";\n";
        return os;
    }

  protected:
    ResetStmt* clone() const override {
        return new ResetStmt(pos_, object::clone(*q_arg_));
    }
};

/**
 * \class qasm3tools::ast::BarrierStmt
 * \brief Class for barrier statement
 * \see qasm3tools::ast::StmtBase
 */
class BarrierStmt final : public QuantumStmt {
    std::vector<ptr<IndexId>> args_; ///< list of quantum bits|registers

  public:
    /**
     * \brief Constructs a barrier gate
     *
     * \param pos The source position
     * \param args Rvalue reference to a list of arguments
     */
    BarrierStmt(parser::Position pos, std::vector<ptr<IndexId>>&& args)
        : QuantumStmt(pos), args_(std::move(args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BarrierStmt> create(parser::Position pos,
                                   std::vector<ptr<IndexId>>&& args) {
        return std::make_unique<BarrierStmt>(pos, std::move(args));
    }

    /**
     * \brief Get the number of arguments
     *
     * \return The number of arguments
     */
    int num_args() const { return static_cast<int>(args_.size()); }

    /**
     * \brief Get the list of arguments
     *
     * \return Reference to the list of arguments
     */
    std::vector<ptr<IndexId>>& args() { return args_; }

    /**
     * \brief Get the ith argument
     *
     * \param i The number of the argument (0 indexed)
     * \return Reference to the ith argument
     */
    IndexId& arg(int i) { return *args_[i]; }

    /**
     * \brief Apply a function to each argument
     *
     * \param f Void function accepting a reference to the argument
     */
    void foreach_arg(std::function<void(IndexId&)> f) {
        for (auto& x : args_)
            f(*x);
    }

    /**
     * \brief Set the ith argument
     *
     * \param i The number of the argument (0 indexed)
     * \param arg The new argument
     */
    void set_arg(int i, ptr<IndexId> arg) { args_[i] = std::move(arg); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "barrier";
        for (auto it = args_.begin(); it != args_.end(); it++)
            os << (it == args_.begin() ? " " : ",") << **it;
        os << ";\n";
        return os;
    }

  protected:
    BarrierStmt* clone() const override {
        std::vector<ptr<IndexId>> tmp;
        for (auto& x : args_)
            tmp.emplace_back(object::clone(*x));
        return new BarrierStmt(pos_, std::move(tmp));
    }
};

/**
 * \class qasm3tools::ast::IfStmt
 * \brief Class for if statements
 * \see qasm3tools::ast::StmtBase
 */
class IfStmt final : public Stmt {
    ptr<Expr> cond_;         ///< boolean expression to check
    ptr<ProgramBlock> then_; ///< block to be executed if true
    ptr<ProgramBlock> else_; ///< block to be executed if false

  public:
    /**
     * \brief Constructs an if statement
     *
     * \param pos The source position
     * \param cond The boolean to check
     * \param then The block to execute in the then branch
     * \param els The block to execute in the else branch
     */
    IfStmt(parser::Position pos, ptr<Expr> cond, ptr<ProgramBlock> then,
           ptr<ProgramBlock> els)
        : Stmt(pos), cond_(std::move(cond)), then_(std::move(then)),
          else_(std::move(els)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<IfStmt> create(parser::Position pos, ptr<Expr> cond,
                              ptr<ProgramBlock> then, ptr<ProgramBlock> els) {
        return std::make_unique<IfStmt>(pos, std::move(cond), std::move(then),
                                        std::move(els));
    }

    /**
     * \brief Get the boolean expression
     *
     * \return A reference to the boolean expression
     */
    Expr& cond() { return *cond_; }

    /**
     * \brief Set the boolean expression
     *
     * \param cond The new expression
     */
    void set_cond(ptr<Expr> cond) { cond_ = std::move(cond); }

    /**
     * \brief Get the then branch
     *
     * \return Reference to the "then" block
     */
    ProgramBlock& then() { return *then_; }

    /**
     * \brief Get the else branch
     *
     * \return Reference to the "else" block
     */
    ProgramBlock& els() { return *else_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "if (" << *cond_ << ") ";
        then_->pretty_print(os, indents);
        if (!(else_->body().empty())) {
            for (size_t i = 0; i < indents; i++)
                os << "\t";
            os << "else ";
            else_->pretty_print(os, indents);
        }
        return os;
    }

  protected:
    IfStmt* clone() const override {
        return new IfStmt(pos_, object::clone(*cond_), object::clone(*then_),
                          object::clone(*else_));
    }
};

/**
 * \class qasm3tools::ast::BreakStmt
 * \brief Class for "break" statements
 * \see qasm3tools::ast::StmtBase
 */
class BreakStmt final : public ControlStmt {

  public:
    /**
     * \brief Construct a break statement
     *
     * \param pos The source position
     */
    BreakStmt(parser::Position pos) : ControlStmt(pos) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BreakStmt> create(parser::Position pos) {
        return std::make_unique<BreakStmt>(pos);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "break;\n";
        return os;
    }

  protected:
    BreakStmt* clone() const override { return new BreakStmt(pos_); }
};

/**
 * \class qasm3tools::ast::ContinueStmt
 * \brief Class for "continue" statements
 * \see qasm3tools::ast::StmtBase
 */
class ContinueStmt final : public ControlStmt {

  public:
    /**
     * \brief Construct a continue statement
     *
     * \param pos The source position
     */
    ContinueStmt(parser::Position pos) : ControlStmt(pos) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ContinueStmt> create(parser::Position pos) {
        return std::make_unique<ContinueStmt>(pos);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "continue;\n";
        return os;
    }

  protected:
    ContinueStmt* clone() const override { return new ContinueStmt(pos_); }
};

/**
 * \class qasm3tools::ast::ReturnStmt
 * \brief Class for "return" statements
 * \see qasm3tools::ast::StmtBase
 */
class ReturnStmt final : public ControlStmt {
    using RetType =
        std::variant<std::monostate, ptr<QuantumMeasurement>, ptr<Expr>>;
    RetType value_;

  public:
    /**
     * \brief Construct a return statement
     *
     * \param pos The source position
     */
    ReturnStmt(parser::Position pos, RetType&& value)
        : ControlStmt(pos), value_(std::move(value)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ReturnStmt> create(parser::Position pos, RetType&& value) {
        return std::make_unique<ReturnStmt>(pos, std::move(value));
    }

    /**
     * \brief Get the returned expression
     *
     * \return Reference to the returned expression
     */
    RetType& value() { return value_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        std::visit(utils::overloaded{[&os](const ptr<QuantumMeasurement>& qm) {
                                         os << "return " << *qm << ";\n";
                                     },
                                     [&os](const ptr<Expr>& exp) {
                                         os << "return " << *exp << ";\n";
                                     },
                                     [&os](auto) { os << "return;\n"; }},
                   value_);
        return os;
    }

  protected:
    ReturnStmt* clone() const override {
        RetType value_copy = std::monostate();
        std::visit(
            utils::overloaded{[&value_copy](const ptr<QuantumMeasurement>& qm) {
                                  value_copy = object::clone(*qm);
                              },
                              [&value_copy](const ptr<Expr>& exp) {
                                  value_copy = object::clone(*exp);
                              },
                              [](auto) {}},
            value_);
        return new ReturnStmt(pos_, std::move(value_copy));
    }
};

/**
 * \class qasm3tools::ast::EndStmt
 * \brief Class for "end" statements
 * \see qasm3tools::ast::StmtBase
 */
class EndStmt final : public Stmt {

  public:
    /**
     * \brief Construct an end statement
     *
     * \param pos The source position
     */
    EndStmt(parser::Position pos) : Stmt(pos) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<EndStmt> create(parser::Position pos) {
        return std::make_unique<EndStmt>(pos);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "end;\n";
        return os;
    }

  protected:
    EndStmt* clone() const override { return new EndStmt(pos_); }
};

/**
 * \class qasm3tools::ast::AliasStmt
 * \brief Class for alias statements
 * \see qasm3tools::ast::StmtBase
 */
class AliasStmt final : public Stmt {
    symbol alias_;                ///< the alias name
    std::vector<ptr<Expr>> regs_; ///< concatenated quantum bits|registers

  public:
    /**
     * \brief Constructs an alias statement
     *
     * \param pos The source position
     * \param alias The alias name
     * \param regs The concatenated quantum bits|registers
     */
    AliasStmt(parser::Position pos, symbol alias,
              std::vector<ptr<Expr>>&& regs)
        : Stmt(pos), alias_(alias), regs_(std::move(regs)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<AliasStmt> create(parser::Position pos, symbol alias,
                                 std::vector<ptr<Expr>>&& regs) {
        return std::make_unique<AliasStmt>(pos, alias, std::move(regs));
    }

    /**
     * \brief Get the alias name
     *
     * \return Const reference to the alias name
     */
    const symbol& alias() const { return alias_; }

    /**
     * \brief Get the number of concatenated registers
     *
     * \return The number of concatenated registers
     */
    int num_regs() const { return static_cast<int>(regs_.size()); }

    /**
     * \brief Get the list of concatenated registers
     *
     * \return Reference to the list of concatenated registers
     */
    std::vector<ptr<Expr>>& regs() { return regs_; }

    /**
     * \brief Apply a function to each concatenated register
     *
     * \param f Void function accepting a reference to the argument
     */
    void foreach_reg(std::function<void(Expr&)> f) {
        for (auto& x : regs_)
            f(*x);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "let " << alias_ << " = ";
        for (auto it = regs_.begin(); it != regs_.end(); it++)
            os << (it == regs_.begin() ? "" : " ++ ") << **it;
        os << ";\n";
        return os;
    }

  protected:
    AliasStmt* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& x : regs_)
            tmp.emplace_back(object::clone(*x));
        return new AliasStmt(pos_, alias_, std::move(tmp));
    }
};

/**
 * \brief Enum of assignment operators
 */
enum class AssignOp {
    Equals,
    Plus,
    Minus,
    Times,
    Div,
    BitAnd,
    BitOr,
    Tilde,
    XOr,
    LeftBitShift,
    RightBitShift,
    Mod,
    Pow
};
inline std::ostream& operator<<(std::ostream& os, const AssignOp& aop) {
    switch (aop) {
        case AssignOp::Equals:
            os << "=";
            break;
        case AssignOp::Plus:
            os << "+=";
            break;
        case AssignOp::Minus:
            os << "-=";
            break;
        case AssignOp::Times:
            os << "*=";
            break;
        case AssignOp::Div:
            os << "/=";
            break;
        case AssignOp::BitAnd:
            os << "&=";
            break;
        case AssignOp::BitOr:
            os << "|=";
            break;
        case AssignOp::Tilde:
            os << "~=";
            break;
        case AssignOp::XOr:
            os << "^=";
            break;
        case AssignOp::LeftBitShift:
            os << "<<=";
            break;
        case AssignOp::RightBitShift:
            os << ">>=";
            break;
        case AssignOp::Mod:
            os << "%=";
            break;
        case AssignOp::Pow:
            os << "**=";
            break;
    }
    return os;
}

/**
 * \class qasm3tools::ast::AssignmentStmt
 * \brief Class for assignment statements
 * \see qasm3tools::ast::StmtBase
 */
class AssignmentStmt final : public Stmt {
    ptr<IndexId> var_; ///< target variable
    AssignOp op_;      ///< the assignment operator
    ptr<Expr> exp_;    ///< the expression

  public:
    /**
     * \brief Constructs an assignment statement
     *
     * \param pos The source position
     * \param var The target variable
     * \param op The assignment operator
     * \param exp The expression
     */
    AssignmentStmt(parser::Position pos, ptr<IndexId> var, AssignOp op, ptr<Expr> exp)
        : Stmt(pos), var_(std::move(var)), op_(op), exp_(std::move(exp)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<AssignmentStmt> create(parser::Position pos, ptr<IndexId> var,
                                      AssignOp op, ptr<Expr> exp) {
        return std::make_unique<AssignmentStmt>(pos, std::move(var), op,
                                                std::move(exp));
    }

    /**
     * \brief Get the target variable
     *
     * \return Reference to the target variable
     */
    IndexId& var() { return *var_; }

    /**
     * \brief Get the assignment operator
     *
     * \return An assignment operator enum
     */
    AssignOp op() const { return op_; }

    /**
     * \brief Set the assignment operator
     *
     * \param op The new assignment operator
     */
    void set_op(AssignOp op) { op_ = op; }

    /**
     * \brief Get the expression
     *
     * \return Reference to the expression
     */
    Expr& exp() { return *exp_; }

    /**
     * \brief Set the expression
     *
     * \param exp The new expression
     */
    void set_exp(ptr<Expr> exp) { exp_ = std::move(exp); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << *var_ << " " << op_ << " " << *exp_ << ";\n";
        return os;
    }

  protected:
    AssignmentStmt* clone() const override {
        return new AssignmentStmt(pos_, object::clone(*var_), op_,
                                  object::clone(*exp_));
    }
};

/**
 * \class qasm3tools::ast::PragmaStmt
 * \brief Class for pragma statements
 * \see qasm3tools::ast::StmtBase
 */
class PragmaStmt final : public GlobalStmt {
    ptr<ProgramBlock> body_; ///< pragma body

  public:
    /**
     * \brief Constructs a pragma statement
     *
     * \param pos The source position
     * \param body The pragma body
     */
    PragmaStmt(parser::Position pos, ptr<ProgramBlock> body)
        : GlobalStmt(pos), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<PragmaStmt> create(parser::Position pos,
                                  ptr<ProgramBlock> body) {
        return std::make_unique<PragmaStmt>(pos, std::move(body));
    }

    /**
     * \brief Get the pragma body
     *
     * \return Reference to the body
     */
    ProgramBlock& body() { return *body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "#pragma ";
        body_->pretty_print(os, indents);
        return os;
    }

  protected:
    PragmaStmt* clone() const override {
        return new PragmaStmt(pos_, object::clone(*body_));
    }
};

} // namespace ast
} // namespace qasm3tools
