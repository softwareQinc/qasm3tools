
// Generated from qasm3.g4 by ANTLR 4.9.2
#pragma once

#include "qasm3Visitor.h"

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
  return "qasm3.g4";
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__14)
      | (1ULL << qasm3Parser::T__15)
      | (1ULL << qasm3Parser::T__17)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__24)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__28)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (qasm3Parser::T__71 - 72))
      | (1ULL << (qasm3Parser::T__73 - 72))
      | (1ULL << (qasm3Parser::T__75 - 72))
      | (1ULL << (qasm3Parser::T__76 - 72))
      | (1ULL << (qasm3Parser::T__80 - 72))
      | (1ULL << (qasm3Parser::T__81 - 72))
      | (1ULL << (qasm3Parser::T__82 - 72))
      | (1ULL << (qasm3Parser::T__83 - 72))
      | (1ULL << (qasm3Parser::T__84 - 72))
      | (1ULL << (qasm3Parser::T__85 - 72))
      | (1ULL << (qasm3Parser::T__86 - 72))
      | (1ULL << (qasm3Parser::T__87 - 72))
      | (1ULL << (qasm3Parser::T__88 - 72))
      | (1ULL << (qasm3Parser::T__89 - 72))
      | (1ULL << (qasm3Parser::T__90 - 72))
      | (1ULL << (qasm3Parser::LPAREN - 72))
      | (1ULL << (qasm3Parser::MINUS - 72))
      | (1ULL << (qasm3Parser::ImagNumber - 72))
      | (1ULL << (qasm3Parser::Constant - 72))
      | (1ULL << (qasm3Parser::Integer - 72))
      | (1ULL << (qasm3Parser::Identifier - 72))
      | (1ULL << (qasm3Parser::RealNumber - 72))
      | (1ULL << (qasm3Parser::TimingLiteral - 72))
      | (1ULL << (qasm3Parser::StringLiteral - 72)))) != 0)) {
      setState(211);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::T__4:
        case qasm3Parser::T__5:
        case qasm3Parser::T__17:
        case qasm3Parser::T__80:
        case qasm3Parser::T__81:
        case qasm3Parser::T__82:
        case qasm3Parser::T__89:
        case qasm3Parser::T__90: {
          setState(209);
          globalStatement();
          break;
        }

        case qasm3Parser::T__6:
        case qasm3Parser::T__7:
        case qasm3Parser::T__8:
        case qasm3Parser::T__9:
        case qasm3Parser::T__10:
        case qasm3Parser::T__11:
        case qasm3Parser::T__12:
        case qasm3Parser::T__13:
        case qasm3Parser::T__14:
        case qasm3Parser::T__15:
        case qasm3Parser::T__18:
        case qasm3Parser::T__19:
        case qasm3Parser::T__20:
        case qasm3Parser::T__21:
        case qasm3Parser::T__22:
        case qasm3Parser::T__23:
        case qasm3Parser::T__24:
        case qasm3Parser::T__26:
        case qasm3Parser::T__27:
        case qasm3Parser::T__28:
        case qasm3Parser::T__29:
        case qasm3Parser::T__30:
        case qasm3Parser::T__45:
        case qasm3Parser::T__46:
        case qasm3Parser::T__47:
        case qasm3Parser::T__48:
        case qasm3Parser::T__49:
        case qasm3Parser::T__50:
        case qasm3Parser::T__51:
        case qasm3Parser::T__52:
        case qasm3Parser::T__53:
        case qasm3Parser::T__54:
        case qasm3Parser::T__55:
        case qasm3Parser::T__56:
        case qasm3Parser::T__57:
        case qasm3Parser::T__58:
        case qasm3Parser::T__71:
        case qasm3Parser::T__73:
        case qasm3Parser::T__75:
        case qasm3Parser::T__76:
        case qasm3Parser::T__83:
        case qasm3Parser::T__84:
        case qasm3Parser::T__85:
        case qasm3Parser::T__86:
        case qasm3Parser::T__87:
        case qasm3Parser::T__88:
        case qasm3Parser::LPAREN:
        case qasm3Parser::MINUS:
        case qasm3Parser::ImagNumber:
        case qasm3Parser::Constant:
        case qasm3Parser::Integer:
        case qasm3Parser::Identifier:
        case qasm3Parser::RealNumber:
        case qasm3Parser::TimingLiteral:
        case qasm3Parser::StringLiteral: {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    if (_la == qasm3Parser::T__0) {
      setState(216);
      version();
    }
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::T__1) {
      setState(219);
      include();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(228);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::T__2

    || _la == qasm3Parser::T__3) {
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

tree::TerminalNode* qasm3Parser::VersionContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::Integer() {
  return getToken(qasm3Parser::Integer, 0);
}

tree::TerminalNode* qasm3Parser::VersionContext::RealNumber() {
  return getToken(qasm3Parser::RealNumber, 0);
}


size_t qasm3Parser::VersionContext::getRuleIndex() const {
  return qasm3Parser::RuleVersion;
}


antlrcpp::Any qasm3Parser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    match(qasm3Parser::T__0);
    setState(232);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::Integer

    || _la == qasm3Parser::RealNumber)) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    match(qasm3Parser::T__1);
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


size_t qasm3Parser::IoIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleIoIdentifier;
}


antlrcpp::Any qasm3Parser::IoIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    if (!(_la == qasm3Parser::T__2

    || _la == qasm3Parser::T__3)) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
      case qasm3Parser::T__81: {
        enterOuterAlt(_localctx, 1);
        setState(246);
        subroutineDefinition();
        break;
      }

      case qasm3Parser::T__80: {
        enterOuterAlt(_localctx, 2);
        setState(247);
        externDeclaration();
        break;
      }

      case qasm3Parser::T__17: {
        enterOuterAlt(_localctx, 3);
        setState(248);
        quantumGateDefinition();
        break;
      }

      case qasm3Parser::T__89:
      case qasm3Parser::T__90: {
        enterOuterAlt(_localctx, 4);
        setState(249);
        calibration();
        break;
      }

      case qasm3Parser::T__4:
      case qasm3Parser::T__5: {
        enterOuterAlt(_localctx, 5);
        setState(250);
        quantumDeclarationStatement();
        break;
      }

      case qasm3Parser::T__82: {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__13:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        setState(267);
        classicalDeclaration();
        break;
      }

      case qasm3Parser::T__14: {
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

tree::TerminalNode* qasm3Parser::ClassicalAssignmentContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::AssignmentOperatorContext* qasm3Parser::ClassicalAssignmentContext::assignmentOperator() {
  return getRuleContext<qasm3Parser::AssignmentOperatorContext>(0);
}

qasm3Parser::ExpressionContext* qasm3Parser::ClassicalAssignmentContext::expression() {
  return getRuleContext<qasm3Parser::ExpressionContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ClassicalAssignmentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::ClassicalAssignmentContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalAssignment;
}


antlrcpp::Any qasm3Parser::ClassicalAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalAssignmentContext* qasm3Parser::classicalAssignment() {
  ClassicalAssignmentContext *_localctx = _tracker.createInstance<ClassicalAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, qasm3Parser::RuleClassicalAssignment);
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
    setState(273);
    match(qasm3Parser::Identifier);
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(274);
      designator();
    }
    setState(277);
    assignmentOperator();
    setState(278);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(282);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(280);
      classicalAssignment();
      break;
    }

    case 2: {
      setState(281);
      quantumMeasurementAssignment();
      break;
    }

    default:
      break;
    }
    setState(284);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(286);
    match(qasm3Parser::ARROW);
    setState(287);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(289);
    match(qasm3Parser::LBRACKET);
    setState(290);
    expression(0);
    setState(291);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IdentifierListContext* qasm3Parser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 28, qasm3Parser::RuleIdentifierList);

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
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(293);
        match(qasm3Parser::Identifier);
        setState(294);
        match(qasm3Parser::COMMA); 
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(300);
    match(qasm3Parser::Identifier);
   
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

tree::TerminalNode* qasm3Parser::QuantumDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QuantumDeclarationContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::QuantumDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumDeclaration;
}


antlrcpp::Any qasm3Parser::QuantumDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(312);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(302);
        match(qasm3Parser::T__4);
        setState(303);
        match(qasm3Parser::Identifier);
        setState(305);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(304);
          designator();
        }
        break;
      }

      case qasm3Parser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(307);
        match(qasm3Parser::T__5);
        setState(309);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(308);
          designator();
        }
        setState(311);
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

tree::TerminalNode* qasm3Parser::QuantumArgumentContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::DesignatorContext* qasm3Parser::QuantumArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::QuantumArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumArgument;
}


antlrcpp::Any qasm3Parser::QuantumArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(324);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(314);
        match(qasm3Parser::T__4);
        setState(315);
        match(qasm3Parser::Identifier);
        setState(317);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(316);
          designator();
        }
        break;
      }

      case qasm3Parser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(319);
        match(qasm3Parser::T__5);
        setState(321);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(320);
          designator();
        }
        setState(323);
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

//----------------- QuantumArgumentListContext ------------------------------------------------------------------

qasm3Parser::QuantumArgumentListContext::QuantumArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::QuantumArgumentContext *> qasm3Parser::QuantumArgumentListContext::quantumArgument() {
  return getRuleContexts<qasm3Parser::QuantumArgumentContext>();
}

qasm3Parser::QuantumArgumentContext* qasm3Parser::QuantumArgumentListContext::quantumArgument(size_t i) {
  return getRuleContext<qasm3Parser::QuantumArgumentContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::QuantumArgumentListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::QuantumArgumentListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::QuantumArgumentListContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumArgumentList;
}


antlrcpp::Any qasm3Parser::QuantumArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumArgumentListContext* qasm3Parser::quantumArgumentList() {
  QuantumArgumentListContext *_localctx = _tracker.createInstance<QuantumArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 34, qasm3Parser::RuleQuantumArgumentList);
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
    quantumArgument();
    setState(331);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(327);
      match(qasm3Parser::COMMA);
      setState(328);
      quantumArgument();
      setState(333);
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

//----------------- BitTypeContext ------------------------------------------------------------------

qasm3Parser::BitTypeContext::BitTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::BitTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleBitType;
}


antlrcpp::Any qasm3Parser::BitTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBitType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BitTypeContext* qasm3Parser::bitType() {
  BitTypeContext *_localctx = _tracker.createInstance<BitTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, qasm3Parser::RuleBitType);
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
    setState(334);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__6

    || _la == qasm3Parser::T__7)) {
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

//----------------- SingleDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::SingleDesignatorTypeContext::SingleDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::SingleDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleSingleDesignatorType;
}


antlrcpp::Any qasm3Parser::SingleDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSingleDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::singleDesignatorType() {
  SingleDesignatorTypeContext *_localctx = _tracker.createInstance<SingleDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 38, qasm3Parser::RuleSingleDesignatorType);
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
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11))) != 0))) {
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

//----------------- NoDesignatorTypeContext ------------------------------------------------------------------

qasm3Parser::NoDesignatorTypeContext::NoDesignatorTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingTypeContext* qasm3Parser::NoDesignatorTypeContext::timingType() {
  return getRuleContext<qasm3Parser::TimingTypeContext>(0);
}


size_t qasm3Parser::NoDesignatorTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleNoDesignatorType;
}


antlrcpp::Any qasm3Parser::NoDesignatorTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitNoDesignatorType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::noDesignatorType() {
  NoDesignatorTypeContext *_localctx = _tracker.createInstance<NoDesignatorTypeContext>(_ctx, getState());
  enterRule(_localctx, 40, qasm3Parser::RuleNoDesignatorType);

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
      case qasm3Parser::T__12: {
        enterOuterAlt(_localctx, 1);
        setState(338);
        match(qasm3Parser::T__12);
        break;
      }

      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        enterOuterAlt(_localctx, 2);
        setState(339);
        timingType();
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

//----------------- ClassicalTypeContext ------------------------------------------------------------------

qasm3Parser::ClassicalTypeContext::ClassicalTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::ClassicalTypeContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::ClassicalTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::ClassicalTypeContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
}

qasm3Parser::BitTypeContext* qasm3Parser::ClassicalTypeContext::bitType() {
  return getRuleContext<qasm3Parser::BitTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalTypeContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::NumericTypeContext* qasm3Parser::ClassicalTypeContext::numericType() {
  return getRuleContext<qasm3Parser::NumericTypeContext>(0);
}

tree::TerminalNode* qasm3Parser::ClassicalTypeContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ClassicalTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalType;
}


antlrcpp::Any qasm3Parser::ClassicalTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalTypeContext* qasm3Parser::classicalType() {
  ClassicalTypeContext *_localctx = _tracker.createInstance<ClassicalTypeContext>(_ctx, getState());
  enterRule(_localctx, 42, qasm3Parser::RuleClassicalType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(342);
        singleDesignatorType();
        setState(343);
        designator();
        break;
      }

      case qasm3Parser::T__12:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        enterOuterAlt(_localctx, 2);
        setState(345);
        noDesignatorType();
        break;
      }

      case qasm3Parser::T__6:
      case qasm3Parser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(346);
        bitType();
        setState(348);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(347);
          designator();
        }
        break;
      }

      case qasm3Parser::T__13: {
        enterOuterAlt(_localctx, 4);
        setState(350);
        match(qasm3Parser::T__13);
        setState(351);
        match(qasm3Parser::LBRACKET);
        setState(352);
        numericType();
        setState(353);
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

//----------------- NumericTypeContext ------------------------------------------------------------------

qasm3Parser::NumericTypeContext::NumericTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::SingleDesignatorTypeContext* qasm3Parser::NumericTypeContext::singleDesignatorType() {
  return getRuleContext<qasm3Parser::SingleDesignatorTypeContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::NumericTypeContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}


size_t qasm3Parser::NumericTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleNumericType;
}


