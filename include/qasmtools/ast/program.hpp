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
 * \file qasmtools/ast/program.hpp
 * \brief openQASM programs
 */

#pragma once

#include "decl.hpp"

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::Program
 * \brief Program class
 */
class Program : public ASTNode {
    using ProgramStmt = std::variant<ptr<GlobalStmt>, ptr<Stmt>>;
    bool std_include_;            ///< whether the program includes stdgates
    std::list<ProgramStmt> body_; ///< the body of the program

  public:
    /**
     * \brief Constructs a QASM program
     *
     * \param pos The source position
     * \param std_include Whether the standard library has been included
     * \param body The program body
     */
    Program(parser::Position pos, bool std_include,
            std::list<ProgramStmt>&& body)
        : ASTNode(pos), std_include_(std_include), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<Program> create(parser::Position pos, bool std_include,
                               std::list<ProgramStmt>&& body) {
        return std::make_unique<Program>(pos, std_include, std::move(body));
    }

    /**
     * \brief Get the program body
     *
     * \return Reference to the body as a list of statements
     */
    std::list<ProgramStmt>& body() { return body_; }

    /**
     * \brief Get an iterator to the beginning of the body
     *
     * \return std::list iterator
     */
    std::list<ProgramStmt>::iterator begin() { return body_.begin(); }

    /**
     * \brief Get an iterator to the end of the body
     *
     * \return std::list iterator
     */
    std::list<ProgramStmt>::iterator end() { return body_.end(); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "OpenQASM 3.0;\n";
        if (std_include_)
            os << "include \"stdgates.inc\";\n";
        os << "\n";
        for (auto& x : body_) {
            std::visit(
                utils::overloaded{
                    [&os, this](auto& stmt) {
                        stmt->pretty_print(os, std_include_);
                    }},
                x);
        }

        return os;
    }
    Program* clone() const override {
        std::list<ProgramStmt> tmp;
        for (const auto& x : body_) {
            std::visit(
                utils::overloaded{
                    [&tmp](const ptr<GlobalStmt>& gs) {
                        tmp.emplace_back(ptr<GlobalStmt>(gs->clone()));
                    },
                    [&tmp](const ptr<Stmt>& ls) {
                        tmp.emplace_back(ptr<Stmt>(ls->clone()));
                    }},
                x);
        }
        return new Program(pos_, std_include_, std::move(tmp));
    }
};

} // namespace ast
} // namespace qasmtools
