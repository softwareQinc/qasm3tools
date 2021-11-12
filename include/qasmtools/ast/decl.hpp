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
#include <variant>
#include <vector>

namespace qasmtools {
namespace ast {

static const std::set<std::string_view> stdgates{
    "p",   "x",   "y",     "z",      "h",  "s",    "sdg", "t",
    "tdg", "sx",  "rx",    "ry",     "rz", "cx",   "cy",  "cz",
    "cp",  "crx", "cry",   "crz",    "ch", "swap", "ccx", "cswap",
    "cu",  "CX",  "phase", "cphase", "id", "u1",   "u2",  "u3"};

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
 * \class qasmtools::ast::Param
 * \brief Class for subroutine parameters
 */
class Param : public ASTNode {
  public:
    Param(parser::Position pos, symbol id) : ASTNode(pos), id_(id) {}
    virtual ~Param() = default;

    /**
     * \brief Return the parameter identifier
     *
     * \return Constant reference to the identifier
     */
    const symbol& id() { return id_; }

  protected:
    symbol id_; ///< the parameter identifier
    virtual Param* clone() const = 0;
};

/**
 * \class qasmtools::ast::ClassicalParam
 * \brief Class for subroutine classical parameters
 */
class ClassicalParam : public Param {
    ptr<ClassicalType> type_;

  public:
    /**
     * \brief Constructs a classical parameter
     *
     * \param pos The source position
     * \param id The parameter identifier
     * \param type The parameter type
     */
    ClassicalParam(parser::Position pos, symbol id, ptr<ClassicalType> type)
        : Param(pos, id), type_(std::move(type)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ClassicalParam> create(parser::Position pos, symbol id,
                                      ptr<ClassicalType> type) {
        return std::make_unique<ClassicalParam>(pos, id, std::move(type));
    }

    /**
     * \brief Get the parmeter type
     *
     * \return Reference to the type
     */
    ClassicalType& type() { return *type_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << *type_ << " " << id_;
        return os;
    }

  protected:
    ClassicalParam* clone() const override {
        return new ClassicalParam(pos_, id_, object::clone(*type_));
    }
};

/**
 * \class qasmtools::ast::QubitParam
 * \brief Class for subroutine qubit parameters
 */
class QubitParam : public Param {
    std::optional<ptr<Expr>> size_;

