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
 * \file qasm3tools/tools/interpreter.hpp
 * \brief OpenQASM 3 program interpreter
 */

#ifndef QASM3TOOLS_TOOLS_INTERPRETER_HPP_
#define QASM3TOOLS_TOOLS_INTERPRETER_HPP_

#include <algorithm>
#include <climits>
#include <cmath>
#include <list>
#include <numeric>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <xtensor/xadapt.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xbuilder.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xvectorize.hpp>
#include <xtensor/xview.hpp>

#include "../ast/ast.hpp"
#include "../ast/visitor.hpp"
#include "../utils/angle.hpp"
#include "../utils/templates.hpp"

#include "qpp/qpp.h"

#include "../parser/parser.hpp"

#define WHILE_ITERATION_LIMIT 1000

namespace std {
/**
 * \brief Hash function for gate calls
 *
 * Allows gate calls to be used as keys in std::unordered_map.
 * Implementation and magic numbers taken from boost::hash_combine.
 */
template <>
struct hash<std::pair<qasmtools::ast::symbol, std::vector<double>>> {
    std::size_t operator()(
        const std::pair<qasmtools::ast::symbol, std::vector<double>>& k) const {
        std::size_t lhs = std::hash<qasmtools::ast::symbol>{}(k.first);
        for (auto& x : k.second) {
            lhs ^=
                std::hash<double>{}(x) + 0x9e3779b9 + (lhs << 6) + (lhs >> 2);
        }
        return lhs;
    }
};
} /* namespace std */

namespace qpp {
/**
 * \brief Copied from qpp::Gates::GATE()
 */
template <typename Derived>
dyn_mat<typename Derived::Scalar> GATE(const Eigen::MatrixBase<Derived>& A,
                                       const std::vector<idx>& target,
                                       const std::vector<idx>& dims) {
    const dyn_mat<typename Derived::Scalar>& rA = A.derived();

    // EXCEPTION CHECKS

    // check matrix zero-size
    if (!internal::check_nonzero_size(rA)) {
        throw exception::ZeroSize("qpp::Gates::GATE()", "A");
    }

    // check square matrix
    if (!internal::check_square_mat(rA)) {
        throw exception::MatrixNotSquare("qpp::Gates::GATE()", "A");
    }

    // check zero-size
    if (target.empty()) {
        throw exception::ZeroSize("qpp::Gates::GATE()", "target");
    }

    // check that dims is a valid dimension vector
    if (!internal::check_dims(dims)) {
        throw exception::DimsInvalid("qpp::Gates::GATE()", "dims");
    }

    // check that target is valid w.r.t. dims
    if (!internal::check_subsys_match_dims(target, dims)) {
        throw exception::SubsysMismatchDims("qpp::Gates::GATE()",
                                            "dims/target");
    }

    // check that target list match the dimension of the matrix
    using Index = typename dyn_mat<typename Derived::Scalar>::Index;

    idx DA = 1;
    for (idx elem : target) {
        DA *= dims[elem];
    }

    if (rA.rows() != static_cast<Index>(DA)) {
        throw exception::MatrixMismatchSubsys("qpp::Gates::GATE()",
                                              "A/dims/target");
    }

    // END EXCEPTION CHECKS

    // Use static allocation for speed!
    idx Cdims[internal::maxn];
    idx midx_row[internal::maxn];
    idx midx_col[internal::maxn];

    idx CdimsA[internal::maxn];
    idx midxA_row[internal::maxn];
    idx midxA_col[internal::maxn];

    idx CdimsA_bar[internal::maxn];
    idx Csubsys_bar[internal::maxn];
    idx midx_bar[internal::maxn];

    idx n = dims.size();
    idx n_gate = target.size();
    idx n_subsys_bar = n - target.size();

    // compute the complementary subsystem of ctrlgate w.r.t. dims
    std::vector<idx> subsys_bar = complement(target, n);

    idx D = prod(dims);
    idx Dsubsys_bar = 1;
    for (idx elem : subsys_bar) {
        Dsubsys_bar *= dims[elem];
    }

    std::copy(std::begin(subsys_bar), std::end(subsys_bar),
              std::begin(Csubsys_bar));

    for (idx k = 0; k < n; ++k) {
        midx_row[k] = midx_col[k] = 0;
        Cdims[k] = dims[k];
    }

    for (idx k = 0; k < n_subsys_bar; ++k) {
        CdimsA_bar[k] = dims[subsys_bar[k]];
        midx_bar[k] = 0;
    }

    for (idx k = 0; k < n_gate; ++k) {
        midxA_row[k] = midxA_col[k] = 0;
        CdimsA[k] = dims[target[k]];
    }

    dyn_mat<typename Derived::Scalar> result =
        dyn_mat<typename Derived::Scalar>::Identity(D, D);

    // run over the complement indexes
    for (idx i = 0; i < Dsubsys_bar; ++i) {
        // get the complement row multi-index
        internal::n2multiidx(i, n_subsys_bar, CdimsA_bar, midx_bar);

        // run over the target row multi-index
        for (idx a = 0; a < DA; ++a) {
            // get the target row multi-index
            internal::n2multiidx(a, n_gate, CdimsA, midxA_row);

            // construct the result row multi-index

            // first the target part
            for (idx k = 0; k < n_gate; ++k) {
                midx_row[target[k]] = midxA_row[k];
            }

            // then the complement part (equal for column)
            for (idx k = 0; k < n_subsys_bar; ++k) {
                midx_row[Csubsys_bar[k]] = midx_col[Csubsys_bar[k]] =
                    midx_bar[k];
            }

            // run over the target column multi-index
            for (idx b = 0; b < DA; ++b) {
                // get the target column multi-index
                internal::n2multiidx(b, n_gate, CdimsA, midxA_col);

                // construct the result column multi-index
                for (idx k = 0; k < n_gate; ++k) {
                    midx_col[target[k]] = midxA_col[k];
                }

                // finally write the values
                result(internal::multiidx2n(midx_row, n, Cdims),
                       internal::multiidx2n(midx_col, n, Cdims)) = rA(a, b);
            }
        }
    }

    return result;
}

/**
 * \brief Copied from qpp::Gates::GATE()
 */
template <typename Derived>
dyn_mat<typename Derived::Scalar> GATE(const Eigen::MatrixBase<Derived>& A,
                                       const std::vector<idx>& target, idx n,
                                       idx d = 2) {
    // EXCEPTION CHECKS

    // check valid local dimension
    if (d == 0) {
        throw exception::DimsInvalid("qpp::Gates::GATE()", "d");
    }
    // END EXCEPTION CHECKS

    return GATE(A, target, std::vector<idx>(n, d));
}
} /* namespace qpp */

namespace qasm3tools {
namespace tools {

using idx = qpp::idx;
using cplx = qpp::cplx;

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
        normalize();
    }

