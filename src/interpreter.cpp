// must include qpp before parser because antlrcpp undefines the EOF macro
#include "qasm3tools/tools/interpreter.hpp"
#include "qasm3tools/parser/parser.hpp"

#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./interpreter /path/to/qasm\n";
        return 0;
    }
    auto prog = qasm3tools::parser::parse_file(argv[1]);
    if (prog->inputs() != argc - 2) {
        std::cerr << prog->pos() << ": error : program expects "
                  << prog->inputs() << " input expression(s)\n";
        std::cerr << "Usage: ./interpreter /path/to/qasm";
        for (int i = 0; i < prog->inputs(); i++) {
            std::cerr << " <expr>";
        }
        std::cerr << "\n";
        return 0;
    }
    std::list<std::string> inputs;
    for (int i = 2; i < argc; i++) {
        inputs.push_back(argv[i]);
    }
    qasm3tools::tools::execute(*prog, std::move(inputs));
}
