#include <spdlog/spdlog.h>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#include "graver/util/log_util.h"

using namespace graver;

int main(int argc, char** argv) {
    util::LogUtil::init(spdlog::level::info, "test.log");

    std::shared_ptr<spdlog::logger> log = util::LogUtil::getLogger("test");
    SPDLOG_LOGGER_INFO(log, "graver test start...");

    doctest::Context context;

    // !!! THIS IS JUST AN EXAMPLE SHOWING HOW DEFAULTS/OVERRIDES ARE SET !!!

    // defaults
    context.addFilter("test-case-exclude", "*math*");  // exclude test cases with "math" in their name
    context.setOption("abort-after", 5);               // stop test execution after 5 failed assertions
    context.setOption("order-by", "name");             // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    // overrides
    context.setOption("no-breaks", true);  // don't break in the debugger when assertions fail

    int res = context.run();  // run

    SPDLOG_LOGGER_INFO(log, "graver test end...");

    if (context.shouldExit()) {  // important - query flags (and --exit) rely on the user doing this
        spdlog::shutdown();
        return res;  // propagate the result of the tests
    }

    int client_stuff_return_code = 0;
    // your program - if the testing framework is integrated in your production code

    spdlog::shutdown();
    return res + client_stuff_return_code;  // the result from doctest is propagated here as well
}