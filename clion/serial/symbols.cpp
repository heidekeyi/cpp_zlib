//
// Created by 1213173752 on 2022/10/31.
//

#include "symbols.h"


namespace SERIAL {
    namespace SYMBOLS_CALLBACK {
        const char *dec() { return "0123456789"; }

        const char *bin() { return "01"; }

        const char *hex() { return "0123456789ABCDEF"; }
    }

    Symbols::Symbols(CALLBACK callback) {
        const std::string symbols{callback()};
        if (symbols.empty()) {
            throw Message{"symbols is empty"};
        }
        if (1 == symbols.size()) {
            throw Message{"symbols make no sense"};
        }
        for (size_t i = 0; i < symbols.size(); ++i) {
            auto ch = symbols[i];
            if (ch < 0x20 || ch > 0x7e) {
                throw Message{"symbols has space char"};
            }
            for (size_t j = i + 1; j < symbols.size(); ++j) {
                if (symbols[j] == ch) {
                    throw Message{"symbols has the same char"};
                }
            }
        }
        m_symbols = symbols;
    }

    int Symbols::find(char ch) const {
        auto pos = -1;
        ch = std::toupper(ch, std::locale{});
        for (size_t i = 0; i < m_symbols.size(); ++i) {
            if (ch == m_symbols[i]) {
                pos = static_cast<int>(i);
                break;
            }
        }
        return pos;
    }

    const std::string &Symbols::symbols() const {
        return m_symbols;
    }

    char Symbols::first() const {
        return m_symbols[0];
    }

    std::ostream &operator<<(std::ostream &os, const Symbols &o) {
        return os << o.symbols();
    }
}