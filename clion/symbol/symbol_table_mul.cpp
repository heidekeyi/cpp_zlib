//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_mul.h"
#include <iostream>

namespace ZLIB {
    void SymbolTableMul::display() {
        retrieve_table();
        for (int i = 0; i < valueSymbol.size(); ++i) {
            for (int j = 0; j < valueSymbol.size(); ++j) {
                if (j > i) {
                    std::cout << '\n';
                    break;
                }
                std::cout << valueSymbol[j] << '*' << valueSymbol[i] << '=';
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

    void SymbolTableMul::retrieve_table() {
        valueTable.clear();
        const auto &list = valueSymbolList.list();
        for (int i = 0; i < valueSymbol.size(); ++i) {
            valueTable.emplace_back();
            for (int j = 0; j < valueSymbol.size(); ++j) {
                if (j > i) {
                    valueTable[i].push_back(std::vector<char>{});
                } else {
                    int pos = retrieve_index(valueSymbol[i]) * retrieve_index(valueSymbol[j]);
                    valueTable[i].push_back(list[pos]);
                }
            }
        }
    }
}