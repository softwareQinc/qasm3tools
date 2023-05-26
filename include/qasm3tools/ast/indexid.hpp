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
 * \file qasm3tools/ast/indexid.hpp
 * \brief OpenQASM indexed identifiers
 */

#ifndef QASM3TOOLS_AST_INDEXID_HPP_
#define QASM3TOOLS_AST_INDEXID_HPP_

#include <optional>
#include <vector>

#include "base.hpp"
#include "exprbase.hpp"

namespace qasm3tools {
namespace ast {

/**
 * \class qasm3tools::ast::IndexOp
 * \brief Class for index operators
 */
class IndexOp : public ASTNode {
  public:
    IndexOp(parser::Position pos) : ASTNode(pos) {}
    virtual ~IndexOp() = default;

    /**
     * \brief Get the number of single indices (i.e. non-slices) in the access
     *
     * return The number of single indices
     */
    virtual int num_single_indices() const = 0;

    /**
     * \brief Get the number of index entities in the access
     *
     * return The number of index entities
     */
    virtual int num_index_entities() const = 0;

  protected:
    virtual IndexOp* clone() const = 0;
};

/**
 * \class qasm3tools::ast::IndexEntity
 * \brief Class for index entities
 */
class IndexEntity : public ASTNode {
  public:
    IndexEntity(parser::Position pos) : ASTNode(pos) {}
    virtual ~IndexEntity() = default;

    /**
     * \brief Get whether the index entity is a single index
     *
     * return Whether the index entity is a single index
     */
    virtual bool is_single_index() const = 0;

  protected:
    virtual IndexEntity* clone() const = 0;
};

/**
 * \class qasm3tools::ast::SingleIndex
 * \brief Class for single indices
 */
class SingleIndex : public IndexEntity {
    ptr<Expr> index_; ///< the index

