#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <memory>

#include "graver/compiler/compiler.h"
#include "graver/util/io_util.h"
#include "graver/util/log_util.h"

using namespace graver;

int main(int argc, char** argv) {
    util::LogUtil::init(spdlog::level::info, "../logs/app.log");
    const std::shared_ptr<spdlog::logger> log = util::LogUtil::getLogger("app");

    if (2 != argc) {
        std::cerr << "Incorrect usage. Correct usage is:" << std::endl;
        std::cerr << "graver <input.graver>" << std::endl;
        return EXIT_FAILURE;
    }

    auto content  = util::IoUtil::readToLine(argv[1]);
    auto compiler = std::make_unique<com::Compiler>(argv[1]);
    compiler->compile();

    spdlog::shutdown();
    return EXIT_SUCCESS;
}
