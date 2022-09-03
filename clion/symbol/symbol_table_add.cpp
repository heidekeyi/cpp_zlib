//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_add.h"
#include <iostream>
#include "symbol_list.h"

namespace ZLIB {
    SymbolTableAdd &SymbolTableAdd::symbol(const char *sym) {
        return symbol(std::string{sym});
    }

    SymbolTableAdd &SymbolTableAdd::symbol(const std::string &sym) {
        valueSymbol.clear();
        for (int i = 1; i < sym.size(); ++i) {
            valueSymbol.push_back(sym[i]);
        }
        valueSymbolList = SymbolList{}.symbol(sym).minNum(108);
        return *this;
    }

    const std::vector<char> &SymbolTableAdd::symbol() const {
        return valueSymbol;
    }

    void SymbolTableAdd::display() {
        retrieve_table();
        for (int i = 0; i < valueSymbol.size(); ++i) {
            for (int j = 0; j < valueSymbol.size(); ++j) {
                if (j > i) {
                    std::cout << '\n';
                    break;
                }
                std::cout << valueSymbol[j] << '+' << valueSymbol[i] << '=';
                auto &it = valueTable[i][j];
                int index = static_cast<int>(it.size());
                while (--index >= 0) {
                    std::cout << it[index];
                }
                std::cout << '\t';
            }
        }
        std::cout << std::endl;
    }

    void SymbolTableAdd::retrieve_table() {
        valueTable.clear();
        const auto &list = valueSymbolList.list();
        for (int i = 0; i < valueSymbol.size(); ++i) {
            valueTable.emplace_back();
            for (int j = 0; j < valueSymbol.size(); ++j) {
                if (j > i) {
                    valueTable[i].push_back(std::vector<char>{});
                } else {
                    int pos = retrieve_index(valueSymbol[i]) + retrieve_index(valueSymbol[j]);
                    valueTable[i].push_back(list[pos]);
                }
            }
        }
    }

    int SymbolTableAdd::retrieve_index(char ch) {
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