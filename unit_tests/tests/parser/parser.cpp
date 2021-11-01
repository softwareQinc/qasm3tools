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

std::vector<ast::ptr<ast::Expr>> make_expr_list() {
    std::vector<ast::ptr<ast::Expr>> tmp;
    tmp.emplace_back(ast::IntExpr::create({}, 24));
    tmp.emplace_back(ast::RealExpr::create({}, 1.5));
    tmp.emplace_back(ast::ConstantExpr::create({}, ast::Constant::Pi));
    return tmp;
}

// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(ASTNodes, Construction) {
    EXPECT_NO_THROW({
        //expr
        ast::IntExpr expr1({}, 1);
        ast::IntExpr expr2({}, 2);
        ast::IntExpr expr3({}, 3);
        ast::IntExpr expr10({}, 10);
        ast::IntExpr expr32({}, 32);
        //gate modifiers
        ast::CtrlModifier ctrl({}, false, ast::object::clone(expr2));
        ast::CtrlModifier negctrl({}, true, ast::object::clone(expr1));
        ast::InvModifier inv({});
        ast::PowModifier pow({}, ast::object::clone(expr2));
        //slice
        ast::RangeSlice rs({}, ast::object::clone(expr2),
                           ast::object::clone(expr2),
                           ast::object::clone(expr10));
        ast::ListSlice ls({}, make_expr_list());
        //indexid
        ast::VarAccess va({}, "x");
        ast::VarAccess va1({}, "y", ast::object::clone(rs));
        ast::VarAccess va2({}, "z", ast::object::clone(ls));
        ast::Concat con({}, ast::object::clone(va1), ast::object::clone(va2));
        //classical types
        ast::SingleDesignatorType int32({}, ast::SDType::Int,
                                        ast::object::clone(expr32));
        ast::NoDesignatorType boolean({}, ast::NDType::Bool);
        ast::BitType bit({});
        ast::BitType bit2({}, ast::object::clone(expr2));
        ast::ComplexType complex_int32({}, ast::object::clone(int32));

        //program
        ast::Program({}, {}, false);

        //stmt
        ast::QuantumMeasurement qm({}, ast::object::clone(va));
        ast::ProgramBlock pb({}, {});
        ast::QuantumBlock qb({}, {});
        ast::QuantumLoopBlock qlb({}, {});
        ast::MeasureStmt qmst({}, ast::object::clone(qm));
        ast::ExprStmt({}, {});
        ast::MeasureAsgnStmt qmsta({}, ast::object::clone(qm),
                                   ast::object::clone(va));
        ast::ResetStmt({}, make_va_list());
        ast::BarrierStmt({}, make_va_list());
        ast::IfStmt({}, {}, {}, {});
        ast::BreakStmt({});
        ast::ContinueStmt({});
        ast::ReturnStmt({}, std::monostate());
        ast::EndStmt({});
        ast::AliasStmt alias({}, "my_alias", ast::object::clone(va));
        ast::AssignmentStmt asgn({}, "x_assign", ast::AssignOp::Pow,
                                 ast::object::clone(expr32));
        //decl
        ast::GateDecl({}, "mydecl", {}, {}, {});
        ast::QuantumRegisterDecl qrd({}, "quantum_zyx",
                                     ast::object::clone(expr3));
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
        //loops
        ast::ListSet lset({}, make_expr_list());
        ast::ForStmt forstmt({}, "i", ast::object::clone(lset),
                             ast::object::clone(pb));
        ast::WhileStmt whilestmt({}, ast::object::clone(expr1),
                                 ast::object::clone(pb));
        // timing
        ast::BoxStmt box({}, std::nullopt, ast::object::clone(qb));
        ast::DelayStmt delay({}, {}, ast::object::clone(expr1), make_va_list());
        ast::RotaryStmt rot({}, make_expr_list(), ast::object::clone(expr32),
                            make_va_list());

        std::list<ast::ProgramStmt> stmts;
        stmts.emplace_back(ast::object::clone(qmst));
        stmts.emplace_back(ast::object::clone(qmsta));
        stmts.emplace_back(ast::object::clone(qrd));
        stmts.emplace_back(ast::object::clone(cd));
        stmts.emplace_back(ast::object::clone(cd2));
        stmts.emplace_back(ast::object::clone(alias));
        stmts.emplace_back(ast::object::clone(asgn));
        stmts.emplace_back(ast::object::clone(forstmt));
        stmts.emplace_back(ast::object::clone(whilestmt));
        stmts.emplace_back(ast::object::clone(box));
        stmts.emplace_back(ast::object::clone(delay));
        stmts.emplace_back(ast::object::clone(rot));
        auto x = ast::Program::create({}, std::move(stmts), true);
        std::cerr << *x;
    });
}
/******************************************************************************/
