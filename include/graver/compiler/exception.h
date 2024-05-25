#pragma once

#include <exception>
#include <string>
namespace graver {

namespace com {

enum ErrorCode {
    ok     = 0,
    failed = 1,
};

class CompilerException : public std::exception {
public:
    CompilerException() = delete;
    explicit CompilerException(ErrorCode code);

    const char* what() const noexcept override;

private:
    ErrorCode           m_code;
    mutable std::string m_msg;
};

}  // namespace com
}  // namespace graver