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
 * @file qasm3tools/ast/type.hpp
 * @brief OpenQASM data types
 */

#ifndef QASM3TOOLS_AST_TYPE_HPP_
#define QASM3TOOLS_AST_TYPE_HPP_

#include <optional>
#include <variant>
#include <vector>

#include "base.hpp"
#include "exprbase.hpp"

namespace qasm3tools {
namespace ast {

/**
 * @class qasm3tools::ast::Type
 * @brief Class for types
 */
class Type : public ASTNode {
  public:
    Type(parser::Position pos) : ASTNode(pos) {}
    virtual ~Type() = default;

  protected:
    virtual Type* clone() const = 0;
};

/**
 * @brief Enum of single-designator types
 */
enum class SDType { Bit, Int, Uint, Float, Angle };
inline std::ostream& operator<<(std::ostream& os, const SDType& t) {
    switch (t) {
        case SDType::Bit:
            os << "bit";
            break;
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
 * @brief Enum of no-designator types
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
 * @class qasm3tools::ast::ClassicalType
 * @brief Class for classical types
 */
class ClassicalType : public Type {
  public:
    ClassicalType(parser::Position pos) : Type(pos) {}
    virtual ~ClassicalType() = default;

  protected:
    virtual ClassicalType* clone() const = 0;
};

/**
 * @class qasm3tools::ast::NonArrayType
 * @brief Class for non-array classical types
 */
class NonArrayType : public ClassicalType {
  public:
    NonArrayType(parser::Position pos) : ClassicalType(pos) {}
    virtual ~NonArrayType() = default;

  protected:
    virtual NonArrayType* clone() const = 0;
};

/**
 * @class qasm3tools::ast::SingleDesignatorType
 * @brief Type sub-class for single-designator types
 */
class SingleDesignatorType : public NonArrayType {
    SDType type_;
    std::optional<ptr<Expr>> size_;

  public:
    /**
     * @brief Constructs a single-designator type
     *
     * @param pos The source position
     * @param type The type name
     * @param size The size
     */
    SingleDesignatorType(parser::Position pos, SDType type,
                         std::optional<ptr<Expr>>&& size = std::nullopt)
        : NonArrayType(pos), type_(type), size_(std::move(size)) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<SingleDesignatorType>
    create(parser::Position pos, SDType type,
           std::optional<ptr<Expr>>&& size = std::nullopt) {
        return std::make_unique<SingleDesignatorType>(pos, type,
                                                      std::move(size));
    }

    /**
     * @brief Get the type name
     *
     * @return A single-designator type enum
     */
    SDType type() { return type_; }

    /**
     * @brief Get the size
     *
     * @return Optional expr size
     */
    std::optional<ptr<Expr>>& size() { return size_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << type_;
        if (size_) {
            os << "[" << **size_ << "]";
        }
        return os;
    }

  protected:
    SingleDesignatorType* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (size_) {
            tmp = object::clone(**size_);
        }
        return new SingleDesignatorType(pos_, type_, std::move(tmp));
    }
};

/**
 * @class qasm3tools::ast::NoDesignatorType
 * @brief Type sub-class for no-designator types
 */
class NoDesignatorType : public NonArrayType {
    NDType type_;

  public:
    /**
     * @brief Constructs a no-designator type
     *
     * @param pos The source position
     * @param type The type name
     */
    NoDesignatorType(parser::Position pos, NDType type)
        : NonArrayType(pos), type_(type) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<NoDesignatorType> create(parser::Position pos, NDType type) {
        return std::make_unique<NoDesignatorType>(pos, type);
    }

    /**
     * @brief Get the type name
     *
     * @return A single-designator type enum
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
 * @class qasm3tools::ast::ComplexType
 * @brief Type sub-class for complex types
 */
class ComplexType : public NonArrayType {
    std::optional<ptr<NonArrayType>> subtype_;

  public:
    /**
     * @brief Constructs a bit type
     *
     * @param pos The source position
     * @param subtype The subtype
     */
    ComplexType(parser::Position pos,
                std::optional<ptr<NonArrayType>> subtype = std::nullopt)
        : NonArrayType(pos), subtype_(std::move(subtype)) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<ComplexType>
    create(parser::Position pos,
           std::optional<ptr<NonArrayType>> subtype = std::nullopt) {
        return std::make_unique<ComplexType>(pos, std::move(subtype));
    }

    /**
     * @brief Get the subtype
     *
     * @return Reference to the subtype
     */
    std::optional<ptr<NonArrayType>>& subtype() { return subtype_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "complex";
        if (subtype_) {
            os << "[" << **subtype_ << "]";
        }
        return os;
    }

  protected:
    ComplexType* clone() const override {
        std::optional<ptr<NonArrayType>> tmp = std::nullopt;
        if (subtype_) {
            tmp = object::clone(**subtype_);
        }
        return new ComplexType(pos_, std::move(tmp));
    }
};

/**
 * @class qasm3tools::ast::ArrayType
 * @brief Class for classical array types
 */
class ArrayType : public ClassicalType {
    ptr<NonArrayType> subtype_;   ///< non-array subtype
    std::vector<ptr<Expr>> dims_; ///< dimension specification

  public:
    /**
     * @brief Construct a classical array types
     *
     * @param pos The source position
     * @param subtype The non-array subtype
     * @param dims The dimension specification
     */
    ArrayType(parser::Position pos, ptr<NonArrayType> subtype,
              std::vector<ptr<Expr>>&& dims)
        : ClassicalType(pos), subtype_(std::move(subtype)),
          dims_(std::move(dims)) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<ArrayType> create(parser::Position pos,
                                 ptr<NonArrayType> subtype,
                                 std::vector<ptr<Expr>>&& dims) {
        return std::make_unique<ArrayType>(pos, std::move(subtype),
                                           std::move(dims));
    }

    /**
     * @brief Get the subtype
     *
     * @return Reference to the non-array subtype
     */
    NonArrayType& subtype() { return *subtype_; }

    /**
     * @brief Get the number of dimensions
     *
     * @return The number of dimensions
     */
    int dims() const { return static_cast<int>(dims_.size()); }

    /**
     * @brief Get the ith dimension size
     *
     * @param i The number of the dimension, 0-indexed
     * @return Reference to an expression
     */
    Expr& dim(int i) { return *(dims_[i]); }

    /**
     * @brief Set the ith dimension size
     *
     * @param i The number of the dimension, 0-indexed
     * @param expr An expression giving the new dimension size
     */
    void set_dim(int i, ptr<Expr> expr) { dims_[i] = std::move(expr); }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "array[" << *subtype_;
        for (auto& dim : dims_) {
            os << ", " << *dim;
        }
        os << "]";
        return os;
    }

  protected:
    ArrayType* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& dim : dims_) {
            tmp.emplace_back(object::clone(*dim));
        }
        return new ArrayType(pos_, object::clone(*subtype_), std::move(tmp));
    }
};

/**
 * @class qasm3tools::ast::ArrayRefType
 * @brief Class for array reference types
 */
class ArrayRefType : public ClassicalType {
    ptr<NonArrayType> subtype_; ///< non-array subtype
    /* vector = list of the dimensions of the array
     * Expr = we only know the number of dimensions, not the sizes
     */
    using Dimensions = std::variant<std::vector<ptr<Expr>>, ptr<Expr>>;
    Dimensions dims_; ///< dimension specification
    bool is_mutable_; ///< Whether the array reference is mutable

