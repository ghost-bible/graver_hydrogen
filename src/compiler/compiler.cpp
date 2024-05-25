#include "graver/compiler/compiler.h"

#include <iostream>
#include <memory>

#include "graver/compiler/code_gen.h"
#include "graver/compiler/compiler_helper.h"
#include "graver/compiler/lexer.h"
#include "graver/util/io_util.h"

Compiler::Compiler(const char* filename) {
    this->m_fileName = filename;
}

CompileResult Compiler::compile() {
    CompileResult ret{};
    ret.success = true;

    // 读取源文件内容
    this->m_fileContent = IoUtil::readToLine(this->m_fileName.c_str());

    // 词法分析
    this->m_lexer = std::make_shared<Lexer>(this->m_fileContent);
    auto tokens   = this->m_lexer->lex();

#ifdef GRAVER_DEBUG
    std::cout << "graver debug -> token list:" << std::endl;
    for (const auto& t : tokens) {
        std::cout << CompilerHelper::tokenToString(t) << std::endl;
    }
#endif

    // 代码生成
    this->m_codeGen = std::make_shared<CodeGen>(tokens);
    ret.asmCode     = this->m_codeGen->gen();

#ifdef GRAVER_DEBUG
    std::cout << "graver debug -> asm code:" << std::endl;
    std::cout << ret.asmCode << std::endl;
#endif

    // 生成汇编源文件
    // TODO 汇编源文件名
    IoUtil::writeToFile("./test.asm", ret.asmCode);

    return ret;
}