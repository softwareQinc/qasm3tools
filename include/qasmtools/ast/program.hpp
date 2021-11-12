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

#include "stmtblock.hpp"

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::Program
 * \brief Program class
 */

using ProgramStmt = std::variant<ptr<GlobalStmt>, ptr<Stmt>>;
class Program : public BlockBase<ProgramStmt, Program> {
    bool std_include_;

  public:
    /**
     * \brief Constructs a QASM program
     *
     * \param pos The source position
     * \param std_include Whether the standard library has been included
     * \param body The program body
     */
    Program(parser::Position pos, std::list<ProgramStmt>&& body,
            bool std_include = false)
        : BlockBase(pos, std::move(body)), std_include_(std_include) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<Program> create(parser::Position pos,
                               std::list<ProgramStmt>&& body,
                               bool std_include = false) {
        return std::make_unique<Program>(pos, std::move(body), std_include);
    }

    /**
     * \brief Get whether the standard library has been included
     *
     * \return Whether the standard library has been included
     */
    bool includes_std() { return std_include_; }

    /**
     * \brief Set whether the standard library has been included
     */
    void set_includes_std(bool includes_std) { std_include_ = includes_std; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, size_t) const override {
        os << "OPENQASM 3.0;\n";
        if (std_include_)
            os << "include \"stdgates.inc\";\n";
        os << "\n";
        for (auto& x : body_) {
            std::visit(
                [&os, this](auto& stmt) {
                    stmt->pretty_print(os, std_include_);
                },
                x);
        }

        return os;
    }

  protected:
    Program* clone() const override {
        std::list<ProgramStmt> tmp;
        for (auto& x : body_) {
            std::visit(
                [&tmp](auto& stmt) { tmp.emplace_back(object::clone(*stmt)); },
                x);
        }
        return new Program(pos_, std::move(tmp), std_include_);
    }
};

} // namespace ast
} // namespace qasmtools
