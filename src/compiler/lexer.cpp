#include "graver/compiler/lexer.h"

#include "graver/compiler/compiler_helper.h"

using namespace graver::com;

Lexer::Lexer(std::string& text) : m_text(std::move(text)) {}

std::vector<Token> Lexer::lex() {
    std::vector<Token> tokens;
    std::string        buff;
    for (std::string::size_type i = 0; i < m_text.length(); i++) {
        char c = m_text.at(i);
        if (std::isspace(c)) {
            continue;
        }

        if (';' == c) {
            tokens.push_back({.type = TokenType::semi, .text = ";"});
            continue;
        }

        if (std::isdigit(c)) {
            buff.push_back(c);
            i++;
            c = m_text.at(i);
            while (std::isdigit(c)) {
                buff.push_back(c);
                i++;
                c = m_text.at(i);
            }
            i--;
            Token t;
            t.text  = buff;
            t.type  = TokenType::int_lit;
            t.value = TokenValue(buff);
            tokens.push_back(t);
            continue;
        }

        if (std::isalpha(c)) {
            buff.push_back(c);
            i++;
            c = m_text.at(i);
            while (std::isalnum(c)) {
                buff.push_back(c);
                i++;
                c = m_text.at(i);
            }
            i--;

            tokens.push_back({.type = CompilerHelper::stringToTokenType(buff), .text = buff});
            buff.clear();
            continue;
        }

        tokens.push_back({.type = TokenType::unknown, .text = std::string(1, c)});
    }
    return tokens;
}