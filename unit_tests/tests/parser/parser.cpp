#include "qasm3tools/parser/parser.hpp"
#include "gtest/gtest.h"

#include <sstream>

using namespace qasm3tools;

// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(Parsing, Standard_Compliance) {
    // generic circuits
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/adder.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/alignment.qasm"));
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/arrays.qasm"));
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/cphase.qasm"));*/
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/dd.qasm"));*/
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/defcal.qasm"));*/
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
    /*EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/t1.qasm"));*/
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
                      "pragma user alice account 12345678\n"
                      "const float[64] pi_by_2 = π/2;\n"
                      "input uint[32] inn;\n"
                      "output complex outt;\n"
                      "@reversible\n"
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
                      "measure q[{1, 3, 6}];\n"
                      "c[2:2:10] = measure q[2:2:10];\n"
                      "reset q[2:2:8][0];\n"
                      "barrier;\n"
                      "if (true) {\n"
                      "\tint[32] i = mod_2(n)*3;\n"
                      "\twhile (n<0) {\n"
                      "\t\tn = n-i;\n"
                      "\t\tbreak;\n"
                      "\t}\n"
                      "}\n"
                      "else {\n"
                      "\tfor uint[32] i in [1:5] {\n"
                      "\t\tif (bool(c[i])) {\n"
                      "\t\t}\n"
                      "\t\tc[i-1] = c[i-1]&c[i+1];\n"
                      "\t\tdo_nothing(c[3],q,false);\n"
                      "\t\tcontinue;\n"
                      "\t}\n"
                      "}\n"
                      "let q_alias = qq ++ q[{0, 1, 2, 4, 8}];\n"
                      "box [0.25s] {\n"
                      "\tdelay[1.234µs] q_alias[0],q[2];\n"
                      "\tfor int[32] i in {5, 7, 9} {\n"
                      "\t\tCCCX q[0],q[1],q[2],q[i];\n"
                      "\t}\n"
                      "}\n"
                      "array[int[32], 2, 3] arr = {{0, 1, 2}, {3, 4, 5}};\n"
                      "sizeof(arr, 1)*sizeof(arr);\n"
                      "arr[:, 2][-1] = arr[0, :][1];\n"
                      "def gg(readonly array[bool, #dim = 2] g) {\n"
                      "}\n"
                      "def hh(mutable array[complex[float[32]], 4] h) {\n"
                      "\tbit[4] b = \"1110\";\n"
                      "}\n"
                      "array[int[32], 4] loop_arr = {1, 4, 9, 16};\n"
                      "for int[32] i in loop_arr {\n"
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

    std::string src5 = "OPENQASM 3.0;\n"
                       "int[32] n = 8;\n"
                       "array[float[32], 3, 2, n, 1] arr;\n";

    std::string src6 = "OPENQASM 3.0;\n"
                       "int[32] n = 2;\n"
                       "def f(mutable array[bool, #dim = n] a) {\n"
                       "}\n";

    std::string src7 = "OPENQASM 3.0;\n"
                       "int[32] n = 2;\n"
                       "def f(readonly array[int[32], 2, n] a) {\n"
                       "}\n";

    EXPECT_THROW(parser::parse_string(src1, "not_const_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "not_const_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "not_const_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "not_const_error_4.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src5, "not_const_error_5.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src6, "not_const_error_6.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src7, "not_const_error_7.qasm"),
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

    std::string src3 = "OPENQASM 3.0;\n"
                       "def f(readonly array[int[32], #dim = 2] a) {\n"
                       "\ta[0, 0] = 0;\n"
                       "}\n";

    EXPECT_THROW(parser::parse_string(src1, "const_assignment_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "const_assignment_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "const_assignment_error_3.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Loop_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "for uint[32] i in [0:5] {\n"
                       "\ti = 0;\n"
                       "}\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "for uint[32] i in [3:] {}\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "for int[32] i in [:4] {}\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "for bool b in [0:5] {}\n";

    std::string src5 = "OPENQASM 3.0;\n"
                       "for float[32] s in {1+2im, 3} {}\n";

    std::string src6 = "OPENQASM 3.0;\n"
                       "array[complex, 3] arr;\n"
                       "for int[32] s in arr {}\n";

    std::string src7 = "OPENQASM 3.0;\n"
                       "array[float[32], 3, 2] arr;\n"
                       "for float[32] s in arr {}\n";

    EXPECT_THROW(parser::parse_string(src1, "loop_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "loop_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "loop_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "loop_error_4.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src5, "loop_error_5.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src6, "loop_error_6.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src7, "loop_error_7.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Dimension_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "array[float[32], 3, 2] arr;\n"
                       "arr[0, 0, 0];\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "array[uint[32], 3, 1] arr = {3, 2, 1};\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "array[float[32], 3, 2] arr;\n"
                       "array[float[32], 3, 2, 1] arr2;\n"
                       "arr = arr2;\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "array[int[32], 3, 2] arr;\n"
                       "arr = arr[:, 0];\n";

    std::string src5 = "OPENQASM 3.0;\n"
                       "array[bool, 3, 2] arr;\n"
                       "def f(mutable array[bool, #dim = 3] a) {\n"
                       "}\n"
                       "f(arr);\n";

    std::string src6 = "OPENQASM 3.0;\n"
                       "array[int[32], 3, 2] arr;\n"
                       "def f(readonly array[int[32], 3, 2] a) {\n"
                       "}\n"
                       "f(arr[0, :]);\n";

    EXPECT_THROW(parser::parse_string(src1, "dimension_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "dimension_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "dimension_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "dimension_error_4.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src5, "dimension_error_5.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src6, "dimension_error_6.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Operand_Type_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "float[32] n = 9;\n"
                       "~n;\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "1.2^2;\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "extern f() -> int[32];\n"
                       "true*f();\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "extern f();\n"
                       "f()+1;\n";

    EXPECT_THROW(parser::parse_string(src1, "operand_type_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "operand_type_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "operand_type_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "operand_type_error_4.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Cast_Type_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "bit[32](3.14);\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "angle[64] theta;\n"
                       "float[64](theta);\n";

    EXPECT_THROW(parser::parse_string(src1, "cast_type_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "cast_type_error_2.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Call_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "extern f(angle[32]);\n"
                       "f(true);\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "extern f(bool, bit);\n"
                       "qubit q;\n"
                       "f(false, q);\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "def f(qubit q) {}\n"
                       "bit b;\n"
                       "f(b);\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "extern f(int[32]);\n"
                       "f();\n";

    std::string src5 = "OPENQASM 3.0;\n"
                       "def f(bool b, int[32] n) {}\n"
                       "f(true, 1, 1);\n";

    std::string src6 = "OPENQASM 3.0;\n"
                       "bit b;\n"
                       "sizeof(b);\n";

    std::string src7 = "OPENQASM 3.0;\n"
                       "def f(qubit q) {}\n"
                       "qubit q;\n"
                       "f q;\n";

    std::string src8 = "OPENQASM 3.0;\n"
                       "gate xx a { U(π, 0, π) a; }\n"
                       "qubit q;\n"
                       "xx(q);\n";

    std::string src9 = "OPENQASM 3.0;\n"
                       "qubit q;\n"
                       "qubit r;\n"
                       "U(π, 0, π) q, r;\n";

    std::string src10 = "OPENQASM 3.0;\n"
                        "qubit q;\n"
                        "ctrl @ U(π, 0, π) q;\n";

    std::string src11 = "OPENQASM 3.0;\n"
                        "qubit q;\n"
                        "gphase(π/4) q;\n";

    std::string src12 = "OPENQASM 3.0;\n"
                        "include \"stdgates.inc\";\n"
                        "qubit q;\n"
                        "qubit r;\n"
                        "t q, r;\n";

    std::string src13 = "OPENQASM 3.0;\n"
                        "include \"stdgates.inc\";\n"
                        "qubit q;\n"
                        "qubit r;\n"
                        "ctrl @ ctrl @ t q, r;\n";

    EXPECT_THROW(parser::parse_string(src1, "call_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "call_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "call_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "call_error_4.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src5, "call_error_5.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src6, "call_error_6.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src7, "call_error_7.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src8, "call_error_8.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src9, "call_error_9.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src10, "call_error_10.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src11, "call_error_11.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src12, "call_error_12.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src13, "call_error_13.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Return_Type_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "def f() -> int[32] {\n"
                       "\treturn;\n"
                       "}\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "def f() {\n"
                       "\treturn 0;\n"
                       "}\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "def f(qubit q) -> float[32] {\n"
                       "\treturn measure q;\n"
                       "}\n";

    EXPECT_THROW(parser::parse_string(src1, "return_type_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "return_type_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "return_type_error_3.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Register_Type_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "bit[1] x;\n"
                       "U(0,0,0) x[0];\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "bit x;\n"
                       "barrier x;\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "bit[10] x;\n"
                       "let q = x[1:2:9];\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "qubit[2] x;\n"
                       "qubit y;\n"
                       "x[1] = measure y;\n";

    EXPECT_THROW(parser::parse_string(src1, "register_type_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "register_type_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "register_type_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "register_type_error_4.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Miscellaneous_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "angle[32] x = π;\n"
                       "qubit[10] q;\n"
                       "measure q[x];\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "for int[32] i in [0:1im] {}\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "bit[10] x;\n"
                       "x[3ns];\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "popcount(2.72);\n";

    std::string src5 = "OPENQASM 3.0;\n"
                       "qubit q;\n"
                       "if (q) {}\n";

    std::string src6 = "OPENQASM 3.0;\n"
                       "extern f();\n"
                       "while (f()) {}\n";

    std::string src7 = "OPENQASM 3.0;\n"
                       "qubit[1] q;\n"
                       "bit[32] x;\n"
                       "pow(x) @ U(0,0,0) q;\n";

    std::string src8 = "OPENQASM 3.0;\n"
                       "float[32] x;\n"
                       "bit[32] y;\n"
                       "x = y;\n";

    std::string src9 = "OPENQASM 3.0;\n"
                       "extern f();\n"
                       "float[32] x = f();\n";

    std::string src10 = "OPENQASM 3.0;\n"
                        "true[0];\n";

    std::string src11 = "OPENQASM 3.0;\n"
                        "complex[bool] x;\n";

    std::string src12 = "OPENQASM 3.0;\n"
                        "include \"stdgates.inc\";\n"
                        "CX;\n";

    std::string src13 = "OPENQASM 3.0;\n"
                        "include \"stdgates.inc\";\n"
                        "CX = 0;\n";

    EXPECT_THROW(parser::parse_string(src1, "miscellaneous_error_1.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src2, "miscellaneous_error_2.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src3, "miscellaneous_error_3.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src4, "miscellaneous_error_4.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src5, "miscellaneous_error_5.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src6, "miscellaneous_error_6.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src7, "miscellaneous_error_7.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src8, "miscellaneous_error_8.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src9, "miscellaneous_error_9.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src10, "miscellaneous_error_10.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src11, "miscellaneous_error_11.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src12, "miscellaneous_error_12.qasm"),
                 ast::SemanticError);
    EXPECT_THROW(parser::parse_string(src13, "miscellaneous_error_13.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Unexpected_Control_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "if (true) return;\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "if (true) break;\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "def foo() {\n"
                       "\tif (true) continue;\n"
                       "}\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "def foo() {\n"
                       "\tif (true) end;\n"
                       "}\n";

    EXPECT_THROW(parser::parse_string(src1, "unexpected_control_error_1.qasm"),
                 ast::SemanticError);

    EXPECT_THROW(parser::parse_string(src2, "unexpected_control_error_2.qasm"),
                 ast::SemanticError);

    EXPECT_THROW(parser::parse_string(src3, "unexpected_control_error_3.qasm"),
                 ast::SemanticError);

    EXPECT_THROW(parser::parse_string(src4, "unexpected_control_error_4.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/

/******************************************************************************/
TEST(Parsing, Statement_Type_Error) {
    std::string src1 = "OPENQASM 3.0;\n"
                       "if (true) {\n"
                       "\tgate xx a { U(π, 0, π) a; }\n"
                       "}\n";

    std::string src2 = "OPENQASM 3.0;\n"
                       "def foo() {\n"
                       "\tqubit q;\n"
                       "}\n";

    std::string src3 = "OPENQASM 3.0;\n"
                       "gate xx a { bool b; }\n";

    std::string src4 = "OPENQASM 3.0;\n"
                       "gate xx a {\n"
                       "\tfor uint[32] i in {0, 1} {\n"
                       "\t\tint[32] n;\n"
                       "\t}\n"
                       "}\n";

    EXPECT_THROW(parser::parse_string(src1, "statement_type_error_1.qasm"),
                 ast::SemanticError);

    EXPECT_THROW(parser::parse_string(src2, "statement_type_error_2.qasm"),
                 ast::SemanticError);

    EXPECT_THROW(parser::parse_string(src3, "statement_type_error_3.qasm"),
                 ast::SemanticError);

    EXPECT_THROW(parser::parse_string(src4, "statement_type_error_4.qasm"),
                 ast::SemanticError);
}
/******************************************************************************/
