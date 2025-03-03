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
 * \file qasm3tools/ast/gate.hpp
 * \brief OpenQASM gates
 */

#ifndef QASM3TOOLS_AST_GATE_HPP_
#define QASM3TOOLS_AST_GATE_HPP_

#include <list>
#include <vector>

#include "base.hpp"
#include "exprbase.hpp"
#include "indexid.hpp"
#include "stmtbase.hpp"

namespace qasm3tools {
namespace ast {

/**
 * \class qasm3tools::ast::GateModifier
 * \brief Class for gate modifiers
 */
class GateModifier : public ASTNode {
  public:
    GateModifier(parser::Position pos) : ASTNode(pos) {}
    virtual ~GateModifier() = default;

  protected:
    virtual GateModifier* clone() const = 0;
};

/**
 * \class qasm3tools::ast::CtrlModifier
 * \brief Class for control modifiers
 */
class CtrlModifier : public GateModifier {
    bool neg_;                   // true for negctrl, false for ctrl
    std::optional<ptr<Expr>> n_; // number of control bits
  public:
    /**
     * \brief Constructs a control modifier
     *
     * \param pos The source position
     * \param neg True for negctrl, false for ctrl
     * \param n The number of control bits
     */
    CtrlModifier(parser::Position pos, bool neg,
                 std::optional<ptr<Expr>>&& n = std::nullopt)
        : GateModifier(pos), neg_(neg), n_(std::move(n)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<CtrlModifier>
    create(parser::Position pos, bool neg,
           std::optional<ptr<Expr>>&& n = std::nullopt) {
        return std::make_unique<CtrlModifier>(pos, neg, std::move(n));
    }

    /**
     * \brief Get whether the modifier is negctrl or ctrl
     *
     * \return True for negctrl, false for ctrl
     */
    bool neg() const { return neg_; }

    /**
     * \brief Get the number of control bits
     *
     * \return Optional expr number of control bits
     */
    std::optional<ptr<Expr>>& n() { return n_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << (neg_ ? "negctrl" : "ctrl");
        if (n_) {
            os << "(" << **n_ << ")";
        }
        os << " @ ";
        return os;
    }

  protected:
    CtrlModifier* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (n_) {
            tmp = object::clone(**n_);
        }
        return new CtrlModifier(pos_, neg_, std::move(tmp));
    }
};

/**
 * \class qasm3tools::ast::InvModifier
 * \brief Class for inversion modifiers
 */
class InvModifier : public GateModifier {
  public:
    /**
     * \brief Constructs an inversion modifier
     *
     * \param pos The source position
     */
    InvModifier(parser::Position pos) : GateModifier(pos) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<InvModifier> create(parser::Position pos) {
        return std::make_unique<InvModifier>(pos);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "inv @ ";
        return os;
    }

  protected:
    InvModifier* clone() const override { return new InvModifier(pos_); }
};

/**
 * \class qasm3tools::ast::PowModifier
 * \brief Class for powering modifiers
 */
class PowModifier : public GateModifier {
    ptr<Expr> r_;

  public:
    /**
     * \brief Constructs a powering modifier
     *
     * \param pos The source position
     * \param r The power
     */
    PowModifier(parser::Position pos, ptr<Expr> r)
        : GateModifier(pos), r_(std::move(r)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<PowModifier> create(parser::Position pos, ptr<Expr> r) {
        return std::make_unique<PowModifier>(pos, std::move(r));
    }

    /**
     * \brief Get the power
     *
     * \return A reference to the power
     */
    Expr& r() { return *r_; }

    /**
     * \brief Set the power
     *
     * \param r The new power
     */
    void set_r(ptr<Expr> r) { r_ = std::move(r); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "pow(" << *r_ << ") @ ";
        return os;
    }

  protected:
    PowModifier* clone() const override {
        return new PowModifier(pos_, object::clone(*r_));
    }
};

/**
 * \class qasm3tools::ast::Gate
 * \brief Statement sub-class for gate
 */
class Gate : public QuantumStmt {
  public:
    Gate(parser::Position pos, std::list<ptr<GateModifier>>&& modifiers,
         std::vector<ptr<IndexId>>&& q_args)
        : QuantumStmt(pos), modifiers_(std::move(modifiers)),
          q_args_(std::move(q_args)) {}

    /**
     * \brief Get the list of gate modifiers
     *
     * \return Reference to the list of gate modifiers
     */
    std::list<ptr<GateModifier>>& modifiers() { return modifiers_; }

    /**
     * \brief Get the number of quantum arguments
     *
     * \return The number of arguments
     */
    int num_qargs() const { return static_cast<int>(q_args_.size()); }

    /**
     * \brief Get the ith quantum argument
     *
     * \param i The number of the argument, 0-indexed
     * \return Reference to the argument
     */
    IndexId& qarg(int i) { return *q_args_[i]; }

