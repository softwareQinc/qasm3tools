
// Generated from qasm3Parser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "qasm3Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by qasm3Parser.
 */
class  qasm3ParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by qasm3Parser.
   */
    virtual antlrcpp::Any visitProgram(qasm3Parser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitVersion(qasm3Parser::VersionContext *context) = 0;

    virtual antlrcpp::Any visitStatement(qasm3Parser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAnnotation(qasm3Parser::AnnotationContext *context) = 0;

    virtual antlrcpp::Any visitScope(qasm3Parser::ScopeContext *context) = 0;

    virtual antlrcpp::Any visitPragma(qasm3Parser::PragmaContext *context) = 0;

    virtual antlrcpp::Any visitStatementOrScope(qasm3Parser::StatementOrScopeContext *context) = 0;

    virtual antlrcpp::Any visitCalibrationGrammarStatement(qasm3Parser::CalibrationGrammarStatementContext *context) = 0;

    virtual antlrcpp::Any visitIncludeStatement(qasm3Parser::IncludeStatementContext *context) = 0;

    virtual antlrcpp::Any visitBreakStatement(qasm3Parser::BreakStatementContext *context) = 0;

    virtual antlrcpp::Any visitContinueStatement(qasm3Parser::ContinueStatementContext *context) = 0;

    virtual antlrcpp::Any visitEndStatement(qasm3Parser::EndStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(qasm3Parser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(qasm3Parser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(qasm3Parser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(qasm3Parser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitBarrierStatement(qasm3Parser::BarrierStatementContext *context) = 0;

    virtual antlrcpp::Any visitBoxStatement(qasm3Parser::BoxStatementContext *context) = 0;

    virtual antlrcpp::Any visitDelayStatement(qasm3Parser::DelayStatementContext *context) = 0;

    virtual antlrcpp::Any visitGateCallStatement(qasm3Parser::GateCallStatementContext *context) = 0;

    virtual antlrcpp::Any visitMeasureArrowAssignmentStatement(qasm3Parser::MeasureArrowAssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitResetStatement(qasm3Parser::ResetStatementContext *context) = 0;

    virtual antlrcpp::Any visitAliasDeclarationStatement(qasm3Parser::AliasDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitClassicalDeclarationStatement(qasm3Parser::ClassicalDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitConstDeclarationStatement(qasm3Parser::ConstDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitIoDeclarationStatement(qasm3Parser::IoDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitOldStyleDeclarationStatement(qasm3Parser::OldStyleDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitQuantumDeclarationStatement(qasm3Parser::QuantumDeclarationStatementContext *context) = 0;

    virtual antlrcpp::Any visitDefStatement(qasm3Parser::DefStatementContext *context) = 0;

    virtual antlrcpp::Any visitExternStatement(qasm3Parser::ExternStatementContext *context) = 0;

    virtual antlrcpp::Any visitGateStatement(qasm3Parser::GateStatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(qasm3Parser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(qasm3Parser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitCalStatement(qasm3Parser::CalStatementContext *context) = 0;

    virtual antlrcpp::Any visitDefcalStatement(qasm3Parser::DefcalStatementContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseXorExpression(qasm3Parser::BitwiseXorExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(qasm3Parser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDurationofExpression(qasm3Parser::DurationofExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParenthesisExpression(qasm3Parser::ParenthesisExpressionContext *context) = 0;

    virtual antlrcpp::Any visitComparisonExpression(qasm3Parser::ComparisonExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(qasm3Parser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(qasm3Parser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCastExpression(qasm3Parser::CastExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPowerExpression(qasm3Parser::PowerExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseOrExpression(qasm3Parser::BitwiseOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCallExpression(qasm3Parser::CallExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitshiftExpression(qasm3Parser::BitshiftExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBitwiseAndExpression(qasm3Parser::BitwiseAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(qasm3Parser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(qasm3Parser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIndexExpression(qasm3Parser::IndexExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(qasm3Parser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpression(qasm3Parser::LiteralExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAliasExpression(qasm3Parser::AliasExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationExpression(qasm3Parser::DeclarationExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMeasureExpression(qasm3Parser::MeasureExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRangeExpression(qasm3Parser::RangeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSetExpression(qasm3Parser::SetExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArrayLiteral(qasm3Parser::ArrayLiteralContext *context) = 0;

    virtual antlrcpp::Any visitIndexOperator(qasm3Parser::IndexOperatorContext *context) = 0;

    virtual antlrcpp::Any visitIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitReturnSignature(qasm3Parser::ReturnSignatureContext *context) = 0;

    virtual antlrcpp::Any visitGateModifier(qasm3Parser::GateModifierContext *context) = 0;

    virtual antlrcpp::Any visitScalarType(qasm3Parser::ScalarTypeContext *context) = 0;

    virtual antlrcpp::Any visitQubitType(qasm3Parser::QubitTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayType(qasm3Parser::ArrayTypeContext *context) = 0;

    virtual antlrcpp::Any visitArrayReferenceType(qasm3Parser::ArrayReferenceTypeContext *context) = 0;

    virtual antlrcpp::Any visitDesignator(qasm3Parser::DesignatorContext *context) = 0;

    virtual antlrcpp::Any visitDefcalTarget(qasm3Parser::DefcalTargetContext *context) = 0;

    virtual antlrcpp::Any visitDefcalArgumentDefinition(qasm3Parser::DefcalArgumentDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitDefcalOperand(qasm3Parser::DefcalOperandContext *context) = 0;

    virtual antlrcpp::Any visitGateOperand(qasm3Parser::GateOperandContext *context) = 0;

    virtual antlrcpp::Any visitExternArgument(qasm3Parser::ExternArgumentContext *context) = 0;

    virtual antlrcpp::Any visitArgumentDefinition(qasm3Parser::ArgumentDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentDefinitionList(qasm3Parser::ArgumentDefinitionListContext *context) = 0;

    virtual antlrcpp::Any visitDefcalArgumentDefinitionList(qasm3Parser::DefcalArgumentDefinitionListContext *context) = 0;

    virtual antlrcpp::Any visitDefcalOperandList(qasm3Parser::DefcalOperandListContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(qasm3Parser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(qasm3Parser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitGateOperandList(qasm3Parser::GateOperandListContext *context) = 0;

    virtual antlrcpp::Any visitExternArgumentList(qasm3Parser::ExternArgumentListContext *context) = 0;


};

