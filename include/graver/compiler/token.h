#pragma once

#include <string>

namespace graver {

namespace com {
enum class TokenType {
    key_word_exit,
    int_lit,
    semi,
    unknown
};

enum class ValueType {
    int_lit,
    bool_lit,
    invalid
};

class TokenValue {
public:
    TokenValue();
    explicit TokenValue(std::string& text);
    ~TokenValue() = default;

    int getInteger() const;

private:
    std::string m_text;
    ValueType   m_valueType = ValueType::invalid;
};

struct Token {
    TokenType   type;
    std::string text;
    TokenValue  value = TokenValue();
};

}  // namespace com
}  // namespace graver
