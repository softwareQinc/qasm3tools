/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2022 softwareQ Inc. All rights reserved.
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
 * \file qasm3tools/ast/expr.hpp
 * \brief OpenQASM expressions
 */

#pragma once

#include "../utils/angle.hpp"
#include "base.hpp"
#include "exprbase.hpp"
#include "type.hpp"

#include <cmath>
#include <iomanip>
#include <vector>

namespace qasm3tools {
namespace ast {

/**
 * \brief Enum of constants
 */
enum class Constant { Pi, Tau, Euler };
inline std::ostream& operator<<(std::ostream& os, const Constant& c) {
    switch (c) {
        case Constant::Pi:
            os << "π";
            break;
        case Constant::Tau:
            os << "τ";
            break;
        case Constant::Euler:
            os << "ℇ";
            break;
    }
    return os;
}

/**
 * \brief Enum of binary operators
 */
enum class BinaryOp {
    LogicalOr,
    LogicalAnd,
    BitOr,
    XOr,
    BitAnd,
    EQ,
    NEQ,
    GT,
    LT,
    GTE,
    LTE,
    LeftBitShift,
    RightBitShift,
    Plus,
    Minus,
    Times,
    Divide,
    Mod,
    Pow
};
inline std::ostream& operator<<(std::ostream& os, const BinaryOp& bop) {
    switch (bop) {
        case BinaryOp::LogicalOr:
            os << "||";
            break;
        case BinaryOp::LogicalAnd:
            os << "&&";
            break;
        case BinaryOp::BitOr:
            os << "|";
            break;
        case BinaryOp::XOr:
            os << "^";
            break;
        case BinaryOp::BitAnd:
            os << "&";
            break;
        case BinaryOp::EQ:
            os << "==";
            break;
        case BinaryOp::NEQ:
            os << "!=";
            break;
        case BinaryOp::GT:
            os << ">";
            break;
        case BinaryOp::LT:
            os << "<";
            break;
        case BinaryOp::GTE:
            os << ">=";
            break;
        case BinaryOp::LTE:
            os << "<=";
            break;
        case BinaryOp::LeftBitShift:
            os << "<<";
            break;
        case BinaryOp::RightBitShift:
            os << ">>";
            break;
        case BinaryOp::Plus:
            os << "+";
            break;
        case BinaryOp::Minus:
            os << "-";
            break;
        case BinaryOp::Times:
            os << "*";
            break;
        case BinaryOp::Divide:
            os << "/";
            break;
        case BinaryOp::Mod:
            os << "%";
            break;
        case BinaryOp::Pow:
            os << "**";
            break;
    }
    return os;
}

/**
 * \brief Enum of unary operators
 */
enum class UnaryOp { BitNot, LogicalNot, Neg };
inline std::ostream& operator<<(std::ostream& os, const UnaryOp& uop) {
    switch (uop) {
        case UnaryOp::BitNot:
            os << "~";
            break;
        case UnaryOp::LogicalNot:
            os << "!";
            break;
        case UnaryOp::Neg:
            os << "-";
            break;
    }
    return os;
}

/**
 * \brief Enum of math operators
 */
enum class MathOp {
    Arcsin,
    Sin,
    Arccos,
    Cos,
    Arctan,
    Tan,
    Exp,
    Ln,
    Sqrt,
    Rotl,
    Rotr,
    Popcount
};
inline std::ostream& operator<<(std::ostream& os, const MathOp& mop) {
    switch (mop) {
        case MathOp::Arcsin:
            os << "arcsin";
            break;
        case MathOp::Sin:
            os << "sin";
            break;
        case MathOp::Arccos:
            os << "arccos";
            break;
        case MathOp::Cos:
            os << "cos";
            break;
        case MathOp::Arctan:
            os << "arctan";
            break;
        case MathOp::Tan:
            os << "tan";
            break;
        case MathOp::Exp:
            os << "exp";
            break;
        case MathOp::Ln:
            os << "ln";
            break;
        case MathOp::Sqrt:
            os << "sqrt";
            break;
        case MathOp::Rotl:
            os << "rotl";
            break;
        case MathOp::Rotr:
            os << "rotr";
            break;
        case MathOp::Popcount:
            os << "popcount";
            break;
    }
    return os;
}

/**
 * \class qasm3tools::ast::BExpr
 * \brief Class for binary operator expressions
 * \see qasm3tools::ast::Expr
 */
class BExpr final : public Expr {
    ptr<Expr> lexp_; ///< the left sub-expression
    BinaryOp op_;    ///< the binary operator
    ptr<Expr> rexp_; ///< the right sub-expression

