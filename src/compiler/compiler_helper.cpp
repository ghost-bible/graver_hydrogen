#include "graver/compiler/compiler_helper.h"

#include <fmt/core.h>

#include <sstream>

std::map<TokenType, std::string> CompilerHelper::m_token_type_map = {  // NOLINT
    {TokenType::key_word_return, "key_word_return"},
    {TokenType::semi, "semi"},
    {TokenType::int_lit, "int_lit"}};

std::string CompilerHelper::tokenTypeToString(TokenType type) {
    auto it = m_token_type_map.find(type);
    return it == m_token_type_map.end() ? "" : it->second;
}

std::string CompilerHelper::tokenToString(const Token& token) {
    std::stringstream buff;

    buff << fmt::format("{:<20}", CompilerHelper::tokenTypeToString(token.type));
    buff << token.text;

    return buff.str();
}