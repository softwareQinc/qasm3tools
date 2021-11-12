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
 * \file qasmtools/ast/stmtbase.hpp
 * \brief Base classes for OpenQASM statements
 */

#pragma once

#include "base.hpp"

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::StmtBase
 * \brief Base class for OpenQASM statements
 */
class StmtBase : public ASTNode {
  public:
    StmtBase(parser::Position pos) : ASTNode(pos) {}
    virtual ~StmtBase() = default;

    /**
     * \brief Internal pretty-printer which can suppress the output of the
     * stdlib, and/or add indentation to block statements
     *
     * \param suppress_std Whether to suppress output of the standard library
     * \param indents Current indentation level
     */
    virtual std::ostream& pretty_print(std::ostream& os, bool suppress_std,
                                       size_t indents) const = 0;

    std::ostream& pretty_print(std::ostream& os, bool suppress_std) const {
        return pretty_print(os, suppress_std, 0);
    }

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

} // namespace ast
} // namespace qasmtools