  public:
    /**
     * \brief Constructs a Binary expression
     *
     * \param pos The source position
     * \param lexp The left sub-expression
     * \param op The binary operator
     * \param rexp The right sub-expression
     */
    BExpr(parser::Position pos, ptr<Expr> lexp, BinaryOp op, ptr<Expr> rexp)
        : Expr(pos), lexp_(std::move(lexp)), op_(op), rexp_(std::move(rexp)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BExpr> create(parser::Position pos, ptr<Expr> lexp, BinaryOp op,
                             ptr<Expr> rexp) {
        return std::make_unique<BExpr>(pos, std::move(lexp), op,
                                       std::move(rexp));
    }

    /**
     * \brief Get the binary operator
     *
     * \return A binary operator enum
     */
    BinaryOp op() const { return op_; }

    /**
     * \brief Get the left sub-expression
     *
     * \return A reference to the left sub-expression
     */
    Expr& lexp() { return *lexp_; }

    /**
     * \brief Get the right sub-expression
     *
     * \return A reference to the right sub-expression
     */
    Expr& rexp() { return *rexp_; }

    /**
     * \brief Set the left sub-expression
     *
     * \param exp The new left sub-expression
     */
    void set_lexp(ptr<Expr> exp) { lexp_ = std::move(exp); }

    /**
     * \brief Set the right sub-expression
     *
     * \param exp The new right sub-expression
     */
    void set_rexp(ptr<Expr> exp) { rexp_ = std::move(exp); }

    std::optional<std::complex<double>> constant_eval() const override {
        auto lexp = lexp_->constant_eval();
        auto rexp = rexp_->constant_eval();

        if (!lexp || !rexp)
            return std::nullopt;

        switch (op_) {
            case BinaryOp::EQ:
                return *lexp == *rexp;
            case BinaryOp::NEQ:
                return *lexp != *rexp;
            case BinaryOp::Plus:
                return *lexp + *rexp;
            case BinaryOp::Minus:
                return *lexp - *rexp;
            case BinaryOp::Times:
                return *lexp * *rexp;
            case BinaryOp::Divide:
                return *lexp / *rexp;
            case BinaryOp::Pow:
                return pow(*lexp, *rexp);
            default:
                return std::nullopt; // can't evaluate other ops
        }
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        if (ctx) {
            os << "(";
            lexp_->pretty_print(os, true);
            os << op_;
            rexp_->pretty_print(os, true);
            os << ")";
        } else {
            lexp_->pretty_print(os, true);
            os << op_;
            rexp_->pretty_print(os, true);
        }

        return os;
    }

  protected:
    BExpr* clone() const override {
        return new BExpr(pos_, object::clone(*lexp_), op_,
                         object::clone(*rexp_));
    }
};

/**
 * \class qasm3tools::ast::UExpr
 * \brief Class for unary operator expressions
 * \see qasm3tools::ast::Expr
 */
class UExpr final : public Expr {
    UnaryOp op_;    ///< the unary operator
    ptr<Expr> exp_; ///< the sub-expression