  public:
    /**
     * \brief Constructs a single index
     *
     * \param pos The source position
     * \param index The index
     */
    SingleIndex(parser::Position pos, ptr<Expr> index)
        : IndexEntity(pos), index_(std::move(index)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<SingleIndex> create(parser::Position pos, ptr<Expr> index) {
        return std::make_unique<SingleIndex>(pos, std::move(index));
    }

    /**
     * \brief Get the index
     *
     * \return A reference to the index
     */
    Expr& index() { return *index_; }

    /**
     * \brief Set the index
     *
     * \param index The new index
     */
    void set_index(ptr<Expr> index) { index_ = std::move(index); }

    bool is_single_index() const override { return true; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << *index_;
        return os;
    }

  protected:
    SingleIndex* clone() const override {
        return new SingleIndex(pos_, object::clone(*index_));
    }
};

/**
 * \class qasm3tools::ast::RangeIndex
 * \brief Class for range slices
 */
class RangeIndex : public IndexEntity {
    std::optional<ptr<Expr>> start_; ///< the start index
    std::optional<ptr<Expr>> step_;  ///< the step size
    std::optional<ptr<Expr>> stop_;  ///< the stop index
  public:
    /**
     * \brief Constructs a range slice
     *
     * \param pos The source position
     * \param start Start index
     * \param step Optional step size (default = std::nullopt)
     * \param stop Stop index
     */
    RangeIndex(parser::Position pos, std::optional<ptr<Expr>>&& start,
               std::optional<ptr<Expr>>&& stop)
        : IndexEntity(pos), start_(std::move(start)), step_(std::nullopt),
          stop_(std::move(stop)) {}
    RangeIndex(parser::Position pos, std::optional<ptr<Expr>>&& start,
               std::optional<ptr<Expr>>&& step, std::optional<ptr<Expr>>&& stop)
        : IndexEntity(pos), start_(std::move(start)), step_(std::move(step)),
          stop_(std::move(stop)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<RangeIndex> create(parser::Position pos,
                                  std::optional<ptr<Expr>>&& start,
                                  std::optional<ptr<Expr>>&& stop) {
        return std::make_unique<RangeIndex>(pos, std::move(start),
                                            std::move(stop));
    }
    static ptr<RangeIndex> create(parser::Position pos,
                                  std::optional<ptr<Expr>>&& start,
                                  std::optional<ptr<Expr>>&& step,
                                  std::optional<ptr<Expr>>&& stop) {
        return std::make_unique<RangeIndex>(pos, std::move(start),
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

    bool is_single_index() const override { return false; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        if (start_)
            os << **start_;
        os << ":";
        if (step_)
            os << **step_ << ":";
        if (stop_)
            os << **stop_;
        return os;
    }

  protected:
    RangeIndex* clone() const override {
        std::optional<ptr<Expr>> tmp_start = std::nullopt;
        if (start_)
            tmp_start = object::clone(**start_);
        std::optional<ptr<Expr>> tmp_step = std::nullopt;
        if (step_)
            tmp_step = object::clone(**step_);
        std::optional<ptr<Expr>> tmp_stop = std::nullopt;
        if (stop_)
            tmp_stop = object::clone(**stop_);
        return new RangeIndex(pos_, std::move(tmp_start), std::move(tmp_step),
                              std::move(tmp_stop));
    }
};

/**
 * \class qasm3tools::ast::IndexEntityList
 * \brief Class for index entity lists
 */
class IndexEntityList : public IndexOp {
    std::vector<ptr<IndexEntity>> indices_; ///< list of index entities

  public:
    /**
     * \brief Construct an index entity list
     *
     * \param pos The source position
     * \param indices The list of index entities
     */
    IndexEntityList(parser::Position pos,
                    std::vector<ptr<IndexEntity>>&& indices)
        : IndexOp(pos), indices_(std::move(indices)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<IndexEntityList>
    create(parser::Position pos, std::vector<ptr<IndexEntity>>&& indices) {
        return std::make_unique<IndexEntityList>(pos, std::move(indices));
    }

    /**
     * \brief Get the list of index entities
     *
     * \return Reference to the list of index entities
     */
    std::vector<ptr<IndexEntity>>& indices() { return indices_; }

    int num_single_indices() const override {
        int ans = 0;
        for (auto& index : indices_) {
            if (index->is_single_index())
                ++ans;
        }
        return ans;
    }
    int num_index_entities() const override { return indices_.size(); }

    /**
     * \brief Apply a function to each index entity
     *
     * \param f Void function accepting a reference to the index entity
     */
    void foreach_index(std::function<void(IndexEntity&)> f) {
        for (auto& x : indices_)
            f(*x);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "[";
        for (auto it = indices_.begin(); it != indices_.end(); it++)
            os << (it == indices_.begin() ? "" : ", ") << **it;
        os << "]";
        return os;
    }

  protected:
    IndexEntityList* clone() const override {
        std::vector<ptr<IndexEntity>> tmp;
        for (auto& x : indices_)
            tmp.emplace_back(object::clone(*x));
        return new IndexEntityList(pos_, std::move(tmp));
    }
};

/**
 * \class qasm3tools::ast::ListSlice
 * \brief Class for list slices
 */
class ListSlice : public IndexOp {
    std::vector<ptr<Expr>> indices_;

  public:
    /**
     * \brief Construct a list slice
     *
     * \param pos The source position
     * \param indices The list of indices
     */
    ListSlice(parser::Position pos, std::vector<ptr<Expr>>&& indices)
        : IndexOp(pos), indices_(std::move(indices)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ListSlice> create(parser::Position pos,
                                 std::vector<ptr<Expr>>&& indices) {
        return std::make_unique<ListSlice>(pos, std::move(indices));
    }

    /**
     * \brief Get the list of indices
     *
     * \return Reference to the list of indices
     */
    std::vector<ptr<Expr>>& indices() { return indices_; }

    int num_single_indices() const override { return 0; }
    int num_index_entities() const override { return 1; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "[{";
        for (auto it = indices_.begin(); it != indices_.end(); it++)
            os << (it == indices_.begin() ? "" : ", ") << **it;
        os << "}]";
        return os;
    }

  protected:
    ListSlice* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& x : indices_)
            tmp.emplace_back(object::clone(*x));
        return new ListSlice(pos_, std::move(tmp));
    }
};

/**
 * \class qasm3tools::ast::IndexId
 * \brief Class for indexed identifiers
 *
 * Represents accesses into a register or array.
 */
class IndexId final : public ASTNode {
    symbol var_;                          ///< the identifier
    std::vector<ptr<IndexOp>> index_ops_; ///< sequence of index operators

  public:
    /**
     * \brief Construct an indexed identifiers
     *
     * \param pos The source position
     * \param var The register name
     * \param index_ops The sequence of index operators
     */
    IndexId(parser::Position pos, symbol var,
            std::vector<ptr<IndexOp>>&& index_ops)
        : ASTNode(pos), var_(var), index_ops_(std::move(index_ops)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<IndexId> create(parser::Position pos, symbol var,
                               std::vector<ptr<IndexOp>>&& index_ops) {
        return std::make_unique<IndexId>(pos, var, std::move(index_ops));
    }

    /**
     * \brief Get the register name
     *
     * return Const reference to the register name
     */
    const symbol& var() const { return var_; }

    /**
     * \brief Get the number of index operators
     *
     * \return The number of index operators
     */
    int num_index_ops() const { return static_cast<int>(index_ops_.size()); }

    /**
     * \brief Get the list of index operators
     *
     * \return Reference to the list of index operators
     */
    std::vector<ptr<IndexOp>>& index_ops() { return index_ops_; }

    /**
     * \brief Apply a function to each index operator
     *
     * \param f Void function accepting a reference to the argument
     */
    void foreach_index_op(std::function<void(IndexOp&)> f) {
        for (auto& x : index_ops_)
            f(*x);
    }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << var_;
        for (auto& x : index_ops_)
            os << *x;
        return os;
    }

  protected:
    IndexId* clone() const override {
        std::vector<ptr<IndexOp>> tmp;
        for (auto& x : index_ops_)
            tmp.emplace_back(object::clone(*x));
        return new IndexId(pos_, var_, std::move(tmp));
    }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_INDEXID_HPP_ */
