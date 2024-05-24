#pragma once

#include <map>
#include <string>

#include "graver/compiler/token.h"

class CompilerHelper {
public:
    CompilerHelper()  = default;
    ~CompilerHelper() = default;
    static std::string tokenTypeToString(TokenType type);
    static std::string tokenToString(const Token& token);

private:
    static std::map<TokenType, std::string> m_token_type_map;
};