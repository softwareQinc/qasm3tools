
// Generated from qasm3Parser.g4 by ANTLR 4.9.2

#pragma once


#include "qasm3ParserVisitor.h"

#include "qasm3Parser.h"


using namespace antlrcpp;
using namespace antlr4;

qasm3Parser::qasm3Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

qasm3Parser::~qasm3Parser() {
  delete _interpreter;
}

std::string qasm3Parser::getGrammarFileName() const {
  return "qasm3Parser.g4";
}

const std::vector<std::string>& qasm3Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& qasm3Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

qasm3Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ProgramContext::EOF() {
  return getToken(qasm3Parser::EOF, 0);
}

qasm3Parser::VersionContext* qasm3Parser::ProgramContext::version() {
  return getRuleContext<qasm3Parser::VersionContext>(0);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::ProgramContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::ProgramContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}


size_t qasm3Parser::ProgramContext::getRuleIndex() const {
  return qasm3Parser::RuleProgram;
}


antlrcpp::Any qasm3Parser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ProgramContext* qasm3Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, qasm3Parser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::OPENQASM) {
      setState(128);
      version();
    }
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::INCLUDE)
      | (1ULL << qasm3Parser::DEFCALGRAMMAR)
      | (1ULL << qasm3Parser::DEF)
      | (1ULL << qasm3Parser::CAL)
      | (1ULL << qasm3Parser::DEFCAL)
      | (1ULL << qasm3Parser::GATE)
      | (1ULL << qasm3Parser::EXTERN)
      | (1ULL << qasm3Parser::BOX)
      | (1ULL << qasm3Parser::LET)
      | (1ULL << qasm3Parser::BREAK)
      | (1ULL << qasm3Parser::CONTINUE)
      | (1ULL << qasm3Parser::IF)
      | (1ULL << qasm3Parser::END)
      | (1ULL << qasm3Parser::RETURN)
      | (1ULL << qasm3Parser::FOR)
      | (1ULL << qasm3Parser::WHILE)
      | (1ULL << qasm3Parser::PRAGMA)
      | (1ULL << qasm3Parser::AnnotationKeyword)
      | (1ULL << qasm3Parser::INPUT)
      | (1ULL << qasm3Parser::OUTPUT)
      | (1ULL << qasm3Parser::CONST)
      | (1ULL << qasm3Parser::QREG)
      | (1ULL << qasm3Parser::QUBIT)
      | (1ULL << qasm3Parser::CREG)
      | (1ULL << qasm3Parser::BOOL)
      | (1ULL << qasm3Parser::BIT)
      | (1ULL << qasm3Parser::INT)
      | (1ULL << qasm3Parser::UINT)
      | (1ULL << qasm3Parser::FLOAT)
      | (1ULL << qasm3Parser::ANGLE)
      | (1ULL << qasm3Parser::COMPLEX)
      | (1ULL << qasm3Parser::ARRAY)
      | (1ULL << qasm3Parser::DURATION)
      | (1ULL << qasm3Parser::STRETCH)
      | (1ULL << qasm3Parser::GPHASE)
      | (1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::DELAY)
      | (1ULL << qasm3Parser::RESET)
      | (1ULL << qasm3Parser::MEASURE)
      | (1ULL << qasm3Parser::BARRIER)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (qasm3Parser::MINUS - 66))
      | (1ULL << (qasm3Parser::TILDE - 66))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 66))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 66))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::Identifier - 66))
      | (1ULL << (qasm3Parser::HardwareQubit - 66))
      | (1ULL << (qasm3Parser::FloatLiteral - 66))
      | (1ULL << (qasm3Parser::TimingLiteral - 66))
      | (1ULL << (qasm3Parser::BitstringLiteral - 66)))) != 0)) {
      setState(131);
      statement();
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
    match(qasm3Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

qasm3Parser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::VersionContext::OPENQASM() {
  return getToken(qasm3Parser::OPENQASM, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::VersionSpecifier() {
  return getToken(qasm3Parser::VersionSpecifier, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::VersionContext::getRuleIndex() const {
  return qasm3Parser::RuleVersion;
}


antlrcpp::Any qasm3Parser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::VersionContext* qasm3Parser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 2, qasm3Parser::RuleVersion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(qasm3Parser::OPENQASM);
    setState(140);
    match(qasm3Parser::VersionSpecifier);
    setState(141);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

qasm3Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::PragmaContext* qasm3Parser::StatementContext::pragma() {
  return getRuleContext<qasm3Parser::PragmaContext>(0);
}

qasm3Parser::AliasDeclarationStatementContext* qasm3Parser::StatementContext::aliasDeclarationStatement() {
  return getRuleContext<qasm3Parser::AliasDeclarationStatementContext>(0);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::StatementContext::assignmentStatement() {
  return getRuleContext<qasm3Parser::AssignmentStatementContext>(0);
}

qasm3Parser::BarrierStatementContext* qasm3Parser::StatementContext::barrierStatement() {
  return getRuleContext<qasm3Parser::BarrierStatementContext>(0);
}

qasm3Parser::BoxStatementContext* qasm3Parser::StatementContext::boxStatement() {
  return getRuleContext<qasm3Parser::BoxStatementContext>(0);
}

qasm3Parser::BreakStatementContext* qasm3Parser::StatementContext::breakStatement() {
  return getRuleContext<qasm3Parser::BreakStatementContext>(0);
}

qasm3Parser::CalStatementContext* qasm3Parser::StatementContext::calStatement() {
  return getRuleContext<qasm3Parser::CalStatementContext>(0);
}

qasm3Parser::CalibrationGrammarStatementContext* qasm3Parser::StatementContext::calibrationGrammarStatement() {
  return getRuleContext<qasm3Parser::CalibrationGrammarStatementContext>(0);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::StatementContext::classicalDeclarationStatement() {
  return getRuleContext<qasm3Parser::ClassicalDeclarationStatementContext>(0);
}

qasm3Parser::ConstDeclarationStatementContext* qasm3Parser::StatementContext::constDeclarationStatement() {
  return getRuleContext<qasm3Parser::ConstDeclarationStatementContext>(0);
}

qasm3Parser::ContinueStatementContext* qasm3Parser::StatementContext::continueStatement() {
  return getRuleContext<qasm3Parser::ContinueStatementContext>(0);
}

qasm3Parser::DefStatementContext* qasm3Parser::StatementContext::defStatement() {
  return getRuleContext<qasm3Parser::DefStatementContext>(0);
}

qasm3Parser::DefcalStatementContext* qasm3Parser::StatementContext::defcalStatement() {
  return getRuleContext<qasm3Parser::DefcalStatementContext>(0);
}

qasm3Parser::DelayStatementContext* qasm3Parser::StatementContext::delayStatement() {
  return getRuleContext<qasm3Parser::DelayStatementContext>(0);
}

qasm3Parser::EndStatementContext* qasm3Parser::StatementContext::endStatement() {
  return getRuleContext<qasm3Parser::EndStatementContext>(0);
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::StatementContext::expressionStatement() {
  return getRuleContext<qasm3Parser::ExpressionStatementContext>(0);
}

qasm3Parser::ExternStatementContext* qasm3Parser::StatementContext::externStatement() {
  return getRuleContext<qasm3Parser::ExternStatementContext>(0);
}

qasm3Parser::ForStatementContext* qasm3Parser::StatementContext::forStatement() {
  return getRuleContext<qasm3Parser::ForStatementContext>(0);
}

qasm3Parser::GateCallStatementContext* qasm3Parser::StatementContext::gateCallStatement() {
  return getRuleContext<qasm3Parser::GateCallStatementContext>(0);
}

qasm3Parser::GateStatementContext* qasm3Parser::StatementContext::gateStatement() {
  return getRuleContext<qasm3Parser::GateStatementContext>(0);
}

qasm3Parser::IfStatementContext* qasm3Parser::StatementContext::ifStatement() {
  return getRuleContext<qasm3Parser::IfStatementContext>(0);
}

qasm3Parser::IncludeStatementContext* qasm3Parser::StatementContext::includeStatement() {
  return getRuleContext<qasm3Parser::IncludeStatementContext>(0);
}

qasm3Parser::IoDeclarationStatementContext* qasm3Parser::StatementContext::ioDeclarationStatement() {
  return getRuleContext<qasm3Parser::IoDeclarationStatementContext>(0);
}

qasm3Parser::MeasureArrowAssignmentStatementContext* qasm3Parser::StatementContext::measureArrowAssignmentStatement() {
  return getRuleContext<qasm3Parser::MeasureArrowAssignmentStatementContext>(0);
}

qasm3Parser::OldStyleDeclarationStatementContext* qasm3Parser::StatementContext::oldStyleDeclarationStatement() {
  return getRuleContext<qasm3Parser::OldStyleDeclarationStatementContext>(0);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::StatementContext::quantumDeclarationStatement() {
  return getRuleContext<qasm3Parser::QuantumDeclarationStatementContext>(0);
}

qasm3Parser::ResetStatementContext* qasm3Parser::StatementContext::resetStatement() {
  return getRuleContext<qasm3Parser::ResetStatementContext>(0);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::StatementContext::returnStatement() {
  return getRuleContext<qasm3Parser::ReturnStatementContext>(0);
}

qasm3Parser::WhileStatementContext* qasm3Parser::StatementContext::whileStatement() {
  return getRuleContext<qasm3Parser::WhileStatementContext>(0);
}

std::vector<qasm3Parser::AnnotationContext *> qasm3Parser::StatementContext::annotation() {
  return getRuleContexts<qasm3Parser::AnnotationContext>();
}

qasm3Parser::AnnotationContext* qasm3Parser::StatementContext::annotation(size_t i) {
  return getRuleContext<qasm3Parser::AnnotationContext>(i);
}


size_t qasm3Parser::StatementContext::getRuleIndex() const {
  return qasm3Parser::RuleStatement;
}


antlrcpp::Any qasm3Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::StatementContext* qasm3Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, qasm3Parser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::PRAGMA: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        pragma();
        break;
      }

      case qasm3Parser::INCLUDE:
      case qasm3Parser::DEFCALGRAMMAR:
      case qasm3Parser::DEF:
      case qasm3Parser::CAL:
      case qasm3Parser::DEFCAL:
      case qasm3Parser::GATE:
      case qasm3Parser::EXTERN:
      case qasm3Parser::BOX:
      case qasm3Parser::LET:
      case qasm3Parser::BREAK:
      case qasm3Parser::CONTINUE:
      case qasm3Parser::IF:
      case qasm3Parser::END:
      case qasm3Parser::RETURN:
      case qasm3Parser::FOR:
      case qasm3Parser::WHILE:
      case qasm3Parser::AnnotationKeyword:
      case qasm3Parser::INPUT:
      case qasm3Parser::OUTPUT:
      case qasm3Parser::CONST:
      case qasm3Parser::QREG:
      case qasm3Parser::QUBIT:
      case qasm3Parser::CREG:
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::GPHASE:
      case qasm3Parser::INV:
      case qasm3Parser::POW:
      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::DELAY:
      case qasm3Parser::RESET:
      case qasm3Parser::MEASURE:
      case qasm3Parser::BARRIER:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(147);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == qasm3Parser::AnnotationKeyword) {
          setState(144);
          annotation();
          setState(149);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(178);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(150);
          aliasDeclarationStatement();
          break;
        }

        case 2: {
          setState(151);
          assignmentStatement();
          break;
        }

        case 3: {
          setState(152);
          barrierStatement();
          break;
        }

        case 4: {
          setState(153);
          boxStatement();
          break;
        }

        case 5: {
          setState(154);
          breakStatement();
          break;
        }

        case 6: {
          setState(155);
          calStatement();
          break;
        }

        case 7: {
          setState(156);
          calibrationGrammarStatement();
          break;
        }

        case 8: {
          setState(157);
          classicalDeclarationStatement();
          break;
        }

        case 9: {
          setState(158);
          constDeclarationStatement();
          break;
        }

        case 10: {
          setState(159);
          continueStatement();
          break;
        }

        case 11: {
          setState(160);
          defStatement();
          break;
        }

        case 12: {
          setState(161);
          defcalStatement();
          break;
        }

        case 13: {
          setState(162);
          delayStatement();
          break;
        }

        case 14: {
          setState(163);
          endStatement();
          break;
        }

        case 15: {
          setState(164);
          expressionStatement();
          break;
        }

        case 16: {
          setState(165);
          externStatement();
          break;
        }

        case 17: {
          setState(166);
          forStatement();
          break;
        }

        case 18: {
          setState(167);
          gateCallStatement();
          break;
        }

        case 19: {
          setState(168);
          gateStatement();
          break;
        }

        case 20: {
          setState(169);
          ifStatement();
          break;
        }

        case 21: {
          setState(170);
          includeStatement();
          break;
        }

        case 22: {
          setState(171);
          ioDeclarationStatement();
          break;
        }

        case 23: {
          setState(172);
          measureArrowAssignmentStatement();
          break;
        }

        case 24: {
          setState(173);
          oldStyleDeclarationStatement();
          break;
        }

        case 25: {
          setState(174);
          quantumDeclarationStatement();
          break;
        }

        case 26: {
          setState(175);
          resetStatement();
          break;
        }

        case 27: {
          setState(176);
          returnStatement();
          break;
        }

        case 28: {
          setState(177);
          whileStatement();
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

qasm3Parser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AnnotationContext::AnnotationKeyword() {
  return getToken(qasm3Parser::AnnotationKeyword, 0);
}

tree::TerminalNode* qasm3Parser::AnnotationContext::RemainingLineContent() {
  return getToken(qasm3Parser::RemainingLineContent, 0);
}


size_t qasm3Parser::AnnotationContext::getRuleIndex() const {
  return qasm3Parser::RuleAnnotation;
}


antlrcpp::Any qasm3Parser::AnnotationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAnnotation(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AnnotationContext* qasm3Parser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 6, qasm3Parser::RuleAnnotation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(qasm3Parser::AnnotationKeyword);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::RemainingLineContent) {
      setState(183);
      match(qasm3Parser::RemainingLineContent);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

qasm3Parser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ScopeContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ScopeContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::ScopeContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::ScopeContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}


size_t qasm3Parser::ScopeContext::getRuleIndex() const {
  return qasm3Parser::RuleScope;
}


antlrcpp::Any qasm3Parser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ScopeContext* qasm3Parser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 8, qasm3Parser::RuleScope);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(qasm3Parser::LBRACE);
    setState(190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::INCLUDE)
      | (1ULL << qasm3Parser::DEFCALGRAMMAR)
      | (1ULL << qasm3Parser::DEF)
      | (1ULL << qasm3Parser::CAL)
      | (1ULL << qasm3Parser::DEFCAL)
      | (1ULL << qasm3Parser::GATE)
      | (1ULL << qasm3Parser::EXTERN)
      | (1ULL << qasm3Parser::BOX)
      | (1ULL << qasm3Parser::LET)
      | (1ULL << qasm3Parser::BREAK)
      | (1ULL << qasm3Parser::CONTINUE)
      | (1ULL << qasm3Parser::IF)
      | (1ULL << qasm3Parser::END)
      | (1ULL << qasm3Parser::RETURN)
      | (1ULL << qasm3Parser::FOR)
      | (1ULL << qasm3Parser::WHILE)
      | (1ULL << qasm3Parser::PRAGMA)
      | (1ULL << qasm3Parser::AnnotationKeyword)
      | (1ULL << qasm3Parser::INPUT)
      | (1ULL << qasm3Parser::OUTPUT)
      | (1ULL << qasm3Parser::CONST)
      | (1ULL << qasm3Parser::QREG)
      | (1ULL << qasm3Parser::QUBIT)
      | (1ULL << qasm3Parser::CREG)
      | (1ULL << qasm3Parser::BOOL)
      | (1ULL << qasm3Parser::BIT)
      | (1ULL << qasm3Parser::INT)
      | (1ULL << qasm3Parser::UINT)
      | (1ULL << qasm3Parser::FLOAT)
      | (1ULL << qasm3Parser::ANGLE)
      | (1ULL << qasm3Parser::COMPLEX)
      | (1ULL << qasm3Parser::ARRAY)
      | (1ULL << qasm3Parser::DURATION)
      | (1ULL << qasm3Parser::STRETCH)
      | (1ULL << qasm3Parser::GPHASE)
      | (1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::DELAY)
      | (1ULL << qasm3Parser::RESET)
      | (1ULL << qasm3Parser::MEASURE)
      | (1ULL << qasm3Parser::BARRIER)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (qasm3Parser::MINUS - 66))
      | (1ULL << (qasm3Parser::TILDE - 66))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 66))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 66))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 66))
      | (1ULL << (qasm3Parser::Identifier - 66))
      | (1ULL << (qasm3Parser::HardwareQubit - 66))
      | (1ULL << (qasm3Parser::FloatLiteral - 66))
      | (1ULL << (qasm3Parser::TimingLiteral - 66))
      | (1ULL << (qasm3Parser::BitstringLiteral - 66)))) != 0)) {
      setState(187);
      statement();
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(193);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PragmaContext ------------------------------------------------------------------

qasm3Parser::PragmaContext::PragmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::PragmaContext::PRAGMA() {
  return getToken(qasm3Parser::PRAGMA, 0);
}

tree::TerminalNode* qasm3Parser::PragmaContext::RemainingLineContent() {
  return getToken(qasm3Parser::RemainingLineContent, 0);
}


size_t qasm3Parser::PragmaContext::getRuleIndex() const {
  return qasm3Parser::RulePragma;
}


antlrcpp::Any qasm3Parser::PragmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitPragma(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PragmaContext* qasm3Parser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 10, qasm3Parser::RulePragma);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(qasm3Parser::PRAGMA);
    setState(196);
    match(qasm3Parser::RemainingLineContent);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementOrScopeContext ------------------------------------------------------------------

qasm3Parser::StatementOrScopeContext::StatementOrScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::StatementContext* qasm3Parser::StatementOrScopeContext::statement() {
  return getRuleContext<qasm3Parser::StatementContext>(0);
}

qasm3Parser::ScopeContext* qasm3Parser::StatementOrScopeContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}


size_t qasm3Parser::StatementOrScopeContext::getRuleIndex() const {
  return qasm3Parser::RuleStatementOrScope;
}


