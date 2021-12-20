// must include qpp before parser because antlrcpp undefines the EOF macro
#include "qasm3tools/tools/interpreter.hpp"
#include "qasm3tools/parser/parser.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./interpreter /path/to/qasm\n";
        return 0;
    }
    auto prog = qasm3tools::parser::parse_file(argv[1]);
    qasm3tools::tools::execute(*prog);
}
