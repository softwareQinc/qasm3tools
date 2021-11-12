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
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/dd.qasm"));
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
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/pong.qasm"));
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
    EXPECT_NO_THROW(
        parser::parse_file(PROJECT_ROOT_DIR "/qasm/generic/vqe.qasm"));
}
/******************************************************************************/
