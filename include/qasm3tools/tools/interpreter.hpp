/*
 * This file is part of qasm3tools.
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
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

#define WHILE_ITERATION_LIMIT 1000

namespace qasm3tools {
namespace tools {

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

/**
 * Assume little-endian ordering
 * e.g. [1, 0, 0, 0] is 1 when cast to int
 *      [1, 1, 0, 0] is 1 + 2 when cast to int
 *      etc.
 */
struct QASM_creg {
    int width;
    std::vector<bool> bits;

    QASM_creg(std::vector<bool> bits) : width(bits.size()), bits(bits) {}
    QASM_creg(int width) : width(width), bits(width, false) {}

    unsigned long long to_int() const {
        unsigned long long ans = 0;
        for (auto it = bits.rbegin(); it != bits.rend(); it++) {
            ans <<= 1;
            ans += *it;
        }
        return ans;
    }

    friend std::ostream& operator<<(std::ostream& os, const QASM_creg& r) {
        // print in big-endian order
        os << "\"";
        for (auto it = r.bits.rbegin(); it != r.bits.rend(); it++)
            os << *it;
        os << "\"";
        return os;
    }
};

struct QASM_qubit {
    int id = 0;
};

struct QASM_qreg {
    int width;
    std::vector<int> ids;

    QASM_qreg(std::vector<int> ids) : width(ids.size()), ids(ids) {}
    QASM_qreg(int width) : width(width), ids(width, 0) {}
};

using QASM_type =
    std::variant<QASM_none, QASM_bool, QASM_int, QASM_float, QASM_angle,
                 QASM_cbit, QASM_creg, QASM_qubit, QASM_qreg>;

/**
 * \brief Cast source expression to target type
 */
