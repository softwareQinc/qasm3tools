/*
 * This file is part of qasm3tools.
 *
 * Copyright (c) 2019 - 2022 softwareQ Inc. All rights reserved.
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

#pragma once

#include "../ast/ast.hpp"
//#include "../ast/semantic.hpp"
#include "antlr4-runtime.h"
#include "position.hpp"
#include "qasm3LexerImpl.hpp"
#include "qasm3ParserImpl.hpp"
#include "qasm3ParserVisitor.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <tuple>

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
    "gate cx c, t { ctrl @ x c, t; }\n"
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
    "gate cu(θ, φ, λ, γ) c, t { p(γ) c; ctrl @ U(θ, φ, λ) c, t; }\n"
    "gate CX c, t { ctrl @ U(π, 0, π) c, t; }\n"
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

  public:
    // program: header (globalStatement | statement)*;
    virtual antlrcpp::Any
    visitProgram(qasm3Parser::ProgramContext* ctx) override {
        auto prog = ast::Program::create(
            get_pos(ctx), {}, get_source_name(ctx) == "stdgates.inc");
        for (auto& child : ctx->children) {
            auto a = child->accept(this);
            if (a.is<ast::ptr<ast::GlobalStmt>>()) {
                prog->body().emplace_back(
                    std::move(a.as<ast::ptr<ast::GlobalStmt>>()));
            } else if (a.is<ast::ptr<ast::Stmt>>()) {
                prog->body().emplace_back(
                    std::move(a.as<ast::ptr<ast::Stmt>>()));
            } else {
                auto includes =
                    std::move(a.as<std::vector<ast::ptr<ast::Program>>>());
                for (auto& included : includes) {
                    prog->extend(*included);
                }
            }
        }
        return prog;
    }

    // header: version? include* io*;
    virtual antlrcpp::Any
    visitHeader(qasm3Parser::HeaderContext* ctx) override {
        std::vector<ast::ptr<ast::Program>> includes;
        for (auto& x : ctx->include()) {
            includes.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Program>>()));
        }
        return includes;
    }

    // version: OPENQASM (DecimalIntegerLiteral | FloatLiteral) SEMICOLON;
    virtual antlrcpp::Any
    visitVersion(qasm3Parser::VersionContext* ctx) override {
        return defaultResult(); // ignored
    }

    // include: INCLUDE StringLiteral SEMICOLON;
    virtual antlrcpp::Any
    visitInclude(qasm3Parser::IncludeContext* ctx) override {
        std::string inc_str = ctx->StringLiteral()->getText();
        std::string fname = inc_str.substr(1, inc_str.length() - 2);
        if (fname == "stdgates.inc") {
            return parse_string_helper(std_include, fname);
        } else {
            return parse_file_helper(fname);
        }
    }

    // ioIdentifier: INPUT | OUTPUT;
    virtual antlrcpp::Any
    visitIoIdentifier(qasm3Parser::IoIdentifierContext* ctx) override {
        return defaultResult(); // ignored
    }

    // io: ioIdentifier classicalType Identifier SEMICOLON;
    virtual antlrcpp::Any visitIo(qasm3Parser::IoContext* ctx) override {
        return defaultResult(); // ignored
    }

    // globalStatement
    //  : subroutineDefinition
    //  | externDeclaration
    //  | quantumGateDefinition
    //  | calibration
    //  | quantumDeclarationStatement  // qubits are declared globally
    //  | pragma
    virtual antlrcpp::Any
    visitGlobalStatement(qasm3Parser::GlobalStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // statement
    //  : expressionStatement
    //  | assignmentStatement
    //  | classicalDeclarationStatement
    //  | branchingStatement
    //  | loopStatement
    //  | endStatement
    //  | aliasStatement
    //  | quantumStatement
    virtual antlrcpp::Any
    visitStatement(qasm3Parser::StatementContext* ctx) override {
        auto a = ctx->children[0]->accept(this);
        if (a.is<ast::ptr<ast::QuantumStmt>>()) {
            return ast::ptr<ast::Stmt>(
                std::move(a.as<ast::ptr<ast::QuantumStmt>>()));
        } else
            return a;
    }

    // quantumDeclarationStatement : quantumDeclaration SEMICOLON ;
    virtual antlrcpp::Any visitQuantumDeclarationStatement(
        qasm3Parser::QuantumDeclarationStatementContext* ctx) override {
        return ctx->quantumDeclaration()->accept(this);
    }

    // classicalDeclarationStatement: (classicalDeclaration | constantDeclaration) SEMICOLON;
    virtual antlrcpp::Any visitClassicalDeclarationStatement(
        qasm3Parser::ClassicalDeclarationStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // classicalAssignment: indexedIdentifier assignmentOperator expression;
    virtual antlrcpp::Any visitClassicalAssignment(
        qasm3Parser::ClassicalAssignmentContext* ctx) override {
        auto var = std::move(
            ctx->indexedIdentifier()->accept(this).as<ast::ptr<ast::IndexId>>());
        auto op = ctx->assignmentOperator()->accept(this).as<ast::AssignOp>();
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(new ast::AssignmentStmt(
            get_pos(ctx), std::move(var), op, std::move(exp)));
    }

    // assignmentStatement: (classicalAssignment | quantumMeasurementAssignment) SEMICOLON;
    virtual antlrcpp::Any visitAssignmentStatement(
        qasm3Parser::AssignmentStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // returnSignature: ARROW classicalType;
    virtual antlrcpp::Any
    visitReturnSignature(qasm3Parser::ReturnSignatureContext* ctx) override {
        return ctx->classicalType()->accept(this);
    }

    // designator: LBRACKET expression RBRACKET;
    virtual antlrcpp::Any
    visitDesignator(qasm3Parser::DesignatorContext* ctx) override {
        return ctx->expression()->accept(this);
    }

    // identifierList: Identifier (COMMA Identifier)*;
    virtual antlrcpp::Any
    visitIdentifierList(qasm3Parser::IdentifierListContext* ctx) override {
        std::vector<std::string> ids;
        for (auto x : ctx->Identifier())
            ids.push_back(x->getText());
        return ids;
    }

    // quantumDeclaration: QREG Identifier designator? | QUBIT designator? Identifier;
    virtual antlrcpp::Any visitQuantumDeclaration(
        qasm3Parser::QuantumDeclarationContext* ctx) override {
        ast::ptr<ast::QuantumType> tmp;
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            tmp = ast::ptr<ast::QuantumType>(
                new ast::QubitType(get_pos(ctx), std::move(size)));
        } else {
            tmp = ast::ptr<ast::QuantumType>(new ast::QubitType(get_pos(ctx)));
        }
        return ast::ptr<ast::GlobalStmt>(new ast::QuantumDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp)));
    }

    // quantumArgument: QREG Identifier designator? | QUBIT designator? Identifier;
    virtual antlrcpp::Any
    visitQuantumArgument(qasm3Parser::QuantumArgumentContext* ctx) override {
        ast::ptr<ast::QuantumType> tmp;
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            tmp = ast::ptr<ast::QuantumType>(
                new ast::QubitType(get_pos(ctx), std::move(size)));
        } else {
            tmp = ast::ptr<ast::QuantumType>(new ast::QubitType(get_pos(ctx)));
        }
        return ast::QuantumParam::create(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
    }

    // bitType: (BIT | CREG) designator?;
    virtual antlrcpp::Any
    visitBitType(qasm3Parser::BitTypeContext* ctx) override {
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::BitType::create(get_pos(ctx), std::move(size));
        } else
            return ast::BitType::create(get_pos(ctx));
    }

    // singleDesignatorType: (INT | UINT | FLOAT | ANGLE) designator?;
    virtual antlrcpp::Any visitSingleDesignatorType(
        qasm3Parser::SingleDesignatorTypeContext* ctx) override {
        ast::SDType type;
        if (ctx->INT())
            type = ast::SDType::Int;
        else if (ctx->UINT())
            type = ast::SDType::Uint;
        else if (ctx->FLOAT())
            type = ast::SDType::Float;
        else
            type = ast::SDType::Angle;
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::SingleDesignatorType::create(get_pos(ctx), type,
                                                     std::move(size));
        } else
            return ast::SingleDesignatorType::create(get_pos(ctx), type);
    }

    // noDesignatorType: BOOL | DURATION | STRETCH;
    virtual antlrcpp::Any
    visitNoDesignatorType(qasm3Parser::NoDesignatorTypeContext* ctx) override {
        ast::NDType type;
        if (ctx->BOOL())
            type = ast::NDType::Bool;
        else if (ctx->DURATION())
            type = ast::NDType::Duration;
        else
            type = ast::NDType::Stretch;
        return ast::NoDesignatorType::create(get_pos(ctx), type);
    }

    // nonArrayType
    //  : singleDesignatorType
    //  | noDesignatorType
    //  | bitType
    //  | COMPLEX LBRACKET numericType RBRACKET
    virtual antlrcpp::Any
    visitNonArrayType(qasm3Parser::NonArrayTypeContext* ctx) override {
        if (ctx->singleDesignatorType()) {
            return ast::ptr<ast::NonArrayType>(
                std::move(ctx->singleDesignatorType()
                             ->accept(this)
                             .as<ast::ptr<ast::SingleDesignatorType>>()));
        } else if (ctx->noDesignatorType()) {
            return ast::ptr<ast::NonArrayType>(
                std::move(ctx->noDesignatorType()
                              ->accept(this)
                              .as<ast::ptr<ast::NoDesignatorType>>()));
        } else if (ctx->bitType()) {
            return ast::ptr<ast::NonArrayType>(
                std::move(ctx->bitType()
                              ->accept(this)
                              .as<ast::ptr<ast::BitType>>()));
        } else {
            auto subtype =
                std::move(ctx->numericType()
                              ->accept(this)
                              .as<ast::ptr<ast::SingleDesignatorType>>());
            return ast::ptr<ast::NonArrayType>(
                new ast::ComplexType(get_pos(ctx), std::move(subtype)));
        }
    }

    // arrayType: ARRAY LBRACKET nonArrayType COMMA expressionList RBRACKET;
    virtual antlrcpp::Any visitArrayType(qasm3Parser::ArrayTypeContext *ctx) override {
        auto subtype =
            std::move(ctx->nonArrayType()
                          ->accept(this)
                          .as<ast::ptr<ast::NonArrayType>>());
        auto dimensions =
            std::move(ctx->expressionList()
                          ->accept(this)
                          .as<std::vector<ast::ptr<ast::Expr>>>());
        return ast::ArrayType::create(get_pos(ctx), std::move(subtype),
                                      std::move(dimensions));
    }

    // arrayReferenceTypeDimensionSpecifier
    //  : expressionList
    //  | DIM EQUALS expression
    virtual antlrcpp::Any visitArrayReferenceTypeDimensionSpecifier(qasm3Parser::ArrayReferenceTypeDimensionSpecifierContext *ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // arrayReferenceType: ARRAY LBRACKET nonArrayType COMMA arrayReferenceTypeDimensionSpecifier RBRACKET;
    virtual antlrcpp::Any visitArrayReferenceType(qasm3Parser::ArrayReferenceTypeContext *ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // classicalType
    //  : nonArrayType
    //  | arrayType
    virtual antlrcpp::Any visitClassicalType(qasm3Parser::ClassicalTypeContext *ctx) override {
        if (ctx->nonArrayType()) {
            return ast::ptr<ast::ClassicalType>(
                std::move(ctx->nonArrayType()
                              ->accept(this)
                              .as<ast::ptr<ast::NonArrayType>>()));
        } else {
            return ast::ptr<ast::ClassicalType>(
                std::move(ctx->arrayType()
                              ->accept(this)
                              .as<ast::ptr<ast::ArrayType>>()));
        }
    }

    // numericType: singleDesignatorType;
    virtual antlrcpp::Any visitNumericType(qasm3Parser::NumericTypeContext *ctx) override {
        return ctx->singleDesignatorType()->accept(this);
    }

    // constantDeclaration: CONST classicalType Identifier equalsExpression;
    virtual antlrcpp::Any visitConstantDeclaration(
        qasm3Parser::ConstantDeclarationContext* ctx) override {
        // constantDeclaration : 'const' classicalType Identifier
        //                       equalsExpression
        auto type = std::move(ctx->classicalType()
                                  ->accept(this)
                                  .as<ast::ptr<ast::ClassicalType>>());
        auto exp = std::move(
            ctx->equalsExpression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp), true));
    }

    // singleDesignatorDeclaration: singleDesignatorType Identifier equalsExpression?;
    virtual antlrcpp::Any visitSingleDesignatorDeclaration(
        qasm3Parser::SingleDesignatorDeclarationContext* ctx) override {
        auto type = std::move(ctx->singleDesignatorType()->accept(this).as<ast::ptr<ast::SingleDesignatorType>>());
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->equalsExpression())
            exp = std::move(ctx->equalsExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp)));
    }

    // noDesignatorDeclaration: noDesignatorType Identifier equalsExpression?;
    virtual antlrcpp::Any visitNoDesignatorDeclaration(qasm3Parser::NoDesignatorDeclarationContext *ctx) override {
        auto type = std::move(ctx->noDesignatorType()->accept(this).as<ast::ptr<ast::NoDesignatorType>>());
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->equalsExpression())
            exp = std::move(ctx->equalsExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp)));
    }

    // bitDeclaration: ( CREG Identifier designator? | BIT designator? Identifier ) equalsExpression?;
    virtual antlrcpp::Any
    visitBitDeclaration(qasm3Parser::BitDeclarationContext* ctx) override {
        ast::ptr<ast::ClassicalType> tmp;
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            tmp = ast::ptr<ast::ClassicalType>(
                new ast::BitType(get_pos(ctx), std::move(size)));
        } else {
            tmp = ast::ptr<ast::ClassicalType>(new ast::BitType(get_pos(ctx)));
        }
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->equalsExpression())
            exp = std::move(ctx->equalsExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(tmp), std::move(exp)));
    }

    // complexDeclaration: COMPLEX LBRACKET numericType RBRACKET Identifier equalsExpression?;
    virtual antlrcpp::Any visitComplexDeclaration(
        qasm3Parser::ComplexDeclarationContext* ctx) override {
        auto subtype =
            std::move(ctx->numericType()
                          ->accept(this)
                          .as<ast::ptr<ast::SingleDesignatorType>>());
        auto tmp = ast::ptr<ast::ClassicalType>(
            new ast::ComplexType(get_pos(ctx), std::move(subtype)));
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->equalsExpression())
            exp = std::move(ctx->equalsExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(tmp), std::move(exp)));
    }

    // arrayInitializer:
    //    LBRACE
    //    (expression | arrayInitializer)
    //    (COMMA (expression | arrayInitializer))*
    //    RBRACE;
    virtual antlrcpp::Any visitArrayInitializer(qasm3Parser::ArrayInitializerContext *ctx) override {
        std::vector<ast::ptr<ast::Expr>> arr;
        for (auto& child : ctx->children) {
            auto a = child->accept(this);
            if (a.isNotNull())
                arr.emplace_back(
                    std::move(a.as<ast::ptr<ast::Expr>>()));
        }
        return ast::ArrayInitExpr::create(get_pos(ctx), std::move(arr));
    }

    // arrayDeclaration: arrayType Identifier (EQUALS (arrayInitializer | expression))?;
    virtual antlrcpp::Any visitArrayDeclaration(qasm3Parser::ArrayDeclarationContext *ctx) override {
        auto type = std::move(ctx->arrayType()->accept(this).as<ast::ptr<ast::ArrayType>>());
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->arrayInitializer()) {
            exp = std::move(ctx->arrayInitializer()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        } else if (ctx->expression()) {
            exp = std::move(ctx->expression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        }
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp)));
    }

    // classicalDeclaration
    //    : singleDesignatorDeclaration
    //    | noDesignatorDeclaration
    //    | bitDeclaration
    //    | complexDeclaration
    //    | arrayDeclaration
    virtual antlrcpp::Any visitClassicalDeclaration(
        qasm3Parser::ClassicalDeclarationContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // classicalTypeList: classicalType (COMMA classicalType)*;
    virtual antlrcpp::Any visitClassicalTypeList(
        qasm3Parser::ClassicalTypeListContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalType>> types;
        for (auto x : ctx->classicalType())
            types.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::ClassicalType>>()));
        return types;
    }

    // classicalArgument
    //    : (singleDesignatorType | noDesignatorType) Identifier
    //    | CREG Identifier designator?
    //    | BIT designator? Identifier
    //    | COMPLEX LBRACKET numericType RBRACKET Identifier
    //    | (CONST | MUTABLE) arrayReferenceType Identifier
    virtual antlrcpp::Any visitClassicalArgument(
        qasm3Parser::ClassicalArgumentContext* ctx) override {
        if (ctx->singleDesignatorType()) {
            auto type =
                std::move(ctx->singleDesignatorType()
                              ->accept(this)
                              .as<ast::ptr<ast::SingleDesignatorType>>());
            return ast::ClassicalParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(type));
        } else if (ctx->noDesignatorType()) {
            auto type =
                std::move(ctx->noDesignatorType()
                              ->accept(this)
                              .as<ast::ptr<ast::NoDesignatorType>>());
            return ast::ClassicalParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(type));
        } else if (ctx->numericType()) {
            auto subtype =
                std::move(ctx->numericType()
                              ->accept(this)
                              .as<ast::ptr<ast::SingleDesignatorType>>());
            auto tmp = ast::ptr<ast::ClassicalType>(
                new ast::ComplexType(get_pos(ctx), std::move(subtype)));
            return ast::ClassicalParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
        } else if (ctx->arrayReferenceType()) {
            auto typectx = ctx->arrayReferenceType();
            auto subtype =
                std::move(typectx->nonArrayType()
                                  ->accept(this)
                                  .as<ast::ptr<ast::NonArrayType>>());
            auto dimctx = typectx->arrayReferenceTypeDimensionSpecifier();
            std::variant<std::vector<ast::ptr<ast::Expr>>,
                ast::ptr<ast::Expr>> dims;
            if (dimctx->expressionList()) {
                dims = std::move(dimctx->expressionList()
                                     ->accept(this)
                                     .as<std::vector<ast::ptr<ast::Expr>>>());
            } else {
                dims = std::move(dimctx->expression()
                                     ->accept(this)
                                     .as<ast::ptr<ast::Expr>>());
            }
            auto tmp = ast::ptr<ast::ClassicalType>(
                new ast::ArrayRefType(get_pos(typectx), std::move(subtype),
                                      std::move(dims),
                                      ctx->MUTABLE()));
            return ast::ClassicalParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
        } else {
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                auto tmp = ast::ptr<ast::ClassicalType>(
                    new ast::BitType(get_pos(ctx), std::move(size)));
                return ast::ClassicalParam::create(
                    get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
            } else {
                auto tmp = ast::ptr<ast::ClassicalType>(
                    new ast::BitType(get_pos(ctx)));
                return ast::ClassicalParam::create(
                    get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
            }
        }
    }

    // classicalArgumentList: classicalArgument (COMMA classicalArgument)*;
    virtual antlrcpp::Any visitClassicalArgumentList(
        qasm3Parser::ClassicalArgumentListContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalParam>> params;
        for (auto x : ctx->classicalArgument())
            params.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::ClassicalParam>>()));
        return params;
    }

    // anyTypeArgument: classicalArgument | quantumArgument;
    virtual antlrcpp::Any
    visitAnyTypeArgument(qasm3Parser::AnyTypeArgumentContext* ctx) override {
        if (ctx->classicalArgument())
            return ast::ptr<ast::Param>(
                std::move(ctx->classicalArgument()
                              ->accept(this)
                              .as<ast::ptr<ast::ClassicalParam>>()));
        else
            return ast::ptr<ast::Param>(
                std::move(ctx->quantumArgument()
                              ->accept(this)
                              .as<ast::ptr<ast::QuantumParam>>()));
    }

    // anyTypeArgumentList: anyTypeArgument (COMMA anyTypeArgument)*;
    virtual antlrcpp::Any visitAnyTypeArgumentList(
        qasm3Parser::AnyTypeArgumentListContext* ctx) override {
        std::vector<ast::ptr<ast::Param>> params;
        for (auto x : ctx->anyTypeArgument())
            params.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Param>>()));
        return params;
    }

    // aliasInitializer: expression (DOUBLE_PLUS expression)*;
    virtual antlrcpp::Any visitAliasInitializer(qasm3Parser::AliasInitializerContext *ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // aliasStatement: LET Identifier EQUALS aliasInitializer SEMICOLON;
    virtual antlrcpp::Any visitAliasStatement(qasm3Parser::AliasStatementContext *ctx) override {
        std::vector<ast::ptr<ast::Expr>> regs;
        for (auto x : ctx->aliasInitializer()->expression())
            regs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        return ast::ptr<ast::Stmt>(new ast::AliasStmt(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(regs)));
    }

    // rangeDefinition: expression? COLON expression? (COLON expression)?;
    virtual antlrcpp::Any
    visitRangeDefinition(qasm3Parser::RangeDefinitionContext* ctx) override {
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
        auto c = ctx->children[index]->accept(this);
        if (c.isNotNull()) {
            std::get<2>(range) = std::move(c.as<ast::ptr<ast::Expr>>());
            ++index;
        }
        return range;
    }

    // quantumGateDefinition
    //    : GATE quantumGateSignature quantumBlock
    virtual antlrcpp::Any visitQuantumGateDefinition(
        qasm3Parser::QuantumGateDefinitionContext* ctx) override {
        auto sigctx = ctx->quantumGateSignature();
        auto idlists = sigctx->identifierList();
        std::vector<std::string> c_params;
        if (idlists.size() > 1)
            c_params = std::move(
                idlists.front()->accept(this).as<std::vector<std::string>>());
        auto q_params = std::move(
            idlists.back()->accept(this).as<std::vector<std::string>>());
        auto body = std::move(ctx->quantumBlock()
                                  ->accept(this)
                                  .as<ast::ptr<ast::QuantumBlock>>());
        return ast::ptr<ast::GlobalStmt>(new ast::GateDecl(
            get_pos(ctx), sigctx->quantumGateName()->getText(), c_params,
            q_params, std::move(body)));
    }

    // quantumGateSignature
    //    : quantumGateName ( LPAREN identifierList? RPAREN )? identifierList
    virtual antlrcpp::Any visitQuantumGateSignature(
        qasm3Parser::QuantumGateSignatureContext* ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // quantumGateName: U_ | CX | Identifier;
    virtual antlrcpp::Any
    visitQuantumGateName(qasm3Parser::QuantumGateNameContext* ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // quantumBlock
    //    : LBRACE ( quantumStatement | quantumLoop )* RBRACE
    virtual antlrcpp::Any
    visitQuantumBlock(qasm3Parser::QuantumBlockContext* ctx) override {
        std::list<ast::ptr<ast::QuantumStmt>> body;
        for (auto& child : ctx->children) {
            auto a = child->accept(this);
            if (a.isNotNull())
                body.emplace_back(
                    std::move(a.as<ast::ptr<ast::QuantumStmt>>()));
        }
        return ast::QuantumBlock::create(get_pos(ctx), std::move(body));
    }

    // quantumLoop
    //    : loopSignature quantumLoopBlock
    virtual antlrcpp::Any
    visitQuantumLoop(qasm3Parser::QuantumLoopContext* ctx) override {
        auto body = std::move(ctx->quantumLoopBlock()
                                  ->accept(this)
                                  .as<ast::ptr<ast::QuantumBlock>>());
        auto sigctx = ctx->loopSignature();
        if (sigctx->Identifier()) {
            std::string var = sigctx->Identifier()->getText();
            auto set = std::move(sigctx->setDeclaration()
                                     ->accept(this)
                                     .as<ast::ptr<ast::IndexSet>>());
            return ast::ptr<ast::QuantumStmt>(new ast::QuantumForStmt(
                get_pos(ctx), var, std::move(set), std::move(body)));
        } else {
            auto cond = std::move(
                sigctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::QuantumStmt>(new ast::QuantumWhileStmt(
                get_pos(ctx), std::move(cond), std::move(body)));
        }
    }

    // quantumLoopBlock
    //    : quantumStatement
    //    | LBRACE quantumStatement* RBRACE
    virtual antlrcpp::Any
    visitQuantumLoopBlock(qasm3Parser::QuantumLoopBlockContext* ctx) override {
        std::list<ast::ptr<ast::QuantumStmt>> body;
        for (auto& qstmt : ctx->quantumStatement())
            body.emplace_back(std::move(
                qstmt->accept(this).as<ast::ptr<ast::QuantumStmt>>()));
        return ast::QuantumBlock::create(get_pos(ctx), std::move(body));
    }

    // quantumStatement
    //    : quantumInstruction SEMICOLON
    //    | timingStatement
    virtual antlrcpp::Any
    visitQuantumStatement(qasm3Parser::QuantumStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // quantumInstruction
    //    : quantumGateCall
    //    | quantumPhase
    //    | quantumMeasurement
    //    | quantumReset
    //    | quantumBarrier
    virtual antlrcpp::Any visitQuantumInstruction(
        qasm3Parser::QuantumInstructionContext* ctx) override {
        if (ctx->quantumMeasurement()) {
            auto msmt = std::move(ctx->quantumMeasurement()
                                      ->accept(this)
                                      .as<ast::ptr<ast::QuantumMeasurement>>());
            return ast::ptr<ast::QuantumStmt>(
                new ast::MeasureStmt(get_pos(ctx), std::move(msmt)));
        } else
            return ctx->children[0]->accept(this);
    }

    // quantumBarrier: BARRIER (indexedIdentifier (COMMA indexedIdentifier)*)?;
    virtual antlrcpp::Any
    visitQuantumBarrier(qasm3Parser::QuantumBarrierContext* ctx) override {
        std::vector<ast::ptr<ast::IndexId>> args;
        for (auto& arg : ctx->indexedIdentifier())
            args.emplace_back(std::move(
                arg->accept(this).as<ast::ptr<ast::IndexId>>()));
        return ast::ptr<ast::QuantumStmt>(
            new ast::BarrierStmt(get_pos(ctx), std::move(args)));
    }

    // quantumMeasurement: MEASURE indexedIdentifier;
    virtual antlrcpp::Any visitQuantumMeasurement(
        qasm3Parser::QuantumMeasurementContext* ctx) override {
        auto id = std::move(
            ctx->indexedIdentifier()->accept(this).as<ast::ptr<ast::IndexId>>());
        return ast::QuantumMeasurement::create(get_pos(ctx), std::move(id));
    }

    // quantumPhase: quantumGateModifier* GPHASE LPAREN expression RPAREN (indexedIdentifier (COMMA indexedIdentifier)*)?;
    virtual antlrcpp::Any
    visitQuantumPhase(qasm3Parser::QuantumPhaseContext* ctx) override {
        std::list<ast::ptr<ast::GateModifier>> mods;
        for (auto x : ctx->quantumGateModifier())
            mods.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::GateModifier>>()));
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        std::vector<ast::ptr<ast::IndexId>> args;
        for (auto& arg : ctx->indexedIdentifier())
            args.emplace_back(std::move(
                arg->accept(this).as<ast::ptr<ast::IndexId>>()));
        return ast::ptr<ast::QuantumStmt>(new ast::GPhase(
            get_pos(ctx), std::move(mods), std::move(exp), std::move(args)));
    }

    // quantumReset: RESET indexedIdentifier;
    virtual antlrcpp::Any
    visitQuantumReset(qasm3Parser::QuantumResetContext* ctx) override {
        auto arg = std::move(ctx->indexedIdentifier()
                                 ->accept(this)
                                 .as<ast::ptr<ast::IndexId>>());
        return ast::ptr<ast::QuantumStmt>(
            new ast::ResetStmt(get_pos(ctx), std::move(arg)));
    }

    // quantumMeasurementAssignment
    //    : quantumMeasurement (ARROW indexedIdentifier)?
    //    | indexedIdentifier EQUALS quantumMeasurement
    virtual antlrcpp::Any visitQuantumMeasurementAssignment(
        qasm3Parser::QuantumMeasurementAssignmentContext* ctx) override {
        auto msmt = std::move(ctx->quantumMeasurement()
                                  ->accept(this)
                                  .as<ast::ptr<ast::QuantumMeasurement>>());
        if (ctx->indexedIdentifier()) {
            auto id = std::move(ctx->indexedIdentifier()
                                    ->accept(this)
                                    .as<ast::ptr<ast::IndexId>>());
            return ast::ptr<ast::Stmt>(new ast::MeasureAsgnStmt(
                get_pos(ctx), std::move(msmt), std::move(id)));
        } else
            return ast::ptr<ast::QuantumStmt>(
                new ast::MeasureStmt(get_pos(ctx), std::move(msmt)));
    }

    // powModifier: POW LPAREN expression RPAREN;
    virtual antlrcpp::Any
    visitPowModifier(qasm3Parser::PowModifierContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::GateModifier>(
            new ast::PowModifier(get_pos(ctx), std::move(exp)));
    }

    // ctrlModifier: (CTRL | NEGCTRL) ( LPAREN expression RPAREN )?;
    virtual antlrcpp::Any
    visitCtrlModifier(qasm3Parser::CtrlModifierContext* ctx) override {
        if (ctx->expression()) {
            auto exp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::GateModifier>(new ast::CtrlModifier(
                get_pos(ctx), ctx->NEGCTRL(), std::move(exp)));
        } else
            return ast::ptr<ast::GateModifier>(new ast::CtrlModifier(
                get_pos(ctx), ctx->NEGCTRL()));
    }

    // quantumGateModifier: (INV | powModifier | ctrlModifier) AT;
    virtual antlrcpp::Any visitQuantumGateModifier(
        qasm3Parser::QuantumGateModifierContext* ctx) override {
        if (ctx->INV()) {
            return ast::ptr<ast::GateModifier>(
                new ast::InvModifier(get_pos(ctx)));
        } else
            return ctx->children[0]->accept(this);
    }

    // quantumGateCall: quantumGateModifier* quantumGateName (LPAREN expressionList RPAREN)? indexedIdentifier (COMMA indexedIdentifier)*;
    virtual antlrcpp::Any
    visitQuantumGateCall(qasm3Parser::QuantumGateCallContext* ctx) override {
        std::list<ast::ptr<ast::GateModifier>> mods;
        for (auto x : ctx->quantumGateModifier())
            mods.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::GateModifier>>()));
        std::string gatename = ctx->quantumGateName()->getText();
        std::vector<ast::ptr<ast::Expr>> c_args;
        if (ctx->expressionList())
            c_args = std::move(ctx->expressionList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::Expr>>>());
        std::vector<ast::ptr<ast::IndexId>> q_args;
        for (auto& arg : ctx->indexedIdentifier())
            q_args.emplace_back(std::move(
                arg->accept(this).as<ast::ptr<ast::IndexId>>()));

        if (gatename == "U") {
            if (c_args.size() != 3) {
                std::cerr << get_pos(ctx)
                          << ": error: U gate takes exactly 3 classical "
                             "arguments, but got "
                          << c_args.size() << "\n";
                throw std::logic_error("Parsing failed!");
            }
            return ast::ptr<ast::QuantumStmt>(new ast::UGate(
                get_pos(ctx), std::move(mods), std::move(c_args[0]),
                std::move(c_args[1]), std::move(c_args[2]), std::move(q_args)));
        } else if (gatename == "gphase") {
            std::cerr << get_pos(ctx)
                      << ":QuantumPhase was parsed as a QuantumGateCall!\n";
            throw std::logic_error("Parsing error!");
        } else {
            return ast::ptr<ast::QuantumStmt>(
                new ast::DeclaredGate(get_pos(ctx), std::move(mods), gatename,
                                      std::move(c_args), std::move(q_args)));
        }
    }

    // unaryOperator: TILDE | EXCLAMATION_POINT | MINUS;
    virtual antlrcpp::Any
    visitUnaryOperator(qasm3Parser::UnaryOperatorContext* ctx) override {
        if (ctx->TILDE())
            return ast::UnaryOp::BitNot;
        else if (ctx->EXCLAMATION_POINT())
            return ast::UnaryOp::LogicalNot;
        else
            return ast::UnaryOp::Neg;
    }

    // expressionStatement: expression SEMICOLON;
    virtual antlrcpp::Any visitExpressionStatement(
        qasm3Parser::ExpressionStatementContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ExprStmt(get_pos(ctx), std::move(exp)));
    }

    // expression
    //    // include terminator/unary as base cases to simplify parsing
    //    : expressionTerminator
    //    | unaryExpression
    //    // expression hierarchy
    //    | logicalAndExpression
    //    | expression DOUBLE_PIPE logicalAndExpression
    virtual antlrcpp::Any
    visitExpression(qasm3Parser::ExpressionContext* ctx) override {
        if (ctx->expression()) {
            auto lexp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(ctx->logicalAndExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::LogicalOr, std::move(rexp)));
        } else
            return ctx->children[0]->accept(this);
    }

    // logicalAndExpression
    //    : bitOrExpression
    //    | logicalAndExpression DOUBLE_AMPERSAND bitOrExpression
    virtual antlrcpp::Any visitLogicalAndExpression(
        qasm3Parser::LogicalAndExpressionContext* ctx) override {
        if (ctx->logicalAndExpression()) {
            auto lexp = std::move(ctx->logicalAndExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(
                ctx->bitOrExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::LogicalAnd, std::move(rexp)));
        } else
            return ctx->bitOrExpression()->accept(this);
    }

    // bitOrExpression
    //    : xOrExpression
    //    | bitOrExpression PIPE xOrExpression
    virtual antlrcpp::Any
    visitBitOrExpression(qasm3Parser::BitOrExpressionContext* ctx) override {
        if (ctx->bitOrExpression()) {
            auto lexp = std::move(
                ctx->bitOrExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(
                ctx->xOrExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::BitOr, std::move(rexp)));
        } else
            return ctx->xOrExpression()->accept(this);
    }

    // xOrExpression
    //    : bitAndExpression
    //    | xOrExpression CARET bitAndExpression
    virtual antlrcpp::Any
    visitXOrExpression(qasm3Parser::XOrExpressionContext* ctx) override {
        if (ctx->xOrExpression()) {
            auto lexp = std::move(
                ctx->xOrExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(ctx->bitAndExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::XOr, std::move(rexp)));
        } else
            return ctx->bitAndExpression()->accept(this);
    }

    // bitAndExpression
    //    : equalityExpression
    //    | bitAndExpression AMPERSAND equalityExpression
    virtual antlrcpp::Any
    visitBitAndExpression(qasm3Parser::BitAndExpressionContext* ctx) override {
        if (ctx->bitAndExpression()) {
            auto lexp = std::move(ctx->bitAndExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(ctx->equalityExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::BitAnd, std::move(rexp)));
        } else
            return ctx->equalityExpression()->accept(this);
    }

    // equalityExpression
    //    : comparisonExpression
    //    | equalityExpression EqualityOperator comparisonExpression
    virtual antlrcpp::Any visitEqualityExpression(
        qasm3Parser::EqualityExpressionContext* ctx) override {
        if (ctx->equalityExpression()) {
            auto lexp = std::move(ctx->equalityExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::EQ;
            if (ctx->EqualityOperator()->getText() == "!=") {
                op = ast::BinaryOp::NEQ;
            }
            auto rexp = std::move(ctx->comparisonExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->comparisonExpression()->accept(this);
    }

    // comparisonExpression
    //    : bitShiftExpression
    //    | comparisonExpression ComparisonOperator bitShiftExpression
    virtual antlrcpp::Any visitComparisonExpression(
        qasm3Parser::ComparisonExpressionContext* ctx) override {
        if (ctx->comparisonExpression()) {
            auto lexp = std::move(ctx->comparisonExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::GT;
            if (ctx->ComparisonOperator()->getText() == "<") {
                op = ast::BinaryOp::LT;
            } else if (ctx->ComparisonOperator()->getText() == ">=") {
                op = ast::BinaryOp::GTE;
            } else if (ctx->ComparisonOperator()->getText() == "<=") {
                op = ast::BinaryOp::LTE;
            }
            auto rexp = std::move(ctx->bitShiftExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->bitShiftExpression()->accept(this);
    }

    // bitShiftExpression
    //    : additiveExpression
    //    | bitShiftExpression BitshiftOperator additiveExpression
    virtual antlrcpp::Any visitBitShiftExpression(
        qasm3Parser::BitShiftExpressionContext* ctx) override {
        if (ctx->bitShiftExpression()) {
            auto lexp = std::move(ctx->bitShiftExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::LeftBitShift;
            if (ctx->BitshiftOperator()->getText() == ">>")
                op = ast::BinaryOp::RightBitShift;
            auto rexp = std::move(ctx->additiveExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->additiveExpression()->accept(this);
    }

    // additiveExpression
    //    : multiplicativeExpression
    //    | additiveExpression (PLUS | MINUS) multiplicativeExpression
    virtual antlrcpp::Any visitAdditiveExpression(
        qasm3Parser::AdditiveExpressionContext* ctx) override {
        if (ctx->additiveExpression()) {
            auto lexp = std::move(ctx->additiveExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::Plus;
            if (ctx->MINUS())
                op = ast::BinaryOp::Minus;
            auto rexp = std::move(ctx->multiplicativeExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->multiplicativeExpression()->accept(this);
    }

    // multiplicativeExpression
    //    // base case either terminator or unary
    //    : unaryExpression
    //    | multiplicativeExpression (ASTERISK | SLASH | PERCENT) unaryExpression
    virtual antlrcpp::Any visitMultiplicativeExpression(
        qasm3Parser::MultiplicativeExpressionContext* ctx) override {
        if (ctx->multiplicativeExpression()) {
            auto lexp = std::move(ctx->multiplicativeExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::Times;
            if (ctx->SLASH())
                op = ast::BinaryOp::Divide;
            else if (ctx->PERCENT())
                op = ast::BinaryOp::Mod;
            auto rexp = std::move(
                ctx->unaryExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->unaryExpression()->accept(this);
    }

    // unaryExpression: unaryOperator? powerExpression;
    virtual antlrcpp::Any
    visitUnaryExpression(qasm3Parser::UnaryExpressionContext* ctx) override {
        if (ctx->unaryOperator()) {
            auto op = ctx->unaryOperator()->accept(this).as<ast::UnaryOp>();
            auto exp = std::move(
                ctx->powerExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::UExpr(get_pos(ctx), op, std::move(exp)));
        } else
            return ctx->powerExpression()->accept(this);
    }

    // powerExpression
    //    : indexExpression
    //    | powerExpression DOUBLE_ASTERISK indexExpression
    virtual antlrcpp::Any
    visitPowerExpression(qasm3Parser::PowerExpressionContext* ctx) override {
        if (ctx->powerExpression()) {
            auto lexp = std::move(ctx->powerExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(
                ctx->indexExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::Pow, std::move(rexp)));
        } else
            return ctx->indexExpression()->accept(this);
    }

    // indexOperator:
    //    LBRACKET
    //    (
    //        discreteSet
    //        | (expression | rangeDefinition) (COMMA (expression | rangeDefinition))*
    //    )
    //    RBRACKET;
    virtual antlrcpp::Any visitIndexOperator(qasm3Parser::IndexOperatorContext *ctx) override {
        if (ctx->discreteSet()) {
            std::vector<ast::ptr<ast::Expr>> indices;
            for (auto x : ctx->discreteSet()->expression())
                indices.emplace_back(
                    std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
            return ast::ptr<ast::IndexOp>(
                new ast::ListSlice(get_pos(ctx), std::move(indices)));
        } else {
            std::vector<ast::ptr<ast::IndexEntity>> indices;
            for (auto& child : ctx->children) {
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

    // indexExpression
    //    : expressionTerminator
    //    | indexExpression indexOperator
    virtual antlrcpp::Any visitIndexExpression(qasm3Parser::IndexExpressionContext *ctx) override {
        if (ctx->indexOperator()) {
            auto exp = std::move(ctx->indexExpression()
                                     ->accept(this)
                                     .as<ast::ptr<ast::Expr>>());
            auto op = std::move(ctx->indexOperator()
                                    ->accept(this)
                                    .as<ast::ptr<ast::IndexOp>>());
            return ast::ptr<ast::Expr>(new ast::AccessExpr(
                get_pos(ctx), std::move(exp), std::move(op)));
        } else
            return ctx->expressionTerminator()->accept(this);
    }

    // indexedIdentifier: Identifier indexOperator*;
    virtual antlrcpp::Any visitIndexedIdentifier(qasm3Parser::IndexedIdentifierContext *ctx) override {
        std::vector<ast::ptr<ast::IndexOp>> ops;
        for (auto x : ctx->indexOperator())
            ops.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::IndexOp>>()));
        return ast::IndexId::create(get_pos(ctx), ctx->Identifier()->getText(),
                                    std::move(ops));
    }

    // expressionTerminator
    //    : Constant
    //    | BinaryIntegerLiteral
    //    | OctalIntegerLiteral
    //    | DecimalIntegerLiteral
    //    | HexIntegerLiteral
    //    | FloatLiteral
    //    | ImaginaryLiteral
    //    | BooleanLiteral
    //    | BitstringLiteral
    //    | Identifier
    //    | builtInCall
    //    | externOrSubroutineCall
    //    | timingIdentifier
    //    | LPAREN expression RPAREN
    virtual antlrcpp::Any visitExpressionTerminator(
        qasm3Parser::ExpressionTerminatorContext* ctx) override {
        if (ctx->expression()) {
            return ctx->expression()->accept(this);
        } else if (ctx->Constant()) {
            std::string text = ctx->Constant()->getText();
            if (text == "pi" || text == "π")
                return ast::ptr<ast::Expr>(
                    new ast::ConstantExpr(get_pos(ctx), ast::Constant::Pi));
            else if (text == "tau" || text == "τ")
                return ast::ptr<ast::Expr>(
                    new ast::ConstantExpr(get_pos(ctx), ast::Constant::Tau));
            else
                return ast::ptr<ast::Expr>(
                    new ast::ConstantExpr(get_pos(ctx), ast::Constant::Euler));
        } else if (ctx->BinaryIntegerLiteral()) {
            std::string text = ctx->BinaryIntegerLiteral()->getText().substr(2);
            remove_underscores(text);
            return ast::ptr<ast::Expr>(new ast::IntExpr(
                get_pos(ctx), std::stoi(text, nullptr, 2)));
        } else if (ctx->OctalIntegerLiteral()) {
            std::string text = ctx->OctalIntegerLiteral()->getText().substr(2);
            remove_underscores(text);
            return ast::ptr<ast::Expr>(new ast::IntExpr(
                get_pos(ctx), std::stoi(text, nullptr, 8)));
        } else if (ctx->DecimalIntegerLiteral()) {
            std::string text = ctx->DecimalIntegerLiteral()->getText();
            remove_underscores(text);
            return ast::ptr<ast::Expr>(new ast::IntExpr(
                get_pos(ctx), std::stoi(text)));
        } else if (ctx->HexIntegerLiteral()) {
            std::string text = ctx->HexIntegerLiteral()->getText().substr(2);
            remove_underscores(text);
            return ast::ptr<ast::Expr>(new ast::IntExpr(
                get_pos(ctx), std::stoi(text, nullptr, 16)));
        } else if (ctx->FloatLiteral()) {
            std::string text = ctx->FloatLiteral()->getText();
            remove_underscores(text);
            return ast::ptr<ast::Expr>(new ast::RealExpr(
                get_pos(ctx), std::stod(text)));
        } else if (ctx->ImaginaryLiteral()) {
            std::string imag =
                ctx->ImaginaryLiteral()->getText(); // "3.5im", "12im", etc
            imag.pop_back();
            imag.pop_back();
            remove_underscores(imag);
            return ast::ptr<ast::Expr>(
                new ast::ImagExpr(get_pos(ctx), std::stod(imag)));
        } else if (ctx->BooleanLiteral()) {
            return ast::ptr<ast::Expr>(
                new ast::BoolExpr(get_pos(ctx), ctx->BooleanLiteral()->getText() == "true"));
        } else if (ctx->BitstringLiteral()) {
            std::string bitstring = ctx->BitstringLiteral()->getText();
            remove_underscores(bitstring);
            return ast::ptr<ast::Expr>(new ast::BitString(
                get_pos(ctx), bitstring));
        } else if (ctx->Identifier()) {
            return ast::ptr<ast::Expr>(
                new ast::VarExpr(get_pos(ctx), ctx->Identifier()->getText()));
        } else
            return ctx->children[0]->accept(this);
    }

    // builtInCall: (BuiltinMath | castOperator | SIZEOF) LPAREN expressionList RPAREN;
    virtual antlrcpp::Any
    visitBuiltInCall(qasm3Parser::BuiltInCallContext* ctx) override {
        auto args = std::move(ctx->expressionList()
                                  ->accept(this)
                                  .as<std::vector<ast::ptr<ast::Expr>>>());
        if (ctx->BuiltinMath()) {
            std::string op_str = ctx->BuiltinMath()->getText();
            ast::MathOp op = ast::MathOp::Arccos;
            if (op_str == "arcsin") op = ast::MathOp::Arcsin;
            else if (op_str == "arctan") op = ast::MathOp::Arctan;
            else if (op_str == "cos") op = ast::MathOp::Cos;
            else if (op_str == "exp") op = ast::MathOp::Exp;
            else if (op_str == "ln") op = ast::MathOp::Ln;
            else if (op_str == "popcount") op = ast::MathOp::Popcount;
            else if (op_str == "rotl") op = ast::MathOp::Rotl;
            else if (op_str == "rotr") op = ast::MathOp::Rotr;
            else if (op_str == "sin") op = ast::MathOp::Sin;
            else if (op_str == "sqrt") op = ast::MathOp::Sqrt;
            else if (op_str == "tan") op = ast::MathOp::Tan;
            return ast::ptr<ast::Expr>(
                new ast::MathExpr(get_pos(ctx), op, std::move(args)));
        } else if (ctx->castOperator()) {
            if (args.size() != 1) {
                std::cerr << get_pos(ctx)
                          << ": error: Casting operator takes exactly one "
                             "argument, but got "
                          << args.size() << "\n";
                throw std::logic_error("Parsing failed!");
            }
            auto type = std::move(ctx->castOperator()
                                      ->accept(this)
                                      .as<ast::ptr<ast::ClassicalType>>());
            return ast::ptr<ast::Expr>(new ast::CastExpr(
                get_pos(ctx), std::move(type), std::move(args[0])));
        } else {
            if (args.size() == 1) {
                return ast::ptr<ast::Expr>(new ast::SizeofExpr(
                    get_pos(ctx), std::move(args[0])));
            } else if (args.size() == 1) {
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
    }

    // castOperator: classicalType;
    virtual antlrcpp::Any
    visitCastOperator(qasm3Parser::CastOperatorContext* ctx) override {
        return ctx->classicalType()->accept(this);
    }

    // expressionList: expression (COMMA expression)*;
    virtual antlrcpp::Any
    visitExpressionList(qasm3Parser::ExpressionListContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> exprs;
        for (auto x : ctx->expression())
            exprs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        return exprs;
    }

    // equalsExpression: EQUALS expression;
    virtual antlrcpp::Any
    visitEqualsExpression(qasm3Parser::EqualsExpressionContext* ctx) override {
        return ctx->expression()->accept(this);
    }

    // assignmentOperator : EQUALS | CompoundAssignmentOperator;
    virtual antlrcpp::Any visitAssignmentOperator(
        qasm3Parser::AssignmentOperatorContext* ctx) override {
        if (ctx->EQUALS())
            return ast::AssignOp::Equals;
        std::string text = ctx->CompoundAssignmentOperator()->getText();
        if (text == "+=")
            return ast::AssignOp::Plus;
        else if (text == "-=")
            return ast::AssignOp::Minus;
        else if (text == "*=")
            return ast::AssignOp::Times;
        else if (text == "/=")
            return ast::AssignOp::Div;
        else if (text == "&=")
            return ast::AssignOp::BitAnd;
        else if (text == "|=")
            return ast::AssignOp::BitOr;
        else if (text == "~=")
            return ast::AssignOp::Tilde;
        else if (text == "^=")
            return ast::AssignOp::XOr;
        else if (text == "<<=")
            return ast::AssignOp::LeftBitShift;
        else if (text == ">>=")
            return ast::AssignOp::RightBitShift;
        else if (text == "%=")
            return ast::AssignOp::Mod;
        else
            return ast::AssignOp::Pow;
    }

    // discreteSet: LBRACE expression (COMMA expression)* RBRACE;
    virtual antlrcpp::Any visitDiscreteSet(qasm3Parser::DiscreteSetContext *ctx) override {
        std::vector<ast::ptr<ast::Expr>> exprs;
        for (auto x : ctx->expression())
            exprs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        return exprs;
    }

    // setDeclaration
    //    : discreteSet
    //    | LBRACKET rangeDefinition RBRACKET
    //    | Identifier
    virtual antlrcpp::Any
    visitSetDeclaration(qasm3Parser::SetDeclarationContext* ctx) override {
        if (ctx->discreteSet()) {
            auto indices =
                std::move(ctx->discreteSet()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::Expr>>>());
            return ast::ptr<ast::IndexSet>(
                new ast::ListSet(get_pos(ctx), std::move(indices)));
        } else if (ctx->rangeDefinition()) {
            auto [start, step, stop] = std::move(
                ctx->rangeDefinition()->accept(this).as<ExprTriplet>());
            return ast::ptr<ast::IndexSet>(
                new ast::RangeSet(get_pos(ctx), std::move(start),
                                  std::move(step), std::move(stop)));
        } else {
            return ast::ptr<ast::IndexSet>(
                new ast::VarSet(get_pos(ctx), ctx->Identifier()->getText()));
        }
    }

    // programBlock
    //    : statement | controlDirective
    //    | LBRACE ( statement | controlDirective )* RBRACE
    virtual antlrcpp::Any
    visitProgramBlock(qasm3Parser::ProgramBlockContext* ctx) override {
        std::list<ast::ptr<ast::Stmt>> body;
        for (auto& child : ctx->children) {
            auto a = child->accept(this);
            if (a.is<ast::ptr<ast::Stmt>>())
                body.emplace_back(std::move(a.as<ast::ptr<ast::Stmt>>()));
            else if (a.is<ast::ptr<ast::ControlStmt>>())
                body.emplace_back(
                    std::move(a.as<ast::ptr<ast::ControlStmt>>()));
        }
        return ast::ProgramBlock::create(get_pos(ctx), std::move(body));
    }

    // branchingStatement: IF LPAREN expression RPAREN programBlock (ELSE programBlock)?;
    virtual antlrcpp::Any visitBranchingStatement(
        qasm3Parser::BranchingStatementContext* ctx) override {
        auto cond = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        auto branches = ctx->programBlock();
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

    // loopSignature
    //    : FOR Identifier IN setDeclaration
    //    | WHILE LPAREN expression RPAREN
    virtual antlrcpp::Any visitLoopSignature(qasm3Parser::LoopSignatureContext *ctx) override {
        return defaultResult(); // handled by parent node in AST
    }

    // loopStatement: loopSignature programBlock;
    virtual antlrcpp::Any
    visitLoopStatement(qasm3Parser::LoopStatementContext* ctx) override {
        auto body = std::move(ctx->programBlock()
                                  ->accept(this)
                                  .as<ast::ptr<ast::ProgramBlock>>());
        auto sigctx = ctx->loopSignature();
        if (sigctx->Identifier()) {
            std::string var = sigctx->Identifier()->getText();
            auto set = std::move(sigctx->setDeclaration()
                                     ->accept(this)
                                     .as<ast::ptr<ast::IndexSet>>());
            return ast::ptr<ast::Stmt>(new ast::ForStmt(
                get_pos(ctx), var, std::move(set), std::move(body)));
        } else {
            auto cond = std::move(
                sigctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Stmt>(new ast::WhileStmt(
                get_pos(ctx), std::move(cond), std::move(body)));
        }
    }

    // endStatement: END SEMICOLON;
    virtual antlrcpp::Any
    visitEndStatement(qasm3Parser::EndStatementContext* ctx) override {
        return ast::ptr<ast::Stmt>(new ast::EndStmt(get_pos(ctx)));
    }

    // returnStatement: RETURN (expression | quantumMeasurement)? SEMICOLON;
    virtual antlrcpp::Any
    visitReturnStatement(qasm3Parser::ReturnStatementContext* ctx) override {
        if (ctx->expression()) {
            auto exp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::ControlStmt>(
                new ast::ReturnStmt(get_pos(ctx), std::move(exp)));
        } else if (ctx->quantumMeasurement()) {
            auto msmt = std::move(ctx->quantumMeasurement()
                                      ->accept(this)
                                      .as<ast::ptr<ast::QuantumMeasurement>>());
            return ast::ptr<ast::ControlStmt>(
                new ast::ReturnStmt(get_pos(ctx), std::move(msmt)));
        } else {
            return ast::ptr<ast::ControlStmt>(
                new ast::ReturnStmt(get_pos(ctx), std::monostate()));
        }
    }

    // controlDirective
    //    : (BREAK| CONTINUE) SEMICOLON
    //    | endStatement
    //    | returnStatement
    virtual antlrcpp::Any
    visitControlDirective(qasm3Parser::ControlDirectiveContext* ctx) override {
        if (ctx->endStatement())
            return ctx->endStatement()->accept(this);
        else if (ctx->returnStatement())
            return ctx->returnStatement()->accept(this);
        else if (ctx->BREAK())
            return ast::ptr<ast::ControlStmt>(new ast::BreakStmt(get_pos(ctx)));
        else
            return ast::ptr<ast::ControlStmt>(new ast::ContinueStmt(get_pos(ctx)));
    }

    // externDeclaration: EXTERN Identifier LPAREN classicalTypeList? RPAREN returnSignature? SEMICOLON;
    virtual antlrcpp::Any visitExternDeclaration(
        qasm3Parser::ExternDeclarationContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalType>> param_types;
        if (ctx->classicalTypeList())
            param_types =
                std::move(ctx->classicalTypeList()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::ClassicalType>>>());
        std::optional<ast::ptr<ast::ClassicalType>> return_type = std::nullopt;
        if (ctx->returnSignature())
            return_type = std::move(ctx->returnSignature()
                                        ->accept(this)
                                        .as<ast::ptr<ast::ClassicalType>>());
        return ast::ptr<ast::GlobalStmt>(new ast::ExternDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(param_types),
            std::move(return_type)));
    }

    // externOrSubroutineCall: Identifier LPAREN expressionList? RPAREN;
    virtual antlrcpp::Any visitExternOrSubroutineCall(
        qasm3Parser::ExternOrSubroutineCallContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> args;
        if (ctx->expressionList())
            args = std::move(ctx->expressionList()
                                 ->accept(this)
                                 .as<std::vector<ast::ptr<ast::Expr>>>());
        return ast::ptr<ast::Expr>(new ast::FunctionCall(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(args)));
    }

    // subroutineDefinition: DEF Identifier LPAREN anyTypeArgumentList? RPAREN returnSignature? subroutineBlock;
    virtual antlrcpp::Any visitSubroutineDefinition(
        qasm3Parser::SubroutineDefinitionContext* ctx) override {
        std::vector<ast::ptr<ast::Param>> params;
        if (ctx->anyTypeArgumentList())
            params = std::move(ctx->anyTypeArgumentList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::Param>>>());
        std::optional<ast::ptr<ast::ClassicalType>> return_type = std::nullopt;
        if (ctx->returnSignature())
            return_type = std::move(ctx->returnSignature()
                                        ->accept(this)
                                        .as<ast::ptr<ast::ClassicalType>>());
        auto body = std::move(ctx->subroutineBlock()
                                  ->accept(this)
                                  .as<ast::ptr<ast::ProgramBlock>>());
        return ast::ptr<ast::GlobalStmt>(new ast::SubroutineDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(params),
            std::move(return_type), std::move(body)));
    }

    // subroutineBlock: LBRACE statement* returnStatement? RBRACE;
    virtual antlrcpp::Any
    visitSubroutineBlock(qasm3Parser::SubroutineBlockContext* ctx) override {
        std::list<ast::ptr<ast::Stmt>> body;
        for (auto& stmt : ctx->statement())
            body.emplace_back(
                std::move(stmt->accept(this).as<ast::ptr<ast::Stmt>>()));
        if (ctx->returnStatement())
            body.emplace_back(std::move(ctx->returnStatement()
                                            ->accept(this)
                                            .as<ast::ptr<ast::ControlStmt>>()));
        return ast::ProgramBlock::create(get_pos(ctx), std::move(body));
    }

    // pragma: PRAGMA LBRACE statement* RBRACE;
    virtual antlrcpp::Any
    visitPragma(qasm3Parser::PragmaContext* ctx) override {
        std::list<ast::ptr<ast::Stmt>> body;
        for (auto& stmt : ctx->statement())
            body.emplace_back(
                std::move(stmt->accept(this).as<ast::ptr<ast::Stmt>>()));
        auto tmp = ast::ProgramBlock::create(get_pos(ctx), std::move(body));
        return ast::ptr<ast::GlobalStmt>(
            new ast::PragmaStmt(get_pos(ctx), std::move(tmp)));
    }

    // timingBox: BOX designator? quantumBlock;
    virtual antlrcpp::Any
    visitTimingBox(qasm3Parser::TimingBoxContext* ctx) override {
        auto body = std::move(ctx->quantumBlock()
                                  ->accept(this)
                                  .as<ast::ptr<ast::QuantumBlock>>());
        if (ctx->designator()) {
            auto duration = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::QuantumStmt>(new ast::BoxStmt(
                get_pos(ctx), std::move(duration), std::move(body)));
        } else
            return ast::ptr<ast::QuantumStmt>(
                new ast::BoxStmt(get_pos(ctx), std::move(body)));
    }

    // timingIdentifier: TimingLiteral | DURATIONOF LPAREN (Identifier | quantumBlock) RPAREN;
    virtual antlrcpp::Any
    visitTimingIdentifier(qasm3Parser::TimingIdentifierContext* ctx) override {
        if (ctx->TimingLiteral()) {
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
        } else if (ctx->Identifier()) {
            return ast::ptr<ast::Expr>(new ast::DurationGateExpr(
                get_pos(ctx), ctx->Identifier()->getText()));
        } else {
            auto body = std::move(ctx->quantumBlock()
                                      ->accept(this)
                                      .as<ast::ptr<ast::QuantumBlock>>());
            return ast::ptr<ast::Expr>(
                new ast::DurationBlockExpr(get_pos(ctx), std::move(body)));
        }
    }

    // timingInstruction: BuiltinTimingInstruction (LPAREN expressionList? RPAREN)?  designator indexedIdentifier (COMMA indexedIdentifier)*;
    virtual antlrcpp::Any visitTimingInstruction(qasm3Parser::TimingInstructionContext *ctx) override {
        std::vector<ast::ptr<ast::Expr>> c_args;
        if (ctx->expressionList())
            c_args = std::move(ctx->expressionList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::Expr>>>());
        auto duration = std::move(
            ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
        std::vector<ast::ptr<ast::IndexId>> q_args;
        for (auto& arg : ctx->indexedIdentifier())
            q_args.emplace_back(std::move(
                arg->accept(this).as<ast::ptr<ast::IndexId>>()));
        if (ctx->BuiltinTimingInstruction()->getText() == "delay")
            return ast::ptr<ast::QuantumStmt>(
                new ast::DelayStmt(get_pos(ctx), std::move(c_args),
                                   std::move(duration), std::move(q_args)));
        else
            return ast::ptr<ast::QuantumStmt>(
                new ast::RotaryStmt(get_pos(ctx), std::move(c_args),
                                    std::move(duration), std::move(q_args)));
    }

    // timingStatement: timingInstruction SEMICOLON | timingBox;
    virtual antlrcpp::Any
    visitTimingStatement(qasm3Parser::TimingStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // calibration: calibrationGrammarDeclaration | calibrationDefinition;
    virtual antlrcpp::Any
    visitCalibration(qasm3Parser::CalibrationContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    // calibrationGrammarDeclaration: DEFCALGRAMMAR StringLiteral SEMICOLON;
    virtual antlrcpp::Any visitCalibrationGrammarDeclaration(
        qasm3Parser::CalibrationGrammarDeclarationContext* ctx) override {
        std::string name = ctx->StringLiteral()->getText();
        return ast::ptr<ast::GlobalStmt>(
            new ast::CalGrammarDecl(get_pos(ctx), name));
    }

    // calibrationDefinition: DEFCAL Identifier (LPAREN calibrationArgumentList? RPAREN)? identifierList returnSignature? LBRACE .*? RBRACE;
    virtual antlrcpp::Any visitCalibrationDefinition(
        qasm3Parser::CalibrationDefinitionContext* ctx) override {
        ast::CalibrationDecl::ParamsType c_params = std::monostate();
        if (ctx->calibrationArgumentList())
            c_params = std::move(ctx->calibrationArgumentList()
                                     ->accept(this)
                                     .as<ast::CalibrationDecl::ParamsType>());
        auto q_params = std::move(
            ctx->identifierList()->accept(this).as<std::vector<std::string>>());
        std::optional<ast::ptr<ast::ClassicalType>> return_type = std::nullopt;
        if (ctx->returnSignature())
            return_type = std::move(ctx->returnSignature()
                                        ->accept(this)
                                        .as<ast::ptr<ast::ClassicalType>>());
        // this does not work, e.g. if the body is { x a; } this only returns
        // the semicolon
        std::string body = ctx->children[ctx->children.size() - 2]->getText();
        return ast::ptr<ast::GlobalStmt>(new ast::CalibrationDecl(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(c_params),
            std::move(q_params), std::move(return_type), body));
    }

    // calibrationArgumentList: classicalArgumentList | expressionList;
    virtual antlrcpp::Any visitCalibrationArgumentList(
        qasm3Parser::CalibrationArgumentListContext* ctx) override {
        if (ctx->classicalArgumentList())
            return ast::CalibrationDecl::ParamsType(std::move(
                ctx->classicalArgumentList()
                    ->accept(this)
                    .as<std::vector<ast::ptr<ast::ClassicalParam>>>()));
        else
            return ast::CalibrationDecl::ParamsType(
                std::move(ctx->expressionList()
                              ->accept(this)
                              .as<std::vector<ast::ptr<ast::Expr>>>()));
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
    if (!std::filesystem::exists(fname))
        throw std::logic_error("File \"" + fname + "\" not found!\n");
    antlr4::ANTLRFileStream input;
    input.loadFromFile(fname);
    qasm3Lexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    qasm3Parser parser(&tokens);
    parser.setBuildParseTree(true);
    qasm3Parser::ProgramContext* tree = parser.program();
    if (parser.getNumberOfSyntaxErrors() > 0)
        throw std::logic_error("Parsing failed!");
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
    if (parser.getNumberOfSyntaxErrors() > 0)
        throw std::logic_error("Parsing failed!");
    return ASTConstructor().make_ast(tree);
}

/**
 * \brief Parse a specified file
 */
inline ast::ptr<ast::Program> parse_file(std::string fname) {
    auto result = parse_file_helper(fname);
    //ast::check_source(*result);
    return result;
}

/**
 * \brief Parse a string
 */
inline ast::ptr<ast::Program> parse_string(const std::string& str,
                                           std::string name = "") {
    auto result = parse_string_helper(str, name);
    //ast::check_source(*result);
    return result;
}

} // namespace parser
} // namespace qasm3tools
