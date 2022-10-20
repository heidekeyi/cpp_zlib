//
// Created by 1213173752 on 2022/10/20.
//

#include "symbols.h"
#include "message.h"

namespace ZLIB {
    Symbols::Symbols(const char *s) {
        init(std::string{s});
    }

    Symbols::Symbols(const std::string &s) {
        init(s);
    }

    Symbols::Symbols(const std::vector<char> &s) {
        init(s);
    }

    void Symbols::symbols(const char *s) {
        init(s);
    }

    void Symbols::symbols(const std::string &s) {
        init(s);
    }

    void Symbols::symbols(const std::vector<char> &s) {
        init(s);
    }

    const std::vector<char> &Symbols::symbols() const {
        return m_symbols;
    }

    void Symbols::init(const std::string &s) {
        std::vector<char> v;
        for (auto c: s) {
            v.push_back(c);
        }
        init(v);
    }

    void Symbols::init(const std::vector<char> &s) {
        m_symbols = s;
        length();
        unique();
        visibility();
    }

    void Symbols::visibility() {
        for (auto c: m_symbols) {
            if (c < 0x20 || c > 0x7e) {
                throw Message{"invisibility is found in symbols"};
            }
        }
    }

    void Symbols::length() {
        if (m_symbols.size() < 2) {
            throw Message{"length of symbols is too short"};
        }
        if (m_symbols.size() > 32) {
            throw Message{"length of symbols is too long"};
        }
    }

    void Symbols::unique() {
        for (int i = 0; i < m_symbols.size(); ++i) {
            for (int j = i + 1; j < m_symbols.size(); ++j) {
                if (m_symbols[i] == m_symbols[j]) {
                    throw Message{"same char is found in symbols"};
                }
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, const Symbols &o) {
        for (auto c: o.symbols()) {
            os << c;
        }
        return os;
    }
}