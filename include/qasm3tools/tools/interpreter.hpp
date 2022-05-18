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
 * \file qasm3tools/tools/interpreter.hpp
 * \brief OpenQASM 3 program interpreter
 */

#pragma once

#include "../ast/ast.hpp"
#include "../ast/visitor.hpp"
#include "../utils/templates.hpp"
#include "../utils/angle.hpp"

#include "qpp/qpp.h"

#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#include <xtensor/xarray.hpp>
#include <xtensor/xadapt.hpp>
#include <xtensor/xbuilder.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xvectorize.hpp>
#include <xtensor/xview.hpp>

#define WHILE_ITERATION_LIMIT 1000

namespace qasm3tools {
namespace tools {

using namespace xt::placeholders;
using namespace qpp::literals;

using idx = qpp::idx;

/**
 * \class qasm3tools::tools::RuntimeError
 * \brief Exception class for runtime errors
 */
class RuntimeError : public std::exception {
  public:
    RuntimeError() noexcept = default;
    ~RuntimeError() = default;
    const char* what() const noexcept { return "Error(s) occurred"; }
};

/**
 * \class qasm3tools::tools::NotImplementedError
 * \brief Exception class for non-implemented features
 */
class NotImplementedError : public std::exception {
  public:
    NotImplementedError() noexcept = default;
    ~NotImplementedError() = default;
    const char* what() const noexcept { return "Error(s) occurred"; }
};

namespace types {

struct QASM_none {};

struct QASM_bool {
    bool value = false;

    friend std::ostream& operator<<(std::ostream& os, const QASM_bool& b) {
        return os << (b.value ? "true" : "false");
    }
};

struct QASM_int {
    int width; // negative indicates unspecified width (e.g. int literal)
    bool is_signed;
    long long value; // signed 64 bits; arithmetic with uint[64] may be buggy