  public:
    /**
     * \brief Constructs a qubit type
     *
     * \param pos The source position
     * \param size The size
     */
    QubitParam(parser::Position pos, symbol id,
               std::optional<ptr<Expr>>&& size = std::nullopt)
        : Param(pos, id), size_(std::move(size)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<QubitParam>
    create(parser::Position pos, symbol id,
           std::optional<ptr<Expr>>&& size = std::nullopt) {
        return std::make_unique<QubitParam>(pos, id, std::move(size));
    }

    /**
     * \brief Get the size
     *
     * \return Optional expr size
     */
    std::optional<ptr<Expr>>& size() { return size_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "qubit";
        if (size_)
            os << "[" << **size_ << "]";
        os << " " << id_;
        return os;
    }

  protected:
    QubitParam* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (size_)
            tmp = object::clone(**size_);
        return new QubitParam(pos_, id_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::SubroutineDecl
 * \brief Class for subroutine declarations
 * \see qasmtools::ast::Stmt
 * \see qasmtools::ast::Decl
 */
class SubroutineDecl final : public GlobalStmt, public Decl {
    std::vector<ptr<Param>> params_;                ///< parameters
    std::optional<ptr<ClassicalType>> return_type_; ///< return type
    ptr<ProgramBlock> body_;                        ///< subroutine body

  public:
    /**
     * \brief Constructs a subroutine declaration
     *
     * \param pos The source position
     * \param id The subroutine identifier
     * \param params List of parameters
     * \param return_type Optional return type (default = std::nullopt)
     * \param body The subroutine body
     */
    SubroutineDecl(parser::Position pos, symbol id,
                   std::vector<ptr<Param>>&& params, ptr<ProgramBlock> body)
        : GlobalStmt(pos), Decl(id), params_(std::move(params)),
          return_type_(std::nullopt), body_(std::move(body)) {}
    SubroutineDecl(parser::Position pos, symbol id,
                   std::vector<ptr<Param>>&& params,
                   std::optional<ptr<ClassicalType>>&& return_type,
                   ptr<ProgramBlock> body)
        : GlobalStmt(pos), Decl(id), params_(std::move(params)),
          return_type_(std::move(return_type)), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<SubroutineDecl> create(parser::Position pos, symbol id,
                                      std::vector<ptr<Param>>&& params,
                                      ptr<ProgramBlock> body) {
        return std::make_unique<SubroutineDecl>(pos, id, std::move(params),
                                                std::move(body));
    }
    static ptr<SubroutineDecl>
    create(parser::Position pos, symbol id, std::vector<ptr<Param>>&& params,
           std::optional<ptr<ClassicalType>>&& return_type,
           ptr<ProgramBlock> body) {
        return std::make_unique<SubroutineDecl>(pos, id, std::move(params),
                                                std::move(return_type),
                                                std::move(body));
    }

    /**
     * \brief Get the parameter list
     *
     * \return Reference to the list of parameters
     */
    std::vector<ptr<Param>>& params() { return params_; }

    /**
     * \brief Get the return type
     *
     * \return Reference to the return type
     */
    std::optional<ptr<ClassicalType>>& return_type() { return return_type_; }

    /**
     * \brief Get the subroutine body
     *
     * \return Reference to the body
     */
    ProgramBlock& body() { return *body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "def " << id_ << "(";
        for (auto it = params_.begin(); it != params_.end(); it++) {
            os << (it == params_.begin() ? "" : ", ") << **it;
        }
        os << ")";
        if (return_type_)
            os << " -> " << **return_type_;
        os << " ";
        body_->pretty_print(os, indents);
        return os;
    }

  protected:
    SubroutineDecl* clone() const override {
        std::vector<ptr<Param>> tmp_params;
        for (auto& x : params_)
            tmp_params.emplace_back(object::clone(*x));
        std::optional<ptr<ClassicalType>> tmp_return = std::nullopt;
        if (return_type_)
            tmp_return = object::clone(**return_type_);
        return new SubroutineDecl(pos_, id_, std::move(tmp_params),
                                  std::move(tmp_return), object::clone(*body_));
    }
};

/**
 * \class qasmtools::ast::ExternDecl
 * \brief Class for external subroutine declarations
 * \see qasmtools::ast::Stmt
 * \see qasmtools::ast::Decl
 */
class ExternDecl final : public GlobalStmt, public Decl {
    std::vector<ptr<ClassicalType>> param_types_;   ///< parameter types
    std::optional<ptr<ClassicalType>> return_type_; ///< return type

  public:
    /**
     * \brief Constructs an external subroutine declaration
     *
     * \param pos The source position
     * \param id The subroutine identifier
     * \param param_types List of parameter types
     * \param return_type Optional return type (default = std::nullopt)
     */
    ExternDecl(parser::Position pos, symbol id,
               std::vector<ptr<ClassicalType>>&& param_types,
               std::optional<ptr<ClassicalType>>&& return_type = std::nullopt)
        : GlobalStmt(pos), Decl(id), param_types_(std::move(param_types)),
          return_type_(std::move(return_type)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ExternDecl>
    create(parser::Position pos, symbol id,
           std::vector<ptr<ClassicalType>>&& param_types,
           std::optional<ptr<ClassicalType>>&& return_type = std::nullopt) {
        return std::make_unique<ExternDecl>(pos, id, std::move(param_types),
                                            std::move(return_type));
    }

    /**
     * \brief Get the parameter type list
     *
     * \return Reference to the list of parameter types
     */
    std::vector<ptr<ClassicalType>>& param_types() { return param_types_; }

    /**
     * \brief Get the return type
     *
     * \return Reference to the return type
     */
    std::optional<ptr<ClassicalType>>& return_type() { return return_type_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "extern " << id_ << "(";
        for (auto it = param_types_.begin(); it != param_types_.end(); it++) {
            os << (it == param_types_.begin() ? "" : ", ") << **it;
        }
        os << ")";
        if (return_type_)
            os << " -> " << **return_type_;
        os << ";\n";
        return os;
    }

  protected:
    ExternDecl* clone() const override {
        std::vector<ptr<ClassicalType>> tmp_params;
        for (auto& x : param_types_)
            tmp_params.emplace_back(object::clone(*x));
        std::optional<ptr<ClassicalType>> tmp_return = std::nullopt;
        if (return_type_)
            tmp_return = object::clone(**return_type_);
        return new ExternDecl(pos_, id_, std::move(tmp_params),
                              std::move(tmp_return));
    }
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
    std::list<QuantumBlockStmt>::iterator begin() {
        return body_->body().begin();
    }

    /**
     * \brief Get an iterator to the end of the body
     *
     * \return std::list iterator
     */
    std::list<QuantumBlockStmt>::iterator end() { return body_->body().end(); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool suppress_std,
                               size_t indents) const override {
        if (suppress_std && is_std_gate(id_))
            return os;

        os << "gate " << id_;
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
        os << " ";
        body_->pretty_print(os, indents);
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
    static ptr<QuantumRegisterDecl>
    create(parser::Position pos, symbol id,
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
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
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
    static ptr<ClassicalDecl>
    create(parser::Position pos, symbol id, ptr<ClassicalType> type,
           std::optional<ptr<Expr>>&& equalsexp = std::nullopt,
           bool is_const = false) {
        return std::make_unique<ClassicalDecl>(pos, id, std::move(type),
                                               std::move(equalsexp), is_const);
    }

    /**
     * \brief Get the type
     *
     * \return Reference to the type
     */
    ClassicalType& type() { return *type_; }

    /**
     * \brief Get the intitialized value
     *
     * \return Optional expr intitialized value
     */
    std::optional<ptr<Expr>>& equalsexp() { return equalsexp_; }

    /**
     * \brief Get whether the declaration is const
     *
     * \return Whether the declaration is const
     */
    bool is_const() { return is_const_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
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

/**
 * \class qasmtools::ast::CalGrammarDecl
 * \brief Class for calibration grammar declarations
 * \see qasmtools::ast::Stmt
 */
class CalGrammarDecl final : public GlobalStmt {
    std::string name_; ///< the name of the grammar (with quotation marks)

  public:
    /**
     * \brief Constructs a calibration grammar declaration
     *
     * \param pos The source position
     * \param name The name of the grammar
     */
    CalGrammarDecl(parser::Position pos, std::string name)
        : GlobalStmt(pos), name_(name) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<CalGrammarDecl> create(parser::Position pos, std::string name) {
        return std::make_unique<CalGrammarDecl>(pos, name);
    }

    /**
     * \brief Return the name of the grammar
     *
     * \return Constant reference to the name
     */
    const std::string& name() const { return name_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "defcalgrammar " << name_ << ";\n";
        return os;
    }

  protected:
    CalGrammarDecl* clone() const override {
        return new CalGrammarDecl(pos_, name_);
    }
};

/**
 * \class qasmtools::ast::CalibrationDecl
 * \brief Class for calibration declarations
 * \see qasmtools::ast::Stmt
 * \see qasmtools::ast::Decl
 */
class CalibrationDecl final : public GlobalStmt, public Decl {
  public:
    using ParamsType =
        std::variant<std::monostate, std::vector<ptr<ClassicalParam>>,
                     std::vector<ptr<Expr>>>;

  private:
    ParamsType c_params_;                           ///< classical parameters
    std::vector<symbol> q_params_;                  ///< quantum parameters
    std::optional<ptr<ClassicalType>> return_type_; ///< return type
    std::string body_;                              ///< body

  public:
    /**
     * \brief Constructs a calibration declaration
     *
     * \param pos The source position
     * \param id The calibration identifier
     * \param c_params List of classical parameters
     * \param q_params List of quantum parameters
     * \param return_type Optional return type (default = std::nullopt)
     * \param body The calibration body
     */
    CalibrationDecl(parser::Position pos, symbol id, ParamsType&& c_params,
                    std::vector<symbol> q_params,
                    std::optional<ptr<ClassicalType>>&& return_type,
                    std::string body)
        : GlobalStmt(pos), Decl(id), c_params_(std::move(c_params)),
          q_params_(q_params), return_type_(std::move(return_type)),
          body_(body) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<CalibrationDecl>
    create(parser::Position pos, symbol id, ParamsType&& c_params,
           std::vector<symbol> q_params,
           std::optional<ptr<ClassicalType>>&& return_type, std::string body) {
        return std::make_unique<CalibrationDecl>(pos, id, std::move(c_params),
                                                 q_params,
                                                 std::move(return_type), body);
    }

    /**
     * \brief Get the classical parameter list
     *
     * \return Reference to the list of classical parameters
     */
    ParamsType& c_params() { return c_params_; }

    /**
     * \brief Get the quantum parameter list
     *
     * \return Reference to the list of quantum parameters
     */
    std::vector<symbol>& q_params() { return q_params_; }

    /**
     * \brief Get the return type
     *
     * \return Reference to the return type
     */
    std::optional<ptr<ClassicalType>>& return_type() { return return_type_; }

    /**
     * \brief Get the calibration body
     *
     * \return Reference to the body
     */
    const std::string& body() const { return body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool, size_t) const override {
        os << "defcal " << id_;

        std::visit(utils::overloaded{
                       [&os](const std::vector<ptr<ClassicalParam>>& cps) {
                           os << "(";
                           for (auto it = cps.begin(); it != cps.end(); it++) {
                               os << (it == cps.begin() ? "" : ", ") << **it;
                           }
                           os << ")";
                       },
                       [&os](const std::vector<ptr<Expr>>& exps) {
                           os << "(";
                           for (auto it = exps.begin(); it != exps.end();
                                it++) {
                               os << (it == exps.begin() ? "" : ", ") << **it;
                           }
                           os << ")";
                       },
                       [](auto) {}},
                   c_params_);

        os << " ";
        for (auto it = q_params_.begin(); it != q_params_.end(); it++) {
            os << (it == q_params_.begin() ? "" : ", ") << *it;
        }
        if (return_type_)
            os << " -> " << **return_type_;
        os << " { " << body_ << " }\n";
        return os;
    }

  protected:
    CalibrationDecl* clone() const override {
        ParamsType tmp = std::monostate();
        std::visit(utils::overloaded{
                       [&tmp](const std::vector<ptr<ClassicalParam>>& cps) {
                           std::vector<ptr<ClassicalParam>> cps_copy;
                           for (auto& x : cps)
                               cps_copy.emplace_back(object::clone(*x));
                           tmp = std::move(cps_copy);
                       },
                       [&tmp](const std::vector<ptr<Expr>>& exps) {
                           std::vector<ptr<Expr>> exps_copy;
                           for (auto& x : exps)
                               exps_copy.emplace_back(object::clone(*x));
                           tmp = std::move(exps_copy);
                       },
                       [](auto) {}},
                   c_params_);
        std::optional<ptr<ClassicalType>> tmp_return = std::nullopt;
        if (return_type_)
            tmp_return = object::clone(**return_type_);
        return new CalibrationDecl(pos_, id_, std::move(tmp), q_params_,
                                   std::move(tmp_return), body_);
    }
};

} // namespace ast
} // namespace qasmtools
