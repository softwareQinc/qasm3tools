#include "qasmtools/parser/parser.hpp"

#include <iostream>

int main(int argc, char** argv) {
    auto prog = qasmtools::parser::parse_file(argv[1]);
    std::cout << *prog;
}