  public:
    /**
     * \brief Constructs a Unary expression
     *
     * \param pos The source position
     * \param op The unary operator
     * \param exp The sub-expression
     */
    UExpr(parser::Position pos, UnaryOp op, ptr<Expr> exp)
        : Expr(pos), op_(op), exp_(std::move(exp)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<UExpr> create(parser::Position pos, UnaryOp op, ptr<Expr> exp) {
        return std::make_unique<UExpr>(pos, op, std::move(exp));
    }

    /**
     * \brief Get the operator
     *
     * \return A unary operator enum
     */
    UnaryOp op() const { return op_; }

    /**
     * \brief Get the sub-expression
     *
     * \return A reference to the sub-expression
     */
    Expr& subexp() { return *exp_; }

    /**
     * \brief Set the sub-expression
     *
     * \param exp The new sub-expression
     */
    void set_subexp(ptr<Expr> exp) { exp_ = std::move(exp); }

    std::optional<std::complex<double>> constant_eval() const override {
        auto expr = exp_->constant_eval();

        if (!expr)
            return std::nullopt;

        switch (op_) {
            case UnaryOp::Neg:
                return -(*expr);
            default:
                return std::nullopt; // can't evaluate other ops
        }
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << op_;
        exp_->pretty_print(os, true);

        return os;
    }

  protected:
    UExpr* clone() const override {
        return new UExpr(pos_, op_, object::clone(*exp_));
    }
};

/**
 * \class qasm3tools::ast::MathExpr
 * \brief Class for math operator expressions
 * \see qasm3tools::ast::Expr
 */
class MathExpr final : public Expr {
    MathOp op_;                   ///< the math operator
    std::vector<ptr<Expr>> args_; ///< the arguments

  public:
    /**
     * \brief Constructs a Math expression
     *
     * \param pos The source position
     * \param op The math operator
     * \param args The arguments
     */
    MathExpr(parser::Position pos, MathOp op, std::vector<ptr<Expr>>&& args)
        : Expr(pos), op_(op), args_(std::move(args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<MathExpr> create(parser::Position pos, MathOp op,
                                std::vector<ptr<Expr>>&& args) {
        return std::make_unique<MathExpr>(pos, op, std::move(args));
    }

    /**
     * \brief Get the operator
     *
     * \return A unary operator enum
     */
    MathOp op() const { return op_; }

    /**
     * \brief Get the number of arguments
     *
     * \return The number of arguments
     */
    int num_args() const { return static_cast<int>(args_.size()); }

    /**
     * \brief Get the ith argument
     *
     * \param i The number of the argument, 0-indexed
     * \return Reference to an expression
     */
    Expr& arg(int i) { return *(args_[i]); }

    /**
     * \brief Set the ith argument
     *
     * \param i The number of the argument, 0-indexed
     * \param expr An expression giving the new argument
     */
    void set_arg(int i, ptr<Expr> expr) { args_[i] = std::move(expr); }

    std::optional<std::complex<double>> constant_eval() const override {
        if (args_.size() != 1)
            return std::nullopt;

        auto expr = args_[0]->constant_eval();

        if (!expr)
            return std::nullopt;

        switch (op_) {
            case MathOp::Arcsin:
                return asin(*expr);
            case MathOp::Sin:
                return sin(*expr);
            case MathOp::Arccos:
                return acos(*expr);
            case MathOp::Cos:
                return cos(*expr);
            case MathOp::Arctan:
                return atan(*expr);
            case MathOp::Tan:
                return tan(*expr);
            case MathOp::Exp:
                return exp(*expr);
            case MathOp::Ln:
                return log(*expr);
            case MathOp::Sqrt:
                return sqrt(*expr);
            default:
                return std::nullopt; // can't evaluate other ops
        }
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << op_ << "(";
        for (auto it = args_.begin(); it != args_.end(); it++)
            os << (it == args_.begin() ? "" : ",") << **it;
        os << ")";

        return os;
    }

  protected:
    MathExpr* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& x : args_)
            tmp.emplace_back(object::clone(*x));
        return new MathExpr(pos_, op_, std::move(tmp));
    }
};

/**
 * \class qasm3tools::ast::CastExpr
 * \brief Class for typecast expressions
 * \see qasm3tools::ast::Expr
 */
class CastExpr final : public Expr {
    ptr<ClassicalType> type_; ///< the type specifier
    ptr<Expr> exp_;           ///< the sub-expression

