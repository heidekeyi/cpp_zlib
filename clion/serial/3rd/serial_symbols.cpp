//
// Created by 1213173752 on 2022/10/26.
//

#include "serial_symbols.h"
#include "serial_message.h"

namespace SERIAL_SYMBOLS {
    using namespace SERIAL_MESSAGE;

    SerialSymbols::SerialSymbols(const std::string &s) {
        symbols(s);
    }

    SerialSymbols &SerialSymbols::symbols(const std::string &s) {
        m_serial_symbols = s;
        for (int i = 0; i < m_serial_symbols.size(); ++i) {
            auto ch = m_serial_symbols[i];
            if (ch < 0x20 || ch > 0x7e) {
                throw SerialMessage{": invisibility char encounter in " + s};
            }
            for (int j = i + 1; j < m_serial_symbols.size(); ++j) {
                if (m_serial_symbols[j] == ch) {
                    throw SerialMessage{"the same char encounter in " + s};
                }
            }
        }
        if (m_serial_symbols.empty()) {
            throw SerialMessage{"serial_symbols is empty"};
        }
        if (m_serial_symbols.size() < 2) {
            throw SerialMessage{"message: length of symbols less than 2"};
        }
        if (m_serial_symbols.size() > 32) {
            throw SerialMessage{"message: length of symbols more than 32"};
        }
        return *this;
    }

    const std::string &SerialSymbols::symbols() const {
        return m_serial_symbols;
    }

    bool SerialSymbols::has(char elem) const {
//        return std::ranges::any_of(
//                m_serial_symbols.begin(),
//                m_serial_symbols.end(),
//                [elem](char ch) { return ch == elem; }
//        );
return false;
    }

    std::ostream &operator<<(std::ostream &os, const SerialSymbols &o) {
        for (auto c: o.symbols()) {
            os << c;
        }
        return os;
    }
}