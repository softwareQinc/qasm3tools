# antlr4cpp generated files

These files must stay up-to-date with the `qasm3Lexer.g4` and `qasm3Parser.g4` grammar files. Instructions:

1. Go to the `../grammar` directory. After updating the `*.g4` files, run `make` (requires java).
2. From the generated files, rename `qasm3Lexer.cpp` to `qasm3LexerImpl.hpp` and add the `#pragma once` preprocessor directive. Similarly, change `qasm3Parser.cpp` to `qasm3ParserImpl.hpp`.
3. Replace the files in this directory with the new files.

To use the lexer/parser, make sure to include `qasm3LexerImpl.hpp` and `qasm3ParserImpl.hpp`, rather than `qasm3Lexer.h` and `qasm3Parser.h`.
