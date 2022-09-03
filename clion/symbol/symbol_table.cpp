//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table.h"

namespace ZLIB{
    SymbolTable &SymbolTable::symbol(const char *sym) {
        return symbol(std::string{sym});
    }

    SymbolTable &SymbolTable::symbol(const std::string &sym) {
        valueSymbol.clear();
        for (int i = 1; i < sym.size(); ++i) {
            valueSymbol.push_back(sym[i]);
        }
        valueSymbolList = SymbolList{}.symbol(sym).minNum(108);
        return *this;
    }

    const std::vector<char> &SymbolTable::symbol() const {
        return valueSymbol;
    }

    int SymbolTable::retrieve_index(char ch) {
        const auto &list = valueSymbolList.list();
        int index = 0;
        auto sz = list.size();
        while (index < list.size()) {
            if (ch == list[index][0]) {
                break;
            }
            ++index;
        }
        return index;
    }
}