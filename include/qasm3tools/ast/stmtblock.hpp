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
 * @file qasm3tools/ast/stmtblock.hpp
 * @brief OpenQASM block statements
 */

#ifndef QASM3TOOLS_AST_STMTBLOCK_HPP_
#define QASM3TOOLS_AST_STMTBLOCK_HPP_

#include <functional>
#include <list>

#include "../utils/templates.hpp"
#include "base.hpp"
#include "stmtbase.hpp"

namespace qasm3tools {
namespace ast {

/**
 * @class qasm3tools::ast::BlockBase
 * @brief Base class for statement blocks
 * D is derived class
 */
template <typename D>
class BlockBase : public ASTNode {
  public:
    /**
     * @brief Constructs a program block
     *
     * @param pos The source position
     * @param body The block body
     */
    BlockBase(parser::Position pos, std::list<ptr<Stmt>>&& body)
        : ASTNode(pos), body_(std::move(body)) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<D> create(parser::Position pos, std::list<ptr<Stmt>>&& body) {
        return std::make_unique<D>(pos, std::move(body));
    }

    /**
     * @brief Get the block body
     *
     * @return Reference to the body as a list of statements
     */
    typename std::list<ptr<Stmt>>& body() { return body_; }

    /**
     * @brief Apply a function to each stetement
     *
     * @param f Void function accepting a reference to the statement
     */
    void foreach_stmt(std::function<void(Stmt&)> f) {
        for (auto& x : body_) {
            f(*x);
        }
    }

    /**
     * @brief Get an iterator to the beginning of the body
     *
     * @return std::list iterator
     */
    typename std::list<ptr<Stmt>>::iterator begin() { return body_.begin(); }

    /**
     * @brief Get an iterator to the end of the body
     *
     * @return std::list iterator
     */
    typename std::list<ptr<Stmt>>::iterator end() { return body_.end(); }

    /**
     * @brief Internal pretty-printer which adds indentation to each line
     *
     * @param indents Current indentation level
     */
    virtual std::ostream& pretty_print(std::ostream& os, size_t indents) const {
        os << "{\n";
        for (auto& x : body_) {
            for (auto& ann : x->annotations()) {
                for (size_t i = 0; i <= indents; i++) {
                    os << "\t";
                }
                os << *ann;
            }
            for (size_t i = 0; i <= indents; i++) {
                os << "\t";
            }
            x->pretty_print(os, false, indents + 1);
        }
        for (size_t i = 0; i < indents; i++) {
            os << "\t";
        }
        os << "}\n";

        return os;
    }

    std::ostream& pretty_print(std::ostream& os) const override {
        return pretty_print(os, 0);
    }

  protected:
    std::list<ptr<Stmt>> body_; ///< the body of the block
    BlockBase* clone() const override {
        std::list<ptr<Stmt>> tmp;
        for (auto& x : body_) {
            tmp.emplace_back(object::clone(*x));
        }
        return new D(pos_, std::move(tmp));
    }
};

/**
 * @class qasm3tools::ast::ProgramBlock
 * @brief Class for program blocks
 */
class ProgramBlock final : public BlockBase<ProgramBlock> {
    using BlockBase<ProgramBlock>::BlockBase;

  public:
    void accept(Visitor& visitor) override { visitor.visit(*this); }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_STMTBLOCK_HPP_ */