  public:
    /**
     * \brief Constructs a Cast expression
     *
     * \param pos The source position
     * \param type The type specifier
     * \param exp The sub-expression
     */
    CastExpr(parser::Position pos, ptr<ClassicalType> type, ptr<Expr> exp)
        : Expr(pos), type_(std::move(type)), exp_(std::move(exp)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<CastExpr> create(parser::Position pos, ptr<ClassicalType> type,
                                ptr<Expr> exp) {
        return std::make_unique<CastExpr>(pos, std::move(type), std::move(exp));
    }

    /**
     * \brief Get the type
     *
     * \return A reference to the type
     */
    ClassicalType& type() { return *type_; }

    /**
     * \brief Set the type
     *
     * \param type The new type
     */
    void set_type(ptr<ClassicalType> type) { type_ = std::move(type); }

    /**
     * \brief Get the sub-expression
     *
     * \return A reference to the sub-expression
     */
    Expr& subexp() { return *exp_; }

    /**
     * \brief Set the sub-expression
     *
     * \param exp The new sub-expression
     */
    void set_subexp(ptr<Expr> exp) { exp_ = std::move(exp); }

    std::optional<std::complex<double>> constant_eval() const override {
        return exp_->constant_eval(); // return without casting
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << *type_ << "(" << *exp_ << ")";

        return os;
    }

  protected:
    CastExpr* clone() const override {
        return new CastExpr(pos_, object::clone(*type_), object::clone(*exp_));
    }
};

/**
 * \class qasm3tools::ast::FunctionCall
 * \brief Class for subroutine-call expressions
 * \see qasm3tools::ast::Expr
 */
class FunctionCall final : public Expr {
    symbol name_;                 ///< the subroutine identifier
    std::vector<ptr<Expr>> args_; ///< the arguments

  public:
    /**
     * \brief Constructs a subroutine-call expression
     *
     * \param pos The source position
     * \param name The subroutine name
     * \param args The arguments
     */
    FunctionCall(parser::Position pos, symbol name,
                 std::vector<ptr<Expr>>&& args)
        : Expr(pos), name_(name), args_(std::move(args)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<FunctionCall> create(parser::Position pos, symbol name,
                                    std::vector<ptr<Expr>>&& args) {
        return std::make_unique<FunctionCall>(pos, name, std::move(args));
    }

    /**
     * \brief Get the subroutine name
     *
     * \return Const reference to the subroutine name
     */
    const symbol& name() const { return name_; }

    /**
     * \brief Get the number of arguments
     *
     * \return The number of arguments
     */
    int num_args() const { return static_cast<int>(args_.size()); }

    /**
     * \brief Get the ith argument
     *
     * \param i The number of the argument, 0-indexed
     * \return Reference to an expression
     */
    Expr& arg(int i) { return *(args_[i]); }

    /**
     * \brief Set the ith argument
     *
     * \param i The number of the argument, 0-indexed
     * \param expr An expression giving the new argument
     */
    void set_arg(int i, ptr<Expr> expr) { args_[i] = std::move(expr); }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << name_ << "(";
        for (auto it = args_.begin(); it != args_.end(); it++)
            os << (it == args_.begin() ? "" : ",") << **it;
        os << ")";

        return os;
    }

  protected:
    FunctionCall* clone() const override {
        std::vector<ptr<Expr>> tmp;
        for (auto& x : args_)
            tmp.emplace_back(object::clone(*x));
        return new FunctionCall(pos_, name_, std::move(tmp));
    }
};

/**
 * \class qasm3tools::ast::AccessExpr
 * \brief Class for access expressions
 * \see qasm3tools::ast::Expr
 */
class AccessExpr final : public Expr {
    ptr<Expr> exp_;   ///< the expression
    ptr<Expr> index_; ///< the index

  public:
    /**
     * \brief Constructs an Access expression
     *
     * \param pos The source position
     * \param exp The expression
     * \param index The index
     */
    AccessExpr(parser::Position pos, ptr<Expr> exp, ptr<Expr> index)
        : Expr(pos), exp_(std::move(exp)), index_(std::move(index)) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<AccessExpr> create(parser::Position pos, ptr<Expr> exp,
                                  ptr<Expr> index) {
        return std::make_unique<AccessExpr>(pos, std::move(exp),
                                            std::move(index));
    }

    /**
     * \brief Get the expression
     *
     * \return A reference to the expression
     */
    Expr& exp() { return *exp_; }

    /**
     * \brief Get the index
     *
     * \return A reference to the index
     */
    Expr& index() { return *index_; }

    /**
     * \brief Set the expression
     *
     * \param exp The new expression
     */
    void set_exp(ptr<Expr> exp) { exp_ = std::move(exp); }

