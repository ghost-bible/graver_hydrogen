#pragma once

#include <vector>

#include "graver/compiler/token.h"
namespace graver {

namespace com {

struct NodeExpre {
    Token int_lint;
};

struct NodeExit {
    NodeExpre expre;
};

class Parser {
public:
    Parser() = default;
    explicit Parser(std::vector<Token> tokens);
    ~Parser() = default;

public:
    NodeExit parse();

private:
    NodeExpre parseExpre();

    Token peek();
    Token next();

private:
    std::vector<Token>            m_tokens;
    std::vector<Token>::size_type m_index{0};
};

}  // namespace com
}  // namespace graver