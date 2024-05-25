#pragma once

#include <memory>
#include <string>

#include "graver/compiler/code_gen.h"
#include "graver/compiler/lexer.h"

struct CompileResult {
    bool        success;
    std::string asmCode;
};

class Compiler {
public:
    Compiler() = default;
    explicit Compiler(const char* filename);
    ~Compiler() = default;

public:
    CompileResult compile();

private:
    std::string m_fileContent;
    std::string m_fileName;

    std::shared_ptr<Lexer>   m_lexer;
    std::shared_ptr<CodeGen> m_codeGen;
};