antlrcpp::Any qasm3Parser::StatementOrScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitStatementOrScope(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::statementOrScope() {
  StatementOrScopeContext *_localctx = _tracker.createInstance<StatementOrScopeContext>(_ctx, getState());
  enterRule(_localctx, 12, qasm3Parser::RuleStatementOrScope);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INCLUDE:
      case qasm3Parser::DEFCALGRAMMAR:
      case qasm3Parser::DEF:
      case qasm3Parser::CAL:
      case qasm3Parser::DEFCAL:
      case qasm3Parser::GATE:
      case qasm3Parser::EXTERN:
      case qasm3Parser::BOX:
      case qasm3Parser::LET:
      case qasm3Parser::BREAK:
      case qasm3Parser::CONTINUE:
      case qasm3Parser::IF:
      case qasm3Parser::END:
      case qasm3Parser::RETURN:
      case qasm3Parser::FOR:
      case qasm3Parser::WHILE:
      case qasm3Parser::PRAGMA:
      case qasm3Parser::AnnotationKeyword:
      case qasm3Parser::INPUT:
      case qasm3Parser::OUTPUT:
      case qasm3Parser::CONST:
      case qasm3Parser::QREG:
      case qasm3Parser::QUBIT:
      case qasm3Parser::CREG:
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::GPHASE:
      case qasm3Parser::INV:
      case qasm3Parser::POW:
      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::DELAY:
      case qasm3Parser::RESET:
      case qasm3Parser::MEASURE:
      case qasm3Parser::BARRIER:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(198);
        statement();
        break;
      }

      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(199);
        scope();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarStatementContext ------------------------------------------------------------------

qasm3Parser::CalibrationGrammarStatementContext::CalibrationGrammarStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarStatementContext::DEFCALGRAMMAR() {
  return getToken(qasm3Parser::DEFCALGRAMMAR, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarStatementContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::CalibrationGrammarStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammarStatement;
}


antlrcpp::Any qasm3Parser::CalibrationGrammarStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalibrationGrammarStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarStatementContext* qasm3Parser::calibrationGrammarStatement() {
  CalibrationGrammarStatementContext *_localctx = _tracker.createInstance<CalibrationGrammarStatementContext>(_ctx, getState());
  enterRule(_localctx, 14, qasm3Parser::RuleCalibrationGrammarStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(qasm3Parser::DEFCALGRAMMAR);
    setState(203);
    match(qasm3Parser::StringLiteral);
    setState(204);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeStatementContext ------------------------------------------------------------------

qasm3Parser::IncludeStatementContext::IncludeStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IncludeStatementContext::INCLUDE() {
  return getToken(qasm3Parser::INCLUDE, 0);
}

tree::TerminalNode* qasm3Parser::IncludeStatementContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::IncludeStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::IncludeStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleIncludeStatement;
}


antlrcpp::Any qasm3Parser::IncludeStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIncludeStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IncludeStatementContext* qasm3Parser::includeStatement() {
  IncludeStatementContext *_localctx = _tracker.createInstance<IncludeStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, qasm3Parser::RuleIncludeStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(qasm3Parser::INCLUDE);
    setState(207);
    match(qasm3Parser::StringLiteral);
    setState(208);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

qasm3Parser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BreakStatementContext::BREAK() {
  return getToken(qasm3Parser::BREAK, 0);
}

tree::TerminalNode* qasm3Parser::BreakStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::BreakStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBreakStatement;
}


antlrcpp::Any qasm3Parser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BreakStatementContext* qasm3Parser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 18, qasm3Parser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(qasm3Parser::BREAK);
    setState(211);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

qasm3Parser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ContinueStatementContext::CONTINUE() {
  return getToken(qasm3Parser::CONTINUE, 0);
}

tree::TerminalNode* qasm3Parser::ContinueStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ContinueStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleContinueStatement;
}


antlrcpp::Any qasm3Parser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ContinueStatementContext* qasm3Parser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, qasm3Parser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(qasm3Parser::CONTINUE);
    setState(214);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndStatementContext ------------------------------------------------------------------

qasm3Parser::EndStatementContext::EndStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::EndStatementContext::END() {
  return getToken(qasm3Parser::END, 0);
}

tree::TerminalNode* qasm3Parser::EndStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::EndStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleEndStatement;
}


antlrcpp::Any qasm3Parser::EndStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitEndStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EndStatementContext* qasm3Parser::endStatement() {
  EndStatementContext *_localctx = _tracker.createInstance<EndStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, qasm3Parser::RuleEndStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(qasm3Parser::END);
    setState(217);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

qasm3Parser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ForStatementContext::FOR() {
  return getToken(qasm3Parser::FOR, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ForStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

std::vector<tree::TerminalNode *> qasm3Parser::ForStatementContext::Identifier() {
  return getTokens(qasm3Parser::Identifier);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::Identifier(size_t i) {
  return getToken(qasm3Parser::Identifier, i);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::IN() {
  return getToken(qasm3Parser::IN, 0);
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::ForStatementContext::statementOrScope() {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(0);
}

qasm3Parser::SetExpressionContext* qasm3Parser::ForStatementContext::setExpression() {
  return getRuleContext<qasm3Parser::SetExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::RangeExpressionContext* qasm3Parser::ForStatementContext::rangeExpression() {
  return getRuleContext<qasm3Parser::RangeExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ForStatementContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ForStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleForStatement;
}


antlrcpp::Any qasm3Parser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ForStatementContext* qasm3Parser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, qasm3Parser::RuleForStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(qasm3Parser::FOR);
    setState(220);
    scalarType();
    setState(221);
    match(qasm3Parser::Identifier);
    setState(222);
    match(qasm3Parser::IN);
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        setState(223);
        setExpression();
        break;
      }

      case qasm3Parser::LBRACKET: {
        setState(224);
        match(qasm3Parser::LBRACKET);
        setState(225);
        rangeExpression();
        setState(226);
        match(qasm3Parser::RBRACKET);
        break;
      }

      case qasm3Parser::Identifier: {
        setState(228);
        match(qasm3Parser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(231);
    dynamic_cast<ForStatementContext *>(_localctx)->body = statementOrScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

qasm3Parser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IfStatementContext::IF() {
  return getToken(qasm3Parser::IF, 0);
}

tree::TerminalNode* qasm3Parser::IfStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::IfStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::IfStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<qasm3Parser::StatementOrScopeContext *> qasm3Parser::IfStatementContext::statementOrScope() {
  return getRuleContexts<qasm3Parser::StatementOrScopeContext>();
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::IfStatementContext::statementOrScope(size_t i) {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(i);
}

tree::TerminalNode* qasm3Parser::IfStatementContext::ELSE() {
  return getToken(qasm3Parser::ELSE, 0);
}


size_t qasm3Parser::IfStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleIfStatement;
}


antlrcpp::Any qasm3Parser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IfStatementContext* qasm3Parser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, qasm3Parser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(qasm3Parser::IF);
    setState(234);
    match(qasm3Parser::LPAREN);
    setState(235);
    expression(0);
    setState(236);
    match(qasm3Parser::RPAREN);
    setState(237);
    dynamic_cast<IfStatementContext *>(_localctx)->if_body = statementOrScope();
    setState(240);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(238);
      match(qasm3Parser::ELSE);
      setState(239);
      dynamic_cast<IfStatementContext *>(_localctx)->else_body = statementOrScope();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

qasm3Parser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ReturnStatementContext::RETURN() {
  return getToken(qasm3Parser::RETURN, 0);
}

tree::TerminalNode* qasm3Parser::ReturnStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ReturnStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::ReturnStatementContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}


size_t qasm3Parser::ReturnStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleReturnStatement;
}


antlrcpp::Any qasm3Parser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, qasm3Parser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(qasm3Parser::RETURN);
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(243);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        setState(244);
        measureExpression();
        break;
      }

      case qasm3Parser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(247);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

qasm3Parser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::WhileStatementContext::WHILE() {
  return getToken(qasm3Parser::WHILE, 0);
}

tree::TerminalNode* qasm3Parser::WhileStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::WhileStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::WhileStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::StatementOrScopeContext* qasm3Parser::WhileStatementContext::statementOrScope() {
  return getRuleContext<qasm3Parser::StatementOrScopeContext>(0);
}


size_t qasm3Parser::WhileStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleWhileStatement;
}


antlrcpp::Any qasm3Parser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::WhileStatementContext* qasm3Parser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, qasm3Parser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(qasm3Parser::WHILE);
    setState(250);
    match(qasm3Parser::LPAREN);
    setState(251);
    expression(0);
    setState(252);
    match(qasm3Parser::RPAREN);
    setState(253);
    dynamic_cast<WhileStatementContext *>(_localctx)->body = statementOrScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BarrierStatementContext ------------------------------------------------------------------

qasm3Parser::BarrierStatementContext::BarrierStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BarrierStatementContext::BARRIER() {
  return getToken(qasm3Parser::BARRIER, 0);
}

tree::TerminalNode* qasm3Parser::BarrierStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::BarrierStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}


size_t qasm3Parser::BarrierStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBarrierStatement;
}


antlrcpp::Any qasm3Parser::BarrierStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBarrierStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BarrierStatementContext* qasm3Parser::barrierStatement() {
  BarrierStatementContext *_localctx = _tracker.createInstance<BarrierStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, qasm3Parser::RuleBarrierStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(qasm3Parser::BARRIER);
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit) {
      setState(256);
      gateOperandList();
    }
    setState(259);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoxStatementContext ------------------------------------------------------------------

qasm3Parser::BoxStatementContext::BoxStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BoxStatementContext::BOX() {
  return getToken(qasm3Parser::BOX, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::BoxStatementContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::BoxStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::BoxStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBoxStatement;
}


antlrcpp::Any qasm3Parser::BoxStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBoxStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BoxStatementContext* qasm3Parser::boxStatement() {
  BoxStatementContext *_localctx = _tracker.createInstance<BoxStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, qasm3Parser::RuleBoxStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(qasm3Parser::BOX);
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(262);
      designator();
    }
    setState(265);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DelayStatementContext ------------------------------------------------------------------

qasm3Parser::DelayStatementContext::DelayStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DelayStatementContext::DELAY() {
  return getToken(qasm3Parser::DELAY, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::DelayStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::DelayStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::DelayStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}


size_t qasm3Parser::DelayStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleDelayStatement;
}


antlrcpp::Any qasm3Parser::DelayStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDelayStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DelayStatementContext* qasm3Parser::delayStatement() {
  DelayStatementContext *_localctx = _tracker.createInstance<DelayStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, qasm3Parser::RuleDelayStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(qasm3Parser::DELAY);
    setState(268);
    designator();
    setState(270);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit) {
      setState(269);
      gateOperandList();
    }
    setState(272);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateCallStatementContext ------------------------------------------------------------------

qasm3Parser::GateCallStatementContext::GateCallStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::GateOperandListContext* qasm3Parser::GateCallStatementContext::gateOperandList() {
  return getRuleContext<qasm3Parser::GateOperandListContext>(0);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

std::vector<qasm3Parser::GateModifierContext *> qasm3Parser::GateCallStatementContext::gateModifier() {
  return getRuleContexts<qasm3Parser::GateModifierContext>();
}

qasm3Parser::GateModifierContext* qasm3Parser::GateCallStatementContext::gateModifier(size_t i) {
  return getRuleContext<qasm3Parser::GateModifierContext>(i);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::GateCallStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::GateCallStatementContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::GateCallStatementContext::GPHASE() {
  return getToken(qasm3Parser::GPHASE, 0);
}


size_t qasm3Parser::GateCallStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleGateCallStatement;
}


antlrcpp::Any qasm3Parser::GateCallStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateCallStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateCallStatementContext* qasm3Parser::gateCallStatement() {
  GateCallStatementContext *_localctx = _tracker.createInstance<GateCallStatementContext>(_ctx, getState());
  enterRule(_localctx, 38, qasm3Parser::RuleGateCallStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::INV)
        | (1ULL << qasm3Parser::POW)
        | (1ULL << qasm3Parser::CTRL)
        | (1ULL << qasm3Parser::NEGCTRL))) != 0)) {
        setState(274);
        gateModifier();
        setState(279);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(280);
      match(qasm3Parser::Identifier);
      setState(286);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LPAREN) {
        setState(281);
        match(qasm3Parser::LPAREN);
        setState(283);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 30) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 30)) & ((1ULL << (qasm3Parser::BOOL - 30))
          | (1ULL << (qasm3Parser::BIT - 30))
          | (1ULL << (qasm3Parser::INT - 30))
          | (1ULL << (qasm3Parser::UINT - 30))
          | (1ULL << (qasm3Parser::FLOAT - 30))
          | (1ULL << (qasm3Parser::ANGLE - 30))
          | (1ULL << (qasm3Parser::COMPLEX - 30))
          | (1ULL << (qasm3Parser::ARRAY - 30))
          | (1ULL << (qasm3Parser::DURATION - 30))
          | (1ULL << (qasm3Parser::STRETCH - 30))
          | (1ULL << (qasm3Parser::DURATIONOF - 30))
          | (1ULL << (qasm3Parser::BooleanLiteral - 30))
          | (1ULL << (qasm3Parser::LPAREN - 30))
          | (1ULL << (qasm3Parser::MINUS - 30))
          | (1ULL << (qasm3Parser::TILDE - 30))
          | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 30))
          | (1ULL << (qasm3Parser::ImaginaryLiteral - 30))
          | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::OctalIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::HexIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::Identifier - 30))
          | (1ULL << (qasm3Parser::HardwareQubit - 30))
          | (1ULL << (qasm3Parser::FloatLiteral - 30))
          | (1ULL << (qasm3Parser::TimingLiteral - 30))
          | (1ULL << (qasm3Parser::BitstringLiteral - 30)))) != 0)) {
          setState(282);
          expressionList();
        }
        setState(285);
        match(qasm3Parser::RPAREN);
      }
      setState(289);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LBRACKET) {
        setState(288);
        designator();
      }
      setState(291);
      gateOperandList();
      setState(292);
      match(qasm3Parser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::INV)
        | (1ULL << qasm3Parser::POW)
        | (1ULL << qasm3Parser::CTRL)
        | (1ULL << qasm3Parser::NEGCTRL))) != 0)) {
        setState(294);
        gateModifier();
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(300);
      match(qasm3Parser::GPHASE);
      setState(306);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LPAREN) {
        setState(301);
        match(qasm3Parser::LPAREN);
        setState(303);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 30) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 30)) & ((1ULL << (qasm3Parser::BOOL - 30))
          | (1ULL << (qasm3Parser::BIT - 30))
          | (1ULL << (qasm3Parser::INT - 30))
          | (1ULL << (qasm3Parser::UINT - 30))
          | (1ULL << (qasm3Parser::FLOAT - 30))
          | (1ULL << (qasm3Parser::ANGLE - 30))
          | (1ULL << (qasm3Parser::COMPLEX - 30))
          | (1ULL << (qasm3Parser::ARRAY - 30))
          | (1ULL << (qasm3Parser::DURATION - 30))
          | (1ULL << (qasm3Parser::STRETCH - 30))
          | (1ULL << (qasm3Parser::DURATIONOF - 30))
          | (1ULL << (qasm3Parser::BooleanLiteral - 30))
          | (1ULL << (qasm3Parser::LPAREN - 30))
          | (1ULL << (qasm3Parser::MINUS - 30))
          | (1ULL << (qasm3Parser::TILDE - 30))
          | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 30))
          | (1ULL << (qasm3Parser::ImaginaryLiteral - 30))
          | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::OctalIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::HexIntegerLiteral - 30))
          | (1ULL << (qasm3Parser::Identifier - 30))
          | (1ULL << (qasm3Parser::HardwareQubit - 30))
          | (1ULL << (qasm3Parser::FloatLiteral - 30))
          | (1ULL << (qasm3Parser::TimingLiteral - 30))
          | (1ULL << (qasm3Parser::BitstringLiteral - 30)))) != 0)) {
          setState(302);
          expressionList();
        }
        setState(305);
        match(qasm3Parser::RPAREN);
      }
      setState(309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::LBRACKET) {
        setState(308);
        designator();
      }
      setState(312);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier

      || _la == qasm3Parser::HardwareQubit) {
        setState(311);
        gateOperandList();
      }
      setState(314);
      match(qasm3Parser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureArrowAssignmentStatementContext ------------------------------------------------------------------

qasm3Parser::MeasureArrowAssignmentStatementContext::MeasureArrowAssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::MeasureArrowAssignmentStatementContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::MeasureArrowAssignmentStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::MeasureArrowAssignmentStatementContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::MeasureArrowAssignmentStatementContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}


size_t qasm3Parser::MeasureArrowAssignmentStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleMeasureArrowAssignmentStatement;
}


antlrcpp::Any qasm3Parser::MeasureArrowAssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMeasureArrowAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::MeasureArrowAssignmentStatementContext* qasm3Parser::measureArrowAssignmentStatement() {
  MeasureArrowAssignmentStatementContext *_localctx = _tracker.createInstance<MeasureArrowAssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 40, qasm3Parser::RuleMeasureArrowAssignmentStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    measureExpression();
    setState(320);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(318);
      match(qasm3Parser::ARROW);
      setState(319);
      indexedIdentifier();
    }
    setState(322);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResetStatementContext ------------------------------------------------------------------

qasm3Parser::ResetStatementContext::ResetStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ResetStatementContext::RESET() {
  return getToken(qasm3Parser::RESET, 0);
}

qasm3Parser::GateOperandContext* qasm3Parser::ResetStatementContext::gateOperand() {
  return getRuleContext<qasm3Parser::GateOperandContext>(0);
}

tree::TerminalNode* qasm3Parser::ResetStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ResetStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleResetStatement;
}


