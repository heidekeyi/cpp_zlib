//
// Created by 12131 on 2022/9/4.
//

#include "symbol_base.h"
#include <iostream>

namespace ZLIB {
    SymbolBase &SymbolBase::symbol(const char *sym) {
        return symbol(std::string{sym});
    }

    SymbolBase &SymbolBase::symbol(const std::string &sym) {
        valueSymbol.clear();
        for (char ch: sym) {
            valueSymbol.push_back(ch);
        }
        return *this;
    }

    const std::vector<char> &SymbolBase::symbol() const {
        return valueSymbol;
    }

    int SymbolBase::retrieve_index(char ch) const {
        int index = 0;
        for (auto it: symbol()) {
            if (ch == it) {
                break;
            }
            ++index;
        }
        return index;
    }

    void SymbolBase::display(const std::vector<char> &vec) {
        int index = static_cast<int>(vec.size());
        while (--index >= 0) {
            std::cout << vec[index];
        }
    }
}