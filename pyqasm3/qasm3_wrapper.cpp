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
#include <pybind11/stl.h>
#include <sstream>

#include "qasm3tools/tools/interpreter.hpp"
#include "qasm3tools/parser/parser.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pyqasm3, m) {
    m.doc() = "Python wrapper for qasm3tools (https://github.com/softwareQinc/qasm3tools)";

    m.def("execute_file", [](const std::string& fname, std::list<std::string> inputs) -> std::string {
        auto prog = qasm3tools::parser::parse_file(fname);
        std::ostringstream oss;
        qasm3tools::tools::Executor(oss).run(*prog, std::move(inputs));
        return oss.str();
    }, "Execute OpenQASM 3.0 program file", py::arg("file_name"), py::arg("inputs") = std::list<std::string>());

    m.def("execute_str", [](const std::string& str, std::list<std::string> inputs) -> std::string {
        auto prog = qasm3tools::parser::parse_string(str);
        std::ostringstream oss;
        qasm3tools::tools::Executor(oss).run(*prog, std::move(inputs));
        return oss.str();
    }, "Execute OpenQASM 3.0 program string", py::arg("program_string"), py::arg("inputs") = std::list<std::string>());
}
