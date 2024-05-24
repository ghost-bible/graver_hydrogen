#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <cstdlib>
#include <iostream>
#include <memory>

#include "graver/compiler/compiler.h"
#include "graver/compiler/compiler_helper.h"
#include "graver/util/io_util.h"
#include "graver/util/log_util.h"

int main(int argc, char** argv) {
    LogUtil::init(spdlog::level::info, "../logs/app.log");
    const std::shared_ptr<spdlog::logger> log = LogUtil::getLogger("app");

    if (2 != argc) {
        std::cerr << "Incorrect usage. Correct usage is:" << std::endl;
        std::cerr << "graver <input.graver>" << std::endl;
        return EXIT_FAILURE;
    }

    auto content  = IoUtil::readToLine(argv[1]);
    auto compiler = std::make_unique<Compiler>(argv[1]);
    auto tokens   = compiler->tokenize();
    for (const auto& t : tokens) {
        std::cout << CompilerHelper::tokenToString(t) << std::endl;
    }

    std::cout << compiler->compileAsm() << std::endl;

    IoUtil::writeToFile("./test.asm", compiler->compileAsm());

    spdlog::shutdown();
    return EXIT_SUCCESS;
}
