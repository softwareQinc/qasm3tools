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
 * \file qasmtools/ast/loop.hpp
 * \brief OpenQASM loop statements
 */

#pragma once

#include "base.hpp"
#include "exprbase.hpp"
#include "stmtbase.hpp"
#include "stmtblock.hpp"

#include <optional>
#include <vector>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::IndexSet
 * \brief Class for index sets
 */
class IndexSet : public ASTNode {
  public:
    IndexSet(parser::Position pos) : ASTNode(pos) {}
    virtual ~IndexSet() = default;

  protected:
    virtual IndexSet* clone() const = 0;
};

/**
 * \class qasmtools::ast::RangeSet
 * \brief Class for range index sets
 */
class RangeSet : public IndexSet {
    std::optional<ptr<Expr>> start_;
    std::optional<ptr<Expr>> step_;
    std::optional<ptr<Expr>> stop_;

  public:
    /**
     * \brief Constructs a range index set
     *
     * \param pos The source position
     * \param start Start index
     * \param step Optional step size (default = std::nullopt)
     * \param stop Stop index
     */
    RangeSet(parser::Position pos, std::optional<ptr<Expr>>&& start,
             std::optional<ptr<Expr>>&& stop)
        : IndexSet(pos), start_(std::move(start)), step_(std::nullopt),
          stop_(std::move(stop)) {}
    RangeSet(parser::Position pos, std::optional<ptr<Expr>>&& start,
             std::optional<ptr<Expr>>&& step, std::optional<ptr<Expr>>&& stop)
        : IndexSet(pos), start_(std::move(start)), step_(std::move(step)),
          stop_(std::move(stop)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<RangeSet> create(parser::Position pos,
                                std::optional<ptr<Expr>>&& start,
                                std::optional<ptr<Expr>>&& stop) {
        return std::make_unique<RangeSet>(pos, std::move(start),
                                          std::move(stop));
    }
    static ptr<RangeSet> create(parser::Position pos,
                                std::optional<ptr<Expr>>&& start,
                                std::optional<ptr<Expr>>&& step,
                                std::optional<ptr<Expr>>&& stop) {
        return std::make_unique<RangeSet>(pos, std::move(start),
                                          std::move(step), std::move(stop));
    }

    /**
     * \brief Get the start index
     *
     * return std::optional reference to start index
     */
    std::optional<ptr<Expr>>& start() { return start_; }

    /**
     * \brief Get the step size
     *
     * return std::optional reference to step size
     */
    std::optional<ptr<Expr>>& step() { return step_; }

    /**
     * \brief Get the stop index
     *
     * return std::optional reference to stop index
     */
    std::optional<ptr<Expr>>& stop() { return stop_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "[";
        if (start_)
            os << **start_;
        os << ":";
        if (step_)
            os << **step_ << ":";
        if (stop_)
            os << **stop_;
        os << "]";
        return os;
    }

  protected:
    RangeSet* clone() const override {
        std::optional<ptr<Expr>> tmp_start = std::nullopt;
        if (start_)
            tmp_start = object::clone(**start_);
        std::optional<ptr<Expr>> tmp_step = std::nullopt;
        if (step_)
            tmp_step = object::clone(**step_);
        std::optional<ptr<Expr>> tmp_stop = std::nullopt;
        if (stop_)
            tmp_stop = object::clone(**stop_);
        return new RangeSet(pos_, std::move(tmp_start), std::move(tmp_step),
                            std::move(tmp_stop));
    }
};

/**
 * \class qasmtools::ast::ListSet
 * \brief Class for list index sets
 */
class ListSet : public IndexSet {
    std::vector<ptr<Expr>> indices_;