antlrcpp::Any qasm3Parser::ResetStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitResetStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ResetStatementContext* qasm3Parser::resetStatement() {
  ResetStatementContext *_localctx = _tracker.createInstance<ResetStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, qasm3Parser::RuleResetStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(qasm3Parser::RESET);
    setState(325);
    gateOperand();
    setState(326);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::AliasDeclarationStatementContext::AliasDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::LET() {
  return getToken(qasm3Parser::LET, 0);
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::AliasExpressionContext* qasm3Parser::AliasDeclarationStatementContext::aliasExpression() {
  return getRuleContext<qasm3Parser::AliasExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::AliasDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::AliasDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasDeclarationStatement;
}


antlrcpp::Any qasm3Parser::AliasDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAliasDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasDeclarationStatementContext* qasm3Parser::aliasDeclarationStatement() {
  AliasDeclarationStatementContext *_localctx = _tracker.createInstance<AliasDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, qasm3Parser::RuleAliasDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    match(qasm3Parser::LET);
    setState(329);
    match(qasm3Parser::Identifier);
    setState(330);
    match(qasm3Parser::EQUALS);
    setState(331);
    aliasExpression();
    setState(332);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::ClassicalDeclarationStatementContext::ClassicalDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ClassicalDeclarationStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::ClassicalDeclarationStatementContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::DeclarationExpressionContext* qasm3Parser::ClassicalDeclarationStatementContext::declarationExpression() {
  return getRuleContext<qasm3Parser::DeclarationExpressionContext>(0);
}


size_t qasm3Parser::ClassicalDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalDeclarationStatement;
}


antlrcpp::Any qasm3Parser::ClassicalDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::classicalDeclarationStatement() {
  ClassicalDeclarationStatementContext *_localctx = _tracker.createInstance<ClassicalDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 46, qasm3Parser::RuleClassicalDeclarationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        setState(334);
        scalarType();
        break;
      }

      case qasm3Parser::ARRAY: {
        setState(335);
        arrayType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(338);
    match(qasm3Parser::Identifier);
    setState(341);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(339);
      match(qasm3Parser::EQUALS);
      setState(340);
      declarationExpression();
    }
    setState(343);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::ConstDeclarationStatementContext::ConstDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::CONST() {
  return getToken(qasm3Parser::CONST, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ConstDeclarationStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::DeclarationExpressionContext* qasm3Parser::ConstDeclarationStatementContext::declarationExpression() {
  return getRuleContext<qasm3Parser::DeclarationExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ConstDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ConstDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleConstDeclarationStatement;
}


antlrcpp::Any qasm3Parser::ConstDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitConstDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ConstDeclarationStatementContext* qasm3Parser::constDeclarationStatement() {
  ConstDeclarationStatementContext *_localctx = _tracker.createInstance<ConstDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, qasm3Parser::RuleConstDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    match(qasm3Parser::CONST);
    setState(346);
    scalarType();
    setState(347);
    match(qasm3Parser::Identifier);
    setState(348);
    match(qasm3Parser::EQUALS);
    setState(349);
    declarationExpression();
    setState(350);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::IoDeclarationStatementContext::IoDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::INPUT() {
  return getToken(qasm3Parser::INPUT, 0);
}

tree::TerminalNode* qasm3Parser::IoDeclarationStatementContext::OUTPUT() {
  return getToken(qasm3Parser::OUTPUT, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::IoDeclarationStatementContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::IoDeclarationStatementContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}


size_t qasm3Parser::IoDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleIoDeclarationStatement;
}


antlrcpp::Any qasm3Parser::IoDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIoDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IoDeclarationStatementContext* qasm3Parser::ioDeclarationStatement() {
  IoDeclarationStatementContext *_localctx = _tracker.createInstance<IoDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, qasm3Parser::RuleIoDeclarationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::INPUT

    || _la == qasm3Parser::OUTPUT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        setState(353);
        scalarType();
        break;
      }

      case qasm3Parser::ARRAY: {
        setState(354);
        arrayType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(357);
    match(qasm3Parser::Identifier);
    setState(358);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OldStyleDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::OldStyleDeclarationStatementContext::OldStyleDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

tree::TerminalNode* qasm3Parser::OldStyleDeclarationStatementContext::QREG() {
  return getToken(qasm3Parser::QREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::OldStyleDeclarationStatementContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::OldStyleDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleOldStyleDeclarationStatement;
}


antlrcpp::Any qasm3Parser::OldStyleDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitOldStyleDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::OldStyleDeclarationStatementContext* qasm3Parser::oldStyleDeclarationStatement() {
  OldStyleDeclarationStatementContext *_localctx = _tracker.createInstance<OldStyleDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, qasm3Parser::RuleOldStyleDeclarationStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::QREG

    || _la == qasm3Parser::CREG)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(361);
    match(qasm3Parser::Identifier);
    setState(363);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(362);
      designator();
    }
    setState(365);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::QuantumDeclarationStatementContext::QuantumDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QubitTypeContext* qasm3Parser::QuantumDeclarationStatementContext::qubitType() {
  return getRuleContext<qasm3Parser::QubitTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::QuantumDeclarationStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumDeclarationStatement;
}


antlrcpp::Any qasm3Parser::QuantumDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumDeclarationStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::quantumDeclarationStatement() {
  QuantumDeclarationStatementContext *_localctx = _tracker.createInstance<QuantumDeclarationStatementContext>(_ctx, getState());
  enterRule(_localctx, 54, qasm3Parser::RuleQuantumDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    qubitType();
    setState(368);
    match(qasm3Parser::Identifier);
    setState(369);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefStatementContext ------------------------------------------------------------------

qasm3Parser::DefStatementContext::DefStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefStatementContext::DEF() {
  return getToken(qasm3Parser::DEF, 0);
}

tree::TerminalNode* qasm3Parser::DefStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::DefStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::DefStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::DefStatementContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

qasm3Parser::ArgumentDefinitionListContext* qasm3Parser::DefStatementContext::argumentDefinitionList() {
  return getRuleContext<qasm3Parser::ArgumentDefinitionListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::DefStatementContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}


size_t qasm3Parser::DefStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleDefStatement;
}


antlrcpp::Any qasm3Parser::DefStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefStatementContext* qasm3Parser::defStatement() {
  DefStatementContext *_localctx = _tracker.createInstance<DefStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, qasm3Parser::RuleDefStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(qasm3Parser::DEF);
    setState(372);
    match(qasm3Parser::Identifier);
    setState(373);
    match(qasm3Parser::LPAREN);
    setState(375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::READONLY)
      | (1ULL << qasm3Parser::MUTABLE)
      | (1ULL << qasm3Parser::QREG)
      | (1ULL << qasm3Parser::QUBIT)
      | (1ULL << qasm3Parser::CREG)
      | (1ULL << qasm3Parser::BOOL)
      | (1ULL << qasm3Parser::BIT)
      | (1ULL << qasm3Parser::INT)
      | (1ULL << qasm3Parser::UINT)
      | (1ULL << qasm3Parser::FLOAT)
      | (1ULL << qasm3Parser::ANGLE)
      | (1ULL << qasm3Parser::COMPLEX)
      | (1ULL << qasm3Parser::DURATION)
      | (1ULL << qasm3Parser::STRETCH))) != 0)) {
      setState(374);
      argumentDefinitionList();
    }
    setState(377);
    match(qasm3Parser::RPAREN);
    setState(379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(378);
      returnSignature();
    }
    setState(381);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternStatementContext ------------------------------------------------------------------

qasm3Parser::ExternStatementContext::ExternStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::EXTERN() {
  return getToken(qasm3Parser::EXTERN, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ExternArgumentListContext* qasm3Parser::ExternStatementContext::externArgumentList() {
  return getRuleContext<qasm3Parser::ExternArgumentListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::ExternStatementContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}


size_t qasm3Parser::ExternStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleExternStatement;
}


antlrcpp::Any qasm3Parser::ExternStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternStatementContext* qasm3Parser::externStatement() {
  ExternStatementContext *_localctx = _tracker.createInstance<ExternStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, qasm3Parser::RuleExternStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    match(qasm3Parser::EXTERN);
    setState(384);
    match(qasm3Parser::Identifier);
    setState(385);
    match(qasm3Parser::LPAREN);
    setState(387);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::READONLY)
      | (1ULL << qasm3Parser::MUTABLE)
      | (1ULL << qasm3Parser::CREG)
      | (1ULL << qasm3Parser::BOOL)
      | (1ULL << qasm3Parser::BIT)
      | (1ULL << qasm3Parser::INT)
      | (1ULL << qasm3Parser::UINT)
      | (1ULL << qasm3Parser::FLOAT)
      | (1ULL << qasm3Parser::ANGLE)
      | (1ULL << qasm3Parser::COMPLEX)
      | (1ULL << qasm3Parser::DURATION)
      | (1ULL << qasm3Parser::STRETCH))) != 0)) {
      setState(386);
      externArgumentList();
    }
    setState(389);
    match(qasm3Parser::RPAREN);
    setState(391);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(390);
      returnSignature();
    }
    setState(393);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateStatementContext ------------------------------------------------------------------

qasm3Parser::GateStatementContext::GateStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::GateStatementContext::GATE() {
  return getToken(qasm3Parser::GATE, 0);
}

tree::TerminalNode* qasm3Parser::GateStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::GateStatementContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

std::vector<qasm3Parser::IdentifierListContext *> qasm3Parser::GateStatementContext::identifierList() {
  return getRuleContexts<qasm3Parser::IdentifierListContext>();
}

qasm3Parser::IdentifierListContext* qasm3Parser::GateStatementContext::identifierList(size_t i) {
  return getRuleContext<qasm3Parser::IdentifierListContext>(i);
}

tree::TerminalNode* qasm3Parser::GateStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::GateStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::GateStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleGateStatement;
}


antlrcpp::Any qasm3Parser::GateStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateStatementContext* qasm3Parser::gateStatement() {
  GateStatementContext *_localctx = _tracker.createInstance<GateStatementContext>(_ctx, getState());
  enterRule(_localctx, 60, qasm3Parser::RuleGateStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(qasm3Parser::GATE);
    setState(396);
    match(qasm3Parser::Identifier);
    setState(402);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(397);
      match(qasm3Parser::LPAREN);
      setState(399);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier) {
        setState(398);
        dynamic_cast<GateStatementContext *>(_localctx)->params = identifierList();
      }
      setState(401);
      match(qasm3Parser::RPAREN);
    }
    setState(404);
    dynamic_cast<GateStatementContext *>(_localctx)->qubits = identifierList();
    setState(405);
    scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

qasm3Parser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::AssignmentStatementContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::CompoundAssignmentOperator() {
  return getToken(qasm3Parser::CompoundAssignmentOperator, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::AssignmentStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::AssignmentStatementContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}


size_t qasm3Parser::AssignmentStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAssignmentStatement;
}


antlrcpp::Any qasm3Parser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, qasm3Parser::RuleAssignmentStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    indexedIdentifier();
    setState(408);
    dynamic_cast<AssignmentStatementContext *>(_localctx)->op = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::EQUALS

    || _la == qasm3Parser::CompoundAssignmentOperator)) {
      dynamic_cast<AssignmentStatementContext *>(_localctx)->op = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(411);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(409);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        setState(410);
        measureExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(413);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

qasm3Parser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::ExpressionStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionStatement;
}


antlrcpp::Any qasm3Parser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, qasm3Parser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    expression(0);
    setState(416);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalStatementContext ------------------------------------------------------------------

qasm3Parser::CalStatementContext::CalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalStatementContext::CAL() {
  return getToken(qasm3Parser::CAL, 0);
}

tree::TerminalNode* qasm3Parser::CalStatementContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalStatementContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalStatementContext::CalibrationBlock() {
  return getToken(qasm3Parser::CalibrationBlock, 0);
}


size_t qasm3Parser::CalStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleCalStatement;
}


antlrcpp::Any qasm3Parser::CalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalStatementContext* qasm3Parser::calStatement() {
  CalStatementContext *_localctx = _tracker.createInstance<CalStatementContext>(_ctx, getState());
  enterRule(_localctx, 66, qasm3Parser::RuleCalStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(qasm3Parser::CAL);
    setState(419);
    match(qasm3Parser::LBRACE);
    setState(421);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::CalibrationBlock) {
      setState(420);
      match(qasm3Parser::CalibrationBlock);
    }
    setState(423);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalStatementContext ------------------------------------------------------------------

qasm3Parser::DefcalStatementContext::DefcalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::DEFCAL() {
  return getToken(qasm3Parser::DEFCAL, 0);
}

qasm3Parser::DefcalTargetContext* qasm3Parser::DefcalStatementContext::defcalTarget() {
  return getRuleContext<qasm3Parser::DefcalTargetContext>(0);
}

qasm3Parser::DefcalOperandListContext* qasm3Parser::DefcalStatementContext::defcalOperandList() {
  return getRuleContext<qasm3Parser::DefcalOperandListContext>(0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::DefcalStatementContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}

tree::TerminalNode* qasm3Parser::DefcalStatementContext::CalibrationBlock() {
  return getToken(qasm3Parser::CalibrationBlock, 0);
}

qasm3Parser::DefcalArgumentDefinitionListContext* qasm3Parser::DefcalStatementContext::defcalArgumentDefinitionList() {
  return getRuleContext<qasm3Parser::DefcalArgumentDefinitionListContext>(0);
}


size_t qasm3Parser::DefcalStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalStatement;
}


antlrcpp::Any qasm3Parser::DefcalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalStatementContext* qasm3Parser::defcalStatement() {
  DefcalStatementContext *_localctx = _tracker.createInstance<DefcalStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, qasm3Parser::RuleDefcalStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    match(qasm3Parser::DEFCAL);
    setState(426);
    defcalTarget();
    setState(432);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(427);
      match(qasm3Parser::LPAREN);
      setState(429);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::READONLY)
        | (1ULL << qasm3Parser::MUTABLE)
        | (1ULL << qasm3Parser::QREG)
        | (1ULL << qasm3Parser::QUBIT)
        | (1ULL << qasm3Parser::CREG)
        | (1ULL << qasm3Parser::BOOL)
        | (1ULL << qasm3Parser::BIT)
        | (1ULL << qasm3Parser::INT)
        | (1ULL << qasm3Parser::UINT)
        | (1ULL << qasm3Parser::FLOAT)
        | (1ULL << qasm3Parser::ANGLE)
        | (1ULL << qasm3Parser::COMPLEX)
        | (1ULL << qasm3Parser::ARRAY)
        | (1ULL << qasm3Parser::DURATION)
        | (1ULL << qasm3Parser::STRETCH)
        | (1ULL << qasm3Parser::DURATIONOF)
        | (1ULL << qasm3Parser::BooleanLiteral)
        | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (qasm3Parser::MINUS - 66))
        | (1ULL << (qasm3Parser::TILDE - 66))
        | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 66))
        | (1ULL << (qasm3Parser::ImaginaryLiteral - 66))
        | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 66))
        | (1ULL << (qasm3Parser::OctalIntegerLiteral - 66))
        | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 66))
        | (1ULL << (qasm3Parser::HexIntegerLiteral - 66))
        | (1ULL << (qasm3Parser::Identifier - 66))
        | (1ULL << (qasm3Parser::HardwareQubit - 66))
        | (1ULL << (qasm3Parser::FloatLiteral - 66))
        | (1ULL << (qasm3Parser::TimingLiteral - 66))
        | (1ULL << (qasm3Parser::BitstringLiteral - 66)))) != 0)) {
        setState(428);
        defcalArgumentDefinitionList();
      }
      setState(431);
      match(qasm3Parser::RPAREN);
    }
    setState(434);
    defcalOperandList();
    setState(436);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(435);
      returnSignature();
    }
    setState(438);
    match(qasm3Parser::LBRACE);
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::CalibrationBlock) {
      setState(439);
      match(qasm3Parser::CalibrationBlock);
    }
    setState(442);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::ExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleExpression;
}

void qasm3Parser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitwiseXorExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitwiseXorExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitwiseXorExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitwiseXorExpressionContext::CARET() {
  return getToken(qasm3Parser::CARET, 0);
}

qasm3Parser::BitwiseXorExpressionContext::BitwiseXorExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::BitwiseXorExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitwiseXorExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::AdditiveExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::AdditiveExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::PLUS() {
  return getToken(qasm3Parser::PLUS, 0);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}

qasm3Parser::AdditiveExpressionContext::AdditiveExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DurationofExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::DurationofExpressionContext::DURATIONOF() {
  return getToken(qasm3Parser::DURATIONOF, 0);
}

tree::TerminalNode* qasm3Parser::DurationofExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ScopeContext* qasm3Parser::DurationofExpressionContext::scope() {
  return getRuleContext<qasm3Parser::ScopeContext>(0);
}

tree::TerminalNode* qasm3Parser::DurationofExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::DurationofExpressionContext::DurationofExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::DurationofExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDurationofExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::ParenthesisExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ParenthesisExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ParenthesisExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ParenthesisExpressionContext::ParenthesisExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::ParenthesisExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitParenthesisExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ComparisonExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ComparisonExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::ComparisonExpressionContext::ComparisonOperator() {
  return getToken(qasm3Parser::ComparisonOperator, 0);
}

