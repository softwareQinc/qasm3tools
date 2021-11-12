# qasm3tools
[![Build status - CircleCI Linux/macOS](https://circleci.com/gh/softwareQinc/qasmtools.svg?style=svg)](https://circleci.com/gh/softwareQinc/qasm3tools)
[![Build status](https://ci.appveyor.com/api/projects/status/yidln2j88dssf4v1?svg=true)](https://ci.appveyor.com/project/vsoftco/qasm3tools)

## Setup
```bash
mkdir build && cd build
cmake ..
make
```

This creates the `parser` executable.
```bash
./parser /path/to/circuit.qasm
```

## Unit testing
For unit testing, make sure to clone this repository with `--recursive`.
```bash
make unit_tests
ctest
```
