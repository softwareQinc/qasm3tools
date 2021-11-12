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
 * \file qasmtools/ast/type.hpp
 * \brief OpenQASM classical types
 */

#pragma once

#include "base.hpp"
#include "exprbase.hpp"

#include <optional>

namespace qasmtools {
namespace ast {

/**
 * \brief Enum of single-designator types
 */
enum class SDType { Int, Uint, Float, Angle };
inline std::ostream& operator<<(std::ostream& os, const SDType& t) {
    switch (t) {
        case SDType::Int:
            os << "int";
            break;
        case SDType::Uint:
            os << "uint";
            break;
        case SDType::Float:
            os << "float";
            break;
        case SDType::Angle:
            os << "angle";
            break;
    }
    return os;
}

/**
 * \brief Enum of no-designator types
 */
enum class NDType { Bool, Duration, Stretch };
inline std::ostream& operator<<(std::ostream& os, const NDType& t) {
    switch (t) {
        case NDType::Bool:
            os << "bool";
            break;
        case NDType::Duration:
            os << "duration";
            break;
        case NDType::Stretch:
            os << "stretch";
            break;
    }
    return os;
}

/**
 * \class qasmtools::ast::ClassicalType
 * \brief Class for classical types
 */
class ClassicalType : public ASTNode {
  public:
    ClassicalType(parser::Position pos) : ASTNode(pos) {}
    virtual ~ClassicalType() = default;

  protected:
    virtual ClassicalType* clone() const = 0;
};

/**
 * \class qasmtools::ast::SingleDesignatorType
 * \brief Type sub-class for single-designator types
 */
class SingleDesignatorType : public ClassicalType {
    SDType type_;
    ptr<Expr> size_;

  public:
    /**
     * \brief Constructs a single-designator type
     *
     * \param pos The source position
     * \param type The type name
     * \param size The size
     */
    SingleDesignatorType(parser::Position pos, SDType type, ptr<Expr> size)
        : ClassicalType(pos), type_(type), size_(std::move(size)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<SingleDesignatorType> create(parser::Position pos, SDType type,
                                            ptr<Expr> size) {
        return std::make_unique<SingleDesignatorType>(pos, type,
                                                      std::move(size));
    }

    /**
     * \brief Get the type name
     *
     * \return A single-designator type enum
     */
    SDType type() { return type_; }

    /**
     * \brief Get the size
     *
     * \return Reference to Expr size
     */
    Expr& size() { return *size_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << type_ << "[" << *size_ << "]";
        return os;
    }

  protected:
    SingleDesignatorType* clone() const override {
        return new SingleDesignatorType(pos_, type_, object::clone(*size_));
    }
};

/**
 * \class qasmtools::ast::NoDesignatorType
 * \brief Type sub-class for no-designator types
 */
class NoDesignatorType : public ClassicalType {
    NDType type_;

  public:
    /**
     * \brief Constructs a no-designator type
     *
     * \param pos The source position
     * \param type The type name
     */
    NoDesignatorType(parser::Position pos, NDType type)
        : ClassicalType(pos), type_(type) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<NoDesignatorType> create(parser::Position pos, NDType type) {
        return std::make_unique<NoDesignatorType>(pos, type);
    }

    /**
     * \brief Get the type name
     *
     * \return A single-designator type enum
     */
    NDType type() { return type_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << type_;
        return os;
    }

  protected:
    NoDesignatorType* clone() const override {
        return new NoDesignatorType(pos_, type_);
    }
};

/**
 * \class qasmtools::ast::BitType
 * \brief Type sub-class for bit types
 */
class BitType : public ClassicalType {
    std::optional<ptr<Expr>> size_;

  public:
    /**
     * \brief Constructs a bit type
     *
     * \param pos The source position
     * \param size The size
     */
    BitType(parser::Position pos,
            std::optional<ptr<Expr>>&& size = std::nullopt)
        : ClassicalType(pos), size_(std::move(size)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BitType> create(parser::Position pos,
                               std::optional<ptr<Expr>>&& size = std::nullopt) {
        return std::make_unique<BitType>(pos, std::move(size));
    }

    /**
     * \brief Get the size
     *
     * \return Optional expr size
     */
    std::optional<ptr<Expr>>& size() { return size_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "bit";
        if (size_)
            os << "[" << **size_ << "]";
        return os;
    }

  protected:
    BitType* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (size_)
            tmp = object::clone(**size_);
        return new BitType(pos_, std::move(tmp));
    }
};

/**
 * \class qasmtools::ast::ComplexType
 * \brief Type sub-class for complex types
 */
class ComplexType : public ClassicalType {
    ptr<SingleDesignatorType> subtype_;

  public:
    /**
     * \brief Constructs a bit type
     *
     * \param pos The source position
     * \param subtype The single-designator subtype
     */
    ComplexType(parser::Position pos, ptr<SingleDesignatorType> subtype)
        : ClassicalType(pos), subtype_(std::move(subtype)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ComplexType> create(parser::Position pos,
                                   ptr<SingleDesignatorType> subtype) {
        return std::make_unique<ComplexType>(pos, std::move(subtype));
    }

    /**
     * \brief Get the subtype
     *
     * \return Reference to the single-designator subtype
     */
    SingleDesignatorType& subtype() { return *subtype_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "complex[" << *subtype_ << "]";
        return os;
    }

  protected:
    ComplexType* clone() const override {
        return new ComplexType(pos_, object::clone(*subtype_));
    }
};

} // namespace ast
} // namespace qasmtools
