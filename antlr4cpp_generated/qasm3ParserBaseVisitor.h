
// Generated from qasm3Parser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasm3ParserVisitor.h"


/**
 * This class provides an empty implementation of qasm3ParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  qasm3ParserBaseVisitor : public qasm3ParserVisitor {
public:

  virtual antlrcpp::Any visitProgram(qasm3Parser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHeader(qasm3Parser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion(qasm3Parser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude(qasm3Parser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIoIdentifier(qasm3Parser::IoIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIo(qasm3Parser::IoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobalStatement(qasm3Parser::GlobalStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(qasm3Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumDeclarationStatement(qasm3Parser::QuantumDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalDeclarationStatement(qasm3Parser::ClassicalDeclarationStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalAssignment(qasm3Parser::ClassicalAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(qasm3Parser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnSignature(qasm3Parser::ReturnSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesignator(qasm3Parser::DesignatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(qasm3Parser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumDeclaration(qasm3Parser::QuantumDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumArgument(qasm3Parser::QuantumArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitType(qasm3Parser::BitTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleDesignatorType(qasm3Parser::SingleDesignatorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoDesignatorType(qasm3Parser::NoDesignatorTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonArrayType(qasm3Parser::NonArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayType(qasm3Parser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayReferenceTypeDimensionSpecifier(qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayReferenceType(qasm3Parser::ArrayReferenceTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalType(qasm3Parser::ClassicalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumericType(qasm3Parser::NumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstantDeclaration(qasm3Parser::ConstantDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleDesignatorDeclaration(qasm3Parser::SingleDesignatorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNoDesignatorDeclaration(qasm3Parser::NoDesignatorDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitDeclaration(qasm3Parser::BitDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComplexDeclaration(qasm3Parser::ComplexDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayInitializer(qasm3Parser::ArrayInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayDeclaration(qasm3Parser::ArrayDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalDeclaration(qasm3Parser::ClassicalDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalTypeList(qasm3Parser::ClassicalTypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalArgument(qasm3Parser::ClassicalArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassicalArgumentList(qasm3Parser::ClassicalArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnyTypeArgument(qasm3Parser::AnyTypeArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnyTypeArgumentList(qasm3Parser::AnyTypeArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasInitializer(qasm3Parser::AliasInitializerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasStatement(qasm3Parser::AliasStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRangeDefinition(qasm3Parser::RangeDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateDefinition(qasm3Parser::QuantumGateDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateSignature(qasm3Parser::QuantumGateSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateName(qasm3Parser::QuantumGateNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumBlock(qasm3Parser::QuantumBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumLoop(qasm3Parser::QuantumLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumLoopBlock(qasm3Parser::QuantumLoopBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumStatement(qasm3Parser::QuantumStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumInstruction(qasm3Parser::QuantumInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumBarrier(qasm3Parser::QuantumBarrierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumMeasurement(qasm3Parser::QuantumMeasurementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumPhase(qasm3Parser::QuantumPhaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumReset(qasm3Parser::QuantumResetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumMeasurementAssignment(qasm3Parser::QuantumMeasurementAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowModifier(qasm3Parser::PowModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCtrlModifier(qasm3Parser::CtrlModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateModifier(qasm3Parser::QuantumGateModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantumGateCall(qasm3Parser::QuantumGateCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryOperator(qasm3Parser::UnaryOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionStatement(qasm3Parser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(qasm3Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalAndExpression(qasm3Parser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOrExpression(qasm3Parser::BitOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXOrExpression(qasm3Parser::XOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitAndExpression(qasm3Parser::BitAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualityExpression(qasm3Parser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonExpression(qasm3Parser::ComparisonExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitShiftExpression(qasm3Parser::BitShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdditiveExpression(qasm3Parser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiplicativeExpression(qasm3Parser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpression(qasm3Parser::UnaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowerExpression(qasm3Parser::PowerExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexOperator(qasm3Parser::IndexOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexExpression(qasm3Parser::IndexExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionTerminator(qasm3Parser::ExpressionTerminatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuiltInCall(qasm3Parser::BuiltInCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCastOperator(qasm3Parser::CastOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionList(qasm3Parser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualsExpression(qasm3Parser::EqualsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentOperator(qasm3Parser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiscreteSet(qasm3Parser::DiscreteSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetDeclaration(qasm3Parser::SetDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramBlock(qasm3Parser::ProgramBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranchingStatement(qasm3Parser::BranchingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopSignature(qasm3Parser::LoopSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopStatement(qasm3Parser::LoopStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEndStatement(qasm3Parser::EndStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(qasm3Parser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlDirective(qasm3Parser::ControlDirectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternDeclaration(qasm3Parser::ExternDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExternOrSubroutineCall(qasm3Parser::ExternOrSubroutineCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubroutineDefinition(qasm3Parser::SubroutineDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubroutineBlock(qasm3Parser::SubroutineBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma(qasm3Parser::PragmaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingBox(qasm3Parser::TimingBoxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingIdentifier(qasm3Parser::TimingIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingInstruction(qasm3Parser::TimingInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimingStatement(qasm3Parser::TimingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibration(qasm3Parser::CalibrationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationGrammarDeclaration(qasm3Parser::CalibrationGrammarDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationDefinition(qasm3Parser::CalibrationDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCalibrationArgumentList(qasm3Parser::CalibrationArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }


};

