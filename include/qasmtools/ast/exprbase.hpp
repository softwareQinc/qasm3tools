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
 * \file qasmtools/ast/exprbase.hpp
 * \brief Base class for openQASM expressions
 */

#pragma once

#include "base.hpp"

#include <complex>
#include <optional>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::Expr
 * \brief Base class for openQASM expressions
 */
class Expr : public ASTNode {
  public:
    Expr(parser::Position pos) : ASTNode(pos) {}
    virtual ~Expr() = default;

    /**
     * \brief Evaluate constant expressions
     *
     * All sub-classes must override this
     *
     * \return Returns the value of the expression if it
     *         is constant, or nullopt otherwise
     */
    virtual std::optional<std::complex<double>> constant_eval() const = 0;

    /**
     * \brief Internal pretty-printer with associative context
     *
     * \param ctx Whether the current associative context is ambiguous
     */
    virtual std::ostream& pretty_print(std::ostream& os, bool ctx) const = 0;
    std::ostream& pretty_print(std::ostream& os) const override {
        return pretty_print(os, false);
    }
  protected:
    virtual Expr* clone() const override = 0;
};


} // namespace ast
} // namespace qasmtools
