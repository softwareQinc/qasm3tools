
// Generated from qasm3Parser.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  qasm3Parser : public antlr4::Parser {
public:
  enum {
    OPENQASM = 1, INCLUDE = 2, DEFCALGRAMMAR = 3, DEF = 4, CAL = 5, DEFCAL = 6, 
    GATE = 7, EXTERN = 8, BOX = 9, LET = 10, BREAK = 11, CONTINUE = 12, 
    IF = 13, ELSE = 14, END = 15, RETURN = 16, FOR = 17, WHILE = 18, IN = 19, 
    PRAGMA = 20, AnnotationKeyword = 21, INPUT = 22, OUTPUT = 23, CONST = 24, 
    MUTABLE = 25, QREG = 26, QUBIT = 27, CREG = 28, BOOL = 29, BIT = 30, 
    INT = 31, UINT = 32, FLOAT = 33, ANGLE = 34, COMPLEX = 35, ARRAY = 36, 
    DURATION = 37, STRETCH = 38, GPHASE = 39, INV = 40, POW = 41, CTRL = 42, 
    NEGCTRL = 43, DIM = 44, DURATIONOF = 45, DELAY = 46, RESET = 47, MEASURE = 48, 
    BARRIER = 49, BooleanLiteral = 50, LBRACKET = 51, RBRACKET = 52, LBRACE = 53, 
    RBRACE = 54, LPAREN = 55, RPAREN = 56, COLON = 57, SEMICOLON = 58, DOT = 59, 
    COMMA = 60, EQUALS = 61, ARROW = 62, PLUS = 63, DOUBLE_PLUS = 64, MINUS = 65, 
    ASTERISK = 66, DOUBLE_ASTERISK = 67, SLASH = 68, PERCENT = 69, PIPE = 70, 
    DOUBLE_PIPE = 71, AMPERSAND = 72, DOUBLE_AMPERSAND = 73, CARET = 74, 
    AT = 75, TILDE = 76, EXCLAMATION_POINT = 77, EqualityOperator = 78, 
    CompoundAssignmentOperator = 79, ComparisonOperator = 80, BitshiftOperator = 81, 
    IMAG = 82, ImaginaryLiteral = 83, BinaryIntegerLiteral = 84, OctalIntegerLiteral = 85, 
    DecimalIntegerLiteral = 86, HexIntegerLiteral = 87, Identifier = 88, 
    HardwareQubit = 89, FloatLiteral = 90, TimingLiteral = 91, BitstringLiteral = 92, 
    StringLiteral = 93, Whitespace = 94, Newline = 95, LineComment = 96, 
    BlockComment = 97, VERSION_IDENTIFER_WHITESPACE = 98, VersionSpecifier = 99, 
    EAT_INITIAL_SPACE = 100, EAT_LINE_END = 101, RemainingLineContent = 102, 
    CAL_PRELUDE_WHITESPACE = 103, CAL_PRELUDE_COMMENT = 104, DEFCAL_PRELUDE_WHITESPACE = 105, 
    DEFCAL_PRELUDE_COMMENT = 106, CalibrationBlock = 107
  };

  enum {
    RuleProgram = 0, RuleVersion = 1, RuleStatement = 2, RuleAnnotation = 3, 
    RuleScope = 4, RulePragma = 5, RuleStatementOrScope = 6, RuleCalibrationGrammarStatement = 7, 
    RuleIncludeStatement = 8, RuleBreakStatement = 9, RuleContinueStatement = 10, 
    RuleEndStatement = 11, RuleForStatement = 12, RuleIfStatement = 13, 
    RuleReturnStatement = 14, RuleWhileStatement = 15, RuleBarrierStatement = 16, 
    RuleBoxStatement = 17, RuleDelayStatement = 18, RuleGateCallStatement = 19, 
    RuleMeasureArrowAssignmentStatement = 20, RuleResetStatement = 21, RuleAliasDeclarationStatement = 22, 
    RuleClassicalDeclarationStatement = 23, RuleConstDeclarationStatement = 24, 
    RuleIoDeclarationStatement = 25, RuleOldStyleDeclarationStatement = 26, 
    RuleQuantumDeclarationStatement = 27, RuleDefStatement = 28, RuleExternStatement = 29, 
    RuleGateStatement = 30, RuleAssignmentStatement = 31, RuleExpressionStatement = 32, 
    RuleCalStatement = 33, RuleDefcalStatement = 34, RuleExpression = 35, 
    RuleAliasExpression = 36, RuleDeclarationExpression = 37, RuleMeasureExpression = 38, 
    RuleRangeExpression = 39, RuleSetExpression = 40, RuleArrayLiteral = 41, 
    RuleIndexOperator = 42, RuleIndexedIdentifier = 43, RuleReturnSignature = 44, 
    RuleGateModifier = 45, RuleScalarType = 46, RuleQubitType = 47, RuleArrayType = 48, 
    RuleArrayReferenceType = 49, RuleDesignator = 50, RuleDefcalTarget = 51, 
    RuleDefcalArgumentDefinition = 52, RuleDefcalOperand = 53, RuleGateOperand = 54, 
    RuleExternArgument = 55, RuleArgumentDefinition = 56, RuleArgumentDefinitionList = 57, 
    RuleDefcalArgumentDefinitionList = 58, RuleDefcalOperandList = 59, RuleExpressionList = 60, 
    RuleIdentifierList = 61, RuleGateOperandList = 62, RuleExternArgumentList = 63
  };

  explicit qasm3Parser(antlr4::TokenStream *input);
  ~qasm3Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class VersionContext;
  class StatementContext;
  class AnnotationContext;
  class ScopeContext;
  class PragmaContext;
  class StatementOrScopeContext;
  class CalibrationGrammarStatementContext;
  class IncludeStatementContext;
  class BreakStatementContext;
  class ContinueStatementContext;
  class EndStatementContext;
  class ForStatementContext;
  class IfStatementContext;
  class ReturnStatementContext;
  class WhileStatementContext;
  class BarrierStatementContext;
  class BoxStatementContext;
  class DelayStatementContext;
  class GateCallStatementContext;
  class MeasureArrowAssignmentStatementContext;
  class ResetStatementContext;
  class AliasDeclarationStatementContext;
  class ClassicalDeclarationStatementContext;
  class ConstDeclarationStatementContext;
  class IoDeclarationStatementContext;
  class OldStyleDeclarationStatementContext;
  class QuantumDeclarationStatementContext;
  class DefStatementContext;
  class ExternStatementContext;
  class GateStatementContext;
  class AssignmentStatementContext;
  class ExpressionStatementContext;
  class CalStatementContext;
  class DefcalStatementContext;
  class ExpressionContext;
  class AliasExpressionContext;
  class DeclarationExpressionContext;
  class MeasureExpressionContext;
  class RangeExpressionContext;
  class SetExpressionContext;
  class ArrayLiteralContext;
  class IndexOperatorContext;
  class IndexedIdentifierContext;
  class ReturnSignatureContext;
  class GateModifierContext;
  class ScalarTypeContext;
  class QubitTypeContext;
  class ArrayTypeContext;
  class ArrayReferenceTypeContext;
  class DesignatorContext;
  class DefcalTargetContext;
  class DefcalArgumentDefinitionContext;
  class DefcalOperandContext;
  class GateOperandContext;
  class ExternArgumentContext;
  class ArgumentDefinitionContext;
  class ArgumentDefinitionListContext;
  class DefcalArgumentDefinitionListContext;
  class DefcalOperandListContext;
  class ExpressionListContext;
  class IdentifierListContext;
  class GateOperandListContext;
  class ExternArgumentListContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    VersionContext *version();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  VersionContext : public antlr4::ParserRuleContext {
  public:
    VersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPENQASM();
    antlr4::tree::TerminalNode *VersionSpecifier();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VersionContext* version();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PragmaContext *pragma();
    AliasDeclarationStatementContext *aliasDeclarationStatement();
    AssignmentStatementContext *assignmentStatement();
    BarrierStatementContext *barrierStatement();
    BoxStatementContext *boxStatement();
    BreakStatementContext *breakStatement();
    CalStatementContext *calStatement();
    CalibrationGrammarStatementContext *calibrationGrammarStatement();
    ClassicalDeclarationStatementContext *classicalDeclarationStatement();
    ConstDeclarationStatementContext *constDeclarationStatement();
    ContinueStatementContext *continueStatement();
    DefStatementContext *defStatement();
    DefcalStatementContext *defcalStatement();
    DelayStatementContext *delayStatement();
    EndStatementContext *endStatement();
    ExpressionStatementContext *expressionStatement();
    ExternStatementContext *externStatement();
    ForStatementContext *forStatement();
    GateCallStatementContext *gateCallStatement();
    GateStatementContext *gateStatement();
    IfStatementContext *ifStatement();
    IncludeStatementContext *includeStatement();
    IoDeclarationStatementContext *ioDeclarationStatement();
    MeasureArrowAssignmentStatementContext *measureArrowAssignmentStatement();
    OldStyleDeclarationStatementContext *oldStyleDeclarationStatement();
    QuantumDeclarationStatementContext *quantumDeclarationStatement();
    ResetStatementContext *resetStatement();
    ReturnStatementContext *returnStatement();
    WhileStatementContext *whileStatement();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AnnotationKeyword();
    antlr4::tree::TerminalNode *RemainingLineContent();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnnotationContext* annotation();

  class  ScopeContext : public antlr4::ParserRuleContext {
  public:
    ScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScopeContext* scope();

  class  PragmaContext : public antlr4::ParserRuleContext {
  public:
    PragmaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRAGMA();
    antlr4::tree::TerminalNode *RemainingLineContent();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PragmaContext* pragma();

  class  StatementOrScopeContext : public antlr4::ParserRuleContext {
  public:
    StatementOrScopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    ScopeContext *scope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementOrScopeContext* statementOrScope();

  class  CalibrationGrammarStatementContext : public antlr4::ParserRuleContext {
  public:
    CalibrationGrammarStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFCALGRAMMAR();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalibrationGrammarStatementContext* calibrationGrammarStatement();

  class  IncludeStatementContext : public antlr4::ParserRuleContext {
  public:
    IncludeStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IncludeStatementContext* includeStatement();

  class  BreakStatementContext : public antlr4::ParserRuleContext {
  public:
    BreakStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BreakStatementContext* breakStatement();

  class  ContinueStatementContext : public antlr4::ParserRuleContext {
  public:
    ContinueStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ContinueStatementContext* continueStatement();

  class  EndStatementContext : public antlr4::ParserRuleContext {
  public:
    EndStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndStatementContext* endStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    qasm3Parser::StatementOrScopeContext *body = nullptr;
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    ScalarTypeContext *scalarType();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *IN();
    StatementOrScopeContext *statementOrScope();
    SetExpressionContext *setExpression();
    antlr4::tree::TerminalNode *LBRACKET();
    RangeExpressionContext *rangeExpression();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    qasm3Parser::StatementOrScopeContext *if_body = nullptr;
    qasm3Parser::StatementOrScopeContext *else_body = nullptr;
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StatementOrScopeContext *> statementOrScope();
    StatementOrScopeContext* statementOrScope(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();
    MeasureExpressionContext *measureExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    qasm3Parser::StatementOrScopeContext *body = nullptr;
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    StatementOrScopeContext *statementOrScope();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  BarrierStatementContext : public antlr4::ParserRuleContext {
  public:
    BarrierStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BARRIER();
    antlr4::tree::TerminalNode *SEMICOLON();
    GateOperandListContext *gateOperandList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BarrierStatementContext* barrierStatement();

  class  BoxStatementContext : public antlr4::ParserRuleContext {
  public:
    BoxStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOX();
    ScopeContext *scope();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoxStatementContext* boxStatement();

  class  DelayStatementContext : public antlr4::ParserRuleContext {
  public:
    DelayStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELAY();
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *SEMICOLON();
    GateOperandListContext *gateOperandList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DelayStatementContext* delayStatement();

  class  GateCallStatementContext : public antlr4::ParserRuleContext {
  public:
    GateCallStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    GateOperandListContext *gateOperandList();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<GateModifierContext *> gateModifier();
    GateModifierContext* gateModifier(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    DesignatorContext *designator();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *GPHASE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GateCallStatementContext* gateCallStatement();

  class  MeasureArrowAssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    MeasureArrowAssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MeasureExpressionContext *measureExpression();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ARROW();
    IndexedIdentifierContext *indexedIdentifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeasureArrowAssignmentStatementContext* measureArrowAssignmentStatement();

  class  ResetStatementContext : public antlr4::ParserRuleContext {
  public:
    ResetStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESET();
    GateOperandContext *gateOperand();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResetStatementContext* resetStatement();

  class  AliasDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    AliasDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUALS();
    AliasExpressionContext *aliasExpression();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasDeclarationStatementContext* aliasDeclarationStatement();

  class  ClassicalDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    ClassicalDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMICOLON();
    ScalarTypeContext *scalarType();
    ArrayTypeContext *arrayType();
    antlr4::tree::TerminalNode *EQUALS();
    DeclarationExpressionContext *declarationExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassicalDeclarationStatementContext* classicalDeclarationStatement();

  class  ConstDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    ScalarTypeContext *scalarType();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *EQUALS();
    DeclarationExpressionContext *declarationExpression();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclarationStatementContext* constDeclarationStatement();

  class  IoDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    IoDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *OUTPUT();
    ScalarTypeContext *scalarType();
    ArrayTypeContext *arrayType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IoDeclarationStatementContext* ioDeclarationStatement();

  class  OldStyleDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    OldStyleDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *CREG();
    antlr4::tree::TerminalNode *QREG();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OldStyleDeclarationStatementContext* oldStyleDeclarationStatement();

  class  QuantumDeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    QuantumDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QubitTypeContext *qubitType();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuantumDeclarationStatementContext* quantumDeclarationStatement();

  class  DefStatementContext : public antlr4::ParserRuleContext {
  public:
    DefStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ScopeContext *scope();
    ArgumentDefinitionListContext *argumentDefinitionList();
    ReturnSignatureContext *returnSignature();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefStatementContext* defStatement();

  class  ExternStatementContext : public antlr4::ParserRuleContext {
  public:
    ExternStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTERN();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExternArgumentListContext *externArgumentList();
    ReturnSignatureContext *returnSignature();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternStatementContext* externStatement();

  class  GateStatementContext : public antlr4::ParserRuleContext {
  public:
    qasm3Parser::IdentifierListContext *params = nullptr;
    qasm3Parser::IdentifierListContext *qubits = nullptr;
    GateStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GATE();
    antlr4::tree::TerminalNode *Identifier();
    ScopeContext *scope();
    std::vector<IdentifierListContext *> identifierList();
    IdentifierListContext* identifierList(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GateStatementContext* gateStatement();

  class  AssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *op = nullptr;
    AssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexedIdentifierContext *indexedIdentifier();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *CompoundAssignmentOperator();
    ExpressionContext *expression();
    MeasureExpressionContext *measureExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStatementContext* assignmentStatement();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMICOLON();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  CalStatementContext : public antlr4::ParserRuleContext {
  public:
    CalStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CAL();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *CalibrationBlock();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CalStatementContext* calStatement();

  class  DefcalStatementContext : public antlr4::ParserRuleContext {
  public:
    DefcalStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFCAL();
    DefcalTargetContext *defcalTarget();
    DefcalOperandListContext *defcalOperandList();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ReturnSignatureContext *returnSignature();
    antlr4::tree::TerminalNode *CalibrationBlock();
    DefcalArgumentDefinitionListContext *defcalArgumentDefinitionList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefcalStatementContext* defcalStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BitwiseXorExpressionContext : public ExpressionContext {
  public:
    BitwiseXorExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *CARET();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AdditiveExpressionContext : public ExpressionContext {
  public:
    AdditiveExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DurationofExpressionContext : public ExpressionContext {
  public:
    DurationofExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *DURATIONOF();
    antlr4::tree::TerminalNode *LPAREN();
    ScopeContext *scope();
    antlr4::tree::TerminalNode *RPAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesisExpressionContext : public ExpressionContext {
  public:
    ParenthesisExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComparisonExpressionContext : public ExpressionContext {
  public:
    ComparisonExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ComparisonOperator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultiplicativeExpressionContext : public ExpressionContext {
  public:
    MultiplicativeExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PERCENT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalOrExpressionContext : public ExpressionContext {
  public:
    LogicalOrExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DOUBLE_PIPE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CastExpressionContext : public ExpressionContext {
  public:
    CastExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    ScalarTypeContext *scalarType();
    ArrayTypeContext *arrayType();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PowerExpressionContext : public ExpressionContext {
  public:
    PowerExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DOUBLE_ASTERISK();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitwiseOrExpressionContext : public ExpressionContext {
  public:
    BitwiseOrExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PIPE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallExpressionContext : public ExpressionContext {
  public:
    CallExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionListContext *expressionList();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitshiftExpressionContext : public ExpressionContext {
  public:
    BitshiftExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *BitshiftOperator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitwiseAndExpressionContext : public ExpressionContext {
  public:
    BitwiseAndExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *AMPERSAND();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqualityExpressionContext : public ExpressionContext {
  public:
    EqualityExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *EqualityOperator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalAndExpressionContext : public ExpressionContext {
  public:
    LogicalAndExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *DOUBLE_AMPERSAND();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IndexExpressionContext : public ExpressionContext {
  public:
    IndexExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    IndexOperatorContext *indexOperator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExpressionContext : public ExpressionContext {
  public:
    UnaryExpressionContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *EXCLAMATION_POINT();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiteralExpressionContext : public ExpressionContext {
  public:
    LiteralExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *BinaryIntegerLiteral();
    antlr4::tree::TerminalNode *OctalIntegerLiteral();
    antlr4::tree::TerminalNode *DecimalIntegerLiteral();
    antlr4::tree::TerminalNode *HexIntegerLiteral();
    antlr4::tree::TerminalNode *FloatLiteral();
    antlr4::tree::TerminalNode *ImaginaryLiteral();
    antlr4::tree::TerminalNode *BooleanLiteral();
    antlr4::tree::TerminalNode *BitstringLiteral();
    antlr4::tree::TerminalNode *TimingLiteral();
    antlr4::tree::TerminalNode *HardwareQubit();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  AliasExpressionContext : public antlr4::ParserRuleContext {
  public:
    AliasExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOUBLE_PLUS();
    antlr4::tree::TerminalNode* DOUBLE_PLUS(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasExpressionContext* aliasExpression();

  class  DeclarationExpressionContext : public antlr4::ParserRuleContext {
  public:
    DeclarationExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArrayLiteralContext *arrayLiteral();
    ExpressionContext *expression();
    MeasureExpressionContext *measureExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationExpressionContext* declarationExpression();

  class  MeasureExpressionContext : public antlr4::ParserRuleContext {
  public:
    MeasureExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEASURE();
    GateOperandContext *gateOperand();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeasureExpressionContext* measureExpression();

  class  RangeExpressionContext : public antlr4::ParserRuleContext {
  public:
    RangeExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangeExpressionContext* rangeExpression();

  class  SetExpressionContext : public antlr4::ParserRuleContext {
  public:
    SetExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetExpressionContext* setExpression();

  class  ArrayLiteralContext : public antlr4::ParserRuleContext {
  public:
    ArrayLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<ArrayLiteralContext *> arrayLiteral();
    ArrayLiteralContext* arrayLiteral(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayLiteralContext* arrayLiteral();

  class  IndexOperatorContext : public antlr4::ParserRuleContext {
  public:
    IndexOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    SetExpressionContext *setExpression();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<RangeExpressionContext *> rangeExpression();
    RangeExpressionContext* rangeExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexOperatorContext* indexOperator();

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

  class  ReturnSignatureContext : public antlr4::ParserRuleContext {
  public:
    ReturnSignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARROW();
    ScalarTypeContext *scalarType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnSignatureContext* returnSignature();

  class  GateModifierContext : public antlr4::ParserRuleContext {
  public:
    GateModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *INV();
    antlr4::tree::TerminalNode *POW();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *CTRL();
    antlr4::tree::TerminalNode *NEGCTRL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GateModifierContext* gateModifier();

  class  ScalarTypeContext : public antlr4::ParserRuleContext {
  public:
    ScalarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BIT();
    DesignatorContext *designator();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *ANGLE();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *DURATION();
    antlr4::tree::TerminalNode *STRETCH();
    antlr4::tree::TerminalNode *COMPLEX();
    antlr4::tree::TerminalNode *LBRACKET();
    ScalarTypeContext *scalarType();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScalarTypeContext* scalarType();

  class  QubitTypeContext : public antlr4::ParserRuleContext {
  public:
    QubitTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUBIT();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QubitTypeContext* qubitType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LBRACKET();
    ScalarTypeContext *scalarType();
    antlr4::tree::TerminalNode *COMMA();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *RBRACKET();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayTypeContext* arrayType();

  class  ArrayReferenceTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayReferenceTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LBRACKET();
    ScalarTypeContext *scalarType();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *MUTABLE();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *DIM();
    antlr4::tree::TerminalNode *EQUALS();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArrayReferenceTypeContext* arrayReferenceType();

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

  class  DefcalTargetContext : public antlr4::ParserRuleContext {
  public:
    DefcalTargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEASURE();
    antlr4::tree::TerminalNode *RESET();
    antlr4::tree::TerminalNode *DELAY();
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefcalTargetContext* defcalTarget();

  class  DefcalArgumentDefinitionContext : public antlr4::ParserRuleContext {
  public:
    DefcalArgumentDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    ArgumentDefinitionContext *argumentDefinition();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefcalArgumentDefinitionContext* defcalArgumentDefinition();

  class  DefcalOperandContext : public antlr4::ParserRuleContext {
  public:
    DefcalOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HardwareQubit();
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefcalOperandContext* defcalOperand();

  class  GateOperandContext : public antlr4::ParserRuleContext {
  public:
    GateOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IndexedIdentifierContext *indexedIdentifier();
    antlr4::tree::TerminalNode *HardwareQubit();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GateOperandContext* gateOperand();

  class  ExternArgumentContext : public antlr4::ParserRuleContext {
  public:
    ExternArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScalarTypeContext *scalarType();
    ArrayReferenceTypeContext *arrayReferenceType();
    antlr4::tree::TerminalNode *CREG();
    DesignatorContext *designator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternArgumentContext* externArgument();

  class  ArgumentDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ArgumentDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScalarTypeContext *scalarType();
    antlr4::tree::TerminalNode *Identifier();
    QubitTypeContext *qubitType();
    antlr4::tree::TerminalNode *CREG();
    antlr4::tree::TerminalNode *QREG();
    DesignatorContext *designator();
    ArrayReferenceTypeContext *arrayReferenceType();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentDefinitionContext* argumentDefinition();

  class  ArgumentDefinitionListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentDefinitionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentDefinitionContext *> argumentDefinition();
    ArgumentDefinitionContext* argumentDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentDefinitionListContext* argumentDefinitionList();

  class  DefcalArgumentDefinitionListContext : public antlr4::ParserRuleContext {
  public:
    DefcalArgumentDefinitionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DefcalArgumentDefinitionContext *> defcalArgumentDefinition();
    DefcalArgumentDefinitionContext* defcalArgumentDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefcalArgumentDefinitionListContext* defcalArgumentDefinitionList();

  class  DefcalOperandListContext : public antlr4::ParserRuleContext {
  public:
    DefcalOperandListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DefcalOperandContext *> defcalOperand();
    DefcalOperandContext* defcalOperand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefcalOperandListContext* defcalOperandList();

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

  class  GateOperandListContext : public antlr4::ParserRuleContext {
  public:
    GateOperandListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<GateOperandContext *> gateOperand();
    GateOperandContext* gateOperand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GateOperandListContext* gateOperandList();

  class  ExternArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ExternArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExternArgumentContext *> externArgument();
    ExternArgumentContext* externArgument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternArgumentListContext* externArgumentList();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

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