    /**
     * \brief Get the list of quantum arguments
     *
     * \return Reference to the list of arguments
     */
    std::vector<ptr<IndexId>>& qargs() { return q_args_; }

    /**
     * \brief Apply a function to each quantum argument
     *
     * \param f Void function accepting a reference to an argument
     */
    void foreach_qarg(std::function<void(IndexId&)> f) {
        for (auto& x : q_args_) {
            f(*x);
        }
    }

    /**
     * \brief Set the ith quantum argument
     *
     * \param i The number of the argument, 0-indexed
     * \param arg The new argument
     */
    void set_qarg(int i, ptr<IndexId> arg) { q_args_[i] = std::move(arg); }

    virtual ~Gate() = default;

  protected:
    std::list<ptr<GateModifier>> modifiers_; ///< gate modifiers
    std::vector<ptr<IndexId>> q_args_;       ///< list of quantum arguments

    void print_modifiers(std::ostream& os) const {
        for (auto& x : modifiers_) {
            os << *x;
        }
    }

    void print_qargs(std::ostream& os) const {
        for (auto it = q_args_.begin(); it != q_args_.end(); it++) {
            os << (it == q_args_.begin() ? " " : ",") << **it;
        }
    }

    virtual Gate* clone() const = 0;
};

/**
 * \class qasm3tools::ast::UGate
 * \brief Class for U gates
 * \see qasm3tools::ast::Gate
 */
class UGate final : public Gate {
    ptr<Expr> theta_;  ///< theta angle
    ptr<Expr> phi_;    ///< phi angle
    ptr<Expr> lambda_; ///< lambda angle

  public:
    /**
     * \brief Constructs a U gate
     *
     * \param pos The source position
     * \param modifiers The gate modifiers
     * \param theta The theta angle
     * \param phi The phi angle
     * \param lambda The lambda angle
     * \param arg Rvalue reference to the quantum argument
     */
    UGate(parser::Position pos, std::list<ptr<GateModifier>>&& modifiers,
          ptr<Expr> theta, ptr<Expr> phi, ptr<Expr> lambda,
          std::vector<ptr<IndexId>>&& q_args)
        : Gate(pos, std::move(modifiers), std::move(q_args)),
          theta_(std::move(theta)), phi_(std::move(phi)),
          lambda_(std::move(lambda)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<UGate> create(parser::Position pos,
                             std::list<ptr<GateModifier>>&& modifiers,
                             ptr<Expr> theta, ptr<Expr> phi, ptr<Expr> lambda,
                             std::vector<ptr<IndexId>>&& q_args) {
        return std::make_unique<UGate>(pos, std::move(modifiers),
                                       std::move(theta), std::move(phi),
                                       std::move(lambda), std::move(q_args));
    }

    /**
     * \brief Get the theta angle
     *
     * \return Reference to the angle expression
     */
    Expr& theta() { return *theta_; }

    /**
     * \brief Get the phi angle
     *
     * \return Reference to the angle expression
     */
    Expr& phi() { return *phi_; }

    /**
     * \brief Get the lambda angle
     *
     * \return Reference to the angle expression
     */
    Expr& lambda() { return *lambda_; }

    /**
     * \brief Set the theta angle
     *
     * \param theta The new angle expression
     */
    void set_theta(ptr<Expr> theta) { theta_ = std::move(theta); }

    /**
     * \brief Set the phi angle
     *
     * \param theta The new angle expression
     */
    void set_phi(ptr<Expr> phi) { phi_ = std::move(phi); }

    /**
     * \brief Set the lambda angle
     *
     * \param theta The new angle expression
     */
    void set_lambda(ptr<Expr> lambda) { lambda_ = std::move(lambda); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        print_modifiers(os);
        os << "U(" << *theta_ << "," << *phi_ << "," << *lambda_ << ")";
        print_qargs(os);
        os << ";\n";
        return os;
    }

  protected:
    UGate* clone() const override {
        std::list<ptr<GateModifier>> tmp;
        for (auto& x : modifiers_) {
            tmp.emplace_back(object::clone(*x));
        }
        std::vector<ptr<IndexId>> q_tmp;
        for (auto& x : q_args_) {
            q_tmp.emplace_back(object::clone(*x));
        }
        return new UGate(pos_, std::move(tmp), object::clone(*theta_),
                         object::clone(*phi_), object::clone(*lambda_),
                         std::move(q_tmp));
    }
};

/**
 * \class qasm3tools::ast::GPhase
 * \brief Class for global phase gates
 * \see qasm3tools::ast::Gate
 */
class GPhase final : public Gate {
    ptr<Expr> gamma_; ///< gamma angle