    void normalize() {
        // mod by 2^width
        if (width > 0 && width < 64) {
            const long long maxbits = 1LL << width;
            value %= maxbits;
            if (!is_signed && value < 0) {
                // unsigned means nonnegative
                value += maxbits;
            } else if (is_signed) {
                const long long half_maxbits = maxbits >> 1;
                // range is [-2^(width-1), 2^(width-1)-1]
                if (value >= half_maxbits) {
                    value -= maxbits;
                } else if (value < -half_maxbits) {
                    value += maxbits;
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const QASM_int& i) {
        if (!i.is_signed && i.width == 64) {
            return os << (unsigned long long)i.value;
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
            if (*it) {
                ans += tmp;
            }
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

struct QASM_complex {
    cplx value = 0;

    friend std::ostream& operator<<(std::ostream& os, const QASM_complex& c) {
        return os << c.value.real() << (c.value.imag() < 0 ? "" : "+")
                  << c.value.imag() << "im";
    }
};

struct QASM_qubit {
    idx id = 0;

    friend std::ostream& operator<<(std::ostream& os, const QASM_qubit& q) {
        return os << "$" << q.id;
    }
};

/**
 * \brief OpenQASM non-array types as a std::variant
 */
using BasicType = std::variant<QASM_bool, QASM_int, QASM_float, QASM_angle,
                               QASM_cbit, QASM_complex, QASM_qubit>;

std::ostream& operator<<(std::ostream& os, const BasicType& exp) {
    std::visit([&os](auto&& arg) { os << arg; }, exp);
    return os;
}

/**
 * \brief Reference to a bit in an integer or angle
 */
class BitReference {
    using RefType = std::variant<std::monostate, QASM_int*, QASM_angle*>;
    RefType ref_; ///< integer/angle pointer
    int index_;   ///< index of the bit

  public:
    // default constructor needed for xt::xarray
    BitReference() : ref_(std::monostate()) {}
    BitReference(RefType ref, int index) : ref_(ref), index_(index) {}

    virtual void assign(bool value) {
        std::visit(utils::overloaded{[this, value](QASM_int* ref) {
                                         if (value) {
                                             ref->value |= 1LL << index_;
                                         } else {
                                             ref->value &= ~(1LL << index_);
                                         }
                                         ref->normalize();
                                     },
                                     [this, value](QASM_angle* ref) {
                                         ref->bits[index_] = value;
                                     },
                                     [](auto) {
                                         std::cerr << "Invalid BitReference!\n";
                                         throw RuntimeError();
                                     }},
                   ref_);
    }
};

/**
 * \brief OpenQASM expression types as a std::variant
 *
 * BasicType and xt::xarray<BasicType> are used for computing most expressions.
 *
 * BasicType* and BitReference are used as references and should only be used
 * when computing the left-hand side of an assignment (including measurements).
 * Exception: xt::xarray<BasicType*> is used when passing an array into a
 * subroutine, because in that case the array is passed by reference.
 */
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
                return QASM_int{t.width, t.is_signed, s.value};
            },
            [](const QASM_bool& s, const QASM_float&) -> BasicType {
                return QASM_float{(double)s.value};
            },
            [](const QASM_bool& s, const QASM_cbit&) -> BasicType {
                return QASM_cbit{s.value};
            },
            [](const QASM_bool& s, const QASM_complex&) -> BasicType {
                return QASM_complex{(cplx)s.value};
            },
            /* casting from int */
            [](const QASM_int& s, const QASM_bool&) -> BasicType {
                return QASM_bool{(bool)s.value};
            },
            [](const QASM_int& s, const QASM_int& t) -> BasicType {
                return QASM_int{t.width, t.is_signed, s.value};
            },
            [](const QASM_int& s, const QASM_float&) -> BasicType {
                return QASM_float{(double)s.value};
            },
            [](const QASM_int& s, const QASM_complex&) -> BasicType {
                return QASM_complex{(cplx)s.value};
            },
            /* casting from float */
            [](const QASM_float& s, const QASM_bool&) -> BasicType {
                return QASM_bool{(bool)s.value};
            },
            [](const QASM_float& s, const QASM_int& t) -> BasicType {
                return QASM_int{t.width, t.is_signed, (long long)s.value};
            },
            [](const QASM_float& s, const QASM_float&) -> BasicType {
                return s;
            },
            [](const QASM_float& s, const QASM_angle& t) -> BasicType {
                return QASM_angle{t.width, s.value};
            },
            [](const QASM_float& s, const QASM_complex&) -> BasicType {
                return QASM_complex{(cplx)s.value};
            },
            /* casting from angle */
            [](const QASM_angle& s, const QASM_bool&) -> BasicType {
                for (bool bit : s.bits) {
                    if (bit) {
                        return QASM_bool{true};
                    }
                }
                return QASM_bool{false};
            },
            [](const QASM_angle& s, const QASM_float&) -> BasicType {
                return QASM_float{s.to_float()};
            },
            [](const QASM_angle& s, const QASM_angle& t) -> BasicType {
                if (s.width == t.width) {
                    return s;
                } else if (s.width > t.width) {
                    // truncate
                    return QASM_angle{std::vector<bool>(
                        s.bits.begin() + (s.width - t.width), s.bits.end())};
                } else {
                    // pad with zeros
                    std::vector<bool> ang(t.width - s.width, false);
                    ang.insert(ang.end(), s.bits.begin(), s.bits.end());
                    return QASM_angle{std::move(ang)};
                }
            },
            /* casting from bit */
            [](const QASM_cbit& s, const QASM_bool&) -> BasicType {
                return QASM_bool{s.bit};
            },
            [](const QASM_cbit& s, const QASM_int& t) -> BasicType {
                return QASM_int{t.width, t.is_signed, s.bit};
            },
            [](const QASM_cbit& s, const QASM_cbit&) -> BasicType { return s; },
            /* casting from complex */
            [](const QASM_complex& s, const QASM_complex&) -> BasicType {
                return s;
            },
            /* the rest can't be cast */
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

/* basic -> basic assignment */
inline void overwrite_help(const BasicType& s, BasicType& t) {
    t = basic_cast(s, t);
}
/* array -> basic assignment */
inline void overwrite_help(const xt::xarray<BasicType>& s, BasicType& t) {
    std::visit(
        utils::overloaded{
            [&s](QASM_int& v) {
                if (s.size() == v.width) {
                    unsigned long long ans = 0;
                    for (auto it = s.rbegin(); it != s.rend(); it++) {
                        ans <<= 1;
                        ans += smart_cast(*it, QASM_cbit{}).bit;
                    }
                    v = QASM_int{v.width, v.is_signed, (long long)ans};
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
                                       return smart_cast(c, QASM_cbit{}).bit;
                                   });
                    v = QASM_angle{std::move(bits)};
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
/* basic -> array assignment */
inline void overwrite_help(const BasicType& s, xt::xarray<BasicType*>& t) {
    std::visit(
        utils::overloaded{
            [&t](const QASM_int& v) {
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
            [&t](const QASM_angle& v) {
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
            [&t](const QASM_cbit& v) {
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
 * \brief Assign source expression to target while preserving target's type
 */
inline void overwrite(const ExprType& source, ExprType& target) {
    return std::visit(
        utils::overloaded{
            /* basic -> basic */
            [](const BasicType& s, BasicType* t) { overwrite_help(s, *t); },
            /* array -> basic */
            [](const xt::xarray<BasicType>& s, BasicType* t) {
                overwrite_help(s, *t);
            },
            /* basic -> array */
            [](const BasicType& s, xt::xarray<BasicType*>& t) {
                overwrite_help(s, t);
            },
            /* array -> array */
            [](const xt::xarray<BasicType>& s, xt::xarray<BasicType*>& t) {
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
            /* assigning to bits of integer/angle */
            [](const BasicType& s, BitReference& t) {
                t.assign(smart_cast(s, QASM_cbit{}).bit);
            },
            [](const xt::xarray<BasicType>& s, BitReference& t) {
                if (s.size() == 1) {
                    t.assign(smart_cast(*s.begin(), QASM_cbit{}).bit);
                    return;
                }
                std::cerr << "Failed to assign bit array to BitReference\n";
                throw RuntimeError();
            },
            [](const xt::xarray<BasicType>& s, xt::xarray<BitReference>& t) {
                if (s.shape() != t.shape()) {
                    std::cerr << "Overwrite: slicing shape mismatch!\n";
                    throw RuntimeError();
                }
                auto it = t.begin();
                auto s_it = s.begin();
                for (; it != t.end() && s_it != s.end(); it++, s_it++) {
                    it->assign(smart_cast(*s_it, QASM_cbit{}).bit);
                }
            },
            /* catch-all for invalid overwrite */
            [](auto, auto) {
                std::cerr << "Overwrite: target is not an lvalue!\n";
                throw RuntimeError();
            }},
        source, target);
}

/**
 * \brief Cast expression to a basic type
 */
inline BasicType cast_to_basic(const ExprType& source, BasicType target) {
    std::visit(utils::overloaded{[&target](const BasicType& s) {
                                     return overwrite_help(s, target);
                                 },
                                 [&target](const xt::xarray<BasicType>& s) {
                                     return overwrite_help(s, target);
                                 },
                                 [](auto) {
                                     std::cerr << ": failed cast_to_basic()\n";
                                     throw RuntimeError();
                                 }},
               source);
    return target;
}

/**
 * \brief Cast expression to a basic type and return target type
 */
template <typename T>
inline T smart_cast_to_basic(const ExprType& source, T target) {
    return std::get<T>(cast_to_basic(source, target));
}

using value_type = std::variant<long long, unsigned long long, double, cplx>;

/**
 * \brief Get numerical value of a non-array expression
 */
inline value_type get_value_help(const BasicType& t) {
    return std::visit(
        utils::overloaded{
            [](const QASM_bool& v) -> value_type { return (long long)v.value; },
            [](const QASM_int& v) -> value_type {
                if (v.is_signed) {
                    return v.value;
                }
                return (unsigned long long)v.value;
            },
            [](const QASM_float& v) -> value_type { return v.value; },
            [](const QASM_angle& v) -> value_type { return v.to_float(); },
            [](const QASM_cbit& v) -> value_type { return (long long)v.bit; },
            [](const QASM_complex& v) -> value_type { return v.value; },
            [](auto) -> value_type {
                std::cerr << ": get_value called on type without a value\n";
                throw RuntimeError();
            }},
        t);
}
/**
 * \brief Get numerical value of a classical register (by converting to int)
 */
inline value_type get_value_help(const xt::xarray<BasicType>& s) {
    unsigned long long ans = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
        ans <<= 1;
        ans += smart_cast(*it, QASM_cbit{}).bit;
    }
    return ans;
}
/**
 * \brief Get numerical value of an expression
 */
inline value_type get_value(const ExprType& x) {
    return std::visit(
        utils::overloaded{
            [](const BasicType& v) -> value_type { return get_value_help(v); },
            [](const xt::xarray<BasicType>& v) -> value_type {
                return get_value_help(v);
            },
            [](auto) -> value_type {
                std::cerr << ": get_value called on type without a value\n";
                throw RuntimeError();
            }},
        x);
}
/**
 * \brief Convert numerical value to a basic expression
 */
inline BasicType value_to_basictype(value_type val) {
    return std::visit(
        utils::overloaded{[](long long v) -> BasicType {
                              return QASM_int{-1, true, v};
                          },
                          [](unsigned long long v) -> BasicType {
                              return QASM_int{-1, false, (long long)v};
                          },
                          [](double v) -> BasicType { return QASM_float{v}; },
                          [](cplx v) -> BasicType { return QASM_complex{v}; }},
        val);
}

/**
 * \brief Convert integer/angle reference to a bit array reference
 */
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
            creg(j) = BitReference(std::addressof(i), j);
        }
        return creg;
    } else if (std::holds_alternative<QASM_angle>(*type)) {
        auto& a = std::get<QASM_angle>(*type);
        auto creg = xt::xarray<BitReference>::from_shape(
            {static_cast<unsigned long>(a.width)});
        for (int j = 0; j < a.width; j++) {
            creg(j) = BitReference(std::addressof(a), j);
        }
        return creg;
    }
    std::cerr << ": error : to_creg_ref() : basic type cannot be indexed\n";
    throw RuntimeError();
}

/**
 * \brief Convert integer/angle expression to a bit array expression
 */
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

} /* namespace types */

using BasicType = types::BasicType;
using ExprType = types::ExprType;

using cmat = qpp::cmat;

/**
 * \brief Table of computed matrices. Maps [gatename, {args}] -> cmat
 */
static std::unordered_map<std::pair<ast::symbol, std::vector<double>>, cmat>
    known_matrices{};

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
        ast::ProgramBlock* body;
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

    /**
     * \brief Subsystem information used to compute gate matrices
     *
     * Example: gate ccx a, b, c { <body> }
     * Then dims = 3 and ids = {{"a", 0}, {"b", 1}, {"c", 2}}
     */
    struct Subsystem {
        idx dims;                                 ///< number of dimensions
        std::unordered_map<ast::symbol, idx> ids; ///< 0-based qubit indices
    };

    /**
     * \brief Apply gate modifiers to the matrix_ member. Then:
     *
     * If we are computing a gate matrix, then we need to take a product of
     * matrices. prev_matrix is the product of the matrices of all quantum
     * gates preceding this one, so we multiply on the left by the new matrix.
     *
     * Otherwise, we apply the gate to the quantum arguments.
     */
    void apply_with_modifiers(ast::Gate& gate, const cmat& prev_matrix) {
        // apply modifiers from innermost to outermost (modifies matrix_)
        for (auto it = gate.modifiers().rbegin(); it != gate.modifiers().rend();
             it++) {
            (**it).accept(*this);
        }
        if (subsystem_) { // we are in the middle of computing a gate matrix
            // get quantum argument indices within the subsystem
            std::vector<idx> ids;
            for (int i = 0; i < gate.num_qargs(); i++) {
                auto it = subsystem_->ids.find(gate.qarg(i).var());
                if (it != subsystem_->ids.end()) {
                    ids.push_back(it->second);
                } else {
                    std::cerr << gate.qarg(i).pos() << ": error : variable '"
                              << gate.qarg(i).var()
                              << "' not accessible from this scope\n";
                    throw RuntimeError();
                }
            }
            // multiply original matrix by the proper gate matrix
            matrix_ = qpp::GATE(matrix_, ids, subsystem_->dims) * prev_matrix;
        } else { // apply the gate
            // get quantum arguments
            std::vector<std::vector<idx>> q_args(gate.num_qargs());
            for (int i = 0; i < gate.num_qargs(); i++) {
                gate.qarg(i).accept(*this);
                if (std::holds_alternative<BasicType*>(value_)) {
                    q_args[i].push_back(std::get<types::QASM_qubit>(
                                            *std::get<BasicType*>(value_))
                                            .id);
                } else if (std::holds_alternative<xt::xarray<BasicType*>>(
                               value_)) {
                    auto& x = std::get<xt::xarray<BasicType*>>(value_);
                    std::transform(
                        x.begin(), x.end(), std::back_inserter(q_args[i]),
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
                        std::cerr << gate.qarg(i).pos()
                                  << ": error : incompatible register length\n";
                        throw RuntimeError();
                    } else {
                        mapping_size = q_args[i].size();
                    }
                }
            }
            for (idx j = 0; j < mapping_size; j++) {
                // map virtual qubits to physical qubits
                std::vector<idx> mapped_args(q_args.size());
                for (idx i = 0; i < q_args.size(); i++) {
                    mapped_args[i] = mapped[i] ? q_args[i][j] : q_args[i][0];
                }

                // apply gate
                psi_ = qpp::apply(psi_, matrix_, mapped_args);
            }
        }
    }

  public:
    explicit Executor(std::ostream& os) : os_(os) {}

    void run(ast::Program& prog, std::list<std::string> inputs) {
        if (prog.inputs() != inputs.size()) {
            std::cerr << prog.pos() << ": error : expected " << prog.inputs()
                      << " input expressions, but got " << inputs.size()
                      << "\n";
            throw RuntimeError();
        }
        inputs_ = std::move(inputs);
        outputs_.clear();
        prog.accept(*this);
    }

    // Index identifiers
    void visit(ast::SingleIndex& index) override {
        index.index().accept(*this);
        auto val = types::smart_cast_to_basic(value_, types::QASM_int{-1});
        index_entities_.push_back(val.value);
    }
    void visit(ast::RangeIndex& index) override {
        using namespace xt::placeholders;
        types::QASM_int start{-1, true, INT_MAX};
        types::QASM_int step{-1, true, INT_MAX};
        types::QASM_int stop{-1, true, INT_MAX};
        if (index.start()) {
            (**index.start()).accept(*this);
            start = types::smart_cast_to_basic(value_, types::QASM_int{-1});
        }
        if (index.step()) {
            (**index.step()).accept(*this);
            step = types::smart_cast_to_basic(value_, types::QASM_int{-1});
            if (step.value == 0) {
                std::cerr << index.pos()
                          << ": error : range step size is zero\n";
                throw RuntimeError();
            }
        }
        if (index.stop()) {
            (**index.stop()).accept(*this);
            stop = types::smart_cast_to_basic(value_, types::QASM_int{-1});
        }
        int a = start.value, c = step.value, b = stop.value;
        if (a == INT_MAX && b == INT_MAX && c == INT_MAX) {
            index_entities_.push_back(xt::all());
        } else if (a == INT_MAX && b == INT_MAX) {
            index_entities_.push_back(xt::range(_, _, c));
        } else if (a == INT_MAX && c == INT_MAX) {
            index_entities_.push_back(xt::range(_, b));
        } else if (b == INT_MAX && c == INT_MAX) {
            index_entities_.push_back(xt::range(a, _));
        } else if (a == INT_MAX) {
            index_entities_.push_back(xt::range(_, b, c));
        } else if (b == INT_MAX) {
            index_entities_.push_back(xt::range(a, _, c));
        } else if (c == INT_MAX) {
            index_entities_.push_back(xt::range(a, b));
        } else {
            index_entities_.push_back(xt::range(a, b, c));
        }
    }
    void visit(ast::IndexEntityList& indices) override {
        // save array
        auto tmp = std::move(value_);
        // convert integer/angle to creg
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
                    check_index_entities_in_bounds(x, index_entities_);
                    xt::xarray<BasicType> tmp =
                        xt::strided_view(x, index_entities_);
                    if (tmp.dimension() == 0) {
                        value_ = *tmp.begin();
                    } else {
                        value_ = std::move(tmp);
                    }
                },
                [this](xt::xarray<BasicType*>& x) {
                    check_index_entities_in_bounds(x, index_entities_);
                    xt::xarray<BasicType*> tmp =
                        xt::strided_view(x, index_entities_);
                    if (tmp.dimension() == 0) {
                        value_ = *tmp.begin();
                    } else {
                        value_ = std::move(tmp);
                    }
                },
                [this](xt::xarray<types::BitReference>& x) {
                    check_index_entities_in_bounds(x, index_entities_);
                    xt::xarray<types::BitReference> tmp =
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
        // convert integer/angle to creg
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
                types::smart_cast_to_basic(value_, types::QASM_int{-1}).value);
        }
        // apply index operation
        std::visit(
            utils::overloaded{
                [this, &indices](const xt::xarray<BasicType>& x) {
                    check_indices_in_bounds(x, indices);
                    value_ = xt::xarray<BasicType>(
                        xt::view(x, xt::xkeep_slice<std::ptrdiff_t>(indices)));
                },
                [this, &indices](const xt::xarray<BasicType*>& x) {
                    check_indices_in_bounds(x, indices);
                    value_ = xt::xarray<BasicType*>(
                        xt::view(x, xt::xkeep_slice<std::ptrdiff_t>(indices)));
                },
                [this, &indices](const xt::xarray<types::BitReference>& x) {
                    check_indices_in_bounds(x, indices);
                    value_ = xt::xarray<types::BitReference>(
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
            value_ = get_reference(std::get<xt::xarray<BasicType>>(entry));
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
            auto expr = dynamic_cast<ast::IntExpr*>(type.size()->get());
            n = expr->value();
        } else if (type.type() == ast::SDType::Bit) {
            value_ = types::QASM_cbit{};
            return;
        } else {
            std::cerr << type.pos()
                      << ": error : single designator type must have specified "
                         "size\n";
            throw RuntimeError();
        }
        switch (type.type()) {
            case ast::SDType::Bit: {
                auto tmp =
                    xt::xarray<BasicType>::from_shape({(unsigned long)n});
                tmp.fill(types::QASM_cbit{});
                value_ = std::move(tmp);
                break;
            }
            case ast::SDType::Int:
                value_ = types::QASM_int{n};
                break;
            case ast::SDType::Uint:
                value_ = types::QASM_int{n, false};
                break;
            case ast::SDType::Float:
                value_ = types::QASM_float{};
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
    void visit(ast::ComplexType& type) override {
        value_ = types::QASM_complex();
    }
    void visit(ast::ArrayType& type) override {
        std::vector<unsigned long> shape;
        for (int i = 0; i < type.dims(); i++) {
            auto expr =
                dynamic_cast<ast::IntExpr*>(std::addressof(type.dim(i)));
            shape.push_back(expr->value());
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
            auto expr = dynamic_cast<ast::IntExpr*>(type.size()->get());
            auto tmp = xt::xarray<BasicType>::from_shape(
                {(unsigned long)expr->value()});
            tmp.fill(types::QASM_qubit{});
            value_ = std::move(tmp);
        } else {
            value_ = types::QASM_qubit{};
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
                auto b1 = types::smart_cast_to_basic(v1, types::QASM_bool{});
                auto b2 = types::smart_cast_to_basic(v2, types::QASM_bool{});
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
                                    return types::QASM_int{-1, true,
                                                           x.value | y.value};
                                } else if (exp.op() == ast::BinaryOp::XOr) {
                                    return types::QASM_int{-1, true,
                                                           x.value ^ y.value};
                                } else {
                                    return types::QASM_int{-1, true,
                                                           x.value & y.value};
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
                    utils::overloaded{
                        [&exp](cplx, cplx) -> bool {
                            std::cerr << exp.pos()
                                      << ": error : invalid complex operand(s) "
                                         "to binary operator "
                                      << exp.op() << "\n";
                            throw RuntimeError();
                        },
                        [&exp](cplx, auto) -> bool {
                            std::cerr << exp.pos()
                                      << ": error : invalid complex operand(s) "
                                         "to binary operator "
                                      << exp.op() << "\n";
                            throw RuntimeError();
                        },
                        [&exp](auto, cplx) -> bool {
                            std::cerr << exp.pos()
                                      << ": error : invalid complex operand(s) "
                                         "to binary operator "
                                      << exp.op() << "\n";
                            throw RuntimeError();
                        },
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
                        }},
                    x, y);
                value_ = types::QASM_bool{b};
                return;
            }
            case ast::BinaryOp::LeftBitShift:
            case ast::BinaryOp::RightBitShift: {
                auto shift =
                    types::smart_cast_to_basic(v2, types::QASM_int{-1});
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
                                            : (unsigned long long)v.value
                                                  << shift.value);
                                } else {
                                    return types::QASM_int(
                                        v.width, v.is_signed,
                                        v.is_signed
                                            ? v.value >> shift.value
                                            : (unsigned long long)v.value >>
                                                  shift.value);
                                }
                            },
                            [&exp,
                             &shift](const types::QASM_angle& v) -> ExprType {
                                // bits are little-endian, so we shift the other
                                // way
                                if (exp.op() == ast::BinaryOp::LeftBitShift) {
                                    return types::QASM_angle{
                                        right_shift(v.bits, shift.value)};
                                } else {
                                    return types::QASM_angle{
                                        left_shift(v.bits, shift.value)};
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
            case ast::BinaryOp::Pow: {
                auto x = types::get_value(v1);
                auto y = types::get_value(v2);
                types::value_type val = std::visit(
                    utils::overloaded{
                        [&exp](cplx e1, cplx e2) -> types::value_type {
                            if (exp.op() == ast::BinaryOp::Pow) {
                                return std::pow(e1, e2);
                            } else if (exp.op() == ast::BinaryOp::Plus) {
                                return e1 + e2;
                            } else if (exp.op() == ast::BinaryOp::Minus) {
                                return e1 - e2;
                            } else if (exp.op() == ast::BinaryOp::Times) {
                                return e1 * e2;
                            } else {
                                return e1 / e2;
                            }
                        },
                        [&exp](cplx e1, auto e2) -> types::value_type {
                            if (exp.op() == ast::BinaryOp::Pow) {
                                return std::pow(e1, e2);
                            } else if (exp.op() == ast::BinaryOp::Plus) {
                                return e1 + cplx(e2);
                            } else if (exp.op() == ast::BinaryOp::Minus) {
                                return e1 - cplx(e2);
                            } else if (exp.op() == ast::BinaryOp::Times) {
                                return e1 * cplx(e2);
                            } else {
                                return e1 / cplx(e2);
                            }
                        },
                        [&exp](auto e1, cplx e2) -> types::value_type {
                            if (exp.op() == ast::BinaryOp::Pow) {
                                return std::pow(e1, e2);
                            } else if (exp.op() == ast::BinaryOp::Plus) {
                                return cplx(e1) + e2;
                            } else if (exp.op() == ast::BinaryOp::Minus) {
                                return cplx(e1) - e2;
                            } else if (exp.op() == ast::BinaryOp::Times) {
                                return cplx(e1) * e2;
                            } else {
                                return cplx(e1) / e2;
                            }
                        },
                        [this, &exp](auto e1, auto e2) -> types::value_type {
                            if (exp.op() == ast::BinaryOp::Pow) {
                                return std::pow(e1, e2);
                            } else if (exp.op() == ast::BinaryOp::Plus) {
                                return e1 + e2;
                            } else if (exp.op() == ast::BinaryOp::Minus) {
                                return e1 - e2;
                            } else if (exp.op() == ast::BinaryOp::Times) {
                                return e1 * e2;
                            } else {
                                if (expect_float_div_) {
                                    return (double)e1 / (double)e2;
                                }
                                return e1 / e2;
                            }
                        }},
                    x, y);
                value_ = types::value_to_basictype(val);
                return;
            }
            case ast::BinaryOp::Mod: {
                types::QASM_int e1{-1};
                if (std::holds_alternative<BasicType>(v1) &&
                    std::holds_alternative<types::QASM_int>(
                        std::get<BasicType>(v1))) {
                    e1 = std::get<types::QASM_int>(std::get<BasicType>(v1));
                } else {
                    e1 = types::smart_cast_to_basic(v1, e1);
                }
                types::QASM_int e2{-1};
                if (std::holds_alternative<BasicType>(v2) &&
                    std::holds_alternative<types::QASM_int>(
                        std::get<BasicType>(v2))) {
                    e2 = std::get<types::QASM_int>(std::get<BasicType>(v2));
                } else {
                    e2 = types::smart_cast_to_basic(v2, e2);
                }
                // might be wrong if e1 or e2 have type uint[64]
                value_ = types::QASM_int{-1, true, e1.value % e2.value};
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
                                return types::QASM_int{v.width, v.is_signed,
                                                       ~v.value};
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
                auto tmp =
                    types::smart_cast_to_basic(value_, types::QASM_bool());
                value_ = types::QASM_bool{!tmp.value};
                break;
            }
            case ast::UnaryOp::Neg: {
                value_ = std::visit(
                    utils::overloaded{
                        [](const types::QASM_int& v) -> BasicType {
                            return types::QASM_int{-1, true, -v.value};
                        },
                        [](const types::QASM_float& v) -> BasicType {
                            return types::QASM_float{-v.value};
                        },
                        [](const types::QASM_complex& v) -> BasicType {
                            return types::QASM_complex{-v.value};
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
            case ast::MathOp::Arccos:
            case ast::MathOp::Arcsin:
            case ast::MathOp::Arctan:
            case ast::MathOp::Cos:
            case ast::MathOp::Log:
            case ast::MathOp::Sin:
            case ast::MathOp::Sqrt:
            case ast::MathOp::Tan: {
                exp.arg(0).accept(*this);
                auto arg = types::get_value(value_);
                types::value_type val = std::visit(
                    [&exp](auto v) -> types::value_type {
                        switch (exp.op()) {
                            case ast::MathOp::Arccos:
                                return std::acos(v);
                            case ast::MathOp::Arcsin:
                                return std::asin(v);
                            case ast::MathOp::Arctan:
                                return std::atan(v);
                            case ast::MathOp::Cos:
                                return std::cos(v);
                            case ast::MathOp::Log:
                                return std::log(v);
                            case ast::MathOp::Sin:
                                return std::sin(v);
                            case ast::MathOp::Sqrt:
                                return std::sqrt(v);
                            default:
                                return std::tan(v);
                        }
                    },
                    arg);
                value_ = types::value_to_basictype(val);
                return;
            }
            case ast::MathOp::Ceiling:
            case ast::MathOp::Floor: {
                exp.arg(0).accept(*this);
                auto arg = types::get_value(value_);
                types::value_type val = std::visit(
                    utils::overloaded{
                        [&exp](cplx) -> types::value_type {
                            std::cerr
                                << exp.pos()
                                << ": error : invalid complex argument to "
                                << exp.op() << "\n";
                            throw RuntimeError();
                        },
                        [&exp](auto v) -> types::value_type {
                            switch (exp.op()) {
                                case ast::MathOp::Ceiling:
                                    return std::ceil(v);
                                default:
                                    return std::floor(v);
                            }
                        }},
                    arg);
                value_ = types::value_to_basictype(val);
                return;
            }
            case ast::MathOp::Exp: {
                exp.arg(0).accept(*this);
                auto arg = types::get_value(value_);
                types::value_type val = std::visit(
                    utils::overloaded{
                        [](cplx v) -> types::value_type { return std::exp(v); },
                        [](auto v) -> types::value_type {
                            return std::exp(v);
                        }}, // TODO check this
                    arg);
                value_ = types::value_to_basictype(val);
                return;
            }
            case ast::MathOp::Rotl:
            case ast::MathOp::Rotr: {
                exp.arg(0).accept(*this);
                auto reg = value_;
                exp.arg(1).accept(*this);
                auto shift =
                    types::smart_cast_to_basic(value_, types::QASM_int{-1});
                if (std::holds_alternative<BasicType>(reg)) {
                    auto& val = std::get<BasicType>(reg);
                    if (std::holds_alternative<types::QASM_angle>(val)) {
                        auto& ang = std::get<types::QASM_angle>(val);
                        // bits are little-endian, so we shift the other way
                        if (exp.op() == ast::MathOp::Rotl) {
                            value_ = types::QASM_angle{
                                right_rotate_shift(ang.bits, shift.value)};
                        } else {
                            value_ = types::QASM_angle{
                                left_rotate_shift(ang.bits, shift.value)};
                        }
                    } else {
                        std::cerr << exp.pos()
                                  << ": error : invalid first argument to "
                                  << exp.op() << "\n";
                        throw RuntimeError();
                    }
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
                    auto& val = std::get<BasicType>(value_);
                    if (std::holds_alternative<types::QASM_angle>(val)) {
                        for (bool bit : std::get<types::QASM_angle>(val).bits) {
                            n += bit;
                        }
                    } else {
                        std::cerr << exp.pos()
                                  << ": error : invalid first argument to "
                                  << exp.op() << "\n";
                        throw RuntimeError();
                    }
                } else if (std::holds_alternative<xt::xarray<BasicType>>(
                               value_)) {
                    auto& x = std::get<xt::xarray<BasicType>>(value_);
                    for (auto& i : x) {
                        n += std::get<types::QASM_cbit>(i).bit;
                    }
                }
                value_ = types::QASM_int{-1, true, n};
                return;
            }
            case ast::MathOp::Mod: {
                exp.arg(0).accept(*this);
                auto v1 = value_;
                exp.arg(1).accept(*this);
                auto v2 = value_;
                types::QASM_int e1{-1};
                if (std::holds_alternative<BasicType>(v1) &&
                    std::holds_alternative<types::QASM_int>(
                        std::get<BasicType>(v1))) {
                    e1 = std::get<types::QASM_int>(std::get<BasicType>(v1));
                } else {
                    e1 = types::smart_cast_to_basic(v1, e1);
                }
                types::QASM_int e2{-1};
                if (std::holds_alternative<BasicType>(v2) &&
                    std::holds_alternative<types::QASM_int>(
                        std::get<BasicType>(v2))) {
                    e2 = std::get<types::QASM_int>(std::get<BasicType>(v2));
                } else {
                    e2 = types::smart_cast_to_basic(v2, e2);
                }
                // might be wrong if e1 or e2 have type uint[64]
                value_ = types::QASM_int{-1, true, e1.value % e2.value};
                return;
            }
            case ast::MathOp::Pow: {
                exp.arg(0).accept(*this);
                auto x = types::get_value(value_);
                exp.arg(1).accept(*this);
                auto y = types::get_value(value_);
                types::value_type val = std::visit(
                    [](auto e1, auto e2) -> types::value_type {
                        return std::pow(e1, e2);
                    },
                    x, y);
                value_ = types::value_to_basictype(val);
                return;
            }
            case ast::MathOp::Real:
            case ast::MathOp::Imag: {
                exp.arg(0).accept(*this);
                auto arg = types::get_value(value_);
                types::value_type val = std::visit(
                    utils::overloaded{
                        [&exp](cplx v) -> types::value_type {
                            switch (exp.op()) {
                                case ast::MathOp::Real:
                                    return v.real();
                                default:
                                    return v.imag();
                            }
                        },
                        [&exp](auto v) -> types::value_type {
                            switch (exp.op()) {
                                case ast::MathOp::Real:
                                    return v;
                                default:
                                    return static_cast<long long int>(0);
                            }
                        }},
                    arg);
                value_ = types::value_to_basictype(val);
                return;
            }
        }
    }
    void visit(ast::CastExpr& exp) override {
        exp.subexp().accept(*this);
        auto tmp = value_;
        exp.type().accept(*this);
        std::visit(
            utils::overloaded{
                [&tmp](BasicType& v) { v = types::cast_to_basic(tmp, v); },
                [&tmp](xt::xarray<BasicType>& v) {
                    ExprType v_ref = get_reference(v);
                    types::overwrite(tmp, v_ref);
                },
                [&exp](auto) {
                    std::cerr << exp.pos() << ": error : can't perform cast\n";
                    throw RuntimeError();
                }},
            value_);
    }
    void visit(ast::SizeofExpr& exp) override {
        int dim = 0;
        if (exp.dim()) {
            (**exp.dim()).accept(*this);
            dim = types::smart_cast_to_basic(value_, types::QASM_int{-1}).value;
        }
        exp.arr().accept(*this);
        if (std::holds_alternative<xt::xarray<BasicType>>(value_)) {
            long long ans = std::get<xt::xarray<BasicType>>(value_).shape(dim);
            value_ = types::QASM_int{-1, true, ans};
        } else {
            std::cerr << exp.pos()
                      << ": error : invalid first argument to sizeof\n";
            throw RuntimeError();
        }
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
            } else if (std::holds_alternative<BasicType>(func.param_types[i])) {
                exp.arg(i).accept(*this);
                args.push_back(types::cast_to_basic(
                    value_, std::get<BasicType>(func.param_types[i])));
            } else {
                std::cerr << exp.pos() << ": error : can't compute argument "
                          << i << "\n";
                throw RuntimeError();
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
        value_ =
            std::visit(utils::overloaded{
                           [this](const BasicType& v) -> ExprType {
                               return types::cast_to_basic(return_value_, v);
                           },
                           [this](const xt::xarray<BasicType>& v) -> ExprType {
                               xt::xarray<BasicType> v_cpy = v;
                               ExprType ref = get_reference(v_cpy);
                               types::overwrite(return_value_, ref);
                               return v_cpy;
                           },
                           [](const types::QASM_none&) -> ExprType {
                               return types::QASM_none{};
                           },
                           [&exp](auto) -> ExprType {
                               std::cerr
                                   << exp.pos()
                                   << ": error : can't return expression\n";
                               throw RuntimeError();
                           }},
                       func.return_type);

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
        value_ = types::QASM_int{-1, false, exp.value()};
    }
    void visit(ast::RealExpr& exp) override {
        value_ = types::QASM_float{exp.value()};
    }
    void visit(ast::ImagExpr& exp) override {
        value_ = types::QASM_complex{cplx(0, exp.value())};
    }
    void visit(ast::BoolExpr& exp) override {
        value_ = types::QASM_bool{exp.value()};
    }
    void visit(ast::VarExpr& exp) override {
        auto& entry = std::get<ExprType>(lookup(exp.var()));
        if (expect_array_reference_) {
            // get pointer(s), if applicable
            if (std::holds_alternative<xt::xarray<BasicType>>(entry)) {
                value_ = get_reference(std::get<xt::xarray<BasicType>>(entry));
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
                for (BasicType* i : x) {
                    x_deref.push_back(*i);
                }
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
            for (auto i : element.shape()) {
                shape.push_back(i);
            }
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
    void visit(ast::DurationofExpr& exp) override {
        std::cerr << exp.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::MeasureExpr& msmt) override {
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
    // Statements
    void visit(ast::Annotation&) override {}
    void visit(ast::ProgramBlock& block) override {
        block.foreach_stmt([this](ast::Stmt& stmt) {
            if (!control_flow_) {
                if (!stmt.annotations().empty()) {
                    std::cerr
                        << stmt.pos()
                        << ": warning : annotation(s) ignored by interpreter\n";
                }
                stmt.accept(*this);
            }
        });
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
        auto cond = types::smart_cast_to_basic(value_, types::QASM_bool());

        push_scope();
        if (cond.value) {
            stmt.then().accept(*this);
        } else {
            stmt.els().accept(*this);
        }
        pop_scope();
    }
    void visit(ast::BreakStmt&) override { control_flow_ = ControlFlow::Break; }
    void visit(ast::ContinueStmt&) override {
        control_flow_ = ControlFlow::Continue;
    }
    void visit(ast::ReturnStmt& stmt) override {
        if (stmt.value()) {
            (**stmt.value()).accept(*this);
            return_value_ = value_;
        } else {
            return_value_ = types::QASM_none();
        }
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
        std::cerr << stmt.pos()
                  << ": warning : pragma ignored by interpreter\n";
    }
    // Gates
    void visit(ast::CtrlModifier& mod) override {
        if (mod.neg()) {
            if (mod.n()) {
                auto expr = dynamic_cast<ast::IntExpr*>(mod.n()->get());
                for (int i = 0; i < expr->value(); i++) {
                    matrix_ =
                        qpp::dirsum(matrix_, cmat::Identity(matrix_.rows(),
                                                            matrix_.cols()));
                }
            } else {
                matrix_ = qpp::dirsum(
                    matrix_, cmat::Identity(matrix_.rows(), matrix_.cols()));
            }
        } else {
            if (mod.n()) {
                auto expr = dynamic_cast<ast::IntExpr*>(mod.n()->get());
                for (int i = 0; i < expr->value(); i++) {
                    matrix_ = qpp::dirsum(
                        cmat::Identity(matrix_.rows(), matrix_.cols()),
                        matrix_);
                }
            } else {
                matrix_ = qpp::dirsum(
                    cmat::Identity(matrix_.rows(), matrix_.cols()), matrix_);
            }
        }
    }
    void visit(ast::InvModifier&) override { matrix_ = qpp::inverse(matrix_); }
    void visit(ast::PowModifier& mod) override {
        expect_float_div_ = true;
        mod.r().accept(*this);
        double power =
            types::smart_cast_to_basic(value_, types::QASM_float{}).value;
        expect_float_div_ = false;
        matrix_ = qpp::spectralpowm(matrix_, power);
    }
    void visit(ast::UGate& gate) override {
        using namespace qpp::literals;
        // save the current matrix
        cmat matrix_copy = std::move(matrix_);

        // evaluate classical arguments
        expect_float_div_ = true;
        gate.theta().accept(*this);
        double theta =
            types::smart_cast_to_basic(value_, types::QASM_float{}).value;
        gate.phi().accept(*this);
        double phi =
            types::smart_cast_to_basic(value_, types::QASM_float{}).value;
        gate.lambda().accept(*this);
        double lambda =
            types::smart_cast_to_basic(value_, types::QASM_float{}).value;
        expect_float_div_ = false;

        // generate the matrix
        matrix_ = cmat::Zero(2, 2);
        matrix_ << std::cos(theta / 2),
            -(std::sin(theta / 2)) * std::exp(1_i * lambda),
            std::sin(theta / 2) * std::exp(1_i * phi),
            std::cos(theta / 2) * std::exp(1_i * (phi + lambda));

        // apply the gate
        apply_with_modifiers(gate, matrix_copy);
    }
    void visit(ast::GPhase& gate) override {
        using namespace qpp::literals;
        // save the current matrix
        cmat matrix_copy = std::move(matrix_);

        // evaluate classical arguments
        expect_float_div_ = true;
        gate.gamma().accept(*this);
        double gamma =
            types::smart_cast_to_basic(value_, types::QASM_float{}).value;
        expect_float_div_ = false;

        if (gate.num_qargs() == 0) {
            // must be gphase(gamma); inside a gate definition
            matrix_ = std::exp(1_i * gamma) * matrix_copy;
        } else {
            // generate the matrix
            matrix_ = cmat::Zero(1, 1);
            matrix_ << std::exp(1_i * gamma);

            // apply the gate
            apply_with_modifiers(gate, matrix_copy);
        }
    }
    void visit(ast::DeclaredGate& dgate) override {
        // save the current matrix
        cmat matrix_copy = std::move(matrix_);

        // evaluate classical arguments
        std::vector<double> c_args(dgate.num_cargs());
        expect_float_div_ = true;
        for (int i = 0; i < dgate.num_cargs(); i++) {
            dgate.carg(i).accept(*this);
            c_args[i] =
                types::smart_cast_to_basic(value_, types::QASM_float{}).value;
        }
        expect_float_div_ = false;

        // generate the matrix
        auto it = known_matrices.find({dgate.name(), c_args});
        if (it != known_matrices.end()) {
            matrix_ = it->second;
        } else {
            auto gate = std::get<GateType>(lookup(dgate.name()));
            // save the current subsytem
            auto subsystem_copy = std::move(subsystem_);
            // compute the matrix
            idx n = gate.q_param_names.size();
            subsystem_ = Subsystem{n, {}};
            for (idx i = 0; i < n; i++) {
                subsystem_->ids[gate.q_param_names[i]] = i;
            }
            matrix_ = cmat::Identity(1 << n, 1 << n);
            // push classical arguments onto a new scope
            push_scope();
            for (idx i = 0; i < c_args.size(); i++) {
                set(gate.c_param_names[i], types::QASM_float{c_args[i]});
            }
            gate.body->accept(*this);
            pop_scope();
            // save the matrix
            known_matrices[{dgate.name(), c_args}] = matrix_;
            // restore the original subsystem
            subsystem_ = std::move(subsystem_copy);
        }

        // apply the gate
        apply_with_modifiers(dgate, matrix_copy);
    }
    // Loops
    void visit(ast::RangeSet& set) override {
        (**set.start()).accept(*this);
        int start =
            types::smart_cast_to_basic(value_, types::QASM_int{-1}).value;
        int step = 1;
        if (set.step()) {
            (**set.step()).accept(*this);
            step =
                types::smart_cast_to_basic(value_, types::QASM_int{-1}).value;
            if (step == 0) {
                std::cerr << set.pos() << ": error : range step size is zero\n";
                throw RuntimeError();
            }
        }
        (**set.stop()).accept(*this);
        int stop =
            types::smart_cast_to_basic(value_, types::QASM_int{-1}).value;
        loop_set_ = LoopRange(start, step, stop);
    }
    void visit(ast::ListSet& set) override { loop_set_ = std::addressof(set); }
    void visit(ast::VarSet& set) override {
        auto exp = ast::VarExpr::create({}, set.var());
        exp->accept(*this);
        loop_set_ = std::move(std::get<xt::xarray<BasicType>>(value_));
    }
    void visit(ast::ForStmt& stmt) override {
        stmt.var_type().accept(*this);
        if (!std::holds_alternative<BasicType>(value_)) {
            std::cerr << stmt.pos()
                      << ": error : loop variable must be non-array type\n";
            throw RuntimeError();
        }
        auto var_type = std::get<BasicType>(value_);
        stmt.index_set().accept(*this);
        auto loop_set = std::move(loop_set_);

        std::visit(
            utils::overloaded{
                [this, &stmt, &var_type](ast::ListSet* list_set) {
                    for (auto& exp : list_set->indices()) {
                        exp->accept(*this);
                        var_type = cast_to_basic(value_, var_type);
                        push_scope();
                        set(stmt.var(), var_type);
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
                [this, &stmt, &var_type](LoopRange& range) {
                    for (int i = range.start;
                         (range.step > 0) ? (i < range.stop) : (i > range.stop);
                         i += range.step) {
                        var_type = cast_to_basic(types::QASM_int{-1, true, i},
                                                 var_type);
                        push_scope();
                        set(stmt.var(), var_type);
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
                [this, &stmt, &var_type](xt::xarray<BasicType>& list) {
                    for (auto& x : list) {
                        var_type = cast_to_basic(x, var_type);
                        push_scope();
                        set(stmt.var(), var_type);
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
            loop_set);
    }
    void visit(ast::WhileStmt& stmt) override {
        int iterations = 0;
        while (true) {
            stmt.cond().accept(*this);
            auto cond = types::smart_cast_to_basic(value_, types::QASM_bool());
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
            } else {
                break;
            }
        }
    }
    // Timing Statements
    void visit(ast::DelayStmt& stmt) override {
        std::cerr << stmt.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    void visit(ast::BoxStmt& stmt) override {
        std::cerr << stmt.pos() << ": circuit timing not supported\n";
        throw NotImplementedError();
    }
    // Declarations
    void visit(ast::Param& param) override { param.type().accept(*this); }
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
    void visit(ast::IODecl& decl) override {
        if (decl.is_input()) {
            // initialize
            decl.type().accept(*this);
            set(decl.id(), value_);
            // get reference
            auto lval = ast::IndexId::create({}, decl.id(), {});
            lval->accept(*this);
            auto tmp = value_;
            // get value
            std::string expr = inputs_.front();
            inputs_.pop_front();
            try {
                auto prog =
                    parser::parse_string(expr + ";"); // parse as ExprStmt
                prog->body().front()->accept(*this);
            } catch (...) {
                std::cerr << decl.pos()
                          << ": error : invalid input expression \"" << expr
                          << "\"\n";
                throw RuntimeError();
            }
            // set value
            try {
                types::overwrite(value_, tmp);
            } catch (...) {
                std::cerr << decl.pos() << ": error : input variable '"
                          << decl.id() << "' has type " << decl.type()
                          << ", which is incompatible with expression \""
                          << expr << "\"\n";
                throw;
            }
        } else {
            outputs_.insert(decl.id());
            decl.type().accept(*this);
            set(decl.id(), value_);
        }
    }
    // Program
    void visit(ast::Program& prog) override {
        if (prog.qubits() > 0) {
            psi_ = qpp::st.zero(prog.qubits());
        } else {
            std::cerr << prog.pos() << ": warning : program has no qubits\n";
        }

        push_scope();

        prog.foreach_stmt([this](ast::Stmt& stmt) {
            if (!control_flow_) {
                if (!stmt.annotations().empty()) {
                    std::cerr
                        << stmt.pos()
                        << ": warning : annotation(s) ignored by interpreter\n";
                }
                stmt.accept(*this);
            }
        });

        print_global_vars();
        if (prog.qubits() > 0) {
            print_psi();
        }

        pop_scope();
    }

  private:
    bool expect_float_div_ =
        false; ///< true when float (not integer) division is required
    bool expect_array_reference_ =
        false; ///< true when the argument of a function is an array type
    std::optional<ControlFlow> control_flow_ =
        std::nullopt; ///< signifies when a control statement is executed
    ExprType value_ = types::QASM_none();        ///< stores intermediate values
    ExprType return_value_ = types::QASM_none(); ///< stores return values
    std::variant<ast::ListSet*, LoopRange, xt::xarray<BasicType>>
        loop_set_{}; ///< for-loop values to iterate over
    xt::xstrided_slice_vector index_entities_{}; /// index entities
    idx allocated_qubits_ = 0; ///< total number qubits from visited decls
    qpp::ket psi_{};           ///< state vector
    cmat matrix_{};            ///< stores intermediate gate matrices
    std::optional<Subsystem>
        subsystem_; ///< current subsystem to get matrix for
    std::list<std::unordered_map<ast::symbol, Type>>
        symbol_table_{};                        ///< a stack of symbol tables
    std::unordered_set<ast::symbol> outputs_{}; ///< output variables
    std::list<std::string> inputs_{}; ///< input expressions (to be parsed)
    std::ostream& os_;

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
        if (symbol_table_.empty()) {
            throw std::logic_error("No current symbol table!");
        }

        symbol_table_.front()[id] = typ;
    }

    /**
     * \brief Prints list of global variables and their values
     */
    void print_global_vars() const {
        os_ << "Final values:\n";
        if (outputs_.empty()) {
            for (const auto& v : symbol_table_.back()) {
                if (std::holds_alternative<ExprType>(v.second)) {
                    auto& tmp = std::get<ExprType>(v.second);
                    if (std::holds_alternative<BasicType>(tmp)) {
                        os_ << v.first << ": " << std::get<BasicType>(tmp)
                            << "\n";
                    } else if (std::holds_alternative<xt::xarray<BasicType>>(
                                   tmp)) {
                        os_ << v.first << ":\n"
                            << std::get<xt::xarray<BasicType>>(tmp) << "\n";
                    }
                }
            }
        } else {
            for (const auto& id : outputs_) {
                auto& v =
                    std::get<ExprType>(symbol_table_.back().find(id)->second);
                if (std::holds_alternative<BasicType>(v)) {
                    os_ << id << ": " << std::get<BasicType>(v) << "\n";
                } else if (std::holds_alternative<xt::xarray<BasicType>>(v)) {
                    os_ << id << ":\n"
                        << std::get<xt::xarray<BasicType>>(v) << "\n";
                }
            }
        }
    }

    /**
     * \brief Prints the state vector
     */
    void print_psi() {
        os_ << ">> Final state (transpose):\n";
        os_ << qpp::disp(qpp::transpose(psi_)) << '\n';
    }

    /**
     * \brief Check indices in entities are in bounds for array x
     */
    template <typename T>
    static void
    check_index_entities_in_bounds(const xt::xarray<T>& x,
                                   xt::xstrided_slice_vector& entities) {
        for (int i = 0; i < entities.size(); i++) {
            if (xtl::holds_alternative<std::ptrdiff_t>(entities[i])) {
                int ind = xtl::get<std::ptrdiff_t>(entities[i]);
                int size = x.shape(i);
                if (ind >= size || ind < -size) {
                    std::cerr << "error : index " << ind
                              << " is out of bounds for axis " << i
                              << " with size " << size << "\n";
                    throw RuntimeError();
                }
                if (ind < 0) { // fix negative indices
                    entities[i] = ind + size;
                }
            }
        }
    }

    /**
     * \brief Check indices for a list slice are in bounds for array x
     */
    template <typename T>
    static void check_indices_in_bounds(const xt::xarray<T>& x,
                                        const std::vector<int>& indices) {
        int size = x.shape(0);
        for (int ind : indices) {
            if (ind >= size || ind < -size) {
                std::cerr << ": error : index " << ind
                          << " is out of bounds for array of size " << size
                          << "\n";
                throw RuntimeError();
            }
        }
    }

    /**
     * \brief Get array of pointers to the elements of the given array
     */
    static xt::xarray<BasicType*> get_reference(xt::xarray<BasicType>& arr) {
        std::vector<BasicType*> arr_ref;
        arr_ref.reserve(arr.size());
        for (BasicType& i : arr) {
            arr_ref.push_back(std::addressof(i));
        }
        return xt::adapt(arr_ref, arr.shape());
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
        shift %= (int)bits.size();
        if (shift < 0) {
            shift += bits.size();
        }
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
inline void execute(ast::Program& prog, std::list<std::string> inputs) {
    Executor(std::cout).run(prog, std::move(inputs));
}

} /* namespace tools */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_TOOLS_INTERPRETER_HPP_ */
