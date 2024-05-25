#include "graver/compiler/code_gen.h"

#include <sstream>

using namespace graver::com;

CodeGen::CodeGen(NodeExit root) : m_root(std::move(root)) {}

std::string CodeGen::gen() const {
    std::stringstream buff;
    buff << "global _start\n";
    buff << "_start:\n";

    buff << "    mov rax, 60\n";
    buff << "    mov rdi, " << m_root.expre.int_lint.text << "\n";
    buff << "    syscall\n";

    return buff.str();
}