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
#include "expr.hpp"
#include "var.hpp"
#include "../utils/templates.hpp"

#include <functional>
#include <optional>
#include <variant>
#include <vector>
#include <list>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::StmtBase
 * \brief Base class for openQASM statements
 */
class StmtBase : public ASTNode {
  public:
    StmtBase(parser::Position pos) : ASTNode(pos) {}
    virtual ~StmtBase() = default;

    /**
     * \brief Internal pretty-printer which can suppress the output of the
     * stdlib
     *
     * \param suppress_std Whether to suppress output of the standard library
     */
    virtual std::ostream& pretty_print(std::ostream& os,
                                       bool suppress_std) const = 0;

    std::ostream& pretty_print(std::ostream& os) const override {
        return pretty_print(os, false);
    }
  protected:
    virtual StmtBase* clone() const override = 0;
};
/**
 * \class qasmtools::ast::GlobalStmt
 * \brief Statement sub-class for global statements
 */
class GlobalStmt : public StmtBase {
  public:
    GlobalStmt(parser::Position pos) : StmtBase(pos) {}
    virtual ~GlobalStmt() = default;
  protected:
    virtual GlobalStmt* clone() const = 0;
};
/**
 * \class qasmtools::ast::Stmt
 * \brief Statement sub-class for local statements
 */
class Stmt : public StmtBase {
  public:
    Stmt(parser::Position pos) : StmtBase(pos) {}
    virtual ~Stmt() = default;
  protected:
    virtual Stmt* clone() const = 0;
};
/**
 * \class qasmtools::ast::QuantumStmt
 * \brief Statement sub-class for quantum statements
 */
class QuantumStmt : public Stmt {
  public:
    QuantumStmt(parser::Position pos) : Stmt(pos) {}
    virtual ~QuantumStmt() = default;
  protected:
    virtual QuantumStmt* clone() const = 0;
};
/**
 * \class qasmtools::ast::TimingStmt
 * \brief Statement sub-class for timing statements
 */
class TimingStmt : public QuantumStmt {
  public:
    TimingStmt(parser::Position pos) : QuantumStmt(pos) {}
    virtual ~TimingStmt() = default;
  protected:
    virtual TimingStmt* clone() const = 0;
};
/**
 * \class qasmtools::ast::ControlStmt
 * \brief Statement sub-class for control statements
 */
class ControlStmt : public StmtBase {
  public:
    ControlStmt(parser::Position pos) : StmtBase(pos) {}
    virtual ~ControlStmt() = default;
  protected:
    virtual ControlStmt* clone() const = 0;
};
/**
 * \class qasmtools::ast::QuantumLoop
 * \brief Statement sub-class for quantum loops
 */
class QuantumLoop : public StmtBase {
  public:
    QuantumLoop(parser::Position pos) : StmtBase(pos) {}
    virtual ~QuantumLoop() = default;
  protected:
    virtual QuantumLoop* clone() const = 0;
};



/**
 * \class qasmtools::ast::BlockBase
 * \brief Base class for program blocks
 * T is std::variant of allowed statement types
 * D is derived class
 */
template <typename T, typename D>
class BlockBase : public ASTNode {
  public:
    /**
     * \brief Constructs a program block
     *
     * \param pos The source position
     * \param body The block body
     */
    BlockBase(parser::Position pos, std::list<T>&& body)
        : ASTNode(pos), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<D> create(parser::Position pos, std::list<T>&& body) {
        return std::make_unique<D>(pos, std::move(body));
    }

    /**
     * \brief Get the block body
     *
     * \return Reference to the body as a list of statements
     */
    typename std::list<T>& body() { return body_; }

    /**
     * \brief Get an iterator to the beginning of the body
     *
     * \return std::list iterator
     */
    typename std::list<T>::iterator begin() { return body_.begin(); }

    /**
     * \brief Get an iterator to the end of the body
     *
     * \return std::list iterator
     */
    typename std::list<T>::iterator end() { return body_.end(); }

    virtual std::ostream& pretty_print(std::ostream& os) const override {
        os << "{\n";
        for (auto& x : body_) {
            std::visit([&os](auto& stmt) {
                stmt->pretty_print(os);
            }, x);
        }
        os << "}\n";

        return os;
    }
  protected:
    std::list<T> body_; ///< the body of the block
    virtual BlockBase<T, D>* clone() const override = 0;
};

