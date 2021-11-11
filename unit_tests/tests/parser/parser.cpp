#ifndef PATH
#define PATH "../../"
#endif

#include "gtest/gtest.h"
#include "qasmtools/parser/parser.hpp"

#include <sstream>

using namespace qasmtools;

// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(Parsing, Standard_Compliance) {
    // generic circuits
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/adder.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/alignment.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/cphase.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/dd.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/defcal.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/gateteleport.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/inverseqft1.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/inverseqft2.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/ipe.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/msd.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/pong.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/qec.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/qft.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/qpt.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/rb.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/rus.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/scqec.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/t1.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/teleport.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/varteleport.qasm"));
    EXPECT_NO_THROW(parser::parse_file(PATH "/qasm/generic/vqe.qasm"));
}
/******************************************************************************/
