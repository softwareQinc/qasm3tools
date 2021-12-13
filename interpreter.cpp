// must include qpp.h first because antlrcpp undefines the EOF macro
#include "qpp/qpp.h"
#include "qasm3tools/parser/parser.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./interpreter /path/to/qasm\n";
        return 0;
    }
}
