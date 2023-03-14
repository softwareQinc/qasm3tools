/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2023 softwareQ Inc. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file qasm3tools/ast/visitor.hpp
 * \brief Visitor interface for syntax trees
 */

#ifndef QASM3TOOLS_AST_VISITOR_HPP_
#define QASM3TOOLS_AST_VISITOR_HPP_

namespace qasm3tools {
namespace ast {

class SingleIndex;
class RangeIndex;
class IndexEntityList;
class ListSlice;
class IndexId;
class SingleDesignatorType;
class NoDesignatorType;
class ComplexType;
class ArrayType;
class ArrayRefType;
class QubitType;
class BExpr;
class UExpr;
class MathExpr;
class CastExpr;
class SizeofExpr;
class FunctionCall;
class AccessExpr;
class ConstantExpr;
class IntExpr;
class RealExpr;
class ImagExpr;
class BoolExpr;
class VarExpr;
class BitString;
class ArrayInitExpr;
class TimeExpr;
class DurationofExpr;
class MeasureExpr;
class Annotation;
class ProgramBlock;
class ExprStmt;
class ResetStmt;
class BarrierStmt;
class IfStmt;
class BreakStmt;
class ContinueStmt;
class ReturnStmt;
class EndStmt;
class AliasStmt;
class AssignmentStmt;
class PragmaStmt;
class CtrlModifier;
class InvModifier;
class PowModifier;
class UGate;
class GPhase;
class DeclaredGate;
class RangeSet;
class ListSet;
class VarSet;
class ForStmt;
class WhileStmt;
class DelayStmt;
class BoxStmt;
class Param;
class SubroutineDecl;
class ExternDecl;
class GateDecl;
class QuantumDecl;
class ClassicalDecl;
class IODecl;
class Program;

/**
 * \class qasm3tools::ast::Visitor
 * \brief Base visitor interface
 *
 * Classic visitor via (virtual) double dispatch. Standard usage is to
 * derive from this class and provide implementations of visit for **every**
 * node type.
 *
 * Traversal to sub-nodes is handled by the particular visitor, not the
 * node class.
 */
class Visitor {
  public:
    // Index identifiers
    virtual void visit(SingleIndex&) = 0;
    virtual void visit(RangeIndex&) = 0;
    virtual void visit(IndexEntityList&) = 0;
    virtual void visit(ListSlice&) = 0;
    virtual void visit(IndexId&) = 0;
    // Types
    virtual void visit(SingleDesignatorType&) = 0;
    virtual void visit(NoDesignatorType&) = 0;
    virtual void visit(ComplexType&) = 0;
    virtual void visit(ArrayType&) = 0;
    virtual void visit(ArrayRefType&) = 0;
    virtual void visit(QubitType&) = 0;
    // Expressions
    virtual void visit(BExpr&) = 0;
    virtual void visit(UExpr&) = 0;
    virtual void visit(MathExpr&) = 0;
    virtual void visit(CastExpr&) = 0;
    virtual void visit(SizeofExpr&) = 0;
    virtual void visit(FunctionCall&) = 0;
    virtual void visit(AccessExpr&) = 0;
    virtual void visit(ConstantExpr&) = 0;
    virtual void visit(IntExpr&) = 0;
    virtual void visit(RealExpr&) = 0;
    virtual void visit(ImagExpr&) = 0;
    virtual void visit(BoolExpr&) = 0;
    virtual void visit(VarExpr&) = 0;
    virtual void visit(BitString&) = 0;
    virtual void visit(ArrayInitExpr&) = 0;
    virtual void visit(TimeExpr&) = 0;
    virtual void visit(DurationofExpr&) = 0;
    virtual void visit(MeasureExpr&) = 0;
    // Statements
    virtual void visit(Annotation&) = 0;
    virtual void visit(ProgramBlock&) = 0;
    virtual void visit(ExprStmt&) = 0;
    virtual void visit(ResetStmt&) = 0;
    virtual void visit(BarrierStmt&) = 0;
    virtual void visit(IfStmt&) = 0;
    virtual void visit(BreakStmt&) = 0;
    virtual void visit(ContinueStmt&) = 0;
    virtual void visit(ReturnStmt&) = 0;
    virtual void visit(EndStmt&) = 0;
    virtual void visit(AliasStmt&) = 0;
    virtual void visit(AssignmentStmt&) = 0;
    virtual void visit(PragmaStmt&) = 0;
    // Gates
    virtual void visit(CtrlModifier&) = 0;
    virtual void visit(InvModifier&) = 0;
    virtual void visit(PowModifier&) = 0;
    virtual void visit(UGate&) = 0;
    virtual void visit(GPhase&) = 0;
    virtual void visit(DeclaredGate&) = 0;
    // Loops
    virtual void visit(RangeSet&) = 0;
    virtual void visit(ListSet&) = 0;
    virtual void visit(VarSet&) = 0;
    virtual void visit(ForStmt&) = 0;
    virtual void visit(WhileStmt&) = 0;
    // Timing Statements
    virtual void visit(DelayStmt&) = 0;
    virtual void visit(BoxStmt&) = 0;
    // Declarations
    virtual void visit(Param&) = 0;
    virtual void visit(SubroutineDecl&) = 0;
    virtual void visit(ExternDecl&) = 0;
    virtual void visit(GateDecl&) = 0;
    virtual void visit(QuantumDecl&) = 0;
    virtual void visit(ClassicalDecl&) = 0;
    virtual void visit(IODecl&) = 0;
    // Program
    virtual void visit(Program&) = 0;
    // Destructor
    virtual ~Visitor() = default;
};

} /* namespace ast */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_AST_VISITOR_HPP_ */
