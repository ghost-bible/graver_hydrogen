#include "graver/compiler/exception.h"

#include <fmt/format.h>

using namespace graver::com;

CompilerException::CompilerException(ErrorCode code) : m_code(code) {}

const char* CompilerException::what() const noexcept {
    this->m_msg = fmt::format("error code:{}", static_cast<int>(m_code));
    return this->m_msg.c_str();
}