qasm3Parser::ComparisonExpressionContext::ComparisonExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::MultiplicativeExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::MultiplicativeExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::ASTERISK() {
  return getToken(qasm3Parser::ASTERISK, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::SLASH() {
  return getToken(qasm3Parser::SLASH, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::PERCENT() {
  return getToken(qasm3Parser::PERCENT, 0);
}

qasm3Parser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::LogicalOrExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::LogicalOrExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::LogicalOrExpressionContext::DOUBLE_PIPE() {
  return getToken(qasm3Parser::DOUBLE_PIPE, 0);
}

qasm3Parser::LogicalOrExpressionContext::LogicalOrExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CastExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::CastExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::CastExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::CastExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::CastExpressionContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::CastExpressionContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}

qasm3Parser::CastExpressionContext::CastExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::CastExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCastExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::PowerExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::PowerExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::PowerExpressionContext::DOUBLE_ASTERISK() {
  return getToken(qasm3Parser::DOUBLE_ASTERISK, 0);
}

qasm3Parser::PowerExpressionContext::PowerExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseOrExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitwiseOrExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitwiseOrExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitwiseOrExpressionContext::PIPE() {
  return getToken(qasm3Parser::PIPE, 0);
}

qasm3Parser::BitwiseOrExpressionContext::BitwiseOrExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::BitwiseOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitwiseOrExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::CallExpressionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::CallExpressionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::CallExpressionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::CallExpressionContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

qasm3Parser::CallExpressionContext::CallExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::CallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCallExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitshiftExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitshiftExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitshiftExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitshiftExpressionContext::BitshiftOperator() {
  return getToken(qasm3Parser::BitshiftOperator, 0);
}

qasm3Parser::BitshiftExpressionContext::BitshiftExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::BitshiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitshiftExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitwiseAndExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::BitwiseAndExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::BitwiseAndExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::BitwiseAndExpressionContext::AMPERSAND() {
  return getToken(qasm3Parser::AMPERSAND, 0);
}

qasm3Parser::BitwiseAndExpressionContext::BitwiseAndExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::BitwiseAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitwiseAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::EqualityExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::EqualityExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::EqualityExpressionContext::EqualityOperator() {
  return getToken(qasm3Parser::EqualityOperator, 0);
}

qasm3Parser::EqualityExpressionContext::EqualityExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::LogicalAndExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::LogicalAndExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::LogicalAndExpressionContext::DOUBLE_AMPERSAND() {
  return getToken(qasm3Parser::DOUBLE_AMPERSAND, 0);
}

qasm3Parser::LogicalAndExpressionContext::LogicalAndExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext* qasm3Parser::IndexExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::IndexOperatorContext* qasm3Parser::IndexExpressionContext::indexOperator() {
  return getRuleContext<qasm3Parser::IndexOperatorContext>(0);
}

qasm3Parser::IndexExpressionContext::IndexExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::IndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExpressionContext ------------------------------------------------------------------

qasm3Parser::ExpressionContext* qasm3Parser::UnaryExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::UnaryExpressionContext::TILDE() {
  return getToken(qasm3Parser::TILDE, 0);
}

tree::TerminalNode* qasm3Parser::UnaryExpressionContext::EXCLAMATION_POINT() {
  return getToken(qasm3Parser::EXCLAMATION_POINT, 0);
}

tree::TerminalNode* qasm3Parser::UnaryExpressionContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}

qasm3Parser::UnaryExpressionContext::UnaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralExpressionContext ------------------------------------------------------------------

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::BinaryIntegerLiteral() {
  return getToken(qasm3Parser::BinaryIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::OctalIntegerLiteral() {
  return getToken(qasm3Parser::OctalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::DecimalIntegerLiteral() {
  return getToken(qasm3Parser::DecimalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::HexIntegerLiteral() {
  return getToken(qasm3Parser::HexIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::FloatLiteral() {
  return getToken(qasm3Parser::FloatLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::ImaginaryLiteral() {
  return getToken(qasm3Parser::ImaginaryLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::BooleanLiteral() {
  return getToken(qasm3Parser::BooleanLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::BitstringLiteral() {
  return getToken(qasm3Parser::BitstringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::TimingLiteral() {
  return getToken(qasm3Parser::TimingLiteral, 0);
}

tree::TerminalNode* qasm3Parser::LiteralExpressionContext::HardwareQubit() {
  return getToken(qasm3Parser::HardwareQubit, 0);
}

qasm3Parser::LiteralExpressionContext::LiteralExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any qasm3Parser::LiteralExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionContext* qasm3Parser::expression() {
   return expression(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  qasm3Parser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, qasm3Parser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(471);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(445);
      match(qasm3Parser::LPAREN);
      setState(446);
      expression(0);
      setState(447);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(449);
      dynamic_cast<UnaryExpressionContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & ((1ULL << (qasm3Parser::MINUS - 66))
        | (1ULL << (qasm3Parser::TILDE - 66))
        | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 66)))) != 0))) {
        dynamic_cast<UnaryExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(450);
      expression(15);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CastExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(453);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::BOOL:
        case qasm3Parser::BIT:
        case qasm3Parser::INT:
        case qasm3Parser::UINT:
        case qasm3Parser::FLOAT:
        case qasm3Parser::ANGLE:
        case qasm3Parser::COMPLEX:
        case qasm3Parser::DURATION:
        case qasm3Parser::STRETCH: {
          setState(451);
          scalarType();
          break;
        }

        case qasm3Parser::ARRAY: {
          setState(452);
          arrayType();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(455);
      match(qasm3Parser::LPAREN);
      setState(456);
      expression(0);
      setState(457);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<DurationofExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(459);
      match(qasm3Parser::DURATIONOF);
      setState(460);
      match(qasm3Parser::LPAREN);
      setState(461);
      scope();
      setState(462);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CallExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(464);
      match(qasm3Parser::Identifier);
      setState(465);
      match(qasm3Parser::LPAREN);
      setState(467);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 30) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 30)) & ((1ULL << (qasm3Parser::BOOL - 30))
        | (1ULL << (qasm3Parser::BIT - 30))
        | (1ULL << (qasm3Parser::INT - 30))
        | (1ULL << (qasm3Parser::UINT - 30))
        | (1ULL << (qasm3Parser::FLOAT - 30))
        | (1ULL << (qasm3Parser::ANGLE - 30))
        | (1ULL << (qasm3Parser::COMPLEX - 30))
        | (1ULL << (qasm3Parser::ARRAY - 30))
        | (1ULL << (qasm3Parser::DURATION - 30))
        | (1ULL << (qasm3Parser::STRETCH - 30))
        | (1ULL << (qasm3Parser::DURATIONOF - 30))
        | (1ULL << (qasm3Parser::BooleanLiteral - 30))
        | (1ULL << (qasm3Parser::LPAREN - 30))
        | (1ULL << (qasm3Parser::MINUS - 30))
        | (1ULL << (qasm3Parser::TILDE - 30))
        | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 30))
        | (1ULL << (qasm3Parser::ImaginaryLiteral - 30))
        | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 30))
        | (1ULL << (qasm3Parser::OctalIntegerLiteral - 30))
        | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 30))
        | (1ULL << (qasm3Parser::HexIntegerLiteral - 30))
        | (1ULL << (qasm3Parser::Identifier - 30))
        | (1ULL << (qasm3Parser::HardwareQubit - 30))
        | (1ULL << (qasm3Parser::FloatLiteral - 30))
        | (1ULL << (qasm3Parser::TimingLiteral - 30))
        | (1ULL << (qasm3Parser::BitstringLiteral - 30)))) != 0)) {
        setState(466);
        expressionList();
      }
      setState(469);
      match(qasm3Parser::RPAREN);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<LiteralExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(470);
      _la = _input->LA(1);
      if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 51)) & ((1ULL << (qasm3Parser::BooleanLiteral - 51))
        | (1ULL << (qasm3Parser::ImaginaryLiteral - 51))
        | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 51))
        | (1ULL << (qasm3Parser::OctalIntegerLiteral - 51))
        | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 51))
        | (1ULL << (qasm3Parser::HexIntegerLiteral - 51))
        | (1ULL << (qasm3Parser::Identifier - 51))
        | (1ULL << (qasm3Parser::HardwareQubit - 51))
        | (1ULL << (qasm3Parser::FloatLiteral - 51))
        | (1ULL << (qasm3Parser::TimingLiteral - 51))
        | (1ULL << (qasm3Parser::BitstringLiteral - 51)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(510);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(508);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(473);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(474);
          dynamic_cast<PowerExpressionContext *>(_localctx)->op = match(qasm3Parser::DOUBLE_ASTERISK);
          setState(475);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MultiplicativeExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(476);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(477);
          dynamic_cast<MultiplicativeExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::ASTERISK - 67))
            | (1ULL << (qasm3Parser::SLASH - 67))
            | (1ULL << (qasm3Parser::PERCENT - 67)))) != 0))) {
            dynamic_cast<MultiplicativeExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(478);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AdditiveExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(479);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(480);
          dynamic_cast<AdditiveExpressionContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == qasm3Parser::PLUS

          || _la == qasm3Parser::MINUS)) {
            dynamic_cast<AdditiveExpressionContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(481);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BitshiftExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(482);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(483);
          dynamic_cast<BitshiftExpressionContext *>(_localctx)->op = match(qasm3Parser::BitshiftOperator);
          setState(484);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ComparisonExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(485);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(486);
          dynamic_cast<ComparisonExpressionContext *>(_localctx)->op = match(qasm3Parser::ComparisonOperator);
          setState(487);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<EqualityExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(488);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(489);
          dynamic_cast<EqualityExpressionContext *>(_localctx)->op = match(qasm3Parser::EqualityOperator);
          setState(490);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitwiseAndExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(491);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(492);
          dynamic_cast<BitwiseAndExpressionContext *>(_localctx)->op = match(qasm3Parser::AMPERSAND);
          setState(493);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitwiseXorExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(494);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(495);
          dynamic_cast<BitwiseXorExpressionContext *>(_localctx)->op = match(qasm3Parser::CARET);
          setState(496);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BitwiseOrExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(497);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(498);
          dynamic_cast<BitwiseOrExpressionContext *>(_localctx)->op = match(qasm3Parser::PIPE);
          setState(499);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicalAndExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(500);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(501);
          dynamic_cast<LogicalAndExpressionContext *>(_localctx)->op = match(qasm3Parser::DOUBLE_AMPERSAND);
          setState(502);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<LogicalOrExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(503);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(504);
          dynamic_cast<LogicalOrExpressionContext *>(_localctx)->op = match(qasm3Parser::DOUBLE_PIPE);
          setState(505);
          expression(6);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<IndexExpressionContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(506);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(507);
          indexOperator();
          break;
        }

        default:
          break;
        } 
      }
      setState(512);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AliasExpressionContext ------------------------------------------------------------------

qasm3Parser::AliasExpressionContext::AliasExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::AliasExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::AliasExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::AliasExpressionContext::DOUBLE_PLUS() {
  return getTokens(qasm3Parser::DOUBLE_PLUS);
}

tree::TerminalNode* qasm3Parser::AliasExpressionContext::DOUBLE_PLUS(size_t i) {
  return getToken(qasm3Parser::DOUBLE_PLUS, i);
}


size_t qasm3Parser::AliasExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasExpression;
}


antlrcpp::Any qasm3Parser::AliasExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAliasExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasExpressionContext* qasm3Parser::aliasExpression() {
  AliasExpressionContext *_localctx = _tracker.createInstance<AliasExpressionContext>(_ctx, getState());
  enterRule(_localctx, 72, qasm3Parser::RuleAliasExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    expression(0);
    setState(518);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::DOUBLE_PLUS) {
      setState(514);
      match(qasm3Parser::DOUBLE_PLUS);
      setState(515);
      expression(0);
      setState(520);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationExpressionContext ------------------------------------------------------------------

qasm3Parser::DeclarationExpressionContext::DeclarationExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ArrayLiteralContext* qasm3Parser::DeclarationExpressionContext::arrayLiteral() {
  return getRuleContext<qasm3Parser::ArrayLiteralContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::DeclarationExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::DeclarationExpressionContext::measureExpression() {
  return getRuleContext<qasm3Parser::MeasureExpressionContext>(0);
}


size_t qasm3Parser::DeclarationExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleDeclarationExpression;
}


antlrcpp::Any qasm3Parser::DeclarationExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDeclarationExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DeclarationExpressionContext* qasm3Parser::declarationExpression() {
  DeclarationExpressionContext *_localctx = _tracker.createInstance<DeclarationExpressionContext>(_ctx, getState());
  enterRule(_localctx, 74, qasm3Parser::RuleDeclarationExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(524);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(521);
        arrayLiteral();
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(522);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        enterOuterAlt(_localctx, 3);
        setState(523);
        measureExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasureExpressionContext ------------------------------------------------------------------

qasm3Parser::MeasureExpressionContext::MeasureExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::MeasureExpressionContext::MEASURE() {
  return getToken(qasm3Parser::MEASURE, 0);
}

qasm3Parser::GateOperandContext* qasm3Parser::MeasureExpressionContext::gateOperand() {
  return getRuleContext<qasm3Parser::GateOperandContext>(0);
}


size_t qasm3Parser::MeasureExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleMeasureExpression;
}


antlrcpp::Any qasm3Parser::MeasureExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMeasureExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::MeasureExpressionContext* qasm3Parser::measureExpression() {
  MeasureExpressionContext *_localctx = _tracker.createInstance<MeasureExpressionContext>(_ctx, getState());
  enterRule(_localctx, 76, qasm3Parser::RuleMeasureExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    match(qasm3Parser::MEASURE);
    setState(527);
    gateOperand();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeExpressionContext ------------------------------------------------------------------

qasm3Parser::RangeExpressionContext::RangeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::RangeExpressionContext::COLON() {
  return getTokens(qasm3Parser::COLON);
}

tree::TerminalNode* qasm3Parser::RangeExpressionContext::COLON(size_t i) {
  return getToken(qasm3Parser::COLON, i);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::RangeExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::RangeExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}


size_t qasm3Parser::RangeExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleRangeExpression;
}


antlrcpp::Any qasm3Parser::RangeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitRangeExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::RangeExpressionContext* qasm3Parser::rangeExpression() {
  RangeExpressionContext *_localctx = _tracker.createInstance<RangeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 78, qasm3Parser::RuleRangeExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(530);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 30) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 30)) & ((1ULL << (qasm3Parser::BOOL - 30))
      | (1ULL << (qasm3Parser::BIT - 30))
      | (1ULL << (qasm3Parser::INT - 30))
      | (1ULL << (qasm3Parser::UINT - 30))
      | (1ULL << (qasm3Parser::FLOAT - 30))
      | (1ULL << (qasm3Parser::ANGLE - 30))
      | (1ULL << (qasm3Parser::COMPLEX - 30))
      | (1ULL << (qasm3Parser::ARRAY - 30))
      | (1ULL << (qasm3Parser::DURATION - 30))
      | (1ULL << (qasm3Parser::STRETCH - 30))
      | (1ULL << (qasm3Parser::DURATIONOF - 30))
      | (1ULL << (qasm3Parser::BooleanLiteral - 30))
      | (1ULL << (qasm3Parser::LPAREN - 30))
      | (1ULL << (qasm3Parser::MINUS - 30))
      | (1ULL << (qasm3Parser::TILDE - 30))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 30))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 30))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::Identifier - 30))
      | (1ULL << (qasm3Parser::HardwareQubit - 30))
      | (1ULL << (qasm3Parser::FloatLiteral - 30))
      | (1ULL << (qasm3Parser::TimingLiteral - 30))
      | (1ULL << (qasm3Parser::BitstringLiteral - 30)))) != 0)) {
      setState(529);
      expression(0);
    }
    setState(532);
    match(qasm3Parser::COLON);
    setState(534);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 30) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 30)) & ((1ULL << (qasm3Parser::BOOL - 30))
      | (1ULL << (qasm3Parser::BIT - 30))
      | (1ULL << (qasm3Parser::INT - 30))
      | (1ULL << (qasm3Parser::UINT - 30))
      | (1ULL << (qasm3Parser::FLOAT - 30))
      | (1ULL << (qasm3Parser::ANGLE - 30))
      | (1ULL << (qasm3Parser::COMPLEX - 30))
      | (1ULL << (qasm3Parser::ARRAY - 30))
      | (1ULL << (qasm3Parser::DURATION - 30))
      | (1ULL << (qasm3Parser::STRETCH - 30))
      | (1ULL << (qasm3Parser::DURATIONOF - 30))
      | (1ULL << (qasm3Parser::BooleanLiteral - 30))
      | (1ULL << (qasm3Parser::LPAREN - 30))
      | (1ULL << (qasm3Parser::MINUS - 30))
      | (1ULL << (qasm3Parser::TILDE - 30))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 30))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 30))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 30))
      | (1ULL << (qasm3Parser::Identifier - 30))
      | (1ULL << (qasm3Parser::HardwareQubit - 30))
      | (1ULL << (qasm3Parser::FloatLiteral - 30))
      | (1ULL << (qasm3Parser::TimingLiteral - 30))
      | (1ULL << (qasm3Parser::BitstringLiteral - 30)))) != 0)) {
      setState(533);
      expression(0);
    }
    setState(538);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COLON) {
      setState(536);
      match(qasm3Parser::COLON);
      setState(537);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetExpressionContext ------------------------------------------------------------------

qasm3Parser::SetExpressionContext::SetExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SetExpressionContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::SetExpressionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::SetExpressionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::SetExpressionContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::SetExpressionContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::SetExpressionContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::SetExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleSetExpression;
}


antlrcpp::Any qasm3Parser::SetExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSetExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SetExpressionContext* qasm3Parser::setExpression() {
  SetExpressionContext *_localctx = _tracker.createInstance<SetExpressionContext>(_ctx, getState());
  enterRule(_localctx, 80, qasm3Parser::RuleSetExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(540);
    match(qasm3Parser::LBRACE);
    setState(541);
    expression(0);
    setState(546);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(542);
        match(qasm3Parser::COMMA);
        setState(543);
        expression(0); 
      }
      setState(548);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    }
    setState(550);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(549);
      match(qasm3Parser::COMMA);
    }
    setState(552);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLiteralContext ------------------------------------------------------------------

qasm3Parser::ArrayLiteralContext::ArrayLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayLiteralContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ArrayLiteralContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ArrayLiteralContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayLiteralContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<qasm3Parser::ArrayLiteralContext *> qasm3Parser::ArrayLiteralContext::arrayLiteral() {
  return getRuleContexts<qasm3Parser::ArrayLiteralContext>();
}

qasm3Parser::ArrayLiteralContext* qasm3Parser::ArrayLiteralContext::arrayLiteral(size_t i) {
  return getRuleContext<qasm3Parser::ArrayLiteralContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ArrayLiteralContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ArrayLiteralContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ArrayLiteralContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayLiteral;
}