    QASM_int(int w, bool i = true, long long v = 0)
        : width(w), is_signed(i), value(v) {
        if (width > 64) {
            width = 64;
            std::cerr << "warning: int[" << width
                      << "] is too large to handle; using int[64] instead\n";
        }
        // mod by 2^width
        if (width > 0 && width < 64) {
            const long long maxbits = (long long) 1 << width;
            value %= maxbits;
            if (!is_signed && value < 0) {
                // unsigned means nonnegative
                value += maxbits;
            } else if (is_signed) {
                const long long half_maxbits = maxbits >> 1;
                // range is [-2^(width-1), 2^(width-1)-1]
                if (value >= half_maxbits)
                    value -= maxbits;
                else if (value < -half_maxbits)
                    value += maxbits;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const QASM_int& i) {
        if (!i.is_signed && i.width == 64) {
            return os << (unsigned long long) i.value;
        }
        return os << i.value;
    }
};

struct QASM_float {
    double value = 0;

    friend std::ostream& operator<<(std::ostream& os, const QASM_float& f) {
        return os << f.value;
    }
};

/**
 * First bit has the smallest value
 * e.g. [0, 0, 0, 1] means 1/2
 *      [0, 0, 1, 1] means 1/2 + 1/4
 *      etc.
 */
struct QASM_angle {
    int width;
    std::vector<bool> bits;

    QASM_angle(std::vector<bool> bits) : width(bits.size()), bits(bits) {}
    QASM_angle(int width) : width(width), bits(width, false) {}
    QASM_angle(int width, double val) : width(width), bits(width, false) {
        // bring into [0, 2*pi)
        double mod_val = val - utils::tau * floor(val / utils::tau);
        double tmp = utils::pi;
        for (auto it = bits.rbegin(); it != bits.rend(); it++) {
            if (mod_val >= tmp) {
                *it = true;
                mod_val -= tmp;
            }
            tmp /= 2;
        }
    }

    double to_float() const {
        double tmp = utils::pi;
        double ans = 0;
        for (auto it = bits.rbegin(); it != bits.rend(); it++) {
            if (*it)
                ans += tmp;
            tmp /= 2;
        }
        return ans;
    }

    friend std::ostream& operator<<(std::ostream& os, const QASM_angle& a) {
        return os << a.to_float();
    }
};

struct QASM_cbit {
    bool bit = false;

    friend std::ostream& operator<<(std::ostream& os, const QASM_cbit& b) {
        return os << b.bit;
    }
};

struct QASM_qubit {
    idx id = 0;

    friend std::ostream& operator<<(std::ostream& os, const QASM_qubit& q) {
        return os << "$" << q.id;
    }
};

using BasicType = std::variant<QASM_bool, QASM_int, QASM_float, QASM_angle,
                               QASM_cbit, QASM_qubit>;

std::ostream& operator<<(std::ostream& os, const BasicType& exp) {
    std::visit([&os](auto&& arg) { os << arg; }, exp);
    return os;
}

/**
 * \brief Reference to a bit in an integer or angle
 */
class BitReference {
  public:
    virtual void assign(bool value) {}
};
class IntBitReference : public BitReference {
    QASM_int* ref_;
    int index_;

  public:
    IntBitReference(QASM_int* ref, int index) : ref_(ref), index_(index) {}
    void assign(bool value) override {
        if (value) {
            ref_->value |= 1UL << index_;
        } else {
            ref_->value &= ~(1UL << index_);
        }
    }
};
class AngleBitReference : public BitReference {
    QASM_angle* ref_;
    int index_;

  public:
    AngleBitReference(QASM_angle* ref, int index) : ref_(ref), index_(index) {}
    void assign(bool value) override { ref_->bits[index_] = value; }
};

using ExprType = std::variant<QASM_none, BasicType, xt::xarray<BasicType>,
                              BasicType*, xt::xarray<BasicType*>, BitReference,
                              xt::xarray<BitReference>>;

/**
 * \brief Cast source expression to target type
 */
inline BasicType basic_cast(const BasicType& source, const BasicType& target) {
    return std::visit(
        utils::overloaded{
            /* casting from bool */
            [](const QASM_bool& s, const QASM_bool&) -> BasicType { return s; },
            [](const QASM_bool& s, const QASM_int& t) -> BasicType {
                return QASM_int(t.width, t.is_signed, s.value);
            },
            [](const QASM_bool& s, const QASM_float&) -> BasicType {
                return QASM_float{(double) s.value};
            },
            [](const QASM_bool& s, const QASM_cbit&) -> BasicType {
                return QASM_cbit{s.value};
            },
            /* casting from int */
            [](const QASM_int& s, const QASM_bool&) -> BasicType {
                return QASM_bool{(bool) s.value};
            },
            [](const QASM_int& s, const QASM_int& t) -> BasicType {
                return QASM_int(t.width, t.is_signed, s.value);
            },
            [](const QASM_int& s, const QASM_float&) -> BasicType {
                return QASM_float{(double) s.value};
            },
            /* casting from float */
            [](const QASM_float& s, const QASM_bool&) -> BasicType {
                return QASM_bool{(bool) s.value};
            },
            [](const QASM_float& s, const QASM_int& t) -> BasicType {
                return QASM_int(t.width, t.is_signed, s.value);
            },
            [](const QASM_float& s, const QASM_float&) -> BasicType {
                return s;
            },
            [](const QASM_float& s, const QASM_angle& t) -> BasicType {
                return QASM_angle(t.width, s.value);
            },
            /* casting from angle */
            [](const QASM_angle& s, const QASM_bool&) -> BasicType {
                for (bool bit : s.bits) {
                    if (bit)
                        return QASM_bool{true};
                }
                return QASM_bool{false};
            },
            [](const QASM_angle& s, const QASM_float&) -> BasicType {
                return QASM_float{s.to_float()};
            },
            [](const QASM_angle& s, const QASM_angle& t) -> BasicType {
                if (s.width == t.width)
                    return s;
                else if (s.width > t.width) {
                    // truncate
                    return QASM_angle(std::vector<bool>(
                        s.bits.begin() + (s.width - t.width), s.bits.end()));
                } else {
                    // pad with zeros
                    std::vector<bool> ang(t.width - s.width, false);
                    ang.insert(ang.end(), s.bits.begin(), s.bits.end());
                    return QASM_angle(std::move(ang));
                }
            },
            /* casting from bit */
            [](const QASM_cbit& s, const QASM_bool&) -> BasicType {
                return QASM_bool{s.bit};
            },
            [](const QASM_cbit& s, const QASM_int&) -> BasicType {
                return QASM_int{s.bit};
            },
            [](const QASM_cbit& s, const QASM_cbit&) -> BasicType { return s; },
            /* the rest can't be casted */
            [](const QASM_qubit& s, const QASM_qubit&) -> BasicType {
                return s;
            },
            /* catch-all for invalid casting */
            [](auto, auto) -> BasicType {
                std::cerr << "Invalid cast!\n";
                throw RuntimeError();
            }},
        source, target);
}

/**
 * \brief Cast but return target type instead of a std::variant
 */
template <typename T>
inline T smart_cast(const BasicType& source, const T& target) {
    return std::get<T>(basic_cast(source, target));
}

/* array -> basic helpers */
inline BasicType deref(BasicType* x) { return *x; }
inline xt::xarray<BasicType> deref_xarray(xt::xarray<BasicType*> x) {
    auto vec_deref = xt::vectorize(deref);
    return vec_deref(x);
}

/* basic -> basic */
inline void overwrite_help(const BasicType& s, BasicType& t) {
    t = basic_cast(s, t);
}
/* array -> basic */
inline void overwrite_help(xt::xarray<BasicType>& s, BasicType& t) {
    std::visit(
        utils::overloaded{
            [&s](QASM_int& v) {
                if (s.size() == v.width) {
                    unsigned long long ans = 0;
                    for (auto it = s.rbegin(); it != s.rend(); it++) {
                        ans <<= 1;
                        ans += smart_cast(*it, QASM_cbit()).bit;
                    }
                    v = QASM_int(v.width, v.is_signed, ans);
                    return;
                }
                std::cerr << "Failed to assign bit array to integer (size "
                             "mismatch)\n";
                throw RuntimeError();
            },
            [&s](QASM_angle& v) {
                if (s.size() == v.width) {
                    std::vector<bool> bits;
                    std::transform(s.begin(), s.end(), std::back_inserter(bits),
                                   [](BasicType c) -> bool {
                                       return smart_cast(c, QASM_cbit()).bit;
                                   });
                    v = QASM_angle(std::move(bits));
                    return;
                }
                std::cerr
                    << "Failed to assign bit array to angle (size mismatch)\n";
                throw RuntimeError();
            },
            [&s](QASM_cbit& v) {
                if (s.size() == 1) {
                    v = smart_cast(*s.begin(), v);
                    return;
                }
                std::cerr
                    << "Failed to assign bit array to bit (array size != 1)\n";
                throw RuntimeError();
            },
            [](auto) {
                std::cerr << "Failed to convert array to basic_type\n";
                throw RuntimeError();
            }},
        t);
}
/* basic -> array */
inline void overwrite_help(BasicType& s, xt::xarray<BasicType*>& t) {
    std::visit(
        utils::overloaded{
            [&t](QASM_int& v) {
                if (t.size() == v.width) {
                    long long nth_bit = 1;
                    for (auto it = t.begin(); it != t.end(); it++) {
                        overwrite_help(
                            QASM_cbit{static_cast<bool>(v.value & nth_bit)},
                            **it);
                        nth_bit <<= 1;
                    }
                    return;
                }
                std::cerr << "Failed to assign integer to bit array (size "
                             "mismatch)\n";
                throw RuntimeError();
            },
            [&t](QASM_angle& v) {
                if (t.size() == v.width) {
                    auto it = t.begin();
                    auto v_it = v.bits.begin();
                    for (; it != t.end() && v_it != v.bits.end();
                         it++, v_it++) {
                        overwrite_help(QASM_cbit{*v_it}, **it);
                    }
                    return;
                }
                std::cerr
                    << "Failed to assign angle to bit array (size mismatch)\n";
                throw RuntimeError();
            },
            [&t](QASM_cbit& v) {
                if (t.size() == 1) {
                    overwrite_help(v, **t.begin());
                    return;
                }
                std::cerr
                    << "Failed to assign bit to bit array (array size != 1)\n";
                throw RuntimeError();
            },
            [](auto) {
                std::cerr << "Failed to convert basic_type to array\n";
                throw RuntimeError();
            }},
        s);
}

/**
 * \brief Set target expression to source expression without changing its type
 */
inline void overwrite(ExprType& source, ExprType& target) {
    return std::visit(
        utils::overloaded{
            /* basic -> basic */
            [](BasicType& s, BasicType& t) { overwrite_help(s, t); },
            [](BasicType& s, BasicType* t) { overwrite_help(s, *t); },
            /*[](BasicType* s, BasicType& t) { overwrite_help(*s, t); },*/
            /*[](BasicType* s, BasicType* t) { overwrite_help(*s, *t); },*/
            /* array -> basic */
            [](xt::xarray<BasicType>& s, BasicType& t) {
                overwrite_help(s, t);
            },
            [](xt::xarray<BasicType>& s, BasicType* t) {
                overwrite_help(s, *t);
            },
            /*[](xt::xarray<BasicType*> s, BasicType& t) {
                overwrite_help(deref_xarray(s), t);
            },*/
            /*[](xt::xarray<BasicType*> s, BasicType* t) {
                overwrite_help(deref_xarray(s), *t);
            },*/
            /* basic -> array */
            [](BasicType& s, xt::xarray<BasicType*>& t) {
                overwrite_help(s, t);
            },
            /*[](BasicType* s, xt::xarray<BasicType*>& t) {
                overwrite_help(*s, t);
            },*/
            /* array -> array */
            [](xt::xarray<BasicType>& s, xt::xarray<BasicType*>& t) {
                if (s.shape() != t.shape()) {
                    std::cerr << "Overwrite: array shape mismatch!\n";
                    throw RuntimeError();
                }
                auto it = t.begin();
                auto s_it = s.begin();
                for (; it != t.end() && s_it != s.end(); it++, s_it++) {
                    overwrite_help(*s_it, **it);
                }
            },
            /*[](xt::xarray<BasicType*>& s, xt::xarray<BasicType*>& t) {
                if (s.shape() != t.shape()) {
                    std::cerr << "Overwrite: array shape mismatch!\n";
                    throw RuntimeError();
                }
                for (auto it = t.begin(), s_it = s.begin(); it != t.end() &&
            s_it != s.end(); it++, s_it++) { overwrite_help(**s_it, **it);
                }
            },*/
            /* assigning to bits of int/angle */
            [](BasicType& s, BitReference& t) {
                t.assign(smart_cast(s, QASM_cbit()).bit);
            },
            [](xt::xarray<BasicType>& s, xt::xarray<BitReference>& t) {
                if (s.shape() != t.shape()) {
                    std::cerr << "Overwrite: slicing shape mismatch!\n";
                    throw RuntimeError();
                }
                auto it = t.begin();
                auto s_it = s.begin();
                for (; it != t.end() && s_it != s.end(); it++, s_it++) {
                    it->assign(smart_cast(*s_it, QASM_cbit()).bit);
                }
            },
            [](QASM_none&, QASM_none&) {},
            /* catch-all for invalid overwrite */
            [](auto, auto) {
                std::cerr << "Overwrite: target is not an lvalue!\n";
                throw RuntimeError();
            }},
        source, target);
}
template <typename T>
inline T cast_to_basic(ExprType& source, T&& target) {
    ExprType tmp = std::move(target);
    overwrite(source, tmp);
    return std::get<T>(std::get<BasicType>(tmp));
}

/**
 * \brief Get numerical value of an expression
 */
using value_type = std::variant<long long, unsigned long long, double>;
inline value_type get_value_help(const BasicType& t) {
    return std::visit(
        utils::overloaded{
            [](const QASM_bool& v) -> value_type {
                return (long long) v.value;
            },
            [](const QASM_int& v) -> value_type {
                if (v.is_signed) {
                    return v.value;
                }
                return (unsigned long long) v.value;
            },
            [](const QASM_float& v) -> value_type { return v.value; },
            [](const QASM_angle& v) -> value_type { return v.to_float(); },
            [](const QASM_cbit& v) -> value_type { return (long long) v.bit; },
            [](auto) -> value_type {
                std::cerr << ": get_value called on type without a value\n";
                throw RuntimeError();
            }},
        t);
}
inline value_type get_value_help(xt::xarray<BasicType>& s) {
    unsigned long long ans = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        ans <<= 1;
        ans += smart_cast(*it, QASM_cbit()).bit;
    }
    return ans;
}
inline value_type get_value(ExprType& x) {
    return std::visit(
        utils::overloaded{
            [](BasicType& v) -> value_type { return get_value_help(v); },
            /*[](BasicType* v) -> value_type {
                return get_value_help(*v);
            },*/
            [](xt::xarray<BasicType>& v) -> value_type {
                return get_value_help(v);
            },
            /*[](xt::xarray<BasicType*>& v) -> value_type {
                return get_value_help(deref_xarray(v));
            },*/
            [](auto) -> value_type {
                std::cerr << ": get_value called on type without a value\n";
                throw RuntimeError();
            }},
        x);
}

xt::xarray<BitReference> to_creg_ref(BasicType* type) {
    if (std::holds_alternative<QASM_int>(*type)) {
        auto& i = std::get<QASM_int>(*type);
        if (i.width < 0) {
            std::cerr
                << ": error : int of unspecified width cannot be indexed\n";
            throw RuntimeError();
        }
        auto creg = xt::xarray<BitReference>::from_shape(
            {static_cast<unsigned long>(i.width)});
        for (int j = 0; j < i.width; j++) {
            creg(j) = IntBitReference(std::addressof(i), j);
        }
        return creg;
    } else if (std::holds_alternative<QASM_angle>(*type)) {
        auto& a = std::get<QASM_angle>(*type);
        auto creg = xt::xarray<BitReference>::from_shape(
            {static_cast<unsigned long>(a.width)});
        for (int j = 0; j < a.width; j++) {
            creg(j) = AngleBitReference(std::addressof(a), j);
        }
        return creg;
    }
    std::cerr << ": error : to_creg_ref() : basic type cannot be indexed\n";
    throw RuntimeError();
}

xt::xarray<BasicType> to_creg(const BasicType& type) {
    if (std::holds_alternative<QASM_int>(type)) {
        auto& i = std::get<QASM_int>(type);
        if (i.width < 0) {
            std::cerr
                << ": error : int of unspecified width cannot be indexed\n";
            throw RuntimeError();
        }
        auto creg = xt::xarray<BasicType>::from_shape(
            {static_cast<unsigned long>(i.width)});
        long long mask = 1;
        for (int j = 0; j < i.width; j++) {
            creg(j) = QASM_cbit{static_cast<bool>(i.value & mask)};
            mask <<= 1;
        }
        return creg;
    } else if (std::holds_alternative<QASM_angle>(type)) {
        auto& a = std::get<QASM_angle>(type);
        auto creg = xt::xarray<BasicType>::from_shape(
            {static_cast<unsigned long>(a.width)});
        for (int j = 0; j < a.width; j++) {
            creg(j) = QASM_cbit{a.bits[j]};
        }
        return creg;
    }
    std::cerr << ": error : to_creg() : basic type cannot be indexed\n";
    throw RuntimeError();
}

} // namespace types

using BasicType = types::BasicType;
using ExprType = types::ExprType;

/**
 * \class qasm3tools::tools::Executor
 * \brief Program interpreter
 */
class Executor final : ast::Visitor {
    /**
     * \brief Data struct for quantum gate types
     */
    struct GateType {
        std::vector<ast::symbol> c_param_names; ///< parameter names
        std::vector<ast::symbol> q_param_names; ///< parameter names
        ast::QuantumBlock* body;
    };

