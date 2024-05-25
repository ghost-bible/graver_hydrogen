#include "graver/compiler/code_gen.h"

#include <sstream>

CodeGen::CodeGen(std::vector<Token>& tokens) : m_tokens(tokens) {}

std::string CodeGen::gen() {
    std::stringstream buff;
    buff << "global _start\n";
    buff << "_start:\n";

    for (std::vector<Token>::size_type i = 0; i < m_tokens.size(); i++) {
        const Token& token = m_tokens.at(i);
        if (TokenType::key_word_exit == token.type) {
            if (i + 1 < m_tokens.size() && TokenType::int_lit == m_tokens.at(i + 1).type) {
                if (i + 2 < m_tokens.size() && TokenType::semi == m_tokens.at(i + 2).type) {
                    buff << "    mov rax, 60\n";
                    buff << "    mov rdi, " << m_tokens.at(i + 1).text << "\n";
                    buff << "    syscall\n";
                }
            }
        }
    }

    return buff.str();
}