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
 * \file qasmtools/ast/stmt.hpp
 * \brief openQASM statements
 */

#pragma once

#include "base.hpp"
#include "exprbase.hpp"
#include "indexid.hpp"
#include "stmtbase.hpp"
#include "stmtblock.hpp"
#include "../utils/templates.hpp"

#include <functional>
#include <list>
#include <variant>
#include <vector>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::QuantumMeasurement
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
     * \return Const reference to the quantum argument
     */
    const IndexId& q_arg() const { return *q_arg_; }

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
 * \class qasmtools::ast::MeasureStmt
 * \brief Class for quantum measurement statements
 * \see qasmtools::ast::StmtBase
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << *measurement_ << ";\n";
        return os;
    }
  protected:
    MeasureStmt* clone() const override {
        return new MeasureStmt(pos_, object::clone(*measurement_));
    }
};

/**
 * \class qasmtools::ast::ExprStmt
 * \brief Class for expression statements
 * \see qasmtools::ast::StmtBase
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << exp_ << ";\n";
        return os;
    }
  protected:
    ExprStmt* clone() const override {
        return new ExprStmt(pos_, object::clone(*exp_));
    }
};

/**
 * \class qasmtools::ast::MeasureAsgnStmt
 * \brief Class for measurement assignment statements
 * \see qasmtools::ast::StmtBase
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
        : Stmt(pos), measurement_(std::move(qm)), c_arg_(std::move(c_arg))
    {}

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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
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
 * \class qasmtools::ast::ResetStmt
 * \brief Class for reset statements
 * \see qasmtools::ast::StmtBase
 */
class ResetStmt final : public QuantumStmt {
    std::vector<ptr<IndexId>> args_; ///< list of quantum bits|registers

