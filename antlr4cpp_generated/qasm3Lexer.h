
// Generated from qasm3Lexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  qasm3Lexer : public antlr4::Lexer {
public:
  enum {
    OPENQASM = 1, INCLUDE = 2, DEFCALGRAMMAR = 3, DEF = 4, CAL = 5, DEFCAL = 6, 
    GATE = 7, EXTERN = 8, BOX = 9, LET = 10, BREAK = 11, CONTINUE = 12, 
    IF = 13, ELSE = 14, END = 15, RETURN = 16, FOR = 17, WHILE = 18, IN = 19, 
    PRAGMA = 20, AnnotationKeyword = 21, INPUT = 22, OUTPUT = 23, CONST = 24, 
    READONLY = 25, MUTABLE = 26, QREG = 27, QUBIT = 28, CREG = 29, BOOL = 30, 
    BIT = 31, INT = 32, UINT = 33, FLOAT = 34, ANGLE = 35, COMPLEX = 36, 
    ARRAY = 37, DURATION = 38, STRETCH = 39, GPHASE = 40, INV = 41, POW = 42, 
    CTRL = 43, NEGCTRL = 44, DIM = 45, DURATIONOF = 46, DELAY = 47, RESET = 48, 
    MEASURE = 49, BARRIER = 50, BooleanLiteral = 51, LBRACKET = 52, RBRACKET = 53, 
    LBRACE = 54, RBRACE = 55, LPAREN = 56, RPAREN = 57, COLON = 58, SEMICOLON = 59, 
    DOT = 60, COMMA = 61, EQUALS = 62, ARROW = 63, PLUS = 64, DOUBLE_PLUS = 65, 
    MINUS = 66, ASTERISK = 67, DOUBLE_ASTERISK = 68, SLASH = 69, PERCENT = 70, 
    PIPE = 71, DOUBLE_PIPE = 72, AMPERSAND = 73, DOUBLE_AMPERSAND = 74, 
    CARET = 75, AT = 76, TILDE = 77, EXCLAMATION_POINT = 78, EqualityOperator = 79, 
    CompoundAssignmentOperator = 80, ComparisonOperator = 81, BitshiftOperator = 82, 
    IMAG = 83, ImaginaryLiteral = 84, BinaryIntegerLiteral = 85, OctalIntegerLiteral = 86, 
    DecimalIntegerLiteral = 87, HexIntegerLiteral = 88, Identifier = 89, 
    HardwareQubit = 90, FloatLiteral = 91, TimingLiteral = 92, BitstringLiteral = 93, 
    StringLiteral = 94, Whitespace = 95, Newline = 96, LineComment = 97, 
    BlockComment = 98, VERSION_IDENTIFER_WHITESPACE = 99, VersionSpecifier = 100, 
    EAT_INITIAL_SPACE = 101, EAT_LINE_END = 102, RemainingLineContent = 103, 
    CAL_PRELUDE_WHITESPACE = 104, CAL_PRELUDE_COMMENT = 105, DEFCAL_PRELUDE_WHITESPACE = 106, 
    DEFCAL_PRELUDE_COMMENT = 107, CalibrationBlock = 108
  };

  enum {
    VERSION_IDENTIFIER = 1, EAT_TO_LINE_END = 2, CAL_PRELUDE = 3, DEFCAL_PRELUDE = 4, 
    CAL_BLOCK = 5
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

