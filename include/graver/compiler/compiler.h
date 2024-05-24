#pragma once

#include <map>
#include <string>
#include <vector>

#include "graver/compiler/token.h"

class Compiler {
public:
    Compiler() = default;
    explicit Compiler(const char* filename);
    ~Compiler() = default;
    std::vector<Token> tokenize();
    std::string        compileAsm();

private:
    TokenType getKeyWordType(const std::string& text);

private:
    std::string                      m_fileContent;
    std::string                      m_fileName;
    std::map<std::string, TokenType> m_key_word_map{{"return", TokenType::key_word_return}};
};