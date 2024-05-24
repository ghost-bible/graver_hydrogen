#include "graver/compiler/token.h"

#include <string>

TokenValue::TokenValue() {
    m_valueType = ValueType::invalid;
}

TokenValue::TokenValue(std::string& text) : m_text(std::move(text)) {
    m_valueType = ValueType::int_lit;
}

int TokenValue::getInteger() const {
    return std::stoi(m_text);
}