    /**
     * \brief Data struct for subroutine types
     */
    struct SubroutineType {
        std::vector<ExprType> param_types;    ///< function signature
        std::vector<ast::symbol> param_names; ///< parameter names
        ExprType return_type; ///< return type (None if no return)
        ast::ProgramBlock* body;
    };

    /**
     * \brief OpenQASM types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using Type = std::variant<ExprType, GateType, SubroutineType>;

    /**
     * \brief Enum class for control statements
     */
    enum class ControlFlow { Break, Continue, Return, End };

    /**
     * \brief Ranges for looping
     */
    struct LoopRange {
        int start;
        int step;
        int stop;

        LoopRange(int x, int y, int z) : start(x), step(y), stop(z) {}
    };

  public:
    void run(ast::Program& prog) { prog.accept(*this); }

    // Index identifiers
    void visit(ast::SingleIndex& index) override {
        index.index().accept(*this);
        auto val = types::cast_to_basic(value_, types::QASM_int(-1));
        index_entities_.push_back(val.value);
    }
    void visit(ast::RangeIndex& index) override {
        types::QASM_int start{-1, true, INT_MAX};
        types::QASM_int step{-1, true, INT_MAX};
        types::QASM_int stop{-1, true, INT_MAX};
        if (index.start()) {
            (**index.start()).accept(*this);
            start = types::cast_to_basic(value_, types::QASM_int(-1));
        }
        if (index.step()) {
            (**index.step()).accept(*this);
            step = types::cast_to_basic(value_, types::QASM_int(-1));
            if (step.value == 0) {
                std::cerr << index.pos()
                          << ": error : range step size is zero\n";
                throw RuntimeError();
            }
        }
        if (index.stop()) {
            (**index.stop()).accept(*this);
            stop = types::cast_to_basic(value_, types::QASM_int(-1));
        }
        int a = start.value, c = step.value, b = stop.value;
        if (a == INT_MAX && b == INT_MAX && c == INT_MAX)
            index_entities_.push_back(xt::all());
        else if (a == INT_MAX && b == INT_MAX)
            index_entities_.push_back(xt::range(_, _, c));
        else if (a == INT_MAX && c == INT_MAX)
            index_entities_.push_back(xt::range(_, b));
        else if (b == INT_MAX && c == INT_MAX)
            index_entities_.push_back(xt::range(a, _));
        else if (a == INT_MAX)
            index_entities_.push_back(xt::range(_, b, c));
        else if (b == INT_MAX)
            index_entities_.push_back(xt::range(a, _, c));
        else if (c == INT_MAX)
            index_entities_.push_back(xt::range(a, b));
        else
            index_entities_.push_back(xt::range(a, b, c));
    }
    void visit(ast::IndexEntityList& indices) override {
        // save array
        auto tmp = std::move(value_);
        // convert int/angle to creg
        if (std::holds_alternative<BasicType*>(tmp)) {
            tmp = to_creg_ref(std::get<BasicType*>(tmp));
        } else if (std::holds_alternative<BasicType>(tmp)) {
            tmp = to_creg(std::get<BasicType>(tmp));
        }
        // get index entities
        index_entities_.clear();
        indices.foreach_index(
            [this](ast::IndexEntity& index) { index.accept(*this); });
        // apply index operation
        std::visit(
            utils::overloaded{
                [this](xt::xarray<BasicType>& x) {
                    xt::xarray<BasicType> tmp =
                        xt::strided_view(x, index_entities_);
                    if (tmp.dimension() == 0) {
                        value_ = *tmp.begin();
                    } else {
                        value_ = std::move(tmp);
                    }
                },
                [this](xt::xarray<BasicType*>& x) {
                    xt::xarray<BasicType*> tmp =
                        xt::strided_view(x, index_entities_);
                    if (tmp.dimension() == 0) {
                        value_ = *tmp.begin();
                    } else {
                        value_ = std::move(tmp);
                    }
                },
                [&indices](auto) {
                    std::cerr << indices.pos()
                              << ": error : non-array type cannot be indexed\n";
                    throw RuntimeError();
                }},
            tmp);
    }
    void visit(ast::ListSlice& slice) override {
        // save array
        auto tmp = std::move(value_);
        // convert int/angle to creg
        if (std::holds_alternative<BasicType*>(tmp)) {
            tmp = to_creg_ref(std::get<BasicType*>(tmp));
        } else if (std::holds_alternative<BasicType>(tmp)) {
            tmp = to_creg(std::get<BasicType>(tmp));
        }
        // get indices
        std::vector<int> indices;
        for (auto& index : slice.indices()) {
            index->accept(*this);
            indices.push_back(
                types::cast_to_basic(value_, types::QASM_int(-1)).value);
        }
        // apply index operation
        std::visit(
            utils::overloaded{
                [this, &indices](xt::xarray<BasicType>& x) {
                    value_ = xt::xarray<BasicType>(
                        xt::view(x, xt::xkeep_slice<std::ptrdiff_t>(indices)));
                },
                [this, &indices](xt::xarray<BasicType*>& x) {
                    value_ = xt::xarray<BasicType*>(
                        xt::view(x, xt::xkeep_slice<std::ptrdiff_t>(indices)));
                },
                [&slice](auto) {
                    std::cerr << slice.pos()
                              << ": error : non-array type cannot be indexed\n";
                    throw RuntimeError();
                }},
            tmp);
    }
    void visit(ast::IndexId& indexid) override {
        auto& entry = std::get<ExprType>(lookup(indexid.var()));
        // get pointer(s), if applicable
        if (std::holds_alternative<xt::xarray<BasicType>>(entry)) {
            auto& x = std::get<xt::xarray<BasicType>>(entry);
            std::vector<BasicType*> x_ref;
            x_ref.reserve(x.size());
            for (BasicType& i : x)
                x_ref.push_back(std::addressof(i));
            value_ = xt::xarray<BasicType*>(xt::adapt(x_ref, x.shape()));
        } else if (std::holds_alternative<BasicType>(entry)) {
            value_ = std::addressof(std::get<BasicType>(entry));
        } else {
            value_ = entry;
        }
        // apply index operations
        indexid.foreach_index_op(
            [this](ast::IndexOp& op) { op.accept(*this); });
    }
    // Types
    void visit(ast::SingleDesignatorType& type) override {
        int n;
        if (type.size()) {
            (**type.size()).accept(*this);
            n = std::get<types::QASM_int>(std::get<BasicType>(value_)).value;
        } else {
            std::cerr << type.pos()
                      << ": error : single designator type must have specified "
                         "size\n";
            throw RuntimeError();
        }
        switch (type.type()) {
            case ast::SDType::Int:
                value_ = types::QASM_int{n};
                break;
            case ast::SDType::Uint:
                value_ = types::QASM_int(n, false);
                break;
            case ast::SDType::Float:
                value_ = types::QASM_float();
                break;
            case ast::SDType::Angle:
                value_ = types::QASM_angle{n};
                break;
        }
    }
    void visit(ast::NoDesignatorType& type) override {
        switch (type.type()) {
            case ast::NDType::Bool:
                value_ = types::QASM_bool();
                break;
            case ast::NDType::Duration:
            case ast::NDType::Stretch:
                std::cerr << type.pos() << ": circuit timing not supported\n";
                throw NotImplementedError();
        }
    }
    void visit(ast::BitType& type) override {
        if (type.size()) {
            (**type.size()).accept(*this);
            unsigned long n =
                std::get<types::QASM_int>(std::get<BasicType>(value_)).value;
            auto tmp = xt::xarray<BasicType>::from_shape({n});
            tmp.fill(types::QASM_cbit());
            value_ = std::move(tmp);
        } else {
            value_ = types::QASM_cbit();
        }
    }
    void visit(ast::ComplexType& type) override {
        std::cerr << type.pos() << ": complex types not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::ArrayType& type) override {
        std::vector<unsigned long> shape;
        for (int i = 0; i < type.dims(); i++) {
            type.dim(i).accept(*this);
            shape.push_back(
                std::get<types::QASM_int>(std::get<BasicType>(value_)).value);
        }
        type.subtype().accept(*this);
        auto tmp = xt::xarray<BasicType>::from_shape(shape);
        tmp.fill(std::get<BasicType>(value_));
        value_ = std::move(tmp);
    }
    void visit(ast::ArrayRefType& type) override {
        // Arrays in functions are passed by reference; no casting occurs
        // Here we just signify that it's an array type
        value_ = xt::xarray<BasicType>();
    }
    void visit(ast::QubitType& type) override {
        if (type.size()) {
            (**type.size()).accept(*this);
            unsigned long n =
                std::get<types::QASM_int>(std::get<BasicType>(value_)).value;
            auto tmp = xt::xarray<BasicType>::from_shape({n});
            tmp.fill(types::QASM_qubit());
            value_ = std::move(tmp);
        } else {
            value_ = types::QASM_qubit();
        }
    }
    // Expressions
    void visit(ast::BExpr& exp) override {
        exp.lexp().accept(*this);
        auto v1 = value_;
        exp.rexp().accept(*this);
        auto v2 = value_;
        value_ = types::QASM_none();
        switch (exp.op()) {
            case ast::BinaryOp::LogicalOr:
            case ast::BinaryOp::LogicalAnd: {
                auto b1 = types::cast_to_basic(v1, types::QASM_bool{});
                auto b2 = types::cast_to_basic(v2, types::QASM_bool{});
                if (exp.op() == ast::BinaryOp::LogicalOr) {
                    value_ = types::QASM_bool{b1.value || b2.value};
                } else {
                    value_ = types::QASM_bool{b1.value && b2.value};
                }
                return;
            }
            case ast::BinaryOp::BitOr:
            case ast::BinaryOp::XOr:
            case ast::BinaryOp::BitAnd: {
                if (std::holds_alternative<BasicType>(v1) &&
                    std::holds_alternative<BasicType>(v2)) {
                    value_ = std::visit(
                        utils::overloaded{
                            [&exp](const types::QASM_bool& x,
                                   const types::QASM_bool& y) -> ExprType {
                                if (exp.op() == ast::BinaryOp::BitOr) {
                                    return types::QASM_bool{x.value || y.value};
                                } else if (exp.op() == ast::BinaryOp::XOr) {
                                    return types::QASM_bool{x.value != y.value};
                                } else {
                                    return types::QASM_bool{x.value && y.value};
                                }
                            },
                            [&exp](const types::QASM_int& x,
                                   const types::QASM_int& y) -> ExprType {
                                if (exp.op() == ast::BinaryOp::BitOr) {
                                    return types::QASM_int(-1, true,
                                                           x.value | y.value);
                                } else if (exp.op() == ast::BinaryOp::XOr) {
                                    return types::QASM_int(-1, true,
                                                           x.value ^ y.value);
                                } else {
                                    return types::QASM_int(-1, true,
                                                           x.value & y.value);
                                }
                            },
                            [&exp](const types::QASM_cbit& x,
                                   const types::QASM_cbit& y) -> ExprType {
                                if (exp.op() == ast::BinaryOp::BitOr) {
                                    return types::QASM_cbit{x.bit || y.bit};
                                } else if (exp.op() == ast::BinaryOp::XOr) {
                                    return types::QASM_cbit{x.bit != y.bit};
                                } else {
                                    return types::QASM_cbit{x.bit && y.bit};
                                }
                            },
                            [](auto, auto) -> ExprType {
                                return types::QASM_none();
                            }},
                        std::get<BasicType>(v1), std::get<BasicType>(v2));
                } else if (std::holds_alternative<xt::xarray<BasicType>>(v1) &&
                           std::holds_alternative<xt::xarray<BasicType>>(v2)) {
                    auto x = std::get<xt::xarray<BasicType>>(v1);
                    auto y = std::get<xt::xarray<BasicType>>(v2);
                    if (x.shape() == y.shape()) {
                        std::vector<BasicType> result;
                        result.reserve(x.size());
                        auto it1 = x.begin();
                        auto it2 = y.begin();
                        for (; it1 != x.end() && it2 != y.end(); it1++, it2++) {
                            auto& x1 = std::get<types::QASM_cbit>(*it1);
                            auto& x2 = std::get<types::QASM_cbit>(*it2);
                            if (exp.op() == ast::BinaryOp::BitOr) {
                                result.push_back(
                                    types::QASM_cbit{x1.bit || x2.bit});
                            } else if (exp.op() == ast::BinaryOp::XOr) {
                                result.push_back(
                                    types::QASM_cbit{x1.bit != x2.bit});
                            } else {
                                result.push_back(
                                    types::QASM_cbit{x1.bit && x2.bit});
                            }
                        }
                        value_ =
                            xt::xarray<BasicType>(xt::adapt(result, x.shape()));
                    }
                }
                break; // catch None type below
            }
            case ast::BinaryOp::EQ:
            case ast::BinaryOp::NEQ:
            case ast::BinaryOp::GT:
            case ast::BinaryOp::LT:
            case ast::BinaryOp::GTE:
            case ast::BinaryOp::LTE: {
                auto x = types::get_value(v1);
                auto y = types::get_value(v2);
                bool b = std::visit(
                    [&exp](auto e1, auto e2) -> bool {
                        if (exp.op() == ast::BinaryOp::EQ) {
                            return e1 == e2;
                        } else if (exp.op() == ast::BinaryOp::NEQ) {
                            return e1 != e2;
                        } else if (exp.op() == ast::BinaryOp::GT) {
                            return e1 > e2;
                        } else if (exp.op() == ast::BinaryOp::LT) {
                            return e1 < e2;
                        } else if (exp.op() == ast::BinaryOp::GTE) {
                            return e1 >= e2;
                        } else {
                            return e1 <= e2;
                        }
                    },
                    x, y);
                value_ = types::QASM_bool{b};
                return;
            }
            case ast::BinaryOp::LeftBitShift:
            case ast::BinaryOp::RightBitShift: {
                auto shift = types::cast_to_basic(v2, types::QASM_int(-1));
                if (std::holds_alternative<BasicType>(v1)) {
                    value_ = std::visit(
                        utils::overloaded{
                            [&exp,
                             &shift](const types::QASM_int& v) -> ExprType {
                                if (exp.op() == ast::BinaryOp::LeftBitShift) {
                                    return types::QASM_int(
                                        v.width, v.is_signed,
                                        v.is_signed
                                            ? v.value << shift.value
                                            : (unsigned long long) v.value
                                                  << shift.value);
                                } else {
                                    return types::QASM_int(
                                        v.width, v.is_signed,
                                        v.is_signed
                                            ? v.value >> shift.value
                                            : (unsigned long long) v.value >>
                                                  shift.value);
                                }
                            },
                            [&exp,
                             &shift](const types::QASM_angle& v) -> ExprType {
                                // bits are little-endian, so we shift the other
                                // way
                                if (exp.op() == ast::BinaryOp::LeftBitShift) {
                                    return types::QASM_angle(
                                        right_shift(v.bits, shift.value));
                                } else {
                                    return types::QASM_angle(
                                        left_shift(v.bits, shift.value));
                                }
                            },
                            [](auto) -> ExprType {
                                return types::QASM_none();
                            }},
                        std::get<BasicType>(v1));
                } else if (std::holds_alternative<xt::xarray<BasicType>>(v1)) {
                    auto& x = std::get<xt::xarray<BasicType>>(v1);
                    std::vector<BasicType> result(x.begin(), x.end());
                    // bits are little-endian, so we shift the other way
                    if (exp.op() == ast::BinaryOp::LeftBitShift) {
                        result = right_shift(result, shift.value);
                    } else {
                        result = left_shift(result, shift.value);
                    }
                    value_ =
                        xt::xarray<BasicType>(xt::adapt(result, x.shape()));
                }
                break; // catch None type below
            }
            case ast::BinaryOp::Plus:
            case ast::BinaryOp::Minus:
            case ast::BinaryOp::Times:
            case ast::BinaryOp::Divide:
            case ast::BinaryOp::Mod:
            case ast::BinaryOp::Pow: {
                auto x = types::get_value(v1);
                auto y = types::get_value(v2);
                types::value_type val = std::visit(
                    [this, &exp](auto e1, auto e2) -> types::value_type {
                        if (exp.op() == ast::BinaryOp::Mod) {
                            // might be wrong if e2 has type uint[64]
                            return (long long) e1 % (long long) e2;
                        } else if (exp.op() == ast::BinaryOp::Pow) {
                            return std::pow(e1, e2);
                        } else if (exp.op() == ast::BinaryOp::Plus) {
                            return e1 + e2;
                        } else if (exp.op() == ast::BinaryOp::Minus) {
                            return e1 - e2;
                        } else if (exp.op() == ast::BinaryOp::Times) {
                            return e1 * e2;
                        } else {
                            if (expect_float_div_) {
                                return (double) e1 / (double) e2;
                            }
                            return e1 / e2;
                        }
                    },
                    x, y);
                value_ = std::visit(
                    utils::overloaded{[](long long v) -> BasicType {
                                          return types::QASM_int(-1, true, v);
                                      },
                                      [](unsigned long long v) -> BasicType {
                                          return types::QASM_int(-1, false, v);
                                      },
                                      [](double v) -> BasicType {
                                          return types::QASM_float{v};
                                      }},
                    val);
                return;
            }
        }
        if (std::holds_alternative<types::QASM_none>(value_)) {
            std::cerr << exp.pos()
                      << ": error : invalid operands to binary operator "
                      << exp.op() << "\n";
            throw RuntimeError();
        }
    }
    void visit(ast::UExpr& exp) override {
        exp.subexp().accept(*this);
        switch (exp.op()) {
            case ast::UnaryOp::BitNot: {
                if (std::holds_alternative<BasicType>(value_)) {
                    value_ = std::visit(
                        utils::overloaded{
                            [](const types::QASM_bool& v) -> BasicType {
                                return types::QASM_bool{!v.value};
                            },
                            [](const types::QASM_int& v) -> BasicType {
                                return types::QASM_int(v.width, v.is_signed,
                                                       ~v.value);
                            },
                            [](const types::QASM_cbit& v) -> BasicType {
                                return types::QASM_cbit{!v.bit};
                            },
                            [&exp](auto) -> BasicType {
                                std::cerr
                                    << exp.pos()
                                    << ": error : invalid operand to unary "
                                       "operator ~\n";
                                throw RuntimeError();
                            }},
                        std::get<BasicType>(value_));
                } else if (std::holds_alternative<xt::xarray<BasicType>>(
                               value_)) {
                    auto& x = std::get<xt::xarray<BasicType>>(value_);
                    std::vector<BasicType> result(x.begin(), x.end());
                    for (auto& elem : result) {
                        std::get<types::QASM_cbit>(elem).bit ^= true; // flip
                    }
                    value_ =
                        xt::xarray<BasicType>(xt::adapt(result, x.shape()));
                }
                break;
            }
            case ast::UnaryOp::LogicalNot: {
                auto tmp = types::cast_to_basic(value_, types::QASM_bool());
                value_ = types::QASM_bool{!tmp.value};
                break;
            }
            case ast::UnaryOp::Neg: {
                value_ = std::visit(
                    utils::overloaded{
                        [](const types::QASM_int& v) -> BasicType {
                            return types::QASM_int(-1, true, -v.value);
                        },
                        [](const types::QASM_float& v) -> BasicType {
                            return types::QASM_float{-v.value};
                        },
                        [&exp](auto) -> BasicType {
                            std::cerr << exp.pos()
                                      << ": error : invalid operand to unary "
                                         "operator -\n";
                            throw RuntimeError();
                        }},
                    std::get<BasicType>(value_));
                break;
            }
        }
    }
    void visit(ast::MathExpr& exp) override {
        switch (exp.op()) {
            case ast::MathOp::Arcsin:
            case ast::MathOp::Sin:
            case ast::MathOp::Arccos:
            case ast::MathOp::Cos:
            case ast::MathOp::Arctan:
            case ast::MathOp::Tan:
            case ast::MathOp::Exp:
            case ast::MathOp::Ln:
            case ast::MathOp::Sqrt: {
                exp.arg(0).accept(*this);
                auto arg = types::get_value(value_);
                double val = std::visit(
                    [&exp](auto v) -> double {
                        if (exp.op() == ast::MathOp::Arcsin) {
                            return asin(v);
                        } else if (exp.op() == ast::MathOp::Sin) {
                            return sin(v);
                        } else if (exp.op() == ast::MathOp::Arccos) {
                            return acos(v);
                        } else if (exp.op() == ast::MathOp::Cos) {
                            return cos(v);
                        } else if (exp.op() == ast::MathOp::Arctan) {
                            return atan(v);
                        } else if (exp.op() == ast::MathOp::Tan) {
                            return tan(v);
                        } else if (exp.op() == ast::MathOp::Exp) {
                            return ::exp(v);
                        } else if (exp.op() == ast::MathOp::Ln) {
                            return log(v);
                        } else {
                            return sqrt(v);
                        }
                    },
                    arg);
                value_ = types::QASM_float{val};
                return;
            }
            case ast::MathOp::Rotl:
            case ast::MathOp::Rotr: {
                exp.arg(0).accept(*this);
                auto reg = value_;
                exp.arg(1).accept(*this);
                auto shift = types::cast_to_basic(value_, types::QASM_int(-1));
                if (std::holds_alternative<BasicType>(reg)) {
                    value_ = std::visit(
                        utils::overloaded{
                            [&exp,
                             &shift](const types::QASM_angle& v) -> BasicType {
                                // bits are little-endian, so we shift the other
                                // way
                                if (exp.op() == ast::MathOp::Rotl) {
                                    return types::QASM_angle(right_rotate_shift(
                                        v.bits, shift.value));
                                } else {
                                    return types::QASM_angle(
                                        left_rotate_shift(v.bits, shift.value));
                                }
                            },
                            [&exp](auto) -> BasicType {
                                std::cerr
                                    << exp.pos()
                                    << ": error : invalid first argument to "
                                    << exp.op() << "\n";
                                throw RuntimeError();
                            }},
                        std::get<BasicType>(reg));
                } else if (std::holds_alternative<xt::xarray<BasicType>>(reg)) {
                    auto& x = std::get<xt::xarray<BasicType>>(reg);
                    std::vector<BasicType> result(x.begin(), x.end());
                    // bits are little-endian, so we shift the other way
                    if (exp.op() == ast::MathOp::Rotl) {
                        result = right_rotate_shift(result, shift.value);
                    } else {
                        result = left_rotate_shift(result, shift.value);
                    }
                    value_ =
                        xt::xarray<BasicType>(xt::adapt(result, x.shape()));
                }
                return;
            }
            case ast::MathOp::Popcount: {
                exp.arg(0).accept(*this);
                int n = 0;
                if (std::holds_alternative<BasicType>(value_)) {
                    n = std::visit(
                        utils::overloaded{
                            [](const types::QASM_angle& v) -> int {
                                int ans = 0;
                                for (bool bit : v.bits)
                                    ans += bit;
                                return ans;
                            },
                            [&exp](auto) -> int {
                                std::cerr
                                    << exp.pos()
                                    << ": error : invalid first argument to "
                                    << exp.op() << "\n";
                                throw RuntimeError();
                            }},
                        std::get<BasicType>(value_));
                } else if (std::holds_alternative<xt::xarray<BasicType>>(
                               value_)) {
                    auto& x = std::get<xt::xarray<BasicType>>(value_);
                    for (auto& i : x) {
                        n += std::get<types::QASM_cbit>(i).bit;
                    }
                }
                value_ = types::QASM_int(-1, true, n);
                return;
            }
        }
    }
    void visit(ast::CastExpr& exp) override {
        exp.subexp().accept(*this);
        auto tmp = value_;
        exp.type().accept(*this);
        types::overwrite(tmp, value_);
    }
    void visit(ast::SizeofExpr& exp) override {
        int dim = 0;
        if (exp.dim()) {
            (**exp.dim()).accept(*this);
            dim = types::cast_to_basic(value_, types::QASM_int(-1)).value;
        }
        exp.arr().accept(*this);
        std::visit(utils::overloaded{
                       [this, dim](xt::xarray<BasicType>& x) {
                           long long ans = x.shape()[dim];
                           value_ = types::QASM_int{-1, true, ans};
                       },
                       [this, dim](xt::xarray<BasicType*>& x) {
                           long long ans = x.shape()[dim];
                           value_ = types::QASM_int{-1, true, ans};
                       },
                       [&exp](auto) {
                           std::cerr
                               << exp.pos()
                               << ": error : sizeof() accepts arrays only\n";
                           throw RuntimeError();
                       }},
                   value_);
    }
    void visit(ast::FunctionCall& exp) override {
        auto func = std::get<SubroutineType>(lookup(exp.name()));

        // compute args
        std::vector<types::ExprType> args;
        for (int i = 0; i < exp.num_args(); i++) {
            if (std::holds_alternative<xt::xarray<BasicType>>(
                    func.param_types[i])) {
                expect_array_reference_ = true;
                exp.arg(i).accept(*this);
                args.push_back(std::move(value_));
                expect_array_reference_ = false;
            } else {
                args.push_back(func.param_types[i]);
                exp.arg(i).accept(*this);
                types::overwrite(value_, args.back());
            }
        }

        // store local symbols; subroutine body can only refer to globals
        std::list<std::unordered_map<ast::symbol, Type>> local_symbols;
        local_symbols.splice(local_symbols.begin(), symbol_table_,
                             symbol_table_.begin(), --symbol_table_.end());

        push_scope();

        // pass in arguments by value
        for (int i = 0; i < func.param_types.size(); i++) {
            set(func.param_names[i], args[i]);
        }

        // execute body and obtain return value
        return_value_ = types::QASM_none();
        func.body->accept(*this);
        control_flow_ = std::nullopt; // assume no end statements in body
        if (std::holds_alternative<types::QASM_none>(return_value_) &&
            !std::holds_alternative<types::QASM_none>(func.return_type)) {
            std::cerr << exp.pos()
                      << ": error : function did not return a value\n";
            throw RuntimeError();
        }
        value_ = func.return_type;
        types::overwrite(return_value_, value_);

        pop_scope();
        // put back local symbols
        symbol_table_.splice(symbol_table_.begin(), local_symbols);
    }
    void visit(ast::AccessExpr& exp) override {
        exp.exp().accept(*this);
        exp.index_op().accept(*this);
    }
    void visit(ast::ConstantExpr& exp) override {
        switch (exp.constant()) {
            case ast::Constant::Pi:
                value_ = types::QASM_float{utils::pi};
                break;
            case ast::Constant::Tau:
                value_ = types::QASM_float{utils::tau};
                break;
            case ast::Constant::Euler:
                value_ = types::QASM_float{utils::euler};
                break;
        }
    }
    void visit(ast::IntExpr& exp) override {
        value_ = types::QASM_int(-1, false, exp.value());
    }
    void visit(ast::RealExpr& exp) override {
        value_ = types::QASM_float{exp.value()};
    }
    void visit(ast::ImagExpr& exp) override {
        std::cerr << exp.pos() << ": complex types not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::BoolExpr& exp) override {
        value_ = types::QASM_bool{exp.value()};
    }
    void visit(ast::VarExpr& exp) override {
        auto& entry = std::get<ExprType>(lookup(exp.var()));
        if (expect_array_reference_) {
            // get pointer(s), if applicable
            if (std::holds_alternative<xt::xarray<BasicType>>(entry)) {
                auto& x = std::get<xt::xarray<BasicType>>(entry);
                std::vector<BasicType*> x_ref;
                x_ref.reserve(x.size());
                for (BasicType& i : x)
                    x_ref.push_back(std::addressof(i));
                value_ = xt::xarray<BasicType*>(xt::adapt(x_ref, x.shape()));
            } else if (std::holds_alternative<BasicType>(entry)) {
                value_ = std::addressof(std::get<BasicType>(entry));
            } else {
                value_ = entry;
            }
        } else {
            // dereference pointer(s), if applicable
            if (std::holds_alternative<xt::xarray<BasicType*>>(entry)) {
                auto& x = std::get<xt::xarray<BasicType*>>(entry);
                std::vector<BasicType> x_deref;
                x_deref.reserve(x.size());
                for (BasicType* i : x)
                    x_deref.push_back(*i);
                value_ = xt::xarray<BasicType>(xt::adapt(x_deref, x.shape()));
            } else if (std::holds_alternative<BasicType*>(entry)) {
                value_ = *(std::get<BasicType*>(entry));
            } else {
                value_ = entry;
            }
        }
    }
    void visit(ast::BitString& exp) override {
        std::string content = exp.text().substr(1, exp.text().length() - 2);
        std::vector<BasicType> reg{};
        // binary strings are big-endian; cregs are stored in little-endian
        std::transform(
            content.rbegin(), content.rend(), std::back_inserter(reg),
            [](char c) -> BasicType { return types::QASM_cbit{c != '0'}; });
        value_ = xt::xarray<BasicType>(xt::adapt(reg));
    }
    void visit(ast::ArrayInitExpr& exp) override {
        exp.at(0).accept(*this);
        unsigned long n = exp.size();
        if (std::holds_alternative<BasicType>(value_)) {
            auto tmp = xt::xarray<BasicType>::from_shape({n});
            tmp(0) = std::get<BasicType>(value_);
            for (int i = 1; i < n; i++) {
                exp.at(i).accept(*this);
                tmp(i) = std::get<BasicType>(value_);
            }
            value_ = std::move(tmp);
        } else if (std::holds_alternative<xt::xarray<BasicType>>(value_)) {
            std::vector<unsigned long> shape = {n};
            auto element = std::get<xt::xarray<BasicType>>(value_);
            for (auto i : element.shape())
                shape.push_back(i);
            auto tmp = xt::xarray<BasicType>::from_shape(shape);
            xt::view(tmp, 0) = std::move(element);
            for (int i = 1; i < exp.size(); i++) {
                exp.at(i).accept(*this);
                xt::view(tmp, i) =
                    std::move(std::get<xt::xarray<BasicType>>(value_));
            }
            value_ = std::move(tmp);
        } else {
            std::cerr << exp.pos()
                      << ": unable to interpret array initializer\n";
            throw RuntimeError();
        }
    }
    void visit(ast::TimeExpr& exp) override {
        std::cerr << exp.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::DurationGateExpr& exp) override {
        std::cerr << exp.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::DurationBlockExpr& exp) override {
        std::cerr << exp.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    // Statement components
    void visit(ast::QuantumMeasurement& msmt) override {
        msmt.q_arg().accept(*this);
        // always produce bit[n]; if n = 1 then can be cast to bit later
        std::vector<idx> ids;
        if (std::holds_alternative<BasicType*>(value_)) {
            ids.push_back(
                std::get<types::QASM_qubit>(*std::get<BasicType*>(value_)).id);
        } else if (std::holds_alternative<xt::xarray<BasicType*>>(value_)) {
            auto& x = std::get<xt::xarray<BasicType*>>(value_);
            std::transform(x.begin(), x.end(), std::back_inserter(ids),
                           [](BasicType* b) -> idx {
                               return std::get<types::QASM_qubit>(*b).id;
                           });
        }
        std::tie(ids, std::ignore, psi_) =
            qpp::measure_seq(psi_, ids, 2, false);

        std::vector<BasicType> result;
        std::transform(
            ids.begin(), ids.end(), std::back_inserter(result),
            [this](idx b) -> BasicType { return types::QASM_cbit{b != 0}; });
        value_ = xt::xarray<BasicType>(xt::adapt(result));
    }
    void visit(ast::ProgramBlock& block) override {
        block.foreach_stmt([this](ast::Stmt& stmt) {
            if (!control_flow_)
                stmt.accept(*this);
        });
    }
    void visit(ast::QuantumBlock& block) override {
        block.foreach_stmt([this](ast::QuantumStmt& stmt) {
            if (!control_flow_)
                stmt.accept(*this);
        });
    }
    // Statements
    void visit(ast::MeasureStmt& stmt) override {
        stmt.measurement().accept(*this);
    }
    void visit(ast::MeasureAsgnStmt& stmt) override {
        stmt.measurement().accept(*this);
        auto result = value_;
        stmt.c_arg().accept(*this);
        types::overwrite(result, value_);
    }
    void visit(ast::ExprStmt& stmt) override { stmt.exp().accept(*this); }
    void visit(ast::ResetStmt& stmt) override {
        stmt.q_arg().accept(*this);
        std::vector<idx> ids;
        if (std::holds_alternative<BasicType*>(value_)) {
            ids.push_back(
                std::get<types::QASM_qubit>(*std::get<BasicType*>(value_)).id);
        } else if (std::holds_alternative<xt::xarray<BasicType*>>(value_)) {
            auto& x = std::get<xt::xarray<BasicType*>>(value_);
            std::transform(x.begin(), x.end(), std::back_inserter(ids),
                           [](BasicType* b) -> idx {
                               return std::get<types::QASM_qubit>(*b).id;
                           });
        }
        psi_ = qpp::reset(psi_, ids);
    }
    void visit(ast::BarrierStmt& stmt) override {
        // check validity of registers, but do nothing with them
        stmt.foreach_arg([this](ast::IndexId& arg) { arg.accept(*this); });
    }
    void visit(ast::IfStmt& stmt) override {
        stmt.cond().accept(*this);
        auto cond = types::cast_to_basic(value_, types::QASM_bool());

        push_scope();
        if (cond.value)
            stmt.then().accept(*this);
        else
            stmt.els().accept(*this);
        pop_scope();
    }
    void visit(ast::BreakStmt&) override { control_flow_ = ControlFlow::Break; }
    void visit(ast::ContinueStmt&) override {
        control_flow_ = ControlFlow::Continue;
    }
    void visit(ast::ReturnStmt& stmt) override {
        std::visit(utils::overloaded{
                       [this](ast::ptr<ast::QuantumMeasurement>& qm) {
                           qm->accept(*this);
                           return_value_ = value_;
                       },
                       [this](ast::ptr<ast::Expr>& exp) {
                           exp->accept(*this);
                           return_value_ = value_;
                       },
                       [this](auto) { return_value_ = types::QASM_none(); }},
                   stmt.value());
        control_flow_ = ControlFlow::Return;
    }
    void visit(ast::EndStmt&) override { control_flow_ = ControlFlow::End; }
    void visit(ast::AliasStmt& stmt) override {
        std::vector<BasicType> result;
        stmt.foreach_reg([this, &result](ast::Expr& reg) {
            reg.accept(*this);
            if (std::holds_alternative<BasicType>(value_)) {
                result.push_back(std::get<BasicType>(value_));
            } else if (std::holds_alternative<xt::xarray<BasicType>>(value_)) {
                auto& x = std::get<xt::xarray<BasicType>>(value_);
                result.insert(result.end(), x.begin(), x.end());
            }
        });
        set(stmt.alias(), xt::xarray<BasicType>(xt::adapt(result)));
    }
    void visit(ast::AssignmentStmt& stmt) override {
        stmt.exp().accept(*this);
        auto result = value_;
        stmt.lval().accept(*this);
        types::overwrite(result, value_);
    }
    void visit(ast::PragmaStmt& stmt) override {
        std::cerr << stmt.pos() << ": pragmas not supported\n";
        throw NotImplementedError();
    }
    // Gates
    void visit(ast::CtrlModifier&) override {}
    void visit(ast::InvModifier&) override {}
    void visit(ast::PowModifier&) override {}
    void visit(ast::UGate& gate) override {
        if (!gate.modifiers().empty()) {
            std::cerr << gate.pos() << ": gate modifiers not supported\n";
            throw NotImplementedError();
        } // no modifiers -> there must be exactly one quantum argument

        expect_float_div_ = true;
        gate.theta().accept(*this);
        double theta = types::cast_to_basic(value_, types::QASM_float()).value;
        gate.phi().accept(*this);
        double phi = types::cast_to_basic(value_, types::QASM_float()).value;
        gate.lambda().accept(*this);
        double lambda = types::cast_to_basic(value_, types::QASM_float()).value;
        expect_float_div_ = false;

        gate.qarg(0).accept(*this);
        std::vector<idx> args;
        if (std::holds_alternative<BasicType*>(value_)) {
            args.push_back(
                std::get<types::QASM_qubit>(*std::get<BasicType*>(value_)).id);
        } else if (std::holds_alternative<xt::xarray<BasicType*>>(value_)) {
            auto& x = std::get<xt::xarray<BasicType*>>(value_);
            std::transform(x.begin(), x.end(), std::back_inserter(args),
                           [](BasicType* b) -> idx {
                               return std::get<types::QASM_qubit>(*b).id;
                           });
        }

        // generate the matrix
        qpp::cmat u{qpp::cmat::Zero(2, 2)};

        u << std::cos(theta / 2),
            -(std::sin(theta / 2)) * std::exp(1_i * lambda),
            std::sin(theta / 2) * std::exp(1_i * phi),
            std::cos(theta / 2) * std::exp(1_i * (phi + lambda));

        // apply the gate
        for (auto i : args) {
            psi_ = qpp::apply(psi_, u, {i});
        }
    }
    void visit(ast::GPhase& gate) override {
        std::cerr << gate.pos() << ": gphase gate not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::DeclaredGate& dgate) override {
        if (!dgate.modifiers().empty()) {
            std::cerr << dgate.pos() << ": gate modifiers not supported\n";
            throw NotImplementedError();
        } // no modifiers -> there must be exactly one quantum argument

        auto gate = std::get<GateType>(lookup(dgate.name()));

        // evaluate arguments
        std::vector<double> c_args(dgate.num_cargs());
        std::vector<std::vector<idx>> q_args(dgate.num_qargs());
        expect_float_div_ = true;
        for (int i = 0; i < dgate.num_cargs(); i++) {
            dgate.carg(i).accept(*this);
            c_args[i] = types::cast_to_basic(value_, types::QASM_float()).value;
        }
        expect_float_div_ = false;
        for (int i = 0; i < dgate.num_qargs(); i++) {
            dgate.qarg(i).accept(*this);
            if (std::holds_alternative<BasicType*>(value_)) {
                q_args[i].push_back(
                    std::get<types::QASM_qubit>(*std::get<BasicType*>(value_))
                        .id);
            } else if (std::holds_alternative<xt::xarray<BasicType*>>(value_)) {
                auto& x = std::get<xt::xarray<BasicType*>>(value_);
                std::transform(x.begin(), x.end(),
                               std::back_inserter(q_args[i]),
                               [](BasicType* b) -> idx {
                                   return std::get<types::QASM_qubit>(*b).id;
                               });
            }
        }

        // map gate across registers
        idx mapping_size = 1;
        std::vector<bool> mapped(q_args.size(), false);
        for (idx i = 0; i < q_args.size(); i++) {
            if (q_args[i].size() > 1) {
                mapped[i] = true;
                if (mapping_size > 1 && mapping_size != q_args[i].size()) {
                    std::cerr << dgate.qarg(i).pos()
                              << ": error : incompatible register length\n";
                    throw RuntimeError();
                } else {
                    mapping_size = q_args[i].size();
                }
            }
        }

        auto it = qpp::qasm::known_matrices.find(dgate.name());
        if (it != qpp::qasm::known_matrices.end()) {
            // apply the known matrix directly
            auto mat = it->second(c_args);

            // map the gate accross registers
            for (idx j = 0; j < mapping_size; j++) {
                // map virtual qubits to physical qubits
                std::vector<idx> mapped_args(q_args.size());
                for (idx i = 0; i < q_args.size(); i++) {
                    mapped_args[i] = mapped[i] ? q_args[i][j] : q_args[i][0];
                }

                // apply gate
                psi_ = qpp::apply(psi_, mat, mapped_args);
            }
        } else {
            // push classical arguments onto a new scope
            push_scope();
            for (idx i = 0; i < c_args.size(); i++) {
                set(gate.c_param_names[i], types::QASM_float{c_args[i]});
            }

            // map the gate
            for (idx j = 0; j < mapping_size; j++) {
                push_scope();
                for (idx i = 0; i < q_args.size(); i++) {
                    set(gate.q_param_names[i],
                        types::QASM_qubit{mapped[i] ? q_args[i][j]
                                                    : q_args[i][0]});
                }

                // evaluate the gate
                gate.body->accept(*this);

                pop_scope();
            }
            pop_scope();
        }
    }
    // Loops
    void visit(ast::RangeSet& set) override {
        (**set.start()).accept(*this);
        int start = types::cast_to_basic(value_, types::QASM_int(-1)).value;
        int step = 1;
        if (set.step()) {
            (**set.step()).accept(*this);
            step = types::cast_to_basic(value_, types::QASM_int(-1)).value;
            if (step == 0) {
                std::cerr << set.pos() << ": error : range step size is zero\n";
                throw RuntimeError();
            }
        }
        (**set.stop()).accept(*this);
        int stop = types::cast_to_basic(value_, types::QASM_int(-1)).value;
        loop_set_ = LoopRange(start, step, stop);
    }
    void visit(ast::ListSet& set) override { loop_set_ = std::addressof(set); }
    void visit(ast::VarSet& set) override {
        std::cerr << set.pos() << ": lists not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::ForStmt& stmt) override {
        stmt.index_set().accept(*this);

        std::visit(
            utils::overloaded{
                [this, &stmt](ast::ListSet* list_set) {
                    for (auto& exp : list_set->indices()) {
                        exp->accept(*this);
                        push_scope();
                        set(stmt.var(),
                            types::cast_to_basic(value_, types::QASM_int(-1)));
                        stmt.body().accept(*this);
                        pop_scope();
                        if (control_flow_) {
                            if (*control_flow_ == ControlFlow::Break) {
                                control_flow_ = std::nullopt;
                                break;
                            } else if (*control_flow_ ==
                                       ControlFlow::Continue) {
                                control_flow_ = std::nullopt;
                                continue;
                            } else {
                                break;
                            }
                        }
                    }
                },
                [this, &stmt](LoopRange& range) {
                    for (int i = range.start;
                         (range.step > 0) ? (i <= range.stop)
                                          : (i >= range.stop);
                         i += range.step) {
                        push_scope();
                        set(stmt.var(), types::QASM_int(-1, true, i));
                        stmt.body().accept(*this);
                        pop_scope();
                        if (control_flow_) {
                            if (*control_flow_ == ControlFlow::Break) {
                                control_flow_ = std::nullopt;
                                break;
                            } else if (*control_flow_ ==
                                       ControlFlow::Continue) {
                                control_flow_ = std::nullopt;
                                continue;
                            } else {
                                break;
                            }
                        }
                    }
                }},
            loop_set_);
    }
    void visit(ast::WhileStmt& stmt) override {
        int iterations = 0;
        while (true) {
            stmt.cond().accept(*this);
            auto cond = types::cast_to_basic(value_, types::QASM_bool());
            if (cond.value) {
                if (iterations >= WHILE_ITERATION_LIMIT) {
                    std::cerr << stmt.pos()
                              << ": error : iteration limit reached\n";
                    break;
                }
                push_scope();
                stmt.body().accept(*this);
                ++iterations;
                pop_scope();
                if (control_flow_) {
                    if (*control_flow_ == ControlFlow::Break) {
                        control_flow_ = std::nullopt;
                        break;
                    } else if (*control_flow_ == ControlFlow::Continue) {
                        control_flow_ = std::nullopt;
                        continue;
                    } else {
                        break;
                    }
                }
            } else
                break;
        }
    }
    void visit(ast::QuantumForStmt& stmt) override {
        stmt.index_set().accept(*this);

        std::visit(
            utils::overloaded{
                [this, &stmt](ast::ListSet* list_set) {
                    for (auto& exp : list_set->indices()) {
                        exp->accept(*this);
                        push_scope();
                        set(stmt.var(),
                            types::cast_to_basic(value_, types::QASM_int(-1)));
                        stmt.body().accept(*this);
                        pop_scope();
                        if (control_flow_) {
                            if (*control_flow_ == ControlFlow::Break) {
                                control_flow_ = std::nullopt;
                                break;
                            } else if (*control_flow_ ==
                                       ControlFlow::Continue) {
                                control_flow_ = std::nullopt;
                                continue;
                            } else {
                                break;
                            }
                        }
                    }
                },
                [this, &stmt](LoopRange& range) {
                    for (int i = range.start;
                         (range.step > 0) ? (i <= range.stop)
                                          : (i >= range.stop);
                         i += range.step) {
                        push_scope();
                        set(stmt.var(), types::QASM_int(-1, true, i));
                        stmt.body().accept(*this);
                        pop_scope();
                        if (control_flow_) {
                            if (*control_flow_ == ControlFlow::Break) {
                                control_flow_ = std::nullopt;
                                break;
                            } else if (*control_flow_ ==
                                       ControlFlow::Continue) {
                                control_flow_ = std::nullopt;
                                continue;
                            } else {
                                break;
                            }
                        }
                    }
                }},
            loop_set_);
    }
    void visit(ast::QuantumWhileStmt& stmt) override {
        int iterations = 0;
        while (true) {
            stmt.cond().accept(*this);
            auto cond = types::cast_to_basic(value_, types::QASM_bool());
            if (cond.value) {
                if (iterations >= WHILE_ITERATION_LIMIT) {
                    std::cerr << stmt.pos()
                              << ": error : iteration limit reached\n";
                    break;
                }
                push_scope();
                stmt.body().accept(*this);
                ++iterations;
                pop_scope();
                if (control_flow_) {
                    if (*control_flow_ == ControlFlow::Break) {
                        control_flow_ = std::nullopt;
                        break;
                    } else if (*control_flow_ == ControlFlow::Continue) {
                        control_flow_ = std::nullopt;
                        continue;
                    } else {
                        break;
                    }
                }
            } else
                break;
        }
    }
    // Timing Statements
    void visit(ast::DelayStmt& stmt) override {
        std::cerr << stmt.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::RotaryStmt& stmt) override {
        std::cerr << stmt.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::BoxStmt& stmt) override {
        std::cerr << stmt.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    // Declarations
    void visit(ast::ClassicalParam& param) override {
        param.type().accept(*this);
    }
    void visit(ast::QuantumParam& param) override {
        param.type().accept(*this);
    }
    void visit(ast::SubroutineDecl& decl) override {
        std::vector<ExprType> param_types;
        std::vector<ast::symbol> param_names;

        // signature
        for (auto& param : decl.params()) {
            param->accept(*this);
            param_types.push_back(value_);
            param_names.push_back(param->id());
        }

        // return type
        value_ = types::QASM_none();
        if (decl.return_type()) {
            (**decl.return_type()).accept(*this);
        }

        set(decl.id(), SubroutineType{param_types, param_names, value_,
                                      std::addressof(decl.body())});
    }
    void visit(ast::ExternDecl& decl) override {
        std::cerr << decl.pos() << ": externs not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::GateDecl& decl) override {
        set(decl.id(), GateType{decl.c_params(), decl.q_params(),
                                std::addressof(decl.body())});
    }
    void visit(ast::QuantumDecl& decl) override {
        decl.type().accept(*this);
        if (std::holds_alternative<BasicType>(value_)) { // qubit
            // new id is N
            set(decl.id(), types::QASM_qubit{allocated_qubits_});
            allocated_qubits_ += 1;
        } else {
            // new ids are N, N+1, ..., N+width-1
            int width = std::get<xt::xarray<BasicType>>(value_).size();
            std::vector<BasicType> ids;
            ids.reserve(width);
            while (width > 0) {
                ids.push_back(types::QASM_qubit{allocated_qubits_});
                allocated_qubits_ += 1;
                width -= 1;
            }
            set(decl.id(), xt::xarray<BasicType>(xt::adapt(ids)));
        }
    }
    void visit(ast::ClassicalDecl& decl) override {
        if (decl.is_const()) {
            set(decl.id(), types::QASM_none());
        } else {
            decl.type().accept(*this);
            set(decl.id(), value_);
            if (decl.equalsexp()) {
                auto lval = ast::IndexId::create({}, decl.id(), {});
                lval->accept(*this);
                auto tmp = value_;
                (**decl.equalsexp()).accept(*this);
                types::overwrite(value_, tmp);
            }
        }
    }
    void visit(ast::CalGrammarDecl& decl) override {
        std::cerr << decl.pos() << ": calibration not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::CalibrationDecl& decl) override {
        std::cerr << decl.pos() << ": calibration not supported\n";
        throw NotImplementedError();
    }
    // Program
    void visit(ast::Program& prog) override {
        if (prog.qubits() > 0) {
            psi_ = qpp::st.zero(prog.qubits());
        } else {
            std::cerr << "Warning: program has no qubits\n";
        }

        push_scope();

        prog.foreach_stmt([this](ast::GlobalStmt& stmt) {
            if (!control_flow_)
                stmt.accept(*this);
        });

        print_global_vars();

        pop_scope();
    }

  private:
    bool expect_float_div_ =
        false; ///< true when float (not integer) division is required
    bool expect_array_reference_ =
        false; ///< true when the argument of a function is an array type
    std::optional<ControlFlow> control_flow_ =
        std::nullopt; ///< signifies when a control statment is executed
    ExprType value_ = types::QASM_none();        ///< stores intermediate values
    ExprType return_value_ = types::QASM_none(); ///< stores return values
    std::variant<ast::ListSet*, LoopRange>
        loop_set_{}; ///< for-loop values to iterate over
    xt::xstrided_slice_vector index_entities_{}; /// index entities
    idx allocated_qubits_ = 0; ///< total number qubits from visited decls
    qpp::ket psi_{};           ///< state vector
    std::list<std::unordered_map<ast::symbol, Type>>
        symbol_table_{}; ///< a stack of symbol tables

    /**
     * \brief Enters a new scope
     */
    void push_scope() { symbol_table_.push_front({}); }

    /**
     * \brief Exits the current scope
     */
    void pop_scope() { symbol_table_.pop_front(); }

    /**
     * \brief Looks up a symbol in the symbol table
     *
     * Lookup checks in each symbol table going backwards up the enclosing
     * scopes.
     *
     * \param id Const reference to a symbol
     * \return Reference to the type of the symbol
     */
    Type& lookup(const ast::symbol& id) {
        for (auto& table : symbol_table_) {
            if (auto it = table.find(id); it != table.end()) {
                return it->second;
            }
        }
        std::cerr << ": error : undefined identifier \"" << id << "\"\n";
        throw RuntimeError();
    }

    /**
     * \brief Assigns a symbol in the current scope
     *
     * \param id Const reference to a symbol
     * \param typ The type of the symbol
     */
    void set(const ast::symbol& id, Type typ) {
        if (symbol_table_.empty())
            throw std::logic_error("No current symbol table!");

        symbol_table_.front()[id] = typ;
    }

    /**
     * \brief Prints list of global variables and their values
     */
    void print_global_vars() const {
        std::cout << "Final values:\n";
        for (const auto& v : symbol_table_.back()) {
            if (std::holds_alternative<ExprType>(v.second)) {
                auto& tmp = std::get<ExprType>(v.second);
                if (std::holds_alternative<BasicType>(tmp)) {
                    std::cout << v.first << ": " << std::get<BasicType>(tmp)
                              << "\n";
                } else if (std::holds_alternative<xt::xarray<BasicType>>(tmp)) {
                    std::cout << v.first << ":\n"
                              << std::get<xt::xarray<BasicType>>(tmp) << "\n";
                }
            }
        }
    }

    /**
     * \brief Left shift bit vector
     */
    static std::vector<bool> left_shift(std::vector<bool> bits, int shift) {
        if (shift < 0) {
            std::cerr << ": error : left shift by negative amount " << shift
                      << "\n";
            throw RuntimeError();
        } else if (shift > 0) {
            for (int i = 0; i < bits.size(); i++) {
                int index = i + shift;
                bits[i] = index >= bits.size() ? false : bits[index];
            }
        }
        return bits;
    }
    static std::vector<BasicType> left_shift(std::vector<BasicType> bits,
                                             int shift) {
        if (shift < 0) {
            std::cerr << ": error : left shift by negative amount " << shift
                      << "\n";
            throw RuntimeError();
        } else if (shift > 0) {
            for (int i = 0; i < bits.size(); i++) {
                int index = i + shift;
                bits[i] = index >= bits.size() ? types::QASM_cbit{false}
                                               : bits[index];
            }
        }
        return bits;
    }

    /**
     * \brief Left rotate shift bit vector
     */
    template <typename T>
    static std::vector<T> left_rotate_shift(std::vector<T> bits, int shift) {
        shift %= (int) bits.size();
        if (shift < 0)
            shift += bits.size();
        std::rotate(bits.begin(), bits.begin() + shift, bits.end());
        return bits;
    }

    /**
     * \brief Right shift bit vector
     */
    static std::vector<bool> right_shift(std::vector<bool> bits, int shift) {
        if (shift < 0) {
            std::cerr << ": error : right shift by negative amount " << shift
                      << "\n";
            throw RuntimeError();
        } else if (shift > 0) {
            for (int i = bits.size() - 1; i >= 0; i--) {
                int index = i - shift;
                bits[i] = index < 0 ? false : bits[index];
            }
        }
        return bits;
    }
    static std::vector<BasicType> right_shift(std::vector<BasicType> bits,
                                              int shift) {
        if (shift < 0) {
            std::cerr << ": error : right shift by negative amount " << shift
                      << "\n";
            throw RuntimeError();
        } else if (shift > 0) {
            for (int i = bits.size() - 1; i >= 0; i--) {
                int index = i - shift;
                bits[i] = index < 0 ? types::QASM_cbit{false} : bits[index];
            }
        }
        return bits;
    }

    /**
     * \brief Right rotate shift bit vector
     */
    template <typename T>
    static std::vector<T> right_rotate_shift(std::vector<T> bits, int shift) {
        return left_rotate_shift(bits, -shift);
    }
};

/**
 * \brief Executes a program
 */
inline void execute(ast::Program& prog) { Executor().run(prog); }

} // namespace tools
} // namespace qasm3tools