/**
 * \class qasmtools::ast::ProgramBlock
 * \brief Class for program blocks
 */
using ProgramBlockStmt = std::variant<ptr<Stmt>, ptr<ControlStmt>>;
class ProgramBlock : public BlockBase<ProgramBlockStmt, ProgramBlock> {
    using BlockBase<ProgramBlockStmt, ProgramBlock>::BlockBase;
  public:
    void accept(Visitor& visitor) override { visitor.visit(*this); }
  protected:
    ProgramBlock* clone() const override {
        std::list<ProgramBlockStmt> tmp;
        for (auto& x : body_) {
            std::visit([&tmp](auto& stmt) {
                tmp.emplace_back(object::clone(*stmt));
            }, x);
        }
        return new ProgramBlock(pos_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::QuantumBlock
 * \brief Class for quantum program blocks
 */
using QuantumBlockStmt = std::variant<ptr<QuantumStmt>, ptr<QuantumLoop>>;
class QuantumBlock : public BlockBase<QuantumBlockStmt, QuantumBlock> {
    using BlockBase<QuantumBlockStmt, QuantumBlock>::BlockBase;
  public:
    void accept(Visitor& visitor) override { visitor.visit(*this); }
  protected:
    QuantumBlock* clone() const override {
        std::list<QuantumBlockStmt> tmp;
        for (auto& x : body_) {
            std::visit([&tmp](auto& stmt) {
                tmp.emplace_back(object::clone(*stmt));
            }, x);
        }
        return new QuantumBlock(pos_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::QuantumLoopBlock
 * \brief Class for quantum loop blocks
 */
using QuantumLoopStmt = std::variant<ptr<QuantumStmt>>;
class QuantumLoopBlock : public BlockBase<QuantumLoopStmt, QuantumLoopBlock> {
    using BlockBase<QuantumLoopStmt, QuantumLoopBlock>::BlockBase;
  public:
    void accept(Visitor& visitor) override { visitor.visit(*this); }
  protected:
    QuantumLoopBlock* clone() const override {
        std::list<QuantumLoopStmt> tmp;
        for (auto& x : body_) {
            std::visit([&tmp](auto& stmt) {
                tmp.emplace_back(object::clone(*stmt));
            }, x);
        }
        return new QuantumLoopBlock(pos_, std::move(tmp));
    }
};



/**
 * \class qasmtools::ast::QuantumMeasurement
 * \brief Class for quantum measurements
 */
class QuantumMeasurement final : public ASTNode {
    VarAccess q_arg_; ///< the quantum bit|register

public:
    /**
     * \brief Constructs a quantum measurement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     */
    QuantumMeasurement(parser::Position pos, VarAccess&& q_arg)
        : ASTNode(pos), q_arg_(std::move(q_arg)) {}

    /**
     * \brief Copy constructor
     */
    QuantumMeasurement(const QuantumMeasurement& qm)
        : ASTNode(qm.pos_), q_arg_(qm.q_arg_) {}

    /**
     * \brief Get the quantum argument
     *
     * \return Const reference to the quantum argument
     */
    const VarAccess& q_arg() const { return q_arg_; }

    /**
     * \brief Copy assignment overload
     */
    QuantumMeasurement& operator=(const QuantumMeasurement& q) {
        q_arg_ = q.q_arg_;
        return *this;
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "measure " << q_arg_;
        return os;
    }
  protected:
    QuantumMeasurement* clone() const override {
        return new QuantumMeasurement(pos_, VarAccess(q_arg_));
    }
};



/**
 * \class qasmtools::ast::MeasureStmt
 * \brief Class for quantum measurement statements
 * \see qasmtools::ast::StmtBase
 */
class MeasureStmt final : public QuantumStmt {
    QuantumMeasurement measurement_; ///< the quantum measurement

  public:
    /**
     * \brief Constructs a measurement statement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     */
    MeasureStmt(parser::Position pos, QuantumMeasurement&& qm)
        : QuantumStmt(pos), measurement_(std::move(qm)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<MeasureStmt> create(parser::Position pos,
                                   QuantumMeasurement&& qm) {
        return std::make_unique<MeasureStmt>(pos, std::move(qm));
    }

    /**
     * \brief Get the quantum measurement
     *
     * \return Reference to the quantum measurement
     */
    QuantumMeasurement& measurement() { return measurement_; }

    /**
     * \brief Set the quantum argument
     *
     * \param arg Const reference to a new argument
     */
    void set_measurement(const QuantumMeasurement& qm) { measurement_ = qm; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << measurement_ << ";\n";
        return os;
    }
  protected:
    MeasureStmt* clone() const override {
        return new MeasureStmt(pos_, QuantumMeasurement(measurement_));
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
    Expr& measurement() { return *exp_; }

    /**
     * \brief Set the expression
     *
     * \param exp The new expression
     */
    void set_subexp(ptr<Expr> exp) { exp_ = std::move(exp); }

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
    QuantumMeasurement measurement_; ///< the quantum measurement
    VarAccess c_arg_;                ///< the classical bit|register

  public:
    /**
     * \brief Constructs a measurement statement
     *
     * \param pos The source position
     * \param q_arg Rvalue reference to the quantum argument
     * \param c_arg Rvalue reference to the classical argument
     */
    MeasureAsgnStmt(parser::Position pos, QuantumMeasurement&& qm,
                    VarAccess&& c_arg)
        : Stmt(pos), measurement_(std::move(qm)), c_arg_(std::move(c_arg))
    {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<MeasureAsgnStmt> create(parser::Position pos,
                                       QuantumMeasurement&& qm,
                                       VarAccess&& c_arg) {
        return std::make_unique<MeasureAsgnStmt>(pos, std::move(qm),
                                                 std::move(c_arg));
    }

    /**
     * \brief Get the quantum measurement
     *
     * \return Reference to the quantum measurement
     */
    QuantumMeasurement& measurement() { return measurement_; }

    /**
     * \brief Get the classical argument
     *
     * \return Reference to the classical argument
     */
    VarAccess& c_arg() { return c_arg_; }

    /**
     * \brief Set the quantum measurement
     *
     * \param arg Const reference to a new measurement
     */
    void set_qarg(const QuantumMeasurement& qm) { measurement_ = qm; }

    /**
     * \brief Set the classical argument
     *
     * \param arg Const reference to a new argument
     */
    void set_carg(const VarAccess& arg) { c_arg_ = arg; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << c_arg_ << " = " << measurement_ << ";\n";
        return os;
    }
  protected:
    MeasureAsgnStmt* clone() const override {
        return new MeasureAsgnStmt(pos_, QuantumMeasurement(measurement_),
                                   VarAccess(c_arg_));
    }
};

/**
 * \class qasmtools::ast::ResetStmt
 * \brief Class for reset statements
 * \see qasmtools::ast::StmtBase
 */
class ResetStmt final : public QuantumStmt {
    std::vector<VarAccess> args_; ///< list of quantum bits|registers

  public:
    /**
     * \brief Constructs a reset statement
     *
     * \param pos The source position
     * \param arg Rvalue reference to the list of arguments
     */
    ResetStmt(parser::Position pos, std::vector<VarAccess>&& args)
        : QuantumStmt(pos), args_(std::move(args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ResetStmt> create(parser::Position pos,
                                 std::vector<VarAccess>&& args) {
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
    std::vector<VarAccess>& args() { return args_; }

    /**
     * \brief Get the ith argument
     *
     * \param i The index
     * \return Reference to the argument
     */
    VarAccess& arg(int i) { return args_[i]; }

    /**
     * \brief Apply a function to each argument
     *
     * \param f Void function accepting a reference to the argument
     */
    void foreach_arg(std::function<void(VarAccess&)> f) {
        for (auto& x: args_)
            f(x);
    }

    /**
     * \brief Set the ith argument
     *
     * \param arg Const reference to a new argument
     */
    void set_arg(int i, const VarAccess& arg) { args_[i] = arg; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "reset";
        for (auto it = args_.begin(); it != args_.end(); it++)
            os << (it == args_.begin() ? " " : ", ") << *it;
        os << ";\n";
        return os;
    }
  protected:
    ResetStmt* clone() const override {
        return new ResetStmt(pos_, std::vector<VarAccess>(args_));
    }
};

/**
 * \class qasmtools::ast::BarrierStmt
 * \brief Class for barrier statement
 * \see qasmtools::ast::StmtBase
 */
class BarrierStmt final : public QuantumStmt {
    std::vector<VarAccess> args_; ///< list of quantum bits|registers

  public:
    /**
     * \brief Constructs a barrier gate
     *
     * \param pos The source position
     * \param args Rvalue reference to a list of arguments
     */
    BarrierStmt(parser::Position pos, std::vector<VarAccess>&& args)
        : QuantumStmt(pos), args_(std::move(args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BarrierStmt> create(parser::Position pos,
                                   std::vector<VarAccess>&& args) {
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
    std::vector<VarAccess>& args() { return args_; }

    /**
     * \brief Get the ith argument
     *
     * \param i The number of the argument (0 indexed)
     * \return Reference to the ith argument
     */
    VarAccess& arg(int i) { return args_[i]; }

    /**
     * \brief Apply a function to each argument
     *
     * \param f Void function accepting a reference to the argument
     */
    void foreach_arg(std::function<void(VarAccess&)> f) {
        for (auto& x: args_)
            f(x);
    }

    /**
     * \brief Set the ith argument
     *
     * \param i The number of the argument (0 indexed)
     * \param arg The new argument
     */
    void set_arg(int i, const VarAccess& arg) { args_[i] = arg; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "barrier";
        for (auto it = args_.begin(); it != args_.end(); it++)
            os << (it == args_.begin() ? " " : ",") << *it;
        os << ";\n";
        return os;
    }
  protected:
    BarrierStmt* clone() const override {
        return new BarrierStmt(pos_, std::vector<VarAccess>(args_));
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
    using RetType = std::variant<std::monostate, QuantumMeasurement, ptr<Expr>>;
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

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        std::visit(
            utils::overloaded{
                [&os](QuantumMeasurement& qm) {
                    os << "return " << qm << ";\n";
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
                [&value_copy](QuantumMeasurement& qm) {
                    value_copy = qm;
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
 * \class qasmtools::ast::UGate
 * \brief Class for U gates
 * \see qasmtools::ast::Gate
 */
class UGate final : public QuantumStmt {
    ptr<Expr> theta_;  ///< theta angle
    ptr<Expr> phi_;    ///< phi angle
    ptr<Expr> lambda_; ///< lambda angle

    VarAccess arg_; ///< quantum bit|register

  public:
    /**
     * \brief Constructs a U gate
     *
     * \param pos The source position
     * \param theta The theta angle
     * \param phi The phi angle
     * \param lambda The lambda angle
     * \param arg Rvalue reference to the quantum argument
     */
    UGate(parser::Position pos, ptr<Expr> theta, ptr<Expr> phi,
          ptr<Expr> lambda, VarAccess&& arg)
        : QuantumStmt(pos), theta_(std::move(theta)), phi_(std::move(phi)),
          lambda_(std::move(lambda)), arg_(std::move(arg)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<UGate> create(parser::Position pos, ptr<Expr> theta,
                             ptr<Expr> phi, ptr<Expr> lambda, VarAccess&& arg) {
        return std::make_unique<UGate>(pos, std::move(theta), std::move(phi),
                                       std::move(lambda), std::move(arg));
    }

    /**
     * \brief Get the theta angle
     *
     * \return Reference to the angle expression
     */
    Expr& theta() { return *theta_; }

    /**
     * \brief Get the phi angle
     *
     * \return Reference to the angle expression
     */
    Expr& phi() { return *phi_; }

    /**
     * \brief Get the lambda angle
     *
     * \return Reference to the angle expression
     */
    Expr& lambda() { return *lambda_; }

    /**
     * \brief Get the argument
     *
     * \return Reference to the quantum argument
     */
    VarAccess& arg() { return arg_; }

    /**
     * \brief Set the theta angle
     *
     * \param theta The new angle expression
     */
    void set_theta(ptr<Expr> theta) { theta_ = std::move(theta); }

    /**
     * \brief Set the phi angle
     *
     * \param theta The new angle expression
     */
    void set_phi(ptr<Expr> phi) { phi_ = std::move(phi); }

    /**
     * \brief Set the lambda angle
     *
     * \param theta The new angle expression
     */
    void set_lambda(ptr<Expr> lambda) { lambda_ = std::move(lambda); }

    /**
     * \brief Set the argument
     *
     * \param arg The new argument
     */
    void set_arg(const VarAccess& arg) { arg_ = arg; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "U(" << *theta_ << "," << *phi_ << "," << *lambda_ << ") " << arg_
           << ";\n";
        return os;
    }
  protected:
    UGate* clone() const override {
        return new UGate(pos_, object::clone(*theta_), object::clone(*phi_),
                         object::clone(*lambda_), VarAccess(arg_));
    }
};

/**
 * \class qasmtools::ast::DeclaredGate
 * \brief Class for declared gate applications
 * \see qasmtools::ast::Gate
 */
class DeclaredGate final : public QuantumStmt {
    symbol name_;                   ///< gate identifier
    std::vector<ptr<Expr>> c_args_; ///< list of classical arguments
    std::vector<VarAccess> q_args_; ///< list of quantum arguments

  public:
    /**
     * \brief Constructs an application of a declared gate
     *
     * \param pos The source position
     * \param name The gate name
     * \param c_args Rvalue reference to a list of classical arguments
     * \param q_args Rvalue reference to a list of quantum arguments
     */
    DeclaredGate(parser::Position pos, symbol name,
                 std::vector<ptr<Expr>>&& c_args,
                 std::vector<VarAccess>&& q_args)
        : QuantumStmt(pos), name_(name), c_args_(std::move(c_args)),
          q_args_(std::move(q_args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DeclaredGate> create(parser::Position pos, symbol name,
                                    std::vector<ptr<Expr>>&& c_args,
                                    std::vector<VarAccess>&& q_args) {
        return std::make_unique<DeclaredGate>(pos, name, std::move(c_args),
                                              std::move(q_args));
    }

    /**
     * \brief Get the gate name
     *
     * \return Const reference to the gate name
     */
    const symbol& name() const { return name_; }

    /**
     * \brief Get the number of classical arguments
     *
     * \return The number of arguments
     */
    int num_cargs() const { return static_cast<int>(c_args_.size()); }

    /**
     * \brief Get the number of quantum arguments
     *
     * \return The number of arguments
     */
    int num_qargs() const { return static_cast<int>(q_args_.size()); }

    /**
     * \brief Get the ith classical argument
     *
     * \param i The number of the argument, 0-indexed
     * \return Reference to an expression
     */
    Expr& carg(int i) { return *(c_args_[i]); }

    /**
     * \brief Get the ith quantum argument
     *
     * \param i The number of the argument, 0-indexed
     * \return Reference to the argument
     */
    VarAccess& qarg(int i) { return q_args_[i]; }

    /**
     * \brief Get the list of quantum arguments
     *
     * \return Reference to the list of arguments
     */
    std::vector<VarAccess>& qargs() { return q_args_; }

    /**
     * \brief Apply a function to each classical argument
     *
     * \param f Void function accepting an expression reference
     */
    void foreach_carg(std::function<void(Expr&)> f) {
        for (auto& x: c_args_)
            f(*x);
    }

    /**
     * \brief Apply a function to each quantum argument
     *
     * \param f Void function accepting a reference to an argument
     */
    void foreach_qarg(std::function<void(VarAccess&)> f) {
        for (auto& x: q_args_)
            f(x);
    }

    /**
     * \brief Set the ith classical argument
     *
     * \param i The number of the argument, 0-indexed
     * \param expr An expression giving the new argument
     */
    void set_carg(int i, ptr<Expr> expr) { c_args_[i] = std::move(expr); }

    /**
     * \brief Set the ith quantum argument
     *
     * \param i The number of the argument, 0-indexed
     * \param arg The new argument
     */
    void set_qarg(int i, const VarAccess& arg) { q_args_[i] = arg; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << name_;
        if (c_args_.size() > 0) {
            os << "(";
            for (auto it = c_args_.begin(); it != c_args_.end(); it++)
                os << (it == c_args_.begin() ? "" : ",") << **it;
            os << ")";
        }
        os << " ";
        for (auto it = q_args_.begin(); it != q_args_.end(); it++)
            os << (it == q_args_.begin() ? "" : ",") << *it;
        os << ";\n";
        return os;
    }
  protected:
    DeclaredGate* clone() const override {
        std::vector<ptr<Expr>> c_tmp;
        for (auto& x: c_args_)
            c_tmp.emplace_back(object::clone(*x));

        return new DeclaredGate(pos_, name_, std::move(c_tmp),
                                std::vector<VarAccess>(q_args_));
    }
};

} // namespace ast
} // namespace qasmtools
