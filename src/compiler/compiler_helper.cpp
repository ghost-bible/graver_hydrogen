#include "graver/compiler/compiler_helper.h"

#include <fmt/core.h>

#include <sstream>

#include "graver/compiler/token.h"

using namespace graver::com;

std::map<TokenType, std::string> CompilerHelper::m_token_type_string_map = {  // NOLINT
    {TokenType::key_word_exit, "key_word_exit"},
    {TokenType::semi, "semi"},
    {TokenType::int_lit, "int_lit"}};

std::map<std::string, TokenType> CompilerHelper::m_key_word_token_type_map = {  // NOLINT
    {"exit", TokenType::key_word_exit}};

std::string CompilerHelper::tokenTypeToString(TokenType type) {
    auto it = m_token_type_string_map.find(type);
    return it == m_token_type_string_map.end() ? "" : it->second;
}

TokenType CompilerHelper::stringToTokenType(const std::string& keyWord) {
    auto it = m_key_word_token_type_map.find(keyWord);
    return it == m_key_word_token_type_map.end() ? TokenType::unknown : it->second;
}

std::string CompilerHelper::tokenToString(const Token& token) {
    std::stringstream buff;

    buff << fmt::format("{:<20}", CompilerHelper::tokenTypeToString(token.type));
    buff << token.text;

    return buff.str();
}