  public:
    /**
     * \brief Constructs a U gate
     *
     * \param pos The source position
     * \param modifiers The gate modifiers
     * \param gamma The gamma angle
     * \param arg Rvalue reference to the quantum argument
     */
    GPhase(parser::Position pos, std::list<ptr<GateModifier>>&& modifiers,
           ptr<Expr> gamma, std::vector<ptr<IndexId>>&& q_args)
        : Gate(pos, std::move(modifiers), std::move(q_args)),
          gamma_(std::move(gamma)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<GPhase> create(parser::Position pos,
                              std::list<ptr<GateModifier>>&& modifiers,
                              ptr<Expr> gamma,
                              std::vector<ptr<IndexId>>&& q_args) {
        return std::make_unique<GPhase>(pos, std::move(modifiers),
                                        std::move(gamma), std::move(q_args));
    }

    /**
     * \brief Get the gamma angle
     *
     * \return Reference to the angle expression
     */
    Expr& gamma() { return *gamma_; }

    /**
     * \brief Set the theta angle
     *
     * \param theta The new angle expression
     */
    void set_gamma(ptr<Expr> gamma) { gamma_ = std::move(gamma); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        print_modifiers(os);
        os << "gphase(" << *gamma_ << ")";
        print_qargs(os);
        os << ";\n";
        return os;
    }

  protected:
    GPhase* clone() const override {
        std::list<ptr<GateModifier>> tmp;
        for (auto& x : modifiers_) {
            tmp.emplace_back(object::clone(*x));
        }
        std::vector<ptr<IndexId>> q_tmp;
        for (auto& x : q_args_) {
            q_tmp.emplace_back(object::clone(*x));
        }
        return new GPhase(pos_, std::move(tmp), object::clone(*gamma_),
                          std::move(q_tmp));
    }
};

/**
 * \class qasm3tools::ast::DeclaredGate
 * \brief Class for declared gate applications
 * \see qasm3tools::ast::Gate
 */
class DeclaredGate final : public Gate {
    symbol name_;                   ///< gate identifier
    std::vector<ptr<Expr>> c_args_; ///< list of classical arguments

  public:
    /**
     * \brief Constructs an application of a declared gate
     *
     * \param pos The source position
     * \param modifiers The gate modifiers
     * \param name The gate name
     * \param c_args Rvalue reference to a list of classical arguments
     * \param q_args Rvalue reference to a list of quantum arguments
     */
    DeclaredGate(parser::Position pos, std::list<ptr<GateModifier>>&& modifiers,
                 symbol name, std::vector<ptr<Expr>>&& c_args,
                 std::vector<ptr<IndexId>>&& q_args)
        : Gate(pos, std::move(modifiers), std::move(q_args)), name_(name),
          c_args_(std::move(c_args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<DeclaredGate> create(parser::Position pos,
                                    std::list<ptr<GateModifier>>&& modifiers,
                                    symbol name,
                                    std::vector<ptr<Expr>>&& c_args,
                                    std::vector<ptr<IndexId>>&& q_args) {
        return std::make_unique<DeclaredGate>(pos, std::move(modifiers), name,
                                              std::move(c_args),
                                              std::move(q_args));
    }

    /**
     * \brief Get the gate name
     *
     * \return Const reference to the gate name
     */
    const symbol& name() const { return name_; }

    /**
     * \brief Get the number of classical arguments
     *
     * \return The number of arguments
     */
    int num_cargs() const { return static_cast<int>(c_args_.size()); }

    /**
     * \brief Get the ith classical argument
     *
     * \param i The number of the argument, 0-indexed
     * \return Reference to an expression
     */
    Expr& carg(int i) { return *(c_args_[i]); }

    /**
     * \brief Apply a function to each classical argument
     *
     * \param f Void function accepting an expression reference
     */
    void foreach_carg(std::function<void(Expr&)> f) {
        for (auto& x : c_args_) {
            f(*x);
        }
    }

    /**
     * \brief Set the ith classical argument
     *
     * \param i The number of the argument, 0-indexed
     * \param expr An expression giving the new argument
     */
    void set_carg(int i, ptr<Expr> expr) { c_args_[i] = std::move(expr); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        print_modifiers(os);
        os << name_;
        if (c_args_.size() > 0) {
            os << "(";
            for (auto it = c_args_.begin(); it != c_args_.end(); it++) {
                os << (it == c_args_.begin() ? "" : ",") << **it;
            }
            os << ")";
        }
        print_qargs(os);
        os << ";\n";
        return os;
    }

  protected:
    DeclaredGate* clone() const override {
        std::list<ptr<GateModifier>> tmp;
        for (auto& x : modifiers_) {
            tmp.emplace_back(object::clone(*x));
        }
        std::vector<ptr<Expr>> c_tmp;
        for (auto& x : c_args_) {
            c_tmp.emplace_back(object::clone(*x));
        }
        std::vector<ptr<IndexId>> q_tmp;
        for (auto& x : q_args_) {
            q_tmp.emplace_back(object::clone(*x));
        }

        return new DeclaredGate(pos_, std::move(tmp), name_, std::move(c_tmp),
                                std::move(q_tmp));
    }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_GATE_HPP_ */
