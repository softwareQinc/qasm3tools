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
 * \file qasmtools/ast/decl.hpp
 * \brief openQASM declarations
 */

#pragma once

#include "exprbase.hpp"
#include "stmtblock.hpp"
#include "type.hpp"

#include <set>
#include <vector>

namespace qasmtools {
namespace ast {

static const std::set<std::string_view> stdgates{
    "p", "x", "y", "z", "h", "s", "sdg", "t", "tdg", "sx", "rx", "ry", "rz",
    "cx", "cy", "cz", "cp", "crx", "cry", "crz", "ch", "swap", "ccx", "cswap",
    "cu", "CX", "phase", "cphase", "id", "u1", "u2", "u3"};

/**
 * \brief Tests if identifier is part of the OpenQASM 3 standard library
 *
 * \param id Identifier
 * \return True if \a id is part of the standard openQASM qelib, false otherwise
 */
inline bool is_std_gate(const std::string& id) {
    return stdgates.find(id) != stdgates.end();
}

/**
 * \class qasmtools::ast::Decl
 * \brief Base class for openQASM declarations
 *
 * Declarations are attribute classes as they can occur in different
 * statement contexts. To avoid diamond inheritance, any derived declaration
 * should also inherit from a statement class
 */
class Decl {
  protected:
    symbol id_; ///< the name of the declaration

  public:
    Decl(symbol id) : id_(id) {}
    virtual ~Decl() = default;

    /**
     * \brief Return the name being declared
     *
     * \return Constant reference to the identifier
     */
    const symbol& id() { return id_; }
};

/**
 * \class qasmtools::ast::GateDecl
 * \brief Class for gate declarations
 * \see qasmtools::ast::Stmt
 * \see qasmtools::ast::Decl
 */
class GateDecl final : public GlobalStmt, public Decl {
    std::vector<symbol> c_params_; ///< classical parameters
    std::vector<symbol> q_params_; ///< quantum parameters
    ptr<QuantumBlock> body_;       ///< gate body

  public:
    /**
     * \brief Constructs a gate declaration
     *
     * \param pos The source position
     * \param id The gate identifier
     * \param c_params List of classical parameters
     * \param q_params List of quantum parameters
     * \param body Gate body
     */
    GateDecl(parser::Position pos, symbol id, std::vector<symbol> c_params,
             std::vector<symbol> q_params, ptr<QuantumBlock> body)
        : GlobalStmt(pos), Decl(id), c_params_(c_params), q_params_(q_params),
          body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<GateDecl> create(parser::Position pos, symbol id,
                                std::vector<symbol> c_params,
                                std::vector<symbol> q_params,
                                ptr<QuantumBlock> body) {
        return std::make_unique<GateDecl>(pos, id, c_params, q_params,
                                          std::move(body));
    }

    /**
     * \brief Get the classical parameter list
     *
     * \return Reference to the list of classical parameter names
     */
    std::vector<symbol>& c_params() { return c_params_; }

    /**
     * \brief Get the quantum parameter list
     *
     * \return Reference to the list of quantum parameter names
     */
    std::vector<symbol>& q_params() { return q_params_; }

    /**
     * \brief Get the gate body
     *
     * \return Reference to the body of the gate
     */
    QuantumBlock& body() { return *body_; }

    /**
     * \brief Get an iterator to the beginning of the body
     *
     * \return std::list iterator
     */
    std::list<std::variant<ptr<QuantumStmt>, ptr<QuantumLoop>>>::iterator
    begin() {
        return body_->body().begin();
    }

    /**
     * \brief Get an iterator to the end of the body
     *
     * \return std::list iterator
     */
    std::list<std::variant<ptr<QuantumStmt>, ptr<QuantumLoop>>>::iterator
    end() {
        return body_->body().end();
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os,
                               bool suppress_std) const override {
        if (suppress_std && is_std_gate(id_))
            return os;

        if (c_params_.size() > 0) {
            os << "(";
            for (auto it = c_params_.begin(); it != c_params_.end(); it++) {
                os << (it == c_params_.begin() ? "" : ",") << *it;
            }
            os << ")";
        }
        os << " ";
        for (auto it = q_params_.begin(); it != q_params_.end(); it++) {
            os << (it == q_params_.begin() ? "" : ",") << *it;
        }
        os << *body_;
        return os;
    }
  protected:
    GateDecl* clone() const override {
        return new GateDecl(pos_, id_, c_params_, q_params_,
                            object::clone(*body_));
    }
};

/**
 * \class qasmtools::ast::QuantumRegisterDecl
 * \brief Class for quantum register declarations
 * \see qasmtools::ast::Decl
 */
class QuantumRegisterDecl final : public GlobalStmt, public Decl {
    std::optional<ptr<Expr>> size_; ///< the size of the register

  public:
    /**
     * \brief Constructs a register declaration
     *
     * \param pos The source position
     * \param id The register identifier
     * \param size the size of the register
     */
    QuantumRegisterDecl(parser::Position pos, symbol id,
                        std::optional<ptr<Expr>>&& size = std::nullopt)
        : GlobalStmt(pos), Decl(id), size_(std::move(size)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<QuantumRegisterDecl> create(parser::Position pos, symbol id,
            std::optional<ptr<Expr>>&& size = std::nullopt) {
        return std::make_unique<QuantumRegisterDecl>(pos, id, std::move(size));
    }

    /**
     * \brief Get the size of the register
     *
     * \return Optional expr size of the register
     */
    std::optional<ptr<Expr>>& size() { return size_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        os << "qubit";
        if (size_)
            os << "[" << **size_ << "]";
        os << " " << id_ << ";\n";
        return os;
    }
  protected:
    QuantumRegisterDecl* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (size_)
            tmp = object::clone(**size_);
        return new QuantumRegisterDecl(pos_, id_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::ClassicalDecl
 * \brief Class for classical type declarations
 * \see qasmtools::ast::Decl
 */
class ClassicalDecl final : public Stmt, public Decl {
    ptr<ClassicalType> type_;            ///< the type
    std::optional<ptr<Expr>> equalsexp_; ///< initialized value
    bool is_const_;                      ///< whether the declaration is const

  public:
    /**
     * \brief Constructs a classical declaration
     *
     * \param pos The source position
     * \param id The identifier
     * \param type The type
     * \param equalsexp The initialized value
     * \param is_const Whether the declaration is const
     */
    ClassicalDecl(parser::Position pos, symbol id, ptr<ClassicalType> type,
                  std::optional<ptr<Expr>>&& equalsexp = std::nullopt,
                  bool is_const = false)
        : Stmt(pos), Decl(id), type_(std::move(type)),
          equalsexp_(std::move(equalsexp)), is_const_(is_const) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ClassicalDecl> create(parser::Position pos, symbol id,
            ptr<ClassicalType> type,
            std::optional<ptr<Expr>>&& equalsexp = std::nullopt,
            bool is_const = false) {
        return std::make_unique<ClassicalDecl>(pos, id, std::move(type),
                                               std::move(equalsexp), is_const);
    }

    /**
     * \brief Get whether the declaration is const
     *
     * \return Whether the declaration is const
     */
    bool is_const() { return is_const_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool) const override {
        if (is_const_)
            os << "const ";
        os << *type_ << " " << id_;
        if (equalsexp_)
            os << " = " << **equalsexp_;
        os << ";\n";
        return os;
    }
  protected:
    ClassicalDecl* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (equalsexp_)
            tmp = object::clone(**equalsexp_);
        return new ClassicalDecl(pos_, id_, object::clone(*type_),
                                 std::move(tmp), is_const_);
    }
};

} // namespace ast
} // namespace qasmtools
