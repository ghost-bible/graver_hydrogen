#include "graver/compiler/parser.h"

#include <cstdlib>
#include <iostream>

#include "graver/compiler/exception.h"
#include "graver/compiler/token.h"

using namespace graver::com;

Parser::Parser(std::vector<Token> tokens) : m_tokens(std::move(tokens)) {}

NodeExit Parser::parse() {
    NodeExit nodeExit;
    auto     token = peek();
    while (TokenType::eof != token.type) {
        if (TokenType::key_word_exit == token.type) {
            try {
                nodeExit.expre = parseExpre();
            } catch (CompilerException& ex) {
                std::cerr << "Invalid expression" << std::endl;
                exit(EXIT_FAILURE);
            }

            token = next();
            continue;
        }

        if (TokenType::semi != token.type) {
            std::cerr << "Invalid expression" << std::endl;
            exit(EXIT_FAILURE);
        }
        token = next();
    }
    return nodeExit;
}

NodeExpre Parser::parseExpre() {
    Token token = next();
    if (TokenType::eof == token.type) {
        throw CompilerException(ErrorCode::failed);
    }
    if (TokenType::int_lit != token.type) {
        throw CompilerException(ErrorCode::failed);
    }

    NodeExpre expre;
    expre.int_lint = token;
    return expre;
}

Token Parser::peek() {
    Token t;
    return m_index >= m_tokens.size() ? t : m_tokens.at(m_index);
}
Token Parser::next() {
    m_index++;
    return peek();
}