//
// Created by 1213173752 on 2022/10/20.
//

#include "symbols.h"
#include "message.h"
#include <algorithm>

namespace SERIAL {
    Symbols::Symbols(const std::string &s) {
        symbols(s);
    }

    Symbols &Symbols::symbols(const std::string &s) {
        m_symbols = s;
        for (int i = 0; i < m_symbols.size(); ++i) {
            auto ch = m_symbols[i];
            if (ch < 0x20 || ch > 0x7e) {
                throw Message{"message: char of invisibility is found"};
            }
            for (int j = i + 1; j < m_symbols.size(); ++j) {
                if (m_symbols[j] == ch) {
                    throw Message{"message: same char is found"};
                }
            }
        }
        if (m_symbols.size() < 2) {
            throw Message{"message: length of symbols less than 2"};
        }
        if (m_symbols.size() > 32) {
            throw Message{"message: length of symbols more than 32"};
        }
        return *this;
    }

    const std::string &Symbols::symbols() const {
        return m_symbols;
    }

    bool Symbols::has(char elem) const {
        return std::ranges::any_of(
                m_symbols.begin(),
                m_symbols.end(),
                [elem](char ch) { return ch == elem; }
        );
    }

    std::ostream &operator<<(std::ostream &os, const Symbols &o) {
        for (auto c: o.symbols()) {
            os << c;
        }
        return os;
    }
}