antlrcpp::Any qasm3Parser::ArrayLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayLiteral(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayLiteralContext* qasm3Parser::arrayLiteral() {
  ArrayLiteralContext *_localctx = _tracker.createInstance<ArrayLiteralContext>(_ctx, getState());
  enterRule(_localctx, 82, qasm3Parser::RuleArrayLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(554);
    match(qasm3Parser::LBRACE);
    setState(557);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(555);
        expression(0);
        break;
      }

      case qasm3Parser::LBRACE: {
        setState(556);
        arrayLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(566);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(559);
        match(qasm3Parser::COMMA);
        setState(562);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::BOOL:
          case qasm3Parser::BIT:
          case qasm3Parser::INT:
          case qasm3Parser::UINT:
          case qasm3Parser::FLOAT:
          case qasm3Parser::ANGLE:
          case qasm3Parser::COMPLEX:
          case qasm3Parser::ARRAY:
          case qasm3Parser::DURATION:
          case qasm3Parser::STRETCH:
          case qasm3Parser::DURATIONOF:
          case qasm3Parser::BooleanLiteral:
          case qasm3Parser::LPAREN:
          case qasm3Parser::MINUS:
          case qasm3Parser::TILDE:
          case qasm3Parser::EXCLAMATION_POINT:
          case qasm3Parser::ImaginaryLiteral:
          case qasm3Parser::BinaryIntegerLiteral:
          case qasm3Parser::OctalIntegerLiteral:
          case qasm3Parser::DecimalIntegerLiteral:
          case qasm3Parser::HexIntegerLiteral:
          case qasm3Parser::Identifier:
          case qasm3Parser::HardwareQubit:
          case qasm3Parser::FloatLiteral:
          case qasm3Parser::TimingLiteral:
          case qasm3Parser::BitstringLiteral: {
            setState(560);
            expression(0);
            break;
          }

          case qasm3Parser::LBRACE: {
            setState(561);
            arrayLiteral();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(568);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(569);
      match(qasm3Parser::COMMA);
    }
    setState(572);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexOperatorContext ------------------------------------------------------------------

qasm3Parser::IndexOperatorContext::IndexOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IndexOperatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::IndexOperatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

qasm3Parser::SetExpressionContext* qasm3Parser::IndexOperatorContext::setExpression() {
  return getRuleContext<qasm3Parser::SetExpressionContext>(0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::IndexOperatorContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::IndexOperatorContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<qasm3Parser::RangeExpressionContext *> qasm3Parser::IndexOperatorContext::rangeExpression() {
  return getRuleContexts<qasm3Parser::RangeExpressionContext>();
}

qasm3Parser::RangeExpressionContext* qasm3Parser::IndexOperatorContext::rangeExpression(size_t i) {
  return getRuleContext<qasm3Parser::RangeExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IndexOperatorContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IndexOperatorContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IndexOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexOperator;
}


antlrcpp::Any qasm3Parser::IndexOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexOperatorContext* qasm3Parser::indexOperator() {
  IndexOperatorContext *_localctx = _tracker.createInstance<IndexOperatorContext>(_ctx, getState());
  enterRule(_localctx, 84, qasm3Parser::RuleIndexOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(574);
    match(qasm3Parser::LBRACKET);
    setState(593);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        setState(575);
        setExpression();
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::COLON:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(578);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
        case 1: {
          setState(576);
          expression(0);
          break;
        }

        case 2: {
          setState(577);
          rangeExpression();
          break;
        }

        default:
          break;
        }
        setState(587);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(580);
            match(qasm3Parser::COMMA);
            setState(583);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
            case 1: {
              setState(581);
              expression(0);
              break;
            }

            case 2: {
              setState(582);
              rangeExpression();
              break;
            }

            default:
              break;
            } 
          }
          setState(589);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
        }
        setState(591);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::COMMA) {
          setState(590);
          match(qasm3Parser::COMMA);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(595);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexedIdentifierContext ------------------------------------------------------------------

qasm3Parser::IndexedIdentifierContext::IndexedIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IndexedIdentifierContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

std::vector<qasm3Parser::IndexOperatorContext *> qasm3Parser::IndexedIdentifierContext::indexOperator() {
  return getRuleContexts<qasm3Parser::IndexOperatorContext>();
}

qasm3Parser::IndexOperatorContext* qasm3Parser::IndexedIdentifierContext::indexOperator(size_t i) {
  return getRuleContext<qasm3Parser::IndexOperatorContext>(i);
}


size_t qasm3Parser::IndexedIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexedIdentifier;
}


antlrcpp::Any qasm3Parser::IndexedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexedIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::indexedIdentifier() {
  IndexedIdentifierContext *_localctx = _tracker.createInstance<IndexedIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 86, qasm3Parser::RuleIndexedIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(597);
    match(qasm3Parser::Identifier);
    setState(601);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::LBRACKET) {
      setState(598);
      indexOperator();
      setState(603);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnSignatureContext ------------------------------------------------------------------

qasm3Parser::ReturnSignatureContext::ReturnSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ReturnSignatureContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ReturnSignatureContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}


size_t qasm3Parser::ReturnSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleReturnSignature;
}


antlrcpp::Any qasm3Parser::ReturnSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitReturnSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::returnSignature() {
  ReturnSignatureContext *_localctx = _tracker.createInstance<ReturnSignatureContext>(_ctx, getState());
  enterRule(_localctx, 88, qasm3Parser::RuleReturnSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    match(qasm3Parser::ARROW);
    setState(605);
    scalarType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateModifierContext ------------------------------------------------------------------

qasm3Parser::GateModifierContext::GateModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::GateModifierContext::AT() {
  return getToken(qasm3Parser::AT, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::INV() {
  return getToken(qasm3Parser::INV, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::POW() {
  return getToken(qasm3Parser::POW, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::GateModifierContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::CTRL() {
  return getToken(qasm3Parser::CTRL, 0);
}

tree::TerminalNode* qasm3Parser::GateModifierContext::NEGCTRL() {
  return getToken(qasm3Parser::NEGCTRL, 0);
}


size_t qasm3Parser::GateModifierContext::getRuleIndex() const {
  return qasm3Parser::RuleGateModifier;
}


antlrcpp::Any qasm3Parser::GateModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateModifierContext* qasm3Parser::gateModifier() {
  GateModifierContext *_localctx = _tracker.createInstance<GateModifierContext>(_ctx, getState());
  enterRule(_localctx, 90, qasm3Parser::RuleGateModifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(620);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INV: {
        setState(607);
        match(qasm3Parser::INV);
        break;
      }

      case qasm3Parser::POW: {
        setState(608);
        match(qasm3Parser::POW);
        setState(609);
        match(qasm3Parser::LPAREN);
        setState(610);
        expression(0);
        setState(611);
        match(qasm3Parser::RPAREN);
        break;
      }

      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL: {
        setState(613);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::CTRL

        || _la == qasm3Parser::NEGCTRL)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(618);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LPAREN) {
          setState(614);
          match(qasm3Parser::LPAREN);
          setState(615);
          expression(0);
          setState(616);
          match(qasm3Parser::RPAREN);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(622);
    match(qasm3Parser::AT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarTypeContext ------------------------------------------------------------------

qasm3Parser::ScalarTypeContext::ScalarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::BIT() {
  return getToken(qasm3Parser::BIT, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ScalarTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::INT() {
  return getToken(qasm3Parser::INT, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::UINT() {
  return getToken(qasm3Parser::UINT, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::FLOAT() {
  return getToken(qasm3Parser::FLOAT, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::ANGLE() {
  return getToken(qasm3Parser::ANGLE, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::BOOL() {
  return getToken(qasm3Parser::BOOL, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::DURATION() {
  return getToken(qasm3Parser::DURATION, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::STRETCH() {
  return getToken(qasm3Parser::STRETCH, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::COMPLEX() {
  return getToken(qasm3Parser::COMPLEX, 0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ScalarTypeContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ScalarTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ScalarTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleScalarType;
}


antlrcpp::Any qasm3Parser::ScalarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitScalarType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::scalarType() {
  ScalarTypeContext *_localctx = _tracker.createInstance<ScalarTypeContext>(_ctx, getState());
  enterRule(_localctx, 92, qasm3Parser::RuleScalarType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(654);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BIT: {
        enterOuterAlt(_localctx, 1);
        setState(624);
        match(qasm3Parser::BIT);
        setState(626);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(625);
          designator();
        }
        break;
      }

      case qasm3Parser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(628);
        match(qasm3Parser::INT);
        setState(630);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(629);
          designator();
        }
        break;
      }

      case qasm3Parser::UINT: {
        enterOuterAlt(_localctx, 3);
        setState(632);
        match(qasm3Parser::UINT);
        setState(634);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(633);
          designator();
        }
        break;
      }

      case qasm3Parser::FLOAT: {
        enterOuterAlt(_localctx, 4);
        setState(636);
        match(qasm3Parser::FLOAT);
        setState(638);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(637);
          designator();
        }
        break;
      }

      case qasm3Parser::ANGLE: {
        enterOuterAlt(_localctx, 5);
        setState(640);
        match(qasm3Parser::ANGLE);
        setState(642);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(641);
          designator();
        }
        break;
      }

      case qasm3Parser::BOOL: {
        enterOuterAlt(_localctx, 6);
        setState(644);
        match(qasm3Parser::BOOL);
        break;
      }

      case qasm3Parser::DURATION: {
        enterOuterAlt(_localctx, 7);
        setState(645);
        match(qasm3Parser::DURATION);
        break;
      }

      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 8);
        setState(646);
        match(qasm3Parser::STRETCH);
        break;
      }

      case qasm3Parser::COMPLEX: {
        enterOuterAlt(_localctx, 9);
        setState(647);
        match(qasm3Parser::COMPLEX);
        setState(652);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(648);
          match(qasm3Parser::LBRACKET);
          setState(649);
          scalarType();
          setState(650);
          match(qasm3Parser::RBRACKET);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QubitTypeContext ------------------------------------------------------------------

qasm3Parser::QubitTypeContext::QubitTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QubitTypeContext::QUBIT() {
  return getToken(qasm3Parser::QUBIT, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QubitTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::QubitTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleQubitType;
}


antlrcpp::Any qasm3Parser::QubitTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQubitType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QubitTypeContext* qasm3Parser::qubitType() {
  QubitTypeContext *_localctx = _tracker.createInstance<QubitTypeContext>(_ctx, getState());
  enterRule(_localctx, 94, qasm3Parser::RuleQubitType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(656);
    match(qasm3Parser::QUBIT);
    setState(658);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(657);
      designator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

qasm3Parser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::ARRAY() {
  return getToken(qasm3Parser::ARRAY, 0);
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ArrayTypeContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::COMMA() {
  return getToken(qasm3Parser::COMMA, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::ArrayTypeContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ArrayTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayType;
}


antlrcpp::Any qasm3Parser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 96, qasm3Parser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(660);
    match(qasm3Parser::ARRAY);
    setState(661);
    match(qasm3Parser::LBRACKET);
    setState(662);
    scalarType();
    setState(663);
    match(qasm3Parser::COMMA);
    setState(664);
    expressionList();
    setState(665);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayReferenceTypeContext ------------------------------------------------------------------

qasm3Parser::ArrayReferenceTypeContext::ArrayReferenceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::ARRAY() {
  return getToken(qasm3Parser::ARRAY, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ArrayReferenceTypeContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::COMMA() {
  return getToken(qasm3Parser::COMMA, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::READONLY() {
  return getToken(qasm3Parser::READONLY, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::MUTABLE() {
  return getToken(qasm3Parser::MUTABLE, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::ArrayReferenceTypeContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::DIM() {
  return getToken(qasm3Parser::DIM, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayReferenceTypeContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ArrayReferenceTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayReferenceType;
}


antlrcpp::Any qasm3Parser::ArrayReferenceTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayReferenceType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::arrayReferenceType() {
  ArrayReferenceTypeContext *_localctx = _tracker.createInstance<ArrayReferenceTypeContext>(_ctx, getState());
  enterRule(_localctx, 98, qasm3Parser::RuleArrayReferenceType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(667);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::READONLY

    || _la == qasm3Parser::MUTABLE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(668);
    match(qasm3Parser::ARRAY);
    setState(669);
    match(qasm3Parser::LBRACKET);
    setState(670);
    scalarType();
    setState(671);
    match(qasm3Parser::COMMA);
    setState(676);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::ARRAY:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::HardwareQubit:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(672);
        expressionList();
        break;
      }

      case qasm3Parser::DIM: {
        setState(673);
        match(qasm3Parser::DIM);
        setState(674);
        match(qasm3Parser::EQUALS);
        setState(675);
        expression(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(678);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

qasm3Parser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DesignatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::DesignatorContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::DesignatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::DesignatorContext::getRuleIndex() const {
  return qasm3Parser::RuleDesignator;
}


antlrcpp::Any qasm3Parser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DesignatorContext* qasm3Parser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 100, qasm3Parser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(680);
    match(qasm3Parser::LBRACKET);
    setState(681);
    expression(0);
    setState(682);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalTargetContext ------------------------------------------------------------------

qasm3Parser::DefcalTargetContext::DefcalTargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::MEASURE() {
  return getToken(qasm3Parser::MEASURE, 0);
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::RESET() {
  return getToken(qasm3Parser::RESET, 0);
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::DELAY() {
  return getToken(qasm3Parser::DELAY, 0);
}

tree::TerminalNode* qasm3Parser::DefcalTargetContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::DefcalTargetContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalTarget;
}


antlrcpp::Any qasm3Parser::DefcalTargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalTarget(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalTargetContext* qasm3Parser::defcalTarget() {
  DefcalTargetContext *_localctx = _tracker.createInstance<DefcalTargetContext>(_ctx, getState());
  enterRule(_localctx, 102, qasm3Parser::RuleDefcalTarget);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(684);
    _la = _input->LA(1);
    if (!(((((_la - 47) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 47)) & ((1ULL << (qasm3Parser::DELAY - 47))
      | (1ULL << (qasm3Parser::RESET - 47))
      | (1ULL << (qasm3Parser::MEASURE - 47))
      | (1ULL << (qasm3Parser::Identifier - 47)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalArgumentDefinitionContext ------------------------------------------------------------------

qasm3Parser::DefcalArgumentDefinitionContext::DefcalArgumentDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionContext* qasm3Parser::DefcalArgumentDefinitionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::ArgumentDefinitionContext* qasm3Parser::DefcalArgumentDefinitionContext::argumentDefinition() {
  return getRuleContext<qasm3Parser::ArgumentDefinitionContext>(0);
}


size_t qasm3Parser::DefcalArgumentDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalArgumentDefinition;
}


antlrcpp::Any qasm3Parser::DefcalArgumentDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalArgumentDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalArgumentDefinitionContext* qasm3Parser::defcalArgumentDefinition() {
  DefcalArgumentDefinitionContext *_localctx = _tracker.createInstance<DefcalArgumentDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 104, qasm3Parser::RuleDefcalArgumentDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(688);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(686);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(687);
      argumentDefinition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalOperandContext ------------------------------------------------------------------

qasm3Parser::DefcalOperandContext::DefcalOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DefcalOperandContext::HardwareQubit() {
  return getToken(qasm3Parser::HardwareQubit, 0);
}

tree::TerminalNode* qasm3Parser::DefcalOperandContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::DefcalOperandContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalOperand;
}


antlrcpp::Any qasm3Parser::DefcalOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalOperand(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalOperandContext* qasm3Parser::defcalOperand() {
  DefcalOperandContext *_localctx = _tracker.createInstance<DefcalOperandContext>(_ctx, getState());
  enterRule(_localctx, 106, qasm3Parser::RuleDefcalOperand);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(690);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::Identifier

    || _la == qasm3Parser::HardwareQubit)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateOperandContext ------------------------------------------------------------------

qasm3Parser::GateOperandContext::GateOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::GateOperandContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::GateOperandContext::HardwareQubit() {
  return getToken(qasm3Parser::HardwareQubit, 0);
}


size_t qasm3Parser::GateOperandContext::getRuleIndex() const {
  return qasm3Parser::RuleGateOperand;
}


antlrcpp::Any qasm3Parser::GateOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateOperand(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateOperandContext* qasm3Parser::gateOperand() {
  GateOperandContext *_localctx = _tracker.createInstance<GateOperandContext>(_ctx, getState());
  enterRule(_localctx, 108, qasm3Parser::RuleGateOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(694);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(692);
        indexedIdentifier();
        break;
      }

      case qasm3Parser::HardwareQubit: {
        enterOuterAlt(_localctx, 2);
        setState(693);
        match(qasm3Parser::HardwareQubit);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternArgumentContext ------------------------------------------------------------------

qasm3Parser::ExternArgumentContext::ExternArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ExternArgumentContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::ExternArgumentContext::arrayReferenceType() {
  return getRuleContext<qasm3Parser::ArrayReferenceTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ExternArgumentContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ExternArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::ExternArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleExternArgument;
}


antlrcpp::Any qasm3Parser::ExternArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternArgumentContext* qasm3Parser::externArgument() {
  ExternArgumentContext *_localctx = _tracker.createInstance<ExternArgumentContext>(_ctx, getState());
  enterRule(_localctx, 110, qasm3Parser::RuleExternArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(702);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 1);
        setState(696);
        scalarType();
        break;
      }

      case qasm3Parser::READONLY:
      case qasm3Parser::MUTABLE: {
        enterOuterAlt(_localctx, 2);
        setState(697);
        arrayReferenceType();
        break;
      }

      case qasm3Parser::CREG: {
        enterOuterAlt(_localctx, 3);
        setState(698);
        match(qasm3Parser::CREG);
        setState(700);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(699);
          designator();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentDefinitionContext ------------------------------------------------------------------

qasm3Parser::ArgumentDefinitionContext::ArgumentDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ScalarTypeContext* qasm3Parser::ArgumentDefinitionContext::scalarType() {
  return getRuleContext<qasm3Parser::ScalarTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::QubitTypeContext* qasm3Parser::ArgumentDefinitionContext::qubitType() {
  return getRuleContext<qasm3Parser::QubitTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionContext::QREG() {
  return getToken(qasm3Parser::QREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ArgumentDefinitionContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::ArgumentDefinitionContext::arrayReferenceType() {
  return getRuleContext<qasm3Parser::ArrayReferenceTypeContext>(0);
}


size_t qasm3Parser::ArgumentDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleArgumentDefinition;
}


antlrcpp::Any qasm3Parser::ArgumentDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArgumentDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArgumentDefinitionContext* qasm3Parser::argumentDefinition() {
  ArgumentDefinitionContext *_localctx = _tracker.createInstance<ArgumentDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 112, qasm3Parser::RuleArgumentDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(718);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::BIT:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::COMPLEX:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 1);
        setState(704);
        scalarType();
        setState(705);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::QUBIT: {
        enterOuterAlt(_localctx, 2);
        setState(707);
        qubitType();
        setState(708);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::QREG:
      case qasm3Parser::CREG: {
        enterOuterAlt(_localctx, 3);
        setState(710);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::QREG

        || _la == qasm3Parser::CREG)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(711);
        match(qasm3Parser::Identifier);
        setState(713);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(712);
          designator();
        }
        break;
      }

      case qasm3Parser::READONLY:
      case qasm3Parser::MUTABLE: {
        enterOuterAlt(_localctx, 4);
        setState(715);
        arrayReferenceType();
        setState(716);
        match(qasm3Parser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentDefinitionListContext ------------------------------------------------------------------

qasm3Parser::ArgumentDefinitionListContext::ArgumentDefinitionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ArgumentDefinitionContext *> qasm3Parser::ArgumentDefinitionListContext::argumentDefinition() {
  return getRuleContexts<qasm3Parser::ArgumentDefinitionContext>();
}

qasm3Parser::ArgumentDefinitionContext* qasm3Parser::ArgumentDefinitionListContext::argumentDefinition(size_t i) {
  return getRuleContext<qasm3Parser::ArgumentDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ArgumentDefinitionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ArgumentDefinitionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ArgumentDefinitionListContext::getRuleIndex() const {
  return qasm3Parser::RuleArgumentDefinitionList;
}


antlrcpp::Any qasm3Parser::ArgumentDefinitionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArgumentDefinitionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArgumentDefinitionListContext* qasm3Parser::argumentDefinitionList() {
  ArgumentDefinitionListContext *_localctx = _tracker.createInstance<ArgumentDefinitionListContext>(_ctx, getState());
  enterRule(_localctx, 114, qasm3Parser::RuleArgumentDefinitionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(720);
    argumentDefinition();
    setState(725);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(721);
        match(qasm3Parser::COMMA);
        setState(722);
        argumentDefinition(); 
      }
      setState(727);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx);
    }
    setState(729);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(728);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalArgumentDefinitionListContext ------------------------------------------------------------------

qasm3Parser::DefcalArgumentDefinitionListContext::DefcalArgumentDefinitionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::DefcalArgumentDefinitionContext *> qasm3Parser::DefcalArgumentDefinitionListContext::defcalArgumentDefinition() {
  return getRuleContexts<qasm3Parser::DefcalArgumentDefinitionContext>();
}

qasm3Parser::DefcalArgumentDefinitionContext* qasm3Parser::DefcalArgumentDefinitionListContext::defcalArgumentDefinition(size_t i) {
  return getRuleContext<qasm3Parser::DefcalArgumentDefinitionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::DefcalArgumentDefinitionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::DefcalArgumentDefinitionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::DefcalArgumentDefinitionListContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalArgumentDefinitionList;
}


antlrcpp::Any qasm3Parser::DefcalArgumentDefinitionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalArgumentDefinitionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalArgumentDefinitionListContext* qasm3Parser::defcalArgumentDefinitionList() {
  DefcalArgumentDefinitionListContext *_localctx = _tracker.createInstance<DefcalArgumentDefinitionListContext>(_ctx, getState());
  enterRule(_localctx, 116, qasm3Parser::RuleDefcalArgumentDefinitionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(731);
    defcalArgumentDefinition();
    setState(736);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(732);
        match(qasm3Parser::COMMA);
        setState(733);
        defcalArgumentDefinition(); 
      }
      setState(738);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
    }
    setState(740);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(739);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefcalOperandListContext ------------------------------------------------------------------

qasm3Parser::DefcalOperandListContext::DefcalOperandListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::DefcalOperandContext *> qasm3Parser::DefcalOperandListContext::defcalOperand() {
  return getRuleContexts<qasm3Parser::DefcalOperandContext>();
}

qasm3Parser::DefcalOperandContext* qasm3Parser::DefcalOperandListContext::defcalOperand(size_t i) {
  return getRuleContext<qasm3Parser::DefcalOperandContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::DefcalOperandListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::DefcalOperandListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::DefcalOperandListContext::getRuleIndex() const {
  return qasm3Parser::RuleDefcalOperandList;
}


antlrcpp::Any qasm3Parser::DefcalOperandListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDefcalOperandList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DefcalOperandListContext* qasm3Parser::defcalOperandList() {
  DefcalOperandListContext *_localctx = _tracker.createInstance<DefcalOperandListContext>(_ctx, getState());
  enterRule(_localctx, 118, qasm3Parser::RuleDefcalOperandList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(742);
    defcalOperand();
    setState(747);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(743);
        match(qasm3Parser::COMMA);
        setState(744);
        defcalOperand(); 
      }
      setState(749);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
    setState(751);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(750);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

qasm3Parser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ExpressionListContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ExpressionListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ExpressionListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ExpressionListContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionList;
}


antlrcpp::Any qasm3Parser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionListContext* qasm3Parser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 120, qasm3Parser::RuleExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(753);
    expression(0);
    setState(758);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(754);
        match(qasm3Parser::COMMA);
        setState(755);
        expression(0); 
      }
      setState(760);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    }
    setState(762);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(761);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

qasm3Parser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::IdentifierListContext::Identifier() {
  return getTokens(qasm3Parser::Identifier);
}

tree::TerminalNode* qasm3Parser::IdentifierListContext::Identifier(size_t i) {
  return getToken(qasm3Parser::Identifier, i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IdentifierListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IdentifierListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IdentifierListContext::getRuleIndex() const {
  return qasm3Parser::RuleIdentifierList;
}


antlrcpp::Any qasm3Parser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IdentifierListContext* qasm3Parser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 122, qasm3Parser::RuleIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(764);
    match(qasm3Parser::Identifier);
    setState(769);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(765);
        match(qasm3Parser::COMMA);
        setState(766);
        match(qasm3Parser::Identifier); 
      }
      setState(771);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    }
    setState(773);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(772);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GateOperandListContext ------------------------------------------------------------------

qasm3Parser::GateOperandListContext::GateOperandListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::GateOperandContext *> qasm3Parser::GateOperandListContext::gateOperand() {
  return getRuleContexts<qasm3Parser::GateOperandContext>();
}

qasm3Parser::GateOperandContext* qasm3Parser::GateOperandListContext::gateOperand(size_t i) {
  return getRuleContext<qasm3Parser::GateOperandContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::GateOperandListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::GateOperandListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::GateOperandListContext::getRuleIndex() const {
  return qasm3Parser::RuleGateOperandList;
}


antlrcpp::Any qasm3Parser::GateOperandListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGateOperandList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GateOperandListContext* qasm3Parser::gateOperandList() {
  GateOperandListContext *_localctx = _tracker.createInstance<GateOperandListContext>(_ctx, getState());
  enterRule(_localctx, 124, qasm3Parser::RuleGateOperandList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(775);
    gateOperand();
    setState(780);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(776);
        match(qasm3Parser::COMMA);
        setState(777);
        gateOperand(); 
      }
      setState(782);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
    }
    setState(784);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(783);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternArgumentListContext ------------------------------------------------------------------

qasm3Parser::ExternArgumentListContext::ExternArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExternArgumentContext *> qasm3Parser::ExternArgumentListContext::externArgument() {
  return getRuleContexts<qasm3Parser::ExternArgumentContext>();
}

qasm3Parser::ExternArgumentContext* qasm3Parser::ExternArgumentListContext::externArgument(size_t i) {
  return getRuleContext<qasm3Parser::ExternArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ExternArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ExternArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ExternArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleExternArgumentList;
}


antlrcpp::Any qasm3Parser::ExternArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternArgumentListContext* qasm3Parser::externArgumentList() {
  ExternArgumentListContext *_localctx = _tracker.createInstance<ExternArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 126, qasm3Parser::RuleExternArgumentList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(786);
    externArgument();
    setState(791);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(787);
        match(qasm3Parser::COMMA);
        setState(788);
        externArgument(); 
      }
      setState(793);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    }
    setState(795);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COMMA) {
      setState(794);
      match(qasm3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool qasm3Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 35: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 16);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 17);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> qasm3Parser::_decisionToDFA;
atn::PredictionContextCache qasm3Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN qasm3Parser::_atn;
std::vector<uint16_t> qasm3Parser::_serializedATN;

std::vector<std::string> qasm3Parser::_ruleNames = {
  "program", "version", "statement", "annotation", "scope", "pragma", "statementOrScope", 
  "calibrationGrammarStatement", "includeStatement", "breakStatement", "continueStatement", 
  "endStatement", "forStatement", "ifStatement", "returnStatement", "whileStatement", 
  "barrierStatement", "boxStatement", "delayStatement", "gateCallStatement", 
  "measureArrowAssignmentStatement", "resetStatement", "aliasDeclarationStatement", 
  "classicalDeclarationStatement", "constDeclarationStatement", "ioDeclarationStatement", 
  "oldStyleDeclarationStatement", "quantumDeclarationStatement", "defStatement", 
  "externStatement", "gateStatement", "assignmentStatement", "expressionStatement", 
  "calStatement", "defcalStatement", "expression", "aliasExpression", "declarationExpression", 
  "measureExpression", "rangeExpression", "setExpression", "arrayLiteral", 
  "indexOperator", "indexedIdentifier", "returnSignature", "gateModifier", 
  "scalarType", "qubitType", "arrayType", "arrayReferenceType", "designator", 
  "defcalTarget", "defcalArgumentDefinition", "defcalOperand", "gateOperand", 
  "externArgument", "argumentDefinition", "argumentDefinitionList", "defcalArgumentDefinitionList", 
  "defcalOperandList", "expressionList", "identifierList", "gateOperandList", 
  "externArgumentList"
};

std::vector<std::string> qasm3Parser::_literalNames = {
  "", "'OPENQASM'", "'include'", "'defcalgrammar'", "'def'", "'cal'", "'defcal'", 
  "'gate'", "'extern'", "'box'", "'let'", "'break'", "'continue'", "'if'", 
  "'else'", "'end'", "'return'", "'for'", "'while'", "'in'", "", "", "'input'", 
  "'output'", "'const'", "'readonly'", "'mutable'", "'qreg'", "'qubit'", 
  "'creg'", "'bool'", "'bit'", "'int'", "'uint'", "'float'", "'angle'", 
  "'complex'", "'array'", "'duration'", "'stretch'", "'gphase'", "'inv'", 
  "'pow'", "'ctrl'", "'negctrl'", "'#dim'", "'durationof'", "'delay'", "'reset'", 
  "'measure'", "'barrier'", "", "'['", "']'", "'{'", "'}'", "'('", "')'", 
  "':'", "';'", "'.'", "','", "'='", "'->'", "'+'", "'++'", "'-'", "'*'", 
  "'**'", "'/'", "'%'", "'|'", "'||'", "'&'", "'&&'", "'^'", "'@'", "'~'", 
  "'!'", "", "", "", "", "'im'"
};

std::vector<std::string> qasm3Parser::_symbolicNames = {
  "", "OPENQASM", "INCLUDE", "DEFCALGRAMMAR", "DEF", "CAL", "DEFCAL", "GATE", 
  "EXTERN", "BOX", "LET", "BREAK", "CONTINUE", "IF", "ELSE", "END", "RETURN", 
  "FOR", "WHILE", "IN", "PRAGMA", "AnnotationKeyword", "INPUT", "OUTPUT", 
  "CONST", "READONLY", "MUTABLE", "QREG", "QUBIT", "CREG", "BOOL", "BIT", 
  "INT", "UINT", "FLOAT", "ANGLE", "COMPLEX", "ARRAY", "DURATION", "STRETCH", 
  "GPHASE", "INV", "POW", "CTRL", "NEGCTRL", "DIM", "DURATIONOF", "DELAY", 
  "RESET", "MEASURE", "BARRIER", "BooleanLiteral", "LBRACKET", "RBRACKET", 
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "COLON", "SEMICOLON", "DOT", "COMMA", 
  "EQUALS", "ARROW", "PLUS", "DOUBLE_PLUS", "MINUS", "ASTERISK", "DOUBLE_ASTERISK", 
  "SLASH", "PERCENT", "PIPE", "DOUBLE_PIPE", "AMPERSAND", "DOUBLE_AMPERSAND", 
  "CARET", "AT", "TILDE", "EXCLAMATION_POINT", "EqualityOperator", "CompoundAssignmentOperator", 
  "ComparisonOperator", "BitshiftOperator", "IMAG", "ImaginaryLiteral", 
  "BinaryIntegerLiteral", "OctalIntegerLiteral", "DecimalIntegerLiteral", 
  "HexIntegerLiteral", "Identifier", "HardwareQubit", "FloatLiteral", "TimingLiteral", 
  "BitstringLiteral", "StringLiteral", "Whitespace", "Newline", "LineComment", 
  "BlockComment", "VERSION_IDENTIFER_WHITESPACE", "VersionSpecifier", "EAT_INITIAL_SPACE", 
  "EAT_LINE_END", "RemainingLineContent", "CAL_PRELUDE_WHITESPACE", "CAL_PRELUDE_COMMENT", 
  "DEFCAL_PRELUDE_WHITESPACE", "DEFCAL_PRELUDE_COMMENT", "CalibrationBlock"
};

dfa::Vocabulary qasm3Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> qasm3Parser::_tokenNames;

qasm3Parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x6e, 0x320, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x3, 0x2, 0x5, 0x2, 0x84, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 
       0x87, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x8a, 0xb, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
       0x7, 0x4, 0x94, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x97, 0xb, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0xb5, 0xa, 0x4, 0x5, 0x4, 0xb7, 0xa, 0x4, 
       0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xbb, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x7, 0x6, 0xbf, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xc2, 0xb, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x5, 0x8, 0xcb, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xe8, 0xa, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xf3, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x5, 0x10, 0xf8, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x12, 0x3, 0x12, 0x5, 0x12, 0x104, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x10a, 0xa, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x111, 0xa, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x7, 0x15, 0x116, 0xa, 0x15, 0xc, 
       0x15, 0xe, 0x15, 0x119, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x5, 0x15, 0x11e, 0xa, 0x15, 0x3, 0x15, 0x5, 0x15, 0x121, 0xa, 0x15, 
       0x3, 0x15, 0x5, 0x15, 0x124, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x7, 0x15, 0x12a, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
       0x12d, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x132, 
       0xa, 0x15, 0x3, 0x15, 0x5, 0x15, 0x135, 0xa, 0x15, 0x3, 0x15, 0x5, 
       0x15, 0x138, 0xa, 0x15, 0x3, 0x15, 0x5, 0x15, 0x13b, 0xa, 0x15, 0x3, 
       0x15, 0x5, 0x15, 0x13e, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x5, 0x16, 0x143, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x153, 
       0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x158, 0xa, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x166, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x16e, 0xa, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x17a, 0xa, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x17e, 0xa, 0x1e, 0x3, 0x1e, 0x3, 
       0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x186, 
       0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x18a, 0xa, 0x1f, 0x3, 
       0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
       0x20, 0x192, 0xa, 0x20, 0x3, 0x20, 0x5, 0x20, 0x195, 0xa, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x5, 0x21, 0x19e, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 
       0x1a8, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x5, 0x24, 0x1b0, 0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 
       0x1b3, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1b7, 0xa, 0x24, 
       0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1bb, 0xa, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1c8, 0xa, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x5, 0x25, 0x1d6, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1da, 
       0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x7, 0x25, 0x1ff, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x202, 0xb, 0x25, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x207, 0xa, 0x26, 0xc, 
       0x26, 0xe, 0x26, 0x20a, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x5, 0x27, 0x20f, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
       0x29, 0x5, 0x29, 0x215, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
       0x219, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x21d, 0xa, 0x29, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x223, 0xa, 
       0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x226, 0xb, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 
       0x229, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x5, 0x2b, 0x230, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x5, 0x2b, 0x235, 0xa, 0x2b, 0x7, 0x2b, 0x237, 0xa, 0x2b, 0xc, 0x2b, 
       0xe, 0x2b, 0x23a, 0xb, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x23d, 0xa, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x5, 0x2c, 0x245, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 
       0x2c, 0x24a, 0xa, 0x2c, 0x7, 0x2c, 0x24c, 0xa, 0x2c, 0xc, 0x2c, 0xe, 
       0x2c, 0x24f, 0xb, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x252, 0xa, 0x2c, 0x5, 
       0x2c, 0x254, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 
       0x7, 0x2d, 0x25a, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x25d, 0xb, 0x2d, 
       0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x26d, 0xa, 0x2f, 0x5, 0x2f, 0x26f, 
       0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 
       0x275, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x279, 0xa, 0x30, 
       0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x27d, 0xa, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x5, 0x30, 0x281, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 
       0x285, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x28f, 0xa, 0x30, 
       0x5, 0x30, 0x291, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x295, 
       0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
       0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
       0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 
       0x2a7, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 
       0x36, 0x2b3, 0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 
       0x5, 0x38, 0x2b9, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x5, 0x39, 0x2bf, 0xa, 0x39, 0x5, 0x39, 0x2c1, 0xa, 0x39, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x2cc, 0xa, 0x3a, 0x3, 0x3a, 
       0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x2d1, 0xa, 0x3a, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x2d6, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 
       0x2d9, 0xb, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x2dc, 0xa, 0x3b, 0x3, 0x3c, 
       0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x2e1, 0xa, 0x3c, 0xc, 0x3c, 0xe, 
       0x3c, 0x2e4, 0xb, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x2e7, 0xa, 0x3c, 0x3, 
       0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x2ec, 0xa, 0x3d, 0xc, 0x3d, 
       0xe, 0x3d, 0x2ef, 0xb, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x2f2, 0xa, 0x3d, 
       0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x2f7, 0xa, 0x3e, 0xc, 
       0x3e, 0xe, 0x3e, 0x2fa, 0xb, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x2fd, 0xa, 
       0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x302, 0xa, 0x3f, 
       0xc, 0x3f, 0xe, 0x3f, 0x305, 0xb, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x308, 
       0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x30d, 0xa, 
       0x40, 0xc, 0x40, 0xe, 0x40, 0x310, 0xb, 0x40, 0x3, 0x40, 0x5, 0x40, 
       0x313, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x318, 
       0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x31b, 0xb, 0x41, 0x3, 0x41, 0x5, 
       0x41, 0x31e, 0xa, 0x41, 0x3, 0x41, 0x2, 0x3, 0x48, 0x42, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
       0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
       0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
       0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
       0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
       0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x2, 0xd, 0x3, 0x2, 0x18, 0x19, 
       0x4, 0x2, 0x1d, 0x1d, 0x1f, 0x1f, 0x4, 0x2, 0x40, 0x40, 0x52, 0x52, 
       0x4, 0x2, 0x44, 0x44, 0x4f, 0x50, 0x4, 0x2, 0x35, 0x35, 0x56, 0x5f, 
       0x4, 0x2, 0x45, 0x45, 0x47, 0x48, 0x4, 0x2, 0x42, 0x42, 0x44, 0x44, 
       0x3, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x1b, 0x1c, 0x4, 0x2, 0x31, 0x33, 
       0x5b, 0x5b, 0x3, 0x2, 0x5b, 0x5c, 0x2, 0x373, 0x2, 0x83, 0x3, 0x2, 
       0x2, 0x2, 0x4, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x6, 0xb6, 0x3, 0x2, 0x2, 
       0x2, 0x8, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xa, 0xbc, 0x3, 0x2, 0x2, 0x2, 
       0xc, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xe, 0xca, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0xcc, 0x3, 0x2, 0x2, 0x2, 0x12, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x14, 0xd4, 
       0x3, 0x2, 0x2, 0x2, 0x16, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xda, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xeb, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x20, 0xfb, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0x101, 0x3, 0x2, 0x2, 0x2, 0x24, 0x107, 0x3, 0x2, 0x2, 
       0x2, 0x26, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x28, 0x13d, 0x3, 0x2, 0x2, 
       0x2, 0x2a, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x146, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x152, 0x3, 0x2, 0x2, 
       0x2, 0x32, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x162, 0x3, 0x2, 0x2, 
       0x2, 0x36, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x171, 0x3, 0x2, 0x2, 
       0x2, 0x3a, 0x175, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x181, 0x3, 0x2, 0x2, 
       0x2, 0x3e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x199, 0x3, 0x2, 0x2, 
       0x2, 0x42, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1a4, 0x3, 0x2, 0x2, 
       0x2, 0x46, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1d9, 0x3, 0x2, 0x2, 
       0x2, 0x4a, 0x203, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x20e, 0x3, 0x2, 0x2, 
       0x2, 0x4e, 0x210, 0x3, 0x2, 0x2, 0x2, 0x50, 0x214, 0x3, 0x2, 0x2, 
       0x2, 0x52, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x54, 0x22c, 0x3, 0x2, 0x2, 
       0x2, 0x56, 0x240, 0x3, 0x2, 0x2, 0x2, 0x58, 0x257, 0x3, 0x2, 0x2, 
       0x2, 0x5a, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x26e, 0x3, 0x2, 0x2, 
       0x2, 0x5e, 0x290, 0x3, 0x2, 0x2, 0x2, 0x60, 0x292, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x296, 0x3, 0x2, 0x2, 0x2, 0x64, 0x29d, 0x3, 0x2, 0x2, 
       0x2, 0x66, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x68, 0x2ae, 0x3, 0x2, 0x2, 
       0x2, 0x6a, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x2b4, 0x3, 0x2, 0x2, 
       0x2, 0x6e, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x70, 0x2c0, 0x3, 0x2, 0x2, 
       0x2, 0x72, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x74, 0x2d2, 0x3, 0x2, 0x2, 
       0x2, 0x76, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x78, 0x2e8, 0x3, 0x2, 0x2, 
       0x2, 0x7a, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x2fe, 0x3, 0x2, 0x2, 
       0x2, 0x7e, 0x309, 0x3, 0x2, 0x2, 0x2, 0x80, 0x314, 0x3, 0x2, 0x2, 
       0x2, 0x82, 0x84, 0x5, 0x4, 0x3, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 
       0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x88, 0x3, 0x2, 0x2, 0x2, 0x85, 
       0x87, 0x5, 0x6, 0x4, 0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8a, 
       0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 
       0x2, 0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 
       0x2, 0x2, 0x8b, 0x8c, 0x7, 0x2, 0x2, 0x3, 0x8c, 0x3, 0x3, 0x2, 0x2, 
       0x2, 0x8d, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x66, 0x2, 
       0x2, 0x8f, 0x90, 0x7, 0x3d, 0x2, 0x2, 0x90, 0x5, 0x3, 0x2, 0x2, 0x2, 
       0x91, 0xb7, 0x5, 0xc, 0x7, 0x2, 0x92, 0x94, 0x5, 0x8, 0x5, 0x2, 0x93, 
       0x92, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 
       0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0xb4, 0x3, 
       0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0xb5, 0x5, 0x2e, 
       0x18, 0x2, 0x99, 0xb5, 0x5, 0x40, 0x21, 0x2, 0x9a, 0xb5, 0x5, 0x22, 
       0x12, 0x2, 0x9b, 0xb5, 0x5, 0x24, 0x13, 0x2, 0x9c, 0xb5, 0x5, 0x14, 
       0xb, 0x2, 0x9d, 0xb5, 0x5, 0x44, 0x23, 0x2, 0x9e, 0xb5, 0x5, 0x10, 
       0x9, 0x2, 0x9f, 0xb5, 0x5, 0x30, 0x19, 0x2, 0xa0, 0xb5, 0x5, 0x32, 
       0x1a, 0x2, 0xa1, 0xb5, 0x5, 0x16, 0xc, 0x2, 0xa2, 0xb5, 0x5, 0x3a, 
       0x1e, 0x2, 0xa3, 0xb5, 0x5, 0x46, 0x24, 0x2, 0xa4, 0xb5, 0x5, 0x26, 
       0x14, 0x2, 0xa5, 0xb5, 0x5, 0x18, 0xd, 0x2, 0xa6, 0xb5, 0x5, 0x42, 
       0x22, 0x2, 0xa7, 0xb5, 0x5, 0x3c, 0x1f, 0x2, 0xa8, 0xb5, 0x5, 0x1a, 
       0xe, 0x2, 0xa9, 0xb5, 0x5, 0x28, 0x15, 0x2, 0xaa, 0xb5, 0x5, 0x3e, 
       0x20, 0x2, 0xab, 0xb5, 0x5, 0x1c, 0xf, 0x2, 0xac, 0xb5, 0x5, 0x12, 
       0xa, 0x2, 0xad, 0xb5, 0x5, 0x34, 0x1b, 0x2, 0xae, 0xb5, 0x5, 0x2a, 
       0x16, 0x2, 0xaf, 0xb5, 0x5, 0x36, 0x1c, 0x2, 0xb0, 0xb5, 0x5, 0x38, 
       0x1d, 0x2, 0xb1, 0xb5, 0x5, 0x2c, 0x17, 0x2, 0xb2, 0xb5, 0x5, 0x1e, 
       0x10, 0x2, 0xb3, 0xb5, 0x5, 0x20, 0x11, 0x2, 0xb4, 0x98, 0x3, 0x2, 
       0x2, 0x2, 0xb4, 0x99, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x9a, 0x3, 0x2, 0x2, 
       0x2, 0xb4, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x9c, 0x3, 0x2, 0x2, 0x2, 
       0xb4, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xb4, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa1, 
       0x3, 0x2, 0x2, 0x2, 0xb4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa3, 0x3, 
       0x2, 0x2, 0x2, 0xb4, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa5, 0x3, 0x2, 
       0x2, 0x2, 0xb4, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa7, 0x3, 0x2, 0x2, 
       0x2, 0xb4, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xa9, 0x3, 0x2, 0x2, 0x2, 
       0xb4, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb4, 
       0xac, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xae, 
       0x3, 0x2, 0x2, 0x2, 0xb4, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb0, 0x3, 
       0x2, 0x2, 0x2, 0xb4, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 
       0x2, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb7, 0x3, 0x2, 0x2, 
       0x2, 0xb6, 0x91, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x95, 0x3, 0x2, 0x2, 0x2, 
       0xb7, 0x7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x7, 0x17, 0x2, 0x2, 0xb9, 
       0xbb, 0x7, 0x69, 0x2, 0x2, 0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xba, 
       0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc0, 
       0x7, 0x38, 0x2, 0x2, 0xbd, 0xbf, 0x5, 0x6, 0x4, 0x2, 0xbe, 0xbd, 
       0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 
       0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x3, 0x2, 
       0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x39, 
       0x2, 0x2, 0xc4, 0xb, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x16, 0x2, 
       0x2, 0xc6, 0xc7, 0x7, 0x69, 0x2, 0x2, 0xc7, 0xd, 0x3, 0x2, 0x2, 0x2, 
       0xc8, 0xcb, 0x5, 0x6, 0x4, 0x2, 0xc9, 0xcb, 0x5, 0xa, 0x6, 0x2, 0xca, 
       0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x5, 0x2, 0x2, 0xcd, 0xce, 0x7, 
       0x60, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x3d, 0x2, 0x2, 0xcf, 0x11, 0x3, 
       0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x4, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x60, 
       0x2, 0x2, 0xd2, 0xd3, 0x7, 0x3d, 0x2, 0x2, 0xd3, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0xd4, 0xd5, 0x7, 0xd, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x3d, 
       0x2, 0x2, 0xd6, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0xe, 0x2, 
       0x2, 0xd8, 0xd9, 0x7, 0x3d, 0x2, 0x2, 0xd9, 0x17, 0x3, 0x2, 0x2, 
       0x2, 0xda, 0xdb, 0x7, 0x11, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x3d, 0x2, 
       0x2, 0xdc, 0x19, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x13, 0x2, 
       0x2, 0xde, 0xdf, 0x5, 0x5e, 0x30, 0x2, 0xdf, 0xe0, 0x7, 0x5b, 0x2, 
       0x2, 0xe0, 0xe7, 0x7, 0x15, 0x2, 0x2, 0xe1, 0xe8, 0x5, 0x52, 0x2a, 
       0x2, 0xe2, 0xe3, 0x7, 0x36, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x50, 0x29, 
       0x2, 0xe4, 0xe5, 0x7, 0x37, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 
       0x2, 0xe6, 0xe8, 0x7, 0x5b, 0x2, 0x2, 0xe7, 0xe1, 0x3, 0x2, 0x2, 
       0x2, 0xe7, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 
       0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x5, 0xe, 0x8, 0x2, 0xea, 
       0x1b, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0xf, 0x2, 0x2, 0xec, 0xed, 
       0x7, 0x3a, 0x2, 0x2, 0xed, 0xee, 0x5, 0x48, 0x25, 0x2, 0xee, 0xef, 
       0x7, 0x3b, 0x2, 0x2, 0xef, 0xf2, 0x5, 0xe, 0x8, 0x2, 0xf0, 0xf1, 
       0x7, 0x10, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0xe, 0x8, 0x2, 0xf2, 0xf0, 
       0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0x1d, 0x3, 
       0x2, 0x2, 0x2, 0xf4, 0xf7, 0x7, 0x12, 0x2, 0x2, 0xf5, 0xf8, 0x5, 
       0x48, 0x25, 0x2, 0xf6, 0xf8, 0x5, 0x4e, 0x28, 0x2, 0xf7, 0xf5, 0x3, 
       0x2, 0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 
       0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x3d, 
       0x2, 0x2, 0xfa, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x14, 
       0x2, 0x2, 0xfc, 0xfd, 0x7, 0x3a, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x48, 
       0x25, 0x2, 0xfe, 0xff, 0x7, 0x3b, 0x2, 0x2, 0xff, 0x100, 0x5, 0xe, 
       0x8, 0x2, 0x100, 0x21, 0x3, 0x2, 0x2, 0x2, 0x101, 0x103, 0x7, 0x34, 
       0x2, 0x2, 0x102, 0x104, 0x5, 0x7e, 0x40, 0x2, 0x103, 0x102, 0x3, 
       0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 
       0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0x3d, 0x2, 0x2, 0x106, 0x23, 0x3, 
       0x2, 0x2, 0x2, 0x107, 0x109, 0x7, 0xb, 0x2, 0x2, 0x108, 0x10a, 0x5, 
       0x66, 0x34, 0x2, 0x109, 0x108, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 
       0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 
       0x5, 0xa, 0x6, 0x2, 0x10c, 0x25, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 
       0x7, 0x31, 0x2, 0x2, 0x10e, 0x110, 0x5, 0x66, 0x34, 0x2, 0x10f, 0x111, 
       0x5, 0x7e, 0x40, 0x2, 0x110, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 
       0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
       0x7, 0x3d, 0x2, 0x2, 0x113, 0x27, 0x3, 0x2, 0x2, 0x2, 0x114, 0x116, 
       0x5, 0x5c, 0x2f, 0x2, 0x115, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x120, 0x7, 0x5b, 0x2, 0x2, 0x11b, 0x11d, 
       0x7, 0x3a, 0x2, 0x2, 0x11c, 0x11e, 0x5, 0x7a, 0x3e, 0x2, 0x11d, 0x11c, 
       0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x11f, 0x121, 0x7, 0x3b, 0x2, 0x2, 0x120, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x5, 0x66, 0x34, 0x2, 0x123, 0x122, 
       0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 
       0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x5, 0x7e, 0x40, 0x2, 0x126, 0x127, 
       0x7, 0x3d, 0x2, 0x2, 0x127, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12a, 
       0x5, 0x5c, 0x2f, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x134, 0x7, 0x2a, 0x2, 0x2, 0x12f, 0x131, 
       0x7, 0x3a, 0x2, 0x2, 0x130, 0x132, 0x5, 0x7a, 0x3e, 0x2, 0x131, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x7, 0x3b, 0x2, 0x2, 0x134, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x5, 0x66, 0x34, 0x2, 0x137, 0x136, 
       0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x7e, 0x40, 0x2, 0x13a, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 
       0x3, 0x2, 0x2, 0x2, 0x13c, 0x13e, 0x7, 0x3d, 0x2, 0x2, 0x13d, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x13f, 0x142, 0x5, 0x4e, 0x28, 0x2, 0x140, 0x141, 
       0x7, 0x41, 0x2, 0x2, 0x141, 0x143, 0x5, 0x58, 0x2d, 0x2, 0x142, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x3d, 0x2, 0x2, 0x145, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0x32, 0x2, 0x2, 0x147, 0x148, 
       0x5, 0x6e, 0x38, 0x2, 0x148, 0x149, 0x7, 0x3d, 0x2, 0x2, 0x149, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0xc, 0x2, 0x2, 0x14b, 0x14c, 
       0x7, 0x5b, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x40, 0x2, 0x2, 0x14d, 0x14e, 
       0x5, 0x4a, 0x26, 0x2, 0x14e, 0x14f, 0x7, 0x3d, 0x2, 0x2, 0x14f, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x153, 0x5, 0x5e, 0x30, 0x2, 0x151, 0x153, 
       0x5, 0x62, 0x32, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x151, 
       0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x157, 
       0x7, 0x5b, 0x2, 0x2, 0x155, 0x156, 0x7, 0x40, 0x2, 0x2, 0x156, 0x158, 
       0x5, 0x4c, 0x27, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 
       0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 
       0x7, 0x3d, 0x2, 0x2, 0x15a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 
       0x7, 0x1a, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x5e, 0x30, 0x2, 0x15d, 0x15e, 
       0x7, 0x5b, 0x2, 0x2, 0x15e, 0x15f, 0x7, 0x40, 0x2, 0x2, 0x15f, 0x160, 
       0x5, 0x4c, 0x27, 0x2, 0x160, 0x161, 0x7, 0x3d, 0x2, 0x2, 0x161, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x162, 0x165, 0x9, 0x2, 0x2, 0x2, 0x163, 0x166, 
       0x5, 0x5e, 0x30, 0x2, 0x164, 0x166, 0x5, 0x62, 0x32, 0x2, 0x165, 
       0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x166, 
       0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x5b, 0x2, 0x2, 0x168, 
       0x169, 0x7, 0x3d, 0x2, 0x2, 0x169, 0x35, 0x3, 0x2, 0x2, 0x2, 0x16a, 
       0x16b, 0x9, 0x3, 0x2, 0x2, 0x16b, 0x16d, 0x7, 0x5b, 0x2, 0x2, 0x16c, 
       0x16e, 0x5, 0x66, 0x34, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x170, 0x7, 0x3d, 0x2, 0x2, 0x170, 0x37, 0x3, 0x2, 0x2, 0x2, 0x171, 
       0x172, 0x5, 0x60, 0x31, 0x2, 0x172, 0x173, 0x7, 0x5b, 0x2, 0x2, 0x173, 
       0x174, 0x7, 0x3d, 0x2, 0x2, 0x174, 0x39, 0x3, 0x2, 0x2, 0x2, 0x175, 
       0x176, 0x7, 0x6, 0x2, 0x2, 0x176, 0x177, 0x7, 0x5b, 0x2, 0x2, 0x177, 
       0x179, 0x7, 0x3a, 0x2, 0x2, 0x178, 0x17a, 0x5, 0x74, 0x3b, 0x2, 0x179, 
       0x178, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 
       0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17d, 0x7, 0x3b, 0x2, 0x2, 0x17c, 
       0x17e, 0x5, 0x5a, 0x2e, 0x2, 0x17d, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17d, 
       0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 
       0x180, 0x5, 0xa, 0x6, 0x2, 0x180, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x182, 0x7, 0xa, 0x2, 0x2, 0x182, 0x183, 0x7, 0x5b, 0x2, 0x2, 0x183, 
       0x185, 0x7, 0x3a, 0x2, 0x2, 0x184, 0x186, 0x5, 0x80, 0x41, 0x2, 0x185, 
       0x184, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x3, 0x2, 0x2, 0x2, 0x186, 
       0x187, 0x3, 0x2, 0x2, 0x2, 0x187, 0x189, 0x7, 0x3b, 0x2, 0x2, 0x188, 
       0x18a, 0x5, 0x5a, 0x2e, 0x2, 0x189, 0x188, 0x3, 0x2, 0x2, 0x2, 0x189, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 
       0x18c, 0x7, 0x3d, 0x2, 0x2, 0x18c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x18d, 
       0x18e, 0x7, 0x9, 0x2, 0x2, 0x18e, 0x194, 0x7, 0x5b, 0x2, 0x2, 0x18f, 
       0x191, 0x7, 0x3a, 0x2, 0x2, 0x190, 0x192, 0x5, 0x7c, 0x3f, 0x2, 0x191, 
       0x190, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x3, 0x2, 0x2, 0x2, 0x192, 
       0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x195, 0x7, 0x3b, 0x2, 0x2, 0x194, 
       0x18f, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 
       0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x5, 0x7c, 0x3f, 0x2, 0x197, 
       0x198, 0x5, 0xa, 0x6, 0x2, 0x198, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x199, 
       0x19a, 0x5, 0x58, 0x2d, 0x2, 0x19a, 0x19d, 0x9, 0x4, 0x2, 0x2, 0x19b, 
       0x19e, 0x5, 0x48, 0x25, 0x2, 0x19c, 0x19e, 0x5, 0x4e, 0x28, 0x2, 
       0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 0x2, 
       0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x3d, 0x2, 0x2, 
       0x1a0, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x48, 0x25, 0x2, 
       0x1a2, 0x1a3, 0x7, 0x3d, 0x2, 0x2, 0x1a3, 0x43, 0x3, 0x2, 0x2, 0x2, 
       0x1a4, 0x1a5, 0x7, 0x7, 0x2, 0x2, 0x1a5, 0x1a7, 0x7, 0x38, 0x2, 0x2, 
       0x1a6, 0x1a8, 0x7, 0x6e, 0x2, 0x2, 0x1a7, 0x1a6, 0x3, 0x2, 0x2, 0x2, 
       0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x3, 0x2, 0x2, 0x2, 
       0x1a9, 0x1aa, 0x7, 0x39, 0x2, 0x2, 0x1aa, 0x45, 0x3, 0x2, 0x2, 0x2, 
       0x1ab, 0x1ac, 0x7, 0x8, 0x2, 0x2, 0x1ac, 0x1b2, 0x5, 0x68, 0x35, 
       0x2, 0x1ad, 0x1af, 0x7, 0x3a, 0x2, 0x2, 0x1ae, 0x1b0, 0x5, 0x76, 
       0x3c, 0x2, 0x1af, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 
       0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b3, 0x7, 0x3b, 
       0x2, 0x2, 0x1b2, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x3, 0x2, 
       0x2, 0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x78, 
       0x3d, 0x2, 0x1b5, 0x1b7, 0x5, 0x5a, 0x2e, 0x2, 0x1b6, 0x1b5, 0x3, 
       0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 
       0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x7, 0x38, 0x2, 0x2, 0x1b9, 0x1bb, 0x7, 
       0x6e, 0x2, 0x2, 0x1ba, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x3, 
       0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 
       0x39, 0x2, 0x2, 0x1bd, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x8, 
       0x25, 0x1, 0x2, 0x1bf, 0x1c0, 0x7, 0x3a, 0x2, 0x2, 0x1c0, 0x1c1, 
       0x5, 0x48, 0x25, 0x2, 0x1c1, 0x1c2, 0x7, 0x3b, 0x2, 0x2, 0x1c2, 0x1da, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x9, 0x5, 0x2, 0x2, 0x1c4, 0x1da, 
       0x5, 0x48, 0x25, 0x11, 0x1c5, 0x1c8, 0x5, 0x5e, 0x30, 0x2, 0x1c6, 
       0x1c8, 0x5, 0x62, 0x32, 0x2, 0x1c7, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
       0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
       0x1ca, 0x7, 0x3a, 0x2, 0x2, 0x1ca, 0x1cb, 0x5, 0x48, 0x25, 0x2, 0x1cb, 
       0x1cc, 0x7, 0x3b, 0x2, 0x2, 0x1cc, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
       0x1ce, 0x7, 0x30, 0x2, 0x2, 0x1ce, 0x1cf, 0x7, 0x3a, 0x2, 0x2, 0x1cf, 
       0x1d0, 0x5, 0xa, 0x6, 0x2, 0x1d0, 0x1d1, 0x7, 0x3b, 0x2, 0x2, 0x1d1, 
       0x1da, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x7, 0x5b, 0x2, 0x2, 0x1d3, 
       0x1d5, 0x7, 0x3a, 0x2, 0x2, 0x1d4, 0x1d6, 0x5, 0x7a, 0x3e, 0x2, 0x1d5, 
       0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
       0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1da, 0x7, 0x3b, 0x2, 0x2, 0x1d8, 
       0x1da, 0x9, 0x6, 0x2, 0x2, 0x1d9, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x200, 0x3, 0x2, 0x2, 0x2, 0x1db, 
       0x1dc, 0xc, 0x12, 0x2, 0x2, 0x1dc, 0x1dd, 0x7, 0x46, 0x2, 0x2, 0x1dd, 
       0x1ff, 0x5, 0x48, 0x25, 0x12, 0x1de, 0x1df, 0xc, 0x10, 0x2, 0x2, 
       0x1df, 0x1e0, 0x9, 0x7, 0x2, 0x2, 0x1e0, 0x1ff, 0x5, 0x48, 0x25, 
       0x11, 0x1e1, 0x1e2, 0xc, 0xf, 0x2, 0x2, 0x1e2, 0x1e3, 0x9, 0x8, 0x2, 
       0x2, 0x1e3, 0x1ff, 0x5, 0x48, 0x25, 0x10, 0x1e4, 0x1e5, 0xc, 0xe, 
       0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x54, 0x2, 0x2, 0x1e6, 0x1ff, 0x5, 0x48, 
       0x25, 0xf, 0x1e7, 0x1e8, 0xc, 0xd, 0x2, 0x2, 0x1e8, 0x1e9, 0x7, 0x53, 
       0x2, 0x2, 0x1e9, 0x1ff, 0x5, 0x48, 0x25, 0xe, 0x1ea, 0x1eb, 0xc, 
       0xc, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x51, 0x2, 0x2, 0x1ec, 0x1ff, 0x5, 
       0x48, 0x25, 0xd, 0x1ed, 0x1ee, 0xc, 0xb, 0x2, 0x2, 0x1ee, 0x1ef, 
       0x7, 0x4b, 0x2, 0x2, 0x1ef, 0x1ff, 0x5, 0x48, 0x25, 0xc, 0x1f0, 0x1f1, 
       0xc, 0xa, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x4d, 0x2, 0x2, 0x1f2, 0x1ff, 
       0x5, 0x48, 0x25, 0xb, 0x1f3, 0x1f4, 0xc, 0x9, 0x2, 0x2, 0x1f4, 0x1f5, 
       0x7, 0x49, 0x2, 0x2, 0x1f5, 0x1ff, 0x5, 0x48, 0x25, 0xa, 0x1f6, 0x1f7, 
       0xc, 0x8, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x4c, 0x2, 0x2, 0x1f8, 0x1ff, 
       0x5, 0x48, 0x25, 0x9, 0x1f9, 0x1fa, 0xc, 0x7, 0x2, 0x2, 0x1fa, 0x1fb, 
       0x7, 0x4a, 0x2, 0x2, 0x1fb, 0x1ff, 0x5, 0x48, 0x25, 0x8, 0x1fc, 0x1fd, 
       0xc, 0x13, 0x2, 0x2, 0x1fd, 0x1ff, 0x5, 0x56, 0x2c, 0x2, 0x1fe, 0x1db, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1e1, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1e7, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ed, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f3, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f9, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x202, 
       0x3, 0x2, 0x2, 0x2, 0x200, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 
       0x3, 0x2, 0x2, 0x2, 0x201, 0x49, 0x3, 0x2, 0x2, 0x2, 0x202, 0x200, 
       0x3, 0x2, 0x2, 0x2, 0x203, 0x208, 0x5, 0x48, 0x25, 0x2, 0x204, 0x205, 
       0x7, 0x43, 0x2, 0x2, 0x205, 0x207, 0x5, 0x48, 0x25, 0x2, 0x206, 0x204, 
       0x3, 0x2, 0x2, 0x2, 0x207, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x208, 0x206, 
       0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20f, 
       0x5, 0x54, 0x2b, 0x2, 0x20c, 0x20f, 0x5, 0x48, 0x25, 0x2, 0x20d, 
       0x20f, 0x5, 0x4e, 0x28, 0x2, 0x20e, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20e, 
       0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20f, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x7, 0x33, 0x2, 0x2, 0x211, 
       0x212, 0x5, 0x6e, 0x38, 0x2, 0x212, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x213, 
       0x215, 0x5, 0x48, 0x25, 0x2, 0x214, 0x213, 0x3, 0x2, 0x2, 0x2, 0x214, 
       0x215, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x3, 0x2, 0x2, 0x2, 0x216, 
       0x218, 0x7, 0x3c, 0x2, 0x2, 0x217, 0x219, 0x5, 0x48, 0x25, 0x2, 0x218, 
       0x217, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x3, 0x2, 0x2, 0x2, 0x219, 
       0x21c, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21b, 0x7, 0x3c, 0x2, 0x2, 0x21b, 
       0x21d, 0x5, 0x48, 0x25, 0x2, 0x21c, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21c, 
       0x21d, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x51, 0x3, 0x2, 0x2, 0x2, 0x21e, 
       0x21f, 0x7, 0x38, 0x2, 0x2, 0x21f, 0x224, 0x5, 0x48, 0x25, 0x2, 0x220, 
       0x221, 0x7, 0x3f, 0x2, 0x2, 0x221, 0x223, 0x5, 0x48, 0x25, 0x2, 0x222, 
       0x220, 0x3, 0x2, 0x2, 0x2, 0x223, 0x226, 0x3, 0x2, 0x2, 0x2, 0x224, 
       0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 0x225, 
       0x228, 0x3, 0x2, 0x2, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 0x227, 
       0x229, 0x7, 0x3f, 0x2, 0x2, 0x228, 0x227, 0x3, 0x2, 0x2, 0x2, 0x228, 
       0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22a, 
       0x22b, 0x7, 0x39, 0x2, 0x2, 0x22b, 0x53, 0x3, 0x2, 0x2, 0x2, 0x22c, 
       0x22f, 0x7, 0x38, 0x2, 0x2, 0x22d, 0x230, 0x5, 0x48, 0x25, 0x2, 0x22e, 
       0x230, 0x5, 0x54, 0x2b, 0x2, 0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22f, 
       0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x238, 0x3, 0x2, 0x2, 0x2, 0x231, 
       0x234, 0x7, 0x3f, 0x2, 0x2, 0x232, 0x235, 0x5, 0x48, 0x25, 0x2, 0x233, 
       0x235, 0x5, 0x54, 0x2b, 0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 
       0x233, 0x3, 0x2, 0x2, 0x2, 0x235, 0x237, 0x3, 0x2, 0x2, 0x2, 0x236, 
       0x231, 0x3, 0x2, 0x2, 0x2, 0x237, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x238, 
       0x236, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x3, 0x2, 0x2, 0x2, 0x239, 
       0x23c, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23b, 
       0x23d, 0x7, 0x3f, 0x2, 0x2, 0x23c, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23c, 
       0x23d, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23e, 
       0x23f, 0x7, 0x39, 0x2, 0x2, 0x23f, 0x55, 0x3, 0x2, 0x2, 0x2, 0x240, 
       0x253, 0x7, 0x36, 0x2, 0x2, 0x241, 0x254, 0x5, 0x52, 0x2a, 0x2, 0x242, 
       0x245, 0x5, 0x48, 0x25, 0x2, 0x243, 0x245, 0x5, 0x50, 0x29, 0x2, 
       0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x244, 0x243, 0x3, 0x2, 0x2, 0x2, 
       0x245, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x246, 0x249, 0x7, 0x3f, 0x2, 0x2, 
       0x247, 0x24a, 0x5, 0x48, 0x25, 0x2, 0x248, 0x24a, 0x5, 0x50, 0x29, 
       0x2, 0x249, 0x247, 0x3, 0x2, 0x2, 0x2, 0x249, 0x248, 0x3, 0x2, 0x2, 
       0x2, 0x24a, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x246, 0x3, 0x2, 0x2, 
       0x2, 0x24c, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24b, 0x3, 0x2, 0x2, 
       0x2, 0x24d, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x251, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x250, 0x252, 0x7, 0x3f, 0x2, 
       0x2, 0x251, 0x250, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x3, 0x2, 0x2, 
       0x2, 0x252, 0x254, 0x3, 0x2, 0x2, 0x2, 0x253, 0x241, 0x3, 0x2, 0x2, 
       0x2, 0x253, 0x244, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 
       0x2, 0x255, 0x256, 0x7, 0x37, 0x2, 0x2, 0x256, 0x57, 0x3, 0x2, 0x2, 
       0x2, 0x257, 0x25b, 0x7, 0x5b, 0x2, 0x2, 0x258, 0x25a, 0x5, 0x56, 
       0x2c, 0x2, 0x259, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25d, 0x3, 0x2, 
       0x2, 0x2, 0x25b, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 
       0x2, 0x2, 0x25c, 0x59, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25b, 0x3, 0x2, 
       0x2, 0x2, 0x25e, 0x25f, 0x7, 0x41, 0x2, 0x2, 0x25f, 0x260, 0x5, 0x5e, 
       0x30, 0x2, 0x260, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x261, 0x26f, 0x7, 0x2b, 
       0x2, 0x2, 0x262, 0x263, 0x7, 0x2c, 0x2, 0x2, 0x263, 0x264, 0x7, 0x3a, 
       0x2, 0x2, 0x264, 0x265, 0x5, 0x48, 0x25, 0x2, 0x265, 0x266, 0x7, 
       0x3b, 0x2, 0x2, 0x266, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x267, 0x26c, 0x9, 
       0x9, 0x2, 0x2, 0x268, 0x269, 0x7, 0x3a, 0x2, 0x2, 0x269, 0x26a, 0x5, 
       0x48, 0x25, 0x2, 0x26a, 0x26b, 0x7, 0x3b, 0x2, 0x2, 0x26b, 0x26d, 
       0x3, 0x2, 0x2, 0x2, 0x26c, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26d, 
       0x3, 0x2, 0x2, 0x2, 0x26d, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x261, 
       0x3, 0x2, 0x2, 0x2, 0x26e, 0x262, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x267, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 
       0x7, 0x4e, 0x2, 0x2, 0x271, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x272, 0x274, 
       0x7, 0x21, 0x2, 0x2, 0x273, 0x275, 0x5, 0x66, 0x34, 0x2, 0x274, 0x273, 
       0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x3, 0x2, 0x2, 0x2, 0x275, 0x291, 
       0x3, 0x2, 0x2, 0x2, 0x276, 0x278, 0x7, 0x22, 0x2, 0x2, 0x277, 0x279, 
       0x5, 0x66, 0x34, 0x2, 0x278, 0x277, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 
       0x3, 0x2, 0x2, 0x2, 0x279, 0x291, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27c, 
       0x7, 0x23, 0x2, 0x2, 0x27b, 0x27d, 0x5, 0x66, 0x34, 0x2, 0x27c, 0x27b, 
       0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x291, 
       0x3, 0x2, 0x2, 0x2, 0x27e, 0x280, 0x7, 0x24, 0x2, 0x2, 0x27f, 0x281, 
       0x5, 0x66, 0x34, 0x2, 0x280, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 
       0x3, 0x2, 0x2, 0x2, 0x281, 0x291, 0x3, 0x2, 0x2, 0x2, 0x282, 0x284, 
       0x7, 0x25, 0x2, 0x2, 0x283, 0x285, 0x5, 0x66, 0x34, 0x2, 0x284, 0x283, 
       0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x291, 
       0x3, 0x2, 0x2, 0x2, 0x286, 0x291, 0x7, 0x20, 0x2, 0x2, 0x287, 0x291, 
       0x7, 0x28, 0x2, 0x2, 0x288, 0x291, 0x7, 0x29, 0x2, 0x2, 0x289, 0x28e, 
       0x7, 0x26, 0x2, 0x2, 0x28a, 0x28b, 0x7, 0x36, 0x2, 0x2, 0x28b, 0x28c, 
       0x5, 0x5e, 0x30, 0x2, 0x28c, 0x28d, 0x7, 0x37, 0x2, 0x2, 0x28d, 0x28f, 
       0x3, 0x2, 0x2, 0x2, 0x28e, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 
       0x3, 0x2, 0x2, 0x2, 0x28f, 0x291, 0x3, 0x2, 0x2, 0x2, 0x290, 0x272, 
       0x3, 0x2, 0x2, 0x2, 0x290, 0x276, 0x3, 0x2, 0x2, 0x2, 0x290, 0x27a, 
       0x3, 0x2, 0x2, 0x2, 0x290, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x290, 0x282, 
       0x3, 0x2, 0x2, 0x2, 0x290, 0x286, 0x3, 0x2, 0x2, 0x2, 0x290, 0x287, 
       0x3, 0x2, 0x2, 0x2, 0x290, 0x288, 0x3, 0x2, 0x2, 0x2, 0x290, 0x289, 
       0x3, 0x2, 0x2, 0x2, 0x291, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x292, 0x294, 
       0x7, 0x1e, 0x2, 0x2, 0x293, 0x295, 0x5, 0x66, 0x34, 0x2, 0x294, 0x293, 
       0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 0x2, 0x2, 0x2, 0x295, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x7, 0x27, 0x2, 0x2, 0x297, 0x298, 
       0x7, 0x36, 0x2, 0x2, 0x298, 0x299, 0x5, 0x5e, 0x30, 0x2, 0x299, 0x29a, 
       0x7, 0x3f, 0x2, 0x2, 0x29a, 0x29b, 0x5, 0x7a, 0x3e, 0x2, 0x29b, 0x29c, 
       0x7, 0x37, 0x2, 0x2, 0x29c, 0x63, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 
       0x9, 0xa, 0x2, 0x2, 0x29e, 0x29f, 0x7, 0x27, 0x2, 0x2, 0x29f, 0x2a0, 
       0x7, 0x36, 0x2, 0x2, 0x2a0, 0x2a1, 0x5, 0x5e, 0x30, 0x2, 0x2a1, 0x2a6, 
       0x7, 0x3f, 0x2, 0x2, 0x2a2, 0x2a7, 0x5, 0x7a, 0x3e, 0x2, 0x2a3, 0x2a4, 
       0x7, 0x2f, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0x40, 0x2, 0x2, 0x2a5, 0x2a7, 
       0x5, 0x48, 0x25, 0x2, 0x2a6, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a3, 
       0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 
       0x7, 0x37, 0x2, 0x2, 0x2a9, 0x65, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 
       0x7, 0x36, 0x2, 0x2, 0x2ab, 0x2ac, 0x5, 0x48, 0x25, 0x2, 0x2ac, 0x2ad, 
       0x7, 0x37, 0x2, 0x2, 0x2ad, 0x67, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 
       0x9, 0xb, 0x2, 0x2, 0x2af, 0x69, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b3, 
       0x5, 0x48, 0x25, 0x2, 0x2b1, 0x2b3, 0x5, 0x72, 0x3a, 0x2, 0x2b2, 
       0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b3, 
       0x6b, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x9, 0xc, 0x2, 0x2, 0x2b5, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b9, 0x5, 0x58, 0x2d, 0x2, 0x2b7, 
       0x2b9, 0x7, 0x5c, 0x2, 0x2, 0x2b8, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b8, 
       0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x2ba, 
       0x2c1, 0x5, 0x5e, 0x30, 0x2, 0x2bb, 0x2c1, 0x5, 0x64, 0x33, 0x2, 
       0x2bc, 0x2be, 0x7, 0x1f, 0x2, 0x2, 0x2bd, 0x2bf, 0x5, 0x66, 0x34, 
       0x2, 0x2be, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x3, 0x2, 0x2, 
       0x2, 0x2bf, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2ba, 0x3, 0x2, 0x2, 
       0x2, 0x2c0, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2bc, 0x3, 0x2, 0x2, 
       0x2, 0x2c1, 0x71, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c3, 0x5, 0x5e, 0x30, 
       0x2, 0x2c3, 0x2c4, 0x7, 0x5b, 0x2, 0x2, 0x2c4, 0x2d1, 0x3, 0x2, 0x2, 
       0x2, 0x2c5, 0x2c6, 0x5, 0x60, 0x31, 0x2, 0x2c6, 0x2c7, 0x7, 0x5b, 
       0x2, 0x2, 0x2c7, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x9, 0x3, 
       0x2, 0x2, 0x2c9, 0x2cb, 0x7, 0x5b, 0x2, 0x2, 0x2ca, 0x2cc, 0x5, 0x66, 
       0x34, 0x2, 0x2cb, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x3, 0x2, 
       0x2, 0x2, 0x2cc, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 0x5, 0x64, 
       0x33, 0x2, 0x2ce, 0x2cf, 0x7, 0x5b, 0x2, 0x2, 0x2cf, 0x2d1, 0x3, 
       0x2, 0x2, 0x2, 0x2d0, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2c5, 0x3, 
       0x2, 0x2, 0x2, 0x2d0, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2cd, 0x3, 
       0x2, 0x2, 0x2, 0x2d1, 0x73, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d7, 0x5, 
       0x72, 0x3a, 0x2, 0x2d3, 0x2d4, 0x7, 0x3f, 0x2, 0x2, 0x2d4, 0x2d6, 
       0x5, 0x72, 0x3a, 0x2, 0x2d5, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d9, 
       0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 
       0x3, 0x2, 0x2, 0x2, 0x2da, 0x2dc, 0x7, 0x3f, 0x2, 0x2, 0x2db, 0x2da, 
       0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x75, 
       0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2e2, 0x5, 0x6a, 0x36, 0x2, 0x2de, 0x2df, 
       0x7, 0x3f, 0x2, 0x2, 0x2df, 0x2e1, 0x5, 0x6a, 0x36, 0x2, 0x2e0, 0x2de, 
       0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e0, 
       0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e6, 
       0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e7, 
       0x7, 0x3f, 0x2, 0x2, 0x2e6, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 
       0x3, 0x2, 0x2, 0x2, 0x2e7, 0x77, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2ed, 
       0x5, 0x6c, 0x37, 0x2, 0x2e9, 0x2ea, 0x7, 0x3f, 0x2, 0x2, 0x2ea, 0x2ec, 
       0x5, 0x6c, 0x37, 0x2, 0x2eb, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ef, 
       0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ee, 
       0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2ed, 
       0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 0x7, 0x3f, 0x2, 0x2, 0x2f1, 0x2f0, 
       0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x79, 
       0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f8, 0x5, 0x48, 0x25, 0x2, 0x2f4, 0x2f5, 
       0x7, 0x3f, 0x2, 0x2, 0x2f5, 0x2f7, 0x5, 0x48, 0x25, 0x2, 0x2f6, 0x2f4, 
       0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f6, 
       0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fc, 
       0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fd, 
       0x7, 0x3f, 0x2, 0x2, 0x2fc, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 
       0x3, 0x2, 0x2, 0x2, 0x2fd, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x303, 
       0x7, 0x5b, 0x2, 0x2, 0x2ff, 0x300, 0x7, 0x3f, 0x2, 0x2, 0x300, 0x302, 
       0x7, 0x5b, 0x2, 0x2, 0x301, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x302, 0x305, 
       0x3, 0x2, 0x2, 0x2, 0x303, 0x301, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 
       0x3, 0x2, 0x2, 0x2, 0x304, 0x307, 0x3, 0x2, 0x2, 0x2, 0x305, 0x303, 
       0x3, 0x2, 0x2, 0x2, 0x306, 0x308, 0x7, 0x3f, 0x2, 0x2, 0x307, 0x306, 
       0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x3, 0x2, 0x2, 0x2, 0x308, 0x7d, 
       0x3, 0x2, 0x2, 0x2, 0x309, 0x30e, 0x5, 0x6e, 0x38, 0x2, 0x30a, 0x30b, 
       0x7, 0x3f, 0x2, 0x2, 0x30b, 0x30d, 0x5, 0x6e, 0x38, 0x2, 0x30c, 0x30a, 
       0x3, 0x2, 0x2, 0x2, 0x30d, 0x310, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30c, 
       0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x312, 
       0x3, 0x2, 0x2, 0x2, 0x310, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x311, 0x313, 
       0x7, 0x3f, 0x2, 0x2, 0x312, 0x311, 0x3, 0x2, 0x2, 0x2, 0x312, 0x313, 
       0x3, 0x2, 0x2, 0x2, 0x313, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x314, 0x319, 
       0x5, 0x70, 0x39, 0x2, 0x315, 0x316, 0x7, 0x3f, 0x2, 0x2, 0x316, 0x318, 
       0x5, 0x70, 0x39, 0x2, 0x317, 0x315, 0x3, 0x2, 0x2, 0x2, 0x318, 0x31b, 
       0x3, 0x2, 0x2, 0x2, 0x319, 0x317, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31a, 
       0x3, 0x2, 0x2, 0x2, 0x31a, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x319, 
       0x3, 0x2, 0x2, 0x2, 0x31c, 0x31e, 0x7, 0x3f, 0x2, 0x2, 0x31d, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x31d, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x81, 
       0x3, 0x2, 0x2, 0x2, 0x60, 0x83, 0x88, 0x95, 0xb4, 0xb6, 0xba, 0xc0, 
       0xca, 0xe7, 0xf2, 0xf7, 0x103, 0x109, 0x110, 0x117, 0x11d, 0x120, 
       0x123, 0x12b, 0x131, 0x134, 0x137, 0x13a, 0x13d, 0x142, 0x152, 0x157, 
       0x165, 0x16d, 0x179, 0x17d, 0x185, 0x189, 0x191, 0x194, 0x19d, 0x1a7, 
       0x1af, 0x1b2, 0x1b6, 0x1ba, 0x1c7, 0x1d5, 0x1d9, 0x1fe, 0x200, 0x208, 
       0x20e, 0x214, 0x218, 0x21c, 0x224, 0x228, 0x22f, 0x234, 0x238, 0x23c, 
       0x244, 0x249, 0x24d, 0x251, 0x253, 0x25b, 0x26c, 0x26e, 0x274, 0x278, 
       0x27c, 0x280, 0x284, 0x28e, 0x290, 0x294, 0x2a6, 0x2b2, 0x2b8, 0x2be, 
       0x2c0, 0x2cb, 0x2d0, 0x2d7, 0x2db, 0x2e2, 0x2e6, 0x2ed, 0x2f1, 0x2f8, 
       0x2fc, 0x303, 0x307, 0x30e, 0x312, 0x319, 0x31d, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

qasm3Parser::Initializer qasm3Parser::_init;
