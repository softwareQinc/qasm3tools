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

#include "expr.hpp"
#include "stmt.hpp"

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
 * \class qasmtools::ast::DurationExpr
 * \brief Class for durationof() expressions
 * \see qasmtools::ast::Expr
 */
class DurationExpr final : public Expr {
    ptr<QuantumBlock> block_; // the quantum block

  public:
    /**
     * \brief Construct a duration expression
     *
     * \param pos The source position
     * \param block The quantum block
     */
    DurationExpr(parser::Position pos, ptr<QuantumBlock> block)
        : Expr(pos), block_(std::move(block)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DurationExpr> create(parser::Position pos,
                                    ptr<QuantumBlock> block) {
        return std::make_unique<DurationExpr>(pos, std::move(block));
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
    DurationExpr* clone() const override {
        return new DurationExpr(pos_, object::clone(*block_));
    }
};



} // namespace ast
} // namespace qasmtools