antlrcpp::Any qasm3Parser::NumericTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitNumericType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NumericTypeContext* qasm3Parser::numericType() {
  NumericTypeContext *_localctx = _tracker.createInstance<NumericTypeContext>(_ctx, getState());
  enterRule(_localctx, 44, qasm3Parser::RuleNumericType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    singleDesignatorType();
    setState(358);
    designator();
   
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitConstantDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ConstantDeclarationContext* qasm3Parser::constantDeclaration() {
  ConstantDeclarationContext *_localctx = _tracker.createInstance<ConstantDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 46, qasm3Parser::RuleConstantDeclaration);

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
    match(qasm3Parser::T__14);
    setState(361);
    classicalType();
    setState(362);
    match(qasm3Parser::Identifier);
    setState(363);
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

qasm3Parser::DesignatorContext* qasm3Parser::SingleDesignatorDeclarationContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSingleDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SingleDesignatorDeclarationContext* qasm3Parser::singleDesignatorDeclaration() {
  SingleDesignatorDeclarationContext *_localctx = _tracker.createInstance<SingleDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 48, qasm3Parser::RuleSingleDesignatorDeclaration);
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
    setState(365);
    singleDesignatorType();
    setState(366);
    designator();
    setState(367);
    match(qasm3Parser::Identifier);
    setState(369);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(368);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitNoDesignatorDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::NoDesignatorDeclarationContext* qasm3Parser::noDesignatorDeclaration() {
  NoDesignatorDeclarationContext *_localctx = _tracker.createInstance<NoDesignatorDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 50, qasm3Parser::RuleNoDesignatorDeclaration);
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
    noDesignatorType();
    setState(372);
    match(qasm3Parser::Identifier);
    setState(374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(373);
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

tree::TerminalNode* qasm3Parser::BitDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BitDeclarationContext* qasm3Parser::bitDeclaration() {
  BitDeclarationContext *_localctx = _tracker.createInstance<BitDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 52, qasm3Parser::RuleBitDeclaration);
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
    setState(386);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__7: {
        setState(376);
        match(qasm3Parser::T__7);
        setState(377);
        match(qasm3Parser::Identifier);
        setState(379);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(378);
          designator();
        }
        break;
      }

      case qasm3Parser::T__6: {
        setState(381);
        match(qasm3Parser::T__6);
        setState(383);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(382);
          designator();
        }
        setState(385);
        match(qasm3Parser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(389);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(388);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitComplexDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ComplexDeclarationContext* qasm3Parser::complexDeclaration() {
  ComplexDeclarationContext *_localctx = _tracker.createInstance<ComplexDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 54, qasm3Parser::RuleComplexDeclaration);
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
    setState(391);
    match(qasm3Parser::T__13);
    setState(392);
    match(qasm3Parser::LBRACKET);
    setState(393);
    numericType();
    setState(394);
    match(qasm3Parser::RBRACKET);
    setState(395);
    match(qasm3Parser::Identifier);
    setState(397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::EQUALS) {
      setState(396);
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


size_t qasm3Parser::ClassicalDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalDeclaration;
}


antlrcpp::Any qasm3Parser::ClassicalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalDeclarationContext* qasm3Parser::classicalDeclaration() {
  ClassicalDeclarationContext *_localctx = _tracker.createInstance<ClassicalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, qasm3Parser::RuleClassicalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(403);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(399);
        singleDesignatorDeclaration();
        break;
      }

      case qasm3Parser::T__12:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        enterOuterAlt(_localctx, 2);
        setState(400);
        noDesignatorDeclaration();
        break;
      }

      case qasm3Parser::T__6:
      case qasm3Parser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(401);
        bitDeclaration();
        break;
      }

      case qasm3Parser::T__13: {
        enterOuterAlt(_localctx, 4);
        setState(402);
        complexDeclaration();
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalTypeList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalTypeListContext* qasm3Parser::classicalTypeList() {
  ClassicalTypeListContext *_localctx = _tracker.createInstance<ClassicalTypeListContext>(_ctx, getState());
  enterRule(_localctx, 58, qasm3Parser::RuleClassicalTypeList);

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
    setState(410);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(405);
        classicalType();
        setState(406);
        match(qasm3Parser::COMMA); 
      }
      setState(412);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
    setState(413);
    classicalType();
   
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

qasm3Parser::DesignatorContext* qasm3Parser::ClassicalArgumentContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::NoDesignatorTypeContext* qasm3Parser::ClassicalArgumentContext::noDesignatorType() {
  return getRuleContext<qasm3Parser::NoDesignatorTypeContext>(0);
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


size_t qasm3Parser::ClassicalArgumentContext::getRuleIndex() const {
  return qasm3Parser::RuleClassicalArgument;
}


antlrcpp::Any qasm3Parser::ClassicalArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalArgumentContext* qasm3Parser::classicalArgument() {
  ClassicalArgumentContext *_localctx = _tracker.createInstance<ClassicalArgumentContext>(_ctx, getState());
  enterRule(_localctx, 60, qasm3Parser::RuleClassicalArgument);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(439);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        enterOuterAlt(_localctx, 1);
        setState(419);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::T__8:
          case qasm3Parser::T__9:
          case qasm3Parser::T__10:
          case qasm3Parser::T__11: {
            setState(415);
            singleDesignatorType();
            setState(416);
            designator();
            break;
          }

          case qasm3Parser::T__12:
          case qasm3Parser::T__83:
          case qasm3Parser::T__84: {
            setState(418);
            noDesignatorType();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(421);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(423);
        match(qasm3Parser::T__7);
        setState(424);
        match(qasm3Parser::Identifier);
        setState(426);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(425);
          designator();
        }
        break;
      }

      case qasm3Parser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(428);
        match(qasm3Parser::T__6);
        setState(430);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::LBRACKET) {
          setState(429);
          designator();
        }
        setState(432);
        match(qasm3Parser::Identifier);
        break;
      }

      case qasm3Parser::T__13: {
        enterOuterAlt(_localctx, 4);
        setState(433);
        match(qasm3Parser::T__13);
        setState(434);
        match(qasm3Parser::LBRACKET);
        setState(435);
        numericType();
        setState(436);
        match(qasm3Parser::RBRACKET);
        setState(437);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitClassicalArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ClassicalArgumentListContext* qasm3Parser::classicalArgumentList() {
  ClassicalArgumentListContext *_localctx = _tracker.createInstance<ClassicalArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 62, qasm3Parser::RuleClassicalArgumentList);
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
    setState(441);
    classicalArgument();
    setState(446);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(442);
      match(qasm3Parser::COMMA);
      setState(443);
      classicalArgument();
      setState(448);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAnyTypeArgument(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AnyTypeArgumentContext* qasm3Parser::anyTypeArgument() {
  AnyTypeArgumentContext *_localctx = _tracker.createInstance<AnyTypeArgumentContext>(_ctx, getState());
  enterRule(_localctx, 64, qasm3Parser::RuleAnyTypeArgument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(451);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__13:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        enterOuterAlt(_localctx, 1);
        setState(449);
        classicalArgument();
        break;
      }

      case qasm3Parser::T__4:
      case qasm3Parser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(450);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAnyTypeArgumentList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AnyTypeArgumentListContext* qasm3Parser::anyTypeArgumentList() {
  AnyTypeArgumentListContext *_localctx = _tracker.createInstance<AnyTypeArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 66, qasm3Parser::RuleAnyTypeArgumentList);

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
    setState(458);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(453);
        anyTypeArgument();
        setState(454);
        match(qasm3Parser::COMMA); 
      }
      setState(460);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
    setState(461);
    anyTypeArgument();
   
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

tree::TerminalNode* qasm3Parser::AliasStatementContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::AliasStatementContext::indexIdentifier() {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::AliasStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::AliasStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleAliasStatement;
}


antlrcpp::Any qasm3Parser::AliasStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAliasStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AliasStatementContext* qasm3Parser::aliasStatement() {
  AliasStatementContext *_localctx = _tracker.createInstance<AliasStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, qasm3Parser::RuleAliasStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(463);
    match(qasm3Parser::T__15);
    setState(464);
    match(qasm3Parser::Identifier);
    setState(465);
    match(qasm3Parser::EQUALS);
    setState(466);
    indexIdentifier(0);
    setState(467);
    match(qasm3Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexIdentifierContext ------------------------------------------------------------------

qasm3Parser::IndexIdentifierContext::IndexIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::IndexIdentifierContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::IndexIdentifierContext::rangeDefinition() {
  return getRuleContext<qasm3Parser::RangeDefinitionContext>(0);
}

tree::TerminalNode* qasm3Parser::IndexIdentifierContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::IndexIdentifierContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::IndexIdentifierContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}

std::vector<qasm3Parser::IndexIdentifierContext *> qasm3Parser::IndexIdentifierContext::indexIdentifier() {
  return getRuleContexts<qasm3Parser::IndexIdentifierContext>();
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::IndexIdentifierContext::indexIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(i);
}


size_t qasm3Parser::IndexIdentifierContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexIdentifier;
}


antlrcpp::Any qasm3Parser::IndexIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIndexIdentifier(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::IndexIdentifierContext* qasm3Parser::indexIdentifier() {
   return indexIdentifier(0);
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::indexIdentifier(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::IndexIdentifierContext *_localctx = _tracker.createInstance<IndexIdentifierContext>(_ctx, parentState);
  qasm3Parser::IndexIdentifierContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, qasm3Parser::RuleIndexIdentifier, precedence);

    

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
    setState(479);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(470);
      match(qasm3Parser::Identifier);
      setState(471);
      rangeDefinition();
      break;
    }

    case 2: {
      setState(472);
      match(qasm3Parser::Identifier);
      setState(477);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
      case 1: {
        setState(473);
        match(qasm3Parser::LBRACKET);
        setState(474);
        expressionList();
        setState(475);
        match(qasm3Parser::RBRACKET);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(486);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<IndexIdentifierContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleIndexIdentifier);
        setState(481);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(482);
        match(qasm3Parser::T__16);
        setState(483);
        indexIdentifier(2); 
      }
      setState(488);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IndexIdentifierListContext ------------------------------------------------------------------

qasm3Parser::IndexIdentifierListContext::IndexIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<qasm3Parser::IndexIdentifierContext *> qasm3Parser::IndexIdentifierListContext::indexIdentifier() {
  return getRuleContexts<qasm3Parser::IndexIdentifierContext>();
}

qasm3Parser::IndexIdentifierContext* qasm3Parser::IndexIdentifierListContext::indexIdentifier(size_t i) {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(i);
}

std::vector<tree::TerminalNode *> qasm3Parser::IndexIdentifierListContext::COMMA() {
  return getTokens(qasm3Parser::COMMA);
}

tree::TerminalNode* qasm3Parser::IndexIdentifierListContext::COMMA(size_t i) {
  return getToken(qasm3Parser::COMMA, i);
}


size_t qasm3Parser::IndexIdentifierListContext::getRuleIndex() const {
  return qasm3Parser::RuleIndexIdentifierList;
}


antlrcpp::Any qasm3Parser::IndexIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitIndexIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::indexIdentifierList() {
  IndexIdentifierListContext *_localctx = _tracker.createInstance<IndexIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 72, qasm3Parser::RuleIndexIdentifierList);
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
    setState(489);
    indexIdentifier(0);
    setState(494);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(490);
      match(qasm3Parser::COMMA);
      setState(491);
      indexIdentifier(0);
      setState(496);
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

//----------------- RangeDefinitionContext ------------------------------------------------------------------

qasm3Parser::RangeDefinitionContext::RangeDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

std::vector<tree::TerminalNode *> qasm3Parser::RangeDefinitionContext::COLON() {
  return getTokens(qasm3Parser::COLON);
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::COLON(size_t i) {
  return getToken(qasm3Parser::COLON, i);
}

tree::TerminalNode* qasm3Parser::RangeDefinitionContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitRangeDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::rangeDefinition() {
  RangeDefinitionContext *_localctx = _tracker.createInstance<RangeDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 74, qasm3Parser::RuleRangeDefinition);
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
    setState(497);
    match(qasm3Parser::LBRACKET);
    setState(499);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 84) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 84)) & ((1ULL << (qasm3Parser::T__83 - 84))
      | (1ULL << (qasm3Parser::T__84 - 84))
      | (1ULL << (qasm3Parser::T__86 - 84))
      | (1ULL << (qasm3Parser::LPAREN - 84))
      | (1ULL << (qasm3Parser::MINUS - 84))
      | (1ULL << (qasm3Parser::ImagNumber - 84))
      | (1ULL << (qasm3Parser::Constant - 84))
      | (1ULL << (qasm3Parser::Integer - 84))
      | (1ULL << (qasm3Parser::Identifier - 84))
      | (1ULL << (qasm3Parser::RealNumber - 84))
      | (1ULL << (qasm3Parser::TimingLiteral - 84))
      | (1ULL << (qasm3Parser::StringLiteral - 84)))) != 0)) {
      setState(498);
      expression(0);
    }
    setState(501);
    match(qasm3Parser::COLON);
    setState(503);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 84) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 84)) & ((1ULL << (qasm3Parser::T__83 - 84))
      | (1ULL << (qasm3Parser::T__84 - 84))
      | (1ULL << (qasm3Parser::T__86 - 84))
      | (1ULL << (qasm3Parser::LPAREN - 84))
      | (1ULL << (qasm3Parser::MINUS - 84))
      | (1ULL << (qasm3Parser::ImagNumber - 84))
      | (1ULL << (qasm3Parser::Constant - 84))
      | (1ULL << (qasm3Parser::Integer - 84))
      | (1ULL << (qasm3Parser::Identifier - 84))
      | (1ULL << (qasm3Parser::RealNumber - 84))
      | (1ULL << (qasm3Parser::TimingLiteral - 84))
      | (1ULL << (qasm3Parser::StringLiteral - 84)))) != 0)) {
      setState(502);
      expression(0);
    }
    setState(507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::COLON) {
      setState(505);
      match(qasm3Parser::COLON);
      setState(506);
      expression(0);
    }
    setState(509);
    match(qasm3Parser::RBRACKET);
   
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateDefinitionContext* qasm3Parser::quantumGateDefinition() {
  QuantumGateDefinitionContext *_localctx = _tracker.createInstance<QuantumGateDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 76, qasm3Parser::RuleQuantumGateDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    match(qasm3Parser::T__17);
    setState(512);
    quantumGateSignature();
    setState(513);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateSignatureContext* qasm3Parser::quantumGateSignature() {
  QuantumGateSignatureContext *_localctx = _tracker.createInstance<QuantumGateSignatureContext>(_ctx, getState());
  enterRule(_localctx, 78, qasm3Parser::RuleQuantumGateSignature);
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
    setState(515);
    quantumGateName();
    setState(521);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(516);
      match(qasm3Parser::LPAREN);
      setState(518);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == qasm3Parser::Identifier) {
        setState(517);
        identifierList();
      }
      setState(520);
      match(qasm3Parser::RPAREN);
    }
    setState(523);
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

tree::TerminalNode* qasm3Parser::QuantumGateNameContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::QuantumGateNameContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateName;
}


antlrcpp::Any qasm3Parser::QuantumGateNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateName(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::quantumGateName() {
  QuantumGateNameContext *_localctx = _tracker.createInstance<QuantumGateNameContext>(_ctx, getState());
  enterRule(_localctx, 80, qasm3Parser::RuleQuantumGateName);
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
    setState(525);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__18

    || _la == qasm3Parser::T__19 || _la == qasm3Parser::Identifier)) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumBlockContext* qasm3Parser::quantumBlock() {
  QuantumBlockContext *_localctx = _tracker.createInstance<QuantumBlockContext>(_ctx, getState());
  enterRule(_localctx, 82, qasm3Parser::RuleQuantumBlock);
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
    setState(527);
    match(qasm3Parser::LBRACE);
    setState(532);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__24)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__28))) != 0) || ((((_la - 74) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 74)) & ((1ULL << (qasm3Parser::T__73 - 74))
      | (1ULL << (qasm3Parser::T__75 - 74))
      | (1ULL << (qasm3Parser::T__85 - 74))
      | (1ULL << (qasm3Parser::T__87 - 74))
      | (1ULL << (qasm3Parser::T__88 - 74))
      | (1ULL << (qasm3Parser::Identifier - 74)))) != 0)) {
      setState(530);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case qasm3Parser::T__18:
        case qasm3Parser::T__19:
        case qasm3Parser::T__20:
        case qasm3Parser::T__21:
        case qasm3Parser::T__22:
        case qasm3Parser::T__23:
        case qasm3Parser::T__24:
        case qasm3Parser::T__26:
        case qasm3Parser::T__27:
        case qasm3Parser::T__28:
        case qasm3Parser::T__85:
        case qasm3Parser::T__87:
        case qasm3Parser::T__88:
        case qasm3Parser::Identifier: {
          setState(528);
          quantumStatement();
          break;
        }

        case qasm3Parser::T__73:
        case qasm3Parser::T__75: {
          setState(529);
          quantumLoop();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(534);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(535);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumLoop(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumLoopContext* qasm3Parser::quantumLoop() {
  QuantumLoopContext *_localctx = _tracker.createInstance<QuantumLoopContext>(_ctx, getState());
  enterRule(_localctx, 84, qasm3Parser::RuleQuantumLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(537);
    loopSignature();
    setState(538);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumLoopBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumLoopBlockContext* qasm3Parser::quantumLoopBlock() {
  QuantumLoopBlockContext *_localctx = _tracker.createInstance<QuantumLoopBlockContext>(_ctx, getState());
  enterRule(_localctx, 86, qasm3Parser::RuleQuantumLoopBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(549);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__18:
      case qasm3Parser::T__19:
      case qasm3Parser::T__20:
      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23:
      case qasm3Parser::T__24:
      case qasm3Parser::T__26:
      case qasm3Parser::T__27:
      case qasm3Parser::T__28:
      case qasm3Parser::T__85:
      case qasm3Parser::T__87:
      case qasm3Parser::T__88:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(540);
        quantumStatement();
        break;
      }

      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(541);
        match(qasm3Parser::LBRACE);
        setState(545);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << qasm3Parser::T__18)
          | (1ULL << qasm3Parser::T__19)
          | (1ULL << qasm3Parser::T__20)
          | (1ULL << qasm3Parser::T__21)
          | (1ULL << qasm3Parser::T__22)
          | (1ULL << qasm3Parser::T__23)
          | (1ULL << qasm3Parser::T__24)
          | (1ULL << qasm3Parser::T__26)
          | (1ULL << qasm3Parser::T__27)
          | (1ULL << qasm3Parser::T__28))) != 0) || ((((_la - 86) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 86)) & ((1ULL << (qasm3Parser::T__85 - 86))
          | (1ULL << (qasm3Parser::T__87 - 86))
          | (1ULL << (qasm3Parser::T__88 - 86))
          | (1ULL << (qasm3Parser::Identifier - 86)))) != 0)) {
          setState(542);
          quantumStatement();
          setState(547);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(548);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumStatementContext* qasm3Parser::quantumStatement() {
  QuantumStatementContext *_localctx = _tracker.createInstance<QuantumStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, qasm3Parser::RuleQuantumStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(555);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__18:
      case qasm3Parser::T__19:
      case qasm3Parser::T__20:
      case qasm3Parser::T__21:
      case qasm3Parser::T__22:
      case qasm3Parser::T__23:
      case qasm3Parser::T__24:
      case qasm3Parser::T__26:
      case qasm3Parser::T__27:
      case qasm3Parser::T__28:
      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(551);
        quantumInstruction();
        setState(552);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::T__85:
      case qasm3Parser::T__87:
      case qasm3Parser::T__88: {
        enterOuterAlt(_localctx, 2);
        setState(554);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumInstructionContext* qasm3Parser::quantumInstruction() {
  QuantumInstructionContext *_localctx = _tracker.createInstance<QuantumInstructionContext>(_ctx, getState());
  enterRule(_localctx, 90, qasm3Parser::RuleQuantumInstruction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(562);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(557);
      quantumGateCall();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(558);
      quantumPhase();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(559);
      quantumMeasurement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(560);
      quantumReset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(561);
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

//----------------- QuantumPhaseContext ------------------------------------------------------------------

qasm3Parser::QuantumPhaseContext::QuantumPhaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumPhaseContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}


size_t qasm3Parser::QuantumPhaseContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumPhase;
}


antlrcpp::Any qasm3Parser::QuantumPhaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumPhase(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumPhaseContext* qasm3Parser::quantumPhase() {
  QuantumPhaseContext *_localctx = _tracker.createInstance<QuantumPhaseContext>(_ctx, getState());
  enterRule(_localctx, 92, qasm3Parser::RuleQuantumPhase);
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
    setState(567);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__24)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__28))) != 0)) {
      setState(564);
      quantumGateModifier();
      setState(569);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(570);
    match(qasm3Parser::T__20);
    setState(571);
    match(qasm3Parser::LPAREN);
    setState(572);
    expression(0);
    setState(573);
    match(qasm3Parser::RPAREN);
    setState(575);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier) {
      setState(574);
      indexIdentifierList();
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

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumResetContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}


size_t qasm3Parser::QuantumResetContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumReset;
}


antlrcpp::Any qasm3Parser::QuantumResetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumReset(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumResetContext* qasm3Parser::quantumReset() {
  QuantumResetContext *_localctx = _tracker.createInstance<QuantumResetContext>(_ctx, getState());
  enterRule(_localctx, 94, qasm3Parser::RuleQuantumReset);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    match(qasm3Parser::T__21);
    setState(578);
    indexIdentifierList();
   
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

qasm3Parser::IndexIdentifierContext* qasm3Parser::QuantumMeasurementContext::indexIdentifier() {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(0);
}


size_t qasm3Parser::QuantumMeasurementContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumMeasurement;
}


antlrcpp::Any qasm3Parser::QuantumMeasurementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumMeasurement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumMeasurementContext* qasm3Parser::quantumMeasurement() {
  QuantumMeasurementContext *_localctx = _tracker.createInstance<QuantumMeasurementContext>(_ctx, getState());
  enterRule(_localctx, 96, qasm3Parser::RuleQuantumMeasurement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(580);
    match(qasm3Parser::T__22);
    setState(581);
    indexIdentifier(0);
   
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

qasm3Parser::IndexIdentifierContext* qasm3Parser::QuantumMeasurementAssignmentContext::indexIdentifier() {
  return getRuleContext<qasm3Parser::IndexIdentifierContext>(0);
}

tree::TerminalNode* qasm3Parser::QuantumMeasurementAssignmentContext::EQUALS() {
  return getToken(qasm3Parser::EQUALS, 0);
}


size_t qasm3Parser::QuantumMeasurementAssignmentContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumMeasurementAssignment;
}


antlrcpp::Any qasm3Parser::QuantumMeasurementAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumMeasurementAssignment(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumMeasurementAssignmentContext* qasm3Parser::quantumMeasurementAssignment() {
  QuantumMeasurementAssignmentContext *_localctx = _tracker.createInstance<QuantumMeasurementAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 98, qasm3Parser::RuleQuantumMeasurementAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(592);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__22: {
        enterOuterAlt(_localctx, 1);
        setState(583);
        quantumMeasurement();
        setState(586);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == qasm3Parser::ARROW) {
          setState(584);
          match(qasm3Parser::ARROW);
          setState(585);
          indexIdentifier(0);
        }
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(588);
        indexIdentifier(0);
        setState(589);
        match(qasm3Parser::EQUALS);
        setState(590);
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

//----------------- QuantumBarrierContext ------------------------------------------------------------------

qasm3Parser::QuantumBarrierContext::QuantumBarrierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumBarrierContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}


size_t qasm3Parser::QuantumBarrierContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumBarrier;
}


antlrcpp::Any qasm3Parser::QuantumBarrierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(594);
    match(qasm3Parser::T__23);
    setState(596);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::Identifier) {
      setState(595);
      indexIdentifierList();
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateModifierContext* qasm3Parser::quantumGateModifier() {
  QuantumGateModifierContext *_localctx = _tracker.createInstance<QuantumGateModifierContext>(_ctx, getState());
  enterRule(_localctx, 102, qasm3Parser::RuleQuantumGateModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(601);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__24: {
        setState(598);
        match(qasm3Parser::T__24);
        break;
      }

      case qasm3Parser::T__26: {
        setState(599);
        powModifier();
        break;
      }

      case qasm3Parser::T__27:
      case qasm3Parser::T__28: {
        setState(600);
        ctrlModifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(603);
    match(qasm3Parser::T__25);
   
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitPowModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PowModifierContext* qasm3Parser::powModifier() {
  PowModifierContext *_localctx = _tracker.createInstance<PowModifierContext>(_ctx, getState());
  enterRule(_localctx, 104, qasm3Parser::RulePowModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(605);
    match(qasm3Parser::T__26);
    setState(606);
    match(qasm3Parser::LPAREN);
    setState(607);
    expression(0);
    setState(608);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCtrlModifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CtrlModifierContext* qasm3Parser::ctrlModifier() {
  CtrlModifierContext *_localctx = _tracker.createInstance<CtrlModifierContext>(_ctx, getState());
  enterRule(_localctx, 106, qasm3Parser::RuleCtrlModifier);
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
    setState(610);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__27

    || _la == qasm3Parser::T__28)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(615);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(611);
      match(qasm3Parser::LPAREN);
      setState(612);
      expression(0);
      setState(613);
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

//----------------- QuantumGateCallContext ------------------------------------------------------------------

qasm3Parser::QuantumGateCallContext::QuantumGateCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::QuantumGateNameContext* qasm3Parser::QuantumGateCallContext::quantumGateName() {
  return getRuleContext<qasm3Parser::QuantumGateNameContext>(0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::QuantumGateCallContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
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


size_t qasm3Parser::QuantumGateCallContext::getRuleIndex() const {
  return qasm3Parser::RuleQuantumGateCall;
}


antlrcpp::Any qasm3Parser::QuantumGateCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitQuantumGateCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::QuantumGateCallContext* qasm3Parser::quantumGateCall() {
  QuantumGateCallContext *_localctx = _tracker.createInstance<QuantumGateCallContext>(_ctx, getState());
  enterRule(_localctx, 108, qasm3Parser::RuleQuantumGateCall);
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
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__24)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__28))) != 0)) {
      setState(617);
      quantumGateModifier();
      setState(622);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(623);
    quantumGateName();
    setState(628);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(624);
      match(qasm3Parser::LPAREN);
      setState(625);
      expressionList();
      setState(626);
      match(qasm3Parser::RPAREN);
    }
    setState(630);
    indexIdentifierList();
   
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

tree::TerminalNode* qasm3Parser::UnaryOperatorContext::MINUS() {
  return getToken(qasm3Parser::MINUS, 0);
}


size_t qasm3Parser::UnaryOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleUnaryOperator;
}


antlrcpp::Any qasm3Parser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::UnaryOperatorContext* qasm3Parser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 110, qasm3Parser::RuleUnaryOperator);
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
    setState(632);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__29

    || _la == qasm3Parser::T__30 || _la == qasm3Parser::MINUS)) {
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

//----------------- ComparisonOperatorContext ------------------------------------------------------------------

qasm3Parser::ComparisonOperatorContext::ComparisonOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::ComparisonOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleComparisonOperator;
}


