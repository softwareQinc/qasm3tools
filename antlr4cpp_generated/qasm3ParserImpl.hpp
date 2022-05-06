
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

qasm3Parser::HeaderContext* qasm3Parser::ProgramContext::header() {
  return getRuleContext<qasm3Parser::HeaderContext>(0);
}

std::vector<qasm3Parser::GlobalStatementContext *> qasm3Parser::ProgramContext::globalStatement() {
  return getRuleContexts<qasm3Parser::GlobalStatementContext>();
}

qasm3Parser::GlobalStatementContext* qasm3Parser::ProgramContext::globalStatement(size_t i) {
  return getRuleContext<qasm3Parser::GlobalStatementContext>(i);
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
    setState(208);
    header();
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::PRAGMA)
      | (1ULL << qasm3Parser::DEFCALGRAMMAR)
      | (1ULL << qasm3Parser::DEF)
      | (1ULL << qasm3Parser::DEFCAL)
      | (1ULL << qasm3Parser::GATE)
      | (1ULL << qasm3Parser::EXTERN)
      | (1ULL << qasm3Parser::BOX)
      | (1ULL << qasm3Parser::LET)
      | (1ULL << qasm3Parser::IF)
      | (1ULL << qasm3Parser::END)
      | (1ULL << qasm3Parser::FOR)
      | (1ULL << qasm3Parser::WHILE)
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
      | (1ULL << qasm3Parser::U_)
      | (1ULL << qasm3Parser::CX)
      | (1ULL << qasm3Parser::GPHASE)
      | (1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL)
      | (1ULL << qasm3Parser::SIZEOF)
      | (1ULL << qasm3Parser::BuiltinMath)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::BuiltinTimingInstruction)
      | (1ULL << qasm3Parser::RESET)
      | (1ULL << qasm3Parser::MEASURE)
      | (1ULL << qasm3Parser::BARRIER)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
      | (1ULL << (qasm3Parser::Constant - 67))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::Identifier - 67))
      | (1ULL << (qasm3Parser::FloatLiteral - 67))
      | (1ULL << (qasm3Parser::TimingLiteral - 67))
      | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
      setState(211);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::PRAGMA:
        case qasm3Parser::DEFCALGRAMMAR:
        case qasm3Parser::DEF:
        case qasm3Parser::DEFCAL:
        case qasm3Parser::GATE:
        case qasm3Parser::EXTERN:
        case qasm3Parser::QREG:
        case qasm3Parser::QUBIT: {
          setState(209);
          globalStatement();
          break;
        }

        case qasm3Parser::BOX:
        case qasm3Parser::LET:
        case qasm3Parser::IF:
        case qasm3Parser::END:
        case qasm3Parser::FOR:
        case qasm3Parser::WHILE:
        case qasm3Parser::CONST:
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
        case qasm3Parser::U_:
        case qasm3Parser::CX:
        case qasm3Parser::GPHASE:
        case qasm3Parser::INV:
        case qasm3Parser::POW:
        case qasm3Parser::CTRL:
        case qasm3Parser::NEGCTRL:
        case qasm3Parser::SIZEOF:
        case qasm3Parser::BuiltinMath:
        case qasm3Parser::DURATIONOF:
        case qasm3Parser::BuiltinTimingInstruction:
        case qasm3Parser::RESET:
        case qasm3Parser::MEASURE:
        case qasm3Parser::BARRIER:
        case qasm3Parser::BooleanLiteral:
        case qasm3Parser::LPAREN:
        case qasm3Parser::MINUS:
        case qasm3Parser::TILDE:
        case qasm3Parser::EXCLAMATION_POINT:
        case qasm3Parser::ImaginaryLiteral:
        case qasm3Parser::Constant:
        case qasm3Parser::BinaryIntegerLiteral:
        case qasm3Parser::OctalIntegerLiteral:
        case qasm3Parser::DecimalIntegerLiteral:
        case qasm3Parser::HexIntegerLiteral:
        case qasm3Parser::Identifier:
        case qasm3Parser::FloatLiteral:
        case qasm3Parser::TimingLiteral:
        case qasm3Parser::BitstringLiteral: {
          setState(210);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(215);
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

//----------------- HeaderContext ------------------------------------------------------------------

qasm3Parser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::VersionContext* qasm3Parser::HeaderContext::version() {
  return getRuleContext<qasm3Parser::VersionContext>(0);
}

std::vector<qasm3Parser::IncludeContext *> qasm3Parser::HeaderContext::include() {
  return getRuleContexts<qasm3Parser::IncludeContext>();
}

qasm3Parser::IncludeContext* qasm3Parser::HeaderContext::include(size_t i) {
  return getRuleContext<qasm3Parser::IncludeContext>(i);
}

std::vector<qasm3Parser::IoContext *> qasm3Parser::HeaderContext::io() {
  return getRuleContexts<qasm3Parser::IoContext>();
}

qasm3Parser::IoContext* qasm3Parser::HeaderContext::io(size_t i) {
  return getRuleContext<qasm3Parser::IoContext>(i);
}


size_t qasm3Parser::HeaderContext::getRuleIndex() const {
  return qasm3Parser::RuleHeader;
}


antlrcpp::Any qasm3Parser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::HeaderContext* qasm3Parser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, qasm3Parser::RuleHeader);
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
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::OPENQASM) {
      setState(216);
      version();
    }
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::INCLUDE) {
      setState(219);
      include();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(228);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::INPUT

    || _la == qasm3Parser::OUTPUT) {
      setState(225);
      io();
      setState(230);
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

//----------------- VersionContext ------------------------------------------------------------------

qasm3Parser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::VersionContext::OPENQASM() {
  return getToken(qasm3Parser::OPENQASM, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::DecimalIntegerLiteral() {
  return getToken(qasm3Parser::DecimalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::FloatLiteral() {
  return getToken(qasm3Parser::FloatLiteral, 0);
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
  enterRule(_localctx, 4, qasm3Parser::RuleVersion);
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
    setState(231);
    match(qasm3Parser::OPENQASM);
    setState(232);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::DecimalIntegerLiteral

    || _la == qasm3Parser::FloatLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(233);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

qasm3Parser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IncludeContext::INCLUDE() {
  return getToken(qasm3Parser::INCLUDE, 0);
}

tree::TerminalNode* qasm3Parser::IncludeContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::IncludeContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::IncludeContext::getRuleIndex() const {
  return qasm3Parser::RuleInclude;
}


antlrcpp::Any qasm3Parser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IncludeContext* qasm3Parser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 6, qasm3Parser::RuleInclude);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(qasm3Parser::INCLUDE);
    setState(236);
    match(qasm3Parser::StringLiteral);
    setState(237);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoIdentifierContext ------------------------------------------------------------------

qasm3Parser::IoIdentifierContext::IoIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IoIdentifierContext::INPUT() {
  return getToken(qasm3Parser::INPUT, 0);
}

tree::TerminalNode* qasm3Parser::IoIdentifierContext::OUTPUT() {
  return getToken(qasm3Parser::OUTPUT, 0);
}


size_t qasm3Parser::IoIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleIoIdentifier;
}


antlrcpp::Any qasm3Parser::IoIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIoIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IoIdentifierContext* qasm3Parser::ioIdentifier() {
  IoIdentifierContext *_localctx = _tracker.createInstance<IoIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 8, qasm3Parser::RuleIoIdentifier);
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
    setState(239);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::INPUT

    || _la == qasm3Parser::OUTPUT)) {
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

//----------------- IoContext ------------------------------------------------------------------

qasm3Parser::IoContext::IoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IoIdentifierContext* qasm3Parser::IoContext::ioIdentifier() {
  return getRuleContext<qasm3Parser::IoIdentifierContext>(0);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::IoContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::IoContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::IoContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::IoContext::getRuleIndex() const {
  return qasm3Parser::RuleIo;
}


antlrcpp::Any qasm3Parser::IoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIo(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IoContext* qasm3Parser::io() {
  IoContext *_localctx = _tracker.createInstance<IoContext>(_ctx, getState());
  enterRule(_localctx, 10, qasm3Parser::RuleIo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    ioIdentifier();
    setState(242);
    classicalType();
    setState(243);
    match(qasm3Parser::Identifier);
    setState(244);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalStatementContext ------------------------------------------------------------------

qasm3Parser::GlobalStatementContext::GlobalStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SubroutineDefinitionContext* qasm3Parser::GlobalStatementContext::subroutineDefinition() {
  return getRuleContext<qasm3Parser::SubroutineDefinitionContext>(0);
}

qasm3Parser::ExternDeclarationContext* qasm3Parser::GlobalStatementContext::externDeclaration() {
  return getRuleContext<qasm3Parser::ExternDeclarationContext>(0);
}

qasm3Parser::QuantumGateDefinitionContext* qasm3Parser::GlobalStatementContext::quantumGateDefinition() {
  return getRuleContext<qasm3Parser::QuantumGateDefinitionContext>(0);
}

qasm3Parser::CalibrationContext* qasm3Parser::GlobalStatementContext::calibration() {
  return getRuleContext<qasm3Parser::CalibrationContext>(0);
}

qasm3Parser::QuantumDeclarationStatementContext* qasm3Parser::GlobalStatementContext::quantumDeclarationStatement() {
  return getRuleContext<qasm3Parser::QuantumDeclarationStatementContext>(0);
}

qasm3Parser::PragmaContext* qasm3Parser::GlobalStatementContext::pragma() {
  return getRuleContext<qasm3Parser::PragmaContext>(0);
}


size_t qasm3Parser::GlobalStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleGlobalStatement;
}


antlrcpp::Any qasm3Parser::GlobalStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitGlobalStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::GlobalStatementContext* qasm3Parser::globalStatement() {
  GlobalStatementContext *_localctx = _tracker.createInstance<GlobalStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, qasm3Parser::RuleGlobalStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::DEF: {
        enterOuterAlt(_localctx, 1);
        setState(246);
        subroutineDefinition();
        break;
      }

      case qasm3Parser::EXTERN: {
        enterOuterAlt(_localctx, 2);
        setState(247);
        externDeclaration();
        break;
      }

      case qasm3Parser::GATE: {
        enterOuterAlt(_localctx, 3);
        setState(248);
        quantumGateDefinition();
        break;
      }

      case qasm3Parser::DEFCALGRAMMAR:
      case qasm3Parser::DEFCAL: {
        enterOuterAlt(_localctx, 4);
        setState(249);
        calibration();
        break;
      }

      case qasm3Parser::QREG:
      case qasm3Parser::QUBIT: {
        enterOuterAlt(_localctx, 5);
        setState(250);
        quantumDeclarationStatement();
        break;
      }

      case qasm3Parser::PRAGMA: {
        enterOuterAlt(_localctx, 6);
        setState(251);
        pragma();
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

//----------------- StatementContext ------------------------------------------------------------------

qasm3Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::StatementContext::expressionStatement() {
  return getRuleContext<qasm3Parser::ExpressionStatementContext>(0);
}

qasm3Parser::AssignmentStatementContext* qasm3Parser::StatementContext::assignmentStatement() {
  return getRuleContext<qasm3Parser::AssignmentStatementContext>(0);
}

qasm3Parser::ClassicalDeclarationStatementContext* qasm3Parser::StatementContext::classicalDeclarationStatement() {
  return getRuleContext<qasm3Parser::ClassicalDeclarationStatementContext>(0);
}

qasm3Parser::BranchingStatementContext* qasm3Parser::StatementContext::branchingStatement() {
  return getRuleContext<qasm3Parser::BranchingStatementContext>(0);
}

qasm3Parser::LoopStatementContext* qasm3Parser::StatementContext::loopStatement() {
  return getRuleContext<qasm3Parser::LoopStatementContext>(0);
}

qasm3Parser::EndStatementContext* qasm3Parser::StatementContext::endStatement() {
  return getRuleContext<qasm3Parser::EndStatementContext>(0);
}

qasm3Parser::AliasStatementContext* qasm3Parser::StatementContext::aliasStatement() {
  return getRuleContext<qasm3Parser::AliasStatementContext>(0);
}

qasm3Parser::QuantumStatementContext* qasm3Parser::StatementContext::quantumStatement() {
  return getRuleContext<qasm3Parser::QuantumStatementContext>(0);
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
  enterRule(_localctx, 14, qasm3Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(254);
      expressionStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(255);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(256);
      classicalDeclarationStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(257);
      branchingStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(258);
      loopStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(259);
      endStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(260);
      aliasStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(261);
      quantumStatement();
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

//----------------- QuantumDeclarationStatementContext ------------------------------------------------------------------

qasm3Parser::QuantumDeclarationStatementContext::QuantumDeclarationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumDeclarationContext* qasm3Parser::QuantumDeclarationStatementContext::quantumDeclaration() {
  return getRuleContext<qasm3Parser::QuantumDeclarationContext>(0);
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
  enterRule(_localctx, 16, qasm3Parser::RuleQuantumDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    quantumDeclaration();
    setState(265);
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

tree::TerminalNode* qasm3Parser::ClassicalDeclarationStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ClassicalDeclarationContext* qasm3Parser::ClassicalDeclarationStatementContext::classicalDeclaration() {
  return getRuleContext<qasm3Parser::ClassicalDeclarationContext>(0);
}

qasm3Parser::ConstantDeclarationContext* qasm3Parser::ClassicalDeclarationStatementContext::constantDeclaration() {
  return getRuleContext<qasm3Parser::ConstantDeclarationContext>(0);
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
  enterRule(_localctx, 18, qasm3Parser::RuleClassicalDeclarationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case qasm3Parser::STRETCH: {
        setState(267);
        classicalDeclaration();
        break;
      }

      case qasm3Parser::CONST: {
        setState(268);
        constantDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(271);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalAssignmentContext ------------------------------------------------------------------

qasm3Parser::ClassicalAssignmentContext::ClassicalAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::ClassicalAssignmentContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}

qasm3Parser::AssignmentOperatorContext* qasm3Parser::ClassicalAssignmentContext::assignmentOperator() {
  return getRuleContext<qasm3Parser::AssignmentOperatorContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ClassicalAssignmentContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ClassicalAssignmentContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalAssignment;
}


antlrcpp::Any qasm3Parser::ClassicalAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalAssignmentContext* qasm3Parser::classicalAssignment() {
  ClassicalAssignmentContext *_localctx = _tracker.createInstance<ClassicalAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, qasm3Parser::RuleClassicalAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    indexedIdentifier();
    setState(274);
    assignmentOperator();
    setState(275);
    expression(0);
   
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

tree::TerminalNode* qasm3Parser::AssignmentStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ClassicalAssignmentContext* qasm3Parser::AssignmentStatementContext::classicalAssignment() {
  return getRuleContext<qasm3Parser::ClassicalAssignmentContext>(0);
}

qasm3Parser::QuantumMeasurementAssignmentContext* qasm3Parser::AssignmentStatementContext::quantumMeasurementAssignment() {
  return getRuleContext<qasm3Parser::QuantumMeasurementAssignmentContext>(0);
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
  enterRule(_localctx, 22, qasm3Parser::RuleAssignmentStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(277);
      classicalAssignment();
      break;
    }

    case 2: {
      setState(278);
      quantumMeasurementAssignment();
      break;
    }

    default:
      break;
    }
    setState(281);
    match(qasm3Parser::SEMICOLON);
   
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

qasm3Parser::ClassicalTypeContext* qasm3Parser::ReturnSignatureContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
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
  enterRule(_localctx, 24, qasm3Parser::RuleReturnSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(qasm3Parser::ARROW);
    setState(284);
    classicalType();
   
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
  enterRule(_localctx, 26, qasm3Parser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(qasm3Parser::LBRACKET);
    setState(287);
    expression(0);
    setState(288);
    match(qasm3Parser::RBRACKET);
   
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
  enterRule(_localctx, 28, qasm3Parser::RuleIdentifierList);
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
    setState(290);
    match(qasm3Parser::Identifier);
    setState(295);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(291);
      match(qasm3Parser::COMMA);
      setState(292);
      match(qasm3Parser::Identifier);
      setState(297);
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

//----------------- QuantumDeclarationContext ------------------------------------------------------------------

qasm3Parser::QuantumDeclarationContext::QuantumDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationContext::QREG() {
  return getToken(qasm3Parser::QREG, 0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QuantumDeclarationContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumDeclarationContext::QUBIT() {
  return getToken(qasm3Parser::QUBIT, 0);
}


size_t qasm3Parser::QuantumDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumDeclaration;
}


antlrcpp::Any qasm3Parser::QuantumDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumDeclarationContext* qasm3Parser::quantumDeclaration() {
  QuantumDeclarationContext *_localctx = _tracker.createInstance<QuantumDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, qasm3Parser::RuleQuantumDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::QREG: {
        enterOuterAlt(_localctx, 1);
        setState(298);
        match(qasm3Parser::QREG);
        setState(299);
        match(qasm3Parser::Identifier);
        setState(301);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(300);
          designator();
        }
        break;
      }

      case qasm3Parser::QUBIT: {
        enterOuterAlt(_localctx, 2);
        setState(303);
        match(qasm3Parser::QUBIT);
        setState(305);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(304);
          designator();
        }
        setState(307);
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

//----------------- QuantumArgumentContext ------------------------------------------------------------------

qasm3Parser::QuantumArgumentContext::QuantumArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumArgumentContext::QREG() {
  return getToken(qasm3Parser::QREG, 0);
}

tree::TerminalNode* qasm3Parser::QuantumArgumentContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QuantumArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumArgumentContext::QUBIT() {
  return getToken(qasm3Parser::QUBIT, 0);
}


size_t qasm3Parser::QuantumArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumArgument;
}


antlrcpp::Any qasm3Parser::QuantumArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumArgumentContext* qasm3Parser::quantumArgument() {
  QuantumArgumentContext *_localctx = _tracker.createInstance<QuantumArgumentContext>(_ctx, getState());
  enterRule(_localctx, 32, qasm3Parser::RuleQuantumArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::QREG: {
        enterOuterAlt(_localctx, 1);
        setState(310);
        match(qasm3Parser::QREG);
        setState(311);
        match(qasm3Parser::Identifier);
        setState(313);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(312);
          designator();
        }
        break;
      }

      case qasm3Parser::QUBIT: {
        enterOuterAlt(_localctx, 2);
        setState(315);
        match(qasm3Parser::QUBIT);
        setState(317);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(316);
          designator();
        }
        setState(319);
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

//----------------- BitTypeContext ------------------------------------------------------------------

qasm3Parser::BitTypeContext::BitTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BitTypeContext::BIT() {
  return getToken(qasm3Parser::BIT, 0);
}

tree::TerminalNode* qasm3Parser::BitTypeContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::BitTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::BitTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleBitType;
}


antlrcpp::Any qasm3Parser::BitTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BitTypeContext* qasm3Parser::bitType() {
  BitTypeContext *_localctx = _tracker.createInstance<BitTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, qasm3Parser::RuleBitType);
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
    setState(322);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::CREG

    || _la == qasm3Parser::BIT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(324);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(323);
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

//----------------- SingleDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::SingleDesignatorTypeContext::SingleDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SingleDesignatorTypeContext::INT() {
  return getToken(qasm3Parser::INT, 0);
}

tree::TerminalNode* qasm3Parser::SingleDesignatorTypeContext::UINT() {
  return getToken(qasm3Parser::UINT, 0);
}

tree::TerminalNode* qasm3Parser::SingleDesignatorTypeContext::FLOAT() {
  return getToken(qasm3Parser::FLOAT, 0);
}

tree::TerminalNode* qasm3Parser::SingleDesignatorTypeContext::ANGLE() {
  return getToken(qasm3Parser::ANGLE, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::SingleDesignatorTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::SingleDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleSingleDesignatorType;
}


antlrcpp::Any qasm3Parser::SingleDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSingleDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::singleDesignatorType() {
  SingleDesignatorTypeContext *_localctx = _tracker.createInstance<SingleDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, qasm3Parser::RuleSingleDesignatorType);
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
    setState(326);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::INT)
      | (1ULL << qasm3Parser::UINT)
      | (1ULL << qasm3Parser::FLOAT)
      | (1ULL << qasm3Parser::ANGLE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(327);
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

//----------------- NoDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::NoDesignatorTypeContext::NoDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::NoDesignatorTypeContext::BOOL() {
  return getToken(qasm3Parser::BOOL, 0);
}

tree::TerminalNode* qasm3Parser::NoDesignatorTypeContext::DURATION() {
  return getToken(qasm3Parser::DURATION, 0);
}

tree::TerminalNode* qasm3Parser::NoDesignatorTypeContext::STRETCH() {
  return getToken(qasm3Parser::STRETCH, 0);
}


size_t qasm3Parser::NoDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleNoDesignatorType;
}


antlrcpp::Any qasm3Parser::NoDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitNoDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::noDesignatorType() {
  NoDesignatorTypeContext *_localctx = _tracker.createInstance<NoDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, qasm3Parser::RuleNoDesignatorType);
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
    setState(330);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::BOOL)
      | (1ULL << qasm3Parser::DURATION)
      | (1ULL << qasm3Parser::STRETCH))) != 0))) {
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

//----------------- NonArrayTypeContext ------------------------------------------------------------------

qasm3Parser::NonArrayTypeContext::NonArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::NonArrayTypeContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::NonArrayTypeContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
}

qasm3Parser::BitTypeContext* qasm3Parser::NonArrayTypeContext::bitType() {
  return getRuleContext<qasm3Parser::BitTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::NonArrayTypeContext::COMPLEX() {
  return getToken(qasm3Parser::COMPLEX, 0);
}

tree::TerminalNode* qasm3Parser::NonArrayTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::NumericTypeContext* qasm3Parser::NonArrayTypeContext::numericType() {
  return getRuleContext<qasm3Parser::NumericTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::NonArrayTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::NonArrayTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleNonArrayType;
}


antlrcpp::Any qasm3Parser::NonArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitNonArrayType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NonArrayTypeContext* qasm3Parser::nonArrayType() {
  NonArrayTypeContext *_localctx = _tracker.createInstance<NonArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, qasm3Parser::RuleNonArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(340);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE: {
        enterOuterAlt(_localctx, 1);
        setState(332);
        singleDesignatorType();
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 2);
        setState(333);
        noDesignatorType();
        break;
      }

      case qasm3Parser::CREG:
      case qasm3Parser::BIT: {
        enterOuterAlt(_localctx, 3);
        setState(334);
        bitType();
        break;
      }

      case qasm3Parser::COMPLEX: {
        enterOuterAlt(_localctx, 4);
        setState(335);
        match(qasm3Parser::COMPLEX);
        setState(336);
        match(qasm3Parser::LBRACKET);
        setState(337);
        numericType();
        setState(338);
        match(qasm3Parser::RBRACKET);
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

qasm3Parser::NonArrayTypeContext* qasm3Parser::ArrayTypeContext::nonArrayType() {
  return getRuleContext<qasm3Parser::NonArrayTypeContext>(0);
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
  enterRule(_localctx, 42, qasm3Parser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(qasm3Parser::ARRAY);
    setState(343);
    match(qasm3Parser::LBRACKET);
    setState(344);
    nonArrayType();
    setState(345);
    match(qasm3Parser::COMMA);
    setState(346);
    expressionList();
    setState(347);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayReferenceTypeDimensionSpecifierContext ------------------------------------------------------------------

qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::ArrayReferenceTypeDimensionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionListContext* qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::DIM() {
  return getToken(qasm3Parser::DIM, 0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayReferenceTypeDimensionSpecifier;
}


antlrcpp::Any qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayReferenceTypeDimensionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext* qasm3Parser::arrayReferenceTypeDimensionSpecifier() {
  ArrayReferenceTypeDimensionSpecifierContext *_localctx = _tracker.createInstance<ArrayReferenceTypeDimensionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 44, qasm3Parser::RuleArrayReferenceTypeDimensionSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(353);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case qasm3Parser::SIZEOF:
      case qasm3Parser::BuiltinMath:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::Constant:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(349);
        expressionList();
        break;
      }

      case qasm3Parser::DIM: {
        enterOuterAlt(_localctx, 2);
        setState(350);
        match(qasm3Parser::DIM);
        setState(351);
        match(qasm3Parser::EQUALS);
        setState(352);
        expression(0);
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

qasm3Parser::NonArrayTypeContext* qasm3Parser::ArrayReferenceTypeContext::nonArrayType() {
  return getRuleContext<qasm3Parser::NonArrayTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::COMMA() {
  return getToken(qasm3Parser::COMMA, 0);
}

qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext* qasm3Parser::ArrayReferenceTypeContext::arrayReferenceTypeDimensionSpecifier() {
  return getRuleContext<qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayReferenceTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
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
  enterRule(_localctx, 46, qasm3Parser::RuleArrayReferenceType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    match(qasm3Parser::ARRAY);
    setState(356);
    match(qasm3Parser::LBRACKET);
    setState(357);
    nonArrayType();
    setState(358);
    match(qasm3Parser::COMMA);
    setState(359);
    arrayReferenceTypeDimensionSpecifier();
    setState(360);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalTypeContext ------------------------------------------------------------------

qasm3Parser::ClassicalTypeContext::ClassicalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::NonArrayTypeContext* qasm3Parser::ClassicalTypeContext::nonArrayType() {
  return getRuleContext<qasm3Parser::NonArrayTypeContext>(0);
}

qasm3Parser::ArrayTypeContext* qasm3Parser::ClassicalTypeContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}


size_t qasm3Parser::ClassicalTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalType;
}


antlrcpp::Any qasm3Parser::ClassicalTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::classicalType() {
  ClassicalTypeContext *_localctx = _tracker.createInstance<ClassicalTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, qasm3Parser::RuleClassicalType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(364);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::CREG:
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
        setState(362);
        nonArrayType();
        break;
      }

      case qasm3Parser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(363);
        arrayType();
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

//----------------- NumericTypeContext ------------------------------------------------------------------

qasm3Parser::NumericTypeContext::NumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::NumericTypeContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}


size_t qasm3Parser::NumericTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleNumericType;
}


antlrcpp::Any qasm3Parser::NumericTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitNumericType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NumericTypeContext* qasm3Parser::numericType() {
  NumericTypeContext *_localctx = _tracker.createInstance<NumericTypeContext>(_ctx, getState());
  enterRule(_localctx, 50, qasm3Parser::RuleNumericType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(366);
    singleDesignatorType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantDeclarationContext ------------------------------------------------------------------

qasm3Parser::ConstantDeclarationContext::ConstantDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ConstantDeclarationContext::CONST() {
  return getToken(qasm3Parser::CONST, 0);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::ConstantDeclarationContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ConstantDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::ConstantDeclarationContext::equalsExpression() {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(0);
}


size_t qasm3Parser::ConstantDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleConstantDeclaration;
}


antlrcpp::Any qasm3Parser::ConstantDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitConstantDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ConstantDeclarationContext* qasm3Parser::constantDeclaration() {
  ConstantDeclarationContext *_localctx = _tracker.createInstance<ConstantDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 52, qasm3Parser::RuleConstantDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(qasm3Parser::CONST);
    setState(369);
    classicalType();
    setState(370);
    match(qasm3Parser::Identifier);
    setState(371);
    equalsExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleDesignatorDeclarationContext ------------------------------------------------------------------

qasm3Parser::SingleDesignatorDeclarationContext::SingleDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::SingleDesignatorDeclarationContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::SingleDesignatorDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::SingleDesignatorDeclarationContext::equalsExpression() {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(0);
}


size_t qasm3Parser::SingleDesignatorDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleSingleDesignatorDeclaration;
}


antlrcpp::Any qasm3Parser::SingleDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSingleDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SingleDesignatorDeclarationContext* qasm3Parser::singleDesignatorDeclaration() {
  SingleDesignatorDeclarationContext *_localctx = _tracker.createInstance<SingleDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, qasm3Parser::RuleSingleDesignatorDeclaration);
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
    setState(373);
    singleDesignatorType();
    setState(374);
    match(qasm3Parser::Identifier);
    setState(376);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(375);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoDesignatorDeclarationContext ------------------------------------------------------------------

qasm3Parser::NoDesignatorDeclarationContext::NoDesignatorDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::NoDesignatorDeclarationContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::NoDesignatorDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::NoDesignatorDeclarationContext::equalsExpression() {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(0);
}


size_t qasm3Parser::NoDesignatorDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleNoDesignatorDeclaration;
}


antlrcpp::Any qasm3Parser::NoDesignatorDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitNoDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NoDesignatorDeclarationContext* qasm3Parser::noDesignatorDeclaration() {
  NoDesignatorDeclarationContext *_localctx = _tracker.createInstance<NoDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, qasm3Parser::RuleNoDesignatorDeclaration);
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
    setState(378);
    noDesignatorType();
    setState(379);
    match(qasm3Parser::Identifier);
    setState(381);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(380);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BitDeclarationContext ------------------------------------------------------------------

qasm3Parser::BitDeclarationContext::BitDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BitDeclarationContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

tree::TerminalNode* qasm3Parser::BitDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::BitDeclarationContext::BIT() {
  return getToken(qasm3Parser::BIT, 0);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::BitDeclarationContext::equalsExpression() {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::BitDeclarationContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::BitDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleBitDeclaration;
}


antlrcpp::Any qasm3Parser::BitDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BitDeclarationContext* qasm3Parser::bitDeclaration() {
  BitDeclarationContext *_localctx = _tracker.createInstance<BitDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 58, qasm3Parser::RuleBitDeclaration);
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
    setState(393);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::CREG: {
        setState(383);
        match(qasm3Parser::CREG);
        setState(384);
        match(qasm3Parser::Identifier);
        setState(386);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(385);
          designator();
        }
        break;
      }

      case qasm3Parser::BIT: {
        setState(388);
        match(qasm3Parser::BIT);
        setState(390);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(389);
          designator();
        }
        setState(392);
        match(qasm3Parser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(396);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(395);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComplexDeclarationContext ------------------------------------------------------------------

qasm3Parser::ComplexDeclarationContext::ComplexDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ComplexDeclarationContext::COMPLEX() {
  return getToken(qasm3Parser::COMPLEX, 0);
}

tree::TerminalNode* qasm3Parser::ComplexDeclarationContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::NumericTypeContext* qasm3Parser::ComplexDeclarationContext::numericType() {
  return getRuleContext<qasm3Parser::NumericTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ComplexDeclarationContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::ComplexDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::ComplexDeclarationContext::equalsExpression() {
  return getRuleContext<qasm3Parser::EqualsExpressionContext>(0);
}


size_t qasm3Parser::ComplexDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleComplexDeclaration;
}


antlrcpp::Any qasm3Parser::ComplexDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitComplexDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ComplexDeclarationContext* qasm3Parser::complexDeclaration() {
  ComplexDeclarationContext *_localctx = _tracker.createInstance<ComplexDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 60, qasm3Parser::RuleComplexDeclaration);
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
    setState(398);
    match(qasm3Parser::COMPLEX);
    setState(399);
    match(qasm3Parser::LBRACKET);
    setState(400);
    numericType();
    setState(401);
    match(qasm3Parser::RBRACKET);
    setState(402);
    match(qasm3Parser::Identifier);
    setState(404);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(403);
      equalsExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitializerContext ------------------------------------------------------------------

qasm3Parser::ArrayInitializerContext::ArrayInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ArrayInitializerContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ArrayInitializerContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::ArrayInitializerContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayInitializerContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<qasm3Parser::ArrayInitializerContext *> qasm3Parser::ArrayInitializerContext::arrayInitializer() {
  return getRuleContexts<qasm3Parser::ArrayInitializerContext>();
}

qasm3Parser::ArrayInitializerContext* qasm3Parser::ArrayInitializerContext::arrayInitializer(size_t i) {
  return getRuleContext<qasm3Parser::ArrayInitializerContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ArrayInitializerContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ArrayInitializerContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ArrayInitializerContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayInitializer;
}


antlrcpp::Any qasm3Parser::ArrayInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayInitializer(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayInitializerContext* qasm3Parser::arrayInitializer() {
  ArrayInitializerContext *_localctx = _tracker.createInstance<ArrayInitializerContext>(_ctx, getState());
  enterRule(_localctx, 62, qasm3Parser::RuleArrayInitializer);
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
    setState(406);
    match(qasm3Parser::LBRACE);
    setState(409);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case qasm3Parser::SIZEOF:
      case qasm3Parser::BuiltinMath:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::Constant:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(407);
        expression(0);
        break;
      }

      case qasm3Parser::LBRACE: {
        setState(408);
        arrayInitializer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(418);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(411);
      match(qasm3Parser::COMMA);
      setState(414);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
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
        case qasm3Parser::SIZEOF:
        case qasm3Parser::BuiltinMath:
        case qasm3Parser::DURATIONOF:
        case qasm3Parser::BooleanLiteral:
        case qasm3Parser::LPAREN:
        case qasm3Parser::MINUS:
        case qasm3Parser::TILDE:
        case qasm3Parser::EXCLAMATION_POINT:
        case qasm3Parser::ImaginaryLiteral:
        case qasm3Parser::Constant:
        case qasm3Parser::BinaryIntegerLiteral:
        case qasm3Parser::OctalIntegerLiteral:
        case qasm3Parser::DecimalIntegerLiteral:
        case qasm3Parser::HexIntegerLiteral:
        case qasm3Parser::Identifier:
        case qasm3Parser::FloatLiteral:
        case qasm3Parser::TimingLiteral:
        case qasm3Parser::BitstringLiteral: {
          setState(412);
          expression(0);
          break;
        }

        case qasm3Parser::LBRACE: {
          setState(413);
          arrayInitializer();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(420);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(421);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

qasm3Parser::ArrayDeclarationContext::ArrayDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ArrayTypeContext* qasm3Parser::ArrayDeclarationContext::arrayType() {
  return getRuleContext<qasm3Parser::ArrayTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ArrayDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ArrayDeclarationContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::ArrayInitializerContext* qasm3Parser::ArrayDeclarationContext::arrayInitializer() {
  return getRuleContext<qasm3Parser::ArrayInitializerContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ArrayDeclarationContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::ArrayDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleArrayDeclaration;
}


antlrcpp::Any qasm3Parser::ArrayDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitArrayDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ArrayDeclarationContext* qasm3Parser::arrayDeclaration() {
  ArrayDeclarationContext *_localctx = _tracker.createInstance<ArrayDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 64, qasm3Parser::RuleArrayDeclaration);
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
    setState(423);
    arrayType();
    setState(424);
    match(qasm3Parser::Identifier);
    setState(430);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(425);
      match(qasm3Parser::EQUALS);
      setState(428);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::LBRACE: {
          setState(426);
          arrayInitializer();
          break;
        }

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
        case qasm3Parser::SIZEOF:
        case qasm3Parser::BuiltinMath:
        case qasm3Parser::DURATIONOF:
        case qasm3Parser::BooleanLiteral:
        case qasm3Parser::LPAREN:
        case qasm3Parser::MINUS:
        case qasm3Parser::TILDE:
        case qasm3Parser::EXCLAMATION_POINT:
        case qasm3Parser::ImaginaryLiteral:
        case qasm3Parser::Constant:
        case qasm3Parser::BinaryIntegerLiteral:
        case qasm3Parser::OctalIntegerLiteral:
        case qasm3Parser::DecimalIntegerLiteral:
        case qasm3Parser::HexIntegerLiteral:
        case qasm3Parser::Identifier:
        case qasm3Parser::FloatLiteral:
        case qasm3Parser::TimingLiteral:
        case qasm3Parser::BitstringLiteral: {
          setState(427);
          expression(0);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassicalDeclarationContext ------------------------------------------------------------------

qasm3Parser::ClassicalDeclarationContext::ClassicalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorDeclarationContext* qasm3Parser::ClassicalDeclarationContext::singleDesignatorDeclaration() {
  return getRuleContext<qasm3Parser::SingleDesignatorDeclarationContext>(0);
}

qasm3Parser::NoDesignatorDeclarationContext* qasm3Parser::ClassicalDeclarationContext::noDesignatorDeclaration() {
  return getRuleContext<qasm3Parser::NoDesignatorDeclarationContext>(0);
}

qasm3Parser::BitDeclarationContext* qasm3Parser::ClassicalDeclarationContext::bitDeclaration() {
  return getRuleContext<qasm3Parser::BitDeclarationContext>(0);
}

qasm3Parser::ComplexDeclarationContext* qasm3Parser::ClassicalDeclarationContext::complexDeclaration() {
  return getRuleContext<qasm3Parser::ComplexDeclarationContext>(0);
}

qasm3Parser::ArrayDeclarationContext* qasm3Parser::ClassicalDeclarationContext::arrayDeclaration() {
  return getRuleContext<qasm3Parser::ArrayDeclarationContext>(0);
}


size_t qasm3Parser::ClassicalDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalDeclaration;
}


antlrcpp::Any qasm3Parser::ClassicalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalDeclarationContext* qasm3Parser::classicalDeclaration() {
  ClassicalDeclarationContext *_localctx = _tracker.createInstance<ClassicalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 66, qasm3Parser::RuleClassicalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(437);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE: {
        enterOuterAlt(_localctx, 1);
        setState(432);
        singleDesignatorDeclaration();
        break;
      }

      case qasm3Parser::BOOL:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 2);
        setState(433);
        noDesignatorDeclaration();
        break;
      }

      case qasm3Parser::CREG:
      case qasm3Parser::BIT: {
        enterOuterAlt(_localctx, 3);
        setState(434);
        bitDeclaration();
        break;
      }

      case qasm3Parser::COMPLEX: {
        enterOuterAlt(_localctx, 4);
        setState(435);
        complexDeclaration();
        break;
      }

      case qasm3Parser::ARRAY: {
        enterOuterAlt(_localctx, 5);
        setState(436);
        arrayDeclaration();
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

//----------------- ClassicalTypeListContext ------------------------------------------------------------------

qasm3Parser::ClassicalTypeListContext::ClassicalTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ClassicalTypeContext *> qasm3Parser::ClassicalTypeListContext::classicalType() {
  return getRuleContexts<qasm3Parser::ClassicalTypeContext>();
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::ClassicalTypeListContext::classicalType(size_t i) {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ClassicalTypeListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ClassicalTypeListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ClassicalTypeListContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalTypeList;
}


antlrcpp::Any qasm3Parser::ClassicalTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalTypeList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalTypeListContext* qasm3Parser::classicalTypeList() {
  ClassicalTypeListContext *_localctx = _tracker.createInstance<ClassicalTypeListContext>(_ctx, getState());
  enterRule(_localctx, 68, qasm3Parser::RuleClassicalTypeList);
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
    setState(439);
    classicalType();
    setState(444);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(440);
      match(qasm3Parser::COMMA);
      setState(441);
      classicalType();
      setState(446);
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

//----------------- ClassicalArgumentContext ------------------------------------------------------------------

qasm3Parser::ClassicalArgumentContext::ClassicalArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::ClassicalArgumentContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::ClassicalArgumentContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::CREG() {
  return getToken(qasm3Parser::CREG, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ClassicalArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::BIT() {
  return getToken(qasm3Parser::BIT, 0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::COMPLEX() {
  return getToken(qasm3Parser::COMPLEX, 0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::NumericTypeContext* qasm3Parser::ClassicalArgumentContext::numericType() {
  return getRuleContext<qasm3Parser::NumericTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

qasm3Parser::ArrayReferenceTypeContext* qasm3Parser::ClassicalArgumentContext::arrayReferenceType() {
  return getRuleContext<qasm3Parser::ArrayReferenceTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::CONST() {
  return getToken(qasm3Parser::CONST, 0);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentContext::MUTABLE() {
  return getToken(qasm3Parser::MUTABLE, 0);
}


size_t qasm3Parser::ClassicalArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalArgument;
}


antlrcpp::Any qasm3Parser::ClassicalArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalArgumentContext* qasm3Parser::classicalArgument() {
  ClassicalArgumentContext *_localctx = _tracker.createInstance<ClassicalArgumentContext>(_ctx, getState());
  enterRule(_localctx, 70, qasm3Parser::RuleClassicalArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(473);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOOL:
      case qasm3Parser::INT:
      case qasm3Parser::UINT:
      case qasm3Parser::FLOAT:
      case qasm3Parser::ANGLE:
      case qasm3Parser::DURATION:
      case qasm3Parser::STRETCH: {
        enterOuterAlt(_localctx, 1);
        setState(449);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::INT:
          case qasm3Parser::UINT:
          case qasm3Parser::FLOAT:
          case qasm3Parser::ANGLE: {
            setState(447);
            singleDesignatorType();
            break;
          }

          case qasm3Parser::BOOL:
          case qasm3Parser::DURATION:
          case qasm3Parser::STRETCH: {
            setState(448);
            noDesignatorType();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(451);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::CREG: {
        enterOuterAlt(_localctx, 2);
        setState(453);
        match(qasm3Parser::CREG);
        setState(454);
        match(qasm3Parser::Identifier);
        setState(456);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(455);
          designator();
        }
        break;
      }

      case qasm3Parser::BIT: {
        enterOuterAlt(_localctx, 3);
        setState(458);
        match(qasm3Parser::BIT);
        setState(460);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(459);
          designator();
        }
        setState(462);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::COMPLEX: {
        enterOuterAlt(_localctx, 4);
        setState(463);
        match(qasm3Parser::COMPLEX);
        setState(464);
        match(qasm3Parser::LBRACKET);
        setState(465);
        numericType();
        setState(466);
        match(qasm3Parser::RBRACKET);
        setState(467);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::CONST:
      case qasm3Parser::MUTABLE: {
        enterOuterAlt(_localctx, 5);
        setState(469);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::CONST

        || _la == qasm3Parser::MUTABLE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(470);
        arrayReferenceType();
        setState(471);
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

//----------------- ClassicalArgumentListContext ------------------------------------------------------------------

qasm3Parser::ClassicalArgumentListContext::ClassicalArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ClassicalArgumentContext *> qasm3Parser::ClassicalArgumentListContext::classicalArgument() {
  return getRuleContexts<qasm3Parser::ClassicalArgumentContext>();
}

qasm3Parser::ClassicalArgumentContext* qasm3Parser::ClassicalArgumentListContext::classicalArgument(size_t i) {
  return getRuleContext<qasm3Parser::ClassicalArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::ClassicalArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::ClassicalArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::ClassicalArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalArgumentList;
}


antlrcpp::Any qasm3Parser::ClassicalArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitClassicalArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalArgumentListContext* qasm3Parser::classicalArgumentList() {
  ClassicalArgumentListContext *_localctx = _tracker.createInstance<ClassicalArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 72, qasm3Parser::RuleClassicalArgumentList);
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
    setState(475);
    classicalArgument();
    setState(480);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(476);
      match(qasm3Parser::COMMA);
      setState(477);
      classicalArgument();
      setState(482);
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

//----------------- AnyTypeArgumentContext ------------------------------------------------------------------

qasm3Parser::AnyTypeArgumentContext::AnyTypeArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ClassicalArgumentContext* qasm3Parser::AnyTypeArgumentContext::classicalArgument() {
  return getRuleContext<qasm3Parser::ClassicalArgumentContext>(0);
}

qasm3Parser::QuantumArgumentContext* qasm3Parser::AnyTypeArgumentContext::quantumArgument() {
  return getRuleContext<qasm3Parser::QuantumArgumentContext>(0);
}


size_t qasm3Parser::AnyTypeArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleAnyTypeArgument;
}


antlrcpp::Any qasm3Parser::AnyTypeArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAnyTypeArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AnyTypeArgumentContext* qasm3Parser::anyTypeArgument() {
  AnyTypeArgumentContext *_localctx = _tracker.createInstance<AnyTypeArgumentContext>(_ctx, getState());
  enterRule(_localctx, 74, qasm3Parser::RuleAnyTypeArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(485);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::CONST:
      case qasm3Parser::MUTABLE:
      case qasm3Parser::CREG:
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
        setState(483);
        classicalArgument();
        break;
      }

      case qasm3Parser::QREG:
      case qasm3Parser::QUBIT: {
        enterOuterAlt(_localctx, 2);
        setState(484);
        quantumArgument();
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

//----------------- AnyTypeArgumentListContext ------------------------------------------------------------------

qasm3Parser::AnyTypeArgumentListContext::AnyTypeArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::AnyTypeArgumentContext *> qasm3Parser::AnyTypeArgumentListContext::anyTypeArgument() {
  return getRuleContexts<qasm3Parser::AnyTypeArgumentContext>();
}

qasm3Parser::AnyTypeArgumentContext* qasm3Parser::AnyTypeArgumentListContext::anyTypeArgument(size_t i) {
  return getRuleContext<qasm3Parser::AnyTypeArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::AnyTypeArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::AnyTypeArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::AnyTypeArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleAnyTypeArgumentList;
}


antlrcpp::Any qasm3Parser::AnyTypeArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAnyTypeArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AnyTypeArgumentListContext* qasm3Parser::anyTypeArgumentList() {
  AnyTypeArgumentListContext *_localctx = _tracker.createInstance<AnyTypeArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 76, qasm3Parser::RuleAnyTypeArgumentList);
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
    setState(487);
    anyTypeArgument();
    setState(492);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(488);
      match(qasm3Parser::COMMA);
      setState(489);
      anyTypeArgument();
      setState(494);
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

//----------------- AliasInitializerContext ------------------------------------------------------------------

qasm3Parser::AliasInitializerContext::AliasInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::AliasInitializerContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::AliasInitializerContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::AliasInitializerContext::DOUBLE_PLUS() {
  return getTokens(qasm3Parser::DOUBLE_PLUS);
}

tree::TerminalNode* qasm3Parser::AliasInitializerContext::DOUBLE_PLUS(size_t i) {
  return getToken(qasm3Parser::DOUBLE_PLUS, i);
}


size_t qasm3Parser::AliasInitializerContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasInitializer;
}


antlrcpp::Any qasm3Parser::AliasInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAliasInitializer(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasInitializerContext* qasm3Parser::aliasInitializer() {
  AliasInitializerContext *_localctx = _tracker.createInstance<AliasInitializerContext>(_ctx, getState());
  enterRule(_localctx, 78, qasm3Parser::RuleAliasInitializer);
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
    setState(495);
    expression(0);
    setState(500);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::DOUBLE_PLUS) {
      setState(496);
      match(qasm3Parser::DOUBLE_PLUS);
      setState(497);
      expression(0);
      setState(502);
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

//----------------- AliasStatementContext ------------------------------------------------------------------

qasm3Parser::AliasStatementContext::AliasStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::LET() {
  return getToken(qasm3Parser::LET, 0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::AliasInitializerContext* qasm3Parser::AliasStatementContext::aliasInitializer() {
  return getRuleContext<qasm3Parser::AliasInitializerContext>(0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::AliasStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasStatement;
}


antlrcpp::Any qasm3Parser::AliasStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAliasStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasStatementContext* qasm3Parser::aliasStatement() {
  AliasStatementContext *_localctx = _tracker.createInstance<AliasStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, qasm3Parser::RuleAliasStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    match(qasm3Parser::LET);
    setState(504);
    match(qasm3Parser::Identifier);
    setState(505);
    match(qasm3Parser::EQUALS);
    setState(506);
    aliasInitializer();
    setState(507);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeDefinitionContext ------------------------------------------------------------------

qasm3Parser::RangeDefinitionContext::RangeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> qasm3Parser::RangeDefinitionContext::COLON() {
  return getTokens(qasm3Parser::COLON);
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::COLON(size_t i) {
  return getToken(qasm3Parser::COLON, i);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::RangeDefinitionContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::RangeDefinitionContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}


size_t qasm3Parser::RangeDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleRangeDefinition;
}


antlrcpp::Any qasm3Parser::RangeDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitRangeDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::rangeDefinition() {
  RangeDefinitionContext *_localctx = _tracker.createInstance<RangeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 82, qasm3Parser::RuleRangeDefinition);
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
    setState(510);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::CREG)
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
      | (1ULL << qasm3Parser::SIZEOF)
      | (1ULL << qasm3Parser::BuiltinMath)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
      | (1ULL << (qasm3Parser::Constant - 67))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::Identifier - 67))
      | (1ULL << (qasm3Parser::FloatLiteral - 67))
      | (1ULL << (qasm3Parser::TimingLiteral - 67))
      | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
      setState(509);
      expression(0);
    }
    setState(512);
    match(qasm3Parser::COLON);
    setState(514);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::CREG)
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
      | (1ULL << qasm3Parser::SIZEOF)
      | (1ULL << qasm3Parser::BuiltinMath)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
      | (1ULL << (qasm3Parser::Constant - 67))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::Identifier - 67))
      | (1ULL << (qasm3Parser::FloatLiteral - 67))
      | (1ULL << (qasm3Parser::TimingLiteral - 67))
      | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
      setState(513);
      expression(0);
    }
    setState(518);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COLON) {
      setState(516);
      match(qasm3Parser::COLON);
      setState(517);
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

//----------------- QuantumGateDefinitionContext ------------------------------------------------------------------

qasm3Parser::QuantumGateDefinitionContext::QuantumGateDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumGateDefinitionContext::GATE() {
  return getToken(qasm3Parser::GATE, 0);
}

qasm3Parser::QuantumGateSignatureContext* qasm3Parser::QuantumGateDefinitionContext::quantumGateSignature() {
  return getRuleContext<qasm3Parser::QuantumGateSignatureContext>(0);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::QuantumGateDefinitionContext::quantumBlock() {
  return getRuleContext<qasm3Parser::QuantumBlockContext>(0);
}


size_t qasm3Parser::QuantumGateDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateDefinition;
}


antlrcpp::Any qasm3Parser::QuantumGateDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumGateDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateDefinitionContext* qasm3Parser::quantumGateDefinition() {
  QuantumGateDefinitionContext *_localctx = _tracker.createInstance<QuantumGateDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 84, qasm3Parser::RuleQuantumGateDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    match(qasm3Parser::GATE);
    setState(521);
    quantumGateSignature();
    setState(522);
    quantumBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateSignatureContext ------------------------------------------------------------------

qasm3Parser::QuantumGateSignatureContext::QuantumGateSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::QuantumGateSignatureContext::quantumGateName() {
  return getRuleContext<qasm3Parser::QuantumGateNameContext>(0);
}

std::vector<qasm3Parser::IdentifierListContext *> qasm3Parser::QuantumGateSignatureContext::identifierList() {
  return getRuleContexts<qasm3Parser::IdentifierListContext>();
}

qasm3Parser::IdentifierListContext* qasm3Parser::QuantumGateSignatureContext::identifierList(size_t i) {
  return getRuleContext<qasm3Parser::IdentifierListContext>(i);
}

tree::TerminalNode* qasm3Parser::QuantumGateSignatureContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateSignatureContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::QuantumGateSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateSignature;
}


antlrcpp::Any qasm3Parser::QuantumGateSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumGateSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateSignatureContext* qasm3Parser::quantumGateSignature() {
  QuantumGateSignatureContext *_localctx = _tracker.createInstance<QuantumGateSignatureContext>(_ctx, getState());
  enterRule(_localctx, 86, qasm3Parser::RuleQuantumGateSignature);
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
    setState(524);
    quantumGateName();
    setState(530);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(525);
      match(qasm3Parser::LPAREN);
      setState(527);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier) {
        setState(526);
        identifierList();
      }
      setState(529);
      match(qasm3Parser::RPAREN);
    }
    setState(532);
    identifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateNameContext ------------------------------------------------------------------

qasm3Parser::QuantumGateNameContext::QuantumGateNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumGateNameContext::U_() {
  return getToken(qasm3Parser::U_, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateNameContext::CX() {
  return getToken(qasm3Parser::CX, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateNameContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::QuantumGateNameContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateName;
}


antlrcpp::Any qasm3Parser::QuantumGateNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumGateName(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::quantumGateName() {
  QuantumGateNameContext *_localctx = _tracker.createInstance<QuantumGateNameContext>(_ctx, getState());
  enterRule(_localctx, 88, qasm3Parser::RuleQuantumGateName);
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
    setState(534);
    _la = _input->LA(1);
    if (!(((((_la - 37) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 37)) & ((1ULL << (qasm3Parser::U_ - 37))
      | (1ULL << (qasm3Parser::CX - 37))
      | (1ULL << (qasm3Parser::Identifier - 37)))) != 0))) {
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

//----------------- QuantumBlockContext ------------------------------------------------------------------

qasm3Parser::QuantumBlockContext::QuantumBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::QuantumBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::QuantumStatementContext *> qasm3Parser::QuantumBlockContext::quantumStatement() {
  return getRuleContexts<qasm3Parser::QuantumStatementContext>();
}

qasm3Parser::QuantumStatementContext* qasm3Parser::QuantumBlockContext::quantumStatement(size_t i) {
  return getRuleContext<qasm3Parser::QuantumStatementContext>(i);
}

std::vector<qasm3Parser::QuantumLoopContext *> qasm3Parser::QuantumBlockContext::quantumLoop() {
  return getRuleContexts<qasm3Parser::QuantumLoopContext>();
}

qasm3Parser::QuantumLoopContext* qasm3Parser::QuantumBlockContext::quantumLoop(size_t i) {
  return getRuleContext<qasm3Parser::QuantumLoopContext>(i);
}


size_t qasm3Parser::QuantumBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumBlock;
}


antlrcpp::Any qasm3Parser::QuantumBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::quantumBlock() {
  QuantumBlockContext *_localctx = _tracker.createInstance<QuantumBlockContext>(_ctx, getState());
  enterRule(_localctx, 90, qasm3Parser::RuleQuantumBlock);
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
    setState(536);
    match(qasm3Parser::LBRACE);
    setState(541);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::BOX)
      | (1ULL << qasm3Parser::FOR)
      | (1ULL << qasm3Parser::WHILE)
      | (1ULL << qasm3Parser::U_)
      | (1ULL << qasm3Parser::CX)
      | (1ULL << qasm3Parser::GPHASE)
      | (1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL)
      | (1ULL << qasm3Parser::BuiltinTimingInstruction)
      | (1ULL << qasm3Parser::RESET)
      | (1ULL << qasm3Parser::MEASURE)
      | (1ULL << qasm3Parser::BARRIER))) != 0) || _la == qasm3Parser::Identifier) {
      setState(539);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::BOX:
        case qasm3Parser::U_:
        case qasm3Parser::CX:
        case qasm3Parser::GPHASE:
        case qasm3Parser::INV:
        case qasm3Parser::POW:
        case qasm3Parser::CTRL:
        case qasm3Parser::NEGCTRL:
        case qasm3Parser::BuiltinTimingInstruction:
        case qasm3Parser::RESET:
        case qasm3Parser::MEASURE:
        case qasm3Parser::BARRIER:
        case qasm3Parser::Identifier: {
          setState(537);
          quantumStatement();
          break;
        }

        case qasm3Parser::FOR:
        case qasm3Parser::WHILE: {
          setState(538);
          quantumLoop();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(543);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(544);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumLoopContext ------------------------------------------------------------------

qasm3Parser::QuantumLoopContext::QuantumLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::LoopSignatureContext* qasm3Parser::QuantumLoopContext::loopSignature() {
  return getRuleContext<qasm3Parser::LoopSignatureContext>(0);
}

qasm3Parser::QuantumLoopBlockContext* qasm3Parser::QuantumLoopContext::quantumLoopBlock() {
  return getRuleContext<qasm3Parser::QuantumLoopBlockContext>(0);
}


size_t qasm3Parser::QuantumLoopContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumLoop;
}


antlrcpp::Any qasm3Parser::QuantumLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumLoop(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumLoopContext* qasm3Parser::quantumLoop() {
  QuantumLoopContext *_localctx = _tracker.createInstance<QuantumLoopContext>(_ctx, getState());
  enterRule(_localctx, 92, qasm3Parser::RuleQuantumLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(546);
    loopSignature();
    setState(547);
    quantumLoopBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumLoopBlockContext ------------------------------------------------------------------

qasm3Parser::QuantumLoopBlockContext::QuantumLoopBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::QuantumStatementContext *> qasm3Parser::QuantumLoopBlockContext::quantumStatement() {
  return getRuleContexts<qasm3Parser::QuantumStatementContext>();
}

qasm3Parser::QuantumStatementContext* qasm3Parser::QuantumLoopBlockContext::quantumStatement(size_t i) {
  return getRuleContext<qasm3Parser::QuantumStatementContext>(i);
}

tree::TerminalNode* qasm3Parser::QuantumLoopBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::QuantumLoopBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}


size_t qasm3Parser::QuantumLoopBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumLoopBlock;
}


antlrcpp::Any qasm3Parser::QuantumLoopBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumLoopBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumLoopBlockContext* qasm3Parser::quantumLoopBlock() {
  QuantumLoopBlockContext *_localctx = _tracker.createInstance<QuantumLoopBlockContext>(_ctx, getState());
  enterRule(_localctx, 94, qasm3Parser::RuleQuantumLoopBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(558);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BOX:
      case qasm3Parser::U_:
      case qasm3Parser::CX:
      case qasm3Parser::GPHASE:
      case qasm3Parser::INV:
      case qasm3Parser::POW:
      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL:
      case qasm3Parser::BuiltinTimingInstruction:
      case qasm3Parser::RESET:
      case qasm3Parser::MEASURE:
      case qasm3Parser::BARRIER:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(549);
        quantumStatement();
        break;
      }

      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(550);
        match(qasm3Parser::LBRACE);
        setState(554);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << qasm3Parser::BOX)
          | (1ULL << qasm3Parser::U_)
          | (1ULL << qasm3Parser::CX)
          | (1ULL << qasm3Parser::GPHASE)
          | (1ULL << qasm3Parser::INV)
          | (1ULL << qasm3Parser::POW)
          | (1ULL << qasm3Parser::CTRL)
          | (1ULL << qasm3Parser::NEGCTRL)
          | (1ULL << qasm3Parser::BuiltinTimingInstruction)
          | (1ULL << qasm3Parser::RESET)
          | (1ULL << qasm3Parser::MEASURE)
          | (1ULL << qasm3Parser::BARRIER))) != 0) || _la == qasm3Parser::Identifier) {
          setState(551);
          quantumStatement();
          setState(556);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(557);
        match(qasm3Parser::RBRACE);
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

//----------------- QuantumStatementContext ------------------------------------------------------------------

qasm3Parser::QuantumStatementContext::QuantumStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumInstructionContext* qasm3Parser::QuantumStatementContext::quantumInstruction() {
  return getRuleContext<qasm3Parser::QuantumInstructionContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::TimingStatementContext* qasm3Parser::QuantumStatementContext::timingStatement() {
  return getRuleContext<qasm3Parser::TimingStatementContext>(0);
}


size_t qasm3Parser::QuantumStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumStatement;
}


antlrcpp::Any qasm3Parser::QuantumStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumStatementContext* qasm3Parser::quantumStatement() {
  QuantumStatementContext *_localctx = _tracker.createInstance<QuantumStatementContext>(_ctx, getState());
  enterRule(_localctx, 96, qasm3Parser::RuleQuantumStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(564);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::U_:
      case qasm3Parser::CX:
      case qasm3Parser::GPHASE:
      case qasm3Parser::INV:
      case qasm3Parser::POW:
      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL:
      case qasm3Parser::RESET:
      case qasm3Parser::MEASURE:
      case qasm3Parser::BARRIER:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(560);
        quantumInstruction();
        setState(561);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::BOX:
      case qasm3Parser::BuiltinTimingInstruction: {
        enterOuterAlt(_localctx, 2);
        setState(563);
        timingStatement();
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

//----------------- QuantumInstructionContext ------------------------------------------------------------------

qasm3Parser::QuantumInstructionContext::QuantumInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateCallContext* qasm3Parser::QuantumInstructionContext::quantumGateCall() {
  return getRuleContext<qasm3Parser::QuantumGateCallContext>(0);
}

qasm3Parser::QuantumPhaseContext* qasm3Parser::QuantumInstructionContext::quantumPhase() {
  return getRuleContext<qasm3Parser::QuantumPhaseContext>(0);
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::QuantumInstructionContext::quantumMeasurement() {
  return getRuleContext<qasm3Parser::QuantumMeasurementContext>(0);
}

qasm3Parser::QuantumResetContext* qasm3Parser::QuantumInstructionContext::quantumReset() {
  return getRuleContext<qasm3Parser::QuantumResetContext>(0);
}

qasm3Parser::QuantumBarrierContext* qasm3Parser::QuantumInstructionContext::quantumBarrier() {
  return getRuleContext<qasm3Parser::QuantumBarrierContext>(0);
}


size_t qasm3Parser::QuantumInstructionContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumInstruction;
}


antlrcpp::Any qasm3Parser::QuantumInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumInstructionContext* qasm3Parser::quantumInstruction() {
  QuantumInstructionContext *_localctx = _tracker.createInstance<QuantumInstructionContext>(_ctx, getState());
  enterRule(_localctx, 98, qasm3Parser::RuleQuantumInstruction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(571);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(566);
      quantumGateCall();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(567);
      quantumPhase();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(568);
      quantumMeasurement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(569);
      quantumReset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(570);
      quantumBarrier();
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

//----------------- QuantumBarrierContext ------------------------------------------------------------------

qasm3Parser::QuantumBarrierContext::QuantumBarrierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumBarrierContext::BARRIER() {
  return getToken(qasm3Parser::BARRIER, 0);
}

std::vector<qasm3Parser::IndexedIdentifierContext *> qasm3Parser::QuantumBarrierContext::indexedIdentifier() {
  return getRuleContexts<qasm3Parser::IndexedIdentifierContext>();
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::QuantumBarrierContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::QuantumBarrierContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::QuantumBarrierContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::QuantumBarrierContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumBarrier;
}


antlrcpp::Any qasm3Parser::QuantumBarrierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumBarrier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumBarrierContext* qasm3Parser::quantumBarrier() {
  QuantumBarrierContext *_localctx = _tracker.createInstance<QuantumBarrierContext>(_ctx, getState());
  enterRule(_localctx, 100, qasm3Parser::RuleQuantumBarrier);
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
    setState(573);
    match(qasm3Parser::BARRIER);
    setState(582);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier) {
      setState(574);
      indexedIdentifier();
      setState(579);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == qasm3Parser::COMMA) {
        setState(575);
        match(qasm3Parser::COMMA);
        setState(576);
        indexedIdentifier();
        setState(581);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumMeasurementContext ------------------------------------------------------------------

qasm3Parser::QuantumMeasurementContext::QuantumMeasurementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumMeasurementContext::MEASURE() {
  return getToken(qasm3Parser::MEASURE, 0);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::QuantumMeasurementContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}


size_t qasm3Parser::QuantumMeasurementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumMeasurement;
}


antlrcpp::Any qasm3Parser::QuantumMeasurementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumMeasurement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::quantumMeasurement() {
  QuantumMeasurementContext *_localctx = _tracker.createInstance<QuantumMeasurementContext>(_ctx, getState());
  enterRule(_localctx, 102, qasm3Parser::RuleQuantumMeasurement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(584);
    match(qasm3Parser::MEASURE);
    setState(585);
    indexedIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumPhaseContext ------------------------------------------------------------------

qasm3Parser::QuantumPhaseContext::QuantumPhaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::GPHASE() {
  return getToken(qasm3Parser::GPHASE, 0);
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::QuantumPhaseContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<qasm3Parser::QuantumGateModifierContext *> qasm3Parser::QuantumPhaseContext::quantumGateModifier() {
  return getRuleContexts<qasm3Parser::QuantumGateModifierContext>();
}

qasm3Parser::QuantumGateModifierContext* qasm3Parser::QuantumPhaseContext::quantumGateModifier(size_t i) {
  return getRuleContext<qasm3Parser::QuantumGateModifierContext>(i);
}

std::vector<qasm3Parser::IndexedIdentifierContext *> qasm3Parser::QuantumPhaseContext::indexedIdentifier() {
  return getRuleContexts<qasm3Parser::IndexedIdentifierContext>();
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::QuantumPhaseContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::QuantumPhaseContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::QuantumPhaseContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::QuantumPhaseContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumPhase;
}


antlrcpp::Any qasm3Parser::QuantumPhaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumPhase(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumPhaseContext* qasm3Parser::quantumPhase() {
  QuantumPhaseContext *_localctx = _tracker.createInstance<QuantumPhaseContext>(_ctx, getState());
  enterRule(_localctx, 104, qasm3Parser::RuleQuantumPhase);
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
    setState(590);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL))) != 0)) {
      setState(587);
      quantumGateModifier();
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(593);
    match(qasm3Parser::GPHASE);
    setState(594);
    match(qasm3Parser::LPAREN);
    setState(595);
    expression(0);
    setState(596);
    match(qasm3Parser::RPAREN);
    setState(605);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier) {
      setState(597);
      indexedIdentifier();
      setState(602);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == qasm3Parser::COMMA) {
        setState(598);
        match(qasm3Parser::COMMA);
        setState(599);
        indexedIdentifier();
        setState(604);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumResetContext ------------------------------------------------------------------

qasm3Parser::QuantumResetContext::QuantumResetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumResetContext::RESET() {
  return getToken(qasm3Parser::RESET, 0);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::QuantumResetContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}


size_t qasm3Parser::QuantumResetContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumReset;
}


antlrcpp::Any qasm3Parser::QuantumResetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumReset(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumResetContext* qasm3Parser::quantumReset() {
  QuantumResetContext *_localctx = _tracker.createInstance<QuantumResetContext>(_ctx, getState());
  enterRule(_localctx, 106, qasm3Parser::RuleQuantumReset);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    match(qasm3Parser::RESET);
    setState(608);
    indexedIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumMeasurementAssignmentContext ------------------------------------------------------------------

qasm3Parser::QuantumMeasurementAssignmentContext::QuantumMeasurementAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::QuantumMeasurementAssignmentContext::quantumMeasurement() {
  return getRuleContext<qasm3Parser::QuantumMeasurementContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumMeasurementAssignmentContext::ARROW() {
  return getToken(qasm3Parser::ARROW, 0);
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::QuantumMeasurementAssignmentContext::indexedIdentifier() {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumMeasurementAssignmentContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}


size_t qasm3Parser::QuantumMeasurementAssignmentContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumMeasurementAssignment;
}


antlrcpp::Any qasm3Parser::QuantumMeasurementAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumMeasurementAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumMeasurementAssignmentContext* qasm3Parser::quantumMeasurementAssignment() {
  QuantumMeasurementAssignmentContext *_localctx = _tracker.createInstance<QuantumMeasurementAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 108, qasm3Parser::RuleQuantumMeasurementAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(619);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::MEASURE: {
        enterOuterAlt(_localctx, 1);
        setState(610);
        quantumMeasurement();
        setState(613);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::ARROW) {
          setState(611);
          match(qasm3Parser::ARROW);
          setState(612);
          indexedIdentifier();
        }
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(615);
        indexedIdentifier();
        setState(616);
        match(qasm3Parser::EQUALS);
        setState(617);
        quantumMeasurement();
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

//----------------- PowModifierContext ------------------------------------------------------------------

qasm3Parser::PowModifierContext::PowModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::PowModifierContext::POW() {
  return getToken(qasm3Parser::POW, 0);
}

tree::TerminalNode* qasm3Parser::PowModifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::PowModifierContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::PowModifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::PowModifierContext::getRuleIndex() const {
  return qasm3Parser::RulePowModifier;
}


antlrcpp::Any qasm3Parser::PowModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitPowModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PowModifierContext* qasm3Parser::powModifier() {
  PowModifierContext *_localctx = _tracker.createInstance<PowModifierContext>(_ctx, getState());
  enterRule(_localctx, 110, qasm3Parser::RulePowModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(621);
    match(qasm3Parser::POW);
    setState(622);
    match(qasm3Parser::LPAREN);
    setState(623);
    expression(0);
    setState(624);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CtrlModifierContext ------------------------------------------------------------------

qasm3Parser::CtrlModifierContext::CtrlModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CtrlModifierContext::CTRL() {
  return getToken(qasm3Parser::CTRL, 0);
}

tree::TerminalNode* qasm3Parser::CtrlModifierContext::NEGCTRL() {
  return getToken(qasm3Parser::NEGCTRL, 0);
}

tree::TerminalNode* qasm3Parser::CtrlModifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::CtrlModifierContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::CtrlModifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::CtrlModifierContext::getRuleIndex() const {
  return qasm3Parser::RuleCtrlModifier;
}


antlrcpp::Any qasm3Parser::CtrlModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCtrlModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CtrlModifierContext* qasm3Parser::ctrlModifier() {
  CtrlModifierContext *_localctx = _tracker.createInstance<CtrlModifierContext>(_ctx, getState());
  enterRule(_localctx, 112, qasm3Parser::RuleCtrlModifier);
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
    setState(626);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::CTRL

    || _la == qasm3Parser::NEGCTRL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(631);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(627);
      match(qasm3Parser::LPAREN);
      setState(628);
      expression(0);
      setState(629);
      match(qasm3Parser::RPAREN);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateModifierContext ------------------------------------------------------------------

qasm3Parser::QuantumGateModifierContext::QuantumGateModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::QuantumGateModifierContext::AT() {
  return getToken(qasm3Parser::AT, 0);
}

tree::TerminalNode* qasm3Parser::QuantumGateModifierContext::INV() {
  return getToken(qasm3Parser::INV, 0);
}

qasm3Parser::PowModifierContext* qasm3Parser::QuantumGateModifierContext::powModifier() {
  return getRuleContext<qasm3Parser::PowModifierContext>(0);
}

qasm3Parser::CtrlModifierContext* qasm3Parser::QuantumGateModifierContext::ctrlModifier() {
  return getRuleContext<qasm3Parser::CtrlModifierContext>(0);
}


size_t qasm3Parser::QuantumGateModifierContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateModifier;
}


antlrcpp::Any qasm3Parser::QuantumGateModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumGateModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateModifierContext* qasm3Parser::quantumGateModifier() {
  QuantumGateModifierContext *_localctx = _tracker.createInstance<QuantumGateModifierContext>(_ctx, getState());
  enterRule(_localctx, 114, qasm3Parser::RuleQuantumGateModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(636);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::INV: {
        setState(633);
        match(qasm3Parser::INV);
        break;
      }

      case qasm3Parser::POW: {
        setState(634);
        powModifier();
        break;
      }

      case qasm3Parser::CTRL:
      case qasm3Parser::NEGCTRL: {
        setState(635);
        ctrlModifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(638);
    match(qasm3Parser::AT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuantumGateCallContext ------------------------------------------------------------------

qasm3Parser::QuantumGateCallContext::QuantumGateCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::QuantumGateCallContext::quantumGateName() {
  return getRuleContext<qasm3Parser::QuantumGateNameContext>(0);
}

std::vector<qasm3Parser::IndexedIdentifierContext *> qasm3Parser::QuantumGateCallContext::indexedIdentifier() {
  return getRuleContexts<qasm3Parser::IndexedIdentifierContext>();
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::QuantumGateCallContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(i);
}

std::vector<qasm3Parser::QuantumGateModifierContext *> qasm3Parser::QuantumGateCallContext::quantumGateModifier() {
  return getRuleContexts<qasm3Parser::QuantumGateModifierContext>();
}

qasm3Parser::QuantumGateModifierContext* qasm3Parser::QuantumGateCallContext::quantumGateModifier(size_t i) {
  return getRuleContext<qasm3Parser::QuantumGateModifierContext>(i);
}

tree::TerminalNode* qasm3Parser::QuantumGateCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::QuantumGateCallContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumGateCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::QuantumGateCallContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::QuantumGateCallContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::QuantumGateCallContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateCall;
}


antlrcpp::Any qasm3Parser::QuantumGateCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitQuantumGateCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateCallContext* qasm3Parser::quantumGateCall() {
  QuantumGateCallContext *_localctx = _tracker.createInstance<QuantumGateCallContext>(_ctx, getState());
  enterRule(_localctx, 116, qasm3Parser::RuleQuantumGateCall);
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
    setState(643);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL))) != 0)) {
      setState(640);
      quantumGateModifier();
      setState(645);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(646);
    quantumGateName();
    setState(651);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(647);
      match(qasm3Parser::LPAREN);
      setState(648);
      expressionList();
      setState(649);
      match(qasm3Parser::RPAREN);
    }
    setState(653);
    indexedIdentifier();
    setState(658);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(654);
      match(qasm3Parser::COMMA);
      setState(655);
      indexedIdentifier();
      setState(660);
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

//----------------- UnaryOperatorContext ------------------------------------------------------------------

qasm3Parser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::UnaryOperatorContext::TILDE() {
  return getToken(qasm3Parser::TILDE, 0);
}

tree::TerminalNode* qasm3Parser::UnaryOperatorContext::EXCLAMATION_POINT() {
  return getToken(qasm3Parser::EXCLAMATION_POINT, 0);
}

tree::TerminalNode* qasm3Parser::UnaryOperatorContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}


size_t qasm3Parser::UnaryOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleUnaryOperator;
}


antlrcpp::Any qasm3Parser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::UnaryOperatorContext* qasm3Parser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 118, qasm3Parser::RuleUnaryOperator);
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
    setState(661);
    _la = _input->LA(1);
    if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67)))) != 0))) {
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
  enterRule(_localctx, 120, qasm3Parser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(663);
    expression(0);
    setState(664);
    match(qasm3Parser::SEMICOLON);
   
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

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::ExpressionContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::ExpressionContext::unaryExpression() {
  return getRuleContext<qasm3Parser::UnaryExpressionContext>(0);
}

qasm3Parser::LogicalAndExpressionContext* qasm3Parser::ExpressionContext::logicalAndExpression() {
  return getRuleContext<qasm3Parser::LogicalAndExpressionContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionContext::DOUBLE_PIPE() {
  return getToken(qasm3Parser::DOUBLE_PIPE, 0);
}


size_t qasm3Parser::ExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleExpression;
}


antlrcpp::Any qasm3Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
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
  size_t startState = 122;
  enterRecursionRule(_localctx, 122, qasm3Parser::RuleExpression, precedence);

    

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
    setState(670);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(667);
      expressionTerminator();
      break;
    }

    case 2: {
      setState(668);
      unaryExpression();
      break;
    }

    case 3: {
      setState(669);
      logicalAndExpression(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(677);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(672);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(673);
        match(qasm3Parser::DOUBLE_PIPE);
        setState(674);
        logicalAndExpression(0); 
      }
      setState(679);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

qasm3Parser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::BitOrExpressionContext* qasm3Parser::LogicalAndExpressionContext::bitOrExpression() {
  return getRuleContext<qasm3Parser::BitOrExpressionContext>(0);
}

qasm3Parser::LogicalAndExpressionContext* qasm3Parser::LogicalAndExpressionContext::logicalAndExpression() {
  return getRuleContext<qasm3Parser::LogicalAndExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::LogicalAndExpressionContext::DOUBLE_AMPERSAND() {
  return getToken(qasm3Parser::DOUBLE_AMPERSAND, 0);
}


size_t qasm3Parser::LogicalAndExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleLogicalAndExpression;
}


antlrcpp::Any qasm3Parser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::LogicalAndExpressionContext* qasm3Parser::logicalAndExpression() {
   return logicalAndExpression(0);
}

qasm3Parser::LogicalAndExpressionContext* qasm3Parser::logicalAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, parentState);
  qasm3Parser::LogicalAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 124;
  enterRecursionRule(_localctx, 124, qasm3Parser::RuleLogicalAndExpression, precedence);

    

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
    setState(681);
    bitOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(688);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(683);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(684);
        match(qasm3Parser::DOUBLE_AMPERSAND);
        setState(685);
        bitOrExpression(0); 
      }
      setState(690);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitOrExpressionContext ------------------------------------------------------------------

qasm3Parser::BitOrExpressionContext::BitOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::XOrExpressionContext* qasm3Parser::BitOrExpressionContext::xOrExpression() {
  return getRuleContext<qasm3Parser::XOrExpressionContext>(0);
}

qasm3Parser::BitOrExpressionContext* qasm3Parser::BitOrExpressionContext::bitOrExpression() {
  return getRuleContext<qasm3Parser::BitOrExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::BitOrExpressionContext::PIPE() {
  return getToken(qasm3Parser::PIPE, 0);
}


size_t qasm3Parser::BitOrExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitOrExpression;
}


antlrcpp::Any qasm3Parser::BitOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitOrExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::BitOrExpressionContext* qasm3Parser::bitOrExpression() {
   return bitOrExpression(0);
}

qasm3Parser::BitOrExpressionContext* qasm3Parser::bitOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::BitOrExpressionContext *_localctx = _tracker.createInstance<BitOrExpressionContext>(_ctx, parentState);
  qasm3Parser::BitOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 126;
  enterRecursionRule(_localctx, 126, qasm3Parser::RuleBitOrExpression, precedence);

    

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
    setState(692);
    xOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(699);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitOrExpression);
        setState(694);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(695);
        match(qasm3Parser::PIPE);
        setState(696);
        xOrExpression(0); 
      }
      setState(701);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- XOrExpressionContext ------------------------------------------------------------------

qasm3Parser::XOrExpressionContext::XOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::BitAndExpressionContext* qasm3Parser::XOrExpressionContext::bitAndExpression() {
  return getRuleContext<qasm3Parser::BitAndExpressionContext>(0);
}

qasm3Parser::XOrExpressionContext* qasm3Parser::XOrExpressionContext::xOrExpression() {
  return getRuleContext<qasm3Parser::XOrExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::XOrExpressionContext::CARET() {
  return getToken(qasm3Parser::CARET, 0);
}


size_t qasm3Parser::XOrExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleXOrExpression;
}


antlrcpp::Any qasm3Parser::XOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitXOrExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::XOrExpressionContext* qasm3Parser::xOrExpression() {
   return xOrExpression(0);
}

qasm3Parser::XOrExpressionContext* qasm3Parser::xOrExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::XOrExpressionContext *_localctx = _tracker.createInstance<XOrExpressionContext>(_ctx, parentState);
  qasm3Parser::XOrExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 128;
  enterRecursionRule(_localctx, 128, qasm3Parser::RuleXOrExpression, precedence);

    

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
    setState(703);
    bitAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(710);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<XOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleXOrExpression);
        setState(705);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(706);
        match(qasm3Parser::CARET);
        setState(707);
        bitAndExpression(0); 
      }
      setState(712);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitAndExpressionContext ------------------------------------------------------------------

qasm3Parser::BitAndExpressionContext::BitAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::EqualityExpressionContext* qasm3Parser::BitAndExpressionContext::equalityExpression() {
  return getRuleContext<qasm3Parser::EqualityExpressionContext>(0);
}

qasm3Parser::BitAndExpressionContext* qasm3Parser::BitAndExpressionContext::bitAndExpression() {
  return getRuleContext<qasm3Parser::BitAndExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::BitAndExpressionContext::AMPERSAND() {
  return getToken(qasm3Parser::AMPERSAND, 0);
}


size_t qasm3Parser::BitAndExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitAndExpression;
}


antlrcpp::Any qasm3Parser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitAndExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::BitAndExpressionContext* qasm3Parser::bitAndExpression() {
   return bitAndExpression(0);
}

qasm3Parser::BitAndExpressionContext* qasm3Parser::bitAndExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::BitAndExpressionContext *_localctx = _tracker.createInstance<BitAndExpressionContext>(_ctx, parentState);
  qasm3Parser::BitAndExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 130;
  enterRecursionRule(_localctx, 130, qasm3Parser::RuleBitAndExpression, precedence);

    

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
    setState(714);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(721);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitAndExpression);
        setState(716);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(717);
        match(qasm3Parser::AMPERSAND);
        setState(718);
        equalityExpression(0); 
      }
      setState(723);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

qasm3Parser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ComparisonExpressionContext* qasm3Parser::EqualityExpressionContext::comparisonExpression() {
  return getRuleContext<qasm3Parser::ComparisonExpressionContext>(0);
}

qasm3Parser::EqualityExpressionContext* qasm3Parser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<qasm3Parser::EqualityExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::EqualityExpressionContext::EqualityOperator() {
  return getToken(qasm3Parser::EqualityOperator, 0);
}


size_t qasm3Parser::EqualityExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleEqualityExpression;
}


antlrcpp::Any qasm3Parser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::EqualityExpressionContext* qasm3Parser::equalityExpression() {
   return equalityExpression(0);
}

qasm3Parser::EqualityExpressionContext* qasm3Parser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  qasm3Parser::EqualityExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 132;
  enterRecursionRule(_localctx, 132, qasm3Parser::RuleEqualityExpression, precedence);

    

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
    setState(725);
    comparisonExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(732);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
        setState(727);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(728);
        match(qasm3Parser::EqualityOperator);
        setState(729);
        comparisonExpression(0); 
      }
      setState(734);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ComparisonExpressionContext ------------------------------------------------------------------

qasm3Parser::ComparisonExpressionContext::ComparisonExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::BitShiftExpressionContext* qasm3Parser::ComparisonExpressionContext::bitShiftExpression() {
  return getRuleContext<qasm3Parser::BitShiftExpressionContext>(0);
}

qasm3Parser::ComparisonExpressionContext* qasm3Parser::ComparisonExpressionContext::comparisonExpression() {
  return getRuleContext<qasm3Parser::ComparisonExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ComparisonExpressionContext::ComparisonOperator() {
  return getToken(qasm3Parser::ComparisonOperator, 0);
}


size_t qasm3Parser::ComparisonExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleComparisonExpression;
}


antlrcpp::Any qasm3Parser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitComparisonExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::ComparisonExpressionContext* qasm3Parser::comparisonExpression() {
   return comparisonExpression(0);
}

qasm3Parser::ComparisonExpressionContext* qasm3Parser::comparisonExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::ComparisonExpressionContext *_localctx = _tracker.createInstance<ComparisonExpressionContext>(_ctx, parentState);
  qasm3Parser::ComparisonExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 134;
  enterRecursionRule(_localctx, 134, qasm3Parser::RuleComparisonExpression, precedence);

    

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
    setState(736);
    bitShiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(743);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ComparisonExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleComparisonExpression);
        setState(738);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(739);
        match(qasm3Parser::ComparisonOperator);
        setState(740);
        bitShiftExpression(0); 
      }
      setState(745);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitShiftExpressionContext ------------------------------------------------------------------

qasm3Parser::BitShiftExpressionContext::BitShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::AdditiveExpressionContext* qasm3Parser::BitShiftExpressionContext::additiveExpression() {
  return getRuleContext<qasm3Parser::AdditiveExpressionContext>(0);
}

qasm3Parser::BitShiftExpressionContext* qasm3Parser::BitShiftExpressionContext::bitShiftExpression() {
  return getRuleContext<qasm3Parser::BitShiftExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::BitShiftExpressionContext::BitshiftOperator() {
  return getToken(qasm3Parser::BitshiftOperator, 0);
}


size_t qasm3Parser::BitShiftExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitShiftExpression;
}


antlrcpp::Any qasm3Parser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::BitShiftExpressionContext* qasm3Parser::bitShiftExpression() {
   return bitShiftExpression(0);
}

qasm3Parser::BitShiftExpressionContext* qasm3Parser::bitShiftExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::BitShiftExpressionContext *_localctx = _tracker.createInstance<BitShiftExpressionContext>(_ctx, parentState);
  qasm3Parser::BitShiftExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 136;
  enterRecursionRule(_localctx, 136, qasm3Parser::RuleBitShiftExpression, precedence);

    

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
    setState(747);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(754);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitShiftExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitShiftExpression);
        setState(749);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(750);
        match(qasm3Parser::BitshiftOperator);
        setState(751);
        additiveExpression(0); 
      }
      setState(756);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

qasm3Parser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasm3Parser::MultiplicativeExpressionContext>(0);
}

qasm3Parser::AdditiveExpressionContext* qasm3Parser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<qasm3Parser::AdditiveExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::PLUS() {
  return getToken(qasm3Parser::PLUS, 0);
}

tree::TerminalNode* qasm3Parser::AdditiveExpressionContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}


size_t qasm3Parser::AdditiveExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleAdditiveExpression;
}


antlrcpp::Any qasm3Parser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::AdditiveExpressionContext* qasm3Parser::additiveExpression() {
   return additiveExpression(0);
}

qasm3Parser::AdditiveExpressionContext* qasm3Parser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  qasm3Parser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 138;
  enterRecursionRule(_localctx, 138, qasm3Parser::RuleAdditiveExpression, precedence);

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
    setState(758);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(765);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
        setState(760);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(761);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::PLUS

        || _la == qasm3Parser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(762);
        multiplicativeExpression(0); 
      }
      setState(767);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

qasm3Parser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<qasm3Parser::UnaryExpressionContext>(0);
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasm3Parser::MultiplicativeExpressionContext>(0);
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


size_t qasm3Parser::MultiplicativeExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleMultiplicativeExpression;
}


antlrcpp::Any qasm3Parser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  qasm3Parser::MultiplicativeExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 140;
  enterRecursionRule(_localctx, 140, qasm3Parser::RuleMultiplicativeExpression, precedence);

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
    setState(769);
    unaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(776);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
        setState(771);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(772);
        _la = _input->LA(1);
        if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 68)) & ((1ULL << (qasm3Parser::ASTERISK - 68))
          | (1ULL << (qasm3Parser::SLASH - 68))
          | (1ULL << (qasm3Parser::PERCENT - 68)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(773);
        unaryExpression(); 
      }
      setState(778);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

qasm3Parser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::PowerExpressionContext* qasm3Parser::UnaryExpressionContext::powerExpression() {
  return getRuleContext<qasm3Parser::PowerExpressionContext>(0);
}

qasm3Parser::UnaryOperatorContext* qasm3Parser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<qasm3Parser::UnaryOperatorContext>(0);
}


size_t qasm3Parser::UnaryExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleUnaryExpression;
}


antlrcpp::Any qasm3Parser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 142, qasm3Parser::RuleUnaryExpression);
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
    setState(780);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67)))) != 0)) {
      setState(779);
      unaryOperator();
    }
    setState(782);
    powerExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PowerExpressionContext ------------------------------------------------------------------

qasm3Parser::PowerExpressionContext::PowerExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexExpressionContext* qasm3Parser::PowerExpressionContext::indexExpression() {
  return getRuleContext<qasm3Parser::IndexExpressionContext>(0);
}

qasm3Parser::PowerExpressionContext* qasm3Parser::PowerExpressionContext::powerExpression() {
  return getRuleContext<qasm3Parser::PowerExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::PowerExpressionContext::DOUBLE_ASTERISK() {
  return getToken(qasm3Parser::DOUBLE_ASTERISK, 0);
}


size_t qasm3Parser::PowerExpressionContext::getRuleIndex() const {
  return qasm3Parser::RulePowerExpression;
}


antlrcpp::Any qasm3Parser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::PowerExpressionContext* qasm3Parser::powerExpression() {
   return powerExpression(0);
}

qasm3Parser::PowerExpressionContext* qasm3Parser::powerExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::PowerExpressionContext *_localctx = _tracker.createInstance<PowerExpressionContext>(_ctx, parentState);
  qasm3Parser::PowerExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 144;
  enterRecursionRule(_localctx, 144, qasm3Parser::RulePowerExpression, precedence);

    

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
    setState(785);
    indexExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(792);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PowerExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePowerExpression);
        setState(787);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(788);
        match(qasm3Parser::DOUBLE_ASTERISK);
        setState(789);
        indexExpression(0); 
      }
      setState(794);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
    }
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

qasm3Parser::DiscreteSetContext* qasm3Parser::IndexOperatorContext::discreteSet() {
  return getRuleContext<qasm3Parser::DiscreteSetContext>(0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::IndexOperatorContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::IndexOperatorContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

std::vector<qasm3Parser::RangeDefinitionContext *> qasm3Parser::IndexOperatorContext::rangeDefinition() {
  return getRuleContexts<qasm3Parser::RangeDefinitionContext>();
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::IndexOperatorContext::rangeDefinition(size_t i) {
  return getRuleContext<qasm3Parser::RangeDefinitionContext>(i);
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
  enterRule(_localctx, 146, qasm3Parser::RuleIndexOperator);
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
    setState(795);
    match(qasm3Parser::LBRACKET);
    setState(811);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        setState(796);
        discreteSet();
        break;
      }

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
      case qasm3Parser::SIZEOF:
      case qasm3Parser::BuiltinMath:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::COLON:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::Constant:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(799);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
        case 1: {
          setState(797);
          expression(0);
          break;
        }

        case 2: {
          setState(798);
          rangeDefinition();
          break;
        }

        default:
          break;
        }
        setState(808);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == qasm3Parser::COMMA) {
          setState(801);
          match(qasm3Parser::COMMA);
          setState(804);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
          case 1: {
            setState(802);
            expression(0);
            break;
          }

          case 2: {
            setState(803);
            rangeDefinition();
            break;
          }

          default:
            break;
          }
          setState(810);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(813);
    match(qasm3Parser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexExpressionContext ------------------------------------------------------------------

qasm3Parser::IndexExpressionContext::IndexExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::IndexExpressionContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

qasm3Parser::IndexExpressionContext* qasm3Parser::IndexExpressionContext::indexExpression() {
  return getRuleContext<qasm3Parser::IndexExpressionContext>(0);
}

qasm3Parser::IndexOperatorContext* qasm3Parser::IndexExpressionContext::indexOperator() {
  return getRuleContext<qasm3Parser::IndexOperatorContext>(0);
}


size_t qasm3Parser::IndexExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexExpression;
}


antlrcpp::Any qasm3Parser::IndexExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitIndexExpression(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::IndexExpressionContext* qasm3Parser::indexExpression() {
   return indexExpression(0);
}

qasm3Parser::IndexExpressionContext* qasm3Parser::indexExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::IndexExpressionContext *_localctx = _tracker.createInstance<IndexExpressionContext>(_ctx, parentState);
  qasm3Parser::IndexExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 148;
  enterRecursionRule(_localctx, 148, qasm3Parser::RuleIndexExpression, precedence);

    

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
    setState(816);
    expressionTerminator();
    _ctx->stop = _input->LT(-1);
    setState(822);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IndexExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIndexExpression);
        setState(818);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(819);
        indexOperator(); 
      }
      setState(824);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
    }
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
  enterRule(_localctx, 150, qasm3Parser::RuleIndexedIdentifier);
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
    setState(825);
    match(qasm3Parser::Identifier);
    setState(829);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::LBRACKET) {
      setState(826);
      indexOperator();
      setState(831);
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

//----------------- ExpressionTerminatorContext ------------------------------------------------------------------

qasm3Parser::ExpressionTerminatorContext::ExpressionTerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Constant() {
  return getToken(qasm3Parser::Constant, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::BinaryIntegerLiteral() {
  return getToken(qasm3Parser::BinaryIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::OctalIntegerLiteral() {
  return getToken(qasm3Parser::OctalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::DecimalIntegerLiteral() {
  return getToken(qasm3Parser::DecimalIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::HexIntegerLiteral() {
  return getToken(qasm3Parser::HexIntegerLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::FloatLiteral() {
  return getToken(qasm3Parser::FloatLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::ImaginaryLiteral() {
  return getToken(qasm3Parser::ImaginaryLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::BooleanLiteral() {
  return getToken(qasm3Parser::BooleanLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::BitstringLiteral() {
  return getToken(qasm3Parser::BitstringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::BuiltInCallContext* qasm3Parser::ExpressionTerminatorContext::builtInCall() {
  return getRuleContext<qasm3Parser::BuiltInCallContext>(0);
}

qasm3Parser::ExternOrSubroutineCallContext* qasm3Parser::ExpressionTerminatorContext::externOrSubroutineCall() {
  return getRuleContext<qasm3Parser::ExternOrSubroutineCallContext>(0);
}

qasm3Parser::TimingIdentifierContext* qasm3Parser::ExpressionTerminatorContext::timingIdentifier() {
  return getRuleContext<qasm3Parser::TimingIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ExpressionTerminatorContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::ExpressionTerminatorContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionTerminator;
}


antlrcpp::Any qasm3Parser::ExpressionTerminatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExpressionTerminator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::expressionTerminator() {
  ExpressionTerminatorContext *_localctx = _tracker.createInstance<ExpressionTerminatorContext>(_ctx, getState());
  enterRule(_localctx, 152, qasm3Parser::RuleExpressionTerminator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(849);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(832);
      match(qasm3Parser::Constant);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(833);
      match(qasm3Parser::BinaryIntegerLiteral);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(834);
      match(qasm3Parser::OctalIntegerLiteral);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(835);
      match(qasm3Parser::DecimalIntegerLiteral);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(836);
      match(qasm3Parser::HexIntegerLiteral);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(837);
      match(qasm3Parser::FloatLiteral);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(838);
      match(qasm3Parser::ImaginaryLiteral);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(839);
      match(qasm3Parser::BooleanLiteral);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(840);
      match(qasm3Parser::BitstringLiteral);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(841);
      match(qasm3Parser::Identifier);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(842);
      builtInCall();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(843);
      externOrSubroutineCall();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(844);
      timingIdentifier();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(845);
      match(qasm3Parser::LPAREN);
      setState(846);
      expression(0);
      setState(847);
      match(qasm3Parser::RPAREN);
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

//----------------- BuiltInCallContext ------------------------------------------------------------------

qasm3Parser::BuiltInCallContext::BuiltInCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BuiltInCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::BuiltInCallContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::BuiltInCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::BuiltInCallContext::BuiltinMath() {
  return getToken(qasm3Parser::BuiltinMath, 0);
}

qasm3Parser::CastOperatorContext* qasm3Parser::BuiltInCallContext::castOperator() {
  return getRuleContext<qasm3Parser::CastOperatorContext>(0);
}

tree::TerminalNode* qasm3Parser::BuiltInCallContext::SIZEOF() {
  return getToken(qasm3Parser::SIZEOF, 0);
}


size_t qasm3Parser::BuiltInCallContext::getRuleIndex() const {
  return qasm3Parser::RuleBuiltInCall;
}


antlrcpp::Any qasm3Parser::BuiltInCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBuiltInCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BuiltInCallContext* qasm3Parser::builtInCall() {
  BuiltInCallContext *_localctx = _tracker.createInstance<BuiltInCallContext>(_ctx, getState());
  enterRule(_localctx, 154, qasm3Parser::RuleBuiltInCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(854);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BuiltinMath: {
        setState(851);
        match(qasm3Parser::BuiltinMath);
        break;
      }

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
      case qasm3Parser::STRETCH: {
        setState(852);
        castOperator();
        break;
      }

      case qasm3Parser::SIZEOF: {
        setState(853);
        match(qasm3Parser::SIZEOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(856);
    match(qasm3Parser::LPAREN);
    setState(857);
    expressionList();
    setState(858);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastOperatorContext ------------------------------------------------------------------

qasm3Parser::CastOperatorContext::CastOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::CastOperatorContext::classicalType() {
  return getRuleContext<qasm3Parser::ClassicalTypeContext>(0);
}


size_t qasm3Parser::CastOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleCastOperator;
}


antlrcpp::Any qasm3Parser::CastOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCastOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CastOperatorContext* qasm3Parser::castOperator() {
  CastOperatorContext *_localctx = _tracker.createInstance<CastOperatorContext>(_ctx, getState());
  enterRule(_localctx, 156, qasm3Parser::RuleCastOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(860);
    classicalType();
   
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
  enterRule(_localctx, 158, qasm3Parser::RuleExpressionList);
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
    setState(862);
    expression(0);
    setState(867);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(863);
      match(qasm3Parser::COMMA);
      setState(864);
      expression(0);
      setState(869);
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

//----------------- EqualsExpressionContext ------------------------------------------------------------------

qasm3Parser::EqualsExpressionContext::EqualsExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::EqualsExpressionContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::EqualsExpressionContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}


size_t qasm3Parser::EqualsExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleEqualsExpression;
}


antlrcpp::Any qasm3Parser::EqualsExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitEqualsExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::equalsExpression() {
  EqualsExpressionContext *_localctx = _tracker.createInstance<EqualsExpressionContext>(_ctx, getState());
  enterRule(_localctx, 160, qasm3Parser::RuleEqualsExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(870);
    match(qasm3Parser::EQUALS);
    setState(871);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

qasm3Parser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::AssignmentOperatorContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

tree::TerminalNode* qasm3Parser::AssignmentOperatorContext::CompoundAssignmentOperator() {
  return getToken(qasm3Parser::CompoundAssignmentOperator, 0);
}


size_t qasm3Parser::AssignmentOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleAssignmentOperator;
}


antlrcpp::Any qasm3Parser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssignmentOperatorContext* qasm3Parser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 162, qasm3Parser::RuleAssignmentOperator);
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
    setState(873);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::EQUALS

    || _la == qasm3Parser::CompoundAssignmentOperator)) {
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

//----------------- DiscreteSetContext ------------------------------------------------------------------

qasm3Parser::DiscreteSetContext::DiscreteSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::DiscreteSetContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

std::vector<qasm3Parser::ExpressionContext *> qasm3Parser::DiscreteSetContext::expression() {
  return getRuleContexts<qasm3Parser::ExpressionContext>();
}

qasm3Parser::ExpressionContext* qasm3Parser::DiscreteSetContext::expression(size_t i) {
  return getRuleContext<qasm3Parser::ExpressionContext>(i);
}

tree::TerminalNode* qasm3Parser::DiscreteSetContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::DiscreteSetContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::DiscreteSetContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::DiscreteSetContext::getRuleIndex() const {
  return qasm3Parser::RuleDiscreteSet;
}


antlrcpp::Any qasm3Parser::DiscreteSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitDiscreteSet(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::DiscreteSetContext* qasm3Parser::discreteSet() {
  DiscreteSetContext *_localctx = _tracker.createInstance<DiscreteSetContext>(_ctx, getState());
  enterRule(_localctx, 164, qasm3Parser::RuleDiscreteSet);
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
    setState(875);
    match(qasm3Parser::LBRACE);
    setState(876);
    expression(0);
    setState(881);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(877);
      match(qasm3Parser::COMMA);
      setState(878);
      expression(0);
      setState(883);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(884);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetDeclarationContext ------------------------------------------------------------------

qasm3Parser::SetDeclarationContext::SetDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::DiscreteSetContext* qasm3Parser::SetDeclarationContext::discreteSet() {
  return getRuleContext<qasm3Parser::DiscreteSetContext>(0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::SetDeclarationContext::rangeDefinition() {
  return getRuleContext<qasm3Parser::RangeDefinitionContext>(0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::SetDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleSetDeclaration;
}


antlrcpp::Any qasm3Parser::SetDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSetDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SetDeclarationContext* qasm3Parser::setDeclaration() {
  SetDeclarationContext *_localctx = _tracker.createInstance<SetDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 166, qasm3Parser::RuleSetDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(892);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(886);
        discreteSet();
        break;
      }

      case qasm3Parser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(887);
        match(qasm3Parser::LBRACKET);
        setState(888);
        rangeDefinition();
        setState(889);
        match(qasm3Parser::RBRACKET);
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 3);
        setState(891);
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

//----------------- ProgramBlockContext ------------------------------------------------------------------

qasm3Parser::ProgramBlockContext::ProgramBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::ProgramBlockContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::ProgramBlockContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}

std::vector<qasm3Parser::ControlDirectiveContext *> qasm3Parser::ProgramBlockContext::controlDirective() {
  return getRuleContexts<qasm3Parser::ControlDirectiveContext>();
}

qasm3Parser::ControlDirectiveContext* qasm3Parser::ProgramBlockContext::controlDirective(size_t i) {
  return getRuleContext<qasm3Parser::ControlDirectiveContext>(i);
}

tree::TerminalNode* qasm3Parser::ProgramBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::ProgramBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}


size_t qasm3Parser::ProgramBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleProgramBlock;
}


antlrcpp::Any qasm3Parser::ProgramBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitProgramBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ProgramBlockContext* qasm3Parser::programBlock() {
  ProgramBlockContext *_localctx = _tracker.createInstance<ProgramBlockContext>(_ctx, getState());
  enterRule(_localctx, 168, qasm3Parser::RuleProgramBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(905);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(894);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(895);
      controlDirective();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(896);
      match(qasm3Parser::LBRACE);
      setState(901);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::BOX)
        | (1ULL << qasm3Parser::LET)
        | (1ULL << qasm3Parser::BREAK)
        | (1ULL << qasm3Parser::CONTINUE)
        | (1ULL << qasm3Parser::IF)
        | (1ULL << qasm3Parser::END)
        | (1ULL << qasm3Parser::RETURN)
        | (1ULL << qasm3Parser::FOR)
        | (1ULL << qasm3Parser::WHILE)
        | (1ULL << qasm3Parser::CONST)
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
        | (1ULL << qasm3Parser::U_)
        | (1ULL << qasm3Parser::CX)
        | (1ULL << qasm3Parser::GPHASE)
        | (1ULL << qasm3Parser::INV)
        | (1ULL << qasm3Parser::POW)
        | (1ULL << qasm3Parser::CTRL)
        | (1ULL << qasm3Parser::NEGCTRL)
        | (1ULL << qasm3Parser::SIZEOF)
        | (1ULL << qasm3Parser::BuiltinMath)
        | (1ULL << qasm3Parser::DURATIONOF)
        | (1ULL << qasm3Parser::BuiltinTimingInstruction)
        | (1ULL << qasm3Parser::RESET)
        | (1ULL << qasm3Parser::MEASURE)
        | (1ULL << qasm3Parser::BARRIER)
        | (1ULL << qasm3Parser::BooleanLiteral)
        | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
        | (1ULL << (qasm3Parser::TILDE - 67))
        | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
        | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
        | (1ULL << (qasm3Parser::Constant - 67))
        | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::Identifier - 67))
        | (1ULL << (qasm3Parser::FloatLiteral - 67))
        | (1ULL << (qasm3Parser::TimingLiteral - 67))
        | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
        setState(899);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
        case 1: {
          setState(897);
          statement();
          break;
        }

        case 2: {
          setState(898);
          controlDirective();
          break;
        }

        default:
          break;
        }
        setState(903);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(904);
      match(qasm3Parser::RBRACE);
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

//----------------- BranchingStatementContext ------------------------------------------------------------------

qasm3Parser::BranchingStatementContext::BranchingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::BranchingStatementContext::IF() {
  return getToken(qasm3Parser::IF, 0);
}

tree::TerminalNode* qasm3Parser::BranchingStatementContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::BranchingStatementContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::BranchingStatementContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<qasm3Parser::ProgramBlockContext *> qasm3Parser::BranchingStatementContext::programBlock() {
  return getRuleContexts<qasm3Parser::ProgramBlockContext>();
}

qasm3Parser::ProgramBlockContext* qasm3Parser::BranchingStatementContext::programBlock(size_t i) {
  return getRuleContext<qasm3Parser::ProgramBlockContext>(i);
}

tree::TerminalNode* qasm3Parser::BranchingStatementContext::ELSE() {
  return getToken(qasm3Parser::ELSE, 0);
}


size_t qasm3Parser::BranchingStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBranchingStatement;
}


antlrcpp::Any qasm3Parser::BranchingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitBranchingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BranchingStatementContext* qasm3Parser::branchingStatement() {
  BranchingStatementContext *_localctx = _tracker.createInstance<BranchingStatementContext>(_ctx, getState());
  enterRule(_localctx, 170, qasm3Parser::RuleBranchingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(907);
    match(qasm3Parser::IF);
    setState(908);
    match(qasm3Parser::LPAREN);
    setState(909);
    expression(0);
    setState(910);
    match(qasm3Parser::RPAREN);
    setState(911);
    programBlock();
    setState(914);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      setState(912);
      match(qasm3Parser::ELSE);
      setState(913);
      programBlock();
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

//----------------- LoopSignatureContext ------------------------------------------------------------------

qasm3Parser::LoopSignatureContext::LoopSignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::FOR() {
  return getToken(qasm3Parser::FOR, 0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::IN() {
  return getToken(qasm3Parser::IN, 0);
}

qasm3Parser::SetDeclarationContext* qasm3Parser::LoopSignatureContext::setDeclaration() {
  return getRuleContext<qasm3Parser::SetDeclarationContext>(0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::WHILE() {
  return getToken(qasm3Parser::WHILE, 0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

qasm3Parser::ExpressionContext* qasm3Parser::LoopSignatureContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::LoopSignatureContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}


size_t qasm3Parser::LoopSignatureContext::getRuleIndex() const {
  return qasm3Parser::RuleLoopSignature;
}


antlrcpp::Any qasm3Parser::LoopSignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLoopSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LoopSignatureContext* qasm3Parser::loopSignature() {
  LoopSignatureContext *_localctx = _tracker.createInstance<LoopSignatureContext>(_ctx, getState());
  enterRule(_localctx, 172, qasm3Parser::RuleLoopSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(925);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::FOR: {
        enterOuterAlt(_localctx, 1);
        setState(916);
        match(qasm3Parser::FOR);
        setState(917);
        match(qasm3Parser::Identifier);
        setState(918);
        match(qasm3Parser::IN);
        setState(919);
        setDeclaration();
        break;
      }

      case qasm3Parser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(920);
        match(qasm3Parser::WHILE);
        setState(921);
        match(qasm3Parser::LPAREN);
        setState(922);
        expression(0);
        setState(923);
        match(qasm3Parser::RPAREN);
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

//----------------- LoopStatementContext ------------------------------------------------------------------

qasm3Parser::LoopStatementContext::LoopStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::LoopSignatureContext* qasm3Parser::LoopStatementContext::loopSignature() {
  return getRuleContext<qasm3Parser::LoopSignatureContext>(0);
}

qasm3Parser::ProgramBlockContext* qasm3Parser::LoopStatementContext::programBlock() {
  return getRuleContext<qasm3Parser::ProgramBlockContext>(0);
}


size_t qasm3Parser::LoopStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleLoopStatement;
}


antlrcpp::Any qasm3Parser::LoopStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitLoopStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LoopStatementContext* qasm3Parser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 174, qasm3Parser::RuleLoopStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(927);
    loopSignature();
    setState(928);
    programBlock();
   
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
  enterRule(_localctx, 176, qasm3Parser::RuleEndStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(930);
    match(qasm3Parser::END);
    setState(931);
    match(qasm3Parser::SEMICOLON);
   
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

qasm3Parser::QuantumMeasurementContext* qasm3Parser::ReturnStatementContext::quantumMeasurement() {
  return getRuleContext<qasm3Parser::QuantumMeasurementContext>(0);
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
  enterRule(_localctx, 178, qasm3Parser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(933);
    match(qasm3Parser::RETURN);
    setState(936);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case qasm3Parser::SIZEOF:
      case qasm3Parser::BuiltinMath:
      case qasm3Parser::DURATIONOF:
      case qasm3Parser::BooleanLiteral:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::TILDE:
      case qasm3Parser::EXCLAMATION_POINT:
      case qasm3Parser::ImaginaryLiteral:
      case qasm3Parser::Constant:
      case qasm3Parser::BinaryIntegerLiteral:
      case qasm3Parser::OctalIntegerLiteral:
      case qasm3Parser::DecimalIntegerLiteral:
      case qasm3Parser::HexIntegerLiteral:
      case qasm3Parser::Identifier:
      case qasm3Parser::FloatLiteral:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::BitstringLiteral: {
        setState(934);
        expression(0);
        break;
      }

      case qasm3Parser::MEASURE: {
        setState(935);
        quantumMeasurement();
        break;
      }

      case qasm3Parser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(938);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlDirectiveContext ------------------------------------------------------------------

qasm3Parser::ControlDirectiveContext::ControlDirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ControlDirectiveContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::ControlDirectiveContext::BREAK() {
  return getToken(qasm3Parser::BREAK, 0);
}

tree::TerminalNode* qasm3Parser::ControlDirectiveContext::CONTINUE() {
  return getToken(qasm3Parser::CONTINUE, 0);
}

qasm3Parser::EndStatementContext* qasm3Parser::ControlDirectiveContext::endStatement() {
  return getRuleContext<qasm3Parser::EndStatementContext>(0);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::ControlDirectiveContext::returnStatement() {
  return getRuleContext<qasm3Parser::ReturnStatementContext>(0);
}


size_t qasm3Parser::ControlDirectiveContext::getRuleIndex() const {
  return qasm3Parser::RuleControlDirective;
}


antlrcpp::Any qasm3Parser::ControlDirectiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitControlDirective(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ControlDirectiveContext* qasm3Parser::controlDirective() {
  ControlDirectiveContext *_localctx = _tracker.createInstance<ControlDirectiveContext>(_ctx, getState());
  enterRule(_localctx, 180, qasm3Parser::RuleControlDirective);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(944);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BREAK:
      case qasm3Parser::CONTINUE: {
        enterOuterAlt(_localctx, 1);
        setState(940);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::BREAK

        || _la == qasm3Parser::CONTINUE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(941);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::END: {
        enterOuterAlt(_localctx, 2);
        setState(942);
        endStatement();
        break;
      }

      case qasm3Parser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(943);
        returnStatement();
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

//----------------- ExternDeclarationContext ------------------------------------------------------------------

qasm3Parser::ExternDeclarationContext::ExternDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExternDeclarationContext::EXTERN() {
  return getToken(qasm3Parser::EXTERN, 0);
}

tree::TerminalNode* qasm3Parser::ExternDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ExternDeclarationContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternDeclarationContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternDeclarationContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::ClassicalTypeListContext* qasm3Parser::ExternDeclarationContext::classicalTypeList() {
  return getRuleContext<qasm3Parser::ClassicalTypeListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::ExternDeclarationContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}


size_t qasm3Parser::ExternDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleExternDeclaration;
}


antlrcpp::Any qasm3Parser::ExternDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternDeclarationContext* qasm3Parser::externDeclaration() {
  ExternDeclarationContext *_localctx = _tracker.createInstance<ExternDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 182, qasm3Parser::RuleExternDeclaration);
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
    setState(946);
    match(qasm3Parser::EXTERN);
    setState(947);
    match(qasm3Parser::Identifier);
    setState(948);
    match(qasm3Parser::LPAREN);
    setState(950);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::CREG)
      | (1ULL << qasm3Parser::BOOL)
      | (1ULL << qasm3Parser::BIT)
      | (1ULL << qasm3Parser::INT)
      | (1ULL << qasm3Parser::UINT)
      | (1ULL << qasm3Parser::FLOAT)
      | (1ULL << qasm3Parser::ANGLE)
      | (1ULL << qasm3Parser::COMPLEX)
      | (1ULL << qasm3Parser::ARRAY)
      | (1ULL << qasm3Parser::DURATION)
      | (1ULL << qasm3Parser::STRETCH))) != 0)) {
      setState(949);
      classicalTypeList();
    }
    setState(952);
    match(qasm3Parser::RPAREN);
    setState(954);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(953);
      returnSignature();
    }
    setState(956);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternOrSubroutineCallContext ------------------------------------------------------------------

qasm3Parser::ExternOrSubroutineCallContext::ExternOrSubroutineCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExternOrSubroutineCallContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ExternOrSubroutineCallContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::ExternOrSubroutineCallContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::ExternOrSubroutineCallContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::ExternOrSubroutineCallContext::getRuleIndex() const {
  return qasm3Parser::RuleExternOrSubroutineCall;
}


antlrcpp::Any qasm3Parser::ExternOrSubroutineCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitExternOrSubroutineCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternOrSubroutineCallContext* qasm3Parser::externOrSubroutineCall() {
  ExternOrSubroutineCallContext *_localctx = _tracker.createInstance<ExternOrSubroutineCallContext>(_ctx, getState());
  enterRule(_localctx, 184, qasm3Parser::RuleExternOrSubroutineCall);
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
    setState(958);
    match(qasm3Parser::Identifier);
    setState(959);
    match(qasm3Parser::LPAREN);
    setState(961);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::CREG)
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
      | (1ULL << qasm3Parser::SIZEOF)
      | (1ULL << qasm3Parser::BuiltinMath)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
      | (1ULL << (qasm3Parser::Constant - 67))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::Identifier - 67))
      | (1ULL << (qasm3Parser::FloatLiteral - 67))
      | (1ULL << (qasm3Parser::TimingLiteral - 67))
      | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
      setState(960);
      expressionList();
    }
    setState(963);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineDefinitionContext ------------------------------------------------------------------

qasm3Parser::SubroutineDefinitionContext::SubroutineDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::DEF() {
  return getToken(qasm3Parser::DEF, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineDefinitionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::SubroutineBlockContext* qasm3Parser::SubroutineDefinitionContext::subroutineBlock() {
  return getRuleContext<qasm3Parser::SubroutineBlockContext>(0);
}

qasm3Parser::AnyTypeArgumentListContext* qasm3Parser::SubroutineDefinitionContext::anyTypeArgumentList() {
  return getRuleContext<qasm3Parser::AnyTypeArgumentListContext>(0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::SubroutineDefinitionContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}


size_t qasm3Parser::SubroutineDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleSubroutineDefinition;
}


antlrcpp::Any qasm3Parser::SubroutineDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSubroutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineDefinitionContext* qasm3Parser::subroutineDefinition() {
  SubroutineDefinitionContext *_localctx = _tracker.createInstance<SubroutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 186, qasm3Parser::RuleSubroutineDefinition);
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
    setState(965);
    match(qasm3Parser::DEF);
    setState(966);
    match(qasm3Parser::Identifier);
    setState(967);
    match(qasm3Parser::LPAREN);
    setState(969);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::CONST)
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
      setState(968);
      anyTypeArgumentList();
    }
    setState(971);
    match(qasm3Parser::RPAREN);
    setState(973);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(972);
      returnSignature();
    }
    setState(975);
    subroutineBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineBlockContext ------------------------------------------------------------------

qasm3Parser::SubroutineBlockContext::SubroutineBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SubroutineBlockContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::SubroutineBlockContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::SubroutineBlockContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::SubroutineBlockContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::SubroutineBlockContext::returnStatement() {
  return getRuleContext<qasm3Parser::ReturnStatementContext>(0);
}


size_t qasm3Parser::SubroutineBlockContext::getRuleIndex() const {
  return qasm3Parser::RuleSubroutineBlock;
}


antlrcpp::Any qasm3Parser::SubroutineBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitSubroutineBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineBlockContext* qasm3Parser::subroutineBlock() {
  SubroutineBlockContext *_localctx = _tracker.createInstance<SubroutineBlockContext>(_ctx, getState());
  enterRule(_localctx, 188, qasm3Parser::RuleSubroutineBlock);
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
    setState(977);
    match(qasm3Parser::LBRACE);
    setState(981);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::BOX)
      | (1ULL << qasm3Parser::LET)
      | (1ULL << qasm3Parser::IF)
      | (1ULL << qasm3Parser::END)
      | (1ULL << qasm3Parser::FOR)
      | (1ULL << qasm3Parser::WHILE)
      | (1ULL << qasm3Parser::CONST)
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
      | (1ULL << qasm3Parser::U_)
      | (1ULL << qasm3Parser::CX)
      | (1ULL << qasm3Parser::GPHASE)
      | (1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL)
      | (1ULL << qasm3Parser::SIZEOF)
      | (1ULL << qasm3Parser::BuiltinMath)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::BuiltinTimingInstruction)
      | (1ULL << qasm3Parser::RESET)
      | (1ULL << qasm3Parser::MEASURE)
      | (1ULL << qasm3Parser::BARRIER)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
      | (1ULL << (qasm3Parser::Constant - 67))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::Identifier - 67))
      | (1ULL << (qasm3Parser::FloatLiteral - 67))
      | (1ULL << (qasm3Parser::TimingLiteral - 67))
      | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
      setState(978);
      statement();
      setState(983);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(985);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::RETURN) {
      setState(984);
      returnStatement();
    }
    setState(987);
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

tree::TerminalNode* qasm3Parser::PragmaContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::PragmaContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

std::vector<qasm3Parser::StatementContext *> qasm3Parser::PragmaContext::statement() {
  return getRuleContexts<qasm3Parser::StatementContext>();
}

qasm3Parser::StatementContext* qasm3Parser::PragmaContext::statement(size_t i) {
  return getRuleContext<qasm3Parser::StatementContext>(i);
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
  enterRule(_localctx, 190, qasm3Parser::RulePragma);
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
    setState(989);
    match(qasm3Parser::PRAGMA);
    setState(990);
    match(qasm3Parser::LBRACE);
    setState(994);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::BOX)
      | (1ULL << qasm3Parser::LET)
      | (1ULL << qasm3Parser::IF)
      | (1ULL << qasm3Parser::END)
      | (1ULL << qasm3Parser::FOR)
      | (1ULL << qasm3Parser::WHILE)
      | (1ULL << qasm3Parser::CONST)
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
      | (1ULL << qasm3Parser::U_)
      | (1ULL << qasm3Parser::CX)
      | (1ULL << qasm3Parser::GPHASE)
      | (1ULL << qasm3Parser::INV)
      | (1ULL << qasm3Parser::POW)
      | (1ULL << qasm3Parser::CTRL)
      | (1ULL << qasm3Parser::NEGCTRL)
      | (1ULL << qasm3Parser::SIZEOF)
      | (1ULL << qasm3Parser::BuiltinMath)
      | (1ULL << qasm3Parser::DURATIONOF)
      | (1ULL << qasm3Parser::BuiltinTimingInstruction)
      | (1ULL << qasm3Parser::RESET)
      | (1ULL << qasm3Parser::MEASURE)
      | (1ULL << qasm3Parser::BARRIER)
      | (1ULL << qasm3Parser::BooleanLiteral)
      | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
      | (1ULL << (qasm3Parser::TILDE - 67))
      | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
      | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
      | (1ULL << (qasm3Parser::Constant - 67))
      | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
      | (1ULL << (qasm3Parser::Identifier - 67))
      | (1ULL << (qasm3Parser::FloatLiteral - 67))
      | (1ULL << (qasm3Parser::TimingLiteral - 67))
      | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
      setState(991);
      statement();
      setState(996);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(997);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingBoxContext ------------------------------------------------------------------

qasm3Parser::TimingBoxContext::TimingBoxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::TimingBoxContext::BOX() {
  return getToken(qasm3Parser::BOX, 0);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::TimingBoxContext::quantumBlock() {
  return getRuleContext<qasm3Parser::QuantumBlockContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::TimingBoxContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::TimingBoxContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingBox;
}


antlrcpp::Any qasm3Parser::TimingBoxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitTimingBox(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingBoxContext* qasm3Parser::timingBox() {
  TimingBoxContext *_localctx = _tracker.createInstance<TimingBoxContext>(_ctx, getState());
  enterRule(_localctx, 192, qasm3Parser::RuleTimingBox);
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
    setState(999);
    match(qasm3Parser::BOX);
    setState(1001);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(1000);
      designator();
    }
    setState(1003);
    quantumBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingIdentifierContext ------------------------------------------------------------------

qasm3Parser::TimingIdentifierContext::TimingIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::TimingLiteral() {
  return getToken(qasm3Parser::TimingLiteral, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::DURATIONOF() {
  return getToken(qasm3Parser::DURATIONOF, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingIdentifierContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::TimingIdentifierContext::quantumBlock() {
  return getRuleContext<qasm3Parser::QuantumBlockContext>(0);
}


size_t qasm3Parser::TimingIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingIdentifier;
}


antlrcpp::Any qasm3Parser::TimingIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitTimingIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingIdentifierContext* qasm3Parser::timingIdentifier() {
  TimingIdentifierContext *_localctx = _tracker.createInstance<TimingIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 194, qasm3Parser::RuleTimingIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1013);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::TimingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(1005);
        match(qasm3Parser::TimingLiteral);
        break;
      }

      case qasm3Parser::DURATIONOF: {
        enterOuterAlt(_localctx, 2);
        setState(1006);
        match(qasm3Parser::DURATIONOF);
        setState(1007);
        match(qasm3Parser::LPAREN);
        setState(1010);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::Identifier: {
            setState(1008);
            match(qasm3Parser::Identifier);
            break;
          }

          case qasm3Parser::LBRACE: {
            setState(1009);
            quantumBlock();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1012);
        match(qasm3Parser::RPAREN);
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

//----------------- TimingInstructionContext ------------------------------------------------------------------

qasm3Parser::TimingInstructionContext::TimingInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::BuiltinTimingInstruction() {
  return getToken(qasm3Parser::BuiltinTimingInstruction, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::TimingInstructionContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

std::vector<qasm3Parser::IndexedIdentifierContext *> qasm3Parser::TimingInstructionContext::indexedIdentifier() {
  return getRuleContexts<qasm3Parser::IndexedIdentifierContext>();
}

qasm3Parser::IndexedIdentifierContext* qasm3Parser::TimingInstructionContext::indexedIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexedIdentifierContext>(i);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::TimingInstructionContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}

qasm3Parser::ExpressionListContext* qasm3Parser::TimingInstructionContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::TimingInstructionContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingInstruction;
}


antlrcpp::Any qasm3Parser::TimingInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitTimingInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingInstructionContext* qasm3Parser::timingInstruction() {
  TimingInstructionContext *_localctx = _tracker.createInstance<TimingInstructionContext>(_ctx, getState());
  enterRule(_localctx, 196, qasm3Parser::RuleTimingInstruction);
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
    setState(1015);
    match(qasm3Parser::BuiltinTimingInstruction);
    setState(1021);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(1016);
      match(qasm3Parser::LPAREN);
      setState(1018);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::CREG)
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
        | (1ULL << qasm3Parser::SIZEOF)
        | (1ULL << qasm3Parser::BuiltinMath)
        | (1ULL << qasm3Parser::DURATIONOF)
        | (1ULL << qasm3Parser::BooleanLiteral)
        | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
        | (1ULL << (qasm3Parser::TILDE - 67))
        | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
        | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
        | (1ULL << (qasm3Parser::Constant - 67))
        | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::Identifier - 67))
        | (1ULL << (qasm3Parser::FloatLiteral - 67))
        | (1ULL << (qasm3Parser::TimingLiteral - 67))
        | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
        setState(1017);
        expressionList();
      }
      setState(1020);
      match(qasm3Parser::RPAREN);
    }
    setState(1023);
    designator();
    setState(1024);
    indexedIdentifier();
    setState(1029);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(1025);
      match(qasm3Parser::COMMA);
      setState(1026);
      indexedIdentifier();
      setState(1031);
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

//----------------- TimingStatementContext ------------------------------------------------------------------

qasm3Parser::TimingStatementContext::TimingStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingInstructionContext* qasm3Parser::TimingStatementContext::timingInstruction() {
  return getRuleContext<qasm3Parser::TimingInstructionContext>(0);
}

tree::TerminalNode* qasm3Parser::TimingStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

qasm3Parser::TimingBoxContext* qasm3Parser::TimingStatementContext::timingBox() {
  return getRuleContext<qasm3Parser::TimingBoxContext>(0);
}


size_t qasm3Parser::TimingStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingStatement;
}


antlrcpp::Any qasm3Parser::TimingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitTimingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingStatementContext* qasm3Parser::timingStatement() {
  TimingStatementContext *_localctx = _tracker.createInstance<TimingStatementContext>(_ctx, getState());
  enterRule(_localctx, 198, qasm3Parser::RuleTimingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1036);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::BuiltinTimingInstruction: {
        enterOuterAlt(_localctx, 1);
        setState(1032);
        timingInstruction();
        setState(1033);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::BOX: {
        enterOuterAlt(_localctx, 2);
        setState(1035);
        timingBox();
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

//----------------- CalibrationContext ------------------------------------------------------------------

qasm3Parser::CalibrationContext::CalibrationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::CalibrationGrammarDeclarationContext* qasm3Parser::CalibrationContext::calibrationGrammarDeclaration() {
  return getRuleContext<qasm3Parser::CalibrationGrammarDeclarationContext>(0);
}

qasm3Parser::CalibrationDefinitionContext* qasm3Parser::CalibrationContext::calibrationDefinition() {
  return getRuleContext<qasm3Parser::CalibrationDefinitionContext>(0);
}


size_t qasm3Parser::CalibrationContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibration;
}


antlrcpp::Any qasm3Parser::CalibrationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalibration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationContext* qasm3Parser::calibration() {
  CalibrationContext *_localctx = _tracker.createInstance<CalibrationContext>(_ctx, getState());
  enterRule(_localctx, 200, qasm3Parser::RuleCalibration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1040);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::DEFCALGRAMMAR: {
        enterOuterAlt(_localctx, 1);
        setState(1038);
        calibrationGrammarDeclaration();
        break;
      }

      case qasm3Parser::DEFCAL: {
        enterOuterAlt(_localctx, 2);
        setState(1039);
        calibrationDefinition();
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

//----------------- CalibrationGrammarDeclarationContext ------------------------------------------------------------------

qasm3Parser::CalibrationGrammarDeclarationContext::CalibrationGrammarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarDeclarationContext::DEFCALGRAMMAR() {
  return getToken(qasm3Parser::DEFCALGRAMMAR, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarDeclarationContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarDeclarationContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::CalibrationGrammarDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammarDeclaration;
}


antlrcpp::Any qasm3Parser::CalibrationGrammarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalibrationGrammarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarDeclarationContext* qasm3Parser::calibrationGrammarDeclaration() {
  CalibrationGrammarDeclarationContext *_localctx = _tracker.createInstance<CalibrationGrammarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 202, qasm3Parser::RuleCalibrationGrammarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1042);
    match(qasm3Parser::DEFCALGRAMMAR);
    setState(1043);
    match(qasm3Parser::StringLiteral);
    setState(1044);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationDefinitionContext ------------------------------------------------------------------

qasm3Parser::CalibrationDefinitionContext::CalibrationDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::DEFCAL() {
  return getToken(qasm3Parser::DEFCAL, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::IdentifierListContext* qasm3Parser::CalibrationDefinitionContext::identifierList() {
  return getRuleContext<qasm3Parser::IdentifierListContext>(0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::CalibrationDefinitionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ReturnSignatureContext* qasm3Parser::CalibrationDefinitionContext::returnSignature() {
  return getRuleContext<qasm3Parser::ReturnSignatureContext>(0);
}

qasm3Parser::CalibrationArgumentListContext* qasm3Parser::CalibrationDefinitionContext::calibrationArgumentList() {
  return getRuleContext<qasm3Parser::CalibrationArgumentListContext>(0);
}


size_t qasm3Parser::CalibrationDefinitionContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationDefinition;
}


antlrcpp::Any qasm3Parser::CalibrationDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalibrationDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationDefinitionContext* qasm3Parser::calibrationDefinition() {
  CalibrationDefinitionContext *_localctx = _tracker.createInstance<CalibrationDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 204, qasm3Parser::RuleCalibrationDefinition);
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
    setState(1046);
    match(qasm3Parser::DEFCAL);
    setState(1047);
    match(qasm3Parser::Identifier);
    setState(1053);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(1048);
      match(qasm3Parser::LPAREN);
      setState(1050);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::CONST)
        | (1ULL << qasm3Parser::MUTABLE)
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
        | (1ULL << qasm3Parser::SIZEOF)
        | (1ULL << qasm3Parser::BuiltinMath)
        | (1ULL << qasm3Parser::DURATIONOF)
        | (1ULL << qasm3Parser::BooleanLiteral)
        | (1ULL << qasm3Parser::LPAREN))) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 67)) & ((1ULL << (qasm3Parser::MINUS - 67))
        | (1ULL << (qasm3Parser::TILDE - 67))
        | (1ULL << (qasm3Parser::EXCLAMATION_POINT - 67))
        | (1ULL << (qasm3Parser::ImaginaryLiteral - 67))
        | (1ULL << (qasm3Parser::Constant - 67))
        | (1ULL << (qasm3Parser::BinaryIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::OctalIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::DecimalIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::HexIntegerLiteral - 67))
        | (1ULL << (qasm3Parser::Identifier - 67))
        | (1ULL << (qasm3Parser::FloatLiteral - 67))
        | (1ULL << (qasm3Parser::TimingLiteral - 67))
        | (1ULL << (qasm3Parser::BitstringLiteral - 67)))) != 0)) {
        setState(1049);
        calibrationArgumentList();
      }
      setState(1052);
      match(qasm3Parser::RPAREN);
    }
    setState(1055);
    identifierList();
    setState(1057);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(1056);
      returnSignature();
    }
    setState(1059);
    match(qasm3Parser::LBRACE);
    setState(1063);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(1060);
        matchWildcard(); 
      }
      setState(1065);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx);
    }
    setState(1066);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationArgumentListContext ------------------------------------------------------------------

qasm3Parser::CalibrationArgumentListContext::CalibrationArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::ClassicalArgumentListContext* qasm3Parser::CalibrationArgumentListContext::classicalArgumentList() {
  return getRuleContext<qasm3Parser::ClassicalArgumentListContext>(0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::CalibrationArgumentListContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::CalibrationArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationArgumentList;
}


antlrcpp::Any qasm3Parser::CalibrationArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3ParserVisitor*>(visitor))
    return parserVisitor->visitCalibrationArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationArgumentListContext* qasm3Parser::calibrationArgumentList() {
  CalibrationArgumentListContext *_localctx = _tracker.createInstance<CalibrationArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 206, qasm3Parser::RuleCalibrationArgumentList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1070);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1068);
      classicalArgumentList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1069);
      expressionList();
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

bool qasm3Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 61: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 62: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 63: return bitOrExpressionSempred(dynamic_cast<BitOrExpressionContext *>(context), predicateIndex);
    case 64: return xOrExpressionSempred(dynamic_cast<XOrExpressionContext *>(context), predicateIndex);
    case 65: return bitAndExpressionSempred(dynamic_cast<BitAndExpressionContext *>(context), predicateIndex);
    case 66: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 67: return comparisonExpressionSempred(dynamic_cast<ComparisonExpressionContext *>(context), predicateIndex);
    case 68: return bitShiftExpressionSempred(dynamic_cast<BitShiftExpressionContext *>(context), predicateIndex);
    case 69: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 70: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 72: return powerExpressionSempred(dynamic_cast<PowerExpressionContext *>(context), predicateIndex);
    case 74: return indexExpressionSempred(dynamic_cast<IndexExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitOrExpressionSempred(BitOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::xOrExpressionSempred(XOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitAndExpressionSempred(BitAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::comparisonExpressionSempred(ComparisonExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitShiftExpressionSempred(BitShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::powerExpressionSempred(PowerExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::indexExpressionSempred(IndexExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 1);

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
  "program", "header", "version", "include", "ioIdentifier", "io", "globalStatement", 
  "statement", "quantumDeclarationStatement", "classicalDeclarationStatement", 
  "classicalAssignment", "assignmentStatement", "returnSignature", "designator", 
  "identifierList", "quantumDeclaration", "quantumArgument", "bitType", 
  "singleDesignatorType", "noDesignatorType", "nonArrayType", "arrayType", 
  "arrayReferenceTypeDimensionSpecifier", "arrayReferenceType", "classicalType", 
  "numericType", "constantDeclaration", "singleDesignatorDeclaration", "noDesignatorDeclaration", 
  "bitDeclaration", "complexDeclaration", "arrayInitializer", "arrayDeclaration", 
  "classicalDeclaration", "classicalTypeList", "classicalArgument", "classicalArgumentList", 
  "anyTypeArgument", "anyTypeArgumentList", "aliasInitializer", "aliasStatement", 
  "rangeDefinition", "quantumGateDefinition", "quantumGateSignature", "quantumGateName", 
  "quantumBlock", "quantumLoop", "quantumLoopBlock", "quantumStatement", 
  "quantumInstruction", "quantumBarrier", "quantumMeasurement", "quantumPhase", 
  "quantumReset", "quantumMeasurementAssignment", "powModifier", "ctrlModifier", 
  "quantumGateModifier", "quantumGateCall", "unaryOperator", "expressionStatement", 
  "expression", "logicalAndExpression", "bitOrExpression", "xOrExpression", 
  "bitAndExpression", "equalityExpression", "comparisonExpression", "bitShiftExpression", 
  "additiveExpression", "multiplicativeExpression", "unaryExpression", "powerExpression", 
  "indexOperator", "indexExpression", "indexedIdentifier", "expressionTerminator", 
  "builtInCall", "castOperator", "expressionList", "equalsExpression", "assignmentOperator", 
  "discreteSet", "setDeclaration", "programBlock", "branchingStatement", 
  "loopSignature", "loopStatement", "endStatement", "returnStatement", "controlDirective", 
  "externDeclaration", "externOrSubroutineCall", "subroutineDefinition", 
  "subroutineBlock", "pragma", "timingBox", "timingIdentifier", "timingInstruction", 
  "timingStatement", "calibration", "calibrationGrammarDeclaration", "calibrationDefinition", 
  "calibrationArgumentList"
};

std::vector<std::string> qasm3Parser::_literalNames = {
  "", "'OPENQASM'", "'include'", "'#pragma'", "'defcalgrammar'", "'def'", 
  "'defcal'", "'gate'", "'extern'", "'box'", "'let'", "'break'", "'continue'", 
  "'if'", "'else'", "'end'", "'return'", "'for'", "'while'", "'in'", "'input'", 
  "'output'", "'const'", "'mutable'", "'qreg'", "'qubit'", "'creg'", "'bool'", 
  "'bit'", "'int'", "'uint'", "'float'", "'angle'", "'complex'", "'array'", 
  "'duration'", "'stretch'", "'U'", "'CX'", "'gphase'", "'inv'", "'pow'", 
  "'ctrl'", "'negctrl'", "'#dim'", "'sizeof'", "", "'durationof'", "", "'reset'", 
  "'measure'", "'barrier'", "", "'['", "']'", "'{'", "'}'", "'('", "')'", 
  "':'", "';'", "'.'", "','", "'='", "'->'", "'+'", "'++'", "'-'", "'*'", 
  "'**'", "'/'", "'%'", "'|'", "'||'", "'&'", "'&&'", "'^'", "'@'", "'~'", 
  "'!'", "", "", "", "", "'im'"
};

std::vector<std::string> qasm3Parser::_symbolicNames = {
  "", "OPENQASM", "INCLUDE", "PRAGMA", "DEFCALGRAMMAR", "DEF", "DEFCAL", 
  "GATE", "EXTERN", "BOX", "LET", "BREAK", "CONTINUE", "IF", "ELSE", "END", 
  "RETURN", "FOR", "WHILE", "IN", "INPUT", "OUTPUT", "CONST", "MUTABLE", 
  "QREG", "QUBIT", "CREG", "BOOL", "BIT", "INT", "UINT", "FLOAT", "ANGLE", 
  "COMPLEX", "ARRAY", "DURATION", "STRETCH", "U_", "CX", "GPHASE", "INV", 
  "POW", "CTRL", "NEGCTRL", "DIM", "SIZEOF", "BuiltinMath", "DURATIONOF", 
  "BuiltinTimingInstruction", "RESET", "MEASURE", "BARRIER", "BooleanLiteral", 
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "COLON", 
  "SEMICOLON", "DOT", "COMMA", "EQUALS", "ARROW", "PLUS", "DOUBLE_PLUS", 
  "MINUS", "ASTERISK", "DOUBLE_ASTERISK", "SLASH", "PERCENT", "PIPE", "DOUBLE_PIPE", 
  "AMPERSAND", "DOUBLE_AMPERSAND", "CARET", "AT", "TILDE", "EXCLAMATION_POINT", 
  "EqualityOperator", "CompoundAssignmentOperator", "ComparisonOperator", 
  "BitshiftOperator", "IMAG", "ImaginaryLiteral", "Constant", "BinaryIntegerLiteral", 
  "OctalIntegerLiteral", "DecimalIntegerLiteral", "HexIntegerLiteral", "Identifier", 
  "FloatLiteral", "TimingLiteral", "BitstringLiteral", "StringLiteral", 
  "Whitespace", "Newline", "LineComment", "BlockComment"
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
       0x3, 0x65, 0x433, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
       0x2, 0xd6, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd9, 0xb, 0x2, 0x3, 0x3, 
       0x5, 0x3, 0xdc, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0xdf, 0xa, 0x3, 0xc, 
       0x3, 0xe, 0x3, 0xe2, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0xe5, 0xa, 0x3, 
       0xc, 0x3, 0xe, 0x3, 0xe8, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xff, 
       0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x109, 0xa, 0x9, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x110, 0xa, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
       0x3, 0xd, 0x5, 0xd, 0x11a, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x128, 0xa, 0x10, 0xc, 0x10, 
       0xe, 0x10, 0x12b, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 
       0x11, 0x130, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x134, 0xa, 
       0x11, 0x3, 0x11, 0x5, 0x11, 0x137, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x5, 0x12, 0x13c, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 
       0x12, 0x140, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0x143, 0xa, 0x12, 0x3, 
       0x13, 0x3, 0x13, 0x5, 0x13, 0x147, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 
       0x5, 0x14, 0x14b, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x5, 0x16, 0x157, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x164, 0xa, 0x18, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x16f, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x17b, 0xa, 0x1d, 0x3, 0x1e, 0x3, 
       0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x180, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x5, 0x1f, 0x185, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
       0x1f, 0x189, 0xa, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x18c, 0xa, 0x1f, 0x3, 
       0x1f, 0x5, 0x1f, 0x18f, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x197, 0xa, 0x20, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x19c, 0xa, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x1a1, 0xa, 0x21, 0x7, 0x21, 0x1a3, 
       0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x1a6, 0xb, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 
       0x22, 0x1af, 0xa, 0x22, 0x5, 0x22, 0x1b1, 0xa, 0x22, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1b8, 0xa, 0x23, 
       0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x1bd, 0xa, 0x24, 0xc, 
       0x24, 0xe, 0x24, 0x1c0, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 
       0x1c4, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x5, 0x25, 0x1cb, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 
       0x1cf, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x5, 0x25, 0x1dc, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x7, 0x26, 0x1e1, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x1e4, 0xb, 0x26, 
       0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1e8, 0xa, 0x27, 0x3, 0x28, 0x3, 
       0x28, 0x3, 0x28, 0x7, 0x28, 0x1ed, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 
       0x1f0, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x1f5, 
       0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x1f8, 0xb, 0x29, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x5, 
       0x2b, 0x201, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x205, 0xa, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x209, 0xa, 0x2b, 0x3, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x5, 0x2d, 0x212, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x215, 0xa, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x7, 0x2f, 0x21e, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x221, 
       0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x22b, 0xa, 0x31, 0xc, 
       0x31, 0xe, 0x31, 0x22e, 0xb, 0x31, 0x3, 0x31, 0x5, 0x31, 0x231, 0xa, 
       0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x237, 
       0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
       0x5, 0x33, 0x23e, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x7, 0x34, 0x244, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x247, 0xb, 
       0x34, 0x5, 0x34, 0x249, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 
       0x3, 0x36, 0x7, 0x36, 0x24f, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x252, 
       0xb, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x25b, 0xa, 0x36, 0xc, 0x36, 0xe, 
       0x36, 0x25e, 0xb, 0x36, 0x5, 0x36, 0x260, 0xa, 0x36, 0x3, 0x37, 0x3, 
       0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x268, 
       0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 
       0x26e, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 
       0x3a, 0x27a, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 
       0x27f, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x7, 0x3c, 0x284, 
       0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x287, 0xb, 0x3c, 0x3, 0x3c, 0x3, 
       0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 0x28e, 0xa, 0x3c, 
       0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x293, 0xa, 0x3c, 0xc, 
       0x3c, 0xe, 0x3c, 0x296, 0xb, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 
       0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
       0x5, 0x3f, 0x2a1, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 
       0x3f, 0x2a6, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x2a9, 0xb, 0x3f, 0x3, 
       0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 
       0x40, 0x2b1, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x2b4, 0xb, 0x40, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 
       0x41, 0x2bc, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x2bf, 0xb, 0x41, 0x3, 
       0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 
       0x42, 0x2c7, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x2ca, 0xb, 0x42, 0x3, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 
       0x43, 0x2d2, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x2d5, 0xb, 0x43, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 
       0x44, 0x2dd, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x2e0, 0xb, 0x44, 0x3, 
       0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 
       0x45, 0x2e8, 0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x2eb, 0xb, 0x45, 0x3, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 
       0x46, 0x2f3, 0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x2f6, 0xb, 0x46, 0x3, 
       0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 
       0x47, 0x2fe, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x301, 0xb, 0x47, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 
       0x48, 0x309, 0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x30c, 0xb, 0x48, 0x3, 
       0x49, 0x5, 0x49, 0x30f, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 
       0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 
       0x319, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x31c, 0xb, 0x4a, 0x3, 0x4b, 
       0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x322, 0xa, 0x4b, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x327, 0xa, 0x4b, 0x7, 0x4b, 
       0x329, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x32c, 0xb, 0x4b, 0x5, 0x4b, 
       0x32e, 0xa, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x337, 0xa, 0x4c, 0xc, 0x4c, 
       0xe, 0x4c, 0x33a, 0xb, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x33e, 
       0xa, 0x4d, 0xc, 0x4d, 0xe, 0x4d, 0x341, 0xb, 0x4d, 0x3, 0x4e, 0x3, 
       0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
       0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
       0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x354, 0xa, 0x4e, 
       0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x359, 0xa, 0x4f, 0x3, 
       0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 
       0x51, 0x3, 0x51, 0x3, 0x51, 0x7, 0x51, 0x364, 0xa, 0x51, 0xc, 0x51, 
       0xe, 0x51, 0x367, 0xb, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 
       0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x7, 
       0x54, 0x372, 0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 0x375, 0xb, 0x54, 0x3, 
       0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x5, 0x55, 0x37f, 0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 
       0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 0x386, 0xa, 0x56, 0xc, 
       0x56, 0xe, 0x56, 0x389, 0xb, 0x56, 0x3, 0x56, 0x5, 0x56, 0x38c, 0xa, 
       0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 
       0x57, 0x3, 0x57, 0x5, 0x57, 0x395, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 
       0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 
       0x3, 0x58, 0x5, 0x58, 0x3a0, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 
       0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 
       0x5b, 0x5, 0x5b, 0x3ab, 0xa, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 
       0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x3b3, 0xa, 0x5c, 0x3, 
       0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3b9, 0xa, 0x5d, 
       0x3, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3bd, 0xa, 0x5d, 0x3, 0x5d, 0x3, 
       0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x5, 0x5e, 0x3c4, 0xa, 0x5e, 
       0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 
       0x5, 0x5f, 0x3cc, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x3d0, 
       0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x7, 0x60, 
       0x3d6, 0xa, 0x60, 0xc, 0x60, 0xe, 0x60, 0x3d9, 0xb, 0x60, 0x3, 0x60, 
       0x5, 0x60, 0x3dc, 0xa, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 
       0x61, 0x3, 0x61, 0x7, 0x61, 0x3e3, 0xa, 0x61, 0xc, 0x61, 0xe, 0x61, 
       0x3e6, 0xb, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 0x5, 
       0x62, 0x3ec, 0xa, 0x62, 0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 
       0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x5, 0x63, 0x3f5, 0xa, 0x63, 0x3, 
       0x63, 0x5, 0x63, 0x3f8, 0xa, 0x63, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 
       0x5, 0x64, 0x3fd, 0xa, 0x64, 0x3, 0x64, 0x5, 0x64, 0x400, 0xa, 0x64, 
       0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x7, 0x64, 0x406, 0xa, 
       0x64, 0xc, 0x64, 0xe, 0x64, 0x409, 0xb, 0x64, 0x3, 0x65, 0x3, 0x65, 
       0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 0x40f, 0xa, 0x65, 0x3, 0x66, 0x3, 
       0x66, 0x5, 0x66, 0x413, 0xa, 0x66, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 
       0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x68, 0x5, 0x68, 
       0x41d, 0xa, 0x68, 0x3, 0x68, 0x5, 0x68, 0x420, 0xa, 0x68, 0x3, 0x68, 
       0x3, 0x68, 0x5, 0x68, 0x424, 0xa, 0x68, 0x3, 0x68, 0x3, 0x68, 0x7, 
       0x68, 0x428, 0xa, 0x68, 0xc, 0x68, 0xe, 0x68, 0x42b, 0xb, 0x68, 0x3, 
       0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 0x431, 0xa, 0x69, 
       0x3, 0x69, 0x3, 0x429, 0xe, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 
       0x8a, 0x8c, 0x8e, 0x92, 0x96, 0x6a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
       0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
       0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
       0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 
       0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
       0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0x2, 
       0xf, 0x4, 0x2, 0x5b, 0x5b, 0x5e, 0x5e, 0x3, 0x2, 0x16, 0x17, 0x4, 
       0x2, 0x1c, 0x1c, 0x1e, 0x1e, 0x3, 0x2, 0x1f, 0x22, 0x4, 0x2, 0x1d, 
       0x1d, 0x25, 0x26, 0x3, 0x2, 0x18, 0x19, 0x4, 0x2, 0x27, 0x28, 0x5d, 
       0x5d, 0x3, 0x2, 0x2c, 0x2d, 0x4, 0x2, 0x45, 0x45, 0x50, 0x51, 0x4, 
       0x2, 0x43, 0x43, 0x45, 0x45, 0x4, 0x2, 0x46, 0x46, 0x48, 0x49, 0x4, 
       0x2, 0x41, 0x41, 0x53, 0x53, 0x3, 0x2, 0xd, 0xe, 0x2, 0x468, 0x2, 
       0xd2, 0x3, 0x2, 0x2, 0x2, 0x4, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x6, 0xe9, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0xed, 0x3, 0x2, 0x2, 0x2, 0xa, 0xf1, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xe, 0xfe, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x108, 0x3, 0x2, 0x2, 0x2, 0x12, 0x10a, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x16, 0x113, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0x119, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x11d, 0x3, 0x2, 
       0x2, 0x2, 0x1c, 0x120, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x124, 0x3, 0x2, 
       0x2, 0x2, 0x20, 0x136, 0x3, 0x2, 0x2, 0x2, 0x22, 0x142, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x144, 0x3, 0x2, 0x2, 0x2, 0x26, 0x148, 0x3, 0x2, 
       0x2, 0x2, 0x28, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x156, 0x3, 0x2, 
       0x2, 0x2, 0x2c, 0x158, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x163, 0x3, 0x2, 
       0x2, 0x2, 0x30, 0x165, 0x3, 0x2, 0x2, 0x2, 0x32, 0x16e, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x170, 0x3, 0x2, 0x2, 0x2, 0x36, 0x172, 0x3, 0x2, 
       0x2, 0x2, 0x38, 0x177, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x17c, 0x3, 0x2, 
       0x2, 0x2, 0x3c, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x190, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x198, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1a9, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1b9, 0x3, 0x2, 
       0x2, 0x2, 0x48, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1dd, 0x3, 0x2, 
       0x2, 0x2, 0x4c, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1e9, 0x3, 0x2, 
       0x2, 0x2, 0x50, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x52, 0x1f9, 0x3, 0x2, 
       0x2, 0x2, 0x54, 0x200, 0x3, 0x2, 0x2, 0x2, 0x56, 0x20a, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x218, 0x3, 0x2, 
       0x2, 0x2, 0x5c, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x224, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x230, 0x3, 0x2, 0x2, 0x2, 0x62, 0x236, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x66, 0x23f, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x250, 0x3, 0x2, 
       0x2, 0x2, 0x6c, 0x261, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x26d, 0x3, 0x2, 
       0x2, 0x2, 0x70, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x72, 0x274, 0x3, 0x2, 
       0x2, 0x2, 0x74, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x76, 0x285, 0x3, 0x2, 
       0x2, 0x2, 0x78, 0x297, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x299, 0x3, 0x2, 
       0x2, 0x2, 0x7c, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x2aa, 0x3, 0x2, 
       0x2, 0x2, 0x80, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x82, 0x2c0, 0x3, 0x2, 
       0x2, 0x2, 0x84, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2d6, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2ec, 0x3, 0x2, 
       0x2, 0x2, 0x8c, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x302, 0x3, 0x2, 
       0x2, 0x2, 0x90, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x92, 0x312, 0x3, 0x2, 
       0x2, 0x2, 0x94, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x96, 0x331, 0x3, 0x2, 
       0x2, 0x2, 0x98, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x353, 0x3, 0x2, 
       0x2, 0x2, 0x9c, 0x358, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x35e, 0x3, 0x2, 
       0x2, 0x2, 0xa0, 0x360, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x368, 0x3, 0x2, 
       0x2, 0x2, 0xa4, 0x36b, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x36d, 0x3, 0x2, 
       0x2, 0x2, 0xa8, 0x37e, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x38b, 0x3, 0x2, 
       0x2, 0x2, 0xac, 0x38d, 0x3, 0x2, 0x2, 0x2, 0xae, 0x39f, 0x3, 0x2, 
       0x2, 0x2, 0xb0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x3a4, 0x3, 0x2, 
       0x2, 0x2, 0xb4, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x3b2, 0x3, 0x2, 
       0x2, 0x2, 0xb8, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0xba, 0x3c0, 0x3, 0x2, 
       0x2, 0x2, 0xbc, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x3d3, 0x3, 0x2, 
       0x2, 0x2, 0xc0, 0x3df, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x3e9, 0x3, 0x2, 
       0x2, 0x2, 0xc4, 0x3f7, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x3f9, 0x3, 0x2, 
       0x2, 0x2, 0xc8, 0x40e, 0x3, 0x2, 0x2, 0x2, 0xca, 0x412, 0x3, 0x2, 
       0x2, 0x2, 0xcc, 0x414, 0x3, 0x2, 0x2, 0x2, 0xce, 0x418, 0x3, 0x2, 
       0x2, 0x2, 0xd0, 0x430, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd7, 0x5, 0x4, 
       0x3, 0x2, 0xd3, 0xd6, 0x5, 0xe, 0x8, 0x2, 0xd4, 0xd6, 0x5, 0x10, 
       0x9, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 
       0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 
       0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x3, 0x3, 0x2, 0x2, 0x2, 0xd9, 
       0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdc, 0x5, 0x6, 0x4, 0x2, 0xdb, 0xda, 
       0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x3, 
       0x2, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x8, 0x5, 0x2, 0xde, 0xdd, 0x3, 0x2, 
       0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe6, 0x3, 0x2, 0x2, 0x2, 
       0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x5, 0xc, 0x7, 0x2, 0xe4, 
       0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 
       0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0x3, 
       0x2, 0x2, 0xea, 0xeb, 0x9, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x3e, 
       0x2, 0x2, 0xec, 0x7, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0x4, 0x2, 
       0x2, 0xee, 0xef, 0x7, 0x61, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x3e, 0x2, 
       0x2, 0xf0, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x9, 0x3, 0x2, 0x2, 
       0xf2, 0xb, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0xa, 0x6, 0x2, 0xf4, 
       0xf5, 0x5, 0x32, 0x1a, 0x2, 0xf5, 0xf6, 0x7, 0x5d, 0x2, 0x2, 0xf6, 
       0xf7, 0x7, 0x3e, 0x2, 0x2, 0xf7, 0xd, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xff, 
       0x5, 0xbc, 0x5f, 0x2, 0xf9, 0xff, 0x5, 0xb8, 0x5d, 0x2, 0xfa, 0xff, 
       0x5, 0x56, 0x2c, 0x2, 0xfb, 0xff, 0x5, 0xca, 0x66, 0x2, 0xfc, 0xff, 
       0x5, 0x12, 0xa, 0x2, 0xfd, 0xff, 0x5, 0xc0, 0x61, 0x2, 0xfe, 0xf8, 
       0x3, 0x2, 0x2, 0x2, 0xfe, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfa, 0x3, 
       0x2, 0x2, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 
       0x2, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 0xf, 0x3, 0x2, 0x2, 
       0x2, 0x100, 0x109, 0x5, 0x7a, 0x3e, 0x2, 0x101, 0x109, 0x5, 0x18, 
       0xd, 0x2, 0x102, 0x109, 0x5, 0x14, 0xb, 0x2, 0x103, 0x109, 0x5, 0xac, 
       0x57, 0x2, 0x104, 0x109, 0x5, 0xb0, 0x59, 0x2, 0x105, 0x109, 0x5, 
       0xb2, 0x5a, 0x2, 0x106, 0x109, 0x5, 0x52, 0x2a, 0x2, 0x107, 0x109, 
       0x5, 0x62, 0x32, 0x2, 0x108, 0x100, 0x3, 0x2, 0x2, 0x2, 0x108, 0x101, 
       0x3, 0x2, 0x2, 0x2, 0x108, 0x102, 0x3, 0x2, 0x2, 0x2, 0x108, 0x103, 
       0x3, 0x2, 0x2, 0x2, 0x108, 0x104, 0x3, 0x2, 0x2, 0x2, 0x108, 0x105, 
       0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x107, 
       0x3, 0x2, 0x2, 0x2, 0x109, 0x11, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 
       0x5, 0x20, 0x11, 0x2, 0x10b, 0x10c, 0x7, 0x3e, 0x2, 0x2, 0x10c, 0x13, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x5, 0x44, 0x23, 0x2, 0x10e, 0x110, 
       0x5, 0x36, 0x1c, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10e, 
       0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 
       0x7, 0x3e, 0x2, 0x2, 0x112, 0x15, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 
       0x5, 0x98, 0x4d, 0x2, 0x114, 0x115, 0x5, 0xa4, 0x53, 0x2, 0x115, 
       0x116, 0x5, 0x7c, 0x3f, 0x2, 0x116, 0x17, 0x3, 0x2, 0x2, 0x2, 0x117, 
       0x11a, 0x5, 0x16, 0xc, 0x2, 0x118, 0x11a, 0x5, 0x6e, 0x38, 0x2, 0x119, 
       0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 
       0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x3e, 0x2, 0x2, 0x11c, 
       0x19, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0x42, 0x2, 0x2, 0x11e, 
       0x11f, 0x5, 0x32, 0x1a, 0x2, 0x11f, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x120, 
       0x121, 0x7, 0x37, 0x2, 0x2, 0x121, 0x122, 0x5, 0x7c, 0x3f, 0x2, 0x122, 
       0x123, 0x7, 0x38, 0x2, 0x2, 0x123, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x124, 
       0x129, 0x7, 0x5d, 0x2, 0x2, 0x125, 0x126, 0x7, 0x40, 0x2, 0x2, 0x126, 
       0x128, 0x7, 0x5d, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x128, 
       0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 
       0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x12b, 
       0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x1a, 0x2, 0x2, 0x12d, 
       0x12f, 0x7, 0x5d, 0x2, 0x2, 0x12e, 0x130, 0x5, 0x1c, 0xf, 0x2, 0x12f, 
       0x12e, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 
       0x137, 0x3, 0x2, 0x2, 0x2, 0x131, 0x133, 0x7, 0x1b, 0x2, 0x2, 0x132, 
       0x134, 0x5, 0x1c, 0xf, 0x2, 0x133, 0x132, 0x3, 0x2, 0x2, 0x2, 0x133, 
       0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 
       0x137, 0x7, 0x5d, 0x2, 0x2, 0x136, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x136, 
       0x131, 0x3, 0x2, 0x2, 0x2, 0x137, 0x21, 0x3, 0x2, 0x2, 0x2, 0x138, 
       0x139, 0x7, 0x1a, 0x2, 0x2, 0x139, 0x13b, 0x7, 0x5d, 0x2, 0x2, 0x13a, 
       0x13c, 0x5, 0x1c, 0xf, 0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13b, 
       0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x143, 0x3, 0x2, 0x2, 0x2, 0x13d, 
       0x13f, 0x7, 0x1b, 0x2, 0x2, 0x13e, 0x140, 0x5, 0x1c, 0xf, 0x2, 0x13f, 
       0x13e, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
       0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x143, 0x7, 0x5d, 0x2, 0x2, 0x142, 
       0x138, 0x3, 0x2, 0x2, 0x2, 0x142, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x143, 
       0x23, 0x3, 0x2, 0x2, 0x2, 0x144, 0x146, 0x9, 0x4, 0x2, 0x2, 0x145, 
       0x147, 0x5, 0x1c, 0xf, 0x2, 0x146, 0x145, 0x3, 0x2, 0x2, 0x2, 0x146, 
       0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 0x25, 0x3, 0x2, 0x2, 0x2, 0x148, 
       0x14a, 0x9, 0x5, 0x2, 0x2, 0x149, 0x14b, 0x5, 0x1c, 0xf, 0x2, 0x14a, 
       0x149, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x9, 0x6, 0x2, 0x2, 0x14d, 
       0x29, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x157, 0x5, 0x26, 0x14, 0x2, 0x14f, 
       0x157, 0x5, 0x28, 0x15, 0x2, 0x150, 0x157, 0x5, 0x24, 0x13, 0x2, 
       0x151, 0x152, 0x7, 0x23, 0x2, 0x2, 0x152, 0x153, 0x7, 0x37, 0x2, 
       0x2, 0x153, 0x154, 0x5, 0x34, 0x1b, 0x2, 0x154, 0x155, 0x7, 0x38, 
       0x2, 0x2, 0x155, 0x157, 0x3, 0x2, 0x2, 0x2, 0x156, 0x14e, 0x3, 0x2, 
       0x2, 0x2, 0x156, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x156, 0x150, 0x3, 0x2, 
       0x2, 0x2, 0x156, 0x151, 0x3, 0x2, 0x2, 0x2, 0x157, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x158, 0x159, 0x7, 0x24, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x37, 
       0x2, 0x2, 0x15a, 0x15b, 0x5, 0x2a, 0x16, 0x2, 0x15b, 0x15c, 0x7, 
       0x40, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0xa0, 0x51, 0x2, 0x15d, 0x15e, 
       0x7, 0x38, 0x2, 0x2, 0x15e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x164, 
       0x5, 0xa0, 0x51, 0x2, 0x160, 0x161, 0x7, 0x2e, 0x2, 0x2, 0x161, 0x162, 
       0x7, 0x41, 0x2, 0x2, 0x162, 0x164, 0x5, 0x7c, 0x3f, 0x2, 0x163, 0x15f, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x160, 0x3, 0x2, 0x2, 0x2, 0x164, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0x24, 0x2, 0x2, 0x166, 0x167, 
       0x7, 0x37, 0x2, 0x2, 0x167, 0x168, 0x5, 0x2a, 0x16, 0x2, 0x168, 0x169, 
       0x7, 0x40, 0x2, 0x2, 0x169, 0x16a, 0x5, 0x2e, 0x18, 0x2, 0x16a, 0x16b, 
       0x7, 0x38, 0x2, 0x2, 0x16b, 0x31, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 
       0x5, 0x2a, 0x16, 0x2, 0x16d, 0x16f, 0x5, 0x2c, 0x17, 0x2, 0x16e, 
       0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x5, 0x26, 0x14, 0x2, 0x171, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x7, 0x18, 0x2, 0x2, 0x173, 
       0x174, 0x5, 0x32, 0x1a, 0x2, 0x174, 0x175, 0x7, 0x5d, 0x2, 0x2, 0x175, 
       0x176, 0x5, 0xa2, 0x52, 0x2, 0x176, 0x37, 0x3, 0x2, 0x2, 0x2, 0x177, 
       0x178, 0x5, 0x26, 0x14, 0x2, 0x178, 0x17a, 0x7, 0x5d, 0x2, 0x2, 0x179, 
       0x17b, 0x5, 0xa2, 0x52, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17a, 
       0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x17c, 
       0x17d, 0x5, 0x28, 0x15, 0x2, 0x17d, 0x17f, 0x7, 0x5d, 0x2, 0x2, 0x17e, 
       0x180, 0x5, 0xa2, 0x52, 0x2, 0x17f, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17f, 
       0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x182, 0x7, 0x1c, 0x2, 0x2, 0x182, 0x184, 0x7, 0x5d, 0x2, 0x2, 0x183, 
       0x185, 0x5, 0x1c, 0xf, 0x2, 0x184, 0x183, 0x3, 0x2, 0x2, 0x2, 0x184, 
       0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x186, 
       0x188, 0x7, 0x1e, 0x2, 0x2, 0x187, 0x189, 0x5, 0x1c, 0xf, 0x2, 0x188, 
       0x187, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18c, 0x7, 0x5d, 0x2, 0x2, 0x18b, 
       0x181, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x186, 0x3, 0x2, 0x2, 0x2, 0x18c, 
       0x18e, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18f, 0x5, 0xa2, 0x52, 0x2, 0x18e, 
       0x18d, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 
       0x3d, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x7, 0x23, 0x2, 0x2, 0x191, 
       0x192, 0x7, 0x37, 0x2, 0x2, 0x192, 0x193, 0x5, 0x34, 0x1b, 0x2, 0x193, 
       0x194, 0x7, 0x38, 0x2, 0x2, 0x194, 0x196, 0x7, 0x5d, 0x2, 0x2, 0x195, 
       0x197, 0x5, 0xa2, 0x52, 0x2, 0x196, 0x195, 0x3, 0x2, 0x2, 0x2, 0x196, 
       0x197, 0x3, 0x2, 0x2, 0x2, 0x197, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x198, 
       0x19b, 0x7, 0x39, 0x2, 0x2, 0x199, 0x19c, 0x5, 0x7c, 0x3f, 0x2, 0x19a, 
       0x19c, 0x5, 0x40, 0x21, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 
       0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x19d, 
       0x1a0, 0x7, 0x40, 0x2, 0x2, 0x19e, 0x1a1, 0x5, 0x7c, 0x3f, 0x2, 0x19f, 
       0x1a1, 0x5, 0x40, 0x21, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x1a0, 
       0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
       0x19d, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
       0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 
       0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
       0x1a8, 0x7, 0x3a, 0x2, 0x2, 0x1a8, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1aa, 0x5, 0x2c, 0x17, 0x2, 0x1aa, 0x1b0, 0x7, 0x5d, 0x2, 0x2, 0x1ab, 
       0x1ae, 0x7, 0x41, 0x2, 0x2, 0x1ac, 0x1af, 0x5, 0x40, 0x21, 0x2, 0x1ad, 
       0x1af, 0x5, 0x7c, 0x3f, 0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
       0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b0, 
       0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b8, 0x5, 0x38, 0x1d, 0x2, 0x1b3, 
       0x1b8, 0x5, 0x3a, 0x1e, 0x2, 0x1b4, 0x1b8, 0x5, 0x3c, 0x1f, 0x2, 
       0x1b5, 0x1b8, 0x5, 0x3e, 0x20, 0x2, 0x1b6, 0x1b8, 0x5, 0x42, 0x22, 
       0x2, 0x1b7, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b3, 0x3, 0x2, 0x2, 
       0x2, 0x1b7, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b5, 0x3, 0x2, 0x2, 
       0x2, 0x1b7, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x45, 0x3, 0x2, 0x2, 
       0x2, 0x1b9, 0x1be, 0x5, 0x32, 0x1a, 0x2, 0x1ba, 0x1bb, 0x7, 0x40, 
       0x2, 0x2, 0x1bb, 0x1bd, 0x5, 0x32, 0x1a, 0x2, 0x1bc, 0x1ba, 0x3, 
       0x2, 0x2, 0x2, 0x1bd, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 
       0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x47, 0x3, 
       0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c4, 0x5, 
       0x26, 0x14, 0x2, 0x1c2, 0x1c4, 0x5, 0x28, 0x15, 0x2, 0x1c3, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 
       0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x5d, 0x2, 0x2, 0x1c6, 0x1dc, 
       0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x1c, 0x2, 0x2, 0x1c8, 0x1ca, 
       0x7, 0x5d, 0x2, 0x2, 0x1c9, 0x1cb, 0x5, 0x1c, 0xf, 0x2, 0x1ca, 0x1c9, 
       0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1dc, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1ce, 0x7, 0x1e, 0x2, 0x2, 0x1cd, 0x1cf, 
       0x5, 0x1c, 0xf, 0x2, 0x1ce, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cf, 
       0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1dc, 
       0x7, 0x5d, 0x2, 0x2, 0x1d1, 0x1d2, 0x7, 0x23, 0x2, 0x2, 0x1d2, 0x1d3, 
       0x7, 0x37, 0x2, 0x2, 0x1d3, 0x1d4, 0x5, 0x34, 0x1b, 0x2, 0x1d4, 0x1d5, 
       0x7, 0x38, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x5d, 0x2, 0x2, 0x1d6, 0x1dc, 
       0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x9, 0x7, 0x2, 0x2, 0x1d8, 0x1d9, 
       0x5, 0x30, 0x19, 0x2, 0x1d9, 0x1da, 0x7, 0x5d, 0x2, 0x2, 0x1da, 0x1dc, 
       0x3, 0x2, 0x2, 0x2, 0x1db, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1c7, 
       0x3, 0x2, 0x2, 0x2, 0x1db, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d1, 
       0x3, 0x2, 0x2, 0x2, 0x1db, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x49, 
       0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e2, 0x5, 0x48, 0x25, 0x2, 0x1de, 0x1df, 
       0x7, 0x40, 0x2, 0x2, 0x1df, 0x1e1, 0x5, 0x48, 0x25, 0x2, 0x1e0, 0x1de, 
       0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e0, 
       0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x4b, 
       0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e8, 
       0x5, 0x48, 0x25, 0x2, 0x1e6, 0x1e8, 0x5, 0x22, 0x12, 0x2, 0x1e7, 
       0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ee, 0x5, 0x4c, 0x27, 0x2, 0x1ea, 
       0x1eb, 0x7, 0x40, 0x2, 0x2, 0x1eb, 0x1ed, 0x5, 0x4c, 0x27, 0x2, 0x1ec, 
       0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
       0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
       0x1f6, 0x5, 0x7c, 0x3f, 0x2, 0x1f2, 0x1f3, 0x7, 0x44, 0x2, 0x2, 0x1f3, 
       0x1f5, 0x5, 0x7c, 0x3f, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
       0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f6, 
       0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1f8, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x7, 0xc, 0x2, 0x2, 0x1fa, 
       0x1fb, 0x7, 0x5d, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x41, 0x2, 0x2, 0x1fc, 
       0x1fd, 0x5, 0x50, 0x29, 0x2, 0x1fd, 0x1fe, 0x7, 0x3e, 0x2, 0x2, 0x1fe, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x201, 0x5, 0x7c, 0x3f, 0x2, 0x200, 
       0x1ff, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x202, 0x3, 0x2, 0x2, 0x2, 0x202, 0x204, 0x7, 0x3d, 0x2, 0x2, 0x203, 
       0x205, 0x5, 0x7c, 0x3f, 0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 0x2, 0x204, 
       0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x208, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x207, 0x7, 0x3d, 0x2, 0x2, 0x207, 0x209, 0x5, 0x7c, 0x3f, 0x2, 0x208, 
       0x206, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 0x9, 0x2, 0x2, 0x20b, 
       0x20c, 0x5, 0x58, 0x2d, 0x2, 0x20c, 0x20d, 0x5, 0x5c, 0x2f, 0x2, 
       0x20d, 0x57, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x214, 0x5, 0x5a, 0x2e, 0x2, 
       0x20f, 0x211, 0x7, 0x3b, 0x2, 0x2, 0x210, 0x212, 0x5, 0x1e, 0x10, 
       0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 0x3, 0x2, 0x2, 
       0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 0x215, 0x7, 0x3c, 0x2, 
       0x2, 0x214, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 
       0x2, 0x215, 0x216, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x5, 0x1e, 0x10, 
       0x2, 0x217, 0x59, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 0x9, 0x8, 0x2, 
       0x2, 0x219, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x21f, 0x7, 0x39, 0x2, 
       0x2, 0x21b, 0x21e, 0x5, 0x62, 0x32, 0x2, 0x21c, 0x21e, 0x5, 0x5e, 
       0x30, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21c, 0x3, 0x2, 
       0x2, 0x2, 0x21e, 0x221, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x21d, 0x3, 0x2, 
       0x2, 0x2, 0x21f, 0x220, 0x3, 0x2, 0x2, 0x2, 0x220, 0x222, 0x3, 0x2, 
       0x2, 0x2, 0x221, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x7, 0x3a, 
       0x2, 0x2, 0x223, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x5, 0xae, 
       0x58, 0x2, 0x225, 0x226, 0x5, 0x60, 0x31, 0x2, 0x226, 0x5f, 0x3, 
       0x2, 0x2, 0x2, 0x227, 0x231, 0x5, 0x62, 0x32, 0x2, 0x228, 0x22c, 
       0x7, 0x39, 0x2, 0x2, 0x229, 0x22b, 0x5, 0x62, 0x32, 0x2, 0x22a, 0x229, 
       0x3, 0x2, 0x2, 0x2, 0x22b, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22a, 
       0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22f, 
       0x3, 0x2, 0x2, 0x2, 0x22e, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x231, 
       0x7, 0x3a, 0x2, 0x2, 0x230, 0x227, 0x3, 0x2, 0x2, 0x2, 0x230, 0x228, 
       0x3, 0x2, 0x2, 0x2, 0x231, 0x61, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
       0x5, 0x64, 0x33, 0x2, 0x233, 0x234, 0x7, 0x3e, 0x2, 0x2, 0x234, 0x237, 
       0x3, 0x2, 0x2, 0x2, 0x235, 0x237, 0x5, 0xc8, 0x65, 0x2, 0x236, 0x232, 
       0x3, 0x2, 0x2, 0x2, 0x236, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x63, 
       0x3, 0x2, 0x2, 0x2, 0x238, 0x23e, 0x5, 0x76, 0x3c, 0x2, 0x239, 0x23e, 
       0x5, 0x6a, 0x36, 0x2, 0x23a, 0x23e, 0x5, 0x68, 0x35, 0x2, 0x23b, 
       0x23e, 0x5, 0x6c, 0x37, 0x2, 0x23c, 0x23e, 0x5, 0x66, 0x34, 0x2, 
       0x23d, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x239, 0x3, 0x2, 0x2, 0x2, 
       0x23d, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23b, 0x3, 0x2, 0x2, 0x2, 
       0x23d, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x65, 0x3, 0x2, 0x2, 0x2, 
       0x23f, 0x248, 0x7, 0x35, 0x2, 0x2, 0x240, 0x245, 0x5, 0x98, 0x4d, 
       0x2, 0x241, 0x242, 0x7, 0x40, 0x2, 0x2, 0x242, 0x244, 0x5, 0x98, 
       0x4d, 0x2, 0x243, 0x241, 0x3, 0x2, 0x2, 0x2, 0x244, 0x247, 0x3, 0x2, 
       0x2, 0x2, 0x245, 0x243, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 0x3, 0x2, 
       0x2, 0x2, 0x246, 0x249, 0x3, 0x2, 0x2, 0x2, 0x247, 0x245, 0x3, 0x2, 
       0x2, 0x2, 0x248, 0x240, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 
       0x2, 0x2, 0x249, 0x67, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x7, 0x34, 
       0x2, 0x2, 0x24b, 0x24c, 0x5, 0x98, 0x4d, 0x2, 0x24c, 0x69, 0x3, 0x2, 
       0x2, 0x2, 0x24d, 0x24f, 0x5, 0x74, 0x3b, 0x2, 0x24e, 0x24d, 0x3, 
       0x2, 0x2, 0x2, 0x24f, 0x252, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 
       0x2, 0x2, 0x2, 0x250, 0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x253, 0x3, 
       0x2, 0x2, 0x2, 0x252, 0x250, 0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 
       0x29, 0x2, 0x2, 0x254, 0x255, 0x7, 0x3b, 0x2, 0x2, 0x255, 0x256, 
       0x5, 0x7c, 0x3f, 0x2, 0x256, 0x25f, 0x7, 0x3c, 0x2, 0x2, 0x257, 0x25c, 
       0x5, 0x98, 0x4d, 0x2, 0x258, 0x259, 0x7, 0x40, 0x2, 0x2, 0x259, 0x25b, 
       0x5, 0x98, 0x4d, 0x2, 0x25a, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25e, 
       0x3, 0x2, 0x2, 0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 
       0x3, 0x2, 0x2, 0x2, 0x25d, 0x260, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25c, 
       0x3, 0x2, 0x2, 0x2, 0x25f, 0x257, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 
       0x3, 0x2, 0x2, 0x2, 0x260, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x261, 0x262, 
       0x7, 0x33, 0x2, 0x2, 0x262, 0x263, 0x5, 0x98, 0x4d, 0x2, 0x263, 0x6d, 
       0x3, 0x2, 0x2, 0x2, 0x264, 0x267, 0x5, 0x68, 0x35, 0x2, 0x265, 0x266, 
       0x7, 0x42, 0x2, 0x2, 0x266, 0x268, 0x5, 0x98, 0x4d, 0x2, 0x267, 0x265, 
       0x3, 0x2, 0x2, 0x2, 0x267, 0x268, 0x3, 0x2, 0x2, 0x2, 0x268, 0x26e, 
       0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x5, 0x98, 0x4d, 0x2, 0x26a, 0x26b, 
       0x7, 0x41, 0x2, 0x2, 0x26b, 0x26c, 0x5, 0x68, 0x35, 0x2, 0x26c, 0x26e, 
       0x3, 0x2, 0x2, 0x2, 0x26d, 0x264, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x269, 
       0x3, 0x2, 0x2, 0x2, 0x26e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 
       0x7, 0x2b, 0x2, 0x2, 0x270, 0x271, 0x7, 0x3b, 0x2, 0x2, 0x271, 0x272, 
       0x5, 0x7c, 0x3f, 0x2, 0x272, 0x273, 0x7, 0x3c, 0x2, 0x2, 0x273, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x274, 0x279, 0x9, 0x9, 0x2, 0x2, 0x275, 0x276, 
       0x7, 0x3b, 0x2, 0x2, 0x276, 0x277, 0x5, 0x7c, 0x3f, 0x2, 0x277, 0x278, 
       0x7, 0x3c, 0x2, 0x2, 0x278, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x279, 0x275, 
       0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x27b, 0x27f, 0x7, 0x2a, 0x2, 0x2, 0x27c, 0x27f, 
       0x5, 0x70, 0x39, 0x2, 0x27d, 0x27f, 0x5, 0x72, 0x3a, 0x2, 0x27e, 
       0x27b, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27e, 
       0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 
       0x281, 0x7, 0x4f, 0x2, 0x2, 0x281, 0x75, 0x3, 0x2, 0x2, 0x2, 0x282, 
       0x284, 0x5, 0x74, 0x3b, 0x2, 0x283, 0x282, 0x3, 0x2, 0x2, 0x2, 0x284, 
       0x287, 0x3, 0x2, 0x2, 0x2, 0x285, 0x283, 0x3, 0x2, 0x2, 0x2, 0x285, 
       0x286, 0x3, 0x2, 0x2, 0x2, 0x286, 0x288, 0x3, 0x2, 0x2, 0x2, 0x287, 
       0x285, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28d, 0x5, 0x5a, 0x2e, 0x2, 0x289, 
       0x28a, 0x7, 0x3b, 0x2, 0x2, 0x28a, 0x28b, 0x5, 0xa0, 0x51, 0x2, 0x28b, 
       0x28c, 0x7, 0x3c, 0x2, 0x2, 0x28c, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28d, 
       0x289, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28e, 
       0x28f, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x294, 0x5, 0x98, 0x4d, 0x2, 0x290, 
       0x291, 0x7, 0x40, 0x2, 0x2, 0x291, 0x293, 0x5, 0x98, 0x4d, 0x2, 0x292, 
       0x290, 0x3, 0x2, 0x2, 0x2, 0x293, 0x296, 0x3, 0x2, 0x2, 0x2, 0x294, 
       0x292, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 0x2, 0x2, 0x2, 0x295, 
       0x77, 0x3, 0x2, 0x2, 0x2, 0x296, 0x294, 0x3, 0x2, 0x2, 0x2, 0x297, 
       0x298, 0x9, 0xa, 0x2, 0x2, 0x298, 0x79, 0x3, 0x2, 0x2, 0x2, 0x299, 
       0x29a, 0x5, 0x7c, 0x3f, 0x2, 0x29a, 0x29b, 0x7, 0x3e, 0x2, 0x2, 0x29b, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x8, 0x3f, 0x1, 0x2, 0x29d, 
       0x2a1, 0x5, 0x9a, 0x4e, 0x2, 0x29e, 0x2a1, 0x5, 0x90, 0x49, 0x2, 
       0x29f, 0x2a1, 0x5, 0x7e, 0x40, 0x2, 0x2a0, 0x29c, 0x3, 0x2, 0x2, 
       0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x29f, 0x3, 0x2, 0x2, 
       0x2, 0x2a1, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a3, 0xc, 0x3, 0x2, 
       0x2, 0x2a3, 0x2a4, 0x7, 0x4b, 0x2, 0x2, 0x2a4, 0x2a6, 0x5, 0x7e, 
       0x40, 0x2, 0x2a5, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a9, 0x3, 0x2, 
       0x2, 0x2, 0x2a7, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 
       0x2, 0x2, 0x2a8, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a7, 0x3, 0x2, 
       0x2, 0x2, 0x2aa, 0x2ab, 0x8, 0x40, 0x1, 0x2, 0x2ab, 0x2ac, 0x5, 0x80, 
       0x41, 0x2, 0x2ac, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ae, 0xc, 0x3, 
       0x2, 0x2, 0x2ae, 0x2af, 0x7, 0x4d, 0x2, 0x2, 0x2af, 0x2b1, 0x5, 0x80, 
       0x41, 0x2, 0x2b0, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b4, 0x3, 0x2, 
       0x2, 0x2, 0x2b2, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x3, 0x2, 
       0x2, 0x2, 0x2b3, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b2, 0x3, 0x2, 
       0x2, 0x2, 0x2b5, 0x2b6, 0x8, 0x41, 0x1, 0x2, 0x2b6, 0x2b7, 0x5, 0x82, 
       0x42, 0x2, 0x2b7, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0xc, 0x3, 
       0x2, 0x2, 0x2b9, 0x2ba, 0x7, 0x4a, 0x2, 0x2, 0x2ba, 0x2bc, 0x5, 0x82, 
       0x42, 0x2, 0x2bb, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bf, 0x3, 0x2, 
       0x2, 0x2, 0x2bd, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 
       0x2, 0x2, 0x2be, 0x81, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 0x3, 0x2, 
       0x2, 0x2, 0x2c0, 0x2c1, 0x8, 0x42, 0x1, 0x2, 0x2c1, 0x2c2, 0x5, 0x84, 
       0x43, 0x2, 0x2c2, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0xc, 0x3, 
       0x2, 0x2, 0x2c4, 0x2c5, 0x7, 0x4e, 0x2, 0x2, 0x2c5, 0x2c7, 0x5, 0x84, 
       0x43, 0x2, 0x2c6, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2ca, 0x3, 0x2, 
       0x2, 0x2, 0x2c8, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 
       0x2, 0x2, 0x2c9, 0x83, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 
       0x2, 0x2, 0x2cb, 0x2cc, 0x8, 0x43, 0x1, 0x2, 0x2cc, 0x2cd, 0x5, 0x86, 
       0x44, 0x2, 0x2cd, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0xc, 0x3, 
       0x2, 0x2, 0x2cf, 0x2d0, 0x7, 0x4c, 0x2, 0x2, 0x2d0, 0x2d2, 0x5, 0x86, 
       0x44, 0x2, 0x2d1, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d5, 0x3, 0x2, 
       0x2, 0x2, 0x2d3, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x3, 0x2, 
       0x2, 0x2, 0x2d4, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d3, 0x3, 0x2, 
       0x2, 0x2, 0x2d6, 0x2d7, 0x8, 0x44, 0x1, 0x2, 0x2d7, 0x2d8, 0x5, 0x88, 
       0x45, 0x2, 0x2d8, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2da, 0xc, 0x3, 
       0x2, 0x2, 0x2da, 0x2db, 0x7, 0x52, 0x2, 0x2, 0x2db, 0x2dd, 0x5, 0x88, 
       0x45, 0x2, 0x2dc, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2e0, 0x3, 0x2, 
       0x2, 0x2, 0x2de, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 0x2, 
       0x2, 0x2, 0x2df, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 
       0x2, 0x2, 0x2e1, 0x2e2, 0x8, 0x45, 0x1, 0x2, 0x2e2, 0x2e3, 0x5, 0x8a, 
       0x46, 0x2, 0x2e3, 0x2e9, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0xc, 0x3, 
       0x2, 0x2, 0x2e5, 0x2e6, 0x7, 0x54, 0x2, 0x2, 0x2e6, 0x2e8, 0x5, 0x8a, 
       0x46, 0x2, 0x2e7, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2eb, 0x3, 0x2, 
       0x2, 0x2, 0x2e9, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ea, 0x3, 0x2, 
       0x2, 0x2, 0x2ea, 0x89, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2e9, 0x3, 0x2, 
       0x2, 0x2, 0x2ec, 0x2ed, 0x8, 0x46, 0x1, 0x2, 0x2ed, 0x2ee, 0x5, 0x8c, 
       0x47, 0x2, 0x2ee, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0xc, 0x3, 
       0x2, 0x2, 0x2f0, 0x2f1, 0x7, 0x55, 0x2, 0x2, 0x2f1, 0x2f3, 0x5, 0x8c, 
       0x47, 0x2, 0x2f2, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f6, 0x3, 0x2, 
       0x2, 0x2, 0x2f4, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 0x3, 0x2, 
       0x2, 0x2, 0x2f5, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f4, 0x3, 0x2, 
       0x2, 0x2, 0x2f7, 0x2f8, 0x8, 0x47, 0x1, 0x2, 0x2f8, 0x2f9, 0x5, 0x8e, 
       0x48, 0x2, 0x2f9, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0xc, 0x3, 
       0x2, 0x2, 0x2fb, 0x2fc, 0x9, 0xb, 0x2, 0x2, 0x2fc, 0x2fe, 0x5, 0x8e, 
       0x48, 0x2, 0x2fd, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x301, 0x3, 0x2, 
       0x2, 0x2, 0x2ff, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 0x3, 0x2, 
       0x2, 0x2, 0x300, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x301, 0x2ff, 0x3, 0x2, 
       0x2, 0x2, 0x302, 0x303, 0x8, 0x48, 0x1, 0x2, 0x303, 0x304, 0x5, 0x90, 
       0x49, 0x2, 0x304, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0xc, 0x3, 
       0x2, 0x2, 0x306, 0x307, 0x9, 0xc, 0x2, 0x2, 0x307, 0x309, 0x5, 0x90, 
       0x49, 0x2, 0x308, 0x305, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30c, 0x3, 0x2, 
       0x2, 0x2, 0x30a, 0x308, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x30b, 0x3, 0x2, 
       0x2, 0x2, 0x30b, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30a, 0x3, 0x2, 
       0x2, 0x2, 0x30d, 0x30f, 0x5, 0x78, 0x3d, 0x2, 0x30e, 0x30d, 0x3, 
       0x2, 0x2, 0x2, 0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x30f, 0x310, 0x3, 
       0x2, 0x2, 0x2, 0x310, 0x311, 0x5, 0x92, 0x4a, 0x2, 0x311, 0x91, 0x3, 
       0x2, 0x2, 0x2, 0x312, 0x313, 0x8, 0x4a, 0x1, 0x2, 0x313, 0x314, 0x5, 
       0x96, 0x4c, 0x2, 0x314, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 
       0xc, 0x3, 0x2, 0x2, 0x316, 0x317, 0x7, 0x47, 0x2, 0x2, 0x317, 0x319, 
       0x5, 0x96, 0x4c, 0x2, 0x318, 0x315, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x31a, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x93, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31a, 
       0x3, 0x2, 0x2, 0x2, 0x31d, 0x32d, 0x7, 0x37, 0x2, 0x2, 0x31e, 0x32e, 
       0x5, 0xa6, 0x54, 0x2, 0x31f, 0x322, 0x5, 0x7c, 0x3f, 0x2, 0x320, 
       0x322, 0x5, 0x54, 0x2b, 0x2, 0x321, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x321, 
       0x320, 0x3, 0x2, 0x2, 0x2, 0x322, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x323, 
       0x326, 0x7, 0x40, 0x2, 0x2, 0x324, 0x327, 0x5, 0x7c, 0x3f, 0x2, 0x325, 
       0x327, 0x5, 0x54, 0x2b, 0x2, 0x326, 0x324, 0x3, 0x2, 0x2, 0x2, 0x326, 
       0x325, 0x3, 0x2, 0x2, 0x2, 0x327, 0x329, 0x3, 0x2, 0x2, 0x2, 0x328, 
       0x323, 0x3, 0x2, 0x2, 0x2, 0x329, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32a, 
       0x328, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32b, 
       0x32e, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32d, 
       0x31e, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x321, 0x3, 0x2, 0x2, 0x2, 0x32e, 
       0x32f, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x330, 0x7, 0x38, 0x2, 0x2, 0x330, 
       0x95, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x8, 0x4c, 0x1, 0x2, 0x332, 
       0x333, 0x5, 0x9a, 0x4e, 0x2, 0x333, 0x338, 0x3, 0x2, 0x2, 0x2, 0x334, 
       0x335, 0xc, 0x3, 0x2, 0x2, 0x335, 0x337, 0x5, 0x94, 0x4b, 0x2, 0x336, 
       0x334, 0x3, 0x2, 0x2, 0x2, 0x337, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x338, 
       0x336, 0x3, 0x2, 0x2, 0x2, 0x338, 0x339, 0x3, 0x2, 0x2, 0x2, 0x339, 
       0x97, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x338, 0x3, 0x2, 0x2, 0x2, 0x33b, 
       0x33f, 0x7, 0x5d, 0x2, 0x2, 0x33c, 0x33e, 0x5, 0x94, 0x4b, 0x2, 0x33d, 
       0x33c, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x341, 0x3, 0x2, 0x2, 0x2, 0x33f, 
       0x33d, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 
       0x99, 0x3, 0x2, 0x2, 0x2, 0x341, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x342, 
       0x354, 0x7, 0x58, 0x2, 0x2, 0x343, 0x354, 0x7, 0x59, 0x2, 0x2, 0x344, 
       0x354, 0x7, 0x5a, 0x2, 0x2, 0x345, 0x354, 0x7, 0x5b, 0x2, 0x2, 0x346, 
       0x354, 0x7, 0x5c, 0x2, 0x2, 0x347, 0x354, 0x7, 0x5e, 0x2, 0x2, 0x348, 
       0x354, 0x7, 0x57, 0x2, 0x2, 0x349, 0x354, 0x7, 0x36, 0x2, 0x2, 0x34a, 
       0x354, 0x7, 0x60, 0x2, 0x2, 0x34b, 0x354, 0x7, 0x5d, 0x2, 0x2, 0x34c, 
       0x354, 0x5, 0x9c, 0x4f, 0x2, 0x34d, 0x354, 0x5, 0xba, 0x5e, 0x2, 
       0x34e, 0x354, 0x5, 0xc4, 0x63, 0x2, 0x34f, 0x350, 0x7, 0x3b, 0x2, 
       0x2, 0x350, 0x351, 0x5, 0x7c, 0x3f, 0x2, 0x351, 0x352, 0x7, 0x3c, 
       0x2, 0x2, 0x352, 0x354, 0x3, 0x2, 0x2, 0x2, 0x353, 0x342, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x343, 0x3, 0x2, 0x2, 0x2, 0x353, 0x344, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x345, 0x3, 0x2, 0x2, 0x2, 0x353, 0x346, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x347, 0x3, 0x2, 0x2, 0x2, 0x353, 0x348, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x349, 0x3, 0x2, 0x2, 0x2, 0x353, 0x34a, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x353, 0x34c, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x353, 0x34e, 0x3, 0x2, 
       0x2, 0x2, 0x353, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x354, 0x9b, 0x3, 0x2, 
       0x2, 0x2, 0x355, 0x359, 0x7, 0x30, 0x2, 0x2, 0x356, 0x359, 0x5, 0x9e, 
       0x50, 0x2, 0x357, 0x359, 0x7, 0x2f, 0x2, 0x2, 0x358, 0x355, 0x3, 
       0x2, 0x2, 0x2, 0x358, 0x356, 0x3, 0x2, 0x2, 0x2, 0x358, 0x357, 0x3, 
       0x2, 0x2, 0x2, 0x359, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x7, 
       0x3b, 0x2, 0x2, 0x35b, 0x35c, 0x5, 0xa0, 0x51, 0x2, 0x35c, 0x35d, 
       0x7, 0x3c, 0x2, 0x2, 0x35d, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 
       0x5, 0x32, 0x1a, 0x2, 0x35f, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x360, 0x365, 
       0x5, 0x7c, 0x3f, 0x2, 0x361, 0x362, 0x7, 0x40, 0x2, 0x2, 0x362, 0x364, 
       0x5, 0x7c, 0x3f, 0x2, 0x363, 0x361, 0x3, 0x2, 0x2, 0x2, 0x364, 0x367, 
       0x3, 0x2, 0x2, 0x2, 0x365, 0x363, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 
       0x3, 0x2, 0x2, 0x2, 0x366, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x367, 0x365, 
       0x3, 0x2, 0x2, 0x2, 0x368, 0x369, 0x7, 0x41, 0x2, 0x2, 0x369, 0x36a, 
       0x5, 0x7c, 0x3f, 0x2, 0x36a, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 
       0x9, 0xd, 0x2, 0x2, 0x36c, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36e, 
       0x7, 0x39, 0x2, 0x2, 0x36e, 0x373, 0x5, 0x7c, 0x3f, 0x2, 0x36f, 0x370, 
       0x7, 0x40, 0x2, 0x2, 0x370, 0x372, 0x5, 0x7c, 0x3f, 0x2, 0x371, 0x36f, 
       0x3, 0x2, 0x2, 0x2, 0x372, 0x375, 0x3, 0x2, 0x2, 0x2, 0x373, 0x371, 
       0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 0x376, 
       0x3, 0x2, 0x2, 0x2, 0x375, 0x373, 0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 
       0x7, 0x3a, 0x2, 0x2, 0x377, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x378, 0x37f, 
       0x5, 0xa6, 0x54, 0x2, 0x379, 0x37a, 0x7, 0x37, 0x2, 0x2, 0x37a, 0x37b, 
       0x5, 0x54, 0x2b, 0x2, 0x37b, 0x37c, 0x7, 0x38, 0x2, 0x2, 0x37c, 0x37f, 
       0x3, 0x2, 0x2, 0x2, 0x37d, 0x37f, 0x7, 0x5d, 0x2, 0x2, 0x37e, 0x378, 
       0x3, 0x2, 0x2, 0x2, 0x37e, 0x379, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x37d, 
       0x3, 0x2, 0x2, 0x2, 0x37f, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x380, 0x38c, 
       0x5, 0x10, 0x9, 0x2, 0x381, 0x38c, 0x5, 0xb6, 0x5c, 0x2, 0x382, 0x387, 
       0x7, 0x39, 0x2, 0x2, 0x383, 0x386, 0x5, 0x10, 0x9, 0x2, 0x384, 0x386, 
       0x5, 0xb6, 0x5c, 0x2, 0x385, 0x383, 0x3, 0x2, 0x2, 0x2, 0x385, 0x384, 
       0x3, 0x2, 0x2, 0x2, 0x386, 0x389, 0x3, 0x2, 0x2, 0x2, 0x387, 0x385, 
       0x3, 0x2, 0x2, 0x2, 0x387, 0x388, 0x3, 0x2, 0x2, 0x2, 0x388, 0x38a, 
       0x3, 0x2, 0x2, 0x2, 0x389, 0x387, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38c, 
       0x7, 0x3a, 0x2, 0x2, 0x38b, 0x380, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x381, 
       0x3, 0x2, 0x2, 0x2, 0x38b, 0x382, 0x3, 0x2, 0x2, 0x2, 0x38c, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x7, 0xf, 0x2, 0x2, 0x38e, 0x38f, 
       0x7, 0x3b, 0x2, 0x2, 0x38f, 0x390, 0x5, 0x7c, 0x3f, 0x2, 0x390, 0x391, 
       0x7, 0x3c, 0x2, 0x2, 0x391, 0x394, 0x5, 0xaa, 0x56, 0x2, 0x392, 0x393, 
       0x7, 0x10, 0x2, 0x2, 0x393, 0x395, 0x5, 0xaa, 0x56, 0x2, 0x394, 0x392, 
       0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 0x3, 0x2, 0x2, 0x2, 0x395, 0xad, 
       0x3, 0x2, 0x2, 0x2, 0x396, 0x397, 0x7, 0x13, 0x2, 0x2, 0x397, 0x398, 
       0x7, 0x5d, 0x2, 0x2, 0x398, 0x399, 0x7, 0x15, 0x2, 0x2, 0x399, 0x3a0, 
       0x5, 0xa8, 0x55, 0x2, 0x39a, 0x39b, 0x7, 0x14, 0x2, 0x2, 0x39b, 0x39c, 
       0x7, 0x3b, 0x2, 0x2, 0x39c, 0x39d, 0x5, 0x7c, 0x3f, 0x2, 0x39d, 0x39e, 
       0x7, 0x3c, 0x2, 0x2, 0x39e, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x396, 
       0x3, 0x2, 0x2, 0x2, 0x39f, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0xaf, 
       0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x5, 0xae, 0x58, 0x2, 0x3a2, 0x3a3, 
       0x5, 0xaa, 0x56, 0x2, 0x3a3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a5, 
       0x7, 0x11, 0x2, 0x2, 0x3a5, 0x3a6, 0x7, 0x3e, 0x2, 0x2, 0x3a6, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3aa, 0x7, 0x12, 0x2, 0x2, 0x3a8, 0x3ab, 
       0x5, 0x7c, 0x3f, 0x2, 0x3a9, 0x3ab, 0x5, 0x68, 0x35, 0x2, 0x3aa, 
       0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
       0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ac, 
       0x3ad, 0x7, 0x3e, 0x2, 0x2, 0x3ad, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x3ae, 
       0x3af, 0x9, 0xe, 0x2, 0x2, 0x3af, 0x3b3, 0x7, 0x3e, 0x2, 0x2, 0x3b0, 
       0x3b3, 0x5, 0xb2, 0x5a, 0x2, 0x3b1, 0x3b3, 0x5, 0xb4, 0x5b, 0x2, 
       0x3b2, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b0, 0x3, 0x2, 0x2, 0x2, 
       0x3b2, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0xb7, 0x3, 0x2, 0x2, 0x2, 
       0x3b4, 0x3b5, 0x7, 0xa, 0x2, 0x2, 0x3b5, 0x3b6, 0x7, 0x5d, 0x2, 0x2, 
       0x3b6, 0x3b8, 0x7, 0x3b, 0x2, 0x2, 0x3b7, 0x3b9, 0x5, 0x46, 0x24, 
       0x2, 0x3b8, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 
       0x2, 0x3b9, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bc, 0x7, 0x3c, 0x2, 
       0x2, 0x3bb, 0x3bd, 0x5, 0x1a, 0xe, 0x2, 0x3bc, 0x3bb, 0x3, 0x2, 0x2, 
       0x2, 0x3bc, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 0x3, 0x2, 0x2, 
       0x2, 0x3be, 0x3bf, 0x7, 0x3e, 0x2, 0x2, 0x3bf, 0xb9, 0x3, 0x2, 0x2, 
       0x2, 0x3c0, 0x3c1, 0x7, 0x5d, 0x2, 0x2, 0x3c1, 0x3c3, 0x7, 0x3b, 
       0x2, 0x2, 0x3c2, 0x3c4, 0x5, 0xa0, 0x51, 0x2, 0x3c3, 0x3c2, 0x3, 
       0x2, 0x2, 0x2, 0x3c3, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c5, 0x3, 
       0x2, 0x2, 0x2, 0x3c5, 0x3c6, 0x7, 0x3c, 0x2, 0x2, 0x3c6, 0xbb, 0x3, 
       0x2, 0x2, 0x2, 0x3c7, 0x3c8, 0x7, 0x7, 0x2, 0x2, 0x3c8, 0x3c9, 0x7, 
       0x5d, 0x2, 0x2, 0x3c9, 0x3cb, 0x7, 0x3b, 0x2, 0x2, 0x3ca, 0x3cc, 
       0x5, 0x4e, 0x28, 0x2, 0x3cb, 0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3cc, 
       0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3cf, 
       0x7, 0x3c, 0x2, 0x2, 0x3ce, 0x3d0, 0x5, 0x1a, 0xe, 0x2, 0x3cf, 0x3ce, 
       0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d1, 
       0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d2, 0x5, 0xbe, 0x60, 0x2, 0x3d2, 0xbd, 
       0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d7, 0x7, 0x39, 0x2, 0x2, 0x3d4, 0x3d6, 
       0x5, 0x10, 0x9, 0x2, 0x3d5, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3d9, 
       0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d8, 
       0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3d7, 
       0x3, 0x2, 0x2, 0x2, 0x3da, 0x3dc, 0x5, 0xb4, 0x5b, 0x2, 0x3db, 0x3da, 
       0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3dd, 
       0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3de, 0x7, 0x3a, 0x2, 0x2, 0x3de, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e0, 0x7, 0x5, 0x2, 0x2, 0x3e0, 0x3e4, 
       0x7, 0x39, 0x2, 0x2, 0x3e1, 0x3e3, 0x5, 0x10, 0x9, 0x2, 0x3e2, 0x3e1, 
       0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e2, 
       0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e7, 
       0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 
       0x7, 0x3a, 0x2, 0x2, 0x3e8, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3eb, 
       0x7, 0xb, 0x2, 0x2, 0x3ea, 0x3ec, 0x5, 0x1c, 0xf, 0x2, 0x3eb, 0x3ea, 
       0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 
       0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ee, 0x5, 0x5c, 0x2f, 0x2, 0x3ee, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f8, 0x7, 0x5f, 0x2, 0x2, 0x3f0, 0x3f1, 
       0x7, 0x31, 0x2, 0x2, 0x3f1, 0x3f4, 0x7, 0x3b, 0x2, 0x2, 0x3f2, 0x3f5, 
       0x7, 0x5d, 0x2, 0x2, 0x3f3, 0x3f5, 0x5, 0x5c, 0x2f, 0x2, 0x3f4, 0x3f2, 
       0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f6, 
       0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f8, 0x7, 0x3c, 0x2, 0x2, 0x3f7, 0x3ef, 
       0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0xc5, 
       0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3ff, 0x7, 0x32, 0x2, 0x2, 0x3fa, 0x3fc, 
       0x7, 0x3b, 0x2, 0x2, 0x3fb, 0x3fd, 0x5, 0xa0, 0x51, 0x2, 0x3fc, 0x3fb, 
       0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 
       0x3, 0x2, 0x2, 0x2, 0x3fe, 0x400, 0x7, 0x3c, 0x2, 0x2, 0x3ff, 0x3fa, 
       0x3, 0x2, 0x2, 0x2, 0x3ff, 0x400, 0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 
       0x3, 0x2, 0x2, 0x2, 0x401, 0x402, 0x5, 0x1c, 0xf, 0x2, 0x402, 0x407, 
       0x5, 0x98, 0x4d, 0x2, 0x403, 0x404, 0x7, 0x40, 0x2, 0x2, 0x404, 0x406, 
       0x5, 0x98, 0x4d, 0x2, 0x405, 0x403, 0x3, 0x2, 0x2, 0x2, 0x406, 0x409, 
       0x3, 0x2, 0x2, 0x2, 0x407, 0x405, 0x3, 0x2, 0x2, 0x2, 0x407, 0x408, 
       0x3, 0x2, 0x2, 0x2, 0x408, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x409, 0x407, 
       0x3, 0x2, 0x2, 0x2, 0x40a, 0x40b, 0x5, 0xc6, 0x64, 0x2, 0x40b, 0x40c, 
       0x7, 0x3e, 0x2, 0x2, 0x40c, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40f, 
       0x5, 0xc2, 0x62, 0x2, 0x40e, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x40d, 
       0x3, 0x2, 0x2, 0x2, 0x40f, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x410, 0x413, 
       0x5, 0xcc, 0x67, 0x2, 0x411, 0x413, 0x5, 0xce, 0x68, 0x2, 0x412, 
       0x410, 0x3, 0x2, 0x2, 0x2, 0x412, 0x411, 0x3, 0x2, 0x2, 0x2, 0x413, 
       0xcb, 0x3, 0x2, 0x2, 0x2, 0x414, 0x415, 0x7, 0x6, 0x2, 0x2, 0x415, 
       0x416, 0x7, 0x61, 0x2, 0x2, 0x416, 0x417, 0x7, 0x3e, 0x2, 0x2, 0x417, 
       0xcd, 0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 0x7, 0x8, 0x2, 0x2, 0x419, 
       0x41f, 0x7, 0x5d, 0x2, 0x2, 0x41a, 0x41c, 0x7, 0x3b, 0x2, 0x2, 0x41b, 
       0x41d, 0x5, 0xd0, 0x69, 0x2, 0x41c, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x41c, 
       0x41d, 0x3, 0x2, 0x2, 0x2, 0x41d, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x41e, 
       0x420, 0x7, 0x3c, 0x2, 0x2, 0x41f, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x41f, 
       0x420, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 0x3, 0x2, 0x2, 0x2, 0x421, 
       0x423, 0x5, 0x1e, 0x10, 0x2, 0x422, 0x424, 0x5, 0x1a, 0xe, 0x2, 0x423, 
       0x422, 0x3, 0x2, 0x2, 0x2, 0x423, 0x424, 0x3, 0x2, 0x2, 0x2, 0x424, 
       0x425, 0x3, 0x2, 0x2, 0x2, 0x425, 0x429, 0x7, 0x39, 0x2, 0x2, 0x426, 
       0x428, 0xb, 0x2, 0x2, 0x2, 0x427, 0x426, 0x3, 0x2, 0x2, 0x2, 0x428, 
       0x42b, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x429, 
       0x427, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x42b, 
       0x429, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x42d, 0x7, 0x3a, 0x2, 0x2, 0x42d, 
       0xcf, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x431, 0x5, 0x4a, 0x26, 0x2, 0x42f, 
       0x431, 0x5, 0xa0, 0x51, 0x2, 0x430, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x430, 
       0x42f, 0x3, 0x2, 0x2, 0x2, 0x431, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x78, 
       0xd5, 0xd7, 0xdb, 0xe0, 0xe6, 0xfe, 0x108, 0x10f, 0x119, 0x129, 0x12f, 
       0x133, 0x136, 0x13b, 0x13f, 0x142, 0x146, 0x14a, 0x156, 0x163, 0x16e, 
       0x17a, 0x17f, 0x184, 0x188, 0x18b, 0x18e, 0x196, 0x19b, 0x1a0, 0x1a4, 
       0x1ae, 0x1b0, 0x1b7, 0x1be, 0x1c3, 0x1ca, 0x1ce, 0x1db, 0x1e2, 0x1e7, 
       0x1ee, 0x1f6, 0x200, 0x204, 0x208, 0x211, 0x214, 0x21d, 0x21f, 0x22c, 
       0x230, 0x236, 0x23d, 0x245, 0x248, 0x250, 0x25c, 0x25f, 0x267, 0x26d, 
       0x279, 0x27e, 0x285, 0x28d, 0x294, 0x2a0, 0x2a7, 0x2b2, 0x2bd, 0x2c8, 
       0x2d3, 0x2de, 0x2e9, 0x2f4, 0x2ff, 0x30a, 0x30e, 0x31a, 0x321, 0x326, 
       0x32a, 0x32d, 0x338, 0x33f, 0x353, 0x358, 0x365, 0x373, 0x37e, 0x385, 
       0x387, 0x38b, 0x394, 0x39f, 0x3aa, 0x3b2, 0x3b8, 0x3bc, 0x3c3, 0x3cb, 
       0x3cf, 0x3d7, 0x3db, 0x3e4, 0x3eb, 0x3f4, 0x3f7, 0x3fc, 0x3ff, 0x407, 
       0x40e, 0x412, 0x41c, 0x41f, 0x423, 0x429, 0x430, 
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
