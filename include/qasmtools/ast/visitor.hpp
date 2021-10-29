/*
 * This file is part of qasmtools.
 *
 * Copyright (c) 2019 - 2021 softwareQ Inc. All rights reserved.
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
 * \file qasmtools/ast/visitor.hpp
 * \brief Visitor interface for syntax trees
 */

#pragma once

namespace qasmtools {
namespace ast {

/* Forward declarations */
class BExpr;
class UExpr;
class PiExpr;
class IntExpr;
class RealExpr;
class VarExpr;

/* Completed OpenQASM 3 AST nodes */
class SingleDesignatorType;
class NoDesignatorType;
class BitType;
class ComplexType;
class Program;
class QuantumMeasurement;
class ProgramBlock;
class QuantumBlock;
class QuantumLoopBlock;
class MeasureStmt;
class ExprStmt;
class MeasureAsgnStmt;
class ResetStmt;
class BarrierStmt;
class IfStmt;
class BreakStmt;
class ContinueStmt;
class ReturnStmt;
class EndStmt;
class GateDecl;
class QuantumRegisterDecl;
class ClassicalDecl;
class CtrlModifier;
class InvModifier;
class PowModifier;
class UGate;
class GPhase;
class DeclaredGate;
class RangeSlice;
class ListSlice;
class VarAccess;
class Concat;

/**
 * \class qasmtools::ast::Visitor
 * \brief Base visitor interface
 *
 * Classic visitor via (virtual) double dispatch. Standard usage is to
 * derive from this class and provide implementations of visit for **every**
 * node type.
 *
 * Traversal to sub-nodes is handled by the particular visitor, not the
 * node class. For a visitor that automatically handles traversal and also
 * allows picking and choosing the particular visit overloads, see
 * qasmtools::ast::Traverse.
 */
class Visitor {
  public:
    // Index identifiers
    virtual void visit(RangeSlice&) = 0;
    virtual void visit(ListSlice&) = 0;
    virtual void visit(VarAccess&) = 0;
    virtual void visit(Concat&) = 0;
    // Types
    virtual void visit(SingleDesignatorType&) = 0;
    virtual void visit(NoDesignatorType&) = 0;
    virtual void visit(BitType&) = 0;
    virtual void visit(ComplexType&) = 0;
    // Expressions
    virtual void visit(BExpr&) = 0;
    virtual void visit(UExpr&) = 0;
    virtual void visit(PiExpr&) = 0;
    virtual void visit(IntExpr&) = 0;
    virtual void visit(RealExpr&) = 0;
    virtual void visit(VarExpr&) = 0;
    // Statement components
    virtual void visit(QuantumMeasurement&) = 0;
    virtual void visit(ProgramBlock&) = 0;
    virtual void visit(QuantumLoopBlock&) = 0;
    virtual void visit(QuantumBlock&) = 0;
    // Statements
    virtual void visit(MeasureAsgnStmt&) = 0;
    virtual void visit(MeasureStmt&) = 0;
    virtual void visit(ExprStmt&) = 0;
    virtual void visit(ResetStmt&) = 0;
    virtual void visit(BarrierStmt&) = 0;
    virtual void visit(IfStmt&) = 0;
    virtual void visit(BreakStmt&) = 0;
    virtual void visit(ContinueStmt&) = 0;
    virtual void visit(ReturnStmt&) = 0;
    virtual void visit(EndStmt&) = 0;
    // Gates
    virtual void visit(CtrlModifier&) = 0;
    virtual void visit(InvModifier&) = 0;
    virtual void visit(PowModifier&) = 0;
    virtual void visit(UGate&) = 0;
    virtual void visit(GPhase&) = 0;
    virtual void visit(DeclaredGate&) = 0;
    // Declarations
    virtual void visit(GateDecl&) = 0;
    virtual void visit(QuantumRegisterDecl&) = 0;
    virtual void visit(ClassicalDecl&) = 0;
    // Program
    virtual void visit(Program&) = 0;
    // Destructor
    virtual ~Visitor() = default;
};

} // namespace ast
} // namespace qasmtools
