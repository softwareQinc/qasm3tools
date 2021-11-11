
// Generated from qasm3.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  qasm3Parser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, T__67 = 68, 
    T__68 = 69, T__69 = 70, T__70 = 71, T__71 = 72, T__72 = 73, T__73 = 74, 
    T__74 = 75, T__75 = 76, T__76 = 77, T__77 = 78, T__78 = 79, T__79 = 80, 
    T__80 = 81, T__81 = 82, T__82 = 83, T__83 = 84, T__84 = 85, T__85 = 86, 
    T__86 = 87, T__87 = 88, T__88 = 89, T__89 = 90, T__90 = 91, LBRACKET = 92, 
    RBRACKET = 93, LBRACE = 94, RBRACE = 95, LPAREN = 96, RPAREN = 97, COLON = 98, 
    SEMICOLON = 99, DOT = 100, COMMA = 101, EQUALS = 102, ARROW = 103, PLUS = 104, 
    MINUS = 105, MUL = 106, DIV = 107, MOD = 108, IMAG = 109, ImagNumber = 110, 
    Constant = 111, Whitespace = 112, Newline = 113, Integer = 114, Identifier = 115, 
    RealNumber = 116, TimingLiteral = 117, StringLiteral = 118, LineComment = 119, 
    BlockComment = 120
  };

  enum {
    RuleProgram = 0, RuleHeader = 1, RuleVersion = 2, RuleInclude = 3, RuleIoIdentifier = 4, 
    RuleIo = 5, RuleGlobalStatement = 6, RuleStatement = 7, RuleQuantumDeclarationStatement = 8, 
    RuleClassicalDeclarationStatement = 9, RuleClassicalAssignment = 10, 
    RuleAssignmentStatement = 11, RuleReturnSignature = 12, RuleDesignator = 13, 
    RuleIdentifierList = 14, RuleQuantumDeclaration = 15, RuleQuantumArgument = 16, 
    RuleQuantumArgumentList = 17, RuleBitType = 18, RuleSingleDesignatorType = 19, 
    RuleNoDesignatorType = 20, RuleClassicalType = 21, RuleNumericType = 22, 
    RuleConstantDeclaration = 23, RuleSingleDesignatorDeclaration = 24, 
    RuleNoDesignatorDeclaration = 25, RuleBitDeclaration = 26, RuleComplexDeclaration = 27, 
    RuleClassicalDeclaration = 28, RuleClassicalTypeList = 29, RuleClassicalArgument = 30, 
    RuleClassicalArgumentList = 31, RuleAnyTypeArgument = 32, RuleAnyTypeArgumentList = 33, 
    RuleAliasStatement = 34, RuleIndexIdentifier = 35, RuleIndexIdentifierList = 36, 
    RuleRangeDefinition = 37, RuleQuantumGateDefinition = 38, RuleQuantumGateSignature = 39, 
    RuleQuantumGateName = 40, RuleQuantumBlock = 41, RuleQuantumLoop = 42, 
    RuleQuantumLoopBlock = 43, RuleQuantumStatement = 44, RuleQuantumInstruction = 45, 
    RuleQuantumPhase = 46, RuleQuantumReset = 47, RuleQuantumMeasurement = 48, 
    RuleQuantumMeasurementAssignment = 49, RuleQuantumBarrier = 50, RuleQuantumGateModifier = 51, 
    RulePowModifier = 52, RuleCtrlModifier = 53, RuleQuantumGateCall = 54, 
    RuleUnaryOperator = 55, RuleComparisonOperator = 56, RuleEqualityOperator = 57, 
    RuleLogicalOperator = 58, RuleExpressionStatement = 59, RuleExpression = 60, 
    RuleLogicalAndExpression = 61, RuleBitOrExpression = 62, RuleXOrExpression = 63, 
    RuleBitAndExpression = 64, RuleEqualityExpression = 65, RuleComparisonExpression = 66, 
    RuleBitShiftExpression = 67, RuleAdditiveExpression = 68, RuleMultiplicativeExpression = 69, 
    RuleUnaryExpression = 70, RulePowerExpression = 71, RuleExpressionTerminator = 72, 
    RuleBooleanLiteral = 73, RuleBuiltInCall = 74, RuleBuiltInMath = 75, 
    RuleCastOperator = 76, RuleExpressionList = 77, RuleEqualsExpression = 78, 
    RuleAssignmentOperator = 79, RuleSetDeclaration = 80, RuleProgramBlock = 81, 
    RuleBranchingStatement = 82, RuleLoopSignature = 83, RuleLoopStatement = 84, 
    RuleEndStatement = 85, RuleReturnStatement = 86, RuleControlDirective = 87, 
    RuleExternDeclaration = 88, RuleExternOrSubroutineCall = 89, RuleSubroutineDefinition = 90, 
    RuleSubroutineBlock = 91, RulePragma = 92, RuleTimingType = 93, RuleTimingBox = 94, 
    RuleTimingIdentifier = 95, RuleTimingInstructionName = 96, RuleTimingInstruction = 97, 
    RuleTimingStatement = 98, RuleCalibration = 99, RuleCalibrationGrammarDeclaration = 100, 
    RuleCalibrationDefinition = 101, RuleCalibrationGrammar = 102, RuleCalibrationArgumentList = 103
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
  class QuantumArgumentListContext;
  class BitTypeContext;
  class SingleDesignatorTypeContext;
  class NoDesignatorTypeContext;
  class ClassicalTypeContext;
  class NumericTypeContext;
  class ConstantDeclarationContext;
  class SingleDesignatorDeclarationContext;
  class NoDesignatorDeclarationContext;
  class BitDeclarationContext;
  class ComplexDeclarationContext;
  class ClassicalDeclarationContext;
  class ClassicalTypeListContext;
  class ClassicalArgumentContext;
  class ClassicalArgumentListContext;
  class AnyTypeArgumentContext;
  class AnyTypeArgumentListContext;
  class AliasStatementContext;
  class IndexIdentifierContext;
  class IndexIdentifierListContext;
  class RangeDefinitionContext;
  class QuantumGateDefinitionContext;
  class QuantumGateSignatureContext;
  class QuantumGateNameContext;
  class QuantumBlockContext;
  class QuantumLoopContext;
  class QuantumLoopBlockContext;
  class QuantumStatementContext;
  class QuantumInstructionContext;
  class QuantumPhaseContext;
  class QuantumResetContext;
  class QuantumMeasurementContext;
  class QuantumMeasurementAssignmentContext;
  class QuantumBarrierContext;
  class QuantumGateModifierContext;
  class PowModifierContext;
  class CtrlModifierContext;
  class QuantumGateCallContext;
  class UnaryOperatorContext;
  class ComparisonOperatorContext;
  class EqualityOperatorContext;
  class LogicalOperatorContext;
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
  class ExpressionTerminatorContext;
  class BooleanLiteralContext;
  class BuiltInCallContext;
  class BuiltInMathContext;
  class CastOperatorContext;
  class ExpressionListContext;
  class EqualsExpressionContext;
  class AssignmentOperatorContext;
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
  class TimingTypeContext;
  class TimingBoxContext;
  class TimingIdentifierContext;
  class TimingInstructionNameContext;
  class TimingInstructionContext;
  class TimingStatementContext;
  class CalibrationContext;
  class CalibrationGrammarDeclarationContext;
  class CalibrationDefinitionContext;
  class CalibrationGrammarContext;
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
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *Integer();
    antlr4::tree::TerminalNode *RealNumber();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VersionContext* version();

  class  IncludeContext : public antlr4::ParserRuleContext {
  public:
    IncludeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeContext* include();

  class  IoIdentifierContext : public antlr4::ParserRuleContext {
  public:
    IoIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


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
    antlr4::tree::TerminalNode *Identifier();
    AssignmentOperatorContext *assignmentOperator();
    ExpressionContext *expression();
    DesignatorContext *designator();


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
    antlr4::tree::TerminalNode *Identifier();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumDeclarationContext* quantumDeclaration();

  class  QuantumArgumentContext : public antlr4::ParserRuleContext {
  public:
    QuantumArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumArgumentContext* quantumArgument();

  class  QuantumArgumentListContext : public antlr4::ParserRuleContext {
  public:
    QuantumArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<QuantumArgumentContext *> quantumArgument();
    QuantumArgumentContext* quantumArgument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumArgumentListContext* quantumArgumentList();

  class  BitTypeContext : public antlr4::ParserRuleContext {
  public:
    BitTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitTypeContext* bitType();

  class  SingleDesignatorTypeContext : public antlr4::ParserRuleContext {
  public:
    SingleDesignatorTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleDesignatorTypeContext* singleDesignatorType();

  class  NoDesignatorTypeContext : public antlr4::ParserRuleContext {
  public:
    NoDesignatorTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TimingTypeContext *timingType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NoDesignatorTypeContext* noDesignatorType();

  class  ClassicalTypeContext : public antlr4::ParserRuleContext {
  public:
    ClassicalTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorTypeContext *singleDesignatorType();
    DesignatorContext *designator();
    NoDesignatorTypeContext *noDesignatorType();
    BitTypeContext *bitType();
    antlr4::tree::TerminalNode *LBRACKET();
    NumericTypeContext *numericType();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalTypeContext* classicalType();

  class  NumericTypeContext : public antlr4::ParserRuleContext {
  public:
    NumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorTypeContext *singleDesignatorType();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumericTypeContext* numericType();

  class  ConstantDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ConstantDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    DesignatorContext *designator();
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
    antlr4::tree::TerminalNode *Identifier();
    EqualsExpressionContext *equalsExpression();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BitDeclarationContext* bitDeclaration();

  class  ComplexDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ComplexDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    NumericTypeContext *numericType();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *Identifier();
    EqualsExpressionContext *equalsExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComplexDeclarationContext* complexDeclaration();

  class  ClassicalDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ClassicalDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SingleDesignatorDeclarationContext *singleDesignatorDeclaration();
    NoDesignatorDeclarationContext *noDesignatorDeclaration();
    BitDeclarationContext *bitDeclaration();
    ComplexDeclarationContext *complexDeclaration();


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
    DesignatorContext *designator();
    NoDesignatorTypeContext *noDesignatorType();
    antlr4::tree::TerminalNode *LBRACKET();
    NumericTypeContext *numericType();
    antlr4::tree::TerminalNode *RBRACKET();


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

  class  AliasStatementContext : public antlr4::ParserRuleContext {
  public:
    AliasStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUALS();
    IndexIdentifierContext *indexIdentifier();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasStatementContext* aliasStatement();

  class  IndexIdentifierContext : public antlr4::ParserRuleContext {
  public:
    IndexIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    RangeDefinitionContext *rangeDefinition();
    antlr4::tree::TerminalNode *LBRACKET();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<IndexIdentifierContext *> indexIdentifier();
    IndexIdentifierContext* indexIdentifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexIdentifierContext* indexIdentifier();
  IndexIdentifierContext* indexIdentifier(int precedence);
  class  IndexIdentifierListContext : public antlr4::ParserRuleContext {
  public:
    IndexIdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IndexIdentifierContext *> indexIdentifier();
    IndexIdentifierContext* indexIdentifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexIdentifierListContext* indexIdentifierList();

  class  RangeDefinitionContext : public antlr4::ParserRuleContext {
  public:
    RangeDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangeDefinitionContext* rangeDefinition();

  class  QuantumGateDefinitionContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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

  class  QuantumPhaseContext : public antlr4::ParserRuleContext {
  public:
    QuantumPhaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<QuantumGateModifierContext *> quantumGateModifier();
    QuantumGateModifierContext* quantumGateModifier(size_t i);
    IndexIdentifierListContext *indexIdentifierList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumPhaseContext* quantumPhase();

  class  QuantumResetContext : public antlr4::ParserRuleContext {
  public:
    QuantumResetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexIdentifierListContext *indexIdentifierList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumResetContext* quantumReset();

  class  QuantumMeasurementContext : public antlr4::ParserRuleContext {
  public:
    QuantumMeasurementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexIdentifierContext *indexIdentifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumMeasurementContext* quantumMeasurement();

  class  QuantumMeasurementAssignmentContext : public antlr4::ParserRuleContext {
  public:
    QuantumMeasurementAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumMeasurementContext *quantumMeasurement();
    antlr4::tree::TerminalNode *ARROW();
    IndexIdentifierContext *indexIdentifier();
    antlr4::tree::TerminalNode *EQUALS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumMeasurementAssignmentContext* quantumMeasurementAssignment();

  class  QuantumBarrierContext : public antlr4::ParserRuleContext {
  public:
    QuantumBarrierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexIdentifierListContext *indexIdentifierList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumBarrierContext* quantumBarrier();

  class  QuantumGateModifierContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PowModifierContext *powModifier();
    CtrlModifierContext *ctrlModifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateModifierContext* quantumGateModifier();

  class  PowModifierContext : public antlr4::ParserRuleContext {
  public:
    PowModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CtrlModifierContext* ctrlModifier();

  class  QuantumGateCallContext : public antlr4::ParserRuleContext {
  public:
    QuantumGateCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QuantumGateNameContext *quantumGateName();
    IndexIdentifierListContext *indexIdentifierList();
    std::vector<QuantumGateModifierContext *> quantumGateModifier();
    QuantumGateModifierContext* quantumGateModifier(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumGateCallContext* quantumGateCall();

  class  UnaryOperatorContext : public antlr4::ParserRuleContext {
  public:
    UnaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryOperatorContext* unaryOperator();

  class  ComparisonOperatorContext : public antlr4::ParserRuleContext {
  public:
    ComparisonOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonOperatorContext* comparisonOperator();

  class  EqualityOperatorContext : public antlr4::ParserRuleContext {
  public:
    EqualityOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityOperatorContext* equalityOperator();

  class  LogicalOperatorContext : public antlr4::ParserRuleContext {
  public:
    LogicalOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalOperatorContext* logicalOperator();

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
    EqualityOperatorContext *equalityOperator();


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
    ComparisonOperatorContext *comparisonOperator();


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
    PowerExpressionContext *powerExpression();
    UnaryExpressionContext *unaryExpression();
    MultiplicativeExpressionContext *multiplicativeExpression();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeExpressionContext* multiplicativeExpression();
  MultiplicativeExpressionContext* multiplicativeExpression(int precedence);
  class  UnaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryOperatorContext *unaryOperator();
    PowerExpressionContext *powerExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryExpressionContext* unaryExpression();

  class  PowerExpressionContext : public antlr4::ParserRuleContext {
  public:
    PowerExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionTerminatorContext *expressionTerminator();
    PowerExpressionContext *powerExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PowerExpressionContext* powerExpression();

  class  ExpressionTerminatorContext : public antlr4::ParserRuleContext {
  public:
    ExpressionTerminatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Constant();
    antlr4::tree::TerminalNode *Integer();
    antlr4::tree::TerminalNode *RealNumber();
    antlr4::tree::TerminalNode *ImagNumber();
    BooleanLiteralContext *booleanLiteral();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *StringLiteral();
    BuiltInCallContext *builtInCall();
    ExternOrSubroutineCallContext *externOrSubroutineCall();
    TimingIdentifierContext *timingIdentifier();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionTerminatorContext *expressionTerminator();
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionTerminatorContext* expressionTerminator();
  ExpressionTerminatorContext* expressionTerminator(int precedence);
  class  BooleanLiteralContext : public antlr4::ParserRuleContext {
  public:
    BooleanLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanLiteralContext* booleanLiteral();

  class  BuiltInCallContext : public antlr4::ParserRuleContext {
  public:
    BuiltInCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RPAREN();
    BuiltInMathContext *builtInMath();
    CastOperatorContext *castOperator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BuiltInCallContext* builtInCall();

  class  BuiltInMathContext : public antlr4::ParserRuleContext {
  public:
    BuiltInMathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BuiltInMathContext* builtInMath();

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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentOperatorContext* assignmentOperator();

  class  SetDeclarationContext : public antlr4::ParserRuleContext {
  public:
    SetDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RBRACE();
    RangeDefinitionContext *rangeDefinition();
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
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ProgramBlockContext *> programBlock();
    ProgramBlockContext* programBlock(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchingStatementContext* branchingStatement();

  class  LoopSignatureContext : public antlr4::ParserRuleContext {
  public:
    LoopSignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    SetDeclarationContext *setDeclaration();
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
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndStatementContext* endStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    EndStatementContext *endStatement();
    ReturnStatementContext *returnStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ControlDirectiveContext* controlDirective();

  class  ExternDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ExternDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PragmaContext* pragma();

  class  TimingTypeContext : public antlr4::ParserRuleContext {
  public:
    TimingTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingTypeContext* timingType();

  class  TimingBoxContext : public antlr4::ParserRuleContext {
  public:
    TimingBoxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *Identifier();
    QuantumBlockContext *quantumBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingIdentifierContext* timingIdentifier();

  class  TimingInstructionNameContext : public antlr4::ParserRuleContext {
  public:
    TimingInstructionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimingInstructionNameContext* timingInstructionName();

  class  TimingInstructionContext : public antlr4::ParserRuleContext {
  public:
    TimingInstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TimingInstructionNameContext *timingInstructionName();
    DesignatorContext *designator();
    IndexIdentifierListContext *indexIdentifierList();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
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
    CalibrationGrammarContext *calibrationGrammar();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationGrammarDeclarationContext* calibrationGrammarDeclaration();

  class  CalibrationDefinitionContext : public antlr4::ParserRuleContext {
  public:
    CalibrationDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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

  class  CalibrationGrammarContext : public antlr4::ParserRuleContext {
  public:
    CalibrationGrammarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StringLiteral();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationGrammarContext* calibrationGrammar();

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
  bool indexIdentifierSempred(IndexIdentifierContext *_localctx, size_t predicateIndex);
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
  bool expressionTerminatorSempred(ExpressionTerminatorContext *_localctx, size_t predicateIndex);

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

