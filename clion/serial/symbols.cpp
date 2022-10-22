//
// Created by 1213173752 on 2022/10/20.
//

#include "symbols.h"
#include "message.h"
#include <algorithm>

namespace ZLIB {
    Symbols::Symbols(const std::string &s) {
        symbols(s);
    }

    void Symbols::symbols(const std::string &s) {
        m_symbols = s;
        length();
        unique();
        visibility();
    }

    std::string Symbols::symbols() const {
        return m_symbols;
    }

    void Symbols::visibility() {
        for (auto c: m_symbols) {
            if (c < 0x20 || c > 0x7e) {
                throw Message{"message: char of invisibility is found"};
            }
        }
    }

    void Symbols::length() {
        if (m_symbols.size() < 2) {
            throw Message{"message: length of symbols is too short"};
        }
        if (m_symbols.size() > 32) {
            throw Message{"message: length of symbols is too long"};
        }
    }

    void Symbols::unique() {
        for (int i = 0; i < m_symbols.size(); ++i) {
            for (int j = i + 1; j < m_symbols.size(); ++j) {
                if (m_symbols[i] == m_symbols[j]) {
                    throw Message{"message: same char is found"};
                }
            }
        }
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
