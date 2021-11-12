/*
 * This file is part of qasmtools.
 *
 * Copyright (c) 2019 - 2021 softwareQ Inc. All rights reserved.
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
 * \file qasmtools/parser/parser.hpp
 */

#pragma once

#include "../ast/ast.hpp"
#include "antlr4-runtime.h"
#include "position.hpp"
#include "qasm3LexerImpl.hpp"
#include "qasm3ParserImpl.hpp"
#include "qasm3Visitor.h"

#include <filesystem>
#include <fstream>
#include <tuple>

namespace qasmtools {
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
ast::ptr<ast::Program> parse_file(std::string);
ast::ptr<ast::Program> parse_string(const std::string&, std::string);

class ASTConstructor : public qasm3Visitor {
    using ExprTriplet = std::tuple<std::optional<ast::ptr<ast::Expr>>,
                                   std::optional<ast::ptr<ast::Expr>>,
                                   std::optional<ast::ptr<ast::Expr>>>;

  public:
    virtual antlrcpp::Any
    visitProgram(qasm3Parser::ProgramContext* ctx) override {
        // program : header (globalStatement | statement)*
        auto prog = ast::Program::create(get_pos(ctx), {}, false);
        auto includes =
            std::move(ctx->header()
                          ->accept(this)
                          .as<std::vector<ast::ptr<ast::Program>>>());
        for (auto& included : includes) {
            prog->set_includes_std(prog->includes_std() ||
                                   included->includes_std());
            prog->body().insert(
                prog->body().end(),
                std::make_move_iterator(included->body().begin()),
                std::make_move_iterator(included->body().end()));
        }
        std::list<ast::ProgramStmt> body;
        for (auto& child : ctx->children) {
            auto a = child->accept(this);
            if (a.is<ast::ptr<ast::GlobalStmt>>()) {
                prog->body().emplace_back(
                    std::move(a.as<ast::ptr<ast::GlobalStmt>>()));
            } else if (a.is<ast::ptr<ast::Stmt>>()) {
                prog->body().emplace_back(
                    std::move(a.as<ast::ptr<ast::Stmt>>()));
            }
        }
        return prog;
    }