antlrcpp::Any qasm3Parser::ComparisonOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitComparisonOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ComparisonOperatorContext* qasm3Parser::comparisonOperator() {
  ComparisonOperatorContext *_localctx = _tracker.createInstance<ComparisonOperatorContext>(_ctx, getState());
  enterRule(_localctx, 112, qasm3Parser::RuleComparisonOperator);
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
    setState(634);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__31)
      | (1ULL << qasm3Parser::T__32)
      | (1ULL << qasm3Parser::T__33)
      | (1ULL << qasm3Parser::T__34))) != 0))) {
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

//----------------- EqualityOperatorContext ------------------------------------------------------------------

qasm3Parser::EqualityOperatorContext::EqualityOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::EqualityOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleEqualityOperator;
}


antlrcpp::Any qasm3Parser::EqualityOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitEqualityOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EqualityOperatorContext* qasm3Parser::equalityOperator() {
  EqualityOperatorContext *_localctx = _tracker.createInstance<EqualityOperatorContext>(_ctx, getState());
  enterRule(_localctx, 114, qasm3Parser::RuleEqualityOperator);
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
    setState(636);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__35

    || _la == qasm3Parser::T__36)) {
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

//----------------- LogicalOperatorContext ------------------------------------------------------------------

qasm3Parser::LogicalOperatorContext::LogicalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::LogicalOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleLogicalOperator;
}


antlrcpp::Any qasm3Parser::LogicalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitLogicalOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LogicalOperatorContext* qasm3Parser::logicalOperator() {
  LogicalOperatorContext *_localctx = _tracker.createInstance<LogicalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 116, qasm3Parser::RuleLogicalOperator);
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
    setState(638);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__37

    || _la == qasm3Parser::T__38)) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionStatementContext* qasm3Parser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 118, qasm3Parser::RuleExpressionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(640);
    expression(0);
    setState(641);
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


size_t qasm3Parser::ExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleExpression;
}


antlrcpp::Any qasm3Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 120;
  enterRecursionRule(_localctx, 120, qasm3Parser::RuleExpression, precedence);

    

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
    setState(647);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      setState(644);
      expressionTerminator(0);
      break;
    }

    case 2: {
      setState(645);
      unaryExpression();
      break;
    }

    case 3: {
      setState(646);
      logicalAndExpression(0);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(654);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(649);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(650);
        match(qasm3Parser::T__38);
        setState(651);
        logicalAndExpression(0); 
      }
      setState(656);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
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


size_t qasm3Parser::LogicalAndExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleLogicalAndExpression;
}


antlrcpp::Any qasm3Parser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 122;
  enterRecursionRule(_localctx, 122, qasm3Parser::RuleLogicalAndExpression, precedence);

    

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
    setState(658);
    bitOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(665);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalAndExpression);
        setState(660);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(661);
        match(qasm3Parser::T__37);
        setState(662);
        bitOrExpression(0); 
      }
      setState(667);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
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


size_t qasm3Parser::BitOrExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitOrExpression;
}


antlrcpp::Any qasm3Parser::BitOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 124;
  enterRecursionRule(_localctx, 124, qasm3Parser::RuleBitOrExpression, precedence);

    

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
    setState(669);
    xOrExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(676);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitOrExpression);
        setState(671);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(672);
        match(qasm3Parser::T__39);
        setState(673);
        xOrExpression(0); 
      }
      setState(678);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
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


size_t qasm3Parser::XOrExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleXOrExpression;
}


antlrcpp::Any qasm3Parser::XOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 126;
  enterRecursionRule(_localctx, 126, qasm3Parser::RuleXOrExpression, precedence);

    

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
    setState(680);
    bitAndExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(687);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<XOrExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleXOrExpression);
        setState(682);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(683);
        match(qasm3Parser::T__40);
        setState(684);
        bitAndExpression(0); 
      }
      setState(689);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
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


size_t qasm3Parser::BitAndExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitAndExpression;
}


antlrcpp::Any qasm3Parser::BitAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 128;
  enterRecursionRule(_localctx, 128, qasm3Parser::RuleBitAndExpression, precedence);

    

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
    setState(691);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(698);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitAndExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitAndExpression);
        setState(693);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(694);
        match(qasm3Parser::T__41);
        setState(695);
        equalityExpression(0); 
      }
      setState(700);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
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

qasm3Parser::EqualityOperatorContext* qasm3Parser::EqualityExpressionContext::equalityOperator() {
  return getRuleContext<qasm3Parser::EqualityOperatorContext>(0);
}


size_t qasm3Parser::EqualityExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleEqualityExpression;
}


antlrcpp::Any qasm3Parser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 130;
  enterRecursionRule(_localctx, 130, qasm3Parser::RuleEqualityExpression, precedence);

    

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
    setState(702);
    comparisonExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(710);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
        setState(704);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(705);
        equalityOperator();
        setState(706);
        comparisonExpression(0); 
      }
      setState(712);
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

qasm3Parser::ComparisonOperatorContext* qasm3Parser::ComparisonExpressionContext::comparisonOperator() {
  return getRuleContext<qasm3Parser::ComparisonOperatorContext>(0);
}


size_t qasm3Parser::ComparisonExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleComparisonExpression;
}


antlrcpp::Any qasm3Parser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 132;
  enterRecursionRule(_localctx, 132, qasm3Parser::RuleComparisonExpression, precedence);

    

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
    bitShiftExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(722);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ComparisonExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleComparisonExpression);
        setState(716);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(717);
        comparisonOperator();
        setState(718);
        bitShiftExpression(0); 
      }
      setState(724);
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


size_t qasm3Parser::BitShiftExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleBitShiftExpression;
}


antlrcpp::Any qasm3Parser::BitShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 134;
  enterRecursionRule(_localctx, 134, qasm3Parser::RuleBitShiftExpression, precedence);

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
    setState(726);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(733);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<BitShiftExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleBitShiftExpression);
        setState(728);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(729);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::T__42

        || _la == qasm3Parser::T__43)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(730);
        additiveExpression(0); 
      }
      setState(735);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 136;
  enterRecursionRule(_localctx, 136, qasm3Parser::RuleAdditiveExpression, precedence);

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
    setState(737);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(744);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
        setState(739);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(740);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::PLUS

        || _la == qasm3Parser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(741);
        multiplicativeExpression(0); 
      }
      setState(746);
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

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

qasm3Parser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::PowerExpressionContext* qasm3Parser::MultiplicativeExpressionContext::powerExpression() {
  return getRuleContext<qasm3Parser::PowerExpressionContext>(0);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<qasm3Parser::UnaryExpressionContext>(0);
}