  public:
    /**
     * \brief Construct a list index set
     *
     * \param pos The source position
     * \param indices The list of indices
     */
    ListSet(parser::Position pos, std::vector<ptr<Expr>>&& indices)
        : IndexSet(pos), indices_(std::move(indices)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ListSet> create(parser::Position pos,
                               std::vector<ptr<Expr>>&& indices) {
        return std::make_unique<ListSet>(pos, std::move(indices));
    }

    /**
     * \brief Get the list of indices
     *
     * \return Reference to the list of indices
     */
    std::vector<ptr<Expr>>& indices() { return indices_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "{";
        for (auto it = indices_.begin(); it != indices_.end(); it++)
            os << (it == indices_.begin() ? "" : ",") << **it;
        os << "}";
        return os;
    }

  protected:
    ListSet* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& x : indices_)
            tmp.emplace_back(object::clone(*x));
        return new ListSet(pos_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::VarSet
 * \brief Class for variable index sets
 */
class VarSet : public IndexSet {
    symbol var_;

  public:
    /**
     * \brief Construct a variable index set
     *
     * \param pos The source position
     * \param var The variable
     */
    VarSet(parser::Position pos, symbol var) : IndexSet(pos), var_(var) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<VarSet> create(parser::Position pos, symbol var) {
        return std::make_unique<VarSet>(pos, var);
    }

    /**
     * \brief Get the variable
     *
     * \return Const reference to the variable
     */
    const symbol& var() const { return var_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << var_;
        return os;
    }

  protected:
    VarSet* clone() const override { return new VarSet(pos_, var_); }
};

/**
 * \class qasmtools::ast::ForStmt
 * \brief Class for for-loops
 * \see qasmtools::ast::StmtBase
 */
class ForStmt final : public Stmt {
    symbol var_;              ///< the loop variable
    ptr<IndexSet> index_set_; ///< index set
    ptr<ProgramBlock> body_;  ///< loop body

  public:
    /**
     * \brief Constructs a for loop
     *
     * \param pos The source position
     * \param var The loop variable
     * \param index_set The index set
     * \param body The loop body
     */
    ForStmt(parser::Position pos, symbol var, ptr<IndexSet> index_set,
            ptr<ProgramBlock> body)
        : Stmt(pos), var_(var), index_set_(std::move(index_set)),
          body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ForStmt> create(parser::Position pos, symbol var,
                               ptr<IndexSet> index_set,
                               ptr<ProgramBlock> body) {
        return std::make_unique<ForStmt>(pos, var, std::move(index_set),
                                         std::move(body));
    }

    /**
     * \brief Return the loop variable
     *
     * \return Constant reference to the loop variable
     */
    const symbol& var() const { return var_; }

    /**
     * \brief Get the index set
     *
     * \return A reference to the index set
     */
    IndexSet& index_set() { return *index_set_; }

    /**
     * \brief Get the loop body
     *
     * \return Reference to the body
     */
    ProgramBlock& body() { return *body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "for " << var_ << " in " << *index_set_ << " ";
        body_->pretty_print(os, indents);
        return os;
    }

  protected:
    ForStmt* clone() const override {
        return new ForStmt(pos_, var_, object::clone(*index_set_),
                           object::clone(*body_));
    }
};

/**
 * \class qasmtools::ast::WhileStmt
 * \brief Class for while loops
 * \see qasmtools::ast::StmtBase
 */
class WhileStmt final : public Stmt {
    ptr<Expr> cond_;         ///< boolean expression to check
    ptr<ProgramBlock> body_; ///< loop body

  public:
    /**
     * \brief Constructs a while loop
     *
     * \param pos The source position
     * \param cond The boolean to check
     * \param body The loop body
     */
    WhileStmt(parser::Position pos, ptr<Expr> cond, ptr<ProgramBlock> body)
        : Stmt(pos), cond_(std::move(cond)), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<WhileStmt> create(parser::Position pos, ptr<Expr> cond,
                                 ptr<ProgramBlock> body) {
        return std::make_unique<WhileStmt>(pos, std::move(cond),
                                           std::move(body));
    }

    /**
     * \brief Get the boolean expression
     *
     * \return A reference to the boolean expression
     */
    Expr& cond() { return *cond_; }

    /**
     * \brief Set the boolean expression
     *
     * \param cond The new expression
     */
    void set_cond(ptr<Expr> cond) { cond_ = std::move(cond); }

    /**
     * \brief Get the loop body
     *
     * \return Reference to the body
     */
    ProgramBlock& body() { return *body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "while (" << *cond_ << ") ";
        body_->pretty_print(os, indents);
        return os;
    }

  protected:
    WhileStmt* clone() const override {
        return new WhileStmt(pos_, object::clone(*cond_),
                             object::clone(*body_));
    }
};

/**
 * \class qasmtools::ast::QuantumForStmt
 * \brief Class for quantum for-loops
 * \see qasmtools::ast::StmtBase
 */
class QuantumForStmt final : public QuantumStmt {
    symbol var_;              ///< the loop variable
    ptr<IndexSet> index_set_; ///< index set
    ptr<QuantumBlock> body_;  ///< loop body

  public:
    /**
     * \brief Constructs a quantum for loop
     *
     * \param pos The source position
     * \param var The loop variable
     * \param index_set The index set
     * \param body The loop body
     */
    QuantumForStmt(parser::Position pos, symbol var, ptr<IndexSet> index_set,
                   ptr<QuantumBlock> body)
        : QuantumStmt(pos), var_(var), index_set_(std::move(index_set)),
          body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<QuantumForStmt> create(parser::Position pos, symbol var,
                                      ptr<IndexSet> index_set,
                                      ptr<QuantumBlock> body) {
        return std::make_unique<QuantumForStmt>(pos, var, std::move(index_set),
                                                std::move(body));
    }

    /**
     * \brief Return the loop variable
     *
     * \return Constant reference to the loop variable
     */
    const symbol& var() const { return var_; }

    /**
     * \brief Get the index set
     *
     * \return A reference to the index set
     */
    IndexSet& index_set() { return *index_set_; }

    /**
     * \brief Get the loop body
     *
     * \return Reference to the body
     */
    QuantumBlock& body() { return *body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "for " << var_ << " in " << *index_set_ << " ";
        body_->pretty_print(os, indents);
        return os;
    }

  protected:
    QuantumForStmt* clone() const override {
        return new QuantumForStmt(pos_, var_, object::clone(*index_set_),
                                  object::clone(*body_));
    }
};

/**
 * \class qasmtools::ast::QuantumWhileStmt
 * \brief Class for quantum while loops
 * \see qasmtools::ast::StmtBase
 */
class QuantumWhileStmt final : public QuantumStmt {
    ptr<Expr> cond_;         ///< boolean expression to check
    ptr<QuantumBlock> body_; ///< loop body

  public:
    /**
     * \brief Constructs a quantum while loop
     *
     * \param pos The source position
     * \param cond The boolean to check
     * \param body The loop body
     */
    QuantumWhileStmt(parser::Position pos, ptr<Expr> cond,
                     ptr<QuantumBlock> body)
        : QuantumStmt(pos), cond_(std::move(cond)), body_(std::move(body)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<QuantumWhileStmt> create(parser::Position pos, ptr<Expr> cond,
                                        ptr<QuantumBlock> body) {
        return std::make_unique<QuantumWhileStmt>(pos, std::move(cond),
                                                  std::move(body));
    }

    /**
     * \brief Get the boolean expression
     *
     * \return A reference to the boolean expression
     */
    Expr& cond() { return *cond_; }

    /**
     * \brief Set the boolean expression
     *
     * \param cond The new expression
     */
    void set_cond(ptr<Expr> cond) { cond_ = std::move(cond); }

    /**
     * \brief Get the loop body
     *
     * \return Reference to the body
     */
    QuantumBlock& body() { return *body_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool,
                               size_t indents) const override {
        os << "while (" << *cond_ << ") ";
        body_->pretty_print(os, indents);
        return os;
    }

  protected:
    QuantumWhileStmt* clone() const override {
        return new QuantumWhileStmt(pos_, object::clone(*cond_),
                                    object::clone(*body_));
    }
};

} // namespace ast
} // namespace qasmtools