  public:
    /**
     * @brief Construct an array reference types
     *
     * @param pos The source position
     * @param subtype The non-array subtype
     * @param dims The dimension specification
     * @param is_mutable Whether the array reference is mutable
     */
    ArrayRefType(parser::Position pos, ptr<NonArrayType> subtype,
                 Dimensions&& dims, bool is_mutable = false)
        : ClassicalType(pos), subtype_(std::move(subtype)),
          dims_(std::move(dims)), is_mutable_(is_mutable) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<ArrayRefType> create(parser::Position pos,
                                    ptr<NonArrayType> subtype,
                                    Dimensions&& dims,
                                    bool is_mutable = false) {
        return std::make_unique<ArrayRefType>(pos, std::move(subtype),
                                              std::move(dims), is_mutable);
    }

    /**
     * @brief Get the subtype
     *
     * @return Reference to the non-array subtype
     */
    NonArrayType& subtype() { return *subtype_; }

    /**
     * @brief Get the dimension specification
     *
     * @return Reference to the dimension specification
     */
    Dimensions& dims() { return dims_; }

    bool is_mutable() const { return is_mutable_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << (is_mutable_ ? "mutable" : "readonly") << " array[" << *subtype_;
        std::visit(utils::overloaded{[&os](const std::vector<ptr<Expr>>& dims) {
                                         for (auto& dim : dims) {
                                             os << ", " << *dim;
                                         }
                                     },
                                     [&os](const ptr<Expr>& dims) {
                                         os << ", #dim = " << *dims;
                                     }},
                   dims_);
        os << "]";
        return os;
    }

  protected:
    ArrayRefType* clone() const override {
        Dimensions dims_copy = std::vector<ptr<Expr>>();
        std::visit(utils::overloaded{
                       [&dims_copy](const std::vector<ptr<Expr>>& dims) {
                           for (auto& dim : dims) {
                               std::get<std::vector<ptr<Expr>>>(dims_copy)
                                   .emplace_back(object::clone(*dim));
                           }
                       },
                       [&dims_copy](const ptr<Expr>& dims) {
                           dims_copy = object::clone(*dims);
                       }},
                   dims_);
        return new ArrayRefType(pos_, object::clone(*subtype_),
                                std::move(dims_copy), is_mutable_);
    }
};

/**
 * @class qasm3tools::ast::QuantumType
 * @brief Class for quantum types
 */
class QuantumType : public Type {
  public:
    QuantumType(parser::Position pos) : Type(pos) {}
    virtual ~QuantumType() = default;

  protected:
    virtual QuantumType* clone() const = 0;
};

/**
 * @class qasm3tools::ast::QubitType
 * @brief Type sub-class for qubit types
 */
class QubitType : public QuantumType {
    std::optional<ptr<Expr>> size_;

  public:
    /**
     * @brief Constructs a qubit type
     *
     * @param pos The source position
     * @param size The size
     */
    QubitType(parser::Position pos,
              std::optional<ptr<Expr>>&& size = std::nullopt)
        : QuantumType(pos), size_(std::move(size)) {}

    /**
     * @brief Protected heap-allocated construction
     */
    static ptr<QubitType>
    create(parser::Position pos,
           std::optional<ptr<Expr>>&& size = std::nullopt) {
        return std::make_unique<QubitType>(pos, std::move(size));
    }

    /**
     * @brief Get the size
     *
     * @return Optional expr size
     */
    std::optional<ptr<Expr>>& size() { return size_; }

    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os) const override {
        os << "qubit";
        if (size_) {
            os << "[" << **size_ << "]";
        }
        return os;
    }

  protected:
    QubitType* clone() const override {
        std::optional<ptr<Expr>> tmp = std::nullopt;
        if (size_) {
            tmp = object::clone(**size_);
        }
        return new QubitType(pos_, std::move(tmp));
    }
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_TYPE_HPP_ */
