#ifndef PATH
#define PATH "../../"
#endif

#include "gtest/gtest.h"
#include "qasmtools/ast/ast.hpp"

#include <sstream>

using namespace qasmtools::ast;

std::vector<ptr<IndexId>> make_va_list() {
    std::vector<ptr<IndexId>> tmp;
    tmp.emplace_back(VarAccess::create({}, "a"));
    tmp.emplace_back(VarAccess::create({}, "b"));
    tmp.emplace_back(VarAccess::create({}, "c"));
    return tmp;
}

std::vector<ptr<Expr>> make_expr_list() {
    std::vector<ptr<Expr>> tmp;
    tmp.emplace_back(IntExpr::create({}, 24));
    tmp.emplace_back(RealExpr::create({}, 1.5));
    tmp.emplace_back(ConstantExpr::create({}, Constant::Pi));
    return tmp;
}

std::vector<ptr<ClassicalType>> make_ctype_list() {
    std::vector<ptr<ClassicalType>> tmp;
    tmp.emplace_back(NoDesignatorType::create({}, NDType::Bool));
    tmp.emplace_back(BitType::create({}));
    return tmp;
}

std::vector<ptr<Param>> make_param_list() {
    std::vector<ptr<Param>> tmp;
    tmp.emplace_back(ClassicalParam::create({}, "ct",
        NoDesignatorType::create({}, NDType::Bool)));
    tmp.emplace_back(QubitParam::create({}, "qt"));
    return tmp;
}

// Parsing & semantic analysis unit tests
/******************************************************************************/
TEST(ASTNodes, Construction) {
    EXPECT_NO_THROW({
        //expr
        IntExpr expr1({}, 1);
        IntExpr expr2({}, 2);
        IntExpr expr3({}, 3);
        IntExpr expr10({}, 10);
        IntExpr expr32({}, 32);
        //gate modifiers
        CtrlModifier ctrl({}, false, object::clone(expr2));
        CtrlModifier negctrl({}, true, object::clone(expr1));
        InvModifier inv({});
        PowModifier pow({}, object::clone(expr2));
        //slice
        RangeSlice rs({}, object::clone(expr2),
                      object::clone(expr2),
                      object::clone(expr10));
        ListSlice ls({}, make_expr_list());
        //indexid
        VarAccess va({}, "x");
        VarAccess va1({}, "y", object::clone(rs));
        VarAccess va2({}, "z", object::clone(ls));
        Concat con({}, object::clone(va1), object::clone(va2));
        //classical types
        SingleDesignatorType int32({}, SDType::Int, object::clone(expr32));
        NoDesignatorType boolean({}, NDType::Bool);
        BitType bit({});
        BitType bit2({}, object::clone(expr2));
        ComplexType complex_int32({}, object::clone(int32));

        //program
        Program({}, {}, false);

        //stmt
        QuantumMeasurement qm({}, object::clone(va));
        ProgramBlock pb({}, {});
        QuantumBlock qb({}, {});
        MeasureStmt qmst({}, object::clone(qm));
         qb.body().emplace_back(object::clone(qmst));
        ExprStmt({}, {});
        MeasureAsgnStmt qmsta({}, object::clone(qm), object::clone(va));
        ResetStmt reset({}, make_va_list());
         pb.body().emplace_back(object::clone(reset));
        BarrierStmt bar({}, make_va_list());
         qb.body().emplace_back(object::clone(bar));
        IfStmt({}, {}, {}, {});
        BreakStmt({});
        ContinueStmt({});
        ReturnStmt({}, std::monostate());
        EndStmt({});
        AliasStmt alias({}, "my_alias", object::clone(va));
        AssignmentStmt asgn({}, "x_assign", AssignOp::Pow,
                            object::clone(expr32));
        //decl
        SubroutineDecl sub({}, "my_subroutine", make_param_list(),
                           object::clone(pb));
        ExternDecl ext({}, "my_external", make_ctype_list(),
                       object::clone(complex_int32));
        GateDecl({}, "mydecl", {}, {}, {});
        QuantumRegisterDecl qrd({}, "quantum_zyx",
                                object::clone(expr3));
        ClassicalDecl cd({}, "complex_int32",
                         object::clone(complex_int32));
        ClassicalDecl cd2({}, "complex_int32_2",
                          object::clone(complex_int32),
                          object::clone(expr2), true);
        CalGrammarDecl openpulse({}, "\"openpulse\"");
        CalibrationDecl cal({}, "calib", std::monostate(), {"$0", "$2"},
                            object::clone(complex_int32), "--foo--");
        CalibrationDecl cal2({}, "calib", make_expr_list(), {"x"},
                             std::nullopt, "--bar--");
        //gates
        UGate({}, {}, object::clone(expr1), object::clone(expr1),
              object::clone(expr1), object::clone(va));
        GPhase({}, {}, object::clone(expr2), make_va_list());
        DeclaredGate ({}, {}, "mygate", {}, make_va_list());
        //loops
        ListSet lset({}, make_expr_list());
        QuantumForStmt forstmt({}, "i", object::clone(lset), object::clone(qb));
         forstmt.body().body().emplace_back(object::clone(forstmt));
        WhileStmt whilestmt({}, object::clone(expr1), object::clone(pb));
        PragmaStmt ps({}, {});
        // timing
        BoxStmt box({}, std::nullopt, object::clone(qb));
         box.circuit().body().emplace_back(object::clone(forstmt));
        DelayStmt delay({}, {}, object::clone(expr1), make_va_list());
        RotaryStmt rot({}, make_expr_list(), object::clone(expr32),
                       make_va_list());

        std::list<ProgramStmt> stmts;
        stmts.emplace_back(object::clone(qmst));
        stmts.emplace_back(object::clone(qmsta));
        stmts.emplace_back(object::clone(qrd));
        stmts.emplace_back(object::clone(cd));
        stmts.emplace_back(object::clone(cd2));
        stmts.emplace_back(object::clone(alias));
        stmts.emplace_back(object::clone(asgn));
        stmts.emplace_back(object::clone(forstmt));
        stmts.emplace_back(object::clone(whilestmt));
        stmts.emplace_back(object::clone(box));
        stmts.emplace_back(object::clone(delay));
        stmts.emplace_back(object::clone(rot));
        stmts.emplace_back(object::clone(sub));
        stmts.emplace_back(object::clone(ext));
        stmts.emplace_back(object::clone(ps));
        stmts.emplace_back(object::clone(openpulse));
        stmts.emplace_back(object::clone(cal));
        stmts.emplace_back(object::clone(cal2));
        auto x = Program::create({}, std::move(stmts), true);
        std::cerr << *x;
    });
}
/******************************************************************************/
