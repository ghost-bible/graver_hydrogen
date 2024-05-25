#pragma once

#include <string>
#include <vector>

#include "graver/compiler/parser.h"

namespace graver {

namespace com {

class CodeGen {
public:
    CodeGen() = default;
    explicit CodeGen(NodeExit root);
    ~CodeGen() = default;

public:
    std::string gen() const;

private:
    NodeExit m_root;
};

}  // namespace com
}  // namespace graver