    /**
     * \brief Set the index
     *
     * \param exp The new index
     */
    void set_index(ptr<Expr> exp) { index_ = std::move(exp); }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        exp_->pretty_print(os, true);
        os << "[";
        index_->pretty_print(os, false);
        os << "]";

        return os;
    }

  protected:
    AccessExpr* clone() const override {
        return new AccessExpr(pos_, object::clone(*exp_),
                              object::clone(*index_));
    }
};

/**
 * \class qasm3tools::ast::ConstantExpr
 * \brief Class for defined constant expressions
 * \see qasm3tools::ast::Expr
 */
class ConstantExpr final : public Expr {
    Constant constant_;

  public:
    /**
     * \brief Construct a contant expression
     *
     * \param pos The source position
     * \param constant The constant
     */
    ConstantExpr(parser::Position pos, Constant constant)
        : Expr(pos), constant_(constant) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ConstantExpr> create(parser::Position pos, Constant constant) {
        return std::make_unique<ConstantExpr>(pos, constant);
    }

    /**
     * \brief Get the constant
     *
     * \return A constant enum
     */
    Constant constant() const { return constant_; }

    std::optional<std::complex<double>> constant_eval() const override {
        switch (constant_) {
            case Constant::Pi:
                return utils::pi;
            case Constant::Tau:
                return utils::tau;
            case Constant::Euler:
                return utils::euler;
            default:
                return 0; // inaccessible
        }
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << constant_;
        return os;
    }

  protected:
    ConstantExpr* clone() const override {
        return new ConstantExpr(pos_, constant_);
    }
};

/**
 * \class qasm3tools::ast::IntExpr
 * \brief Class for integer literal expressions
 * \see qasm3tools::ast::Expr
 */
class IntExpr final : public Expr {
    int value_; ///< the integer value

  public:
    /**
     * \brief Construct an integer expression
     *
     * \param pos The source position
     * \param val The integer value
     */
    IntExpr(parser::Position pos, int value) : Expr(pos), value_(value) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<IntExpr> create(parser::Position pos, int value) {
        return std::make_unique<IntExpr>(pos, value);
    }

    /**
     * \brief Get the integer value
     *
     * \return The integer value
     */
    int value() const { return value_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return value_;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << value_;
        return os;
    }

  protected:
    IntExpr* clone() const override { return new IntExpr(pos_, value_); }
};

/**
 * \class qasm3tools::ast::RealExpr
 * \brief Class for floating point literal expressions
 * \see qasm3tools::ast::Expr
 */
class RealExpr final : public Expr {
    double value_; ///< the floating point value

  public:
    /**
     * \brief Construct a real-value expression
     *
     * \param pos The source position
     * \param val The floating point value
     */
    RealExpr(parser::Position pos, double value) : Expr(pos), value_(value) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<RealExpr> create(parser::Position pos, double value) {
        return std::make_unique<RealExpr>(pos, value);
    }

    /**
     * \brief Get the real value
     *
     * \return The floating point value
     */
    double value() const { return value_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return value_;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        std::streamsize ss = os.precision();
        os << std::setprecision(15) << value_ << std::setprecision(ss);
        return os;
    }

  protected:
    RealExpr* clone() const override { return new RealExpr(pos_, value_); }
};

/**
 * \class qasm3tools::ast::ImagExpr
 * \brief Class for imaginary literal expressions
 * \see qasm3tools::ast::Expr
 */
class ImagExpr final : public Expr {
    double value_; ///< the floating point value (which is multiplied by i)

  public:
    /**
     * \brief Construct an imaginary expression
     *
     * \param pos The source position
     * \param val The floating point value
     */
    ImagExpr(parser::Position pos, double value) : Expr(pos), value_(value) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<ImagExpr> create(parser::Position pos, double value) {
        return std::make_unique<ImagExpr>(pos, value);
    }

    /**
     * \brief Get the real value
     *
     * \return The floating point value
     */
    double value() const { return value_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::complex<double>(value_) * std::complex<double>(0, 1);
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        std::streamsize ss = os.precision();
        os << std::setprecision(15) << value_ << std::setprecision(ss) << "im";
        return os;
    }

