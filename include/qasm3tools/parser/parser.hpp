/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2025 softwareQ Inc. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file qasm3tools/parser/parser.hpp
 */

#ifndef QASM3TOOLS_PARSER_PARSER_HPP_
#define QASM3TOOLS_PARSER_PARSER_HPP_

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <tuple>

#include "../ast/ast.hpp"
#include "../ast/semantic.hpp"
#include "antlr4-runtime.h"
#include "position.hpp"
#include "qasm3LexerImpl.hpp"
#include "qasm3ParserImpl.hpp"
#include "qasm3ParserVisitor.h"

namespace qasm3tools {
namespace parser {

/**
 * \brief OpenQASM 3.0 standard library (stdgates.inc) as a string constant
 */
static const std::string std_include =
    "gate p(λ) a { ctrl @ gphase(λ) a; }\n"
    "gate x a { U(π, 0, π) a; }\n"
    "gate y a { U(π, π/2, π/2) a; }\n"
    "gate z a { p(π) a; }\n"
    "gate h a { U(π/2, 0, π) a; }\n"
    "gate s a { pow(1/2) @ z a; }\n"
    "gate sdg a { inv @ pow(1/2) @ z a; }\n"
    "gate t a { pow(1/2) @ s a; }\n"
    "gate tdg a { inv @ pow(1/2) @ s a; }\n"
    "gate sx a { pow(1/2) @ x a; }\n"
    "gate rx(θ) a { U(θ, -π/2, π/2) a; }\n"
    "gate ry(θ) a { U(θ, 0, 0) a; }\n"
    "gate rz(λ) a { gphase(-λ/2); U(0, 0, λ) a; }\n"
    "gate cx a, b { ctrl @ x a, b; }\n"
    "gate cy a, b { ctrl @ y a, b; }\n"
    "gate cz a, b { ctrl @ z a, b; }\n"
    "gate cp(λ) a, b { ctrl @ p(λ) a, b; }\n"
    "gate crx(θ) a, b { ctrl @ rx(θ) a, b; }\n"
    "gate cry(θ) a, b { ctrl @ ry(θ) a, b; }\n"
    "gate crz(θ) a, b { ctrl @ rz(θ) a, b; }\n"
    "gate ch a, b { ctrl @ h a, b; }\n"
    "gate swap a, b { cx a, b; cx b, a; cx a, b; }\n"
    "gate ccx a, b, c { ctrl @ ctrl @ x a, b, c; }\n"
    "gate cswap a, b, c { ctrl @ swap a, b, c; }\n"
    "gate cu(θ, φ, λ, γ) a, b { p(γ) a; ctrl @ U(θ, φ, λ) a, b; }\n"
    "gate CX a, b { ctrl @ U(π, 0, π) a, b; }\n"
    "gate phase(λ) q { U(0, 0, λ) q; }\n"
    "gate cphase(λ) a, b { ctrl @ phase(λ) a, b; }\n"
    "gate id a { U(0, 0, 0) a; }\n"
    "gate u1(λ) q { U(0, 0, λ) q; }\n"
    "gate u2(φ, λ) q { gphase(-(φ+λ)/2); U(π/2, φ, λ) q; }\n"
    "gate u3(θ, φ, λ) q { gphase(-(φ+λ)/2); U(θ, φ, λ) q; }\n";

// forward declarations
ast::ptr<ast::Program> parse_file_helper(std::string);
ast::ptr<ast::Program> parse_string_helper(const std::string&, std::string);

class ASTConstructor : public qasm3ParserVisitor {
    using ExprTriplet = std::tuple<std::optional<ast::ptr<ast::Expr>>,
                                   std::optional<ast::ptr<ast::Expr>>,
                                   std::optional<ast::ptr<ast::Expr>>>;

    const std::vector<std::string> units{"dt", "ns", "us", "µs", "ms", "s"};
    const std::vector<ast::TimeUnit> timeunits{
        ast::TimeUnit::dt,  ast::TimeUnit::ns, ast::TimeUnit::us,
        ast::TimeUnit::mus, ast::TimeUnit::ms, ast::TimeUnit::s};

    const std::unordered_map<std::string, ast::MathOp> call_map{
        {"arccos", ast::MathOp::Arccos}, {"arcsin", ast::MathOp::Arcsin},
        {"arctan", ast::MathOp::Arctan}, {"ceiling", ast::MathOp::Ceiling},
        {"cos", ast::MathOp::Cos},       {"exp", ast::MathOp::Exp},
        {"floor", ast::MathOp::Floor},   {"log", ast::MathOp::Log},
        {"mod", ast::MathOp::Mod},       {"popcount", ast::MathOp::Popcount},
        {"pow", ast::MathOp::Pow},       {"rotl", ast::MathOp::Rotl},
        {"rotr", ast::MathOp::Rotr},     {"sin", ast::MathOp::Sin},
        {"sqrt", ast::MathOp::Sqrt},     {"tan", ast::MathOp::Tan},
        {"real", ast::MathOp::Real},     {"imag", ast::MathOp::Imag}};

  public:
    // program: version? statement* EOF;
    virtual antlrcpp::Any
    visitProgram(qasm3Parser::ProgramContext* ctx) override {
        auto prog = ast::Program::create(
            get_pos(ctx), {}, get_source_name(ctx) == "stdgates.inc");
        for (auto stmt : ctx->statement()) {
            auto a = stmt->accept(this);
            if (a.is<ast::ptr<ast::Stmt>>()) {
                prog->body().emplace_back(
                    std::move(a.as<ast::ptr<ast::Stmt>>()));
            } else if (a.is<ast::ptr<ast::Program>>()) {
                prog->extend(*(a.as<ast::ptr<ast::Program>>()));
            }
        }
        return prog;
    }

    // version: OPENQASM VersionSpecifier SEMICOLON;
    virtual antlrcpp::Any
    visitVersion(qasm3Parser::VersionContext* ctx) override {
        return defaultResult(); // ignored
    }

    // statement:
    //    pragma
    //    | annotation* (
    //        aliasDeclarationStatement
    //        | assignmentStatement
    //        | ...
    //        | whileStatement
    //    )
    virtual antlrcpp::Any
    visitStatement(qasm3Parser::StatementContext* ctx) override {
        if (ctx->pragma()) {
            return ctx->pragma()->accept(this);
        } else if (ctx->includeStatement()) {
            if (!ctx->annotation().empty()) {
                std::cerr << get_pos(ctx->annotation(0))
                          << ": error: unexpected annotation(s)\n";
                throw std::logic_error("Parsing error!");
            }
            return ctx->includeStatement()->accept(this);
        }
        auto stmt = std::move(
            ctx->children.back()->accept(this).as<ast::ptr<ast::Stmt>>());
        for (auto x : ctx->annotation()) {
            stmt->annotations().emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Annotation>>()));
        }
        return stmt;
    }

    // annotation: AnnotationKeyword RemainingLineContent?;
    virtual antlrcpp::Any
    visitAnnotation(qasm3Parser::AnnotationContext* ctx) override {
        if (ctx->RemainingLineContent()) {
            return ast::Annotation::create(
                get_pos(ctx), ctx->AnnotationKeyword()->getText(),
                ctx->RemainingLineContent()->getText());
        }
        return ast::Annotation::create(get_pos(ctx),
                                       ctx->AnnotationKeyword()->getText());
    }

    // scope: LBRACE statement* RBRACE;
    virtual antlrcpp::Any visitScope(qasm3Parser::ScopeContext* ctx) override {
        std::list<ast::ptr<ast::Stmt>> body;
        for (auto stmt : ctx->statement()) {
            if (stmt->includeStatement()) {
                std::cerr << get_pos(ctx)
                          << ": error: unexpected include statement\n";
                throw std::logic_error("Parsing error!");
            }
            auto a = stmt->accept(this);
            body.emplace_back(std::move(a.as<ast::ptr<ast::Stmt>>()));
        }
        return ast::ProgramBlock::create(get_pos(ctx), std::move(body));
    }

