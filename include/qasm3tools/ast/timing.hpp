/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2025 softwareQ Inc. All rights reserved.
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
 * \file qasm3tools/ast/timing.hpp
 * \brief Classes for timing expressions and statements
 */

#ifndef QASM3TOOLS_AST_TIMING_HPP_
#define QASM3TOOLS_AST_TIMING_HPP_

#include <iomanip>
#include <optional>

#include "exprbase.hpp"
#include "indexid.hpp"
#include "stmtbase.hpp"
#include "stmtblock.hpp"

namespace qasm3tools {
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
            os << "µs";
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
 * \class qasm3tools::ast::TimeExpr
 * \brief Class for time expressions
 * \see qasm3tools::ast::Expr
 */
class TimeExpr final : public Expr {
    double value_;   ///< the floating point value
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

    std::optional<double> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void)ctx;

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
 * \class qasm3tools::ast::DurationofExpr
 * \brief Class for durationof({...}) expressions
 * \see qasm3tools::ast::Expr
 */
class DurationofExpr final : public Expr {
    ptr<ProgramBlock> block_; // the quantum block

  public:
    /**
     * \brief Construct a duration expression
     *
     * \param pos The source position
     * \param block The quantum block
     */
    DurationofExpr(parser::Position pos, ptr<ProgramBlock> block)
        : Expr(pos), block_(std::move(block)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DurationofExpr> create(parser::Position pos,
                                      ptr<ProgramBlock> block) {
        return std::make_unique<DurationofExpr>(pos, std::move(block));
    }

    /**
     * \brief Get the quantum block
     *
     * \return Reference to the quantum block
     */
    ProgramBlock& block() { return *block_; }

    std::optional<double> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void)ctx;
        os << "durationof(" << *block_ << ")";
        return os;
    }

  protected:
    DurationofExpr* clone() const override {
        return new DurationofExpr(pos_, object::clone(*block_));
    }
};

/**
 * \class qasm3tools::ast::TimingStmt
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
 * \class qasm3tools::ast::DelayStmt
 * \brief Class for delay statements
 * \see qasm3tools::ast::Stmt
 */
class DelayStmt final : public TimingStmt {
    ptr<Expr> duration_;               ///< delay duration
    std::vector<ptr<IndexId>> q_args_; ///< list of quantum arguments

  public:
    /**
     * \brief Constructs a delay statement
     *
     * \param pos The source position
     * \param duration The duration
     * \param q_args Rvalue reference to a list of quantum arguments
     */
    DelayStmt(parser::Position pos, ptr<Expr> duration,
              std::vector<ptr<IndexId>>&& q_args)
        : TimingStmt(pos), duration_(std::move(duration)),
          q_args_(std::move(q_args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DelayStmt> create(parser::Position pos, ptr<Expr> duration,
                                 std::vector<ptr<IndexId>>&& q_args) {
        return std::make_unique<DelayStmt>(pos, std::move(duration),
                                           std::move(q_args));
    }

    /**
     * \brief Get the number of quantum arguments
     *
     * \return The number of arguments
     */
    int num_qargs() const { return static_cast<int>(q_args_.size()); }

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
     * \brief Apply a function to each quantum argument
     *
     * \param f Void function accepting a reference to an argument
     */
    void foreach_qarg(std::function<void(IndexId&)> f) {
        for (auto& x : q_args_) {
            f(*x);
        }
    }

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

    /**
     * \brief Set the duration
     *
     * \param d The new duration
     */
    void set_duration(ptr<Expr> d) { duration_ = std::move(d); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "delay[" << *duration_ << "]";
        for (auto it = q_args_.begin(); it != q_args_.end(); it++) {
            os << (it == q_args_.begin() ? " " : ",") << **it;
        }
        os << ";\n";
        return os;
    }

  protected:
    DelayStmt* clone() const override {
        std::vector<ptr<IndexId>> q_tmp;
        for (auto& x : q_args_) {
            q_tmp.emplace_back(object::clone(*x));
        }

        return new DelayStmt(pos_, object::clone(*duration_), std::move(q_tmp));
    }
};

/**
 * \class qasm3tools::ast::BoxStmt
 * \brief Class for box statements
 * \see qasm3tools::ast::StmtBase
 */
class BoxStmt final : public TimingStmt {
    std::optional<ptr<Expr>> duration_; ///< box duration
    ptr<ProgramBlock> circuit_;         ///< boxed subcircuit

  public:
    /**
     * \brief Constructs a box statement
     *
     * \param pos The source position
     * \param duration Optional box duration (default = std::nullopt)
     * \param circuit The boxed subcircuit
     */
    BoxStmt(parser::Position pos, ptr<ProgramBlock> circuit)
        : TimingStmt(pos), duration_(std::nullopt),
          circuit_(std::move(circuit)) {}
    BoxStmt(parser::Position pos, std::optional<ptr<Expr>>&& duration,
            ptr<ProgramBlock> circuit)
        : TimingStmt(pos), duration_(std::move(duration)),
          circuit_(std::move(circuit)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BoxStmt> create(parser::Position pos,
                               ptr<ProgramBlock> circuit) {
        return std::make_unique<BoxStmt>(pos, std::move(circuit));
    }
    static ptr<BoxStmt> create(parser::Position pos,
                               std::optional<ptr<Expr>>&& duration,
                               ptr<ProgramBlock> circuit) {
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
    ProgramBlock& circuit() { return *circuit_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "box ";
        if (duration_) {
            os << "[" << **duration_ << "] ";
        }
        circuit_->pretty_print(os, indents);
        return os;
    }

  protected:
    BoxStmt* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (duration_) {
            tmp = object::clone(**duration_);
        }
        return new BoxStmt(pos_, std::move(tmp), object::clone(*circuit_));
    }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_TIMING_HPP_ */
