/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2023 softwareQ Inc. All rights reserved.
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
 * \file qasm3tools/ast/base.hpp
 * \brief OpenQASM syntax trees
 */

#ifndef QASM3TOOLS_AST_BASE_HPP_
#define QASM3TOOLS_AST_BASE_HPP_

#include "../parser/position.hpp"
#include "cloneable.hpp"
#include "visitor.hpp"

#include <iostream>
#include <memory>
#include <string>

namespace qasm3tools {
namespace ast {

template <typename T>
using ptr = std::unique_ptr<T>;

using symbol = std::string;

/**
 * \class qasm3tools::ast::ASTNode
 * \brief Base class for AST nodes
 */
class ASTNode : public object::cloneable<ASTNode> {
    static int& max_uid_() {
        static int v;
        return v;
    } ///< the maximum uid that has been assigned

  protected:
    const int uid_;              ///< the node's unique ID
    const parser::Position pos_; ///< the node's source code position

  public:
    ASTNode(parser::Position pos) : uid_(++max_uid_()), pos_(pos) {}
    virtual ~ASTNode() = default;

    /**
     * \brief Get the ID of the node
     *
     * \return The node's unique ID
     */
    int uid() const { return uid_; }

    /**
     * \brief Get the position of the node
     *
     * \return The node's position in source
     */
    const parser::Position& pos() const { return pos_; }

    /**
     * \brief Provides dispatch for the Visitor pattern
     */
    virtual void accept(Visitor& visitor) = 0;

    /**
     * \brief Print the formatted QASM source code of the node
     *
     * \param os Output stream
     */
    virtual std::ostream& pretty_print(std::ostream& os) const = 0;

    /**
     * \brief Extraction operator override
     *
     * Extraction is non-virtual and delegates to pretty_print
     *
     * \param os Output stream
     * \param node Node to print
     */
    friend std::ostream& operator<<(std::ostream& os, const ASTNode& node) {
        return node.pretty_print(os);
    }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_BASE_HPP_ */