    // pragma: PRAGMA RemainingLineContent;
    virtual antlrcpp::Any
    visitPragma(qasm3Parser::PragmaContext* ctx) override {
        return ast::ptr<ast::Stmt>(new ast::PragmaStmt(
            get_pos(ctx), ctx->RemainingLineContent()->getText()));
    }

    // statementOrScope: statement | scope;
    virtual antlrcpp::Any
    visitStatementOrScope(qasm3Parser::StatementOrScopeContext* ctx) override {
        if (ctx->statement()) {
            if (ctx->statement()->includeStatement()) {
                std::cerr << get_pos(ctx)
                          << ": error: unexpected include statement\n";
                throw std::logic_error("Parsing error!");
            }
            std::list<ast::ptr<ast::Stmt>> body;
            auto a = ctx->statement()->accept(this);
            body.emplace_back(std::move(a.as<ast::ptr<ast::Stmt>>()));
            return ast::ProgramBlock::create(get_pos(ctx), std::move(body));
        }
        return ctx->scope()->accept(this);
    }

    // calibrationGrammarStatement: DEFCALGRAMMAR StringLiteral SEMICOLON;
    virtual antlrcpp::Any visitCalibrationGrammarStatement(
        qasm3Parser::CalibrationGrammarStatementContext* ctx) override {
        std::cerr << get_pos(ctx)
                  << ": error: calibration grammars are not supported\n";
        throw std::logic_error("Parsing error!");
    }

    // includeStatement: INCLUDE StringLiteral SEMICOLON;
    virtual antlrcpp::Any
    visitIncludeStatement(qasm3Parser::IncludeStatementContext* ctx) override {
        std::string inc_str = ctx->StringLiteral()->getText();
        std::string fname = inc_str.substr(1, inc_str.length() - 2);
        if (fname == "stdgates.inc") {
            return parse_string_helper(std_include, fname);
        } else {
            return parse_file_helper(fname);
        }
    }

    // breakStatement: BREAK SEMICOLON;
    virtual antlrcpp::Any
    visitBreakStatement(qasm3Parser::BreakStatementContext* ctx) override {
        return ast::ptr<ast::Stmt>(new ast::BreakStmt(get_pos(ctx)));
    }

    // continueStatement: CONTINUE SEMICOLON;
    virtual antlrcpp::Any visitContinueStatement(
        qasm3Parser::ContinueStatementContext* ctx) override {
        return ast::ptr<ast::Stmt>(new ast::ContinueStmt(get_pos(ctx)));
    }

    // endStatement: END SEMICOLON;
    virtual antlrcpp::Any
    visitEndStatement(qasm3Parser::EndStatementContext* ctx) override {
        return ast::ptr<ast::Stmt>(new ast::EndStmt(get_pos(ctx)));
    }

    // forStatement: FOR scalarType Identifier IN (setExpression | LBRACKET
    // rangeExpression RBRACKET | Identifier) body=statementOrScope;
    virtual antlrcpp::Any
    visitForStatement(qasm3Parser::ForStatementContext* ctx) override {
        auto type = std::move(
            ctx->scalarType()->accept(this).as<ast::ptr<ast::NonArrayType>>());
        std::string var = ctx->Identifier(0)->getText();
        auto body = std::move(ctx->statementOrScope()
                                  ->accept(this)
                                  .as<ast::ptr<ast::ProgramBlock>>());
        ast::ptr<ast::IndexSet> set;
        if (ctx->setExpression()) {
            auto indices =
                std::move(ctx->setExpression()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::Expr>>>());
            set = ast::ptr<ast::IndexSet>(
                new ast::ListSet(get_pos(ctx), std::move(indices)));
        } else if (ctx->rangeExpression()) {
            auto [start, step, stop] = std::move(
                ctx->rangeExpression()->accept(this).as<ExprTriplet>());
            set = ast::ptr<ast::IndexSet>(
                new ast::RangeSet(get_pos(ctx), std::move(start),
                                  std::move(step), std::move(stop)));
        } else {
            set = ast::ptr<ast::IndexSet>(
                new ast::VarSet(get_pos(ctx), ctx->Identifier(1)->getText()));
        }
        return ast::ptr<ast::Stmt>(
            new ast::ForStmt(get_pos(ctx), std::move(type), var, std::move(set),
                             std::move(body)));
    }

    // ifStatement: IF LPAREN expression RPAREN if_body=statementOrScope (ELSE
    // else_body=statementOrScope)?;
    virtual antlrcpp::Any
    visitIfStatement(qasm3Parser::IfStatementContext* ctx) override {
        auto cond = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        auto branches = ctx->statementOrScope();
        auto then = std::move(
            branches[0]->accept(this).as<ast::ptr<ast::ProgramBlock>>());
        ast::ptr<ast::ProgramBlock> els;
        if (branches.size() > 1) {
            els = std::move(
                branches[1]->accept(this).as<ast::ptr<ast::ProgramBlock>>());
        } else {
            els = ast::ProgramBlock::create({}, {});
        }
        return ast::ptr<ast::Stmt>(new ast::IfStmt(
            get_pos(ctx), std::move(cond), std::move(then), std::move(els)));
    }

