# qasm3tools
[![Build status - CircleCI Linux/macOS](https://circleci.com/gh/softwareQinc/qasmtools.svg?style=svg)](https://circleci.com/gh/softwareQinc/qasm3tools)
[![Build status](https://ci.appveyor.com/api/projects/status/yidln2j88dssf4v1?svg=true)](https://ci.appveyor.com/project/vsoftco/qasm3tools)

## Setup
```bash
mkdir build && cd build
cmake ..
make -j8
```

This creates the `parser` executable.
```bash
./parser /path/to/circuit.qasm
```

## Interpreter
To build the interpreter, you must have [qpp](https://github.com/softwareQinc/qpp) installed. In the build directory, do
```bash
cmake .. -DWITH_INTERPRETER=ON
make -j8
```
This creates the `interpreter` executable.

## Unit testing
```bash
make -j8 unit_tests
ctest
```
