#ifndef PATH
#define PATH "../../"
#endif

#include "gtest/gtest.h"
#include "qasmtools/ast/ast.hpp"

#include <sstream>

using namespace qasmtools;

std::vector<ast::ptr<ast::IndexId>> make_va_list() {
    std::vector<ast::ptr<ast::IndexId>> tmp;
    tmp.emplace_back(ast::VarAccess::create({}, "a"));
    tmp.emplace_back(ast::VarAccess::create({}, "b"));
    tmp.emplace_back(ast::VarAccess::create({}, "c"));
    return tmp;
}
/*
std::vector<ast::ptr<ast::Expr>> make_expr_list() {
    std::vector<ast::ptr<ast::Expr>> tmp;
    tmp.emplace_back(ast::IntExpr::create({}, 24));
    tmp.emplace_back(ast::RealExpr::create({}, 1.5));
    tmp.emplace_back(ast::PiExpr::create({}));
    return tmp;
}
*/
// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(ASTNodes, Construction) {
    EXPECT_NO_THROW({
        //expr
        ast::IntExpr expr1({}, 1);
        ast::IntExpr expr2({}, 2);
        ast::IntExpr expr10({}, 10);
        //gate modifiers
        ast::CtrlModifier ctrl({}, false, ast::object::clone(expr2));
        ast::CtrlModifier negctrl({}, true, ast::object::clone(expr1));
        ast::InvModifier inv({});
        ast::PowModifier pow({}, ast::object::clone(expr2));
        //slice
        ast::RangeSlice rs({}, 2, 2, 10);
        ast::ListSlice ls({}, {1,3,6});
        //indexid
        ast::VarAccess va({}, "x");
        ast::VarAccess va1({}, "y", ast::object::clone(rs));
        ast::VarAccess va2({}, "z", ast::object::clone(ls));
        ast::Concat con({}, ast::object::clone(va1), ast::object::clone(va2));
        //classical types
        ast::SingleDesignatorType int32({}, ast::SDType::Int, 32);
        ast::NoDesignatorType boolean({}, ast::NDType::Bool);
        ast::BitType bit({});
        ast::BitType bit2({}, 2);
        ast::ComplexType complex_int32({}, int32);

        //program
        ast::Program({}, false, {});

        //stmt
        ast::QuantumMeasurement qm({}, ast::object::clone(va));
        ast::ProgramBlock({}, {});
        ast::QuantumBlock({}, {});
        ast::QuantumLoopBlock({}, {});
        ast::MeasureStmt({}, ast::object::clone(qm));
        ast::ExprStmt({}, {});
        ast::MeasureAsgnStmt({}, ast::object::clone(qm),
                             ast::object::clone(va));
        ast::ResetStmt({}, make_va_list());
        ast::BarrierStmt({}, make_va_list());
        ast::IfStmt({}, {}, {}, {});
        ast::BreakStmt({});
        ast::ContinueStmt({});
        ast::ReturnStmt({}, std::monostate());
        ast::EndStmt({});
        //decl
        ast::GateDecl({}, "mydecl", {}, {}, {});
        ast::QuantumRegisterDecl qrd({}, "quantum_zyx", 3);
        ast::ClassicalDecl cd({}, "complex_int32",
                              ast::object::clone(complex_int32));
        ast::ClassicalDecl cd2({}, "complex_int32_2",
                               ast::object::clone(complex_int32),
                               ast::object::clone(expr2), true);
        //gates
        ast::UGate({}, {}, ast::object::clone(expr1), ast::object::clone(expr1),
                   ast::object::clone(expr1), ast::object::clone(va));
        ast::GPhase({}, {}, ast::object::clone(expr2), make_va_list());
        ast::DeclaredGate({}, {}, "mygate", {}, make_va_list());
    });
}
/******************************************************************************/