    // returnStatement: RETURN (expression | measureExpression)? SEMICOLON;
    virtual antlrcpp::Any
    visitReturnStatement(qasm3Parser::ReturnStatementContext* ctx) override {
        if (ctx->expression()) {
            auto exp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Stmt>(
                new ast::ReturnStmt(get_pos(ctx), std::move(exp)));
        } else if (ctx->measureExpression()) {
            auto msmt = std::move(ctx->measureExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Stmt>(
                new ast::ReturnStmt(get_pos(ctx), std::move(msmt)));
        } else {
            return ast::ptr<ast::Stmt>(new ast::ReturnStmt(get_pos(ctx)));
        }
    }

    // whileStatement: WHILE LPAREN expression RPAREN body=statementOrScope;
    virtual antlrcpp::Any
    visitWhileStatement(qasm3Parser::WhileStatementContext* ctx) override {
        auto cond = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        auto body = std::move(ctx->statementOrScope()
                                  ->accept(this)
                                  .as<ast::ptr<ast::ProgramBlock>>());
        return ast::ptr<ast::Stmt>(
            new ast::WhileStmt(get_pos(ctx), std::move(cond), std::move(body)));
    }

    // barrierStatement: BARRIER gateOperandList? SEMICOLON;
    virtual antlrcpp::Any
    visitBarrierStatement(qasm3Parser::BarrierStatementContext* ctx) override {
        if (ctx->gateOperandList()) {
            auto args =
                std::move(ctx->gateOperandList()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::IndexId>>>());
            return ast::ptr<ast::Stmt>(
                new ast::BarrierStmt(get_pos(ctx), std::move(args)));
        }
        return ast::ptr<ast::Stmt>(new ast::BarrierStmt(get_pos(ctx), {}));
    }

    // boxStatement: BOX designator? scope;
    virtual antlrcpp::Any
    visitBoxStatement(qasm3Parser::BoxStatementContext* ctx) override {
        auto body = std::move(
            ctx->scope()->accept(this).as<ast::ptr<ast::ProgramBlock>>());
        if (ctx->designator()) {
            auto duration = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Stmt>(new ast::BoxStmt(
                get_pos(ctx), std::move(duration), std::move(body)));
        } else {
            return ast::ptr<ast::Stmt>(
                new ast::BoxStmt(get_pos(ctx), std::move(body)));
        }
    }

    // delayStatement: DELAY designator gateOperandList? SEMICOLON;
    virtual antlrcpp::Any
    visitDelayStatement(qasm3Parser::DelayStatementContext* ctx) override {
        auto duration = std::move(
            ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
        if (ctx->gateOperandList()) {
            auto args =
                std::move(ctx->gateOperandList()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::IndexId>>>());
            return ast::ptr<ast::Stmt>(new ast::DelayStmt(
                get_pos(ctx), std::move(duration), std::move(args)));
        }
        return ast::ptr<ast::Stmt>(
            new ast::DelayStmt(get_pos(ctx), std::move(duration), {}));
    }

    // gateCallStatement:
    //    gateModifier* Identifier (LPAREN expressionList? RPAREN)? designator?
    //    gateOperandList SEMICOLON | gateModifier* GPHASE (LPAREN
    //    expressionList? RPAREN)? designator? gateOperandList? SEMICOLON
    virtual antlrcpp::Any visitGateCallStatement(
        qasm3Parser::GateCallStatementContext* ctx) override {
        if (ctx->designator()) {
            std::cerr << get_pos(ctx->designator())
                      << ": warning: ignoring unexpected designator\n";
        }
        std::list<ast::ptr<ast::GateModifier>> mods;
        for (auto x : ctx->gateModifier()) {
            mods.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::GateModifier>>()));
        }
        std::string gatename = "gphase";
        if (ctx->Identifier()) {
            gatename = ctx->Identifier()->getText();
        }
        std::vector<ast::ptr<ast::Expr>> c_args;
        if (ctx->expressionList()) {
            c_args = std::move(ctx->expressionList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::Expr>>>());
        }
        std::vector<ast::ptr<ast::IndexId>> q_args;
        if (ctx->gateOperandList()) {
            q_args = std::move(ctx->gateOperandList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::IndexId>>>());
        }

        if (gatename == "U") {
            if (c_args.size() != 3) {
                std::cerr << get_pos(ctx)
                          << ": error: U gate takes exactly 3 classical "
                             "arguments, but got "
                          << c_args.size() << "\n";
                throw std::logic_error("Parsing failed!");
            }
            return ast::ptr<ast::Stmt>(new ast::UGate(
                get_pos(ctx), std::move(mods), std::move(c_args[0]),
                std::move(c_args[1]), std::move(c_args[2]), std::move(q_args)));
        } else if (gatename == "gphase") {
            if (c_args.size() != 1) {
                std::cerr << get_pos(ctx)
                          << ": error: gphase takes exactly 1 classical "
                             "argument, but got "
                          << c_args.size() << "\n";
                throw std::logic_error("Parsing failed!");
            }
            return ast::ptr<ast::Stmt>(
                new ast::GPhase(get_pos(ctx), std::move(mods),
                                std::move(c_args[0]), std::move(q_args)));
        } else {
            return ast::ptr<ast::Stmt>(
                new ast::DeclaredGate(get_pos(ctx), std::move(mods), gatename,
                                      std::move(c_args), std::move(q_args)));
        }
    }

    // measureArrowAssignmentStatement: measureExpression (ARROW
    // indexedIdentifier)? SEMICOLON;
    virtual antlrcpp::Any visitMeasureArrowAssignmentStatement(
        qasm3Parser::MeasureArrowAssignmentStatementContext* ctx) override {
        auto expr = std::move(
            ctx->measureExpression()->accept(this).as<ast::ptr<ast::Expr>>());
        if (ctx->indexedIdentifier()) {
            auto id = std::move(ctx->indexedIdentifier()
                                    ->accept(this)
                                    .as<ast::ptr<ast::IndexId>>());
            return ast::ptr<ast::Stmt>(new ast::AssignmentStmt(
                get_pos(ctx), std::move(id), ast::AssignOp::Equals,
                std::move(expr)));
        }
        return ast::ptr<ast::Stmt>(
            new ast::ExprStmt(get_pos(ctx), std::move(expr)));
    }

    // resetStatement: RESET gateOperand SEMICOLON;
    virtual antlrcpp::Any
    visitResetStatement(qasm3Parser::ResetStatementContext* ctx) override {
        auto arg = std::move(
            ctx->gateOperand()->accept(this).as<ast::ptr<ast::IndexId>>());
        return ast::ptr<ast::Stmt>(
            new ast::ResetStmt(get_pos(ctx), std::move(arg)));
    }

    // aliasDeclarationStatement: LET Identifier EQUALS aliasExpression
    // SEMICOLON;
    virtual antlrcpp::Any visitAliasDeclarationStatement(
        qasm3Parser::AliasDeclarationStatementContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> regs;
        for (auto x : ctx->aliasExpression()->expression()) {
            regs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        }
        return ast::ptr<ast::Stmt>(new ast::AliasStmt(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(regs)));
    }

