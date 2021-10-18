#ifndef PATH
#define PATH "../../"
#endif

#include "gtest/gtest.h"
#include "qasmtools/ast/ast.hpp"

#include <sstream>

using namespace qasmtools;

// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(ASTNodes, Construction) {
    EXPECT_NO_THROW({
        //var
        qasmtools::ast::VarAccess va({}, "x");

        //program
        qasmtools::ast::Program({}, false, {});

        //stmt
        qasmtools::ast::QuantumMeasurement qm({}, std::move(*(va.clone())));
        qasmtools::ast::ProgramBlock({}, {});
        qasmtools::ast::QuantumBlock({}, {});
        qasmtools::ast::QuantumLoopBlock({}, {});
        qasmtools::ast::MeasureStmt({}, std::move(*(qm.clone())));
        qasmtools::ast::ExprStmt({}, {});
        qasmtools::ast::MeasureAsgnStmt({}, std::move(*(qm.clone())), std::move(*(va.clone())));
        qasmtools::ast::ResetStmt({}, {std::move(*(va.clone()))});
        qasmtools::ast::BarrierStmt({}, {std::move(*(va.clone()))});
        qasmtools::ast::IfStmt({}, {}, {}, {});
        qasmtools::ast::BreakStmt({});
        qasmtools::ast::ContinueStmt({});
        qasmtools::ast::ReturnStmt({}, std::monostate());
        qasmtools::ast::EndStmt({});
        //decl
        qasmtools::ast::QuantumRegisterDecl qrd({}, "quantum_zyx", 3);
        qasmtools::ast::ClassicalRegisterDecl crd({}, "classic_zyx", 3);
    });
}
/******************************************************************************/
