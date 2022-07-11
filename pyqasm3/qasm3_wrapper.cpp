/*
 * This file is part of pyqasm3.
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

#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#define NOMINMAX
#endif

#include <pybind11/pybind11.h>
#include <pybind11/stl/filesystem.h>

#include "qasm3tools/tools/interpreter.hpp"
#include "qasm3tools/parser/parser.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pyqasm3, m) {
    m.doc() = "Python wrapper for qasm3tools (https://github.com/softwareQinc/qasm3tools)";

    m.def("execute_file", [](const std::string& fname){
        auto prog = qasm3tools::parser::parse_file(fname);
        qasm3tools::tools::execute(*prog);
    }, "Execute OpenQASM 3.0 program file");

    m.def("execute_str", [](const std::string& str){
        auto prog = qasm3tools::parser::parse_string(str);
        qasm3tools::tools::execute(*prog);
    }, "Execute OpenQASM 3.0 program string");
}