    // classicalDeclarationStatement: (scalarType | arrayType) Identifier
    // (EQUALS declarationExpression)? SEMICOLON;
    virtual antlrcpp::Any visitClassicalDeclarationStatement(
        qasm3Parser::ClassicalDeclarationStatementContext* ctx) override {
        ast::ptr<ast::ClassicalType> type;
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->scalarType()) {
            type = std::move(ctx->scalarType()
                                 ->accept(this)
                                 .as<ast::ptr<ast::NonArrayType>>());
        } else {
            type = std::move(
                ctx->arrayType()->accept(this).as<ast::ptr<ast::ArrayType>>());
        }
        if (ctx->declarationExpression()) {
            exp = std::move(ctx->declarationExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        }
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp)));
    }

    // constDeclarationStatement: CONST scalarType Identifier EQUALS
    // declarationExpression SEMICOLON;
    virtual antlrcpp::Any visitConstDeclarationStatement(
        qasm3Parser::ConstDeclarationStatementContext* ctx) override {
        auto type = std::move(
            ctx->scalarType()->accept(this).as<ast::ptr<ast::NonArrayType>>());
        auto exp = std::move(ctx->declarationExpression()
                                 ->accept(this)
                                 .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp), true));
    }

    // ioDeclarationStatement: (INPUT | OUTPUT) (scalarType | arrayType)
    // Identifier SEMICOLON;
    virtual antlrcpp::Any visitIoDeclarationStatement(
        qasm3Parser::IoDeclarationStatementContext* ctx) override {
        ast::ptr<ast::ClassicalType> type;
        if (ctx->scalarType()) {
            type = std::move(ctx->scalarType()
                                 ->accept(this)
                                 .as<ast::ptr<ast::NonArrayType>>());
        } else {
            type = std::move(
                ctx->arrayType()->accept(this).as<ast::ptr<ast::ArrayType>>());
        }
        return ast::ptr<ast::Stmt>(
            new ast::IODecl(get_pos(ctx), ctx->Identifier()->getText(),
                            std::move(type), ctx->INPUT()));
    }

    // oldStyleDeclarationStatement: (CREG | QREG) Identifier designator?
    // SEMICOLON;
    virtual antlrcpp::Any visitOldStyleDeclarationStatement(
        qasm3Parser::OldStyleDeclarationStatementContext* ctx) override {
        if (ctx->CREG()) {
            ast::ptr<ast::ClassicalType> tmp;
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                tmp =
                    ast::ptr<ast::ClassicalType>(new ast::SingleDesignatorType(
                        get_pos(ctx), ast::SDType::Bit, std::move(size)));
            } else {
                tmp =
                    ast::ptr<ast::ClassicalType>(new ast::SingleDesignatorType(
                        get_pos(ctx), ast::SDType::Bit));
            }
            return ast::ptr<ast::Stmt>(new ast::ClassicalDecl(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp)));
        } else {
            ast::ptr<ast::QuantumType> tmp;
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                tmp = ast::ptr<ast::QuantumType>(
                    new ast::QubitType(get_pos(ctx), std::move(size)));
            } else {
                tmp = ast::ptr<ast::QuantumType>(
                    new ast::QubitType(get_pos(ctx)));
            }
            return ast::ptr<ast::Stmt>(new ast::QuantumDecl(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp)));
        }
    }

    // quantumDeclarationStatement: qubitType Identifier SEMICOLON;
    virtual antlrcpp::Any visitQuantumDeclarationStatement(
        qasm3Parser::QuantumDeclarationStatementContext* ctx) override {
        auto type = std::move(
            ctx->qubitType()->accept(this).as<ast::ptr<ast::QubitType>>());
        return ast::ptr<ast::Stmt>(new ast::QuantumDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(type)));
    }

    // defStatement: DEF Identifier LPAREN argumentDefinitionList? RPAREN
    // returnSignature? scope;
    virtual antlrcpp::Any
    visitDefStatement(qasm3Parser::DefStatementContext* ctx) override {
        std::vector<ast::ptr<ast::Param>> params;
        if (ctx->argumentDefinitionList()) {
            params = std::move(ctx->argumentDefinitionList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::Param>>>());
        }
        std::optional<ast::ptr<ast::NonArrayType>> return_type = std::nullopt;
        if (ctx->returnSignature()) {
            return_type = std::move(ctx->returnSignature()
                                        ->accept(this)
                                        .as<ast::ptr<ast::NonArrayType>>());
        }
        auto body = std::move(
            ctx->scope()->accept(this).as<ast::ptr<ast::ProgramBlock>>());
        return ast::ptr<ast::Stmt>(new ast::SubroutineDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(params),
            std::move(return_type), std::move(body)));
    }

    // externStatement: EXTERN Identifier LPAREN externArgumentList? RPAREN
    // returnSignature? SEMICOLON;
    virtual antlrcpp::Any
    visitExternStatement(qasm3Parser::ExternStatementContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalType>> param_types;
        if (ctx->externArgumentList()) {
            param_types =
                std::move(ctx->externArgumentList()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::ClassicalType>>>());
        }
        std::optional<ast::ptr<ast::NonArrayType>> return_type = std::nullopt;
        if (ctx->returnSignature()) {
            return_type = std::move(ctx->returnSignature()
                                        ->accept(this)
                                        .as<ast::ptr<ast::NonArrayType>>());
        }
        return ast::ptr<ast::Stmt>(new ast::ExternDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(param_types),
            std::move(return_type)));
    }

    // gateStatement: GATE Identifier (LPAREN params=identifierList? RPAREN)?
    // qubits=identifierList scope;
    virtual antlrcpp::Any
    visitGateStatement(qasm3Parser::GateStatementContext* ctx) override {
        auto idlists = ctx->identifierList();
        std::vector<std::string> c_params;
        if (idlists.size() > 1) {
            c_params = std::move(
                idlists.front()->accept(this).as<std::vector<std::string>>());
        }
        auto q_params = std::move(
            idlists.back()->accept(this).as<std::vector<std::string>>());
        auto body = std::move(
            ctx->scope()->accept(this).as<ast::ptr<ast::ProgramBlock>>());
        return ast::ptr<ast::Stmt>(
            new ast::GateDecl(get_pos(ctx), ctx->Identifier()->getText(),
                              c_params, q_params, std::move(body)));
    }

    // indexedIdentifier op=(EQUALS | CompoundAssignmentOperator) (expression |
    // measureExpression) SEMICOLON;
    virtual antlrcpp::Any visitAssignmentStatement(
        qasm3Parser::AssignmentStatementContext* ctx) override {
        auto var = std::move(ctx->indexedIdentifier()
                                 ->accept(this)
                                 .as<ast::ptr<ast::IndexId>>());
        ast::AssignOp op = ast::AssignOp::Equals;
        if (ctx->CompoundAssignmentOperator()) {
            std::string text = ctx->CompoundAssignmentOperator()->getText();
            if (text == "+=") {
                op = ast::AssignOp::Plus;
            } else if (text == "-=") {
                op = ast::AssignOp::Minus;
            } else if (text == "*=") {
                op = ast::AssignOp::Times;
            } else if (text == "/=") {
                op = ast::AssignOp::Div;
            } else if (text == "&=") {
                op = ast::AssignOp::BitAnd;
            } else if (text == "|=") {
                op = ast::AssignOp::BitOr;
            } else if (text == "~=") {
                op = ast::AssignOp::Tilde;
            } else if (text == "^=") {
                op = ast::AssignOp::XOr;
            } else if (text == "<<=") {
                op = ast::AssignOp::LeftBitShift;
            } else if (text == ">>=") {
                op = ast::AssignOp::RightBitShift;
            } else if (text == "%=") {
                op = ast::AssignOp::Mod;
            } else {
                op = ast::AssignOp::Pow;
            }
        }
        ast::ptr<ast::Expr> exp;
        if (ctx->expression()) {
            exp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        } else {
            exp = std::move(ctx->measureExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        }
        return ast::ptr<ast::Stmt>(new ast::AssignmentStmt(
            get_pos(ctx), std::move(var), op, std::move(exp)));
    }

    // expressionStatement: expression SEMICOLON;
    virtual antlrcpp::Any visitExpressionStatement(
        qasm3Parser::ExpressionStatementContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ExprStmt(get_pos(ctx), std::move(exp)));
    }

    // calStatement: CAL LBRACE CalibrationBlock? RBRACE;
    virtual antlrcpp::Any
    visitCalStatement(qasm3Parser::CalStatementContext* ctx) override {
        std::cerr << get_pos(ctx)
                  << ": error: 'cal' statements are not supported\n";
        throw std::logic_error("Parsing error!");
    }

    // defcalStatement: DEFCAL defcalTarget (LPAREN
    // defcalArgumentDefinitionList? RPAREN)? defcalOperandList returnSignature?
    // LBRACE CalibrationBlock? RBRACE;
    virtual antlrcpp::Any
    visitDefcalStatement(qasm3Parser::DefcalStatementContext* ctx) override {
        std::cerr << get_pos(ctx)
                  << ": error: 'defcal' statements are not supported\n";
        throw std::logic_error("Parsing error!");
    }

    // expression op=CARET expression
    virtual antlrcpp::Any visitBitwiseXorExpression(
        qasm3Parser::BitwiseXorExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(new ast::BExpr(get_pos(ctx), std::move(lexp),
                                                  ast::BinaryOp::XOr,
                                                  std::move(rexp)));
    }

    // expression op=(PLUS | MINUS) expression
    virtual antlrcpp::Any visitAdditiveExpression(
        qasm3Parser::AdditiveExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        ast::BinaryOp op = ast::BinaryOp::Plus;
        if (ctx->MINUS()) {
            op = ast::BinaryOp::Minus;
        }
        return ast::ptr<ast::Expr>(
            new ast::BExpr(get_pos(ctx), std::move(lexp), op, std::move(rexp)));
    }

    // DURATIONOF LPAREN scope RPAREN
    virtual antlrcpp::Any visitDurationofExpression(
        qasm3Parser::DurationofExpressionContext* ctx) override {
        auto body = std::move(
            ctx->scope()->accept(this).as<ast::ptr<ast::ProgramBlock>>());
        return ast::ptr<ast::Expr>(
            new ast::DurationofExpr(get_pos(ctx), std::move(body)));
    }

    // LPAREN expression RPAREN
    virtual antlrcpp::Any visitParenthesisExpression(
        qasm3Parser::ParenthesisExpressionContext* ctx) override {
        return ctx->expression()->accept(this);
    }

    // expression op=ComparisonOperator expression
    virtual antlrcpp::Any visitComparisonExpression(
        qasm3Parser::ComparisonExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        ast::BinaryOp op = ast::BinaryOp::GT;
        std::string op_txt = ctx->ComparisonOperator()->getText();
        if (op_txt == "<") {
            op = ast::BinaryOp::LT;
        } else if (op_txt == ">=") {
            op = ast::BinaryOp::GTE;
        } else if (op_txt == "<=") {
            op = ast::BinaryOp::LTE;
        }
        return ast::ptr<ast::Expr>(
            new ast::BExpr(get_pos(ctx), std::move(lexp), op, std::move(rexp)));
    }

    // expression op=(ASTERISK | SLASH | PERCENT) expression
    virtual antlrcpp::Any visitMultiplicativeExpression(
        qasm3Parser::MultiplicativeExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        ast::BinaryOp op = ast::BinaryOp::Times;
        if (ctx->SLASH()) {
            op = ast::BinaryOp::Divide;
        } else if (ctx->PERCENT()) {
            op = ast::BinaryOp::Mod;
        }
        return ast::ptr<ast::Expr>(
            new ast::BExpr(get_pos(ctx), std::move(lexp), op, std::move(rexp)));
    }

    // expression op=DOUBLE_PIPE expression
    virtual antlrcpp::Any visitLogicalOrExpression(
        qasm3Parser::LogicalOrExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(new ast::BExpr(get_pos(ctx), std::move(lexp),
                                                  ast::BinaryOp::LogicalOr,
                                                  std::move(rexp)));
    }

    // (scalarType | arrayType) LPAREN expression RPAREN
    virtual antlrcpp::Any
    visitCastExpression(qasm3Parser::CastExpressionContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        ast::ptr<ast::ClassicalType> type;
        if (ctx->scalarType()) {
            type = std::move(ctx->scalarType()
                                 ->accept(this)
                                 .as<ast::ptr<ast::NonArrayType>>());
        } else {
            type = std::move(
                ctx->arrayType()->accept(this).as<ast::ptr<ast::ArrayType>>());
        }
        return ast::ptr<ast::Expr>(
            new ast::CastExpr(get_pos(ctx), std::move(type), std::move(exp)));
    }

    // <assoc=right> expression op=DOUBLE_ASTERISK expression
    virtual antlrcpp::Any
    visitPowerExpression(qasm3Parser::PowerExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(new ast::BExpr(get_pos(ctx), std::move(lexp),
                                                  ast::BinaryOp::Pow,
                                                  std::move(rexp)));
    }

    // expression op=PIPE expression
    virtual antlrcpp::Any visitBitwiseOrExpression(
        qasm3Parser::BitwiseOrExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(new ast::BExpr(get_pos(ctx), std::move(lexp),
                                                  ast::BinaryOp::BitOr,
                                                  std::move(rexp)));
    }

    // Identifier LPAREN expressionList? RPAREN
    virtual antlrcpp::Any
    visitCallExpression(qasm3Parser::CallExpressionContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> args;
        if (ctx->expressionList()) {
            args = std::move(ctx->expressionList()
                                 ->accept(this)
                                 .as<std::vector<ast::ptr<ast::Expr>>>());
        }
        std::string fn = ctx->Identifier()->getText();
        auto search = call_map.find(fn);
        if (search != call_map.end()) {
            return ast::ptr<ast::Expr>(new ast::MathExpr(
                get_pos(ctx), search->second, std::move(args)));
        } else if (fn == "sizeof") {
            if (args.size() == 1) {
                return ast::ptr<ast::Expr>(
                    new ast::SizeofExpr(get_pos(ctx), std::move(args[0])));
            } else if (args.size() == 2) {
                return ast::ptr<ast::Expr>(new ast::SizeofExpr(
                    get_pos(ctx), std::move(args[0]), std::move(args[1])));
            } else {
                std::cerr << get_pos(ctx)
                          << ": error: sizeof() operator takes one or two "
                             "arguments, but got "
                          << args.size() << "\n";
                throw std::logic_error("Parsing failed!");
            }
        }
        return ast::ptr<ast::Expr>(
            new ast::FunctionCall(get_pos(ctx), fn, std::move(args)));
    }

    // expression op=BitshiftOperator expression
    virtual antlrcpp::Any visitBitshiftExpression(
        qasm3Parser::BitshiftExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        ast::BinaryOp op = ast::BinaryOp::LeftBitShift;
        if (ctx->BitshiftOperator()->getText() == ">>") {
            op = ast::BinaryOp::RightBitShift;
        }
        return ast::ptr<ast::Expr>(
            new ast::BExpr(get_pos(ctx), std::move(lexp), op, std::move(rexp)));
    }

    // expression op=AMPERSAND expression
    virtual antlrcpp::Any visitBitwiseAndExpression(
        qasm3Parser::BitwiseAndExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(new ast::BExpr(get_pos(ctx), std::move(lexp),
                                                  ast::BinaryOp::BitAnd,
                                                  std::move(rexp)));
    }

    // expression op=EqualityOperator expression
    virtual antlrcpp::Any visitEqualityExpression(
        qasm3Parser::EqualityExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        ast::BinaryOp op = ast::BinaryOp::EQ;
        if (ctx->EqualityOperator()->getText() == "!=") {
            op = ast::BinaryOp::NEQ;
        }
        return ast::ptr<ast::Expr>(
            new ast::BExpr(get_pos(ctx), std::move(lexp), op, std::move(rexp)));
    }

    // expression op=DOUBLE_AMPERSAND expression
    virtual antlrcpp::Any visitLogicalAndExpression(
        qasm3Parser::LogicalAndExpressionContext* ctx) override {
        auto lexp = std::move(
            ctx->expression(0)->accept(this).as<ast::ptr<ast::Expr>>());
        auto rexp = std::move(
            ctx->expression(1)->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(new ast::BExpr(get_pos(ctx), std::move(lexp),
                                                  ast::BinaryOp::LogicalAnd,
                                                  std::move(rexp)));
    }

    // expression indexOperator
    virtual antlrcpp::Any
    visitIndexExpression(qasm3Parser::IndexExpressionContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        auto op = std::move(
            ctx->indexOperator()->accept(this).as<ast::ptr<ast::IndexOp>>());
        return ast::ptr<ast::Expr>(
            new ast::AccessExpr(get_pos(ctx), std::move(exp), std::move(op)));
    }

    // op=(TILDE | EXCLAMATION_POINT | MINUS) expression
    virtual antlrcpp::Any
    visitUnaryExpression(qasm3Parser::UnaryExpressionContext* ctx) override {
        ast::UnaryOp op = ast::UnaryOp::BitNot;
        if (ctx->EXCLAMATION_POINT()) {
            op = ast::UnaryOp::LogicalNot;
        } else if (ctx->MINUS()) {
            op = ast::UnaryOp::Neg;
        }
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(
            new ast::UExpr(get_pos(ctx), op, std::move(exp)));
    }

    // Identifier
    //        | BinaryIntegerLiteral
    //        | OctalIntegerLiteral
    //        | DecimalIntegerLiteral
    //        | HexIntegerLiteral
    //        | FloatLiteral
    //        | ImaginaryLiteral
    //        | BooleanLiteral
    //        | BitstringLiteral
    //        | TimingLiteral
    //        | HardwareQubit
    virtual antlrcpp::Any visitLiteralExpression(
        qasm3Parser::LiteralExpressionContext* ctx) override {
        if (ctx->Identifier()) {
            std::string text = ctx->Identifier()->getText();
            if (text == "pi" || text == "π") {
                return ast::ptr<ast::Expr>(
                    new ast::ConstantExpr(get_pos(ctx), ast::Constant::Pi));
            } else if (text == "tau" || text == "τ") {
                return ast::ptr<ast::Expr>(
                    new ast::ConstantExpr(get_pos(ctx), ast::Constant::Tau));
            } else if (text == "euler" || text == "ℇ") {
                return ast::ptr<ast::Expr>(
                    new ast::ConstantExpr(get_pos(ctx), ast::Constant::Euler));
            }
            return ast::ptr<ast::Expr>(new ast::VarExpr(get_pos(ctx), text));
        } else if (ctx->BinaryIntegerLiteral()) {
            std::string text = ctx->BinaryIntegerLiteral()->getText().substr(2);
            remove_underscores(text);
            return ast::ptr<ast::Expr>(
                new ast::IntExpr(get_pos(ctx), std::stoi(text, nullptr, 2)));
        } else if (ctx->OctalIntegerLiteral()) {
            std::string text = ctx->OctalIntegerLiteral()->getText().substr(2);
            remove_underscores(text);
            return ast::ptr<ast::Expr>(
                new ast::IntExpr(get_pos(ctx), std::stoi(text, nullptr, 8)));
        } else if (ctx->DecimalIntegerLiteral()) {
            std::string text = ctx->DecimalIntegerLiteral()->getText();
            remove_underscores(text);
            return ast::ptr<ast::Expr>(
                new ast::IntExpr(get_pos(ctx), std::stoi(text)));
        } else if (ctx->HexIntegerLiteral()) {
            std::string text = ctx->HexIntegerLiteral()->getText().substr(2);
            remove_underscores(text);
            return ast::ptr<ast::Expr>(
                new ast::IntExpr(get_pos(ctx), std::stoi(text, nullptr, 16)));
        } else if (ctx->FloatLiteral()) {
            std::string text = ctx->FloatLiteral()->getText();
            remove_underscores(text);
            return ast::ptr<ast::Expr>(
                new ast::RealExpr(get_pos(ctx), std::stod(text)));
        } else if (ctx->ImaginaryLiteral()) {
            std::string imag =
                ctx->ImaginaryLiteral()->getText(); // "3.5im", "12im", etc
            imag.pop_back();
            imag.pop_back();
            remove_underscores(imag);
            return ast::ptr<ast::Expr>(
                new ast::ImagExpr(get_pos(ctx), std::stod(imag)));
        } else if (ctx->BooleanLiteral()) {
            return ast::ptr<ast::Expr>(new ast::BoolExpr(
                get_pos(ctx), ctx->BooleanLiteral()->getText() == "true"));
        } else if (ctx->BitstringLiteral()) {
            std::string bitstring = ctx->BitstringLiteral()->getText();
            remove_underscores(bitstring);
            return ast::ptr<ast::Expr>(
                new ast::BitString(get_pos(ctx), bitstring));
        } else if (ctx->TimingLiteral()) {
            std::string lit = ctx->TimingLiteral()->getText();
            remove_underscores(lit);
            for (int i = 0; i < units.size(); i++) {
                if (ends_with(lit, units[i])) {
                    std::string value =
                        lit.substr(0, lit.length() - units[i].length());
                    return ast::ptr<ast::Expr>(new ast::TimeExpr(
                        get_pos(ctx), std::stod(value), timeunits[i]));
                }
            }
            std::cerr << get_pos(ctx)
                      << ":TimingLiteral units not recognized!\n";
            throw std::logic_error("Parsing error!");
        } else {
            return ast::ptr<ast::Expr>(new ast::VarExpr(
                get_pos(ctx), ctx->HardwareQubit()->getText()));
        }
    }

    // aliasExpression: expression (DOUBLE_PLUS expression)*;
    virtual antlrcpp::Any
    visitAliasExpression(qasm3Parser::AliasExpressionContext* ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // declarationExpression: arrayLiteral | expression | measureExpression;
    virtual antlrcpp::Any visitDeclarationExpression(
        qasm3Parser::DeclarationExpressionContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // measureExpression: MEASURE gateOperand;
    virtual antlrcpp::Any visitMeasureExpression(
        qasm3Parser::MeasureExpressionContext* ctx) override {
        auto id = std::move(
            ctx->gateOperand()->accept(this).as<ast::ptr<ast::IndexId>>());
        return ast::ptr<ast::Expr>(
            new ast::MeasureExpr(get_pos(ctx), std::move(id)));
    }

    // rangeExpression: expression? COLON expression? (COLON expression)?;
    virtual antlrcpp::Any
    visitRangeExpression(qasm3Parser::RangeExpressionContext* ctx) override {
        ExprTriplet range(std::nullopt, std::nullopt, std::nullopt);
        int index = 0;
        auto a = ctx->children[index]->accept(this);
        if (a.isNotNull()) {
            std::get<0>(range) = std::move(a.as<ast::ptr<ast::Expr>>());
            ++index;
        }
        ++index;
        if (ctx->COLON().size() > 1) {
            auto b = ctx->children[index]->accept(this);
            if (b.isNotNull()) {
                std::get<1>(range) = std::move(b.as<ast::ptr<ast::Expr>>());
                ++index;
            }
            ++index;
        }
        if (ctx->children.size() > index) {
            auto c = ctx->children[index]->accept(this);
            if (c.isNotNull()) {
                std::get<2>(range) = std::move(c.as<ast::ptr<ast::Expr>>());
                ++index;
            }
        }
        return range;
    }

    // setExpression: LBRACE expression (COMMA expression)* COMMA? RBRACE;
    virtual antlrcpp::Any
    visitSetExpression(qasm3Parser::SetExpressionContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> exprs;
        for (auto x : ctx->expression()) {
            exprs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        }
        return exprs;
    }

    // arrayLiteral: LBRACE (expression | arrayLiteral) (COMMA (expression |
    // arrayLiteral))* COMMA? RBRACE;
    virtual antlrcpp::Any
    visitArrayLiteral(qasm3Parser::ArrayLiteralContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> arr;
        for (auto child : ctx->children) {
            auto a = child->accept(this);
            if (a.isNotNull()) {
                arr.emplace_back(std::move(a.as<ast::ptr<ast::Expr>>()));
            }
        }
        return ast::ptr<ast::Expr>(
            new ast::ArrayInitExpr(get_pos(ctx), std::move(arr)));
    }

    // indexOperator:
    //    LBRACKET
    //    (
    //        setExpression
    //        | (expression | rangeExpression) (COMMA (expression |
    //        rangeExpression))* COMMA?
    //    )
    //    RBRACKET;
    virtual antlrcpp::Any
    visitIndexOperator(qasm3Parser::IndexOperatorContext* ctx) override {
        if (ctx->setExpression()) {
            auto indices =
                std::move(ctx->setExpression()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::Expr>>>());
            return ast::ptr<ast::IndexOp>(
                new ast::ListSlice(get_pos(ctx), std::move(indices)));
        } else {
            std::vector<ast::ptr<ast::IndexEntity>> indices;
            for (auto child : ctx->children) {
                auto a = child->accept(this);
                if (a.is<ast::ptr<ast::Expr>>()) {
                    indices.emplace_back(ast::SingleIndex::create(
                        get_pos(ctx), std::move(a.as<ast::ptr<ast::Expr>>())));
                } else if (a.is<ExprTriplet>()) {
                    auto [start, step, stop] = std::move(a.as<ExprTriplet>());
                    indices.emplace_back(ast::RangeIndex::create(
                        get_pos(ctx), std::move(start), std::move(step),
                        std::move(stop)));
                }
            }
            return ast::ptr<ast::IndexOp>(
                new ast::IndexEntityList(get_pos(ctx), std::move(indices)));
        }
    }

    // indexedIdentifier: Identifier indexOperator*;
    virtual antlrcpp::Any visitIndexedIdentifier(
        qasm3Parser::IndexedIdentifierContext* ctx) override {
        std::vector<ast::ptr<ast::IndexOp>> ops;
        for (auto x : ctx->indexOperator()) {
            ops.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::IndexOp>>()));
        }
        return ast::IndexId::create(get_pos(ctx), ctx->Identifier()->getText(),
                                    std::move(ops));
    }

    // returnSignature: ARROW scalarType;
    virtual antlrcpp::Any
    visitReturnSignature(qasm3Parser::ReturnSignatureContext* ctx) override {
        return ctx->scalarType()->accept(this);
    }

    // gateModifier: (
    //    INV
    //    | POW LPAREN expression RPAREN
    //    | (CTRL | NEGCTRL) (LPAREN expression RPAREN)?
    // ) AT;
    virtual antlrcpp::Any
    visitGateModifier(qasm3Parser::GateModifierContext* ctx) override {
        if (ctx->INV()) {
            return ast::ptr<ast::GateModifier>(
                new ast::InvModifier(get_pos(ctx)));
        } else if (ctx->POW()) {
            auto exp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::GateModifier>(
                new ast::PowModifier(get_pos(ctx), std::move(exp)));
        } else {
            if (ctx->expression()) {
                auto exp = std::move(
                    ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
                return ast::ptr<ast::GateModifier>(new ast::CtrlModifier(
                    get_pos(ctx), ctx->NEGCTRL(), std::move(exp)));
            } else {
                return ast::ptr<ast::GateModifier>(
                    new ast::CtrlModifier(get_pos(ctx), ctx->NEGCTRL()));
            }
        }
    }

    // scalarType:
    //    BIT designator?
    //    | INT designator?
    //    | UINT designator?
    //    | FLOAT designator?
    //    | ANGLE designator?
    //    | BOOL
    //    | DURATION
    //    | STRETCH
    //    | COMPLEX (LBRACKET scalarType RBRACKET)?
    virtual antlrcpp::Any
    visitScalarType(qasm3Parser::ScalarTypeContext* ctx) override {
        if (ctx->BOOL()) {
            return ast::ptr<ast::NonArrayType>(
                new ast::NoDesignatorType(get_pos(ctx), ast::NDType::Bool));
        } else if (ctx->DURATION()) {
            return ast::ptr<ast::NonArrayType>(
                new ast::NoDesignatorType(get_pos(ctx), ast::NDType::Duration));
        } else if (ctx->STRETCH()) {
            return ast::ptr<ast::NonArrayType>(
                new ast::NoDesignatorType(get_pos(ctx), ast::NDType::Stretch));
        } else if (ctx->COMPLEX()) {
            if (ctx->scalarType()) {
                auto subtype =
                    std::move(ctx->scalarType()
                                  ->accept(this)
                                  .as<ast::ptr<ast::NonArrayType>>());
                return ast::ptr<ast::NonArrayType>(
                    new ast::ComplexType(get_pos(ctx), std::move(subtype)));
            }
            return ast::ptr<ast::NonArrayType>(
                new ast::ComplexType(get_pos(ctx)));
        } else {
            ast::SDType type;
            if (ctx->BIT()) {
                type = ast::SDType::Bit;
            } else if (ctx->INT()) {
                type = ast::SDType::Int;
            } else if (ctx->UINT()) {
                type = ast::SDType::Uint;
            } else if (ctx->FLOAT()) {
                type = ast::SDType::Float;
            } else {
                type = ast::SDType::Angle;
            }
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                return ast::ptr<ast::NonArrayType>(
                    new ast::SingleDesignatorType(get_pos(ctx), type,
                                                  std::move(size)));
            }
            return ast::ptr<ast::NonArrayType>(
                new ast::SingleDesignatorType(get_pos(ctx), type));
        }
    }

    // qubitType: QUBIT designator?;
    virtual antlrcpp::Any
    visitQubitType(qasm3Parser::QubitTypeContext* ctx) override {
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::QubitType::create(get_pos(ctx), std::move(size));
        }
        return ast::QubitType::create(get_pos(ctx));
    }

    // arrayType: ARRAY LBRACKET scalarType COMMA expressionList RBRACKET;
    virtual antlrcpp::Any
    visitArrayType(qasm3Parser::ArrayTypeContext* ctx) override {
        auto subtype = std::move(
            ctx->scalarType()->accept(this).as<ast::ptr<ast::NonArrayType>>());
        auto dimensions =
            std::move(ctx->expressionList()
                          ->accept(this)
                          .as<std::vector<ast::ptr<ast::Expr>>>());
        return ast::ArrayType::create(get_pos(ctx), std::move(subtype),
                                      std::move(dimensions));
    }

    // arrayReferenceType: (READONLY | MUTABLE) ARRAY LBRACKET scalarType COMMA
    // (expressionList | DIM EQUALS expression) RBRACKET;
    virtual antlrcpp::Any visitArrayReferenceType(
        qasm3Parser::ArrayReferenceTypeContext* ctx) override {
        auto subtype = std::move(
            ctx->scalarType()->accept(this).as<ast::ptr<ast::NonArrayType>>());
        std::variant<std::vector<ast::ptr<ast::Expr>>, ast::ptr<ast::Expr>>
            dims;
        if (ctx->expressionList()) {
            dims = std::move(ctx->expressionList()
                                 ->accept(this)
                                 .as<std::vector<ast::ptr<ast::Expr>>>());
        } else {
            dims = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        }
        return ast::ArrayRefType::create(get_pos(ctx), std::move(subtype),
                                         std::move(dims), ctx->MUTABLE());
    }

    // designator: LBRACKET expression RBRACKET;
    virtual antlrcpp::Any
    visitDesignator(qasm3Parser::DesignatorContext* ctx) override {
        return ctx->expression()->accept(this);
    }

    // defcalTarget: MEASURE | RESET | DELAY | Identifier;
    virtual antlrcpp::Any
    visitDefcalTarget(qasm3Parser::DefcalTargetContext* ctx) override {
        return defaultResult(); // ignored
    }

    // defcalArgumentDefinition: expression | argumentDefinition;
    virtual antlrcpp::Any visitDefcalArgumentDefinition(
        qasm3Parser::DefcalArgumentDefinitionContext* ctx) override {
        return defaultResult(); // ignored
    }

    // defcalOperand: HardwareQubit | Identifier;
    virtual antlrcpp::Any
    visitDefcalOperand(qasm3Parser::DefcalOperandContext* ctx) override {
        return defaultResult(); // ignored
    }

    // gateOperand: indexedIdentifier | HardwareQubit;
    virtual antlrcpp::Any
    visitGateOperand(qasm3Parser::GateOperandContext* ctx) override {
        if (ctx->HardwareQubit()) {
            return ast::IndexId::create(get_pos(ctx),
                                        ctx->HardwareQubit()->getText(), {});
        }
        return ctx->indexedIdentifier()->accept(this);
    }

    // externArgument: scalarType | arrayReferenceType | CREG designator?;
    virtual antlrcpp::Any
    visitExternArgument(qasm3Parser::ExternArgumentContext* ctx) override {
        if (ctx->scalarType()) {
            auto type = std::move(ctx->scalarType()
                                      ->accept(this)
                                      .as<ast::ptr<ast::NonArrayType>>());
            return ast::ptr<ast::ClassicalType>(std::move(type));
        } else if (ctx->arrayReferenceType()) {
            auto type = std::move(ctx->arrayReferenceType()
                                      ->accept(this)
                                      .as<ast::ptr<ast::ArrayRefType>>());
            return ast::ptr<ast::ClassicalType>(std::move(type));
        } else {
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                return ast::ptr<ast::ClassicalType>(
                    new ast::SingleDesignatorType(
                        get_pos(ctx), ast::SDType::Bit, std::move(size)));
            } else {
                return ast::ptr<ast::ClassicalType>(
                    new ast::SingleDesignatorType(get_pos(ctx),
                                                  ast::SDType::Bit));
            }
        }
    }

    // argumentDefinition:
    //    scalarType Identifier
    //    | qubitType Identifier
    //    | (CREG | QREG) Identifier designator?
    //    | arrayReferenceType Identifier
    virtual antlrcpp::Any visitArgumentDefinition(
        qasm3Parser::ArgumentDefinitionContext* ctx) override {
        if (ctx->scalarType()) {
            auto type = std::move(ctx->scalarType()
                                      ->accept(this)
                                      .as<ast::ptr<ast::NonArrayType>>());
            return ast::Param::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(type));
        } else if (ctx->qubitType()) {
            auto type = std::move(
                ctx->qubitType()->accept(this).as<ast::ptr<ast::QubitType>>());
            return ast::Param::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(type));
        } else if (ctx->arrayReferenceType()) {
            auto type = std::move(ctx->arrayReferenceType()
                                      ->accept(this)
                                      .as<ast::ptr<ast::ArrayRefType>>());
            return ast::Param::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(type));
        } else if (ctx->CREG()) {
            ast::ptr<ast::Type> tmp;
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                tmp = ast::ptr<ast::Type>(new ast::SingleDesignatorType(
                    get_pos(ctx), ast::SDType::Bit, std::move(size)));
            } else {
                tmp = ast::ptr<ast::Type>(new ast::SingleDesignatorType(
                    get_pos(ctx), ast::SDType::Bit));
            }
            return ast::Param::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
        } else {
            ast::ptr<ast::Type> tmp;
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                tmp = ast::ptr<ast::Type>(
                    new ast::QubitType(get_pos(ctx), std::move(size)));
            } else {
                tmp = ast::ptr<ast::Type>(new ast::QubitType(get_pos(ctx)));
            }
            return ast::Param::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
        }
    }

    // argumentDefinitionList: argumentDefinition (COMMA argumentDefinition)*
    // COMMA?;
    virtual antlrcpp::Any visitArgumentDefinitionList(
        qasm3Parser::ArgumentDefinitionListContext* ctx) override {
        std::vector<ast::ptr<ast::Param>> params;
        for (auto x : ctx->argumentDefinition()) {
            params.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Param>>()));
        }
        return params;
    }

    // defcalArgumentDefinitionList: defcalArgumentDefinition (COMMA
    // defcalArgumentDefinition)* COMMA?;
    virtual antlrcpp::Any visitDefcalArgumentDefinitionList(
        qasm3Parser::DefcalArgumentDefinitionListContext* ctx) override {
        return defaultResult(); // ignored
    }

    // defcalOperandList: defcalOperand (COMMA defcalOperand)* COMMA?;
    virtual antlrcpp::Any visitDefcalOperandList(
        qasm3Parser::DefcalOperandListContext* ctx) override {
        return defaultResult(); // ignored
    }

    // expressionList: expression (COMMA expression)* COMMA?;
    virtual antlrcpp::Any
    visitExpressionList(qasm3Parser::ExpressionListContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> exprs;
        for (auto x : ctx->expression()) {
            exprs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        }
        return exprs;
    }

    // identifierList: Identifier (COMMA Identifier)* COMMA?;
    virtual antlrcpp::Any
    visitIdentifierList(qasm3Parser::IdentifierListContext* ctx) override {
        std::vector<std::string> ids;
        for (auto x : ctx->Identifier()) {
            ids.push_back(x->getText());
        }
        return ids;
    }

    // gateOperandList: gateOperand (COMMA gateOperand)* COMMA?;
    virtual antlrcpp::Any
    visitGateOperandList(qasm3Parser::GateOperandListContext* ctx) override {
        std::vector<ast::ptr<ast::IndexId>> args;
        for (auto opd : ctx->gateOperand()) {
            args.emplace_back(
                std::move(opd->accept(this).as<ast::ptr<ast::IndexId>>()));
        }
        return args;
    }

    // externArgumentList: externArgument (COMMA externArgument)* COMMA?;
    virtual antlrcpp::Any visitExternArgumentList(
        qasm3Parser::ExternArgumentListContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalType>> args;
        for (auto x : ctx->externArgument()) {
            args.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::ClassicalType>>()));
        }
        return args;
    }

    ast::ptr<ast::Program> make_ast(qasm3Parser::ProgramContext* ctx) {
        return std::move(visitProgram(ctx).as<ast::ptr<ast::Program>>());
    }

  private:
    static Position get_pos(antlr4::ParserRuleContext* ctx) {
        antlr4::Token* tok = ctx->start;
        return Position(tok->getTokenSource()->getSourceName(), tok->getLine(),
                        tok->getCharPositionInLine() + 1);
    }

    static Position get_pos(antlr4::tree::TerminalNode* node) {
        antlr4::Token* tok = node->getSymbol();
        return Position(tok->getTokenSource()->getSourceName(), tok->getLine(),
                        tok->getCharPositionInLine() + 1);
    }

    static bool ends_with(const std::string& str, const std::string& suffix) {
        if (str.length() < suffix.length()) {
            return false;
        }
        return str.substr(str.length() - suffix.length()) == suffix;
    }

    static std::string get_source_name(qasm3Parser::ProgramContext* ctx) {
        antlr4::Token* tok = ctx->start;
        return tok->getTokenSource()->getSourceName();
    }

    static void remove_underscores(std::string& str) {
        str.erase(std::remove(str.begin(), str.end(), '_'), str.end());
    }
};

