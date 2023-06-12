# qasm3tools

[![GitHub actions](https://github.com/softwareqinc/qasm3tools/actions/workflows/cmake.yml/badge.svg)](https://github.com/softwareQinc/qasm3tools/actions)

---

## Setup

```shell
cmake -B build
cmake --build build --parallel 8
```

This creates the `parser` executable.

```shell
./parser /path/to/circuit.qasm
```

---

## Interpreter

To build the interpreter, you must
have [qpp](https://github.com/softwareQinc/qpp) installed.
Execute

```shell
cmake -B build -DWITH_INTERPRETER=ON
cmake --build build --parallel 8
```

This creates the `interpreter` executable. Usage:

```shell
./interpreter /path/to/circuit.qasm
```

If the OpenQASM 3.0 file contains `n` input variables, then the interpreter
requires exactly `n` additional commandline arguments to specify their values.
For example, if the file contains

```
input float[32] fl;
input bool bl;
```

Then it could be executed with

```shell
./interpreter example.qasm "pi/2" "true"
```

---

## Unit testing

```shell
cmake --build build --target unit_tests --parallel 8
ctest --test-dir build
```

---

## Notes

1. The interpreter is implemented to *exclude* the endpoints of ranges. As of
   August 10, 2022, in the OpenQASM 3.0 live specification, range endpoints are
   included.

2. The OpenQASM 3.0 standard library defines the `u3` and `u2` gates differently
   than the Qiskit specifications.

| Gate | OpenQASM 3.0                                                                                                                                                                                                                                                                                                                                            | Qiskit                                                                                                                                                                                                                                                                     | Phase inconsistency                                                                         |
|------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------|
| u3   | ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Bpmatrix%7De%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D%5Ccos%28%5Ctheta/2%29%26-e%5E%7B-i%28%5Cphi-%5Clambda%29/2%7D%5Csin%28%5Ctheta/2%29%5C%5Ce%5E%7Bi%28%5Cphi-%5Clambda%29/2%7D%5Csin%28%5Ctheta/2%29%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29/2%7D%5Ccos%28%5Ctheta/2%29%5Cend%7Bpmatrix%7D) | ![equation](https://latex.codecogs.com/gif.latex?%5Cbegin%7Bpmatrix%7D%5Ccos%28%5Ctheta/2%29%26-e%5E%7Bi%5Clambda%7D%5Csin%28%5Ctheta/2%29%5C%5Ce%5E%7Bi%5Cphi%7D%5Csin%28%5Ctheta/2%29%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29%7D%5Ccos%28%5Ctheta/2%29%5Cend%7Bpmatrix%7D) | ![equation](https://latex.codecogs.com/gif.latex?e%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D) |
| u2   | ![equation](https://latex.codecogs.com/gif.latex?%5Ctfrac%7B1%7D%7B%5Csqrt%7B2%7D%7D%5Cbegin%7Bpmatrix%7De%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D%26-e%5E%7B-i%28%5Cphi-%5Clambda%29/2%7D%5C%5Ce%5E%7Bi%28%5Cphi-%5Clambda%29/2%7D%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29/2%7D%5Cend%7Bpmatrix%7D)                                                      | ![equation](https://latex.codecogs.com/gif.latex?%5Ctfrac%7B1%7D%7B%5Csqrt%7B2%7D%7D%5Cbegin%7Bpmatrix%7D1%26-e%5E%7Bi%5Clambda%7D%5C%5Ce%5E%7Bi%5Cphi%7D%26e%5E%7Bi%28%5Cphi&plus;%5Clambda%29%7D%5Cend%7Bpmatrix%7D)                                                     | ![equation](https://latex.codecogs.com/gif.latex?e%5E%7B-i%28%5Cphi&plus;%5Clambda%29/2%7D) |