  protected:
    ImagExpr* clone() const override { return new ImagExpr(pos_, value_); }
};

/**
 * \class qasm3tools::ast::BoolExpr
 * \brief Class for boolean literal expressions
 * \see qasm3tools::ast::Expr
 */
class BoolExpr final : public Expr {
    bool value_; ///< the boolean value

  public:
    /**
     * \brief Construct a boolean expression
     *
     * \param pos The source position
     * \param val The boolean value
     */
    BoolExpr(parser::Position pos, bool value) : Expr(pos), value_(value) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<BoolExpr> create(parser::Position pos, bool value) {
        return std::make_unique<BoolExpr>(pos, value);
    }

    /**
     * \brief Get the boolean value
     *
     * \return The boolean value
     */
    bool value() const { return value_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return value_;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;

        os << (value_ ? "true" : "false");
        return os;
    }

  protected:
    BoolExpr* clone() const override { return new BoolExpr(pos_, value_); }
};

/**
 * \class qasm3tools::ast::VarExpr
 * \brief Class for variable expressions
 * \see qasm3tools::ast::Expr
 */
class VarExpr final : public Expr {
    symbol var_; ///< the identifier

  public:
    /**
     * \brief Construct a variable expression
     *
     * \param pos The source position
     * \param var The variable name
     */
    VarExpr(parser::Position pos, symbol var) : Expr(pos), var_(var) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<VarExpr> create(parser::Position pos, symbol var) {
        return std::make_unique<VarExpr>(pos, var);
    }

    /**
     * \brief Get the variable name
     *
     * \return Constant reference to the name
     */
    const symbol& var() const { return var_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;
        os << var_;
        return os;
    }

  protected:
    VarExpr* clone() const override { return new VarExpr(pos_, var_); }
};

/**
 * \class qasm3tools::ast::StringExpr
 * \brief Class for string expressions
 * \see qasm3tools::ast::Expr
 */
class StringExpr final : public Expr {
    std::string text_; ///< the string

  public:
    /**
     * \brief Construct a variable expression
     *
     * \param pos The source position
     * \param text The string
     */
    StringExpr(parser::Position pos, std::string text)
        : Expr(pos), text_(text) {}

    /**
     * \brief Protected heap-allocated construction
     */
    static ptr<StringExpr> create(parser::Position pos, std::string text) {
        return std::make_unique<StringExpr>(pos, text);
    }

    /**
     * \brief Get the string text
     *
     * \return Constant reference to the text
     */
    const std::string& text() const { return text_; }

    std::optional<std::complex<double>> constant_eval() const override {
        return std::nullopt;
    }
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::ostream& pretty_print(std::ostream& os, bool ctx) const override {
        (void) ctx;
        os << text_;
        return os;
    }

  protected:
    StringExpr* clone() const override { return new StringExpr(pos_, text_); }
};

/**
 * \brief Returns an Expr representing the given angle
 *
 * \param theta The angle
 * \return The equivalent QASM expression
 */
inline ptr<Expr> angle_to_expr(const utils::Angle& theta) {
    parser::Position pos;

    if (theta.is_symbolic()) {
        // Angle is of the form pi*(a/b) for a & b integers
        auto [a, b] = *(theta.symbolic_value());

        if (a == 0) {
            return std::make_unique<IntExpr>(IntExpr(pos, 0));
        } else if (a == 1) {
            return std::make_unique<BExpr>(
                pos, std::make_unique<ConstantExpr>(pos, Constant::Pi),
                BinaryOp::Divide, std::make_unique<IntExpr>(IntExpr(pos, b)));
        } else {
            auto subexpr = std::make_unique<BExpr>(
                pos, std::make_unique<ConstantExpr>(pos, Constant::Pi),
                BinaryOp::Times, std::make_unique<IntExpr>(IntExpr(pos, a)));

            return std::make_unique<BExpr>(
                pos, std::move(subexpr), BinaryOp::Divide,
                std::make_unique<IntExpr>(IntExpr(pos, b)));
        }
    } else {
        // Angle is real-valued
        return std::make_unique<RealExpr>(RealExpr(pos, theta.numeric_value()));
    }
}

} // namespace ast
} // namespace qasm3tools
