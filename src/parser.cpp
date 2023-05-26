#include "qasm3tools/parser/parser.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./parser /path/to/qasm\n";
        return 0;
    }
    auto prog = qasm3tools::parser::parse_file(argv[1]);
    std::cout << *prog;
}