inline QASM_type QASM_cast(const QASM_type& source, const QASM_type& target) {
    return std::visit(
        utils::overloaded{
            /* casting from bool */
            [](const QASM_bool& s, const QASM_bool&) -> QASM_type { return s; },
            [](const QASM_bool& s, const QASM_int& t) -> QASM_type {
                return QASM_int(t.width, t.is_signed, s.value);
            },
            [](const QASM_bool& s, const QASM_float&) -> QASM_type {
                return QASM_float{(double) s.value};
            },
            [](const QASM_bool& s, const QASM_cbit&) -> QASM_type {
                return QASM_cbit{s.value};
            },
            [](const QASM_bool& s, const QASM_creg& t) -> QASM_type {
                if (t.width == 1)
                    return QASM_creg{std::vector<bool>{s.value}};
                std::cerr << "Can't cast bool to bit[" << t.width << "]!\n";
                throw RuntimeError();
            },
            /* casting from int */
            [](const QASM_int& s, const QASM_bool&) -> QASM_type {
                return QASM_bool{(bool) s.value};
            },
            [](const QASM_int& s, const QASM_int& t) -> QASM_type {
                return QASM_int(t.width, t.is_signed, s.value);
            },
            [](const QASM_int& s, const QASM_float&) -> QASM_type {
                return QASM_float{(double) s.value};
            },
            [](const QASM_int& s, const QASM_creg& t) -> QASM_type {
                if (s.width == t.width) {
                    std::vector<bool> reg(s.width);
                    long long nth_bit = 1;
                    for (auto it = reg.begin(); it != reg.end(); it++) {
                        *it = s.value & nth_bit;
                        nth_bit <<= 1;
                    }
                    return QASM_creg(std::move(reg));
                }
                std::cerr << "Can't cast int[" << s.width << "] to bit["
                          << t.width << "]!\n";
                throw RuntimeError();
            },
            /* casting from float */
            [](const QASM_float& s, const QASM_bool&) -> QASM_type {
                return QASM_bool{(bool) s.value};
            },
            [](const QASM_float& s, const QASM_int& t) -> QASM_type {
                return QASM_int(t.width, t.is_signed, s.value);
            },
            [](const QASM_float& s, const QASM_float&) -> QASM_type {
                return s;
            },
            [](const QASM_float& s, const QASM_angle& t) -> QASM_type {
                return QASM_angle(t.width, s.value);
            },
            /* casting from angle */
            [](const QASM_angle& s, const QASM_bool&) -> QASM_type {
                for (bool bit : s.bits) {
                    if (bit)
                        return QASM_bool{true};
                }
                return QASM_bool{false};
            },
            [](const QASM_angle& s, const QASM_angle& t) -> QASM_type {
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
            [](const QASM_angle& s, const QASM_creg& t) -> QASM_type {
                if (s.width == t.width)
                    return QASM_creg(s.bits);
                std::cerr << "Can't cast angle[" << s.width << "] to bit["
                          << t.width << "]!\n";
                throw RuntimeError();
            },
            /* casting from bit */
            [](const QASM_cbit& s, const QASM_bool&) -> QASM_type {
                return QASM_bool{s.bit};
            },
            [](const QASM_cbit& s, const QASM_cbit&) -> QASM_type { return s; },
            /* casting from bit[n] */
            [](const QASM_creg& s, const QASM_bool&) -> QASM_type {
                for (bool bit : s.bits) {
                    if (bit)
                        return QASM_bool{true};
                }
                return QASM_bool{false};
            },
            [](const QASM_creg& s, const QASM_int& t) -> QASM_type {
                if (s.width == t.width)
                    return QASM_int(t.width, t.is_signed, s.to_int());
                std::cerr << "Can't cast bit[" << s.width << "] to int["
                          << t.width << "]!\n";
                throw RuntimeError();
            },
            [](const QASM_creg& s, const QASM_angle& t) -> QASM_type {
                if (s.width == t.width)
                    return QASM_angle(s.bits);
                std::cerr << "Can't cast bit[" << s.width << "] to angle["
                          << t.width << "]!\n";
                throw RuntimeError();
            },
            [](const QASM_creg& s, const QASM_creg& t) -> QASM_type {
                if (s.width == t.width)
                    return s;
                std::cerr << "Can't cast bit[" << s.width << "] to bit["
                          << t.width << "]!\n";
                throw RuntimeError();
            },
            /* the rest can't be casted */
            [](const QASM_none& s, const QASM_none&) -> QASM_type { return s; },
            [](const QASM_qubit& s, const QASM_qubit&) -> QASM_type {
                return s;
            },
            [](const QASM_qreg& s, const QASM_qreg& t) -> QASM_type {
                if (s.width == t.width)
                    return s;
                std::cerr << "Can't cast qubit[" << s.width << "] to qubit["
                          << t.width << "]!\n";
                throw RuntimeError();
            },
            /* catch-all for invalid casting */
            [](auto, auto) -> QASM_type {
                std::cerr << "Invalid cast!\n";
                throw RuntimeError();
            }},
        source, target);
}

/**
 * \brief Cast but return target type instead of a std::variant
 */
template <typename T>
inline T smart_cast(const QASM_type& source, const T& target) {
    return std::get<T>(QASM_cast(source, target));
}

/**
 * \brief Get numerical value of an expression
 */
using value_type = std::variant<long long, unsigned long long, double>;
inline value_type get_value(const QASM_type& t) {
    return std::visit(
        utils::overloaded{
            [](const types::QASM_bool& v) -> value_type {
                return (long long) v.value;
            },
            [](const types::QASM_int& v) -> value_type {
                if (v.is_signed) {
                    return v.value;
                }
                return (unsigned long long) v.value;
            },
            [](const types::QASM_float& v) -> value_type { return v.value; },
            [](const types::QASM_angle& v) -> value_type {
                return v.to_float();
            },
            [](const types::QASM_cbit& v) -> value_type {
                return (long long) v.bit;
            },
            [](const types::QASM_creg& v) -> value_type { return v.to_int(); },
            [](auto) -> value_type {
                std::cerr << ": get_value called on type without a value\n";
                throw RuntimeError();
            }},
        t);
}

} // namespace types

