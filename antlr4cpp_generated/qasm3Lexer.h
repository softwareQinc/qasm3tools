
// Generated from qasm3Lexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  qasm3Lexer : public antlr4::Lexer {
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

  explicit qasm3Lexer(antlr4::CharStream *input);
  ~qasm3Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

