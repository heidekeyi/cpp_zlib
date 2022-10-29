//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_SYMBOLS_H
#define SERIAL_SYMBOLS_H

#include <string>
#include <ostream>
#include "message.h"
#include <locale>

namespace SERIAL {
    using Pointer = const char *(*)();
    namespace POINTER {
        const char *dec() { return "0123456789"; }

        const char *bin() { return "01"; }

        const char *hex() { return "0123456789ABCDEF"; }
    }

    template<Pointer ptr>
    class Symbols {
    public:
        Symbols();

    public:
        [[nodiscard]]  const std::string &symbols() const;

        [[nodiscard]] int find(char ch) const;

    private:
        std::string m_symbols;
    };

    template<Pointer ptr>
    Symbols<ptr>::Symbols()
            : m_symbols{ptr()} {
        if (m_symbols.empty()) {
            throw Message{"symbols is empty"};
        }
        if (1 == m_symbols.size()) {
            throw Message{"symbols make no sense"};
        }
        for (int i = 0; i < m_symbols.size(); ++i) {
            auto ch = m_symbols[i];
            if (ch < 0x20 || ch > 0x7e) {
                throw Message{"symbols has space char"};
            }
            for (int j = i + 1; j < m_symbols.size(); ++j) {
                if (m_symbols[j] == ch) {
                    throw Message{"symbols has the same char"};
                }
            }
        }
    }

    template<Pointer ptr>
    const std::string &Symbols<ptr>::symbols() const {
        return m_symbols;
    }

    template<Pointer ptr>
    int Symbols<ptr>::find(char ch) const {
        return m_symbols.find(std::toupper(ch, std::locale{}));
    }

    template<Pointer ptr>
    std::ostream &operator<<(std::ostream &os, const Symbols<ptr> &o) {
        return os << o.symbols();
    }
}

#endif //SERIAL_SYMBOLS_H
