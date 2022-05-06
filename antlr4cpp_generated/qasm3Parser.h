
// Generated from qasm3Parser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  qasm3Parser : public antlr4::Parser {
public:
  enum {
    OPENQASM = 1, INCLUDE = 2, PRAGMA = 3, DEFCALGRAMMAR = 4, DEF = 5, DEFCAL = 6, 
    GATE = 7, EXTERN = 8, BOX = 9, LET = 10, BREAK = 11, CONTINUE = 12, 
    IF = 13, ELSE = 14, END = 15, RETURN = 16, FOR = 17, WHILE = 18, IN = 19, 
    INPUT = 20, OUTPUT = 21, CONST = 22, MUTABLE = 23, QREG = 24, QUBIT = 25, 
    CREG = 26, BOOL = 27, BIT = 28, INT = 29, UINT = 30, FLOAT = 31, ANGLE = 32, 
    COMPLEX = 33, ARRAY = 34, DURATION = 35, STRETCH = 36, U_ = 37, CX = 38, 
    GPHASE = 39, INV = 40, POW = 41, CTRL = 42, NEGCTRL = 43, DIM = 44, 
    SIZEOF = 45, BuiltinMath = 46, DURATIONOF = 47, BuiltinTimingInstruction = 48, 
    RESET = 49, MEASURE = 50, BARRIER = 51, BooleanLiteral = 52, LBRACKET = 53, 
    RBRACKET = 54, LBRACE = 55, RBRACE = 56, LPAREN = 57, RPAREN = 58, COLON = 59, 
    SEMICOLON = 60, DOT = 61, COMMA = 62, EQUALS = 63, ARROW = 64, PLUS = 65, 
    DOUBLE_PLUS = 66, MINUS = 67, ASTERISK = 68, DOUBLE_ASTERISK = 69, SLASH = 70, 
    PERCENT = 71, PIPE = 72, DOUBLE_PIPE = 73, AMPERSAND = 74, DOUBLE_AMPERSAND = 75, 
    CARET = 76, AT = 77, TILDE = 78, EXCLAMATION_POINT = 79, EqualityOperator = 80, 
    CompoundAssignmentOperator = 81, ComparisonOperator = 82, BitshiftOperator = 83, 
    IMAG = 84, ImaginaryLiteral = 85, Constant = 86, BinaryIntegerLiteral = 87, 
    OctalIntegerLiteral = 88, DecimalIntegerLiteral = 89, HexIntegerLiteral = 90, 
    Identifier = 91, FloatLiteral = 92, TimingLiteral = 93, BitstringLiteral = 94, 
    StringLiteral = 95, Whitespace = 96, Newline = 97, LineComment = 98, 
    BlockComment = 99
  };

  enum {
    RuleProgram = 0, RuleHeader = 1, RuleVersion = 2, RuleInclude = 3, RuleIoIdentifier = 4, 
    RuleIo = 5, RuleGlobalStatement = 6, RuleStatement = 7, RuleQuantumDeclarationStatement = 8, 
    RuleClassicalDeclarationStatement = 9, RuleClassicalAssignment = 10, 
    RuleAssignmentStatement = 11, RuleReturnSignature = 12, RuleDesignator = 13, 
    RuleIdentifierList = 14, RuleQuantumDeclaration = 15, RuleQuantumArgument = 16, 
    RuleBitType = 17, RuleSingleDesignatorType = 18, RuleNoDesignatorType = 19, 
    RuleNonArrayType = 20, RuleArrayType = 21, RuleArrayReferenceTypeDimensionSpecifier = 22, 
    RuleArrayReferenceType = 23, RuleClassicalType = 24, RuleNumericType = 25, 
    RuleConstantDeclaration = 26, RuleSingleDesignatorDeclaration = 27, 
    RuleNoDesignatorDeclaration = 28, RuleBitDeclaration = 29, RuleComplexDeclaration = 30, 
    RuleArrayInitializer = 31, RuleArrayDeclaration = 32, RuleClassicalDeclaration = 33, 
    RuleClassicalTypeList = 34, RuleClassicalArgument = 35, RuleClassicalArgumentList = 36, 
    RuleAnyTypeArgument = 37, RuleAnyTypeArgumentList = 38, RuleAliasInitializer = 39, 
    RuleAliasStatement = 40, RuleRangeDefinition = 41, RuleQuantumGateDefinition = 42, 
    RuleQuantumGateSignature = 43, RuleQuantumGateName = 44, RuleQuantumBlock = 45, 
    RuleQuantumLoop = 46, RuleQuantumLoopBlock = 47, RuleQuantumStatement = 48, 
    RuleQuantumInstruction = 49, RuleQuantumBarrier = 50, RuleQuantumMeasurement = 51, 
    RuleQuantumPhase = 52, RuleQuantumReset = 53, RuleQuantumMeasurementAssignment = 54, 
    RulePowModifier = 55, RuleCtrlModifier = 56, RuleQuantumGateModifier = 57, 
    RuleQuantumGateCall = 58, RuleUnaryOperator = 59, RuleExpressionStatement = 60, 
    RuleExpression = 61, RuleLogicalAndExpression = 62, RuleBitOrExpression = 63, 
    RuleXOrExpression = 64, RuleBitAndExpression = 65, RuleEqualityExpression = 66, 
    RuleComparisonExpression = 67, RuleBitShiftExpression = 68, RuleAdditiveExpression = 69, 
    RuleMultiplicativeExpression = 70, RuleUnaryExpression = 71, RulePowerExpression = 72, 
    RuleIndexOperator = 73, RuleIndexExpression = 74, RuleIndexedIdentifier = 75, 
    RuleExpressionTerminator = 76, RuleBuiltInCall = 77, RuleCastOperator = 78, 
    RuleExpressionList = 79, RuleEqualsExpression = 80, RuleAssignmentOperator = 81, 
    RuleDiscreteSet = 82, RuleSetDeclaration = 83, RuleProgramBlock = 84, 
    RuleBranchingStatement = 85, RuleLoopSignature = 86, RuleLoopStatement = 87, 
    RuleEndStatement = 88, RuleReturnStatement = 89, RuleControlDirective = 90, 
    RuleExternDeclaration = 91, RuleExternOrSubroutineCall = 92, RuleSubroutineDefinition = 93, 
    RuleSubroutineBlock = 94, RulePragma = 95, RuleTimingBox = 96, RuleTimingIdentifier = 97, 
    RuleTimingInstruction = 98, RuleTimingStatement = 99, RuleCalibration = 100, 
    RuleCalibrationGrammarDeclaration = 101, RuleCalibrationDefinition = 102, 
    RuleCalibrationArgumentList = 103
  };

  explicit qasm3Parser(antlr4::TokenStream *input);
  ~qasm3Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class HeaderContext;
  class VersionContext;
  class IncludeContext;
  class IoIdentifierContext;
  class IoContext;
  class GlobalStatementContext;
  class StatementContext;
  class QuantumDeclarationStatementContext;
  class ClassicalDeclarationStatementContext;
  class ClassicalAssignmentContext;
  class AssignmentStatementContext;
  class ReturnSignatureContext;
  class DesignatorContext;
  class IdentifierListContext;
  class QuantumDeclarationContext;
  class QuantumArgumentContext;
  class BitTypeContext;
  class SingleDesignatorTypeContext;
  class NoDesignatorTypeContext;
  class NonArrayTypeContext;
  class ArrayTypeContext;
  class ArrayReferenceTypeDimensionSpecifierContext;
  class ArrayReferenceTypeContext;
  class ClassicalTypeContext;
  class NumericTypeContext;
  class ConstantDeclarationContext;
  class SingleDesignatorDeclarationContext;
  class NoDesignatorDeclarationContext;
  class BitDeclarationContext;
  class ComplexDeclarationContext;
  class ArrayInitializerContext;
  class ArrayDeclarationContext;
  class ClassicalDeclarationContext;
  class ClassicalTypeListContext;
  class ClassicalArgumentContext;
  class ClassicalArgumentListContext;
  class AnyTypeArgumentContext;
  class AnyTypeArgumentListContext;
  class AliasInitializerContext;
  class AliasStatementContext;
  class RangeDefinitionContext;
  class QuantumGateDefinitionContext;
  class QuantumGateSignatureContext;
  class QuantumGateNameContext;
  class QuantumBlockContext;
  class QuantumLoopContext;
  class QuantumLoopBlockContext;
  class QuantumStatementContext;
  class QuantumInstructionContext;
  class QuantumBarrierContext;
  class QuantumMeasurementContext;
  class QuantumPhaseContext;
  class QuantumResetContext;
  class QuantumMeasurementAssignmentContext;
  class PowModifierContext;
  class CtrlModifierContext;
  class QuantumGateModifierContext;
  class QuantumGateCallContext;
  class UnaryOperatorContext;
  class ExpressionStatementContext;
  class ExpressionContext;
  class LogicalAndExpressionContext;
  class BitOrExpressionContext;
  class XOrExpressionContext;
  class BitAndExpressionContext;
  class EqualityExpressionContext;
  class ComparisonExpressionContext;
  class BitShiftExpressionContext;
  class AdditiveExpressionContext;
  class MultiplicativeExpressionContext;
  class UnaryExpressionContext;
  class PowerExpressionContext;
  class IndexOperatorContext;
  class IndexExpressionContext;
  class IndexedIdentifierContext;
  class ExpressionTerminatorContext;
  class BuiltInCallContext;
  class CastOperatorContext;
  class ExpressionListContext;
  class EqualsExpressionContext;
  class AssignmentOperatorContext;
  class DiscreteSetContext;
  class SetDeclarationContext;
  class ProgramBlockContext;
  class BranchingStatementContext;
  class LoopSignatureContext;
  class LoopStatementContext;
  class EndStatementContext;
  class ReturnStatementContext;
  class ControlDirectiveContext;
  class ExternDeclarationContext;
  class ExternOrSubroutineCallContext;
  class SubroutineDefinitionContext;
  class SubroutineBlockContext;
  class PragmaContext;
  class TimingBoxContext;
  class TimingIdentifierContext;
  class TimingInstructionContext;
  class TimingStatementContext;
  class CalibrationContext;
  class CalibrationGrammarDeclarationContext;
  class CalibrationDefinitionContext;
  class CalibrationArgumentListContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HeaderContext *header();
    std::vector<GlobalStatementContext *> globalStatement();
    GlobalStatementContext* globalStatement(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  HeaderContext : public antlr4::ParserRuleContext {
  public:
    HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VersionContext *version();
    std::vector<IncludeContext *> include();
    IncludeContext* include(size_t i);
    std::vector<IoContext *> io();
    IoContext* io(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HeaderContext* header();

  class  VersionContext : public antlr4::ParserRuleContext {
  public:
    VersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPENQASM();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *DecimalIntegerLiteral();
    antlr4::tree::TerminalNode *FloatLiteral();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VersionContext* version();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  IoIdentifierContext : public antlr4::ParserRuleContext {
  public:
    IoIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *OUTPUT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IoIdentifierContext* ioIdentifier();

  class  IoContext : public antlr4::ParserRuleContext {
  public:
    IoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IoIdentifierContext *ioIdentifier();
    ClassicalTypeContext *classicalType();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IoContext* io();

  class  GlobalStatementContext : public antlr4::ParserRuleContext {
  public:
    GlobalStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SubroutineDefinitionContext *subroutineDefinition();
    ExternDeclarationContext *externDeclaration();
    QuantumGateDefinitionContext *quantumGateDefinition();
    CalibrationContext *calibration();
    QuantumDeclarationStatementContext *quantumDeclarationStatement();
    PragmaContext *pragma();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GlobalStatementContext* globalStatement();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionStatementContext *expressionStatement();
    AssignmentStatementContext *assignmentStatement();
    ClassicalDeclarationStatementContext *classicalDeclarationStatement();
    BranchingStatementContext *branchingStatement();
    LoopStatementContext *loopStatement();
    EndStatementContext *endStatement();
    AliasStatementContext *aliasStatement();
    QuantumStatementContext *quantumStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  QuantumDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    QuantumDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumDeclarationContext *quantumDeclaration();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumDeclarationStatementContext* quantumDeclarationStatement();

  class  ClassicalDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    ClassicalDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ClassicalDeclarationContext *classicalDeclaration();
    ConstantDeclarationContext *constantDeclaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalDeclarationStatementContext* classicalDeclarationStatement();

  class  ClassicalAssignmentContext : public antlr4::ParserRuleContext {
  public:
    ClassicalAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexedIdentifierContext *indexedIdentifier();
    AssignmentOperatorContext *assignmentOperator();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalAssignmentContext* classicalAssignment();

  class  AssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    AssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ClassicalAssignmentContext *classicalAssignment();
    QuantumMeasurementAssignmentContext *quantumMeasurementAssignment();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStatementContext* assignmentStatement();

  class  ReturnSignatureContext : public antlr4::ParserRuleContext {
  public:
    ReturnSignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARROW();
    ClassicalTypeContext *classicalType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnSignatureContext* returnSignature();

  class  DesignatorContext : public antlr4::ParserRuleContext {
  public:
    DesignatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DesignatorContext* designator();

  class  IdentifierListContext : public antlr4::ParserRuleContext {
  public:
    IdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierListContext* identifierList();

  class  QuantumDeclarationContext : public antlr4::ParserRuleContext {
  public:
    QuantumDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QREG();
    antlr4::tree::TerminalNode *Identifier();
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *QUBIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumDeclarationContext* quantumDeclaration();

  class  QuantumArgumentContext : public antlr4::ParserRuleContext {
  public:
    QuantumArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QREG();
    antlr4::tree::TerminalNode *Identifier();
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *QUBIT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumArgumentContext* quantumArgument();

  class  BitTypeContext : public antlr4::ParserRuleContext {
  public:
    BitTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT();
    antlr4::tree::TerminalNode *CREG();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitTypeContext* bitType();

  class  SingleDesignatorTypeContext : public antlr4::ParserRuleContext {
  public:
    SingleDesignatorTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *ANGLE();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleDesignatorTypeContext* singleDesignatorType();

  class  NoDesignatorTypeContext : public antlr4::ParserRuleContext {
  public:
    NoDesignatorTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *DURATION();
    antlr4::tree::TerminalNode *STRETCH();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoDesignatorTypeContext* noDesignatorType();

  class  NonArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    NonArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorTypeContext *singleDesignatorType();
    NoDesignatorTypeContext *noDesignatorType();
    BitTypeContext *bitType();
    antlr4::tree::TerminalNode *COMPLEX();
    antlr4::tree::TerminalNode *LBRACKET();
    NumericTypeContext *numericType();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonArrayTypeContext* nonArrayType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LBRACKET();
    NonArrayTypeContext *nonArrayType();
    antlr4::tree::TerminalNode *COMMA();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  ArrayReferenceTypeDimensionSpecifierContext : public antlr4::ParserRuleContext {
  public:
    ArrayReferenceTypeDimensionSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *DIM();
    antlr4::tree::TerminalNode *EQUALS();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayReferenceTypeDimensionSpecifierContext* arrayReferenceTypeDimensionSpecifier();

  class  ArrayReferenceTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayReferenceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LBRACKET();
    NonArrayTypeContext *nonArrayType();
    antlr4::tree::TerminalNode *COMMA();
    ArrayReferenceTypeDimensionSpecifierContext *arrayReferenceTypeDimensionSpecifier();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayReferenceTypeContext* arrayReferenceType();

  class  ClassicalTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassicalTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonArrayTypeContext *nonArrayType();
    ArrayTypeContext *arrayType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalTypeContext* classicalType();

  class  NumericTypeContext : public antlr4::ParserRuleContext {
  public:
    NumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorTypeContext *singleDesignatorType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumericTypeContext* numericType();

  class  ConstantDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstantDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    ClassicalTypeContext *classicalType();
    antlr4::tree::TerminalNode *Identifier();
    EqualsExpressionContext *equalsExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantDeclarationContext* constantDeclaration();

  class  SingleDesignatorDeclarationContext : public antlr4::ParserRuleContext {
  public:
    SingleDesignatorDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorTypeContext *singleDesignatorType();
    antlr4::tree::TerminalNode *Identifier();
    EqualsExpressionContext *equalsExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleDesignatorDeclarationContext* singleDesignatorDeclaration();

  class  NoDesignatorDeclarationContext : public antlr4::ParserRuleContext {
  public:
    NoDesignatorDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NoDesignatorTypeContext *noDesignatorType();
    antlr4::tree::TerminalNode *Identifier();
    EqualsExpressionContext *equalsExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoDesignatorDeclarationContext* noDesignatorDeclaration();

  class  BitDeclarationContext : public antlr4::ParserRuleContext {
  public:
    BitDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREG();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *BIT();
    EqualsExpressionContext *equalsExpression();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitDeclarationContext* bitDeclaration();

  class  ComplexDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ComplexDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMPLEX();
    antlr4::tree::TerminalNode *LBRACKET();
    NumericTypeContext *numericType();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *Identifier();
    EqualsExpressionContext *equalsExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComplexDeclarationContext* complexDeclaration();

  class  ArrayInitializerContext : public antlr4::ParserRuleContext {
  public:
    ArrayInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<ArrayInitializerContext *> arrayInitializer();
    ArrayInitializerContext* arrayInitializer(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayInitializerContext* arrayInitializer();

  class  ArrayDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ArrayDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayTypeContext *arrayType();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUALS();
    ArrayInitializerContext *arrayInitializer();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayDeclarationContext* arrayDeclaration();

  class  ClassicalDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassicalDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorDeclarationContext *singleDesignatorDeclaration();
    NoDesignatorDeclarationContext *noDesignatorDeclaration();
    BitDeclarationContext *bitDeclaration();
    ComplexDeclarationContext *complexDeclaration();
    ArrayDeclarationContext *arrayDeclaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalDeclarationContext* classicalDeclaration();

  class  ClassicalTypeListContext : public antlr4::ParserRuleContext {
  public:
    ClassicalTypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ClassicalTypeContext *> classicalType();
    ClassicalTypeContext* classicalType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalTypeListContext* classicalTypeList();

  class  ClassicalArgumentContext : public antlr4::ParserRuleContext {
  public:
    ClassicalArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    SingleDesignatorTypeContext *singleDesignatorType();
    NoDesignatorTypeContext *noDesignatorType();
    antlr4::tree::TerminalNode *CREG();
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *BIT();
    antlr4::tree::TerminalNode *COMPLEX();
    antlr4::tree::TerminalNode *LBRACKET();
    NumericTypeContext *numericType();
    antlr4::tree::TerminalNode *RBRACKET();
    ArrayReferenceTypeContext *arrayReferenceType();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *MUTABLE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalArgumentContext* classicalArgument();

  class  ClassicalArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ClassicalArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ClassicalArgumentContext *> classicalArgument();
    ClassicalArgumentContext* classicalArgument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalArgumentListContext* classicalArgumentList();

  class  AnyTypeArgumentContext : public antlr4::ParserRuleContext {
  public:
    AnyTypeArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassicalArgumentContext *classicalArgument();
    QuantumArgumentContext *quantumArgument();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnyTypeArgumentContext* anyTypeArgument();

  class  AnyTypeArgumentListContext : public antlr4::ParserRuleContext {
  public:
    AnyTypeArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AnyTypeArgumentContext *> anyTypeArgument();
    AnyTypeArgumentContext* anyTypeArgument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnyTypeArgumentListContext* anyTypeArgumentList();

  class  AliasInitializerContext : public antlr4::ParserRuleContext {
  public:
    AliasInitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOUBLE_PLUS();
    antlr4::tree::TerminalNode* DOUBLE_PLUS(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasInitializerContext* aliasInitializer();

  class  AliasStatementContext : public antlr4::ParserRuleContext {
  public:
    AliasStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUALS();
    AliasInitializerContext *aliasInitializer();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasStatementContext* aliasStatement();

  class  RangeDefinitionContext : public antlr4::ParserRuleContext {
  public:
    RangeDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangeDefinitionContext* rangeDefinition();

  class  QuantumGateDefinitionContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GATE();
    QuantumGateSignatureContext *quantumGateSignature();
    QuantumBlockContext *quantumBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateDefinitionContext* quantumGateDefinition();

  class  QuantumGateSignatureContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateSignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumGateNameContext *quantumGateName();
    std::vector<IdentifierListContext *> identifierList();
    IdentifierListContext* identifierList(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateSignatureContext* quantumGateSignature();

  class  QuantumGateNameContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *U_();
    antlr4::tree::TerminalNode *CX();
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateNameContext* quantumGateName();

  class  QuantumBlockContext : public antlr4::ParserRuleContext {
  public:
    QuantumBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<QuantumStatementContext *> quantumStatement();
    QuantumStatementContext* quantumStatement(size_t i);
    std::vector<QuantumLoopContext *> quantumLoop();
    QuantumLoopContext* quantumLoop(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumBlockContext* quantumBlock();

  class  QuantumLoopContext : public antlr4::ParserRuleContext {
  public:
    QuantumLoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LoopSignatureContext *loopSignature();
    QuantumLoopBlockContext *quantumLoopBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumLoopContext* quantumLoop();

  class  QuantumLoopBlockContext : public antlr4::ParserRuleContext {
  public:
    QuantumLoopBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QuantumStatementContext *> quantumStatement();
    QuantumStatementContext* quantumStatement(size_t i);
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumLoopBlockContext* quantumLoopBlock();

  class  QuantumStatementContext : public antlr4::ParserRuleContext {
  public:
    QuantumStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumInstructionContext *quantumInstruction();
    antlr4::tree::TerminalNode *SEMICOLON();
    TimingStatementContext *timingStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumStatementContext* quantumStatement();

  class  QuantumInstructionContext : public antlr4::ParserRuleContext {
  public:
    QuantumInstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumGateCallContext *quantumGateCall();
    QuantumPhaseContext *quantumPhase();
    QuantumMeasurementContext *quantumMeasurement();
    QuantumResetContext *quantumReset();
    QuantumBarrierContext *quantumBarrier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumInstructionContext* quantumInstruction();

  class  QuantumBarrierContext : public antlr4::ParserRuleContext {
  public:
    QuantumBarrierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BARRIER();
    std::vector<IndexedIdentifierContext *> indexedIdentifier();
    IndexedIdentifierContext* indexedIdentifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumBarrierContext* quantumBarrier();

  class  QuantumMeasurementContext : public antlr4::ParserRuleContext {
  public:
    QuantumMeasurementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEASURE();
    IndexedIdentifierContext *indexedIdentifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumMeasurementContext* quantumMeasurement();

  class  QuantumPhaseContext : public antlr4::ParserRuleContext {
  public:
    QuantumPhaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GPHASE();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<QuantumGateModifierContext *> quantumGateModifier();
    QuantumGateModifierContext* quantumGateModifier(size_t i);
    std::vector<IndexedIdentifierContext *> indexedIdentifier();
    IndexedIdentifierContext* indexedIdentifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumPhaseContext* quantumPhase();

  class  QuantumResetContext : public antlr4::ParserRuleContext {
  public:
    QuantumResetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESET();
    IndexedIdentifierContext *indexedIdentifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumResetContext* quantumReset();

  class  QuantumMeasurementAssignmentContext : public antlr4::ParserRuleContext {
  public:
    QuantumMeasurementAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumMeasurementContext *quantumMeasurement();
    antlr4::tree::TerminalNode *ARROW();
    IndexedIdentifierContext *indexedIdentifier();
    antlr4::tree::TerminalNode *EQUALS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumMeasurementAssignmentContext* quantumMeasurementAssignment();

  class  PowModifierContext : public antlr4::ParserRuleContext {
  public:
    PowModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PowModifierContext* powModifier();

  class  CtrlModifierContext : public antlr4::ParserRuleContext {
  public:
    CtrlModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CTRL();
    antlr4::tree::TerminalNode *NEGCTRL();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CtrlModifierContext* ctrlModifier();

  class  QuantumGateModifierContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *INV();
    PowModifierContext *powModifier();
    CtrlModifierContext *ctrlModifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateModifierContext* quantumGateModifier();

  class  QuantumGateCallContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumGateNameContext *quantumGateName();
    std::vector<IndexedIdentifierContext *> indexedIdentifier();
    IndexedIdentifierContext* indexedIdentifier(size_t i);
    std::vector<QuantumGateModifierContext *> quantumGateModifier();
    QuantumGateModifierContext* quantumGateModifier(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateCallContext* quantumGateCall();

  class  UnaryOperatorContext : public antlr4::ParserRuleContext {
  public:
    UnaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *EXCLAMATION_POINT();
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryOperatorContext* unaryOperator();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionTerminatorContext *expressionTerminator();
    UnaryExpressionContext *unaryExpression();
    LogicalAndExpressionContext *logicalAndExpression();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *DOUBLE_PIPE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  LogicalAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalAndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BitOrExpressionContext *bitOrExpression();
    LogicalAndExpressionContext *logicalAndExpression();
    antlr4::tree::TerminalNode *DOUBLE_AMPERSAND();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalAndExpressionContext* logicalAndExpression();
  LogicalAndExpressionContext* logicalAndExpression(int precedence);
  class  BitOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    BitOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    XOrExpressionContext *xOrExpression();
    BitOrExpressionContext *bitOrExpression();
    antlr4::tree::TerminalNode *PIPE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitOrExpressionContext* bitOrExpression();
  BitOrExpressionContext* bitOrExpression(int precedence);
  class  XOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    XOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BitAndExpressionContext *bitAndExpression();
    XOrExpressionContext *xOrExpression();
    antlr4::tree::TerminalNode *CARET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  XOrExpressionContext* xOrExpression();
  XOrExpressionContext* xOrExpression(int precedence);
  class  BitAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    BitAndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqualityExpressionContext *equalityExpression();
    BitAndExpressionContext *bitAndExpression();
    antlr4::tree::TerminalNode *AMPERSAND();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitAndExpressionContext* bitAndExpression();
  BitAndExpressionContext* bitAndExpression(int precedence);
  class  EqualityExpressionContext : public antlr4::ParserRuleContext {
  public:
    EqualityExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ComparisonExpressionContext *comparisonExpression();
    EqualityExpressionContext *equalityExpression();
    antlr4::tree::TerminalNode *EqualityOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityExpressionContext* equalityExpression();
  EqualityExpressionContext* equalityExpression(int precedence);
  class  ComparisonExpressionContext : public antlr4::ParserRuleContext {
  public:
    ComparisonExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BitShiftExpressionContext *bitShiftExpression();
    ComparisonExpressionContext *comparisonExpression();
    antlr4::tree::TerminalNode *ComparisonOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonExpressionContext* comparisonExpression();
  ComparisonExpressionContext* comparisonExpression(int precedence);
  class  BitShiftExpressionContext : public antlr4::ParserRuleContext {
  public:
    BitShiftExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AdditiveExpressionContext *additiveExpression();
    BitShiftExpressionContext *bitShiftExpression();
    antlr4::tree::TerminalNode *BitshiftOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitShiftExpressionContext* bitShiftExpression();
  BitShiftExpressionContext* bitShiftExpression(int precedence);
  class  AdditiveExpressionContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MultiplicativeExpressionContext *multiplicativeExpression();
    AdditiveExpressionContext *additiveExpression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveExpressionContext* additiveExpression();
  AdditiveExpressionContext* additiveExpression(int precedence);
  class  MultiplicativeExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryExpressionContext *unaryExpression();
    MultiplicativeExpressionContext *multiplicativeExpression();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PERCENT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeExpressionContext* multiplicativeExpression();
  MultiplicativeExpressionContext* multiplicativeExpression(int precedence);
  class  UnaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PowerExpressionContext *powerExpression();
    UnaryOperatorContext *unaryOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryExpressionContext* unaryExpression();

  class  PowerExpressionContext : public antlr4::ParserRuleContext {
  public:
    PowerExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexExpressionContext *indexExpression();
    PowerExpressionContext *powerExpression();
    antlr4::tree::TerminalNode *DOUBLE_ASTERISK();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PowerExpressionContext* powerExpression();
  PowerExpressionContext* powerExpression(int precedence);
  class  IndexOperatorContext : public antlr4::ParserRuleContext {
  public:
    IndexOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    DiscreteSetContext *discreteSet();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<RangeDefinitionContext *> rangeDefinition();
    RangeDefinitionContext* rangeDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexOperatorContext* indexOperator();

  class  IndexExpressionContext : public antlr4::ParserRuleContext {
  public:
    IndexExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionTerminatorContext *expressionTerminator();
    IndexExpressionContext *indexExpression();
    IndexOperatorContext *indexOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexExpressionContext* indexExpression();
  IndexExpressionContext* indexExpression(int precedence);
  class  IndexedIdentifierContext : public antlr4::ParserRuleContext {
  public:
    IndexedIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<IndexOperatorContext *> indexOperator();
    IndexOperatorContext* indexOperator(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexedIdentifierContext* indexedIdentifier();

  class  ExpressionTerminatorContext : public antlr4::ParserRuleContext {
  public:
    ExpressionTerminatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Constant();
    antlr4::tree::TerminalNode *BinaryIntegerLiteral();
    antlr4::tree::TerminalNode *OctalIntegerLiteral();
    antlr4::tree::TerminalNode *DecimalIntegerLiteral();
    antlr4::tree::TerminalNode *HexIntegerLiteral();
    antlr4::tree::TerminalNode *FloatLiteral();
    antlr4::tree::TerminalNode *ImaginaryLiteral();
    antlr4::tree::TerminalNode *BooleanLiteral();
    antlr4::tree::TerminalNode *BitstringLiteral();
    antlr4::tree::TerminalNode *Identifier();
    BuiltInCallContext *builtInCall();
    ExternOrSubroutineCallContext *externOrSubroutineCall();
    TimingIdentifierContext *timingIdentifier();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionTerminatorContext* expressionTerminator();

  class  BuiltInCallContext : public antlr4::ParserRuleContext {
  public:
    BuiltInCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *BuiltinMath();
    CastOperatorContext *castOperator();
    antlr4::tree::TerminalNode *SIZEOF();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BuiltInCallContext* builtInCall();

  class  CastOperatorContext : public antlr4::ParserRuleContext {
  public:
    CastOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassicalTypeContext *classicalType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CastOperatorContext* castOperator();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();

  class  EqualsExpressionContext : public antlr4::ParserRuleContext {
  public:
    EqualsExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUALS();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualsExpressionContext* equalsExpression();

  class  AssignmentOperatorContext : public antlr4::ParserRuleContext {
  public:
    AssignmentOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *CompoundAssignmentOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentOperatorContext* assignmentOperator();

  class  DiscreteSetContext : public antlr4::ParserRuleContext {
  public:
    DiscreteSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiscreteSetContext* discreteSet();

  class  SetDeclarationContext : public antlr4::ParserRuleContext {
  public:
    SetDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DiscreteSetContext *discreteSet();
    antlr4::tree::TerminalNode *LBRACKET();
    RangeDefinitionContext *rangeDefinition();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetDeclarationContext* setDeclaration();

  class  ProgramBlockContext : public antlr4::ParserRuleContext {
  public:
    ProgramBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<ControlDirectiveContext *> controlDirective();
    ControlDirectiveContext* controlDirective(size_t i);
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramBlockContext* programBlock();

  class  BranchingStatementContext : public antlr4::ParserRuleContext {
  public:
    BranchingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ProgramBlockContext *> programBlock();
    ProgramBlockContext* programBlock(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchingStatementContext* branchingStatement();

  class  LoopSignatureContext : public antlr4::ParserRuleContext {
  public:
    LoopSignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *IN();
    SetDeclarationContext *setDeclaration();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopSignatureContext* loopSignature();

  class  LoopStatementContext : public antlr4::ParserRuleContext {
  public:
    LoopStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LoopSignatureContext *loopSignature();
    ProgramBlockContext *programBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopStatementContext* loopStatement();

  class  EndStatementContext : public antlr4::ParserRuleContext {
  public:
    EndStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndStatementContext* endStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();
    QuantumMeasurementContext *quantumMeasurement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  ControlDirectiveContext : public antlr4::ParserRuleContext {
  public:
    ControlDirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();
    EndStatementContext *endStatement();
    ReturnStatementContext *returnStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ControlDirectiveContext* controlDirective();

  class  ExternDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ExternDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTERN();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ClassicalTypeListContext *classicalTypeList();
    ReturnSignatureContext *returnSignature();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternDeclarationContext* externDeclaration();

  class  ExternOrSubroutineCallContext : public antlr4::ParserRuleContext {
  public:
    ExternOrSubroutineCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionListContext *expressionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternOrSubroutineCallContext* externOrSubroutineCall();

  class  SubroutineDefinitionContext : public antlr4::ParserRuleContext {
  public:
    SubroutineDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    SubroutineBlockContext *subroutineBlock();
    AnyTypeArgumentListContext *anyTypeArgumentList();
    ReturnSignatureContext *returnSignature();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubroutineDefinitionContext* subroutineDefinition();

  class  SubroutineBlockContext : public antlr4::ParserRuleContext {
  public:
    SubroutineBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    ReturnStatementContext *returnStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubroutineBlockContext* subroutineBlock();

  class  PragmaContext : public antlr4::ParserRuleContext {
  public:
    PragmaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRAGMA();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PragmaContext* pragma();

  class  TimingBoxContext : public antlr4::ParserRuleContext {
  public:
    TimingBoxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOX();
    QuantumBlockContext *quantumBlock();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingBoxContext* timingBox();

  class  TimingIdentifierContext : public antlr4::ParserRuleContext {
  public:
    TimingIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TimingLiteral();
    antlr4::tree::TerminalNode *DURATIONOF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *Identifier();
    QuantumBlockContext *quantumBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingIdentifierContext* timingIdentifier();

  class  TimingInstructionContext : public antlr4::ParserRuleContext {
  public:
    TimingInstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BuiltinTimingInstruction();
    DesignatorContext *designator();
    std::vector<IndexedIdentifierContext *> indexedIdentifier();
    IndexedIdentifierContext* indexedIdentifier(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ExpressionListContext *expressionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingInstructionContext* timingInstruction();

  class  TimingStatementContext : public antlr4::ParserRuleContext {
  public:
    TimingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TimingInstructionContext *timingInstruction();
    antlr4::tree::TerminalNode *SEMICOLON();
    TimingBoxContext *timingBox();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingStatementContext* timingStatement();

  class  CalibrationContext : public antlr4::ParserRuleContext {
  public:
    CalibrationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CalibrationGrammarDeclarationContext *calibrationGrammarDeclaration();
    CalibrationDefinitionContext *calibrationDefinition();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationContext* calibration();

  class  CalibrationGrammarDeclarationContext : public antlr4::ParserRuleContext {
  public:
    CalibrationGrammarDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFCALGRAMMAR();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationGrammarDeclarationContext* calibrationGrammarDeclaration();

  class  CalibrationDefinitionContext : public antlr4::ParserRuleContext {
  public:
    CalibrationDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFCAL();
    antlr4::tree::TerminalNode *Identifier();
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ReturnSignatureContext *returnSignature();
    CalibrationArgumentListContext *calibrationArgumentList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationDefinitionContext* calibrationDefinition();

  class  CalibrationArgumentListContext : public antlr4::ParserRuleContext {
  public:
    CalibrationArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassicalArgumentListContext *classicalArgumentList();
    ExpressionListContext *expressionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationArgumentListContext* calibrationArgumentList();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex);
  bool bitOrExpressionSempred(BitOrExpressionContext *_localctx, size_t predicateIndex);
  bool xOrExpressionSempred(XOrExpressionContext *_localctx, size_t predicateIndex);
  bool bitAndExpressionSempred(BitAndExpressionContext *_localctx, size_t predicateIndex);
  bool equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex);
  bool comparisonExpressionSempred(ComparisonExpressionContext *_localctx, size_t predicateIndex);
  bool bitShiftExpressionSempred(BitShiftExpressionContext *_localctx, size_t predicateIndex);
  bool additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex);
  bool multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex);
  bool powerExpressionSempred(PowerExpressionContext *_localctx, size_t predicateIndex);
  bool indexExpressionSempred(IndexExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

