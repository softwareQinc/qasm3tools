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
 * \file qasmtools/ast/timing.hpp
 * \brief Classes for timing expressions and statements
 */

#pragma once

#include "exprbase.hpp"
#include "indexid.hpp"
#include "stmtbase.hpp"
#include "stmtblock.hpp"

#include <iomanip>
#include <optional>

namespace qasmtools {
namespace ast {

/**
 * \brief Enum of time units
 */
enum class TimeUnit { dt, ns, us, mus, ms, s };
inline std::ostream& operator<<(std::ostream& os, const TimeUnit& tu) {
    switch (tu) {
        case TimeUnit::dt:
            os << "dt";
            break;
        case TimeUnit::ns:
            os << "ns";
            break;
        case TimeUnit::us:
            os << "us";
            break;
        case TimeUnit::mus:
            os << "\u03BCs";
            break;
        case TimeUnit::ms:
            os << "ms";
            break;
        case TimeUnit::s:
            os << "s";
            break;
    }
    return os;
}

/**
 * \class qasmtools::ast::TimeExpr
 * \brief Class for time expressions
 * \see qasmtools::ast::Expr
 */
class TimeExpr final : public Expr {
    double value_;    ///< the floating point value
    TimeUnit units_; ///< the units

  public:
    /**
     * \brief Construct a time expression
     *
     * \param pos The source position
     * \param val The floating point value
     * \param units The units
     */
    TimeExpr(parser::Position pos, double value, TimeUnit units)
        : Expr(pos), value_(value), units_(units) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<TimeExpr> create(parser::Position pos, double value,
                                TimeUnit units) {
        return std::make_unique<TimeExpr>(pos, value, units);
    }

    /**
     * \brief Get the real value
     *
     * \return The floating point value
     */
    double value() const { return value_; }

    /**
     * \brief Get the units
     *
     * \return The units
     */
    TimeUnit units() const { return units_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        std::streamsize ss = os.precision();
        os << std::setprecision(15) << value_ << std::setprecision(ss)
           << units_;
        return os;
    }
  protected:
    TimeExpr* clone() const override {
        return new TimeExpr(pos_, value_, units_);
    }
};

/**
 * \class qasmtools::ast::DurationGateExpr
 * \brief Class for durationof(gate) expressions
 * \see qasmtools::ast::Expr
 */
class DurationGateExpr final : public Expr {
    symbol gate_; // the gate indentifier

  public:
    /**
     * \brief Construct a duration expression
     *
     * \param pos The source position
     * \param gate The gate name
     */
    DurationGateExpr(parser::Position pos, symbol gate)
        : Expr(pos), gate_(gate) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DurationGateExpr> create(parser::Position pos, symbol gate) {
        return std::make_unique<DurationGateExpr>(pos, gate);
    }

    /**
     * \brief Get the gate name
     *
     * \return Constant reference to the name
     */
    const symbol& gate() const { return gate_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;
        os << "durationof(" << gate_ << ")";
        return os;
    }
  protected:
    DurationGateExpr* clone() const override {
        return new DurationGateExpr(pos_, gate_);
    }
};

/**
 * \class qasmtools::ast::DurationBlockExpr
 * \brief Class for durationof({...}) expressions
 * \see qasmtools::ast::Expr
 */
class DurationBlockExpr final : public Expr {
    ptr<QuantumBlock> block_; // the quantum block