using QASM_type = types::QASM_type;

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
        std::vector<QASM_type> param_types;   ///< function signature
        std::vector<ast::symbol> param_names; ///< parameter names
        QASM_type return_type; ///< return type (None if no return)
        ast::ProgramBlock* body;
    };

    /**
     * \brief OpenQASM types as a std::variant
     *
     * Functional-style syntax trees in C++17 as a simpler alternative
     * to inheritance hierarchy. Support is still lacking for large-scale.
     */
    using Type = std::variant<QASM_type, GateType, SubroutineType>;

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

    /**
     * \brief References to quantum or classical bits
     */
    using BitReference =
        std::variant<int, std::pair<types::QASM_angle*, int>, types::QASM_cbit*,
                     std::pair<types::QASM_creg*, int>>;

  public:
    void run(ast::Program& prog) { prog.accept(*this); }

    // Index identifiers
    void visit(ast::RangeSlice& slice) override {
        int reg_size = register_.size();
        if (reg_size == 0) {
            std::cerr << slice.pos()
                      << ": error : can't slice empty register\n";
            throw RuntimeError();
        }

        /* step size */
        int step = 1;
        if (slice.step()) {
            (**slice.step()).accept(*this);
            step = types::smart_cast(value_, types::QASM_int(-1)).value;
            if (step == 0) {
                std::cerr << slice.pos()
                          << ": error : range step size is zero\n";
                throw RuntimeError();
            }
        }
        int max_index = reg_size - 1;
        /* start = front by default; or back when step is negative */
        int start = step > 0 ? 0 : max_index;
        if (slice.start()) {
            (**slice.start()).accept(*this);
            start = types::smart_cast(value_, types::QASM_int(-1)).value;
            if (start > max_index) {
                start = max_index;
            } else if (start < -reg_size) {
                start = 0;
            } else if (start < 0) {
                start += register_.size();
            }
        }
        /* stop = back by default; or front when step is negative */
        int stop = step > 0 ? max_index : 0;
        if (slice.stop()) {
            (**slice.stop()).accept(*this);
            stop = types::smart_cast(value_, types::QASM_int(-1)).value;
            if (stop > max_index) {
                stop = max_index;
            } else if (stop < -reg_size) {
                stop = 0;
            } else if (stop < 0) {
                stop += register_.size();
            }
        }

        std::vector<BitReference> new_reg{};
        for (int i = start; (step > 0) ? (i <= stop) : (i >= stop); i += step) {
            new_reg.push_back(register_[i]);
        }
        register_ = std::move(new_reg);
    }
    void visit(ast::ListSlice& slice) override {
        std::vector<BitReference> new_reg{};
        int reg_size = register_.size();
        for (auto& exp : slice.indices()) {
            exp->accept(*this);
            int i = types::smart_cast(value_, types::QASM_int(-1)).value;
            if (i < -reg_size || i >= reg_size) {
                std::cerr << exp->pos()
                          << ": error : index is out of bounds: index " << i
                          << ", size " << reg_size << "\n";
                throw RuntimeError();
            } else if (i < 0) {
                i += reg_size;
            }
            new_reg.push_back(register_[i]);
        }
        register_ = std::move(new_reg);
    }
    void visit(ast::VarAccess& va) override {
        auto& entry = std::get<QASM_type>(lookup(va.var()));
        register_.clear();
        std::visit(
            utils::overloaded{
                [this](types::QASM_angle& x) {
                    for (int i = 0; i < x.width; i++)
                        register_.push_back(
                            std::make_pair(std::addressof(x), i));
                },
                [this](types::QASM_cbit& x) {
                    register_.push_back(std::addressof(x));
                },
                [this](types::QASM_creg& x) {
                    for (int i = 0; i < x.width; i++)
                        register_.push_back(
                            std::make_pair(std::addressof(x), i));
                },
                [this](const types::QASM_qubit& x) {
                    register_.push_back(x.id);
                },
                [this](const types::QASM_qreg& x) {
                    std::transform(x.ids.begin(), x.ids.end(),
                                   std::back_inserter(register_),
                                   [](int i) -> BitReference { return i; });
                },
                [&va](auto) {
                    std::cerr << va.pos() << ": error : not a register\n";
                    throw RuntimeError();
                }},
            entry);

        if (va.slice()) {
            (**va.slice()).accept(*this);
        }
    }
    void visit(ast::Concat& c) override {
        // get right register first
        c.rreg().accept(*this);
        auto rreg = register_;
        // append right register to left one
        c.lreg().accept(*this);
        register_.insert(register_.end(), rreg.begin(), rreg.end());
    }
    // Types
    void visit(ast::SingleDesignatorType& type) override {
        type.size().accept(*this);
        int n = std::get<types::QASM_int>(value_).value;
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
                /* not implemented */
                throw RuntimeError();
        }
    }
    void visit(ast::BitType& type) override {
        if (type.size()) {
            (**type.size()).accept(*this);
            int n = std::get<types::QASM_int>(value_).value;
            value_ = types::QASM_creg{n};
        } else {
            value_ = types::QASM_cbit();
        }
    }
    void visit(ast::ComplexType&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::QubitType& type) override {
        if (type.size()) {
            (**type.size()).accept(*this);
            int n = std::get<types::QASM_int>(value_).value;
            value_ = types::QASM_qreg{n};
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
                auto b1 = types::smart_cast(v1, types::QASM_bool());
                auto b2 = types::smart_cast(v2, types::QASM_bool());
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
                value_ = std::visit(
                    utils::overloaded{
                        [&exp](const types::QASM_bool& x,
                               const types::QASM_bool& y) -> QASM_type {
                            if (exp.op() == ast::BinaryOp::BitOr) {
                                return types::QASM_bool{x.value || y.value};
                            } else if (exp.op() == ast::BinaryOp::XOr) {
                                return types::QASM_bool{x.value != y.value};
                            } else {
                                return types::QASM_bool{x.value && y.value};
                            }
                        },
                        [&exp](const types::QASM_int& x,
                               const types::QASM_int& y) -> QASM_type {
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
                               const types::QASM_cbit& y) -> QASM_type {
                            if (exp.op() == ast::BinaryOp::BitOr) {
                                return types::QASM_cbit{x.bit || y.bit};
                            } else if (exp.op() == ast::BinaryOp::XOr) {
                                return types::QASM_cbit{x.bit != y.bit};
                            } else {
                                return types::QASM_cbit{x.bit && y.bit};
                            }
                        },
                        [&exp](const types::QASM_creg& x,
                               const types::QASM_creg& y) -> QASM_type {
                            if (x.width == y.width) {
                                std::vector<bool> reg(x.width);
                                for (int i = 0; i < x.width; i++) {
                                    if (exp.op() == ast::BinaryOp::BitOr) {
                                        reg[i] = x.bits[i] || y.bits[i];
                                    } else if (exp.op() == ast::BinaryOp::XOr) {
                                        reg[i] = x.bits[i] != y.bits[i];
                                    } else {
                                        reg[i] = x.bits[i] && y.bits[i];
                                    }
                                }
                                return types::QASM_creg(std::move(reg));
                            }
                            std::cerr
                                << exp.pos()
                                << ": error : operands to binary operator "
                                << exp.op() << " are different sizes, bit["
                                << x.width << "] and bit[" << y.width << "]\n";
                            throw RuntimeError();
                        },
                        [](auto, auto) -> QASM_type {
                            return types::QASM_none();
                        }},
                    v1, v2);
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
                auto shift = types::smart_cast(v2, types::QASM_int(-1));
                value_ = std::visit(
                    utils::overloaded{
                        [&exp, &shift](const types::QASM_int& v) -> QASM_type {
                            if (exp.op() == ast::BinaryOp::LeftBitShift) {
                                return types::QASM_int(
                                    v.width, v.is_signed,
                                    v.is_signed ? v.value << shift.value
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
                         &shift](const types::QASM_angle& v) -> QASM_type {
                            // bits are little-endian, so we shift the other way
                            if (exp.op() == ast::BinaryOp::LeftBitShift) {
                                return types::QASM_angle(
                                    right_shift(v.bits, shift.value));
                            } else {
                                return types::QASM_angle(
                                    left_shift(v.bits, shift.value));
                            }
                        },
                        [&exp, &shift](const types::QASM_creg& v) -> QASM_type {
                            // bits are little-endian, so we shift the other way
                            if (exp.op() == ast::BinaryOp::LeftBitShift) {
                                return types::QASM_creg(
                                    right_shift(v.bits, shift.value));
                            } else {
                                return types::QASM_creg(
                                    left_shift(v.bits, shift.value));
                            }
                        },
                        [](auto) -> QASM_type { return types::QASM_none(); }},
                    v1);
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
                    utils::overloaded{[](long long v) -> QASM_type {
                                          return types::QASM_int(-1, true, v);
                                      },
                                      [](unsigned long long v) -> QASM_type {
                                          return types::QASM_int(-1, false, v);
                                      },
                                      [](double v) -> QASM_type {
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
            case ast::UnaryOp::BitNot:
                value_ = std::visit(
                    utils::overloaded{
                        [](const types::QASM_bool& v) -> QASM_type {
                            return types::QASM_bool{!v.value};
                        },
                        [](const types::QASM_int& v) -> QASM_type {
                            return types::QASM_int(v.width, v.is_signed,
                                                   ~v.value);
                        },
                        [](const types::QASM_cbit& v) -> QASM_type {
                            return types::QASM_cbit{!v.bit};
                        },
                        [](const types::QASM_creg& v) -> QASM_type {
                            auto reg = v.bits;
                            std::transform(reg.begin(), reg.end(), reg.begin(),
                                           [](bool b) -> bool { return !b; });
                            return types::QASM_creg(std::move(reg));
                        },
                        [&exp](auto) -> QASM_type {
                            std::cerr << exp.pos()
                                      << ": error : invalid operand to unary "
                                         "operator ~\n";
                            throw RuntimeError();
                        }},
                    value_);
                break;
            case ast::UnaryOp::LogicalNot: {
                auto tmp = types::smart_cast(value_, types::QASM_bool());
                value_ = types::QASM_bool{!tmp.value};
                break;
            }
            case ast::UnaryOp::Neg:
                value_ = std::visit(
                    utils::overloaded{
                        [](const types::QASM_int& v) -> QASM_type {
                            return types::QASM_int(-1, true, -v.value);
                        },
                        [](const types::QASM_float& v) -> QASM_type {
                            return types::QASM_float{-v.value};
                        },
                        [&exp](auto) -> QASM_type {
                            std::cerr << exp.pos()
                                      << ": error : invalid operand to unary "
                                         "operator -\n";
                            throw RuntimeError();
                        }},
                    value_);
                break;
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
                auto shift = types::smart_cast(value_, types::QASM_int(-1));
                value_ = std::visit(
                    utils::overloaded{
                        [&exp,
                         &shift](const types::QASM_angle& v) -> QASM_type {
                            // bits are little-endian, so we shift the other way
                            if (exp.op() == ast::MathOp::Rotl) {
                                return types::QASM_angle(
                                    right_rotate_shift(v.bits, shift.value));
                            } else {
                                return types::QASM_angle(
                                    left_rotate_shift(v.bits, shift.value));
                            }
                        },
                        [&exp, &shift](const types::QASM_creg& v) -> QASM_type {
                            // bits are little-endian, so we shift the other way
                            if (exp.op() == ast::MathOp::Rotl) {
                                return types::QASM_creg(
                                    right_rotate_shift(v.bits, shift.value));
                            } else {
                                return types::QASM_creg(
                                    left_rotate_shift(v.bits, shift.value));
                            }
                        },
                        [&exp](auto) -> QASM_type {
                            std::cerr << exp.pos()
                                      << ": error : invalid first argument to "
                                      << exp.op() << "\n";
                            throw RuntimeError();
                        }},
                    reg);
                return;
            }
            case ast::MathOp::Popcount: {
                exp.arg(0).accept(*this);
                int val = std::visit(
                    utils::overloaded{
                        [](const types::QASM_angle& v) -> int {
                            int ans = 0;
                            for (bool bit : v.bits)
                                ans += bit;
                            return ans;
                        },
                        [](const types::QASM_creg& v) -> int {
                            int ans = 0;
                            for (bool bit : v.bits)
                                ans += bit;
                            return ans;
                        },
                        [&exp](auto) -> int {
                            std::cerr << exp.pos()
                                      << ": error : invalid first argument to "
                                      << exp.op() << "\n";
                            throw RuntimeError();
                        }},
                    value_);
                value_ = types::QASM_int(-1, true, val);
                return;
            }
        }
    }
    void visit(ast::CastExpr& exp) override {
        exp.type().accept(*this);
        auto tmp = value_;
        exp.subexp().accept(*this);
        value_ = types::QASM_cast(value_, tmp);
    }
    void visit(ast::FunctionCall& exp) override {
        auto& entry = std::get<SubroutineType>(lookup(exp.name()));

        // store local symbols; subroutine body can only refer to globals
        std::list<std::unordered_map<ast::symbol, Type>> local_symbols;
        local_symbols.splice(local_symbols.begin(), symbol_table_,
                             symbol_table_.begin(), --symbol_table_.end());

        push_scope();

        // pass in arguments by value
        for (int i = 0; i < entry.param_types.size(); i++) {
            exp.arg(i).accept(*this);
            set(entry.param_names[i],
                types::QASM_cast(value_, entry.param_types[i]));
        }

        // execute body and obtain return value
        return_value_ = types::QASM_none();
        entry.body->accept(*this);
        control_flow_ = std::nullopt;
        value_ = types::QASM_cast(return_value_, entry.return_type);

        pop_scope();
        // put back local symbols
        symbol_table_.splice(symbol_table_.begin(), local_symbols);
    }
    void visit(ast::AccessExpr& exp) override {
        exp.exp().accept(*this);
        auto reg = value_;
        exp.index().accept(*this);
        auto index = types::smart_cast(value_, types::QASM_int(-1));
        value_ = std::visit(
            utils::overloaded{
                [&exp, &index](const types::QASM_angle& v) -> QASM_type {
                    if (index.value < -v.width || index.value >= v.width) {
                        std::cerr << exp.pos() << ": error : index "
                                  << index.value
                                  << " is out of bounds for angle[" << v.width
                                  << "] type\n";
                        throw RuntimeError();
                    } else if (index.value < 0) {
                        index.value += v.width;
                    }
                    return types::QASM_cbit{v.bits[index.value]};
                },
                [&exp, &index](const types::QASM_creg& v) -> QASM_type {
                    if (index.value < -v.width || index.value >= v.width) {
                        std::cerr << exp.pos() << ": error : index "
                                  << index.value << " is out of bounds for bit["
                                  << v.width << "] type\n";
                        throw RuntimeError();
                    } else if (index.value < 0) {
                        index.value += v.width;
                    }
                    return types::QASM_cbit{v.bits[index.value]};
                },
                [&exp, &index](const types::QASM_qreg& v) -> QASM_type {
                    if (index.value < -v.width || index.value >= v.width) {
                        std::cerr << exp.pos() << ": error : index "
                                  << index.value
                                  << " is out of bounds for qubit[" << v.width
                                  << "] type\n";
                        throw RuntimeError();
                    } else if (index.value < 0) {
                        index.value += v.width;
                    }
                    return types::QASM_qubit{v.ids[index.value]};
                },
                [&exp](auto) -> QASM_type {
                    std::cerr << exp.pos()
                              << ": error : invalid access expression\n";
                    throw RuntimeError();
                }},
            reg);
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
    void visit(ast::ImagExpr&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::BoolExpr& exp) override {
        value_ = types::QASM_bool{exp.value()};
    }
    void visit(ast::VarExpr& exp) override {
        value_ = std::get<QASM_type>(lookup(exp.var()));
    }
    void visit(ast::StringExpr& exp) override {
        std::string content = exp.text().substr(1, exp.text().length() - 2);
        std::vector<bool> reg{};
        // binary strings are big-endian; cregs are stored in little-endian
        std::transform(content.rbegin(), content.rend(),
                       std::back_inserter(reg),
                       [](char c) -> bool { return c != '0'; });
        value_ = types::QASM_creg(std::move(reg));
    }
    void visit(ast::TimeExpr&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::DurationGateExpr&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::DurationBlockExpr&) override {
        /* not implemented */
        throw RuntimeError();
    }
    // Statement components
    void visit(ast::QuantumMeasurement&) override {
        /* not implemented (but should be) */
        throw RuntimeError();
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
    void visit(ast::MeasureStmt&) override {}
    void visit(ast::MeasureAsgnStmt&) override {}
    void visit(ast::ExprStmt& stmt) override { stmt.exp().accept(*this); }
    void visit(ast::ResetStmt&) override {}
    void visit(ast::BarrierStmt&) override {}
    void visit(ast::IfStmt& stmt) override {
        stmt.cond().accept(*this);
        auto cond = types::smart_cast(value_, types::QASM_bool());

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
        stmt.qreg().accept(*this);

        std::vector<int> reg{};
        std::transform(register_.begin(), register_.end(),
                       std::back_inserter(reg),
                       [](BitReference b) -> int { return std::get<int>(b); });
        set(stmt.alias(), types::QASM_qreg(std::move(reg)));
    }
    void visit(ast::AssignmentStmt& stmt) override {
        auto& entry = std::get<QASM_type>(lookup(stmt.var()));
        if (stmt.index()) {
            if (std::holds_alternative<types::QASM_creg>(entry)) {
                auto& reg = std::get<types::QASM_creg>(entry);
                (**stmt.index()).accept(*this);
                auto index = types::smart_cast(value_, types::QASM_int(-1));
                if (index.value < -reg.width || index.value >= reg.width) {
                    std::cerr << stmt.pos() << ": error : index " << index.value
                              << " is out of bounds for bit[" << reg.width
                              << "] type\n";
                    throw RuntimeError();
                } else if (index.value < 0) {
                    index.value += reg.width;
                }
                stmt.exp().accept(*this);
                auto result = types::smart_cast(value_, types::QASM_cbit());
                reg.bits[index.value] = result.bit;
            } else {
                std::cerr << stmt.pos() << ": error : identifier \""
                          << stmt.var()
                          << "\" cannot be indexed because it is not a "
                             "classical register type\n";
                throw RuntimeError();
            }
        } else {
            stmt.exp().accept(*this);
            entry = types::QASM_cast(value_, entry);
        }
    }
    void visit(ast::PragmaStmt&) override {
        /* not implemented */
        throw RuntimeError();
    }
    // Gates
    void visit(ast::CtrlModifier&) override {}
    void visit(ast::InvModifier&) override {}
    void visit(ast::PowModifier&) override {}
    void visit(ast::UGate&) override {}
    void visit(ast::GPhase&) override {}
    void visit(ast::DeclaredGate&) override {}
    // Loops
    void visit(ast::RangeSet& set) override {
        (**set.start()).accept(*this);
        int start = types::smart_cast(value_, types::QASM_int(-1)).value;
        int step = 1;
        if (set.step()) {
            (**set.step()).accept(*this);
            step = types::smart_cast(value_, types::QASM_int(-1)).value;
            if (step == 0) {
                std::cerr << set.pos() << ": error : range step size is zero\n";
                throw RuntimeError();
            }
        }
        (**set.stop()).accept(*this);
        int stop = types::smart_cast(value_, types::QASM_int(-1)).value;
        loop_set_ = LoopRange(start, step, stop);
    }
    void visit(ast::ListSet& set) override { loop_set_ = std::addressof(set); }
    void visit(ast::VarSet&) override {
        /* not implemented (no list types yet) */
        throw RuntimeError();
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
                            types::smart_cast(value_, types::QASM_int(-1)));
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
            auto cond = types::smart_cast(value_, types::QASM_bool());
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
                            types::smart_cast(value_, types::QASM_int(-1)));
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
            auto cond = types::smart_cast(value_, types::QASM_bool());
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
    void visit(ast::DelayStmt&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::RotaryStmt&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::BoxStmt&) override {
        /* not implemented */
        throw RuntimeError();
    }
    // Declarations
    void visit(ast::ClassicalParam& param) override {
        param.type().accept(*this);
    }
    void visit(ast::QuantumParam& param) override {
        param.type().accept(*this);
    }
    void visit(ast::SubroutineDecl& decl) override {
        std::vector<QASM_type> param_types;
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
    void visit(ast::ExternDecl&) override {
        /* not implemented */
        throw RuntimeError();
    }
    void visit(ast::GateDecl& decl) override {
        set(decl.id(), GateType{decl.c_params(), decl.q_params(),
                                std::addressof(decl.body())});
    }
    void visit(ast::QuantumDecl& decl) override {
        decl.type().accept(*this);
        if (std::holds_alternative<types::QASM_qreg>(value_)) {
            auto reg = std::get<types::QASM_qreg>(value_);
            // new ids are N, N+1, ..., N+width-1
            std::vector<int> ids(reg.width);
            std::iota(ids.begin(), ids.end(), qubits_.size());
            set(decl.id(), types::QASM_qreg(std::move(ids)));
            // add kets
            qubits_.resize(qubits_.size() + reg.width, qpp::st.z0);
        } else { // qubit
            // new id is N
            set(decl.id(), types::QASM_qubit{(int) qubits_.size()});
            // add ket
            qubits_.push_back(qpp::st.z0);
        }
    }
    void visit(ast::ClassicalDecl& decl) override {
        if (decl.is_const()) {
            set(decl.id(), types::QASM_none());
        } else {
            decl.type().accept(*this);
            auto tmp = value_;
            if (decl.equalsexp()) {
                (**decl.equalsexp()).accept(*this);
                tmp = types::QASM_cast(value_, tmp);
            }
            set(decl.id(), tmp);
        }
    }
    void visit(ast::CalGrammarDecl&) override {
        /* not implemented (calgrammars not specified yet) */
        throw RuntimeError();
    }
    void visit(ast::CalibrationDecl&) override {
        /* not implemented (calgrammars not specified yet) */
        throw RuntimeError();
    }
    // Program
    void visit(ast::Program& prog) override {
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
    std::optional<ControlFlow> control_flow_ =
        std::nullopt; ///< signifies when a control statment is executed
    QASM_type value_ = types::QASM_none(); ///< stores intermediate values
    QASM_type return_value_ = types::QASM_none(); ///< stores return values
    std::variant<ast::ListSet*, LoopRange>
        loop_set_{}; ///< for-loop values to iterate over
    /* ints are qubit ids; bool pointers are classical bits */
    std::vector<BitReference> register_{}; ///< stores intermediate registers
    std::vector<qpp::ket> qubits_{};       ///< all quantum bits
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
            if (std::holds_alternative<QASM_type>(v.second)) {
                std::visit(utils::overloaded{
                               [&v](const types::QASM_bool& val) {
                                   std::cout << v.first << ": " << val << "\n";
                               },
                               [&v](const types::QASM_int& val) {
                                   std::cout << v.first << ": " << val << "\n";
                               },
                               [&v](const types::QASM_float& val) {
                                   std::cout << v.first << ": " << val << "\n";
                               },
                               [&v](const types::QASM_angle& val) {
                                   std::cout << v.first << ": " << val << "\n";
                               },
                               [&v](const types::QASM_cbit& val) {
                                   std::cout << v.first << ": " << val << "\n";
                               },
                               [&v](const types::QASM_creg& val) {
                                   std::cout << v.first << ": " << val << "\n";
                               },
                               [](auto val) {}},
                           std::get<QASM_type>(v.second));
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

    /**
     * \brief Left rotate shift bit vector
     */
    static std::vector<bool> left_rotate_shift(std::vector<bool> bits,
                                               int shift) {
        shift %= bits.size();
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

    /**
     * \brief Right rotate shift bit vector
     */
    static std::vector<bool> right_rotate_shift(std::vector<bool> bits,
                                                int shift) {
        return left_rotate_shift(bits, -shift);
    }
};

/**
 * \brief Executes a program
 */
inline void execute(ast::Program& prog) { Executor().run(prog); }

} // namespace tools
} // namespace qasm3tools
