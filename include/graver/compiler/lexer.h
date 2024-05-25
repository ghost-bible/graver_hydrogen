#pragma once

#include <string>
#include <vector>

#include "graver/compiler/token.h"
class Lexer {
public:
    Lexer() = default;
    explicit Lexer(std::string& text);
    ~Lexer() = default;

public:
    std::vector<Token> lex();

private:
    std::string m_text;
};