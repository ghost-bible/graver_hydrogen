#pragma once

#include <string>
#include <vector>

#include "graver/compiler/token.h"
class CodeGen {
public:
    CodeGen() = default;
    explicit CodeGen(std::vector<Token>& tokens);
    ~CodeGen() = default;

public:
    std::string gen();

private:
    std::vector<Token> m_tokens;
};