    virtual antlrcpp::Any
    visitHeader(qasm3Parser::HeaderContext* ctx) override {
        // header : version? include* io*
        std::vector<ast::ptr<ast::Program>> includes;
        for (auto& x : ctx->include()) {
            includes.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Program>>()));
        }
        return includes;
    }

    virtual antlrcpp::Any
    visitVersion(qasm3Parser::VersionContext* ctx) override {
        return defaultResult(); // ignored
    }

    virtual antlrcpp::Any
    visitInclude(qasm3Parser::IncludeContext* ctx) override {
        // include : 'include' StringLiteral SEMICOLON
        std::string inc_str = ctx->StringLiteral()->getText();
        std::string fname = inc_str.substr(1, inc_str.length() - 2);
        if (fname == "stdgates.inc") {
            auto prog = parse_string(std_include, fname);
            prog->set_includes_std(true);
            return prog;
        } else {
            return parse_file(fname);
        }
    }

    virtual antlrcpp::Any
    visitIoIdentifier(qasm3Parser::IoIdentifierContext* ctx) override {
        return defaultResult(); // ignored
    }

    virtual antlrcpp::Any visitIo(qasm3Parser::IoContext* ctx) override {
        return defaultResult(); // ignored
    }

    virtual antlrcpp::Any
    visitGlobalStatement(qasm3Parser::GlobalStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any
    visitStatement(qasm3Parser::StatementContext* ctx) override {
        auto a = ctx->children[0]->accept(this);
        if (a.is<ast::ptr<ast::QuantumStmt>>()) {
            return ast::ptr<ast::Stmt>(std::move(
                a.as<ast::ptr<ast::QuantumStmt>>())); // upcast QuantumStmt* to
                                                      // Stmt*
        } else
            return a;
    }

    virtual antlrcpp::Any visitQuantumDeclarationStatement(
        qasm3Parser::QuantumDeclarationStatementContext* ctx) override {
        return ctx->quantumDeclaration()->accept(this);
    }

    virtual antlrcpp::Any visitClassicalDeclarationStatement(
        qasm3Parser::ClassicalDeclarationStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any visitClassicalAssignment(
        qasm3Parser::ClassicalAssignmentContext* ctx) override {
        // classicalAssignment : Identifier designator? assignmentOperator
        // expression
        auto op = ctx->assignmentOperator()->accept(this).as<ast::AssignOp>();
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        if (ctx->designator()) {
            auto indexid = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Stmt>(new ast::AssignmentStmt(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(indexid),
                op, std::move(exp)));
        } else
            return ast::ptr<ast::Stmt>(new ast::AssignmentStmt(
                get_pos(ctx), ctx->Identifier()->getText(), op,
                std::move(exp)));
    }

    virtual antlrcpp::Any visitAssignmentStatement(
        qasm3Parser::AssignmentStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any
    visitReturnSignature(qasm3Parser::ReturnSignatureContext* ctx) override {
        return ctx->classicalType()->accept(this);
    }

    virtual antlrcpp::Any
    visitDesignator(qasm3Parser::DesignatorContext* ctx) override {
        return ctx->expression()->accept(this);
    }

    virtual antlrcpp::Any
    visitIdentifierList(qasm3Parser::IdentifierListContext* ctx) override {
        std::vector<std::string> ids;
        for (auto x : ctx->Identifier())
            ids.push_back(x->getText());
        return ids;
    }

    virtual antlrcpp::Any visitQuantumDeclaration(
        qasm3Parser::QuantumDeclarationContext* ctx) override {
        // quantumDeclaration : 'qreg' Identifier designator? | 'qubit'
        // designator? Identifier
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::GlobalStmt>(new ast::QuantumRegisterDecl(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(size)));
        } else {
            return ast::ptr<ast::GlobalStmt>(new ast::QuantumRegisterDecl(
                get_pos(ctx), ctx->Identifier()->getText()));
        }
    }

    virtual antlrcpp::Any
    visitQuantumArgument(qasm3Parser::QuantumArgumentContext* ctx) override {
        // quantumArgument : 'qreg' Identifier designator? | 'qubit' designator?
        // Identifier
        if (ctx->designator()) {
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::QubitParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(size));
        } else {
            return ast::QubitParam::create(get_pos(ctx),
                                           ctx->Identifier()->getText());
        }
    }

    virtual antlrcpp::Any visitQuantumArgumentList(
        qasm3Parser::QuantumArgumentListContext* ctx) override {
        return defaultResult(); // unused in grammar
    }

    virtual antlrcpp::Any
    visitBitType(qasm3Parser::BitTypeContext* ctx) override {
        return defaultResult(); // redundant in AST
    }

    virtual antlrcpp::Any visitSingleDesignatorType(
        qasm3Parser::SingleDesignatorTypeContext* ctx) override {
        std::string text = ctx->getText();
        if (text == "int")
            return ast::SDType::Int;
        else if (text == "uint")
            return ast::SDType::Uint;
        else if (text == "float")
            return ast::SDType::Float;
        else
            return ast::SDType::Angle;
    }

    virtual antlrcpp::Any
    visitNoDesignatorType(qasm3Parser::NoDesignatorTypeContext* ctx) override {
        std::string text = ctx->getText();
        if (text == "bool")
            return ast::NDType::Bool;
        else if (text == "duration")
            return ast::NDType::Duration;
        else
            return ast::NDType::Stretch;
    }

    virtual antlrcpp::Any
    visitClassicalType(qasm3Parser::ClassicalTypeContext* ctx) override {
        // classicalType : singleDesignatorType designator
        //               | noDesignatorType
        //               | bitType designator?
        //               | 'complex' LBRACKET numericType RBRACKET
        if (ctx->singleDesignatorType()) {
            auto type =
                ctx->singleDesignatorType()->accept(this).as<ast::SDType>();
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::ClassicalType>(new ast::SingleDesignatorType(
                get_pos(ctx), type, std::move(size)));
        } else if (ctx->noDesignatorType()) {
            auto type = ctx->noDesignatorType()->accept(this).as<ast::NDType>();
            return ast::ptr<ast::ClassicalType>(
                new ast::NoDesignatorType(get_pos(ctx), type));
        } else if (ctx->bitType()) {
            if (ctx->designator()) {
                auto size = std::move(
                    ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
                return ast::ptr<ast::ClassicalType>(
                    new ast::BitType(get_pos(ctx), std::move(size)));
            } else {
                return ast::ptr<ast::ClassicalType>(
                    new ast::BitType(get_pos(ctx)));
            }
        } else {
            auto subtype =
                std::move(ctx->numericType()
                              ->accept(this)
                              .as<ast::ptr<ast::SingleDesignatorType>>());
            return ast::ptr<ast::ClassicalType>(
                new ast::ComplexType(get_pos(ctx), std::move(subtype)));
        }
    }

    virtual antlrcpp::Any
    visitNumericType(qasm3Parser::NumericTypeContext* ctx) override {
        // numericType : singleDesignatorType designator
        auto type = ctx->singleDesignatorType()->accept(this).as<ast::SDType>();
        auto size = std::move(
            ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::SingleDesignatorType::create(get_pos(ctx), type,
                                                 std::move(size));
    }

    virtual antlrcpp::Any visitConstantDeclaration(
        qasm3Parser::ConstantDeclarationContext* ctx) override {
        // constantDeclaration : 'const' classicalType Identifier
        // equalsExpression
        auto type = std::move(ctx->classicalType()
                                  ->accept(this)
                                  .as<ast::ptr<ast::ClassicalType>>());
        auto exp = std::move(
            ctx->equalsExpression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(type), std::move(exp), true));
    }

    virtual antlrcpp::Any visitSingleDesignatorDeclaration(
        qasm3Parser::SingleDesignatorDeclarationContext* ctx) override {
        // singleDesignatorDeclaration : singleDesignatorType designator
        // Identifier equalsExpression?
        auto type = ctx->singleDesignatorType()->accept(this).as<ast::SDType>();
        auto size = std::move(
            ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
        auto tmp = ast::ptr<ast::ClassicalType>(
            new ast::SingleDesignatorType(get_pos(ctx), type, std::move(size)));
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->equalsExpression())
            exp = std::move(ctx->equalsExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(tmp), std::move(exp)));
    }

    virtual antlrcpp::Any visitNoDesignatorDeclaration(
        qasm3Parser::NoDesignatorDeclarationContext* ctx) override {
        // noDesignatorDeclaration : noDesignatorType Identifier
        // equalsExpression?
        auto type = ctx->noDesignatorType()->accept(this).as<ast::NDType>();
        auto tmp = ast::ptr<ast::ClassicalType>(
            new ast::NoDesignatorType(get_pos(ctx), type));
        std::optional<ast::ptr<ast::Expr>> exp = std::nullopt;
        if (ctx->equalsExpression())
            exp = std::move(ctx->equalsExpression()
                                ->accept(this)
                                .as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ClassicalDecl(get_pos(ctx), ctx->Identifier()->getText(),
                                   std::move(tmp), std::move(exp)));
    }

    virtual antlrcpp::Any
    visitBitDeclaration(qasm3Parser::BitDeclarationContext* ctx) override {
        // bitDeclaration : ( 'creg' Identifier designator? | 'bit' designator?
        // Identifier ) equalsExpression?
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

    virtual antlrcpp::Any visitComplexDeclaration(
        qasm3Parser::ComplexDeclarationContext* ctx) override {
        // complexDeclaration : 'complex' LBRACKET numericType RBRACKET
        // Identifier equalsExpression?
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

    virtual antlrcpp::Any visitClassicalDeclaration(
        qasm3Parser::ClassicalDeclarationContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any visitClassicalTypeList(
        qasm3Parser::ClassicalTypeListContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalType>> types;
        for (auto x : ctx->classicalType())
            types.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::ClassicalType>>()));
        return types;
    }

    virtual antlrcpp::Any visitClassicalArgument(
        qasm3Parser::ClassicalArgumentContext* ctx) override {
        // classicalArgument : ( singleDesignatorType designator |
        // noDesignatorType ) Identifier
        //                   | 'creg' Identifier designator?
        //                   | 'bit' designator? Identifier
        //                   | 'complex' LBRACKET numericType RBRACKET
        //                   Identifier
        if (ctx->singleDesignatorType()) {
            auto type =
                ctx->singleDesignatorType()->accept(this).as<ast::SDType>();
            auto size = std::move(
                ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
            auto tmp =
                ast::ptr<ast::ClassicalType>(new ast::SingleDesignatorType(
                    get_pos(ctx), type, std::move(size)));
            return ast::ClassicalParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
        } else if (ctx->noDesignatorType()) {
            auto type = ctx->noDesignatorType()->accept(this).as<ast::NDType>();
            auto tmp = ast::ptr<ast::ClassicalType>(
                new ast::NoDesignatorType(get_pos(ctx), type));
            return ast::ClassicalParam::create(
                get_pos(ctx), ctx->Identifier()->getText(), std::move(tmp));
        } else if (ctx->numericType()) {
            auto subtype =
                std::move(ctx->numericType()
                              ->accept(this)
                              .as<ast::ptr<ast::SingleDesignatorType>>());
            auto tmp = ast::ptr<ast::ClassicalType>(
                new ast::ComplexType(get_pos(ctx), std::move(subtype)));
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

    virtual antlrcpp::Any visitClassicalArgumentList(
        qasm3Parser::ClassicalArgumentListContext* ctx) override {
        std::vector<ast::ptr<ast::ClassicalParam>> params;
        for (auto x : ctx->classicalArgument())
            params.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::ClassicalParam>>()));
        return params;
    }

    virtual antlrcpp::Any
    visitAnyTypeArgument(qasm3Parser::AnyTypeArgumentContext* ctx) override {
        // anyTypeArgument : classicalArgument | quantumArgument
        if (ctx->classicalArgument())
            return ast::ptr<ast::Param>(
                std::move(ctx->classicalArgument()
                              ->accept(this)
                              .as<ast::ptr<ast::ClassicalParam>>()));
        else
            return ast::ptr<ast::Param>(
                std::move(ctx->quantumArgument()
                              ->accept(this)
                              .as<ast::ptr<ast::QubitParam>>()));
    }

    virtual antlrcpp::Any visitAnyTypeArgumentList(
        qasm3Parser::AnyTypeArgumentListContext* ctx) override {
        std::vector<ast::ptr<ast::Param>> params;
        for (auto x : ctx->anyTypeArgument())
            params.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Param>>()));
        return params;
    }

    virtual antlrcpp::Any
    visitAliasStatement(qasm3Parser::AliasStatementContext* ctx) override {
        // aliasStatement : 'let' Identifier EQUALS indexIdentifier SEMICOLON
        auto reg = std::move(
            ctx->indexIdentifier()->accept(this).as<ast::ptr<ast::IndexId>>());
        return ast::ptr<ast::Stmt>(new ast::AliasStmt(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(reg)));
    }

    virtual antlrcpp::Any
    visitIndexIdentifier(qasm3Parser::IndexIdentifierContext* ctx) override {
        // indexIdentifier : Identifier rangeDefinition
        //                 | Identifier ( LBRACKET expressionList RBRACKET )?
        //                 | indexIdentifier '||' indexIdentifier
        if (ctx->Identifier()) {
            if (ctx->rangeDefinition()) {
                auto [start, step, stop] = std::move(
                    ctx->rangeDefinition()->accept(this).as<ExprTriplet>());
                return ast::ptr<ast::IndexId>(new ast::VarAccess(
                    get_pos(ctx), ctx->Identifier()->getText(),
                    ast::ptr<ast::Slice>(new ast::RangeSlice(
                        get_pos(ctx->rangeDefinition()), std::move(start),
                        std::move(step), std::move(stop)))));
            } else if (ctx->expressionList()) {
                auto indices =
                    std::move(ctx->expressionList()
                                  ->accept(this)
                                  .as<std::vector<ast::ptr<ast::Expr>>>());
                return ast::ptr<ast::IndexId>(new ast::VarAccess(
                    get_pos(ctx), ctx->Identifier()->getText(),
                    ast::ptr<ast::Slice>(new ast::ListSlice(
                        get_pos(ctx->LBRACKET()), std::move(indices)))));
            } else {
                return ast::ptr<ast::IndexId>(new ast::VarAccess(
                    get_pos(ctx), ctx->Identifier()->getText()));
            }
        } else {
            auto lreg = std::move(
                ctx->children[0]->accept(this).as<ast::ptr<ast::IndexId>>());
            auto rreg = std::move(
                ctx->children[2]->accept(this).as<ast::ptr<ast::IndexId>>());
            return ast::ptr<ast::IndexId>(new ast::Concat(
                get_pos(ctx), std::move(lreg), std::move(rreg)));
        }
    }

    virtual antlrcpp::Any visitIndexIdentifierList(
        qasm3Parser::IndexIdentifierListContext* ctx) override {
        std::vector<ast::ptr<ast::IndexId>> ids;
        for (auto x : ctx->indexIdentifier())
            ids.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::IndexId>>()));
        return ids;
    }

    virtual antlrcpp::Any
    visitRangeDefinition(qasm3Parser::RangeDefinitionContext* ctx) override {
        // rangeDefinition : LBRACKET expression? COLON expression? ( COLON
        // expression )? RBRACKET Return triplet of Expr*, nullptr = no
        // expression
        ExprTriplet range(std::nullopt, std::nullopt, std::nullopt);
        int index = 1;
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

    virtual antlrcpp::Any visitQuantumGateDefinition(
        qasm3Parser::QuantumGateDefinitionContext* ctx) override {
        // quantumGateDefinition : 'gate' quantumGateSignature quantumBlock
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

    virtual antlrcpp::Any visitQuantumGateSignature(
        qasm3Parser::QuantumGateSignatureContext* ctx) override {
        // quantumGateName ( LPAREN identifierList? RPAREN )? identifierList
        return defaultResult(); // handled by parent
    }

    virtual antlrcpp::Any
    visitQuantumGateName(qasm3Parser::QuantumGateNameContext* ctx) override {
        return defaultResult(); // handled by parent
    }

    virtual antlrcpp::Any
    visitQuantumBlock(qasm3Parser::QuantumBlockContext* ctx) override {
        std::list<ast::QuantumBlockStmt> body;
        for (auto& child : ctx->children) {
            auto a = child->accept(this);
            if (a.is<ast::ptr<ast::QuantumStmt>>())
                body.emplace_back(
                    std::move(a.as<ast::ptr<ast::QuantumStmt>>()));
        }
        return ast::QuantumBlock::create(get_pos(ctx), std::move(body));
    }

    virtual antlrcpp::Any
    visitQuantumLoop(qasm3Parser::QuantumLoopContext* ctx) override {
        // quantumLoop : loopSignature quantumLoopBlock
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

    virtual antlrcpp::Any
    visitQuantumLoopBlock(qasm3Parser::QuantumLoopBlockContext* ctx) override {
        // quantumLoopBlock : quantumStatement
        //                  | LBRACE quantumStatement* RBRACE
        std::list<ast::QuantumBlockStmt> body;
        for (auto& qstmt : ctx->quantumStatement())
            body.emplace_back(std::move(
                qstmt->accept(this).as<ast::ptr<ast::QuantumStmt>>()));
        return ast::QuantumBlock::create(get_pos(ctx), std::move(body));
    }

    virtual antlrcpp::Any
    visitQuantumStatement(qasm3Parser::QuantumStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

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
        ;
    }

    virtual antlrcpp::Any
    visitQuantumPhase(qasm3Parser::QuantumPhaseContext* ctx) override {
        // quantumPhase : quantumGateModifier* 'gphase' LPAREN expression RPAREN
        // indexIdentifierList?
        std::list<ast::ptr<ast::GateModifier>> mods;
        for (auto x : ctx->quantumGateModifier())
            mods.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::GateModifier>>()));
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        std::vector<ast::ptr<ast::IndexId>> args;
        if (ctx->indexIdentifierList())
            args = std::move(ctx->indexIdentifierList()
                                 ->accept(this)
                                 .as<std::vector<ast::ptr<ast::IndexId>>>());
        return ast::ptr<ast::QuantumStmt>(new ast::GPhase(
            get_pos(ctx), std::move(mods), std::move(exp), std::move(args)));
    }

    virtual antlrcpp::Any
    visitQuantumReset(qasm3Parser::QuantumResetContext* ctx) override {
        auto args = std::move(ctx->indexIdentifierList()
                                  ->accept(this)
                                  .as<std::vector<ast::ptr<ast::IndexId>>>());
        return ast::ptr<ast::QuantumStmt>(
            new ast::ResetStmt(get_pos(ctx), std::move(args)));
    }

    virtual antlrcpp::Any visitQuantumMeasurement(
        qasm3Parser::QuantumMeasurementContext* ctx) override {
        auto id = std::move(
            ctx->indexIdentifier()->accept(this).as<ast::ptr<ast::IndexId>>());
        return ast::QuantumMeasurement::create(get_pos(ctx), std::move(id));
    }

    virtual antlrcpp::Any visitQuantumMeasurementAssignment(
        qasm3Parser::QuantumMeasurementAssignmentContext* ctx) override {
        // quantumMeasurementAssignment : quantumMeasurement ( ARROW
        // indexIdentifier
        // )?
        //                              | indexIdentifier EQUALS
        //                              quantumMeasurement
        auto msmt = std::move(ctx->quantumMeasurement()
                                  ->accept(this)
                                  .as<ast::ptr<ast::QuantumMeasurement>>());
        if (ctx->indexIdentifier()) {
            auto id = std::move(ctx->indexIdentifier()
                                    ->accept(this)
                                    .as<ast::ptr<ast::IndexId>>());
            return ast::ptr<ast::Stmt>(new ast::MeasureAsgnStmt(
                get_pos(ctx), std::move(msmt), std::move(id)));
        } else
            return ast::ptr<ast::QuantumStmt>(
                new ast::MeasureStmt(get_pos(ctx), std::move(msmt)));
    }

    virtual antlrcpp::Any
    visitQuantumBarrier(qasm3Parser::QuantumBarrierContext* ctx) override {
        std::vector<ast::ptr<ast::IndexId>> args;
        if (ctx->indexIdentifierList())
            args = std::move(ctx->indexIdentifierList()
                                 ->accept(this)
                                 .as<std::vector<ast::ptr<ast::IndexId>>>());
        return ast::ptr<ast::QuantumStmt>(
            new ast::BarrierStmt(get_pos(ctx), std::move(args)));
    }

    virtual antlrcpp::Any visitQuantumGateModifier(
        qasm3Parser::QuantumGateModifierContext* ctx) override {
        if (ctx->children[0]->getText() == "inv") {
            return ast::ptr<ast::GateModifier>(
                new ast::InvModifier(get_pos(ctx)));
        } else
            return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any
    visitPowModifier(qasm3Parser::PowModifierContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::GateModifier>(
            new ast::PowModifier(get_pos(ctx), std::move(exp)));
    }

    virtual antlrcpp::Any
    visitCtrlModifier(qasm3Parser::CtrlModifierContext* ctx) override {
        if (ctx->expression()) {
            auto exp = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::GateModifier>(new ast::CtrlModifier(
                get_pos(ctx), ctx->children[0]->getText() == "negctrl",
                std::move(exp)));
        } else
            return ast::ptr<ast::GateModifier>(new ast::CtrlModifier(
                get_pos(ctx), ctx->children[0]->getText() == "negctrl"));
    }

    virtual antlrcpp::Any
    visitQuantumGateCall(qasm3Parser::QuantumGateCallContext* ctx) override {
        // quantumGateCall : quantumGateModifier* quantumGateName ( LPAREN
        // expressionList RPAREN )? indexIdentifierList
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
        auto q_args = std::move(ctx->indexIdentifierList()
                                    ->accept(this)
                                    .as<std::vector<ast::ptr<ast::IndexId>>>());

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

    virtual antlrcpp::Any
    visitUnaryOperator(qasm3Parser::UnaryOperatorContext* ctx) override {
        std::string text = ctx->getText();
        if (text == "~")
            return ast::UnaryOp::BitNot;
        else if (text == "!")
            return ast::UnaryOp::LogicalNot;
        else
            return ast::UnaryOp::Neg;
    }

    virtual antlrcpp::Any visitComparisonOperator(
        qasm3Parser::ComparisonOperatorContext* ctx) override {
        std::string text = ctx->getText();
        if (text == ">")
            return ast::BinaryOp::GT;
        else if (text == "<")
            return ast::BinaryOp::LT;
        else if (text == ">=")
            return ast::BinaryOp::GTE;
        else
            return ast::BinaryOp::LTE;
    }

    virtual antlrcpp::Any
    visitEqualityOperator(qasm3Parser::EqualityOperatorContext* ctx) override {
        if (ctx->getText() == "==")
            return ast::BinaryOp::EQ;
        else
            return ast::BinaryOp::NEQ;
    }

    virtual antlrcpp::Any
    visitLogicalOperator(qasm3Parser::LogicalOperatorContext* ctx) override {
        return defaultResult(); // unused in grammar
    }

    virtual antlrcpp::Any visitExpressionStatement(
        qasm3Parser::ExpressionStatementContext* ctx) override {
        auto exp = std::move(
            ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Stmt>(
            new ast::ExprStmt(get_pos(ctx), std::move(exp)));
    }

    virtual antlrcpp::Any
    visitExpression(qasm3Parser::ExpressionContext* ctx) override {
        // expression : expressionTerminator
        //            | unaryExpression
        //            | logicalAndExpression
        //            | expression '||' logicalAndExpression
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

    virtual antlrcpp::Any visitEqualityExpression(
        qasm3Parser::EqualityExpressionContext* ctx) override {
        if (ctx->equalityExpression()) {
            auto lexp = std::move(ctx->equalityExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            auto op = ctx->equalityOperator()->accept(this).as<ast::BinaryOp>();
            auto rexp = std::move(ctx->comparisonExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->comparisonExpression()->accept(this);
    }

    virtual antlrcpp::Any visitComparisonExpression(
        qasm3Parser::ComparisonExpressionContext* ctx) override {
        if (ctx->comparisonExpression()) {
            auto lexp = std::move(ctx->comparisonExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            auto op =
                ctx->comparisonOperator()->accept(this).as<ast::BinaryOp>();
            auto rexp = std::move(ctx->bitShiftExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->bitShiftExpression()->accept(this);
    }

    virtual antlrcpp::Any visitBitShiftExpression(
        qasm3Parser::BitShiftExpressionContext* ctx) override {
        if (ctx->bitShiftExpression()) {
            auto lexp = std::move(ctx->bitShiftExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::LeftBitShift;
            if (ctx->children[1]->getText() == ">>")
                op = ast::BinaryOp::RightBitShift;
            auto rexp = std::move(ctx->additiveExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->additiveExpression()->accept(this);
    }

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

    virtual antlrcpp::Any visitMultiplicativeExpression(
        qasm3Parser::MultiplicativeExpressionContext* ctx) override {
        if (ctx->multiplicativeExpression()) {
            auto lexp = std::move(ctx->multiplicativeExpression()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            ast::BinaryOp op = ast::BinaryOp::Times;
            if (ctx->DIV())
                op = ast::BinaryOp::Divide;
            else if (ctx->MOD())
                op = ast::BinaryOp::Mod;
            auto rexp = std::move(
                ctx->children[2]->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::BExpr(
                get_pos(ctx), std::move(lexp), op, std::move(rexp)));
        } else
            return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any
    visitUnaryExpression(qasm3Parser::UnaryExpressionContext* ctx) override {
        auto op = ctx->unaryOperator()->accept(this).as<ast::UnaryOp>();
        auto exp = std::move(
            ctx->powerExpression()->accept(this).as<ast::ptr<ast::Expr>>());
        return ast::ptr<ast::Expr>(
            new ast::UExpr(get_pos(ctx), op, std::move(exp)));
    }

    virtual antlrcpp::Any
    visitPowerExpression(qasm3Parser::PowerExpressionContext* ctx) override {
        if (ctx->powerExpression()) {
            auto lexp = std::move(ctx->expressionTerminator()
                                      ->accept(this)
                                      .as<ast::ptr<ast::Expr>>());
            auto rexp = std::move(
                ctx->powerExpression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(
                new ast::BExpr(get_pos(ctx), std::move(lexp),
                               ast::BinaryOp::Pow, std::move(rexp)));
        } else
            return ctx->expressionTerminator()->accept(this);
    }

    virtual antlrcpp::Any visitExpressionTerminator(
        qasm3Parser::ExpressionTerminatorContext* ctx) override {
        if (ctx->expressionTerminator()) {
            auto exp = std::move(ctx->expressionTerminator()
                                     ->accept(this)
                                     .as<ast::ptr<ast::Expr>>());
            auto index = std::move(
                ctx->expression()->accept(this).as<ast::ptr<ast::Expr>>());
            return ast::ptr<ast::Expr>(new ast::AccessExpr(
                get_pos(ctx), std::move(exp), std::move(index)));
        } else if (ctx->expression()) {
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
        } else if (ctx->Integer()) {
            return ast::ptr<ast::Expr>(new ast::IntExpr(
                get_pos(ctx), std::stoi(ctx->Integer()->getText())));
        } else if (ctx->RealNumber()) {
            return ast::ptr<ast::Expr>(new ast::RealExpr(
                get_pos(ctx), std::stod(ctx->RealNumber()->getText())));
        } else if (ctx->ImagNumber()) {
            std::string imag =
                ctx->ImagNumber()->getText(); // "3.5im", "12im", etc
            imag.pop_back();
            imag.pop_back();
            return ast::ptr<ast::Expr>(
                new ast::ImagExpr(get_pos(ctx), std::stod(imag)));
        } else if (ctx->Identifier()) {
            return ast::ptr<ast::Expr>(
                new ast::VarExpr(get_pos(ctx), ctx->Identifier()->getText()));
        } else if (ctx->StringLiteral()) {
            return ast::ptr<ast::Expr>(new ast::StringExpr(
                get_pos(ctx), ctx->StringLiteral()->getText()));
        } else
            return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any
    visitBooleanLiteral(qasm3Parser::BooleanLiteralContext* ctx) override {
        return ast::ptr<ast::Expr>(
            new ast::BoolExpr(get_pos(ctx), ctx->getText() == "true"));
    }

    virtual antlrcpp::Any
    visitBuiltInCall(qasm3Parser::BuiltInCallContext* ctx) override {
        // builtInCall : ( builtInMath | castOperator ) LPAREN expressionList
        // RPAREN
        auto args = std::move(ctx->expressionList()
                                  ->accept(this)
                                  .as<std::vector<ast::ptr<ast::Expr>>>());
        if (ctx->builtInMath()) {
            auto op = ctx->builtInMath()->accept(this).as<ast::MathOp>();
            return ast::ptr<ast::Expr>(
                new ast::MathExpr(get_pos(ctx), op, std::move(args)));
        } else {
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
        }
    }

    virtual antlrcpp::Any
    visitBuiltInMath(qasm3Parser::BuiltInMathContext* ctx) override {
        std::string text = ctx->getText();
        if (text == "arcsin")
            return ast::MathOp::Arcsin;
        else if (text == "sin")
            return ast::MathOp::Sin;
        else if (text == "arccos")
            return ast::MathOp::Arccos;
        else if (text == "cos")
            return ast::MathOp::Cos;
        else if (text == "arctan")
            return ast::MathOp::Arctan;
        else if (text == "tan")
            return ast::MathOp::Tan;
        else if (text == "exp")
            return ast::MathOp::Exp;
        else if (text == "ln")
            return ast::MathOp::Ln;
        else if (text == "sqrt")
            return ast::MathOp::Sqrt;
        else if (text == "rotl")
            return ast::MathOp::Rotl;
        else if (text == "rotr")
            return ast::MathOp::Rotr;
        else
            return ast::MathOp::Popcount;
    }

    virtual antlrcpp::Any
    visitCastOperator(qasm3Parser::CastOperatorContext* ctx) override {
        return ctx->classicalType()->accept(this);
    }

    virtual antlrcpp::Any
    visitExpressionList(qasm3Parser::ExpressionListContext* ctx) override {
        std::vector<ast::ptr<ast::Expr>> exprs;
        for (auto x : ctx->expression())
            exprs.emplace_back(
                std::move(x->accept(this).as<ast::ptr<ast::Expr>>()));
        return exprs;
    }

    virtual antlrcpp::Any
    visitEqualsExpression(qasm3Parser::EqualsExpressionContext* ctx) override {
        return ctx->children[1]->accept(this);
    }

    virtual antlrcpp::Any visitAssignmentOperator(
        qasm3Parser::AssignmentOperatorContext* ctx) override {
        std::string text = ctx->getText();
        if (text == "=")
            return ast::AssignOp::Equals;
        else if (text == "+=")
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

    virtual antlrcpp::Any
    visitSetDeclaration(qasm3Parser::SetDeclarationContext* ctx) override {
        // setDeclaration : LBRACE expressionList RBRACE
        //                | rangeDefinition
        //                | Identifier
        if (ctx->expressionList()) {
            auto indices =
                std::move(ctx->expressionList()
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

    virtual antlrcpp::Any
    visitProgramBlock(qasm3Parser::ProgramBlockContext* ctx) override {
        // programBlock : statement | controlDirective
        //              | LBRACE ( statement | controlDirective )* RBRACE
        std::list<ast::ProgramBlockStmt> body;
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

    virtual antlrcpp::Any visitBranchingStatement(
        qasm3Parser::BranchingStatementContext* ctx) override {
        // branchingStatement : 'if' LPAREN expression RPAREN programBlock (
        // 'else' programBlock )?
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

    virtual antlrcpp::Any
    visitLoopSignature(qasm3Parser::LoopSignatureContext* ctx) override {
        // loopSignature : 'for' Identifier 'in' setDeclaration
        //               | 'while' LPAREN expression RPAREN
        return defaultResult(); // handled by parent
    }

    virtual antlrcpp::Any
    visitLoopStatement(qasm3Parser::LoopStatementContext* ctx) override {
        // loopStatement : loopSignature programBlock
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

    virtual antlrcpp::Any
    visitEndStatement(qasm3Parser::EndStatementContext* ctx) override {
        return ast::ptr<ast::Stmt>(new ast::EndStmt(get_pos(ctx)));
    }

    virtual antlrcpp::Any
    visitReturnStatement(qasm3Parser::ReturnStatementContext* ctx) override {
        // returnStatement : 'return' ( expression | quantumMeasurement )?
        // SEMICOLON;
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

    virtual antlrcpp::Any
    visitControlDirective(qasm3Parser::ControlDirectiveContext* ctx) override {
        // controlDirective : ('break' | 'continue') SEMICOLON
        //                  | endStatement | returnStatement
        if (ctx->endStatement())
            return ctx->endStatement()->accept(this);
        else if (ctx->returnStatement())
            return ctx->returnStatement()->accept(this);
        else {
            if (ctx->children[0]->getText() == "break")
                return ast::ptr<ast::ControlStmt>(
                    new ast::BreakStmt(get_pos(ctx)));
            else
                return ast::ptr<ast::ControlStmt>(
                    new ast::ContinueStmt(get_pos(ctx)));
        }
    }

    virtual antlrcpp::Any visitExternDeclaration(
        qasm3Parser::ExternDeclarationContext* ctx) override {
        // externDeclaration : 'extern' Identifier LPAREN classicalTypeList?
        // RPAREN returnSignature? SEMICOLON
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

    virtual antlrcpp::Any visitExternOrSubroutineCall(
        qasm3Parser::ExternOrSubroutineCallContext* ctx) override {
        // externOrSubroutineCall : Identifier LPAREN expressionList? RPAREN
        std::vector<ast::ptr<ast::Expr>> args;
        if (ctx->expressionList())
            args = std::move(ctx->expressionList()
                                 ->accept(this)
                                 .as<std::vector<ast::ptr<ast::Expr>>>());
        return ast::ptr<ast::Expr>(new ast::FunctionCall(
            get_pos(ctx), ctx->Identifier()->getText(), std::move(args)));
    }

    virtual antlrcpp::Any visitSubroutineDefinition(
        qasm3Parser::SubroutineDefinitionContext* ctx) override {
        // subroutineDefinition : 'def' Identifier LPAREN anyTypeArgumentList?
        // RPAREN returnSignature? subroutineBlock
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

    virtual antlrcpp::Any
    visitSubroutineBlock(qasm3Parser::SubroutineBlockContext* ctx) override {
        // subroutineBlock : LBRACE statement* returnStatement? RBRACE
        std::list<ast::ProgramBlockStmt> body;
        for (auto& stmt : ctx->statement())
            body.emplace_back(
                std::move(stmt->accept(this).as<ast::ptr<ast::Stmt>>()));
        if (ctx->returnStatement())
            body.emplace_back(std::move(ctx->returnStatement()
                                            ->accept(this)
                                            .as<ast::ptr<ast::ControlStmt>>()));
        return ast::ProgramBlock::create(get_pos(ctx), std::move(body));
    }

    virtual antlrcpp::Any
    visitPragma(qasm3Parser::PragmaContext* ctx) override {
        // pragma : '#pragma' LBRACE statement* RBRACE
        std::list<ast::ptr<ast::Stmt>> body;
        for (auto& stmt : ctx->statement())
            body.emplace_back(
                std::move(stmt->accept(this).as<ast::ptr<ast::Stmt>>()));
        return ast::ptr<ast::GlobalStmt>(
            new ast::PragmaStmt(get_pos(ctx), std::move(body)));
    }

    virtual antlrcpp::Any
    visitTimingType(qasm3Parser::TimingTypeContext* ctx) override {
        return defaultResult(); // handled by parent
    }

    virtual antlrcpp::Any
    visitTimingBox(qasm3Parser::TimingBoxContext* ctx) override {
        // timingBox : 'box' designator? quantumBlock
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

    virtual antlrcpp::Any
    visitTimingIdentifier(qasm3Parser::TimingIdentifierContext* ctx) override {
        // timingIdentifier : TimingLiteral
        //                  | 'durationof' LPAREN ( Identifier | quantumBlock )
        //                  RPAREN
        if (ctx->TimingLiteral()) {
            std::vector<std::string> units{"dt", "ns", "us", "µs", "ms", "s"};
            std::vector<ast::TimeUnit> timeunits{
                ast::TimeUnit::dt,  ast::TimeUnit::ns, ast::TimeUnit::us,
                ast::TimeUnit::mus, ast::TimeUnit::ms, ast::TimeUnit::s};
            std::string lit = ctx->TimingLiteral()->getText();
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

    virtual antlrcpp::Any visitTimingInstructionName(
        qasm3Parser::TimingInstructionNameContext* ctx) override {
        return defaultResult(); // handled by parent
    }

    virtual antlrcpp::Any visitTimingInstruction(
        qasm3Parser::TimingInstructionContext* ctx) override {
        // timingInstruction : timingInstructionName ( LPAREN expressionList?
        // RPAREN
        // )? designator indexIdentifierList
        std::vector<ast::ptr<ast::Expr>> c_args;
        if (ctx->expressionList())
            c_args = std::move(ctx->expressionList()
                                   ->accept(this)
                                   .as<std::vector<ast::ptr<ast::Expr>>>());
        auto duration = std::move(
            ctx->designator()->accept(this).as<ast::ptr<ast::Expr>>());
        auto q_args = std::move(ctx->indexIdentifierList()
                                    ->accept(this)
                                    .as<std::vector<ast::ptr<ast::IndexId>>>());
        if (ctx->timingInstructionName()->getText() == "delay")
            return ast::ptr<ast::QuantumStmt>(
                new ast::DelayStmt(get_pos(ctx), std::move(c_args),
                                   std::move(duration), std::move(q_args)));
        else
            return ast::ptr<ast::QuantumStmt>(
                new ast::RotaryStmt(get_pos(ctx), std::move(c_args),
                                    std::move(duration), std::move(q_args)));
    }

    virtual antlrcpp::Any
    visitTimingStatement(qasm3Parser::TimingStatementContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any
    visitCalibration(qasm3Parser::CalibrationContext* ctx) override {
        return ctx->children[0]->accept(this);
    }

    virtual antlrcpp::Any visitCalibrationGrammarDeclaration(
        qasm3Parser::CalibrationGrammarDeclarationContext* ctx) override {
        // calibrationGrammarDeclaration : 'defcalgrammar' calibrationGrammar
        // SEMICOLON
        std::string name = ctx->calibrationGrammar()->getText();
        return ast::ptr<ast::GlobalStmt>(
            new ast::CalGrammarDecl(get_pos(ctx), name));
    }

    virtual antlrcpp::Any visitCalibrationDefinition(
        qasm3Parser::CalibrationDefinitionContext* ctx) override {
        // calibrationDefinition : 'defcal' Identifier ( LPAREN
        // calibrationArgumentList? RPAREN )? identifierList
        //                         returnSignature? LBRACE .*? RBRACE
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

    virtual antlrcpp::Any visitCalibrationGrammar(
        qasm3Parser::CalibrationGrammarContext* ctx) override {
        return defaultResult(); // handled by parent
    }

    virtual antlrcpp::Any visitCalibrationArgumentList(
        qasm3Parser::CalibrationArgumentListContext* ctx) override {
        // calibrationArgumentList : classicalArgumentList | expressionList
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
};

/**
 * \brief Parse a specified file
 */
inline ast::ptr<ast::Program> parse_file(std::string fname) {
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
    ASTConstructor constructor;
    return constructor.make_ast(tree);
}

/**
 * \brief Parse a string
 */
inline ast::ptr<ast::Program> parse_string(const std::string& str,
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
    ASTConstructor constructor;
    return constructor.make_ast(tree);
}

} // namespace parser
} // namespace qasmtools