qasm3Parser::MultiplicativeExpressionContext* qasm3Parser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<qasm3Parser::MultiplicativeExpressionContext>(0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::MUL() {
  return getToken(qasm3Parser::MUL, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::DIV() {
  return getToken(qasm3Parser::DIV, 0);
}

tree::TerminalNode* qasm3Parser::MultiplicativeExpressionContext::MOD() {
  return getToken(qasm3Parser::MOD, 0);
}


size_t qasm3Parser::MultiplicativeExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleMultiplicativeExpression;
}


antlrcpp::Any qasm3Parser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
  size_t startState = 138;
  enterRecursionRule(_localctx, 138, qasm3Parser::RuleMultiplicativeExpression, precedence);

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
    setState(750);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__13:
      case qasm3Parser::T__45:
      case qasm3Parser::T__46:
      case qasm3Parser::T__47:
      case qasm3Parser::T__48:
      case qasm3Parser::T__49:
      case qasm3Parser::T__50:
      case qasm3Parser::T__51:
      case qasm3Parser::T__52:
      case qasm3Parser::T__53:
      case qasm3Parser::T__54:
      case qasm3Parser::T__55:
      case qasm3Parser::T__56:
      case qasm3Parser::T__57:
      case qasm3Parser::T__58:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84:
      case qasm3Parser::T__86:
      case qasm3Parser::LPAREN:
      case qasm3Parser::ImagNumber:
      case qasm3Parser::Constant:
      case qasm3Parser::Integer:
      case qasm3Parser::Identifier:
      case qasm3Parser::RealNumber:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::StringLiteral: {
        setState(748);
        powerExpression();
        break;
      }

      case qasm3Parser::T__29:
      case qasm3Parser::T__30:
      case qasm3Parser::MINUS: {
        setState(749);
        unaryExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(760);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
        setState(752);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(753);
        _la = _input->LA(1);
        if (!(((((_la - 107) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 107)) & ((1ULL << (qasm3Parser::MUL - 107))
          | (1ULL << (qasm3Parser::DIV - 107))
          | (1ULL << (qasm3Parser::MOD - 107)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(756);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::T__6:
          case qasm3Parser::T__7:
          case qasm3Parser::T__8:
          case qasm3Parser::T__9:
          case qasm3Parser::T__10:
          case qasm3Parser::T__11:
          case qasm3Parser::T__12:
          case qasm3Parser::T__13:
          case qasm3Parser::T__45:
          case qasm3Parser::T__46:
          case qasm3Parser::T__47:
          case qasm3Parser::T__48:
          case qasm3Parser::T__49:
          case qasm3Parser::T__50:
          case qasm3Parser::T__51:
          case qasm3Parser::T__52:
          case qasm3Parser::T__53:
          case qasm3Parser::T__54:
          case qasm3Parser::T__55:
          case qasm3Parser::T__56:
          case qasm3Parser::T__57:
          case qasm3Parser::T__58:
          case qasm3Parser::T__83:
          case qasm3Parser::T__84:
          case qasm3Parser::T__86:
          case qasm3Parser::LPAREN:
          case qasm3Parser::ImagNumber:
          case qasm3Parser::Constant:
          case qasm3Parser::Integer:
          case qasm3Parser::Identifier:
          case qasm3Parser::RealNumber:
          case qasm3Parser::TimingLiteral:
          case qasm3Parser::StringLiteral: {
            setState(754);
            powerExpression();
            break;
          }

          case qasm3Parser::T__29:
          case qasm3Parser::T__30:
          case qasm3Parser::MINUS: {
            setState(755);
            unaryExpression();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(762);
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

//----------------- UnaryExpressionContext ------------------------------------------------------------------

qasm3Parser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::UnaryOperatorContext* qasm3Parser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<qasm3Parser::UnaryOperatorContext>(0);
}

qasm3Parser::PowerExpressionContext* qasm3Parser::UnaryExpressionContext::powerExpression() {
  return getRuleContext<qasm3Parser::PowerExpressionContext>(0);
}


size_t qasm3Parser::UnaryExpressionContext::getRuleIndex() const {
  return qasm3Parser::RuleUnaryExpression;
}


antlrcpp::Any qasm3Parser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::UnaryExpressionContext* qasm3Parser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 140, qasm3Parser::RuleUnaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(763);
    unaryOperator();
    setState(764);
    powerExpression();
   
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

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::PowerExpressionContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

qasm3Parser::PowerExpressionContext* qasm3Parser::PowerExpressionContext::powerExpression() {
  return getRuleContext<qasm3Parser::PowerExpressionContext>(0);
}


size_t qasm3Parser::PowerExpressionContext::getRuleIndex() const {
  return qasm3Parser::RulePowerExpression;
}


antlrcpp::Any qasm3Parser::PowerExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitPowerExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PowerExpressionContext* qasm3Parser::powerExpression() {
  PowerExpressionContext *_localctx = _tracker.createInstance<PowerExpressionContext>(_ctx, getState());
  enterRule(_localctx, 142, qasm3Parser::RulePowerExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(771);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(766);
      expressionTerminator(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(767);
      expressionTerminator(0);
      setState(768);
      match(qasm3Parser::T__44);
      setState(769);
      powerExpression();
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

//----------------- ExpressionTerminatorContext ------------------------------------------------------------------

qasm3Parser::ExpressionTerminatorContext::ExpressionTerminatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Constant() {
  return getToken(qasm3Parser::Constant, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Integer() {
  return getToken(qasm3Parser::Integer, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::RealNumber() {
  return getToken(qasm3Parser::RealNumber, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::ImagNumber() {
  return getToken(qasm3Parser::ImagNumber, 0);
}

qasm3Parser::BooleanLiteralContext* qasm3Parser::ExpressionTerminatorContext::booleanLiteral() {
  return getRuleContext<qasm3Parser::BooleanLiteralContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
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

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::ExpressionTerminatorContext::expressionTerminator() {
  return getRuleContext<qasm3Parser::ExpressionTerminatorContext>(0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::LBRACKET() {
  return getToken(qasm3Parser::LBRACKET, 0);
}

tree::TerminalNode* qasm3Parser::ExpressionTerminatorContext::RBRACKET() {
  return getToken(qasm3Parser::RBRACKET, 0);
}


size_t qasm3Parser::ExpressionTerminatorContext::getRuleIndex() const {
  return qasm3Parser::RuleExpressionTerminator;
}


antlrcpp::Any qasm3Parser::ExpressionTerminatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpressionTerminator(this);
  else
    return visitor->visitChildren(this);
}


qasm3Parser::ExpressionTerminatorContext* qasm3Parser::expressionTerminator() {
   return expressionTerminator(0);
}

qasm3Parser::ExpressionTerminatorContext* qasm3Parser::expressionTerminator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  qasm3Parser::ExpressionTerminatorContext *_localctx = _tracker.createInstance<ExpressionTerminatorContext>(_ctx, parentState);
  qasm3Parser::ExpressionTerminatorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 144;
  enterRecursionRule(_localctx, 144, qasm3Parser::RuleExpressionTerminator, precedence);

    

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
    setState(788);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      setState(774);
      match(qasm3Parser::Constant);
      break;
    }

    case 2: {
      setState(775);
      match(qasm3Parser::Integer);
      break;
    }

    case 3: {
      setState(776);
      match(qasm3Parser::RealNumber);
      break;
    }

    case 4: {
      setState(777);
      match(qasm3Parser::ImagNumber);
      break;
    }

    case 5: {
      setState(778);
      booleanLiteral();
      break;
    }

    case 6: {
      setState(779);
      match(qasm3Parser::Identifier);
      break;
    }

    case 7: {
      setState(780);
      match(qasm3Parser::StringLiteral);
      break;
    }

    case 8: {
      setState(781);
      builtInCall();
      break;
    }

    case 9: {
      setState(782);
      externOrSubroutineCall();
      break;
    }

    case 10: {
      setState(783);
      timingIdentifier();
      break;
    }

    case 11: {
      setState(784);
      match(qasm3Parser::LPAREN);
      setState(785);
      expression(0);
      setState(786);
      match(qasm3Parser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(797);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionTerminatorContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpressionTerminator);
        setState(790);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(791);
        match(qasm3Parser::LBRACKET);
        setState(792);
        expression(0);
        setState(793);
        match(qasm3Parser::RBRACKET); 
      }
      setState(799);
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

//----------------- BooleanLiteralContext ------------------------------------------------------------------

qasm3Parser::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::BooleanLiteralContext::getRuleIndex() const {
  return qasm3Parser::RuleBooleanLiteral;
}


antlrcpp::Any qasm3Parser::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BooleanLiteralContext* qasm3Parser::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 146, qasm3Parser::RuleBooleanLiteral);
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
    setState(800);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__45

    || _la == qasm3Parser::T__46)) {
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

qasm3Parser::BuiltInMathContext* qasm3Parser::BuiltInCallContext::builtInMath() {
  return getRuleContext<qasm3Parser::BuiltInMathContext>(0);
}

qasm3Parser::CastOperatorContext* qasm3Parser::BuiltInCallContext::castOperator() {
  return getRuleContext<qasm3Parser::CastOperatorContext>(0);
}


size_t qasm3Parser::BuiltInCallContext::getRuleIndex() const {
  return qasm3Parser::RuleBuiltInCall;
}


antlrcpp::Any qasm3Parser::BuiltInCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBuiltInCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BuiltInCallContext* qasm3Parser::builtInCall() {
  BuiltInCallContext *_localctx = _tracker.createInstance<BuiltInCallContext>(_ctx, getState());
  enterRule(_localctx, 148, qasm3Parser::RuleBuiltInCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(804);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__47:
      case qasm3Parser::T__48:
      case qasm3Parser::T__49:
      case qasm3Parser::T__50:
      case qasm3Parser::T__51:
      case qasm3Parser::T__52:
      case qasm3Parser::T__53:
      case qasm3Parser::T__54:
      case qasm3Parser::T__55:
      case qasm3Parser::T__56:
      case qasm3Parser::T__57:
      case qasm3Parser::T__58: {
        setState(802);
        builtInMath();
        break;
      }

      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__13:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84: {
        setState(803);
        castOperator();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(806);
    match(qasm3Parser::LPAREN);
    setState(807);
    expressionList();
    setState(808);
    match(qasm3Parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInMathContext ------------------------------------------------------------------

qasm3Parser::BuiltInMathContext::BuiltInMathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::BuiltInMathContext::getRuleIndex() const {
  return qasm3Parser::RuleBuiltInMath;
}


antlrcpp::Any qasm3Parser::BuiltInMathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBuiltInMath(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BuiltInMathContext* qasm3Parser::builtInMath() {
  BuiltInMathContext *_localctx = _tracker.createInstance<BuiltInMathContext>(_ctx, getState());
  enterRule(_localctx, 150, qasm3Parser::RuleBuiltInMath);
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
    setState(810);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0))) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCastOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CastOperatorContext* qasm3Parser::castOperator() {
  CastOperatorContext *_localctx = _tracker.createInstance<CastOperatorContext>(_ctx, getState());
  enterRule(_localctx, 152, qasm3Parser::RuleCastOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(812);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExpressionListContext* qasm3Parser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 154, qasm3Parser::RuleExpressionList);
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
    setState(814);
    expression(0);
    setState(819);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == qasm3Parser::COMMA) {
      setState(815);
      match(qasm3Parser::COMMA);
      setState(816);
      expression(0);
      setState(821);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitEqualsExpression(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EqualsExpressionContext* qasm3Parser::equalsExpression() {
  EqualsExpressionContext *_localctx = _tracker.createInstance<EqualsExpressionContext>(_ctx, getState());
  enterRule(_localctx, 156, qasm3Parser::RuleEqualsExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(822);
    match(qasm3Parser::EQUALS);
    setState(823);
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


size_t qasm3Parser::AssignmentOperatorContext::getRuleIndex() const {
  return qasm3Parser::RuleAssignmentOperator;
}


antlrcpp::Any qasm3Parser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::AssignmentOperatorContext* qasm3Parser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 158, qasm3Parser::RuleAssignmentOperator);
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
    _la = _input->LA(1);
    if (!(((((_la - 60) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 60)) & ((1ULL << (qasm3Parser::T__59 - 60))
      | (1ULL << (qasm3Parser::T__60 - 60))
      | (1ULL << (qasm3Parser::T__61 - 60))
      | (1ULL << (qasm3Parser::T__62 - 60))
      | (1ULL << (qasm3Parser::T__63 - 60))
      | (1ULL << (qasm3Parser::T__64 - 60))
      | (1ULL << (qasm3Parser::T__65 - 60))
      | (1ULL << (qasm3Parser::T__66 - 60))
      | (1ULL << (qasm3Parser::T__67 - 60))
      | (1ULL << (qasm3Parser::T__68 - 60))
      | (1ULL << (qasm3Parser::T__69 - 60))
      | (1ULL << (qasm3Parser::T__70 - 60))
      | (1ULL << (qasm3Parser::EQUALS - 60)))) != 0))) {
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

//----------------- SetDeclarationContext ------------------------------------------------------------------

qasm3Parser::SetDeclarationContext::SetDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::LBRACE() {
  return getToken(qasm3Parser::LBRACE, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::SetDeclarationContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::RBRACE() {
  return getToken(qasm3Parser::RBRACE, 0);
}

qasm3Parser::RangeDefinitionContext* qasm3Parser::SetDeclarationContext::rangeDefinition() {
  return getRuleContext<qasm3Parser::RangeDefinitionContext>(0);
}

tree::TerminalNode* qasm3Parser::SetDeclarationContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}


size_t qasm3Parser::SetDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleSetDeclaration;
}


antlrcpp::Any qasm3Parser::SetDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSetDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SetDeclarationContext* qasm3Parser::setDeclaration() {
  SetDeclarationContext *_localctx = _tracker.createInstance<SetDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 160, qasm3Parser::RuleSetDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(833);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::LBRACE: {
        enterOuterAlt(_localctx, 1);
        setState(827);
        match(qasm3Parser::LBRACE);
        setState(828);
        expressionList();
        setState(829);
        match(qasm3Parser::RBRACE);
        break;
      }

      case qasm3Parser::LBRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(831);
        rangeDefinition();
        break;
      }

      case qasm3Parser::Identifier: {
        enterOuterAlt(_localctx, 3);
        setState(832);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitProgramBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ProgramBlockContext* qasm3Parser::programBlock() {
  ProgramBlockContext *_localctx = _tracker.createInstance<ProgramBlockContext>(_ctx, getState());
  enterRule(_localctx, 162, qasm3Parser::RuleProgramBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(846);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(835);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(836);
      controlDirective();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(837);
      match(qasm3Parser::LBRACE);
      setState(842);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__12)
        | (1ULL << qasm3Parser::T__13)
        | (1ULL << qasm3Parser::T__14)
        | (1ULL << qasm3Parser::T__15)
        | (1ULL << qasm3Parser::T__18)
        | (1ULL << qasm3Parser::T__19)
        | (1ULL << qasm3Parser::T__20)
        | (1ULL << qasm3Parser::T__21)
        | (1ULL << qasm3Parser::T__22)
        | (1ULL << qasm3Parser::T__23)
        | (1ULL << qasm3Parser::T__24)
        | (1ULL << qasm3Parser::T__26)
        | (1ULL << qasm3Parser::T__27)
        | (1ULL << qasm3Parser::T__28)
        | (1ULL << qasm3Parser::T__29)
        | (1ULL << qasm3Parser::T__30)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51)
        | (1ULL << qasm3Parser::T__52)
        | (1ULL << qasm3Parser::T__53)
        | (1ULL << qasm3Parser::T__54)
        | (1ULL << qasm3Parser::T__55)
        | (1ULL << qasm3Parser::T__56)
        | (1ULL << qasm3Parser::T__57)
        | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (qasm3Parser::T__71 - 72))
        | (1ULL << (qasm3Parser::T__73 - 72))
        | (1ULL << (qasm3Parser::T__75 - 72))
        | (1ULL << (qasm3Parser::T__76 - 72))
        | (1ULL << (qasm3Parser::T__77 - 72))
        | (1ULL << (qasm3Parser::T__78 - 72))
        | (1ULL << (qasm3Parser::T__79 - 72))
        | (1ULL << (qasm3Parser::T__83 - 72))
        | (1ULL << (qasm3Parser::T__84 - 72))
        | (1ULL << (qasm3Parser::T__85 - 72))
        | (1ULL << (qasm3Parser::T__86 - 72))
        | (1ULL << (qasm3Parser::T__87 - 72))
        | (1ULL << (qasm3Parser::T__88 - 72))
        | (1ULL << (qasm3Parser::LPAREN - 72))
        | (1ULL << (qasm3Parser::MINUS - 72))
        | (1ULL << (qasm3Parser::ImagNumber - 72))
        | (1ULL << (qasm3Parser::Constant - 72))
        | (1ULL << (qasm3Parser::Integer - 72))
        | (1ULL << (qasm3Parser::Identifier - 72))
        | (1ULL << (qasm3Parser::RealNumber - 72))
        | (1ULL << (qasm3Parser::TimingLiteral - 72))
        | (1ULL << (qasm3Parser::StringLiteral - 72)))) != 0)) {
        setState(840);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
        case 1: {
          setState(838);
          statement();
          break;
        }

        case 2: {
          setState(839);
          controlDirective();
          break;
        }

        default:
          break;
        }
        setState(844);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(845);
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


size_t qasm3Parser::BranchingStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleBranchingStatement;
}


antlrcpp::Any qasm3Parser::BranchingStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitBranchingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::BranchingStatementContext* qasm3Parser::branchingStatement() {
  BranchingStatementContext *_localctx = _tracker.createInstance<BranchingStatementContext>(_ctx, getState());
  enterRule(_localctx, 164, qasm3Parser::RuleBranchingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(848);
    match(qasm3Parser::T__71);
    setState(849);
    match(qasm3Parser::LPAREN);
    setState(850);
    expression(0);
    setState(851);
    match(qasm3Parser::RPAREN);
    setState(852);
    programBlock();
    setState(855);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      setState(853);
      match(qasm3Parser::T__72);
      setState(854);
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

tree::TerminalNode* qasm3Parser::LoopSignatureContext::Identifier() {
  return getToken(qasm3Parser::Identifier, 0);
}

qasm3Parser::SetDeclarationContext* qasm3Parser::LoopSignatureContext::setDeclaration() {
  return getRuleContext<qasm3Parser::SetDeclarationContext>(0);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitLoopSignature(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LoopSignatureContext* qasm3Parser::loopSignature() {
  LoopSignatureContext *_localctx = _tracker.createInstance<LoopSignatureContext>(_ctx, getState());
  enterRule(_localctx, 166, qasm3Parser::RuleLoopSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(866);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__73: {
        enterOuterAlt(_localctx, 1);
        setState(857);
        match(qasm3Parser::T__73);
        setState(858);
        match(qasm3Parser::Identifier);
        setState(859);
        match(qasm3Parser::T__74);
        setState(860);
        setDeclaration();
        break;
      }

      case qasm3Parser::T__75: {
        enterOuterAlt(_localctx, 2);
        setState(861);
        match(qasm3Parser::T__75);
        setState(862);
        match(qasm3Parser::LPAREN);
        setState(863);
        expression(0);
        setState(864);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitLoopStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::LoopStatementContext* qasm3Parser::loopStatement() {
  LoopStatementContext *_localctx = _tracker.createInstance<LoopStatementContext>(_ctx, getState());
  enterRule(_localctx, 168, qasm3Parser::RuleLoopStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(868);
    loopSignature();
    setState(869);
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

tree::TerminalNode* qasm3Parser::EndStatementContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::EndStatementContext::getRuleIndex() const {
  return qasm3Parser::RuleEndStatement;
}


antlrcpp::Any qasm3Parser::EndStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitEndStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::EndStatementContext* qasm3Parser::endStatement() {
  EndStatementContext *_localctx = _tracker.createInstance<EndStatementContext>(_ctx, getState());
  enterRule(_localctx, 170, qasm3Parser::RuleEndStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(871);
    match(qasm3Parser::T__76);
    setState(872);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ReturnStatementContext* qasm3Parser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 172, qasm3Parser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(874);
    match(qasm3Parser::T__77);
    setState(877);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__6:
      case qasm3Parser::T__7:
      case qasm3Parser::T__8:
      case qasm3Parser::T__9:
      case qasm3Parser::T__10:
      case qasm3Parser::T__11:
      case qasm3Parser::T__12:
      case qasm3Parser::T__13:
      case qasm3Parser::T__29:
      case qasm3Parser::T__30:
      case qasm3Parser::T__45:
      case qasm3Parser::T__46:
      case qasm3Parser::T__47:
      case qasm3Parser::T__48:
      case qasm3Parser::T__49:
      case qasm3Parser::T__50:
      case qasm3Parser::T__51:
      case qasm3Parser::T__52:
      case qasm3Parser::T__53:
      case qasm3Parser::T__54:
      case qasm3Parser::T__55:
      case qasm3Parser::T__56:
      case qasm3Parser::T__57:
      case qasm3Parser::T__58:
      case qasm3Parser::T__83:
      case qasm3Parser::T__84:
      case qasm3Parser::T__86:
      case qasm3Parser::LPAREN:
      case qasm3Parser::MINUS:
      case qasm3Parser::ImagNumber:
      case qasm3Parser::Constant:
      case qasm3Parser::Integer:
      case qasm3Parser::Identifier:
      case qasm3Parser::RealNumber:
      case qasm3Parser::TimingLiteral:
      case qasm3Parser::StringLiteral: {
        setState(875);
        expression(0);
        break;
      }

      case qasm3Parser::T__22: {
        setState(876);
        quantumMeasurement();
        break;
      }

      case qasm3Parser::SEMICOLON: {
        break;
      }

    default:
      break;
    }
    setState(879);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitControlDirective(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ControlDirectiveContext* qasm3Parser::controlDirective() {
  ControlDirectiveContext *_localctx = _tracker.createInstance<ControlDirectiveContext>(_ctx, getState());
  enterRule(_localctx, 174, qasm3Parser::RuleControlDirective);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(885);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__78:
      case qasm3Parser::T__79: {
        enterOuterAlt(_localctx, 1);
        setState(881);
        _la = _input->LA(1);
        if (!(_la == qasm3Parser::T__78

        || _la == qasm3Parser::T__79)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(882);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::T__76: {
        enterOuterAlt(_localctx, 2);
        setState(883);
        endStatement();
        break;
      }

      case qasm3Parser::T__77: {
        enterOuterAlt(_localctx, 3);
        setState(884);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExternDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternDeclarationContext* qasm3Parser::externDeclaration() {
  ExternDeclarationContext *_localctx = _tracker.createInstance<ExternDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 176, qasm3Parser::RuleExternDeclaration);
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
    setState(887);
    match(qasm3Parser::T__80);
    setState(888);
    match(qasm3Parser::Identifier);
    setState(889);
    match(qasm3Parser::LPAREN);
    setState(891);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13))) != 0) || _la == qasm3Parser::T__83

    || _la == qasm3Parser::T__84) {
      setState(890);
      classicalTypeList();
    }
    setState(893);
    match(qasm3Parser::RPAREN);
    setState(895);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(894);
      returnSignature();
    }
    setState(897);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitExternOrSubroutineCall(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::ExternOrSubroutineCallContext* qasm3Parser::externOrSubroutineCall() {
  ExternOrSubroutineCallContext *_localctx = _tracker.createInstance<ExternOrSubroutineCallContext>(_ctx, getState());
  enterRule(_localctx, 178, qasm3Parser::RuleExternOrSubroutineCall);
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
    setState(899);
    match(qasm3Parser::Identifier);
    setState(900);
    match(qasm3Parser::LPAREN);
    setState(902);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 84) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 84)) & ((1ULL << (qasm3Parser::T__83 - 84))
      | (1ULL << (qasm3Parser::T__84 - 84))
      | (1ULL << (qasm3Parser::T__86 - 84))
      | (1ULL << (qasm3Parser::LPAREN - 84))
      | (1ULL << (qasm3Parser::MINUS - 84))
      | (1ULL << (qasm3Parser::ImagNumber - 84))
      | (1ULL << (qasm3Parser::Constant - 84))
      | (1ULL << (qasm3Parser::Integer - 84))
      | (1ULL << (qasm3Parser::Identifier - 84))
      | (1ULL << (qasm3Parser::RealNumber - 84))
      | (1ULL << (qasm3Parser::TimingLiteral - 84))
      | (1ULL << (qasm3Parser::StringLiteral - 84)))) != 0)) {
      setState(901);
      expressionList();
    }
    setState(904);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSubroutineDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineDefinitionContext* qasm3Parser::subroutineDefinition() {
  SubroutineDefinitionContext *_localctx = _tracker.createInstance<SubroutineDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 180, qasm3Parser::RuleSubroutineDefinition);
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
    setState(906);
    match(qasm3Parser::T__81);
    setState(907);
    match(qasm3Parser::Identifier);
    setState(908);
    match(qasm3Parser::LPAREN);
    setState(910);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__4)
      | (1ULL << qasm3Parser::T__5)
      | (1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13))) != 0) || _la == qasm3Parser::T__83

    || _la == qasm3Parser::T__84) {
      setState(909);
      anyTypeArgumentList();
    }
    setState(912);
    match(qasm3Parser::RPAREN);
    setState(914);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(913);
      returnSignature();
    }
    setState(916);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitSubroutineBlock(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::SubroutineBlockContext* qasm3Parser::subroutineBlock() {
  SubroutineBlockContext *_localctx = _tracker.createInstance<SubroutineBlockContext>(_ctx, getState());
  enterRule(_localctx, 182, qasm3Parser::RuleSubroutineBlock);
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
    setState(918);
    match(qasm3Parser::LBRACE);
    setState(922);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__14)
      | (1ULL << qasm3Parser::T__15)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__24)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__28)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (qasm3Parser::T__71 - 72))
      | (1ULL << (qasm3Parser::T__73 - 72))
      | (1ULL << (qasm3Parser::T__75 - 72))
      | (1ULL << (qasm3Parser::T__76 - 72))
      | (1ULL << (qasm3Parser::T__83 - 72))
      | (1ULL << (qasm3Parser::T__84 - 72))
      | (1ULL << (qasm3Parser::T__85 - 72))
      | (1ULL << (qasm3Parser::T__86 - 72))
      | (1ULL << (qasm3Parser::T__87 - 72))
      | (1ULL << (qasm3Parser::T__88 - 72))
      | (1ULL << (qasm3Parser::LPAREN - 72))
      | (1ULL << (qasm3Parser::MINUS - 72))
      | (1ULL << (qasm3Parser::ImagNumber - 72))
      | (1ULL << (qasm3Parser::Constant - 72))
      | (1ULL << (qasm3Parser::Integer - 72))
      | (1ULL << (qasm3Parser::Identifier - 72))
      | (1ULL << (qasm3Parser::RealNumber - 72))
      | (1ULL << (qasm3Parser::TimingLiteral - 72))
      | (1ULL << (qasm3Parser::StringLiteral - 72)))) != 0)) {
      setState(919);
      statement();
      setState(924);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(926);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::T__77) {
      setState(925);
      returnStatement();
    }
    setState(928);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitPragma(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::PragmaContext* qasm3Parser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 184, qasm3Parser::RulePragma);
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
    setState(930);
    match(qasm3Parser::T__82);
    setState(931);
    match(qasm3Parser::LBRACE);
    setState(935);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
      | (1ULL << qasm3Parser::T__7)
      | (1ULL << qasm3Parser::T__8)
      | (1ULL << qasm3Parser::T__9)
      | (1ULL << qasm3Parser::T__10)
      | (1ULL << qasm3Parser::T__11)
      | (1ULL << qasm3Parser::T__12)
      | (1ULL << qasm3Parser::T__13)
      | (1ULL << qasm3Parser::T__14)
      | (1ULL << qasm3Parser::T__15)
      | (1ULL << qasm3Parser::T__18)
      | (1ULL << qasm3Parser::T__19)
      | (1ULL << qasm3Parser::T__20)
      | (1ULL << qasm3Parser::T__21)
      | (1ULL << qasm3Parser::T__22)
      | (1ULL << qasm3Parser::T__23)
      | (1ULL << qasm3Parser::T__24)
      | (1ULL << qasm3Parser::T__26)
      | (1ULL << qasm3Parser::T__27)
      | (1ULL << qasm3Parser::T__28)
      | (1ULL << qasm3Parser::T__29)
      | (1ULL << qasm3Parser::T__30)
      | (1ULL << qasm3Parser::T__45)
      | (1ULL << qasm3Parser::T__46)
      | (1ULL << qasm3Parser::T__47)
      | (1ULL << qasm3Parser::T__48)
      | (1ULL << qasm3Parser::T__49)
      | (1ULL << qasm3Parser::T__50)
      | (1ULL << qasm3Parser::T__51)
      | (1ULL << qasm3Parser::T__52)
      | (1ULL << qasm3Parser::T__53)
      | (1ULL << qasm3Parser::T__54)
      | (1ULL << qasm3Parser::T__55)
      | (1ULL << qasm3Parser::T__56)
      | (1ULL << qasm3Parser::T__57)
      | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 72) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 72)) & ((1ULL << (qasm3Parser::T__71 - 72))
      | (1ULL << (qasm3Parser::T__73 - 72))
      | (1ULL << (qasm3Parser::T__75 - 72))
      | (1ULL << (qasm3Parser::T__76 - 72))
      | (1ULL << (qasm3Parser::T__83 - 72))
      | (1ULL << (qasm3Parser::T__84 - 72))
      | (1ULL << (qasm3Parser::T__85 - 72))
      | (1ULL << (qasm3Parser::T__86 - 72))
      | (1ULL << (qasm3Parser::T__87 - 72))
      | (1ULL << (qasm3Parser::T__88 - 72))
      | (1ULL << (qasm3Parser::LPAREN - 72))
      | (1ULL << (qasm3Parser::MINUS - 72))
      | (1ULL << (qasm3Parser::ImagNumber - 72))
      | (1ULL << (qasm3Parser::Constant - 72))
      | (1ULL << (qasm3Parser::Integer - 72))
      | (1ULL << (qasm3Parser::Identifier - 72))
      | (1ULL << (qasm3Parser::RealNumber - 72))
      | (1ULL << (qasm3Parser::TimingLiteral - 72))
      | (1ULL << (qasm3Parser::StringLiteral - 72)))) != 0)) {
      setState(932);
      statement();
      setState(937);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(938);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimingTypeContext ------------------------------------------------------------------

qasm3Parser::TimingTypeContext::TimingTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::TimingTypeContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingType;
}


antlrcpp::Any qasm3Parser::TimingTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingType(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingTypeContext* qasm3Parser::timingType() {
  TimingTypeContext *_localctx = _tracker.createInstance<TimingTypeContext>(_ctx, getState());
  enterRule(_localctx, 186, qasm3Parser::RuleTimingType);
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
    setState(940);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__83

    || _la == qasm3Parser::T__84)) {
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

//----------------- TimingBoxContext ------------------------------------------------------------------

qasm3Parser::TimingBoxContext::TimingBoxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingBox(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingBoxContext* qasm3Parser::timingBox() {
  TimingBoxContext *_localctx = _tracker.createInstance<TimingBoxContext>(_ctx, getState());
  enterRule(_localctx, 188, qasm3Parser::RuleTimingBox);
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
    setState(942);
    match(qasm3Parser::T__85);
    setState(944);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LBRACKET) {
      setState(943);
      designator();
    }
    setState(946);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingIdentifier(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingIdentifierContext* qasm3Parser::timingIdentifier() {
  TimingIdentifierContext *_localctx = _tracker.createInstance<TimingIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 190, qasm3Parser::RuleTimingIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(956);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::TimingLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(948);
        match(qasm3Parser::TimingLiteral);
        break;
      }

      case qasm3Parser::T__86: {
        enterOuterAlt(_localctx, 2);
        setState(949);
        match(qasm3Parser::T__86);
        setState(950);
        match(qasm3Parser::LPAREN);
        setState(953);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case qasm3Parser::Identifier: {
            setState(951);
            match(qasm3Parser::Identifier);
            break;
          }

          case qasm3Parser::LBRACE: {
            setState(952);
            quantumBlock();
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(955);
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

//----------------- TimingInstructionNameContext ------------------------------------------------------------------

qasm3Parser::TimingInstructionNameContext::TimingInstructionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t qasm3Parser::TimingInstructionNameContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingInstructionName;
}


antlrcpp::Any qasm3Parser::TimingInstructionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingInstructionName(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingInstructionNameContext* qasm3Parser::timingInstructionName() {
  TimingInstructionNameContext *_localctx = _tracker.createInstance<TimingInstructionNameContext>(_ctx, getState());
  enterRule(_localctx, 192, qasm3Parser::RuleTimingInstructionName);
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
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__87

    || _la == qasm3Parser::T__88)) {
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

//----------------- TimingInstructionContext ------------------------------------------------------------------

qasm3Parser::TimingInstructionContext::TimingInstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

qasm3Parser::TimingInstructionNameContext* qasm3Parser::TimingInstructionContext::timingInstructionName() {
  return getRuleContext<qasm3Parser::TimingInstructionNameContext>(0);
}

qasm3Parser::DesignatorContext* qasm3Parser::TimingInstructionContext::designator() {
  return getRuleContext<qasm3Parser::DesignatorContext>(0);
}

qasm3Parser::IndexIdentifierListContext* qasm3Parser::TimingInstructionContext::indexIdentifierList() {
  return getRuleContext<qasm3Parser::IndexIdentifierListContext>(0);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::LPAREN() {
  return getToken(qasm3Parser::LPAREN, 0);
}

tree::TerminalNode* qasm3Parser::TimingInstructionContext::RPAREN() {
  return getToken(qasm3Parser::RPAREN, 0);
}

qasm3Parser::ExpressionListContext* qasm3Parser::TimingInstructionContext::expressionList() {
  return getRuleContext<qasm3Parser::ExpressionListContext>(0);
}


size_t qasm3Parser::TimingInstructionContext::getRuleIndex() const {
  return qasm3Parser::RuleTimingInstruction;
}


antlrcpp::Any qasm3Parser::TimingInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingInstruction(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingInstructionContext* qasm3Parser::timingInstruction() {
  TimingInstructionContext *_localctx = _tracker.createInstance<TimingInstructionContext>(_ctx, getState());
  enterRule(_localctx, 194, qasm3Parser::RuleTimingInstruction);
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
    setState(960);
    timingInstructionName();
    setState(966);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(961);
      match(qasm3Parser::LPAREN);
      setState(963);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__12)
        | (1ULL << qasm3Parser::T__13)
        | (1ULL << qasm3Parser::T__29)
        | (1ULL << qasm3Parser::T__30)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51)
        | (1ULL << qasm3Parser::T__52)
        | (1ULL << qasm3Parser::T__53)
        | (1ULL << qasm3Parser::T__54)
        | (1ULL << qasm3Parser::T__55)
        | (1ULL << qasm3Parser::T__56)
        | (1ULL << qasm3Parser::T__57)
        | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 84) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 84)) & ((1ULL << (qasm3Parser::T__83 - 84))
        | (1ULL << (qasm3Parser::T__84 - 84))
        | (1ULL << (qasm3Parser::T__86 - 84))
        | (1ULL << (qasm3Parser::LPAREN - 84))
        | (1ULL << (qasm3Parser::MINUS - 84))
        | (1ULL << (qasm3Parser::ImagNumber - 84))
        | (1ULL << (qasm3Parser::Constant - 84))
        | (1ULL << (qasm3Parser::Integer - 84))
        | (1ULL << (qasm3Parser::Identifier - 84))
        | (1ULL << (qasm3Parser::RealNumber - 84))
        | (1ULL << (qasm3Parser::TimingLiteral - 84))
        | (1ULL << (qasm3Parser::StringLiteral - 84)))) != 0)) {
        setState(962);
        expressionList();
      }
      setState(965);
      match(qasm3Parser::RPAREN);
    }
    setState(968);
    designator();
    setState(969);
    indexIdentifierList();
   
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitTimingStatement(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::TimingStatementContext* qasm3Parser::timingStatement() {
  TimingStatementContext *_localctx = _tracker.createInstance<TimingStatementContext>(_ctx, getState());
  enterRule(_localctx, 196, qasm3Parser::RuleTimingStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(975);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__87:
      case qasm3Parser::T__88: {
        enterOuterAlt(_localctx, 1);
        setState(971);
        timingInstruction();
        setState(972);
        match(qasm3Parser::SEMICOLON);
        break;
      }

      case qasm3Parser::T__85: {
        enterOuterAlt(_localctx, 2);
        setState(974);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationContext* qasm3Parser::calibration() {
  CalibrationContext *_localctx = _tracker.createInstance<CalibrationContext>(_ctx, getState());
  enterRule(_localctx, 198, qasm3Parser::RuleCalibration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(979);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case qasm3Parser::T__89: {
        enterOuterAlt(_localctx, 1);
        setState(977);
        calibrationGrammarDeclaration();
        break;
      }

      case qasm3Parser::T__90: {
        enterOuterAlt(_localctx, 2);
        setState(978);
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

qasm3Parser::CalibrationGrammarContext* qasm3Parser::CalibrationGrammarDeclarationContext::calibrationGrammar() {
  return getRuleContext<qasm3Parser::CalibrationGrammarContext>(0);
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarDeclarationContext::SEMICOLON() {
  return getToken(qasm3Parser::SEMICOLON, 0);
}


size_t qasm3Parser::CalibrationGrammarDeclarationContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammarDeclaration;
}


antlrcpp::Any qasm3Parser::CalibrationGrammarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationGrammarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarDeclarationContext* qasm3Parser::calibrationGrammarDeclaration() {
  CalibrationGrammarDeclarationContext *_localctx = _tracker.createInstance<CalibrationGrammarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 200, qasm3Parser::RuleCalibrationGrammarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(981);
    match(qasm3Parser::T__89);
    setState(982);
    calibrationGrammar();
    setState(983);
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationDefinition(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationDefinitionContext* qasm3Parser::calibrationDefinition() {
  CalibrationDefinitionContext *_localctx = _tracker.createInstance<CalibrationDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 202, qasm3Parser::RuleCalibrationDefinition);
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
    setState(985);
    match(qasm3Parser::T__90);
    setState(986);
    match(qasm3Parser::Identifier);
    setState(992);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::LPAREN) {
      setState(987);
      match(qasm3Parser::LPAREN);
      setState(989);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << qasm3Parser::T__6)
        | (1ULL << qasm3Parser::T__7)
        | (1ULL << qasm3Parser::T__8)
        | (1ULL << qasm3Parser::T__9)
        | (1ULL << qasm3Parser::T__10)
        | (1ULL << qasm3Parser::T__11)
        | (1ULL << qasm3Parser::T__12)
        | (1ULL << qasm3Parser::T__13)
        | (1ULL << qasm3Parser::T__29)
        | (1ULL << qasm3Parser::T__30)
        | (1ULL << qasm3Parser::T__45)
        | (1ULL << qasm3Parser::T__46)
        | (1ULL << qasm3Parser::T__47)
        | (1ULL << qasm3Parser::T__48)
        | (1ULL << qasm3Parser::T__49)
        | (1ULL << qasm3Parser::T__50)
        | (1ULL << qasm3Parser::T__51)
        | (1ULL << qasm3Parser::T__52)
        | (1ULL << qasm3Parser::T__53)
        | (1ULL << qasm3Parser::T__54)
        | (1ULL << qasm3Parser::T__55)
        | (1ULL << qasm3Parser::T__56)
        | (1ULL << qasm3Parser::T__57)
        | (1ULL << qasm3Parser::T__58))) != 0) || ((((_la - 84) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 84)) & ((1ULL << (qasm3Parser::T__83 - 84))
        | (1ULL << (qasm3Parser::T__84 - 84))
        | (1ULL << (qasm3Parser::T__86 - 84))
        | (1ULL << (qasm3Parser::LPAREN - 84))
        | (1ULL << (qasm3Parser::MINUS - 84))
        | (1ULL << (qasm3Parser::ImagNumber - 84))
        | (1ULL << (qasm3Parser::Constant - 84))
        | (1ULL << (qasm3Parser::Integer - 84))
        | (1ULL << (qasm3Parser::Identifier - 84))
        | (1ULL << (qasm3Parser::RealNumber - 84))
        | (1ULL << (qasm3Parser::TimingLiteral - 84))
        | (1ULL << (qasm3Parser::StringLiteral - 84)))) != 0)) {
        setState(988);
        calibrationArgumentList();
      }
      setState(991);
      match(qasm3Parser::RPAREN);
    }
    setState(994);
    identifierList();
    setState(996);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == qasm3Parser::ARROW) {
      setState(995);
      returnSignature();
    }
    setState(998);
    match(qasm3Parser::LBRACE);
    setState(1002);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(999);
        matchWildcard(); 
      }
      setState(1004);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx);
    }
    setState(1005);
    match(qasm3Parser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CalibrationGrammarContext ------------------------------------------------------------------

qasm3Parser::CalibrationGrammarContext::CalibrationGrammarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* qasm3Parser::CalibrationGrammarContext::StringLiteral() {
  return getToken(qasm3Parser::StringLiteral, 0);
}


size_t qasm3Parser::CalibrationGrammarContext::getRuleIndex() const {
  return qasm3Parser::RuleCalibrationGrammar;
}


antlrcpp::Any qasm3Parser::CalibrationGrammarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
    return parserVisitor->visitCalibrationGrammar(this);
  else
    return visitor->visitChildren(this);
}

qasm3Parser::CalibrationGrammarContext* qasm3Parser::calibrationGrammar() {
  CalibrationGrammarContext *_localctx = _tracker.createInstance<CalibrationGrammarContext>(_ctx, getState());
  enterRule(_localctx, 204, qasm3Parser::RuleCalibrationGrammar);
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
    setState(1007);
    _la = _input->LA(1);
    if (!(_la == qasm3Parser::T__91

    || _la == qasm3Parser::StringLiteral)) {
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
  if (auto parserVisitor = dynamic_cast<qasm3Visitor*>(visitor))
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
    setState(1011);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1009);
      classicalArgumentList();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1010);
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
    case 35: return indexIdentifierSempred(dynamic_cast<IndexIdentifierContext *>(context), predicateIndex);
    case 60: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 61: return logicalAndExpressionSempred(dynamic_cast<LogicalAndExpressionContext *>(context), predicateIndex);
    case 62: return bitOrExpressionSempred(dynamic_cast<BitOrExpressionContext *>(context), predicateIndex);
    case 63: return xOrExpressionSempred(dynamic_cast<XOrExpressionContext *>(context), predicateIndex);
    case 64: return bitAndExpressionSempred(dynamic_cast<BitAndExpressionContext *>(context), predicateIndex);
    case 65: return equalityExpressionSempred(dynamic_cast<EqualityExpressionContext *>(context), predicateIndex);
    case 66: return comparisonExpressionSempred(dynamic_cast<ComparisonExpressionContext *>(context), predicateIndex);
    case 67: return bitShiftExpressionSempred(dynamic_cast<BitShiftExpressionContext *>(context), predicateIndex);
    case 68: return additiveExpressionSempred(dynamic_cast<AdditiveExpressionContext *>(context), predicateIndex);
    case 69: return multiplicativeExpressionSempred(dynamic_cast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 72: return expressionTerminatorSempred(dynamic_cast<ExpressionTerminatorContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::indexIdentifierSempred(IndexIdentifierContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::logicalAndExpressionSempred(LogicalAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitOrExpressionSempred(BitOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::xOrExpressionSempred(XOrExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitAndExpressionSempred(BitAndExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::comparisonExpressionSempred(ComparisonExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::bitShiftExpressionSempred(BitShiftExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 10: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool qasm3Parser::expressionTerminatorSempred(ExpressionTerminatorContext *_localctx, size_t predicateIndex) {
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
  "identifierList", "quantumDeclaration", "quantumArgument", "quantumArgumentList", 
  "bitType", "singleDesignatorType", "noDesignatorType", "classicalType", 
  "numericType", "constantDeclaration", "singleDesignatorDeclaration", "noDesignatorDeclaration", 
  "bitDeclaration", "complexDeclaration", "classicalDeclaration", "classicalTypeList", 
  "classicalArgument", "classicalArgumentList", "anyTypeArgument", "anyTypeArgumentList", 
  "aliasStatement", "indexIdentifier", "indexIdentifierList", "rangeDefinition", 
  "quantumGateDefinition", "quantumGateSignature", "quantumGateName", "quantumBlock", 
  "quantumLoop", "quantumLoopBlock", "quantumStatement", "quantumInstruction", 
  "quantumPhase", "quantumReset", "quantumMeasurement", "quantumMeasurementAssignment", 
  "quantumBarrier", "quantumGateModifier", "powModifier", "ctrlModifier", 
  "quantumGateCall", "unaryOperator", "comparisonOperator", "equalityOperator", 
  "logicalOperator", "expressionStatement", "expression", "logicalAndExpression", 
  "bitOrExpression", "xOrExpression", "bitAndExpression", "equalityExpression", 
  "comparisonExpression", "bitShiftExpression", "additiveExpression", "multiplicativeExpression", 
  "unaryExpression", "powerExpression", "expressionTerminator", "booleanLiteral", 
  "builtInCall", "builtInMath", "castOperator", "expressionList", "equalsExpression", 
  "assignmentOperator", "setDeclaration", "programBlock", "branchingStatement", 
  "loopSignature", "loopStatement", "endStatement", "returnStatement", "controlDirective", 
  "externDeclaration", "externOrSubroutineCall", "subroutineDefinition", 
  "subroutineBlock", "pragma", "timingType", "timingBox", "timingIdentifier", 
  "timingInstructionName", "timingInstruction", "timingStatement", "calibration", 
  "calibrationGrammarDeclaration", "calibrationDefinition", "calibrationGrammar", 
  "calibrationArgumentList"
};

std::vector<std::string> qasm3Parser::_literalNames = {
  "", "'OPENQASM'", "'include'", "'input'", "'output'", "'qreg'", "'qubit'", 
  "'bit'", "'creg'", "'int'", "'uint'", "'float'", "'angle'", "'bool'", 
  "'complex'", "'const'", "'let'", "'++'", "'gate'", "'U'", "'CX'", "'gphase'", 
  "'reset'", "'measure'", "'barrier'", "'inv'", "'@'", "'pow'", "'ctrl'", 
  "'negctrl'", "'~'", "'!'", "'>'", "'<'", "'>='", "'<='", "'=='", "'!='", 
  "'&&'", "'||'", "'|'", "'^'", "'&'", "'<<'", "'>>'", "'**'", "'true'", 
  "'false'", "'arcsin'", "'sin'", "'arccos'", "'cos'", "'arctan'", "'tan'", 
  "'exp'", "'ln'", "'sqrt'", "'rotl'", "'rotr'", "'popcount'", "'+='", "'-='", 
  "'*='", "'/='", "'&='", "'|='", "'~='", "'^='", "'<<='", "'>>='", "'%='", 
  "'**='", "'if'", "'else'", "'for'", "'in'", "'while'", "'end'", "'return'", 
  "'break'", "'continue'", "'extern'", "'def'", "'#pragma'", "'duration'", 
  "'stretch'", "'box'", "'durationof'", "'delay'", "'rotary'", "'defcalgrammar'", 
  "'defcal'", "'\"openpulse\"'", "'['", "']'", "'{'", "'}'", "'('", "')'", 
  "':'", "';'", "'.'", "','", "'='", "'->'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'im'"
};

std::vector<std::string> qasm3Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", 
  "COLON", "SEMICOLON", "DOT", "COMMA", "EQUALS", "ARROW", "PLUS", "MINUS", 
  "MUL", "DIV", "MOD", "IMAG", "ImagNumber", "Constant", "Whitespace", "Newline", 
  "Integer", "Identifier", "RealNumber", "TimingLiteral", "StringLiteral", 
  "LineComment", "BlockComment"
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
       0x3, 0x7b, 0x3f8, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x116, 0xa, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x11d, 0xa, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x12a, 
       0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x12d, 0xb, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x134, 0xa, 0x11, 
       0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x138, 0xa, 0x11, 0x3, 0x11, 0x5, 
       0x11, 0x13b, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
       0x140, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x144, 0xa, 0x12, 
       0x3, 0x12, 0x5, 0x12, 0x147, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x7, 0x13, 0x14c, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x14f, 0xb, 
       0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
       0x16, 0x5, 0x16, 0x157, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15f, 0xa, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x166, 
       0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x5, 0x1a, 0x174, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x179, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x5, 0x1c, 0x17e, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x182, 
       0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x185, 0xa, 0x1c, 0x3, 0x1c, 0x5, 
       0x1c, 0x188, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x190, 0xa, 0x1d, 0x3, 0x1e, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x196, 0xa, 0x1e, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x19b, 0xa, 0x1f, 0xc, 0x1f, 0xe, 
       0x1f, 0x19e, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1a6, 0xa, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1ad, 0xa, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1b1, 0xa, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 
       0x20, 0x1ba, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 
       0x1bf, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x1c2, 0xb, 0x21, 0x3, 0x22, 
       0x3, 0x22, 0x5, 0x22, 0x1c6, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x7, 0x23, 0x1cb, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x1ce, 0xb, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1e0, 
       0xa, 0x25, 0x5, 0x25, 0x1e2, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x7, 0x25, 0x1e7, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1ea, 0xb, 
       0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x1ef, 0xa, 0x26, 
       0xc, 0x26, 0xe, 0x26, 0x1f2, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 
       0x27, 0x1f6, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1fa, 0xa, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1fe, 0xa, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x209, 0xa, 0x29, 0x3, 0x29, 0x5, 
       0x29, 0x20c, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x215, 0xa, 0x2b, 0xc, 
       0x2b, 0xe, 0x2b, 0x218, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 
       0x222, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x225, 0xb, 0x2d, 0x3, 0x2d, 
       0x5, 0x2d, 0x228, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x5, 0x2e, 0x22e, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x235, 0xa, 0x2f, 0x3, 0x30, 0x7, 
       0x30, 0x238, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x23b, 0xb, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x242, 
       0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 
       0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x24d, 0xa, 
       0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x253, 
       0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x257, 0xa, 0x34, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x25c, 0xa, 0x35, 0x3, 0x35, 
       0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 
       0x26a, 0xa, 0x37, 0x3, 0x38, 0x7, 0x38, 0x26d, 0xa, 0x38, 0xc, 0x38, 
       0xe, 0x38, 0x270, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x5, 0x38, 0x277, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
       0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 
       0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x28a, 0xa, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x28f, 0xa, 0x3e, 0xc, 0x3e, 
       0xe, 0x3e, 0x292, 0xb, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
       0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x29a, 0xa, 0x3f, 0xc, 0x3f, 
       0xe, 0x3f, 0x29d, 0xb, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 
       0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x2a5, 0xa, 0x40, 0xc, 0x40, 
       0xe, 0x40, 0x2a8, 0xb, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
       0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x2b0, 0xa, 0x41, 0xc, 0x41, 
       0xe, 0x41, 0x2b3, 0xb, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
       0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x2bb, 0xa, 0x42, 0xc, 0x42, 
       0xe, 0x42, 0x2be, 0xb, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x2c7, 0xa, 0x43, 
       0xc, 0x43, 0xe, 0x43, 0x2ca, 0xb, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x7, 0x44, 0x2d3, 
       0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 0x2d6, 0xb, 0x44, 0x3, 0x45, 0x3, 
       0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x2de, 
       0xa, 0x45, 0xc, 0x45, 0xe, 0x45, 0x2e1, 0xb, 0x45, 0x3, 0x46, 0x3, 
       0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x2e9, 
       0xa, 0x46, 0xc, 0x46, 0xe, 0x46, 0x2ec, 0xb, 0x46, 0x3, 0x47, 0x3, 
       0x47, 0x3, 0x47, 0x5, 0x47, 0x2f1, 0xa, 0x47, 0x3, 0x47, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2f7, 0xa, 0x47, 0x7, 0x47, 0x2f9, 
       0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x2fc, 0xb, 0x47, 0x3, 0x48, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 
       0x49, 0x5, 0x49, 0x306, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
       0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
       0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 
       0x5, 0x4a, 0x317, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x31e, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 
       0x321, 0xb, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x5, 
       0x4c, 0x327, 0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
       0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 
       0x3, 0x4f, 0x7, 0x4f, 0x334, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x337, 
       0xb, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 
       0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 
       0x5, 0x52, 0x344, 0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 
       0x53, 0x3, 0x53, 0x7, 0x53, 0x34b, 0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 
       0x34e, 0xb, 0x53, 0x3, 0x53, 0x5, 0x53, 0x351, 0xa, 0x53, 0x3, 0x54, 
       0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 
       0x5, 0x54, 0x35a, 0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x5, 
       0x55, 0x365, 0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 
       0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 
       0x370, 0xa, 0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 
       0x59, 0x3, 0x59, 0x5, 0x59, 0x378, 0xa, 0x59, 0x3, 0x5a, 0x3, 0x5a, 
       0x3, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x37e, 0xa, 0x5a, 0x3, 0x5a, 0x3, 
       0x5a, 0x5, 0x5a, 0x382, 0xa, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5b, 
       0x3, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x389, 0xa, 0x5b, 0x3, 0x5b, 0x3, 
       0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x391, 
       0xa, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 0x5, 0x5c, 0x395, 0xa, 0x5c, 0x3, 
       0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 0x39b, 0xa, 0x5d, 
       0xc, 0x5d, 0xe, 0x5d, 0x39e, 0xb, 0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x3a1, 
       0xa, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 
       0x7, 0x5e, 0x3a8, 0xa, 0x5e, 0xc, 0x5e, 0xe, 0x5e, 0x3ab, 0xb, 0x5e, 
       0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 
       0x5, 0x60, 0x3b3, 0xa, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x61, 0x3, 
       0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x5, 0x61, 0x3bc, 0xa, 0x61, 
       0x3, 0x61, 0x5, 0x61, 0x3bf, 0xa, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 
       0x63, 0x3, 0x63, 0x3, 0x63, 0x5, 0x63, 0x3c6, 0xa, 0x63, 0x3, 0x63, 
       0x5, 0x63, 0x3c9, 0xa, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 
       0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x3d2, 0xa, 0x64, 
       0x3, 0x65, 0x3, 0x65, 0x5, 0x65, 0x3d6, 0xa, 0x65, 0x3, 0x66, 0x3, 
       0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 
       0x67, 0x5, 0x67, 0x3e0, 0xa, 0x67, 0x3, 0x67, 0x5, 0x67, 0x3e3, 0xa, 
       0x67, 0x3, 0x67, 0x3, 0x67, 0x5, 0x67, 0x3e7, 0xa, 0x67, 0x3, 0x67, 
       0x3, 0x67, 0x7, 0x67, 0x3eb, 0xa, 0x67, 0xc, 0x67, 0xe, 0x67, 0x3ee, 
       0xb, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 
       0x3, 0x69, 0x5, 0x69, 0x3f6, 0xa, 0x69, 0x3, 0x69, 0x3, 0x3ec, 0xe, 
       0x48, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 
       0x92, 0x6a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
       0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
       0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
       0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 
       0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
       0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 
       0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 
       0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 
       0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0xc0, 0xc2, 0xc4, 
       0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0x2, 0x16, 0x4, 0x2, 0x75, 0x75, 
       0x77, 0x77, 0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0xb, 
       0xe, 0x4, 0x2, 0x15, 0x16, 0x76, 0x76, 0x3, 0x2, 0x1e, 0x1f, 0x4, 
       0x2, 0x20, 0x21, 0x6c, 0x6c, 0x3, 0x2, 0x22, 0x25, 0x3, 0x2, 0x26, 
       0x27, 0x3, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x6b, 
       0x6c, 0x3, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x30, 0x31, 0x3, 0x2, 0x32, 
       0x3d, 0x4, 0x2, 0x3e, 0x49, 0x69, 0x69, 0x3, 0x2, 0x51, 0x52, 0x3, 
       0x2, 0x56, 0x57, 0x3, 0x2, 0x5a, 0x5b, 0x4, 0x2, 0x5e, 0x5e, 0x79, 
       0x79, 0x2, 0x41c, 0x2, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x4, 0xdb, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x8, 0xed, 0x3, 0x2, 
       0x2, 0x2, 0xa, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xc, 0xf3, 0x3, 0x2, 0x2, 
       0x2, 0xe, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x10, 0x108, 0x3, 0x2, 0x2, 0x2, 
       0x12, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x10f, 0x3, 0x2, 0x2, 0x2, 
       0x16, 0x113, 0x3, 0x2, 0x2, 0x2, 0x18, 0x11c, 0x3, 0x2, 0x2, 0x2, 
       0x1a, 0x120, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x123, 0x3, 0x2, 0x2, 0x2, 
       0x1e, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x20, 0x13a, 0x3, 0x2, 0x2, 0x2, 
       0x22, 0x146, 0x3, 0x2, 0x2, 0x2, 0x24, 0x148, 0x3, 0x2, 0x2, 0x2, 
       0x26, 0x150, 0x3, 0x2, 0x2, 0x2, 0x28, 0x152, 0x3, 0x2, 0x2, 0x2, 
       0x2a, 0x156, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x165, 0x3, 0x2, 0x2, 0x2, 
       0x2e, 0x167, 0x3, 0x2, 0x2, 0x2, 0x30, 0x16a, 0x3, 0x2, 0x2, 0x2, 
       0x32, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x34, 0x175, 0x3, 0x2, 0x2, 0x2, 
       0x36, 0x184, 0x3, 0x2, 0x2, 0x2, 0x38, 0x189, 0x3, 0x2, 0x2, 0x2, 
       0x3a, 0x195, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x19c, 0x3, 0x2, 0x2, 0x2, 
       0x3e, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
       0x42, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1cc, 0x3, 0x2, 0x2, 0x2, 
       0x46, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
       0x4a, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1f3, 0x3, 0x2, 0x2, 0x2, 
       0x4e, 0x201, 0x3, 0x2, 0x2, 0x2, 0x50, 0x205, 0x3, 0x2, 0x2, 0x2, 
       0x52, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x54, 0x211, 0x3, 0x2, 0x2, 0x2, 
       0x56, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x58, 0x227, 0x3, 0x2, 0x2, 0x2, 
       0x5a, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x234, 0x3, 0x2, 0x2, 0x2, 
       0x5e, 0x239, 0x3, 0x2, 0x2, 0x2, 0x60, 0x243, 0x3, 0x2, 0x2, 0x2, 
       0x62, 0x246, 0x3, 0x2, 0x2, 0x2, 0x64, 0x252, 0x3, 0x2, 0x2, 0x2, 
       0x66, 0x254, 0x3, 0x2, 0x2, 0x2, 0x68, 0x25b, 0x3, 0x2, 0x2, 0x2, 
       0x6a, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x264, 0x3, 0x2, 0x2, 0x2, 
       0x6e, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x27a, 0x3, 0x2, 0x2, 0x2, 
       0x72, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x74, 0x27e, 0x3, 0x2, 0x2, 0x2, 
       0x76, 0x280, 0x3, 0x2, 0x2, 0x2, 0x78, 0x282, 0x3, 0x2, 0x2, 0x2, 
       0x7a, 0x289, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x293, 0x3, 0x2, 0x2, 0x2, 
       0x7e, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x2a9, 0x3, 0x2, 0x2, 0x2, 
       0x82, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x84, 0x2bf, 0x3, 0x2, 0x2, 0x2, 
       0x86, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2d7, 0x3, 0x2, 0x2, 0x2, 
       0x8a, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2f0, 0x3, 0x2, 0x2, 0x2, 
       0x8e, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x90, 0x305, 0x3, 0x2, 0x2, 0x2, 
       0x92, 0x316, 0x3, 0x2, 0x2, 0x2, 0x94, 0x322, 0x3, 0x2, 0x2, 0x2, 
       0x96, 0x326, 0x3, 0x2, 0x2, 0x2, 0x98, 0x32c, 0x3, 0x2, 0x2, 0x2, 
       0x9a, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x330, 0x3, 0x2, 0x2, 0x2, 
       0x9e, 0x338, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x33b, 0x3, 0x2, 0x2, 0x2, 
       0xa2, 0x343, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x350, 0x3, 0x2, 0x2, 0x2, 
       0xa6, 0x352, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x364, 0x3, 0x2, 0x2, 0x2, 
       0xaa, 0x366, 0x3, 0x2, 0x2, 0x2, 0xac, 0x369, 0x3, 0x2, 0x2, 0x2, 
       0xae, 0x36c, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x377, 0x3, 0x2, 0x2, 0x2, 
       0xb2, 0x379, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x385, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0x38c, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x398, 0x3, 0x2, 0x2, 0x2, 
       0xba, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x3ae, 0x3, 0x2, 0x2, 0x2, 
       0xbe, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x3be, 0x3, 0x2, 0x2, 0x2, 
       0xc2, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x3c2, 0x3, 0x2, 0x2, 0x2, 
       0xc6, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x3d5, 0x3, 0x2, 0x2, 0x2, 
       0xca, 0x3d7, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x3db, 0x3, 0x2, 0x2, 0x2, 
       0xce, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x3f5, 0x3, 0x2, 0x2, 0x2, 
       0xd2, 0xd7, 0x5, 0x4, 0x3, 0x2, 0xd3, 0xd6, 0x5, 0xe, 0x8, 0x2, 0xd4, 
       0xd6, 0x5, 0x10, 0x9, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 
       0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 
       0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x3, 0x3, 
       0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdc, 0x5, 0x6, 
       0x4, 0x2, 0xdb, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 
       0x2, 0xdc, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x8, 0x5, 0x2, 
       0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 
       0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe6, 
       0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x5, 
       0xc, 0x7, 0x2, 0xe4, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 0x3, 0x2, 
       0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 
       0x2, 0xe7, 0x5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 
       0xe9, 0xea, 0x7, 0x3, 0x2, 0x2, 0xea, 0xeb, 0x9, 0x2, 0x2, 0x2, 0xeb, 
       0xec, 0x7, 0x66, 0x2, 0x2, 0xec, 0x7, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 
       0x7, 0x4, 0x2, 0x2, 0xee, 0xef, 0x7, 0x79, 0x2, 0x2, 0xef, 0xf0, 
       0x7, 0x66, 0x2, 0x2, 0xf0, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x9, 
       0x3, 0x2, 0x2, 0xf2, 0xb, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0xa, 
       0x6, 0x2, 0xf4, 0xf5, 0x5, 0x2c, 0x17, 0x2, 0xf5, 0xf6, 0x7, 0x76, 
       0x2, 0x2, 0xf6, 0xf7, 0x7, 0x66, 0x2, 0x2, 0xf7, 0xd, 0x3, 0x2, 0x2, 
       0x2, 0xf8, 0xff, 0x5, 0xb6, 0x5c, 0x2, 0xf9, 0xff, 0x5, 0xb2, 0x5a, 
       0x2, 0xfa, 0xff, 0x5, 0x4e, 0x28, 0x2, 0xfb, 0xff, 0x5, 0xc8, 0x65, 
       0x2, 0xfc, 0xff, 0x5, 0x12, 0xa, 0x2, 0xfd, 0xff, 0x5, 0xba, 0x5e, 
       0x2, 0xfe, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xf9, 0x3, 0x2, 0x2, 0x2, 
       0xfe, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfe, 
       0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xff, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x100, 0x109, 0x5, 0x78, 0x3d, 0x2, 0x101, 0x109, 
       0x5, 0x18, 0xd, 0x2, 0x102, 0x109, 0x5, 0x14, 0xb, 0x2, 0x103, 0x109, 
       0x5, 0xa6, 0x54, 0x2, 0x104, 0x109, 0x5, 0xaa, 0x56, 0x2, 0x105, 
       0x109, 0x5, 0xac, 0x57, 0x2, 0x106, 0x109, 0x5, 0x46, 0x24, 0x2, 
       0x107, 0x109, 0x5, 0x5a, 0x2e, 0x2, 0x108, 0x100, 0x3, 0x2, 0x2, 
       0x2, 0x108, 0x101, 0x3, 0x2, 0x2, 0x2, 0x108, 0x102, 0x3, 0x2, 0x2, 
       0x2, 0x108, 0x103, 0x3, 0x2, 0x2, 0x2, 0x108, 0x104, 0x3, 0x2, 0x2, 
       0x2, 0x108, 0x105, 0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 
       0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x11, 0x3, 0x2, 0x2, 
       0x2, 0x10a, 0x10b, 0x5, 0x20, 0x11, 0x2, 0x10b, 0x10c, 0x7, 0x66, 
       0x2, 0x2, 0x10c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x5, 0x3a, 
       0x1e, 0x2, 0x10e, 0x110, 0x5, 0x30, 0x19, 0x2, 0x10f, 0x10d, 0x3, 
       0x2, 0x2, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 
       0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x66, 0x2, 0x2, 0x112, 0x15, 0x3, 
       0x2, 0x2, 0x2, 0x113, 0x115, 0x7, 0x76, 0x2, 0x2, 0x114, 0x116, 0x5, 
       0x1c, 0xf, 0x2, 0x115, 0x114, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 
       0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x5, 
       0xa0, 0x51, 0x2, 0x118, 0x119, 0x5, 0x7a, 0x3e, 0x2, 0x119, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x11d, 0x5, 0x16, 0xc, 0x2, 0x11b, 0x11d, 
       0x5, 0x64, 0x33, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 
       0x7, 0x66, 0x2, 0x2, 0x11f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
       0x7, 0x6a, 0x2, 0x2, 0x121, 0x122, 0x5, 0x2c, 0x17, 0x2, 0x122, 0x1b, 
       0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x7, 0x5f, 0x2, 0x2, 0x124, 0x125, 
       0x5, 0x7a, 0x3e, 0x2, 0x125, 0x126, 0x7, 0x60, 0x2, 0x2, 0x126, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x7, 0x76, 0x2, 0x2, 0x128, 0x12a, 
       0x7, 0x68, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x76, 0x2, 0x2, 0x12f, 0x1f, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x7, 0x2, 0x2, 0x131, 0x133, 
       0x7, 0x76, 0x2, 0x2, 0x132, 0x134, 0x5, 0x1c, 0xf, 0x2, 0x133, 0x132, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 0x7, 0x8, 0x2, 0x2, 0x136, 0x138, 
       0x5, 0x1c, 0xf, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13b, 
       0x7, 0x76, 0x2, 0x2, 0x13a, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
       0x7, 0x7, 0x2, 0x2, 0x13d, 0x13f, 0x7, 0x76, 0x2, 0x2, 0x13e, 0x140, 
       0x5, 0x1c, 0xf, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x147, 0x3, 0x2, 0x2, 0x2, 0x141, 0x143, 
       0x7, 0x8, 0x2, 0x2, 0x142, 0x144, 0x5, 0x1c, 0xf, 0x2, 0x143, 0x142, 
       0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 
       0x3, 0x2, 0x2, 0x2, 0x145, 0x147, 0x7, 0x76, 0x2, 0x2, 0x146, 0x13c, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x141, 0x3, 0x2, 0x2, 0x2, 0x147, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x148, 0x14d, 0x5, 0x22, 0x12, 0x2, 0x149, 0x14a, 
       0x7, 0x68, 0x2, 0x2, 0x14a, 0x14c, 0x5, 0x22, 0x12, 0x2, 0x14b, 0x149, 
       0x3, 0x2, 0x2, 0x2, 0x14c, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 
       0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 
       0x9, 0x4, 0x2, 0x2, 0x151, 0x27, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
       0x9, 0x5, 0x2, 0x2, 0x153, 0x29, 0x3, 0x2, 0x2, 0x2, 0x154, 0x157, 
       0x7, 0xf, 0x2, 0x2, 0x155, 0x157, 0x5, 0xbc, 0x5f, 0x2, 0x156, 0x154, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x5, 0x28, 0x15, 0x2, 0x159, 0x15a, 
       0x5, 0x1c, 0xf, 0x2, 0x15a, 0x166, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x166, 
       0x5, 0x2a, 0x16, 0x2, 0x15c, 0x15e, 0x5, 0x26, 0x14, 0x2, 0x15d, 
       0x15f, 0x5, 0x1c, 0xf, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15e, 
       0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x166, 0x3, 0x2, 0x2, 0x2, 0x160, 
       0x161, 0x7, 0x10, 0x2, 0x2, 0x161, 0x162, 0x7, 0x5f, 0x2, 0x2, 0x162, 
       0x163, 0x5, 0x2e, 0x18, 0x2, 0x163, 0x164, 0x7, 0x60, 0x2, 0x2, 0x164, 
       0x166, 0x3, 0x2, 0x2, 0x2, 0x165, 0x158, 0x3, 0x2, 0x2, 0x2, 0x165, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x165, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x165, 
       0x160, 0x3, 0x2, 0x2, 0x2, 0x166, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x167, 
       0x168, 0x5, 0x28, 0x15, 0x2, 0x168, 0x169, 0x5, 0x1c, 0xf, 0x2, 0x169, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x11, 0x2, 0x2, 0x16b, 
       0x16c, 0x5, 0x2c, 0x17, 0x2, 0x16c, 0x16d, 0x7, 0x76, 0x2, 0x2, 0x16d, 
       0x16e, 0x5, 0x9e, 0x50, 0x2, 0x16e, 0x31, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x170, 0x5, 0x28, 0x15, 0x2, 0x170, 0x171, 0x5, 0x1c, 0xf, 0x2, 0x171, 
       0x173, 0x7, 0x76, 0x2, 0x2, 0x172, 0x174, 0x5, 0x9e, 0x50, 0x2, 0x173, 
       0x172, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x5, 0x2a, 0x16, 0x2, 0x176, 
       0x178, 0x7, 0x76, 0x2, 0x2, 0x177, 0x179, 0x5, 0x9e, 0x50, 0x2, 0x178, 
       0x177, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 0x2, 0x179, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0xa, 0x2, 0x2, 0x17b, 
       0x17d, 0x7, 0x76, 0x2, 0x2, 0x17c, 0x17e, 0x5, 0x1c, 0xf, 0x2, 0x17d, 
       0x17c, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 
       0x185, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x181, 0x7, 0x9, 0x2, 0x2, 0x180, 
       0x182, 0x5, 0x1c, 0xf, 0x2, 0x181, 0x180, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x182, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 
       0x185, 0x7, 0x76, 0x2, 0x2, 0x184, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x184, 
       0x17f, 0x3, 0x2, 0x2, 0x2, 0x185, 0x187, 0x3, 0x2, 0x2, 0x2, 0x186, 
       0x188, 0x5, 0x9e, 0x50, 0x2, 0x187, 0x186, 0x3, 0x2, 0x2, 0x2, 0x187, 
       0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x37, 0x3, 0x2, 0x2, 0x2, 0x189, 
       0x18a, 0x7, 0x10, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x5f, 0x2, 0x2, 0x18b, 
       0x18c, 0x5, 0x2e, 0x18, 0x2, 0x18c, 0x18d, 0x7, 0x60, 0x2, 0x2, 0x18d, 
       0x18f, 0x7, 0x76, 0x2, 0x2, 0x18e, 0x190, 0x5, 0x9e, 0x50, 0x2, 0x18f, 
       0x18e, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x191, 0x196, 0x5, 0x32, 0x1a, 0x2, 0x192, 
       0x196, 0x5, 0x34, 0x1b, 0x2, 0x193, 0x196, 0x5, 0x36, 0x1c, 0x2, 
       0x194, 0x196, 0x5, 0x38, 0x1d, 0x2, 0x195, 0x191, 0x3, 0x2, 0x2, 
       0x2, 0x195, 0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 0x2, 
       0x2, 0x195, 0x194, 0x3, 0x2, 0x2, 0x2, 0x196, 0x3b, 0x3, 0x2, 0x2, 
       0x2, 0x197, 0x198, 0x5, 0x2c, 0x17, 0x2, 0x198, 0x199, 0x7, 0x68, 
       0x2, 0x2, 0x199, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x197, 0x3, 0x2, 
       0x2, 0x2, 0x19b, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 
       0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19f, 0x3, 0x2, 
       0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x5, 0x2c, 
       0x17, 0x2, 0x1a0, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x5, 0x28, 
       0x15, 0x2, 0x1a2, 0x1a3, 0x5, 0x1c, 0xf, 0x2, 0x1a3, 0x1a6, 0x3, 
       0x2, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 0x2a, 0x16, 0x2, 0x1a5, 0x1a1, 
       0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x76, 0x2, 0x2, 0x1a8, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0xa, 0x2, 0x2, 0x1aa, 0x1ac, 
       0x7, 0x76, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0x1c, 0xf, 0x2, 0x1ac, 0x1ab, 
       0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b0, 0x7, 0x9, 0x2, 0x2, 0x1af, 0x1b1, 
       0x5, 0x1c, 0xf, 0x2, 0x1b0, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 
       0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1ba, 
       0x7, 0x76, 0x2, 0x2, 0x1b3, 0x1b4, 0x7, 0x10, 0x2, 0x2, 0x1b4, 0x1b5, 
       0x7, 0x5f, 0x2, 0x2, 0x1b5, 0x1b6, 0x5, 0x2e, 0x18, 0x2, 0x1b6, 0x1b7, 
       0x7, 0x60, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0x76, 0x2, 0x2, 0x1b8, 0x1ba, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1a9, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1b3, 
       0x3, 0x2, 0x2, 0x2, 0x1ba, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1c0, 
       0x5, 0x3e, 0x20, 0x2, 0x1bc, 0x1bd, 0x7, 0x68, 0x2, 0x2, 0x1bd, 0x1bf, 
       0x5, 0x3e, 0x20, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c2, 
       0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x1c1, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c0, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x5, 0x3e, 0x20, 0x2, 0x1c4, 0x1c6, 
       0x5, 0x22, 0x12, 0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c4, 
       0x3, 0x2, 0x2, 0x2, 0x1c6, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 
       0x5, 0x42, 0x22, 0x2, 0x1c8, 0x1c9, 0x7, 0x68, 0x2, 0x2, 0x1c9, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1ce, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cc, 
       0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x5, 0x42, 0x22, 0x2, 0x1d0, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x7, 0x12, 0x2, 0x2, 0x1d2, 0x1d3, 
       0x7, 0x76, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x69, 0x2, 0x2, 0x1d4, 0x1d5, 
       0x5, 0x48, 0x25, 0x2, 0x1d5, 0x1d6, 0x7, 0x66, 0x2, 0x2, 0x1d6, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x8, 0x25, 0x1, 0x2, 0x1d8, 0x1d9, 
       0x7, 0x76, 0x2, 0x2, 0x1d9, 0x1e2, 0x5, 0x4c, 0x27, 0x2, 0x1da, 0x1df, 
       0x7, 0x76, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x5f, 0x2, 0x2, 0x1dc, 0x1dd, 
       0x5, 0x9c, 0x4f, 0x2, 0x1dd, 0x1de, 0x7, 0x60, 0x2, 0x2, 0x1de, 0x1e0, 
       0x3, 0x2, 0x2, 0x2, 0x1df, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 
       0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1d7, 
       0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e8, 
       0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0xc, 0x3, 0x2, 0x2, 0x1e4, 0x1e5, 
       0x7, 0x13, 0x2, 0x2, 0x1e5, 0x1e7, 0x5, 0x48, 0x25, 0x4, 0x1e6, 0x1e3, 
       0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 
       0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x49, 
       0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1f0, 
       0x5, 0x48, 0x25, 0x2, 0x1ec, 0x1ed, 0x7, 0x68, 0x2, 0x2, 0x1ed, 0x1ef, 
       0x5, 0x48, 0x25, 0x2, 0x1ee, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f2, 
       0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 
       0x3, 0x2, 0x2, 0x2, 0x1f1, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f0, 
       0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x7, 0x5f, 0x2, 0x2, 0x1f4, 0x1f6, 
       0x5, 0x7a, 0x3e, 0x2, 0x1f5, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 
       0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f9, 
       0x7, 0x65, 0x2, 0x2, 0x1f8, 0x1fa, 0x5, 0x7a, 0x3e, 0x2, 0x1f9, 0x1f8, 
       0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fd, 
       0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x65, 0x2, 0x2, 0x1fc, 0x1fe, 
       0x5, 0x7a, 0x3e, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 
       0x7, 0x60, 0x2, 0x2, 0x200, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x201, 0x202, 
       0x7, 0x14, 0x2, 0x2, 0x202, 0x203, 0x5, 0x50, 0x29, 0x2, 0x203, 0x204, 
       0x5, 0x54, 0x2b, 0x2, 0x204, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x205, 0x20b, 
       0x5, 0x52, 0x2a, 0x2, 0x206, 0x208, 0x7, 0x63, 0x2, 0x2, 0x207, 0x209, 
       0x5, 0x1e, 0x10, 0x2, 0x208, 0x207, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 
       0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20c, 
       0x7, 0x64, 0x2, 0x2, 0x20b, 0x206, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 
       0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 
       0x5, 0x1e, 0x10, 0x2, 0x20e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x210, 
       0x9, 0x6, 0x2, 0x2, 0x210, 0x53, 0x3, 0x2, 0x2, 0x2, 0x211, 0x216, 
       0x7, 0x61, 0x2, 0x2, 0x212, 0x215, 0x5, 0x5a, 0x2e, 0x2, 0x213, 0x215, 
       0x5, 0x56, 0x2c, 0x2, 0x214, 0x212, 0x3, 0x2, 0x2, 0x2, 0x214, 0x213, 
       0x3, 0x2, 0x2, 0x2, 0x215, 0x218, 0x3, 0x2, 0x2, 0x2, 0x216, 0x214, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 0x2, 0x217, 0x219, 
       0x3, 0x2, 0x2, 0x2, 0x218, 0x216, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 
       0x7, 0x62, 0x2, 0x2, 0x21a, 0x55, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 
       0x5, 0xa8, 0x55, 0x2, 0x21c, 0x21d, 0x5, 0x58, 0x2d, 0x2, 0x21d, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x228, 0x5, 0x5a, 0x2e, 0x2, 0x21f, 
       0x223, 0x7, 0x61, 0x2, 0x2, 0x220, 0x222, 0x5, 0x5a, 0x2e, 0x2, 0x221, 
       0x220, 0x3, 0x2, 0x2, 0x2, 0x222, 0x225, 0x3, 0x2, 0x2, 0x2, 0x223, 
       0x221, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 
       0x226, 0x3, 0x2, 0x2, 0x2, 0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x226, 
       0x228, 0x7, 0x62, 0x2, 0x2, 0x227, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x227, 
       0x21f, 0x3, 0x2, 0x2, 0x2, 0x228, 0x59, 0x3, 0x2, 0x2, 0x2, 0x229, 
       0x22a, 0x5, 0x5c, 0x2f, 0x2, 0x22a, 0x22b, 0x7, 0x66, 0x2, 0x2, 0x22b, 
       0x22e, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22e, 0x5, 0xc6, 0x64, 0x2, 0x22d, 
       0x229, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22e, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x235, 0x5, 0x6e, 0x38, 0x2, 0x230, 
       0x235, 0x5, 0x5e, 0x30, 0x2, 0x231, 0x235, 0x5, 0x62, 0x32, 0x2, 
       0x232, 0x235, 0x5, 0x60, 0x31, 0x2, 0x233, 0x235, 0x5, 0x66, 0x34, 
       0x2, 0x234, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x234, 0x230, 0x3, 0x2, 0x2, 
       0x2, 0x234, 0x231, 0x3, 0x2, 0x2, 0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 
       0x2, 0x234, 0x233, 0x3, 0x2, 0x2, 0x2, 0x235, 0x5d, 0x3, 0x2, 0x2, 
       0x2, 0x236, 0x238, 0x5, 0x68, 0x35, 0x2, 0x237, 0x236, 0x3, 0x2, 
       0x2, 0x2, 0x238, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x239, 0x237, 0x3, 0x2, 
       0x2, 0x2, 0x239, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23c, 0x3, 0x2, 
       0x2, 0x2, 0x23b, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 0x7, 0x17, 
       0x2, 0x2, 0x23d, 0x23e, 0x7, 0x63, 0x2, 0x2, 0x23e, 0x23f, 0x5, 0x7a, 
       0x3e, 0x2, 0x23f, 0x241, 0x7, 0x64, 0x2, 0x2, 0x240, 0x242, 0x5, 
       0x4a, 0x26, 0x2, 0x241, 0x240, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x242, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 
       0x7, 0x18, 0x2, 0x2, 0x244, 0x245, 0x5, 0x4a, 0x26, 0x2, 0x245, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x7, 0x19, 0x2, 0x2, 0x247, 0x248, 
       0x5, 0x48, 0x25, 0x2, 0x248, 0x63, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24c, 
       0x5, 0x62, 0x32, 0x2, 0x24a, 0x24b, 0x7, 0x6a, 0x2, 0x2, 0x24b, 0x24d, 
       0x5, 0x48, 0x25, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 
       0x3, 0x2, 0x2, 0x2, 0x24d, 0x253, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 
       0x5, 0x48, 0x25, 0x2, 0x24f, 0x250, 0x7, 0x69, 0x2, 0x2, 0x250, 0x251, 
       0x5, 0x62, 0x32, 0x2, 0x251, 0x253, 0x3, 0x2, 0x2, 0x2, 0x252, 0x249, 
       0x3, 0x2, 0x2, 0x2, 0x252, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x253, 0x65, 
       0x3, 0x2, 0x2, 0x2, 0x254, 0x256, 0x7, 0x1a, 0x2, 0x2, 0x255, 0x257, 
       0x5, 0x4a, 0x26, 0x2, 0x256, 0x255, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 
       0x3, 0x2, 0x2, 0x2, 0x257, 0x67, 0x3, 0x2, 0x2, 0x2, 0x258, 0x25c, 
       0x7, 0x1b, 0x2, 0x2, 0x259, 0x25c, 0x5, 0x6a, 0x36, 0x2, 0x25a, 0x25c, 
       0x5, 0x6c, 0x37, 0x2, 0x25b, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x259, 
       0x3, 0x2, 0x2, 0x2, 0x25b, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 
       0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x7, 0x1c, 0x2, 0x2, 0x25e, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x7, 0x1d, 0x2, 0x2, 0x260, 0x261, 
       0x7, 0x63, 0x2, 0x2, 0x261, 0x262, 0x5, 0x7a, 0x3e, 0x2, 0x262, 0x263, 
       0x7, 0x64, 0x2, 0x2, 0x263, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x264, 0x269, 
       0x9, 0x7, 0x2, 0x2, 0x265, 0x266, 0x7, 0x63, 0x2, 0x2, 0x266, 0x267, 
       0x5, 0x7a, 0x3e, 0x2, 0x267, 0x268, 0x7, 0x64, 0x2, 0x2, 0x268, 0x26a, 
       0x3, 0x2, 0x2, 0x2, 0x269, 0x265, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 
       0x3, 0x2, 0x2, 0x2, 0x26a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26d, 
       0x5, 0x68, 0x35, 0x2, 0x26c, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x270, 
       0x3, 0x2, 0x2, 0x2, 0x26e, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x271, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26e, 
       0x3, 0x2, 0x2, 0x2, 0x271, 0x276, 0x5, 0x52, 0x2a, 0x2, 0x272, 0x273, 
       0x7, 0x63, 0x2, 0x2, 0x273, 0x274, 0x5, 0x9c, 0x4f, 0x2, 0x274, 0x275, 
       0x7, 0x64, 0x2, 0x2, 0x275, 0x277, 0x3, 0x2, 0x2, 0x2, 0x276, 0x272, 
       0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 
       0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x5, 0x4a, 0x26, 0x2, 0x279, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 0x9, 0x8, 0x2, 0x2, 0x27b, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x9, 0x9, 0x2, 0x2, 0x27d, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x9, 0xa, 0x2, 0x2, 0x27f, 0x75, 
       0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 0x9, 0xb, 0x2, 0x2, 0x281, 0x77, 
       0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x5, 0x7a, 0x3e, 0x2, 0x283, 0x284, 
       0x7, 0x66, 0x2, 0x2, 0x284, 0x79, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 
       0x8, 0x3e, 0x1, 0x2, 0x286, 0x28a, 0x5, 0x92, 0x4a, 0x2, 0x287, 0x28a, 
       0x5, 0x8e, 0x48, 0x2, 0x288, 0x28a, 0x5, 0x7c, 0x3f, 0x2, 0x289, 
       0x285, 0x3, 0x2, 0x2, 0x2, 0x289, 0x287, 0x3, 0x2, 0x2, 0x2, 0x289, 
       0x288, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x290, 0x3, 0x2, 0x2, 0x2, 0x28b, 
       0x28c, 0xc, 0x3, 0x2, 0x2, 0x28c, 0x28d, 0x7, 0x29, 0x2, 0x2, 0x28d, 
       0x28f, 0x5, 0x7c, 0x3f, 0x2, 0x28e, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28f, 
       0x292, 0x3, 0x2, 0x2, 0x2, 0x290, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x290, 
       0x291, 0x3, 0x2, 0x2, 0x2, 0x291, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x292, 
       0x290, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x8, 0x3f, 0x1, 0x2, 0x294, 
       0x295, 0x5, 0x7e, 0x40, 0x2, 0x295, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x296, 
       0x297, 0xc, 0x3, 0x2, 0x2, 0x297, 0x298, 0x7, 0x28, 0x2, 0x2, 0x298, 
       0x29a, 0x5, 0x7e, 0x40, 0x2, 0x299, 0x296, 0x3, 0x2, 0x2, 0x2, 0x29a, 
       0x29d, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 
       0x29c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x29d, 
       0x29b, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x8, 0x40, 0x1, 0x2, 0x29f, 
       0x2a0, 0x5, 0x80, 0x41, 0x2, 0x2a0, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a1, 
       0x2a2, 0xc, 0x3, 0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x2a, 0x2, 0x2, 0x2a3, 
       0x2a5, 0x5, 0x80, 0x41, 0x2, 0x2a4, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a5, 
       0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a6, 
       0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x2a8, 
       0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x8, 0x41, 0x1, 0x2, 0x2aa, 
       0x2ab, 0x5, 0x82, 0x42, 0x2, 0x2ab, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2ac, 
       0x2ad, 0xc, 0x3, 0x2, 0x2, 0x2ad, 0x2ae, 0x7, 0x2b, 0x2, 0x2, 0x2ae, 
       0x2b0, 0x5, 0x82, 0x42, 0x2, 0x2af, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
       0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b1, 
       0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x81, 0x3, 0x2, 0x2, 0x2, 0x2b3, 
       0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x8, 0x42, 0x1, 0x2, 0x2b5, 
       0x2b6, 0x5, 0x84, 0x43, 0x2, 0x2b6, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
       0x2b8, 0xc, 0x3, 0x2, 0x2, 0x2b8, 0x2b9, 0x7, 0x2c, 0x2, 0x2, 0x2b9, 
       0x2bb, 0x5, 0x84, 0x43, 0x2, 0x2ba, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2bb, 
       0x2be, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bc, 
       0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x83, 0x3, 0x2, 0x2, 0x2, 0x2be, 
       0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x8, 0x43, 0x1, 0x2, 0x2c0, 
       0x2c1, 0x5, 0x86, 0x44, 0x2, 0x2c1, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c2, 
       0x2c3, 0xc, 0x3, 0x2, 0x2, 0x2c3, 0x2c4, 0x5, 0x74, 0x3b, 0x2, 0x2c4, 
       0x2c5, 0x5, 0x86, 0x44, 0x2, 0x2c5, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c6, 
       0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
       0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 
       0x85, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2cb, 
       0x2cc, 0x8, 0x44, 0x1, 0x2, 0x2cc, 0x2cd, 0x5, 0x88, 0x45, 0x2, 0x2cd, 
       0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 0xc, 0x3, 0x2, 0x2, 0x2cf, 
       0x2d0, 0x5, 0x72, 0x3a, 0x2, 0x2d0, 0x2d1, 0x5, 0x88, 0x45, 0x2, 
       0x2d1, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2ce, 0x3, 0x2, 0x2, 0x2, 
       0x2d3, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d2, 0x3, 0x2, 0x2, 0x2, 
       0x2d4, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x87, 0x3, 0x2, 0x2, 0x2, 
       0x2d6, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x8, 0x45, 0x1, 0x2, 
       0x2d8, 0x2d9, 0x5, 0x8a, 0x46, 0x2, 0x2d9, 0x2df, 0x3, 0x2, 0x2, 
       0x2, 0x2da, 0x2db, 0xc, 0x3, 0x2, 0x2, 0x2db, 0x2dc, 0x9, 0xc, 0x2, 
       0x2, 0x2dc, 0x2de, 0x5, 0x8a, 0x46, 0x2, 0x2dd, 0x2da, 0x3, 0x2, 
       0x2, 0x2, 0x2de, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2dd, 0x3, 0x2, 
       0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x89, 0x3, 0x2, 
       0x2, 0x2, 0x2e1, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e3, 0x8, 0x46, 
       0x1, 0x2, 0x2e3, 0x2e4, 0x5, 0x8c, 0x47, 0x2, 0x2e4, 0x2ea, 0x3, 
       0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0xc, 0x3, 0x2, 0x2, 0x2e6, 0x2e7, 0x9, 
       0xd, 0x2, 0x2, 0x2e7, 0x2e9, 0x5, 0x8c, 0x47, 0x2, 0x2e8, 0x2e5, 
       0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2e8, 
       0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ee, 
       0x8, 0x47, 0x1, 0x2, 0x2ee, 0x2f1, 0x5, 0x90, 0x49, 0x2, 0x2ef, 0x2f1, 
       0x5, 0x8e, 0x48, 0x2, 0x2f0, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2ef, 
       0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 
       0xc, 0x3, 0x2, 0x2, 0x2f3, 0x2f6, 0x9, 0xe, 0x2, 0x2, 0x2f4, 0x2f7, 
       0x5, 0x90, 0x49, 0x2, 0x2f5, 0x2f7, 0x5, 0x8e, 0x48, 0x2, 0x2f6, 
       0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f7, 
       0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f9, 
       0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2fa, 
       0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fb, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x2fc, 
       0x2fa, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2fe, 0x5, 0x70, 0x39, 0x2, 0x2fe, 
       0x2ff, 0x5, 0x90, 0x49, 0x2, 0x2ff, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x300, 
       0x306, 0x5, 0x92, 0x4a, 0x2, 0x301, 0x302, 0x5, 0x92, 0x4a, 0x2, 
       0x302, 0x303, 0x7, 0x2f, 0x2, 0x2, 0x303, 0x304, 0x5, 0x90, 0x49, 
       0x2, 0x304, 0x306, 0x3, 0x2, 0x2, 0x2, 0x305, 0x300, 0x3, 0x2, 0x2, 
       0x2, 0x305, 0x301, 0x3, 0x2, 0x2, 0x2, 0x306, 0x91, 0x3, 0x2, 0x2, 
       0x2, 0x307, 0x308, 0x8, 0x4a, 0x1, 0x2, 0x308, 0x317, 0x7, 0x72, 
       0x2, 0x2, 0x309, 0x317, 0x7, 0x75, 0x2, 0x2, 0x30a, 0x317, 0x7, 0x77, 
       0x2, 0x2, 0x30b, 0x317, 0x7, 0x71, 0x2, 0x2, 0x30c, 0x317, 0x5, 0x94, 
       0x4b, 0x2, 0x30d, 0x317, 0x7, 0x76, 0x2, 0x2, 0x30e, 0x317, 0x7, 
       0x79, 0x2, 0x2, 0x30f, 0x317, 0x5, 0x96, 0x4c, 0x2, 0x310, 0x317, 
       0x5, 0xb4, 0x5b, 0x2, 0x311, 0x317, 0x5, 0xc0, 0x61, 0x2, 0x312, 
       0x313, 0x7, 0x63, 0x2, 0x2, 0x313, 0x314, 0x5, 0x7a, 0x3e, 0x2, 0x314, 
       0x315, 0x7, 0x64, 0x2, 0x2, 0x315, 0x317, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x307, 0x3, 0x2, 0x2, 0x2, 0x316, 0x309, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x30a, 0x3, 0x2, 0x2, 0x2, 0x316, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x30c, 0x3, 0x2, 0x2, 0x2, 0x316, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x30e, 0x3, 0x2, 0x2, 0x2, 0x316, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x310, 0x3, 0x2, 0x2, 0x2, 0x316, 0x311, 0x3, 0x2, 0x2, 0x2, 0x316, 
       0x312, 0x3, 0x2, 0x2, 0x2, 0x317, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x318, 
       0x319, 0xc, 0x3, 0x2, 0x2, 0x319, 0x31a, 0x7, 0x5f, 0x2, 0x2, 0x31a, 
       0x31b, 0x5, 0x7a, 0x3e, 0x2, 0x31b, 0x31c, 0x7, 0x60, 0x2, 0x2, 0x31c, 
       0x31e, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31e, 
       0x321, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31f, 
       0x320, 0x3, 0x2, 0x2, 0x2, 0x320, 0x93, 0x3, 0x2, 0x2, 0x2, 0x321, 
       0x31f, 0x3, 0x2, 0x2, 0x2, 0x322, 0x323, 0x9, 0xf, 0x2, 0x2, 0x323, 
       0x95, 0x3, 0x2, 0x2, 0x2, 0x324, 0x327, 0x5, 0x98, 0x4d, 0x2, 0x325, 
       0x327, 0x5, 0x9a, 0x4e, 0x2, 0x326, 0x324, 0x3, 0x2, 0x2, 0x2, 0x326, 
       0x325, 0x3, 0x2, 0x2, 0x2, 0x327, 0x328, 0x3, 0x2, 0x2, 0x2, 0x328, 
       0x329, 0x7, 0x63, 0x2, 0x2, 0x329, 0x32a, 0x5, 0x9c, 0x4f, 0x2, 0x32a, 
       0x32b, 0x7, 0x64, 0x2, 0x2, 0x32b, 0x97, 0x3, 0x2, 0x2, 0x2, 0x32c, 
       0x32d, 0x9, 0x10, 0x2, 0x2, 0x32d, 0x99, 0x3, 0x2, 0x2, 0x2, 0x32e, 
       0x32f, 0x5, 0x2c, 0x17, 0x2, 0x32f, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x330, 
       0x335, 0x5, 0x7a, 0x3e, 0x2, 0x331, 0x332, 0x7, 0x68, 0x2, 0x2, 0x332, 
       0x334, 0x5, 0x7a, 0x3e, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x334, 
       0x337, 0x3, 0x2, 0x2, 0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 
       0x336, 0x3, 0x2, 0x2, 0x2, 0x336, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x337, 
       0x335, 0x3, 0x2, 0x2, 0x2, 0x338, 0x339, 0x7, 0x69, 0x2, 0x2, 0x339, 
       0x33a, 0x5, 0x7a, 0x3e, 0x2, 0x33a, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x33b, 
       0x33c, 0x9, 0x11, 0x2, 0x2, 0x33c, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x33d, 
       0x33e, 0x7, 0x61, 0x2, 0x2, 0x33e, 0x33f, 0x5, 0x9c, 0x4f, 0x2, 0x33f, 
       0x340, 0x7, 0x62, 0x2, 0x2, 0x340, 0x344, 0x3, 0x2, 0x2, 0x2, 0x341, 
       0x344, 0x5, 0x4c, 0x27, 0x2, 0x342, 0x344, 0x7, 0x76, 0x2, 0x2, 0x343, 
       0x33d, 0x3, 0x2, 0x2, 0x2, 0x343, 0x341, 0x3, 0x2, 0x2, 0x2, 0x343, 
       0x342, 0x3, 0x2, 0x2, 0x2, 0x344, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x345, 
       0x351, 0x5, 0x10, 0x9, 0x2, 0x346, 0x351, 0x5, 0xb0, 0x59, 0x2, 0x347, 
       0x34c, 0x7, 0x61, 0x2, 0x2, 0x348, 0x34b, 0x5, 0x10, 0x9, 0x2, 0x349, 
       0x34b, 0x5, 0xb0, 0x59, 0x2, 0x34a, 0x348, 0x3, 0x2, 0x2, 0x2, 0x34a, 
       0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x34c, 
       0x34a, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34d, 
       0x34f, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34f, 
       0x351, 0x7, 0x62, 0x2, 0x2, 0x350, 0x345, 0x3, 0x2, 0x2, 0x2, 0x350, 
       0x346, 0x3, 0x2, 0x2, 0x2, 0x350, 0x347, 0x3, 0x2, 0x2, 0x2, 0x351, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0x352, 0x353, 0x7, 0x4a, 0x2, 0x2, 0x353, 
       0x354, 0x7, 0x63, 0x2, 0x2, 0x354, 0x355, 0x5, 0x7a, 0x3e, 0x2, 0x355, 
       0x356, 0x7, 0x64, 0x2, 0x2, 0x356, 0x359, 0x5, 0xa4, 0x53, 0x2, 0x357, 
       0x358, 0x7, 0x4b, 0x2, 0x2, 0x358, 0x35a, 0x5, 0xa4, 0x53, 0x2, 0x359, 
       0x357, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 
       0xa7, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35c, 0x7, 0x4c, 0x2, 0x2, 0x35c, 
       0x35d, 0x7, 0x76, 0x2, 0x2, 0x35d, 0x35e, 0x7, 0x4d, 0x2, 0x2, 0x35e, 
       0x365, 0x5, 0xa2, 0x52, 0x2, 0x35f, 0x360, 0x7, 0x4e, 0x2, 0x2, 0x360, 
       0x361, 0x7, 0x63, 0x2, 0x2, 0x361, 0x362, 0x5, 0x7a, 0x3e, 0x2, 0x362, 
       0x363, 0x7, 0x64, 0x2, 0x2, 0x363, 0x365, 0x3, 0x2, 0x2, 0x2, 0x364, 
       0x35b, 0x3, 0x2, 0x2, 0x2, 0x364, 0x35f, 0x3, 0x2, 0x2, 0x2, 0x365, 
       0xa9, 0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x5, 0xa8, 0x55, 0x2, 0x367, 
       0x368, 0x5, 0xa4, 0x53, 0x2, 0x368, 0xab, 0x3, 0x2, 0x2, 0x2, 0x369, 
       0x36a, 0x7, 0x4f, 0x2, 0x2, 0x36a, 0x36b, 0x7, 0x66, 0x2, 0x2, 0x36b, 
       0xad, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36f, 0x7, 0x50, 0x2, 0x2, 0x36d, 
       0x370, 0x5, 0x7a, 0x3e, 0x2, 0x36e, 0x370, 0x5, 0x62, 0x32, 0x2, 
       0x36f, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x36e, 0x3, 0x2, 0x2, 0x2, 
       0x36f, 0x370, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x3, 0x2, 0x2, 0x2, 
       0x371, 0x372, 0x7, 0x66, 0x2, 0x2, 0x372, 0xaf, 0x3, 0x2, 0x2, 0x2, 
       0x373, 0x374, 0x9, 0x12, 0x2, 0x2, 0x374, 0x378, 0x7, 0x66, 0x2, 
       0x2, 0x375, 0x378, 0x5, 0xac, 0x57, 0x2, 0x376, 0x378, 0x5, 0xae, 
       0x58, 0x2, 0x377, 0x373, 0x3, 0x2, 0x2, 0x2, 0x377, 0x375, 0x3, 0x2, 
       0x2, 0x2, 0x377, 0x376, 0x3, 0x2, 0x2, 0x2, 0x378, 0xb1, 0x3, 0x2, 
       0x2, 0x2, 0x379, 0x37a, 0x7, 0x53, 0x2, 0x2, 0x37a, 0x37b, 0x7, 0x76, 
       0x2, 0x2, 0x37b, 0x37d, 0x7, 0x63, 0x2, 0x2, 0x37c, 0x37e, 0x5, 0x3c, 
       0x1f, 0x2, 0x37d, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 0x3, 0x2, 
       0x2, 0x2, 0x37e, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x381, 0x7, 0x64, 
       0x2, 0x2, 0x380, 0x382, 0x5, 0x1a, 0xe, 0x2, 0x381, 0x380, 0x3, 0x2, 
       0x2, 0x2, 0x381, 0x382, 0x3, 0x2, 0x2, 0x2, 0x382, 0x383, 0x3, 0x2, 
       0x2, 0x2, 0x383, 0x384, 0x7, 0x66, 0x2, 0x2, 0x384, 0xb3, 0x3, 0x2, 
       0x2, 0x2, 0x385, 0x386, 0x7, 0x76, 0x2, 0x2, 0x386, 0x388, 0x7, 0x63, 
       0x2, 0x2, 0x387, 0x389, 0x5, 0x9c, 0x4f, 0x2, 0x388, 0x387, 0x3, 
       0x2, 0x2, 0x2, 0x388, 0x389, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0x3, 
       0x2, 0x2, 0x2, 0x38a, 0x38b, 0x7, 0x64, 0x2, 0x2, 0x38b, 0xb5, 0x3, 
       0x2, 0x2, 0x2, 0x38c, 0x38d, 0x7, 0x54, 0x2, 0x2, 0x38d, 0x38e, 0x7, 
       0x76, 0x2, 0x2, 0x38e, 0x390, 0x7, 0x63, 0x2, 0x2, 0x38f, 0x391, 
       0x5, 0x44, 0x23, 0x2, 0x390, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x390, 0x391, 
       0x3, 0x2, 0x2, 0x2, 0x391, 0x392, 0x3, 0x2, 0x2, 0x2, 0x392, 0x394, 
       0x7, 0x64, 0x2, 0x2, 0x393, 0x395, 0x5, 0x1a, 0xe, 0x2, 0x394, 0x393, 
       0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 0x3, 0x2, 0x2, 0x2, 0x395, 0x396, 
       0x3, 0x2, 0x2, 0x2, 0x396, 0x397, 0x5, 0xb8, 0x5d, 0x2, 0x397, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0x398, 0x39c, 0x7, 0x61, 0x2, 0x2, 0x399, 0x39b, 
       0x5, 0x10, 0x9, 0x2, 0x39a, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39e, 
       0x3, 0x2, 0x2, 0x2, 0x39c, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39d, 
       0x3, 0x2, 0x2, 0x2, 0x39d, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39c, 
       0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a1, 0x5, 0xae, 0x58, 0x2, 0x3a0, 0x39f, 
       0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 
       0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a3, 0x7, 0x62, 0x2, 0x2, 0x3a3, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a5, 0x7, 0x55, 0x2, 0x2, 0x3a5, 0x3a9, 
       0x7, 0x61, 0x2, 0x2, 0x3a6, 0x3a8, 0x5, 0x10, 0x9, 0x2, 0x3a7, 0x3a6, 
       0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3a7, 
       0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ac, 
       0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 
       0x7, 0x62, 0x2, 0x2, 0x3ad, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3af, 
       0x9, 0x13, 0x2, 0x2, 0x3af, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b2, 
       0x7, 0x58, 0x2, 0x2, 0x3b1, 0x3b3, 0x5, 0x1c, 0xf, 0x2, 0x3b2, 0x3b1, 
       0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b4, 
       0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b5, 0x5, 0x54, 0x2b, 0x2, 0x3b5, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3bf, 0x7, 0x78, 0x2, 0x2, 0x3b7, 0x3b8, 
       0x7, 0x59, 0x2, 0x2, 0x3b8, 0x3bb, 0x7, 0x63, 0x2, 0x2, 0x3b9, 0x3bc, 
       0x7, 0x76, 0x2, 0x2, 0x3ba, 0x3bc, 0x5, 0x54, 0x2b, 0x2, 0x3bb, 0x3b9, 
       0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bd, 
       0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3bf, 0x7, 0x64, 0x2, 0x2, 0x3be, 0x3b6, 
       0x3, 0x2, 0x2, 0x2, 0x3be, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0xc1, 
       0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3c1, 0x9, 0x14, 0x2, 0x2, 0x3c1, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c8, 0x5, 0xc2, 0x62, 0x2, 0x3c3, 0x3c5, 
       0x7, 0x63, 0x2, 0x2, 0x3c4, 0x3c6, 0x5, 0x9c, 0x4f, 0x2, 0x3c5, 0x3c4, 
       0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 
       0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c9, 0x7, 0x64, 0x2, 0x2, 0x3c8, 0x3c3, 
       0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3ca, 
       0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cb, 0x5, 0x1c, 0xf, 0x2, 0x3cb, 0x3cc, 
       0x5, 0x4a, 0x26, 0x2, 0x3cc, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3ce, 
       0x5, 0xc4, 0x63, 0x2, 0x3ce, 0x3cf, 0x7, 0x66, 0x2, 0x2, 0x3cf, 0x3d2, 
       0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d2, 0x5, 0xbe, 0x60, 0x2, 0x3d1, 0x3cd, 
       0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0xc7, 
       0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d6, 0x5, 0xca, 0x66, 0x2, 0x3d4, 0x3d6, 
       0x5, 0xcc, 0x67, 0x2, 0x3d5, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d4, 
       0x3, 0x2, 0x2, 0x2, 0x3d6, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d8, 
       0x7, 0x5c, 0x2, 0x2, 0x3d8, 0x3d9, 0x5, 0xce, 0x68, 0x2, 0x3d9, 0x3da, 
       0x7, 0x66, 0x2, 0x2, 0x3da, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 
       0x7, 0x5d, 0x2, 0x2, 0x3dc, 0x3e2, 0x7, 0x76, 0x2, 0x2, 0x3dd, 0x3df, 
       0x7, 0x63, 0x2, 0x2, 0x3de, 0x3e0, 0x5, 0xd0, 0x69, 0x2, 0x3df, 0x3de, 
       0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 
       0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e3, 0x7, 0x64, 0x2, 0x2, 0x3e2, 0x3dd, 
       0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e4, 
       0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e6, 0x5, 0x1e, 0x10, 0x2, 0x3e5, 0x3e7, 
       0x5, 0x1a, 0xe, 0x2, 0x3e6, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 
       0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3ec, 
       0x7, 0x61, 0x2, 0x2, 0x3e9, 0x3eb, 0xb, 0x2, 0x2, 0x2, 0x3ea, 0x3e9, 
       0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 
       0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ef, 
       0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f0, 
       0x7, 0x62, 0x2, 0x2, 0x3f0, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3f2, 
       0x9, 0x15, 0x2, 0x2, 0x3f2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f6, 
       0x5, 0x40, 0x21, 0x2, 0x3f4, 0x3f6, 0x5, 0x9c, 0x4f, 0x2, 0x3f5, 
       0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f6, 
       0xd1, 0x3, 0x2, 0x2, 0x2, 0x6d, 0xd5, 0xd7, 0xdb, 0xe0, 0xe6, 0xfe, 
       0x108, 0x10f, 0x115, 0x11c, 0x12b, 0x133, 0x137, 0x13a, 0x13f, 0x143, 
       0x146, 0x14d, 0x156, 0x15e, 0x165, 0x173, 0x178, 0x17d, 0x181, 0x184, 
       0x187, 0x18f, 0x195, 0x19c, 0x1a5, 0x1ac, 0x1b0, 0x1b9, 0x1c0, 0x1c5, 
       0x1cc, 0x1df, 0x1e1, 0x1e8, 0x1f0, 0x1f5, 0x1f9, 0x1fd, 0x208, 0x20b, 
       0x214, 0x216, 0x223, 0x227, 0x22d, 0x234, 0x239, 0x241, 0x24c, 0x252, 
       0x256, 0x25b, 0x269, 0x26e, 0x276, 0x289, 0x290, 0x29b, 0x2a6, 0x2b1, 
       0x2bc, 0x2c8, 0x2d4, 0x2df, 0x2ea, 0x2f0, 0x2f6, 0x2fa, 0x305, 0x316, 
       0x31f, 0x326, 0x335, 0x343, 0x34a, 0x34c, 0x350, 0x359, 0x364, 0x36f, 
       0x377, 0x37d, 0x381, 0x388, 0x390, 0x394, 0x39c, 0x3a0, 0x3a9, 0x3b2, 
       0x3bb, 0x3be, 0x3c5, 0x3c8, 0x3d1, 0x3d5, 0x3df, 0x3e2, 0x3e6, 0x3ec, 
       0x3f5, 
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
