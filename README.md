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

## Notes

1. The interpreter is implemented to *exclude* the endpoints of ranges. As of June 3, 2022, in the OpenQASM 3.0 live specification, range endpoints are included.

2. The OpenQASM 3.0 standard library defines the `u3` and `u2` gates differently than the Qiskit specifications.

| Gate | OpenQASM 3.0 | Qiskit | Phase inconsistency|
| - | - | - | - |
| u3 | ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Bpmatrix%7De%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D%5Ccos%28%5Ctheta/2%29%26-e%5E%7B-i%28%5Cphi-%5Clambda%29/2%7D%5Csin%28%5Ctheta/2%29%5C%5Ce%5E%7Bi%28%5Cphi-%5Clambda%29/2%7D%5Csin%28%5Ctheta/2%29%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29/2%7D%5Ccos%28%5Ctheta/2%29%5Cend%7Bpmatrix%7D) | ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Bpmatrix%7D%5Ccos%28%5Ctheta/2%29%26-e%5E%7Bi%5Clambda%7D%5Csin%28%5Ctheta/2%29%5C%5Ce%5E%7Bi%5Cphi%7D%5Csin%28%5Ctheta/2%29%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29%7D%5Ccos%28%5Ctheta/2%29%5Cend%7Bpmatrix%7D) | ![equation](https://latex.codecogs.com/gif.latex?e%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D) |
| u2 | ![equation](https://latex.codecogs.com/gif.latex?%5Ctfrac%7B1%7D%7B%5Csqrt%7B2%7D%7D%5Cbegin%7Bpmatrix%7De%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D%26-e%5E%7B-i%28%5Cphi-%5Clambda%29/2%7D%5C%5Ce%5E%7Bi%28%5Cphi-%5Clambda%29/2%7D%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29/2%7D%5Cend%7Bpmatrix%7D) | ![equation](https://latex.codecogs.com/gif.latex?%5Ctfrac%7B1%7D%7B%5Csqrt%7B2%7D%7D%5Cbegin%7Bpmatrix%7D1%26-e%5E%7Bi%5Clambda%7D%5C%5Ce%5E%7Bi%5Cphi%7D%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29%7D%5Cend%7Bpmatrix%7D) | ![equation](https://latex.codecogs.com/gif.latex?e%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D) |