/**
 * \brief Parse a specified file without semantic checking
 */
inline ast::ptr<ast::Program> parse_file_helper(std::string fname) {
    if (!std::filesystem::exists(fname)) {
        throw std::logic_error("File \"" + fname + "\" not found!\n");
    }
    antlr4::ANTLRFileStream input;
    input.loadFromFile(fname);
    qasm3Lexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    qasm3Parser parser(&tokens);
    parser.setBuildParseTree(true);
    qasm3Parser::ProgramContext* tree = parser.program();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        throw std::logic_error("Parsing failed!");
    }
    return ASTConstructor().make_ast(tree);
}

/**
 * \brief Parse a string without semantic checking
 */
inline ast::ptr<ast::Program> parse_string_helper(const std::string& str,
                                                  std::string name = "") {
    antlr4::ANTLRInputStream input(str);
    input.name = name;
    qasm3Lexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    qasm3Parser parser(&tokens);
    parser.setBuildParseTree(true);
    qasm3Parser::ProgramContext* tree = parser.program();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        throw std::logic_error("Parsing failed!");
    }
    return ASTConstructor().make_ast(tree);
}

/**
 * \brief Parse a specified file
 */
inline ast::ptr<ast::Program> parse_file(std::string fname) {
    auto result = parse_file_helper(fname);
    ast::check_source(*result);
    return result;
}

/**
 * \brief Parse a string
 */
inline ast::ptr<ast::Program> parse_string(const std::string& str,
                                           std::string name = "") {
    auto result = parse_string_helper(str, name);
    ast::check_source(*result);
    return result;
}

} /* namespace parser */
} /* namespace qasm3tools */

#endif /* QASM3TOOLS_PARSER_PARSER_HPP_ */
