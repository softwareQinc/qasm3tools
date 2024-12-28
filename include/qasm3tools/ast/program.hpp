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
 * \file qasm3tools/ast/program.hpp
 * \brief OpenQASM programs
 */

#ifndef QASM3TOOLS_AST_PROGRAM_HPP_
#define QASM3TOOLS_AST_PROGRAM_HPP_

#include "stmtblock.hpp"

namespace qasm3tools {
namespace ast {

/**
 * \class qasm3tools::ast::Program
 * \brief Program class
 */
class Program final : public BlockBase<Program> {
    bool std_include_;
    std::optional<int> qubits_;
    std::optional<int> inputs_;

  public:
    /**
     * \brief Constructs a QASM program
     *
     * \param pos The source position
     * \param body The program body
     * \param std_include Whether the standard library has been included
     * \param qubits The number of qubits
     * \param inputs The number of inputs
     */
    Program(parser::Position pos, std::list<ptr<Stmt>>&& body,
            bool std_include = false, std::optional<int> qubits = std::nullopt,
            std::optional<int> inputs = std::nullopt)
        : BlockBase(pos, std::move(body)), std_include_(std_include),
          qubits_(qubits), inputs_(inputs) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<Program> create(parser::Position pos,
                               std::list<ptr<Stmt>>&& body,
                               bool std_include = false,
                               std::optional<int> qubits = std::nullopt,
                               std::optional<int> inputs = std::nullopt) {
        return std::make_unique<Program>(pos, std::move(body), std_include,
                                         qubits, inputs);
    }

    /**
     * \brief Get the number of qubits
     *
     * \return The number of qubits
     */
    int qubits() { return *qubits_; }

    /**
     * \brief Set the number of qubits
     *
     * \param qubits The number of qubits
     */
    void set_qubits(int qubits) { qubits_ = qubits; }

    /**
     * \brief Get the number of inputs
     *
     * \return The number of inputs
     */
    int inputs() { return *inputs_; }

    /**
     * \brief Set the number of inputs
     *
     * \param qubits The number of inputs
     */
    void set_inputs(int inputs) { inputs_ = inputs; }

    /**
     * \brief Add another program's contents to the end of this program
     * \note This clears the other program's body
     */
    void extend(Program& other) {
        std_include_ = std_include_ || other.std_include_;
        if (qubits_ && other.qubits_) {
            qubits_ = *qubits_ + *other.qubits_;
        } else {
            qubits_ = std::nullopt;
        }
        body_.insert(body_.end(), std::make_move_iterator(other.body_.begin()),
                     std::make_move_iterator(other.body_.end()));
        other.std_include_ = false;
        other.qubits_ = std::nullopt;
        other.body_.clear();
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, size_t) const override {
        os << "OPENQASM 3.0;\n";
        if (std_include_) {
            os << "include \"stdgates.inc\";\n";
        }
        os << "\n";
        for (auto& x : body_) {
            for (auto& ann : x->annotations()) {
                os << *ann;
            }
            x->pretty_print(os, std_include_);
        }

        return os;
    }

  protected:
    Program* clone() const override {
        std::list<ptr<Stmt>> tmp;
        for (auto& x : body_) {
            tmp.emplace_back(object::clone(*x));
        }
        return new Program(pos_, std::move(tmp), std_include_, qubits_,
                           inputs_);
    }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_PROGRAM_HPP_ */
