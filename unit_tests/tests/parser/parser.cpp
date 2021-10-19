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
        ast::VarAccess va({}, "x");
        //expr
        ast::IntExpr expr1({}, 1);
        ast::IntExpr expr2({}, 2);
        //gate modifiers
        ast::CtrlModifier ctrl({}, false, ast::object::clone(expr2));
        ast::CtrlModifier negctrl({}, true, ast::object::clone(expr1));
        ast::InvModifier inv({});
        ast::PowModifier pow({}, ast::object::clone(expr2));

        //program
        ast::Program({}, false, {});

        //stmt
        ast::QuantumMeasurement qm({}, ast::VarAccess(va));
        ast::ProgramBlock({}, {});
        ast::QuantumBlock({}, {});
        ast::QuantumLoopBlock({}, {});
        ast::MeasureStmt({}, ast::QuantumMeasurement(qm));
        ast::ExprStmt({}, {});
        ast::MeasureAsgnStmt({}, ast::QuantumMeasurement(qm), ast::VarAccess(va));
        ast::ResetStmt({}, {ast::VarAccess(va)});
        ast::BarrierStmt({}, {ast::VarAccess(va)});
        ast::IfStmt({}, {}, {}, {});
        ast::BreakStmt({});
        ast::ContinueStmt({});
        ast::ReturnStmt({}, std::monostate());
        ast::EndStmt({});
        //decl
        ast::QuantumRegisterDecl qrd({}, "quantum_zyx", 3);
        ast::ClassicalRegisterDecl crd({}, "classic_zyx", 3);
        //gates
        ast::UGate({}, {}, ast::object::clone(expr1), ast::object::clone(expr1),
                   ast::object::clone(expr1), ast::VarAccess(va));
        ast::GPhase({}, {}, ast::object::clone(expr2), {ast::VarAccess(va)});
        ast::DeclaredGate({}, {}, "mygate", {}, {ast::VarAccess(va)});
    });
}
/******************************************************************************/
