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
 * \file qasmtools/ast/indexid.hpp
 * \brief openQASM index identifiers
 */

#pragma once

#include "base.hpp"
#include "exprbase.hpp"

#include <optional>
#include <vector>

namespace qasmtools {
namespace ast {

/**
 * \class qasmtools::ast::Slice
 * \brief Class for register slices
 */
class Slice : public ASTNode {
  public:
    Slice(parser::Position pos) : ASTNode(pos) {}
    virtual ~Slice() = default;
  protected:
    virtual Slice* clone() const = 0;
};

/**
 * \class qasmtools::ast::RangeSlice
 * \brief Class for range slices
 */
class RangeSlice : public Slice {
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
    RangeSlice(parser::Position pos, std::optional<ptr<Expr>>&& start,
               std::optional<ptr<Expr>>&& stop)
        : Slice(pos), start_(std::move(start)), step_(std::nullopt),
          stop_(std::move(stop)) {}
    RangeSlice(parser::Position pos, std::optional<ptr<Expr>>&& start,
               std::optional<ptr<Expr>>&& step, std::optional<ptr<Expr>>&& stop)
        : Slice(pos), start_(std::move(start)), step_(std::move(step)),
          stop_(std::move(stop)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<RangeSlice> create(parser::Position pos,
                                  std::optional<ptr<Expr>>&& start,
                                  std::optional<ptr<Expr>>&& stop) {
        return std::make_unique<RangeSlice>(pos, std::move(start),
                                            std::move(stop));
    }
    static ptr<RangeSlice> create(parser::Position pos,
                                  std::optional<ptr<Expr>>&& start,
                                  std::optional<ptr<Expr>>&& step,
                                  std::optional<ptr<Expr>>&& stop) {
        return std::make_unique<RangeSlice>(pos, std::move(start),
                                            std::move(step),
                                            std::move(stop));
    }

    /**
     * \brief Get the start index
     *
     * return const std::optional reference to start index
     */
    const std::optional<ptr<Expr>>& start() const { return start_; }

    /**
     * \brief Get the step size
     *
     * return const std::optional reference to step size
     */
    const std::optional<ptr<Expr>>& step() const { return step_; }

    /**
     * \brief Get the stop index
     *
     * return const std::optional reference to stop index
     */
    const std::optional<ptr<Expr>>& stop() const { return stop_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "[";
        if (start_)
            os << *start_;
        os << ":";
        if (step_)
            os << *step_ << ":";
        if (stop_)
            os << *stop_;
        os << "]";
        return os;
    }
  protected:
    RangeSlice* clone() const override {
        std::optional<ptr<Expr>> tmp_start = std::nullopt;
        if (start_)
            tmp_start = object::clone(**start_);
        std::optional<ptr<Expr>> tmp_step = std::nullopt;
        if (step_)
            tmp_step = object::clone(**step_);
        std::optional<ptr<Expr>> tmp_stop = std::nullopt;
        if (stop_)
            tmp_stop = object::clone(**stop_);
        return new RangeSlice(pos_, std::move(tmp_start), std::move(tmp_step),
                              std::move(tmp_stop));
    }
};

/**
 * \class qasmtools::ast::ListSlice
 * \brief Class for list slices
 */
class ListSlice : public Slice {
    std::vector<ptr<Expr>> indices_;
  public:
    /**
     * \brief Construct a list slice
     *
     * \param pos The source position
     * \param indices The list of indices
     */
    ListSlice(parser::Position pos, std::vector<ptr<Expr>>&& indices)
        : Slice(pos), indices_(std::move(indices)) {}

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

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "[";
        for (auto it = indices_.begin(); it != indices_.end(); it++)
            os << (it == indices_.begin() ? "" : ",") << **it;
        os << "]";
        return os;
    }
  protected:
    ListSlice* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& x: indices_)
            tmp.emplace_back(object::clone(*x));
        return new ListSlice(pos_, std::move(tmp));
    }
};



/**
 * \class qasmtools::ast::IndexId
 * \brief Class for index identifiers
 */
class IndexId : public ASTNode {
  public:
    IndexId(parser::Position pos) : ASTNode(pos) {}
    virtual ~IndexId() = default;
  protected:
    virtual IndexId* clone() const = 0;
};

/**
 * \class qasmtools::ast::VarAccess
 * \brief Class for variable accesses
 * \see qasmtools::ast::IndexId
 *
 * Represents accesses into a register by the register name and an optional
 * range or list slicing.
 */
class VarAccess final : public IndexId {
    symbol var_;                      ///< the identifier
    std::optional<ptr<Slice>> slice_; ///< optional register slice

  public:

    /**
     * \brief Construct a variable access
     *
     * \param pos The source position
     * \param var The register name
     * \param offset Optional register slice (default = std::nullopt)
     */
    VarAccess(parser::Position pos, symbol var,
              std::optional<ptr<Slice>>&& slice = std::nullopt)
        : IndexId(pos), var_(var), slice_(std::move(slice)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<VarAccess> create(parser::Position pos, symbol var,
                             std::optional<ptr<Slice>>&& slice = std::nullopt) {
        return std::make_unique<VarAccess>(pos, var, std::move(slice));
    }

    /**
     * \brief Get the register name
     *
     * return Const reference to the register name
     */
    const symbol& var() const { return var_; }

    /**
     * \brief Get the slice
     *
     * return const std::optional reference to slice
     */
    const std::optional<ptr<Slice>>& slice() const { return slice_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << var_;
        if (slice_)
            os << *slice_;
        return os;
    }
  protected:
    VarAccess* clone() const override {
        std::optional<ptr<Slice>> tmp = std::nullopt;
        if (slice_)
            tmp = object::clone(**slice_);
        return new VarAccess(pos_, var_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::Concat
 * \brief Class for register concatenation
 * \see qasmtools::ast::IndexId
 */
class Concat final : public IndexId {
    ptr<IndexId> lreg_; ///< the left sub-register
    ptr<IndexId> rreg_; ///< the right sub-register

  public:
    /**
     * \brief Constructs a register concatenation
     *
     * \param pos The source position
     * \param lreg The left sub-register
     * \param rreg The right sub-register
     */
    Concat(parser::Position pos, ptr<IndexId> lreg, ptr<IndexId> rreg)
        : IndexId(pos), lreg_(std::move(lreg)), rreg_(std::move(rreg)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<Concat> create(parser::Position pos, ptr<IndexId> lreg,
                              ptr<IndexId> rreg) {
        return std::make_unique<Concat>(pos, std::move(lreg), std::move(rreg));
    }

    /**
     * \brief Get the left sub-register
     *
     * \return A reference to the left sub-register
     */
    IndexId& lreg() { return *lreg_; }

    /**
     * \brief Get the right sub-register
     *
     * \return A reference to the right sub-register
     */
    IndexId& rreg() { return *rreg_; }

    /**
     * \brief Set the left sub-register
     *
     * \param exp The new left sub-register
     */
    void set_lreg(ptr<IndexId> reg) { lreg_ = std::move(reg); }

    /**
     * \brief Set the right sub-register
     *
     * \param exp The new right sub-register
     */
    void set_rreg(ptr<IndexId> reg) { rreg_ = std::move(reg); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << *lreg_ << "||" << *rreg_;
        return os;
    }
  protected:
    Concat* clone() const override {
        return new Concat(pos_, object::clone(*lreg_), object::clone(*rreg_));
    }
};

} // namespace ast
} // namespace qasmtools
