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
 * \file qasmtools/ast/stmtblock.hpp
 * \brief openQASM block statements
 */

#pragma once

#include "base.hpp"
#include "stmtbase.hpp"
#include "../utils/templates.hpp"

#include <functional>
#include <list>
#include <variant>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::BlockBase
 * \brief Base class for statement blocks
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
     * \brief Apply a function to each stetement
     *
     * \param f Void function accepting a reference to the statement
     */
    void foreach_stmt(std::function<void(T&)> f) {
        for (auto& x: body_)
            f(x);
    }

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

    /**
     * \brief Internal pretty-printer which adds indentation to each line
     *
     * \param indents Number of indents
     */
    virtual std::ostream& pretty_print(std::ostream& os,
                                       size_t indents) const {
        os << "{\n";
        for (auto& x : body_) {
            for (size_t i = 0; i <= indents; i++)
                os << "\t";
            std::visit([&os, &indents](auto& stmt) {
                stmt->pretty_print(os, false, indents + 1);
            }, x);
        }
        for (size_t i = 0; i < indents; i++)
            os << "\t";
        os << "}\n";

        return os;
    }

    std::ostream& pretty_print(std::ostream& os) const override {
        return pretty_print(os, 0);
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
using QuantumBlockStmt = std::variant<ptr<QuantumStmt>>;
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

} // namespace ast
} // namespace qasmtools
