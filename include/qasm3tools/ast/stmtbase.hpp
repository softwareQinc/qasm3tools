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
 * \file qasm3tools/ast/stmtbase.hpp
 * \brief Base classes for OpenQASM statements
 */

#pragma once

#include "base.hpp"

namespace qasm3tools {
namespace ast {

/**
 * \class qasm3tools::ast::Stmt
 * \brief Base class for OpenQASM statements
 */
class Stmt : public ASTNode {
  public:
    Stmt(parser::Position pos) : ASTNode(pos) {}
    virtual ~Stmt() = default;

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

    enum class Type { Regular, Global, Quantum };
    /**
     * \brief Extraction operator overload for Stmt::Type enum class
     *
     * \param os Output stream passed by reference
     * \param type Stmt::Type enum class
     * \return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Type& type) {
        switch (type) {
            case Type::Regular:
                os << "Statement";
                break;
            case Type::Global:
                os << "GlobalStatement";
                break;
            case Type::Quantum:
                os << "QuantumStatement";
                break;
        }
        return os;
    }

    virtual Type stmt_type() { return Type::Regular; }

  protected:
    virtual Stmt* clone() const override = 0;
};
/**
 * \class qasm3tools::ast::GlobalStmt
 * \brief Statement sub-class for global statements
 */
class GlobalStmt : public Stmt {
  public:
    GlobalStmt(parser::Position pos) : Stmt(pos) {}
    virtual ~GlobalStmt() = default;

    virtual Type stmt_type() override { return Type::Global; }

  protected:
    virtual GlobalStmt* clone() const = 0;
};
/**
 * \class qasm3tools::ast::QuantumStmt
 * \brief Statement sub-class for quantum statements
 */
class QuantumStmt : public Stmt {
  public:
    QuantumStmt(parser::Position pos) : Stmt(pos) {}
    virtual ~QuantumStmt() = default;

    virtual Type stmt_type() override { return Type::Quantum; }

  protected:
    virtual QuantumStmt* clone() const = 0;
};

} // namespace ast
} // namespace qasm3tools
