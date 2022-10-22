//
// Created by 1213173752 on 2022/10/22.
//

#include "operand.h"

#include <utility>
#include "message.h"

namespace ZLIB {
    Operand::Operand(char ch, Symbols symbols)
            : m_operand{ch}, m_symbols(std::move(symbols)) {
        if (!m_symbols.has(m_operand)) {
            throw Message{"operand: value of operand can not find in symbols"};
        }
    }

    char Operand::operand() const {
        return m_operand;
    }

    std::ostream &operator<<(std::ostream &os, const Operand &o) {
        return os << o.operand();
    }
}