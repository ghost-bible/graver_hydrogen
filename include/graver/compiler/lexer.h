#pragma once

#include <string>
#include <vector>

#include "graver/compiler/token.h"

namespace graver {

namespace com {

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

}  // namespace com
}  // namespace graver
