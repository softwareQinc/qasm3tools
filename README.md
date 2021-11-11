# antlr-cmake

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