  public:
    /**
     * \brief Constructs a reset statement
     *
     * \param pos The source position
     * \param arg Rvalue reference to the list of arguments
     */
    ResetStmt(parser::Position pos, std::vector<ptr<IndexId>>&& args)
        : QuantumStmt(pos), args_(std::move(args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ResetStmt> create(parser::Position pos,
                                 std::vector<ptr<IndexId>>&& args) {
        return std::make_unique<ResetStmt>(pos, std::move(args));
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
     * \param i The index
     * \return Reference to the argument
     */
    IndexId& arg(int i) { return *args_[i]; }

    /**
     * \brief Apply a function to each argument
     *
     * \param f Void function accepting a reference to the argument
     */
    void foreach_arg(std::function<void(IndexId&)> f) {
        for (auto& x: args_)
            f(*x);
    }

    /**
     * \brief Set the ith argument
     *
     * \param arg Const reference to a new argument
     */
    void set_arg(int i, ptr<IndexId> arg) { args_[i] = std::move(arg); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "reset";
        for (auto it = args_.begin(); it != args_.end(); it++)
            os << (it == args_.begin() ? " " : ", ") << **it;
        os << ";\n";
        return os;
    }
  protected:
    ResetStmt* clone() const override {
        std::vector<ptr<IndexId>> tmp;
        for (auto& x : args_)
            tmp.emplace_back(object::clone(*x));
        return new ResetStmt(pos_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::BarrierStmt
 * \brief Class for barrier statement
 * \see qasmtools::ast::StmtBase
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
        for (auto& x: args_)
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
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
 * \class qasmtools::ast::IfStmt
 * \brief Class for if statements
 * \see qasmtools::ast::StmtBase
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "if (" << *cond_ << ") " << *then_;
        if (!(else_->body().empty()))
            os << "else " << *else_;
        return os;
    }
  protected:
    IfStmt* clone() const override {
        return new IfStmt(pos_, object::clone(*cond_), object::clone(*then_),
                          object::clone(*else_));
    }
};

/**
 * \class qasmtools::ast::BreakStmt
 * \brief Class for "break" statements
 * \see qasmtools::ast::StmtBase
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "break;\n";
        return os;
    }
  protected:
    BreakStmt* clone() const override { return new BreakStmt(pos_); }
};

/**
 * \class qasmtools::ast::ContinueStmt
 * \brief Class for "continue" statements
 * \see qasmtools::ast::StmtBase
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "continue;\n";
        return os;
    }
  protected:
    ContinueStmt* clone() const override { return new ContinueStmt(pos_); }
};

/**
 * \class qasmtools::ast::ReturnStmt
 * \brief Class for "return" statements
 * \see qasmtools::ast::StmtBase
 */
class ReturnStmt final : public ControlStmt {
    using RetType = std::variant<std::monostate,
                                 ptr<QuantumMeasurement>,
                                 ptr<Expr>>;
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
     * \brief Get the classical parameter list
     *
     * \return Reference to the list of classical parameters
     */
    RetType& value() { return value_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        std::visit(
            utils::overloaded{
                [&os](const ptr<QuantumMeasurement>& qm) {
                    os << "return " << *qm << ";\n";
                },
                [&os](const ptr<Expr>& exp) {
                    os << "return " << *exp << ";\n";
                },
                [&os](auto) {
                    os << "return;\n";
                }},
            value_);
        return os;
    }
  protected:
    ReturnStmt* clone() const override {
        RetType value_copy = std::monostate();
        std::visit(
            utils::overloaded{
                [&value_copy](const ptr<QuantumMeasurement>& qm) {
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
 * \class qasmtools::ast::EndStmt
 * \brief Class for "end" statements
 * \see qasmtools::ast::StmtBase
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
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "end;\n";
        return os;
    }
  protected:
    EndStmt* clone() const override { return new EndStmt(pos_); }
};

/**
 * \class qasmtools::ast::AliasStmt
 * \brief Class for alias statements
 * \see qasmtools::ast::StmtBase
 */
class AliasStmt final : public Stmt {
    symbol alias_;      ///< the alias name
    ptr<IndexId> qreg_; ///< the quantum bit|register

  public:
    /**
     * \brief Constructs an alias statement
     *
     * \param pos The source position
     * \param alias The alias name
     * \param qreq The quantum bit|register
     */
    AliasStmt(parser::Position pos, symbol alias, ptr<IndexId> qreg)
        : Stmt(pos), alias_(alias), qreg_(std::move(qreg)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<AliasStmt> create(parser::Position pos, symbol alias,
                                 ptr<IndexId> qreg) {
        return std::make_unique<AliasStmt>(pos, alias, std::move(qreg));
    }

    /**
     * \brief Get the alias name
     *
     * \return Const reference to the alias name
     */
    const symbol& alias() const { return alias_; }

    /**
     * \brief Get the quantum bit|register
     *
     * \return Reference to the quantum bit|register
     */
    IndexId& qreg() { return *qreg_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "let " << alias_ << " = " << *qreg_ << ";\n";
        return os;
    }
  protected:
    AliasStmt* clone() const override {
        return new AliasStmt(pos_, alias_, object::clone(*qreg_));
    }
};

/**
 * \brief Enum of assignment operators
 */
enum class AssignOp { Equals, Plus, Minus, Times, Div, BitAnd, BitOr,
        Tilde, XOr, LeftBitShift, RightBitShift, Mod, Pow };
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
 * \class qasmtools::ast::AssignmentStmt
 * \brief Class for assignment statements
 * \see qasmtools::ast::StmtBase
 */
class AssignmentStmt final : public Stmt {
    symbol var_;                     ///< the variable being assigned to
    std::optional<ptr<Expr>> index_; ///< the variable index
    AssignOp op_;                    ///< the assignment operator
    ptr<Expr> exp_;                  ///< the expression

  public:
    /**
     * \brief Constructs an assignment statement
     *
     * \param pos The source position
     * \param var The variable name
     * \param index Optional index (default = std::nullopt)
     * \param op The assignment operator
     * \param exp The expression
     */
    AssignmentStmt(parser::Position pos, symbol var, AssignOp op, ptr<Expr> exp)
        : Stmt(pos), var_(var), index_(std::nullopt), op_(op),
          exp_(std::move(exp)) {}
    AssignmentStmt(parser::Position pos, symbol var,
                   std::optional<ptr<Expr>>&& index, AssignOp op, ptr<Expr> exp)
        : Stmt(pos), var_(var), index_(std::move(index)), op_(op),
          exp_(std::move(exp)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<AssignmentStmt> create(parser::Position pos, symbol var,
                                      AssignOp op, ptr<Expr> exp) {
        return std::make_unique<AssignmentStmt>(pos, var, op, std::move(exp));
    }
    static ptr<AssignmentStmt> create(parser::Position pos, symbol var,
                                      std::optional<ptr<Expr>>&& index,
                                      AssignOp op, ptr<Expr> exp) {
        return std::make_unique<AssignmentStmt>(pos, var, std::move(index), op,
                                                std::move(exp));
    }

    /**
     * \brief Get the variable name
     *
     * \return Const reference to the variable name
     */
    const symbol& var() const { return var_; }

    /**
     * \brief Get the variable index
     *
     * \return Reference to the vairable index
     */
    std::optional<ptr<Expr>>& index() { return index_; }

    /**
     * \brief Get the assignment operator
     *
     * \return Ann assignment operator enum
     */
    AssignOp op() const { return op_; }

    /**
     * \brief Get the expression
     *
     * \return Reference to the expression
     */
    Expr& exp() { return *exp_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << var_;
        if (index_)
            os << "[" << **index_ << "]";
        os << " " << op_ << " " << *exp_ << ";\n";
        return os;
    }
  protected:
    AssignmentStmt* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (index_)
            tmp = object::clone(**index_);
        return new AssignmentStmt(pos_, var_, std::move(tmp), op_,
                                  object::clone(*exp_));
    }
};

/**
 * \class qasmtools::ast::PragmaStmt
 * \brief Class for pragma statements
 * \see qasmtools::ast::StmtBase
 */
class PragmaStmt final : public GlobalStmt {
    std::list<ptr<Stmt>> body_; ///< list of statements

  public:
    /**
     * \brief Constructs a pragma statement
     *
     * \param pos The source position
     * \param arg Rvalue reference to the list of statements
     */
    PragmaStmt(parser::Position pos, std::list<ptr<Stmt>>&& body)
        : GlobalStmt(pos), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<PragmaStmt> create(parser::Position pos,
                                  std::list<ptr<Stmt>>&& body) {
        return std::make_unique<PragmaStmt>(pos, std::move(body));
    }

    /**
     * \brief Get the list of statements
     *
     * \return Reference to the list of statements
     */
    std::list<ptr<Stmt>>& body() { return body_; }

    /**
     * \brief Apply a function to each statement
     *
     * \param f Void function accepting a reference to the statement
     */
    void foreach_stmt(std::function<void(Stmt&)> f) {
        for (auto& x: body_)
            f(*x);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "#pragma {\n";
        for (auto& x: body_)
            os << "\t" << *x;
        os << "}\n";
        return os;
    }
  protected:
    PragmaStmt* clone() const override {
        std::list<ptr<Stmt>> tmp;
        for (auto& x : body_)
            tmp.emplace_back(object::clone(*x));
        return new PragmaStmt(pos_, std::move(tmp));
    }
};

} // namespace ast
} // namespace qasmtools
