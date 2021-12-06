#include "qasmtools/parser/parser.hpp"
#include "gtest/gtest.h"

#include <sstream>

using namespace qasmtools;

// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(Parsing, Standard_Compliance) {
    // generic circuits
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/adder.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/alignment.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/cphase.qasm"));
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/dd.qasm"));*/
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/defcal.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/gateteleport.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/inverseqft1.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/inverseqft2.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/ipe.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/msd.qasm"));
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/pong.qasm"));*/
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/qec.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/qft.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/qpt.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/rb.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/rus.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/scqec.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/t1.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/teleport.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/varteleport.qasm"));
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/vqe.qasm"));*/
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Idempotence) {
    std::string src = "OPENQASM 3.0;\n"
                      "include \"stdgates.inc\";\n"
                      "\n"
                      "#pragma {\n"
                      "\tconst float[64] pi_by_2 = π/2;\n"
                      "}\n"
                      "gate CCCX a,b,c,d {\n"
                      "\tctrl(2) @ CX a,b,c,d;\n"
                      "}\n"
                      "extern is_even(int[32]) -> bool;\n"
                      "def mod_2(int[32] n) -> int[32] {\n"
                      "\tif (is_even(n)) {\n"
                      "\t\treturn 1;\n"
                      "\t}\n"
                      "\treturn 0;\n"
                      "}\n"
                      "def do_nothing(bit b, qubit[10] qb, bool foo) {\n"
                      "}\n"
                      "def mes(qubit[10] q) -> bit[10] {\n"
                      "\treturn measure q;\n"
                      "}\n"
                      "qubit[10] q;\n"
                      "qubit qq;\n"
                      "bit[10] c;\n"
                      "int[32] n = -99;\n"
                      "uint[32] un = 99;\n"
                      "angle[32] my_angle = π/2;\n"
                      "const bool tt = true;\n"
                      "duration dur = 3.1ns;\n"
                      "stretch str;\n"
                      "complex[float[32]] complex_e_1 = ℇ+1im;\n"
                      "rotl(c,2);\n"
                      "measure q[0]++q[1,3,6];\n"
                      "c[2:2:10] = measure q[2:2:10];\n"
                      "reset qq++q[2:2:8];\n"
                      "barrier;\n"
                      "if (true) {\n"
                      "\tint[32] i = mod_2(n)*3;\n"
                      "\twhile (n<0) {\n"
                      "\t\tn = n-i;\n"
                      "\t\tbreak;\n"
                      "\t}\n"
                      "}\n"
                      "else {\n"
                      "\tfor i in [1:5] {\n"
                      "\t\tif (bool(c[i])) {\n"
                      "\t\t}\n"
                      "\t\tc[i-1] = c[i-1]&1;\n"
                      "\t\tdo_nothing(c[3],q,false);\n"
                      "\t\tcontinue;\n"
                      "\t}\n"
                      "}\n"
                      "let q_alias = q[0,1,2,4,8];\n"
                      "box [0.25s] {\n"
                      "\tdelay(0.5,1.5)[1.234µs] q_alias[0],q[2];\n"
                      "\tfor i in [5:2:9] {\n"
                      "\t\tCCCX q[0],q[1],q[2],q[i];\n"
                      "\t}\n"
                      "}\n"
                      "end;\n";

    auto prog = parser::parse_string(src, "idempotence_test.qasm");
    std::stringstream ss;
    ss << *prog;

    EXPECT_EQ(ss.str(), src);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Not_Const_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "int[32] n = 8;\n"
                       "qubit[n] q;\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "int[32] n = 8;\n"
                       "float[n] fl;\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "int[32] n = 1;\n"
                       "qubit q;\n"
                       "ctrl(n) @ gphase(π) q;\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "int[32] n = 8;\n"
                       "const int[64] cn = n;\n";

    EXPECT_THROW(parser::parse_string(src1, "not_const_error.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "not_const_error.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "not_const_error.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "not_const_error.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Const_Assignment_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "const int[32] n = 8;\n"
                       "n = 2;\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "const bit[4] n = \"0110\";\n"
                       "qubit[4] q;\n"
                       "n = measure q;\n";

    EXPECT_THROW(parser::parse_string(src1, "const_assignment_error.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "const_assignment_error.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/