  public:
    /**
     * \brief Construct a duration expression
     *
     * \param pos The source position
     * \param block The quantum block
     */
    DurationBlockExpr(parser::Position pos, ptr<QuantumBlock> block)
        : Expr(pos), block_(std::move(block)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DurationBlockExpr> create(parser::Position pos,
                                         ptr<QuantumBlock> block) {
        return std::make_unique<DurationBlockExpr>(pos, std::move(block));
    }

    /**
     * \brief Get the quantum block
     *
     * \return Reference to the quantum block
     */
    QuantumBlock& block() { return *block_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;
        os << "durationof(" << *block_ << ")";
        return os;
    }
  protected:
    DurationBlockExpr* clone() const override {
        return new DurationBlockExpr(pos_, object::clone(*block_));
    }
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
 * \class qasmtools::ast::DelayStmt
 * \brief Class for delay statements
 * \see qasmtools::ast::Stmt
 */
class DelayStmt final : public TimingStmt {
    std::vector<ptr<Expr>> c_args_;    ///< list of classical arguments
    ptr<Expr> duration_;               ///< delay duration
    std::vector<ptr<IndexId>> q_args_; ///< list of quantum arguments

  public:
    /**
     * \brief Constructs a delay statement
     *
     * \param pos The source position
     * \param c_args Rvalue reference to a list of classical arguments
     * \param duration The duration
     * \param q_args Rvalue reference to a list of quantum arguments
     */
    DelayStmt(parser::Position pos, std::vector<ptr<Expr>>&& c_args,
              ptr<Expr> duration, std::vector<ptr<IndexId>>&& q_args)
            : TimingStmt(pos), c_args_(std::move(c_args)),
              duration_(std::move(duration)), q_args_(std::move(q_args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DelayStmt> create(parser::Position pos,
                                 std::vector<ptr<Expr>>&& c_args,
                                 ptr<Expr> duration,
                                 std::vector<ptr<IndexId>>&& q_args) {
        return std::make_unique<DelayStmt>(pos, std::move(c_args),
                                           std::move(duration),
                                           std::move(q_args));
    }

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
    IndexId& qarg(int i) { return *q_args_[i]; }

    /**
     * \brief Get the list of quantum arguments
     *
     * \return Reference to the list of arguments
     */
    std::vector<ptr<IndexId>>& qargs() { return q_args_; }

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
    void foreach_qarg(std::function<void(IndexId&)> f) {
        for (auto& x: q_args_)
            f(*x);
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
    void set_qarg(int i, ptr<IndexId> arg) { q_args_[i] = std::move(arg); }

    /**
     * \brief Get the duration
     *
     * \return Reference to thr duration
     */
    Expr& duration() { return *duration_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "delay";
        if (c_args_.size() > 0) {
            os << "(";
            for (auto it = c_args_.begin(); it != c_args_.end(); it++)
                os << (it == c_args_.begin() ? "" : ",") << **it;
            os << ")";
        }
        os << "[" << *duration_ << "] ";
        for (auto it = q_args_.begin(); it != q_args_.end(); it++)
            os << (it == q_args_.begin() ? "" : ",") << **it;
        os << ";\n";
        return os;
    }
  protected:
    DelayStmt* clone() const override {
        std::vector<ptr<Expr>> c_tmp;
        for (auto& x: c_args_)
            c_tmp.emplace_back(object::clone(*x));
        std::vector<ptr<IndexId>> q_tmp;
        for (auto& x: q_args_)
            q_tmp.emplace_back(object::clone(*x));

        return new DelayStmt(pos_, std::move(c_tmp), object::clone(*duration_),
                             std::move(q_tmp));
    }
};

/**
 * \class qasmtools::ast::RotaryStmt
 * \brief Class for rotary statements
 * \see qasmtools::ast::Stmt
 */
class RotaryStmt final : public TimingStmt {
    std::vector<ptr<Expr>> c_args_;    ///< list of classical arguments
    ptr<Expr> duration_;               ///< rotary duration
    std::vector<ptr<IndexId>> q_args_; ///< list of quantum arguments

  public:
    /**
     * \brief Constructs a rotary statement
     *
     * \param pos The source position
     * \param c_args Rvalue reference to a list of classical arguments
     * \param duration The duration
     * \param q_args Rvalue reference to a list of quantum arguments
     */
    RotaryStmt(parser::Position pos, std::vector<ptr<Expr>>&& c_args,
               ptr<Expr> duration, std::vector<ptr<IndexId>>&& q_args)
            : TimingStmt(pos), c_args_(std::move(c_args)),
              duration_(std::move(duration)), q_args_(std::move(q_args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<RotaryStmt> create(parser::Position pos,
                                  std::vector<ptr<Expr>>&& c_args,
                                  ptr<Expr> duration,
                                  std::vector<ptr<IndexId>>&& q_args) {
        return std::make_unique<RotaryStmt>(pos, std::move(c_args),
                                            std::move(duration),
                                            std::move(q_args));
    }

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
    IndexId& qarg(int i) { return *q_args_[i]; }

    /**
     * \brief Get the list of quantum arguments
     *
     * \return Reference to the list of arguments
     */
    std::vector<ptr<IndexId>>& qargs() { return q_args_; }

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
    void foreach_qarg(std::function<void(IndexId&)> f) {
        for (auto& x: q_args_)
            f(*x);
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
    void set_qarg(int i, ptr<IndexId> arg) { q_args_[i] = std::move(arg); }

    /**
     * \brief Get the duration
     *
     * \return Reference to thr duration
     */
    Expr& duration() { return *duration_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "rotary";
        if (c_args_.size() > 0) {
            os << "(";
            for (auto it = c_args_.begin(); it != c_args_.end(); it++)
                os << (it == c_args_.begin() ? "" : ",") << **it;
            os << ")";
        }
        os << "[" << *duration_ << "] ";
        for (auto it = q_args_.begin(); it != q_args_.end(); it++)
            os << (it == q_args_.begin() ? "" : ",") << **it;
        os << ";\n";
        return os;
    }
  protected:
    RotaryStmt* clone() const override {
        std::vector<ptr<Expr>> c_tmp;
        for (auto& x: c_args_)
            c_tmp.emplace_back(object::clone(*x));
        std::vector<ptr<IndexId>> q_tmp;
        for (auto& x: q_args_)
            q_tmp.emplace_back(object::clone(*x));

        return new RotaryStmt(pos_, std::move(c_tmp), object::clone(*duration_),
                              std::move(q_tmp));
    }
};

/**
 * \class qasmtools::ast::BoxStmt
 * \brief Class for box statements
 * \see qasmtools::ast::StmtBase
 */
class BoxStmt final : public TimingStmt {
    std::optional<ptr<Expr>> duration_; ///< box duration
    ptr<QuantumBlock> circuit_;         ///< boxed subcircuit

  public:
    /**
     * \brief Constructs a box statement
     *
     * \param pos The source position
     * \param duration Optional box duration (default = std::nullopt)
     * \param circuit The boxed subcircuit
     */
    BoxStmt(parser::Position pos, ptr<QuantumBlock> circuit)
        : TimingStmt(pos), duration_(std::nullopt),
          circuit_(std::move(circuit)) {}
    BoxStmt(parser::Position pos, std::optional<ptr<Expr>>&& duration,
            ptr<QuantumBlock> circuit)
        : TimingStmt(pos), duration_(std::move(duration)),
          circuit_(std::move(circuit)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BoxStmt> create(parser::Position pos,
                               ptr<QuantumBlock> circuit) {
        return std::make_unique<BoxStmt>(pos, std::move(circuit));
    }
    static ptr<BoxStmt> create(parser::Position pos,
                               std::optional<ptr<Expr>>&& duration,
                               ptr<QuantumBlock> circuit) {
        return std::make_unique<BoxStmt>(pos, std::move(duration),
                                         std::move(circuit));
    }

    /**
     * \brief Get the box duration
     *
     * \return A reference to the duration
     */
    std::optional<ptr<Expr>>& duration() { return duration_; }

    /**
     * \brief Get the boxed subcircuit
     *
     * \return Reference to the subcircuit
     */
    QuantumBlock& circuit() { return *circuit_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os <<  "box ";
        if (duration_)
            os << "[" << **duration_ << "] ";
        os << *circuit_;
        return os;
    }
  protected:
    BoxStmt* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (duration_)
            tmp = object::clone(**duration_);
        return new BoxStmt(pos_, std::move(tmp), object::clone(*circuit_));
    }
};

} // namespace ast
} // namespace qasmtools
