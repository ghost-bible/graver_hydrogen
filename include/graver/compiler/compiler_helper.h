#pragma once

#include <map>
#include <string>

#include "graver/compiler/token.h"

class CompilerHelper {
public:
    CompilerHelper()  = default;
    ~CompilerHelper() = default;
    static std::string tokenTypeToString(TokenType type);
    static TokenType   stringToTokenType(const std::string& keyWord);
    static std::string tokenToString(const Token& token);

private:
    static std::map<TokenType, std::string> m_token_type_string_map;
    static std::map<std::string, TokenType> m_key_word_token_type_map;
};