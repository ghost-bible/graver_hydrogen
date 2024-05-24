#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <memory>

#include "graver/person/person.h"
#include "graver/util/log_util.h"

int main() {
    LogUtil::init(spdlog::level::info, "../logs/app.log");
    const std::shared_ptr<spdlog::logger> log = LogUtil::getLogger("app");

    auto person = std::make_unique<Person>(18, "laolang");
    SPDLOG_LOGGER_INFO(log, fmt::format("Hello, I am {}, my age is {}", person->name(), person->age()));

    spdlog::shutdown();
    return 0;
}
