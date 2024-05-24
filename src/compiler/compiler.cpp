#include "graver/compiler/compiler.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "graver/compiler/token.h"
#include "graver/util/io_util.h"
Compiler::Compiler(const char* filename) {
    this->m_fileName    = filename;
    this->m_fileContent = IoUtil::readToLine(filename);
}

std::vector<Token> Compiler::tokenize() {
    std::vector<Token> tokens;
    std::string        buff;
    for (std::string::size_type i = 0; i < m_fileContent.length(); i++) {
        char c = m_fileContent.at(i);
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
            c = m_fileContent.at(i);
            while (std::isdigit(c)) {
                buff.push_back(c);
                i++;
                c = m_fileContent.at(i);
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
            c = m_fileContent.at(i);
            while (std::isalnum(c)) {
                buff.push_back(c);
                i++;
                c = m_fileContent.at(i);
            }
            i--;

            tokens.push_back({.type = getKeyWordType(buff), .text = buff});
            buff.clear();
            continue;
        }

        tokens.push_back({.type = TokenType::unknown, .text = std::string(1, c)});
    }
    return tokens;
}

std::string Compiler::compileAsm() {
    std::stringstream buff;
    buff << "global _start\n";
    buff << "_start:\n";

    auto tokens = tokenize();
    for (std::vector<Token>::size_type i = 0; i < tokens.size(); i++) {
        const Token& token = tokens.at(i);
        if (TokenType::key_word_return == token.type) {
            if (i + 1 < tokens.size() && TokenType::int_lit == tokens.at(i + 1).type) {
                if (i + 2 < tokens.size() && TokenType::semi == tokens.at(i + 2).type) {
                    buff << "    mov rax, 60\n";
                    buff << "    mov rdi, " << tokens.at(i + 1).text << "\n";
                    buff << "    syscall\n";
                }
            }
        }
    }

    return buff.str();
}

TokenType Compiler::getKeyWordType(const std::string& text) {
    auto it = m_key_word_map.find(text);
    return it == m_key_word_map.end() ? TokenType::unknown : it->second;
}