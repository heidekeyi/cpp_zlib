//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_mul.h"
#include "symbol_list.h"

namespace ZLIB {
//    void SymbolTableMul::display() {
//        retrieve_table();
//        for (int i = 0; i < valueSymbol.size(); ++i) {
//            for (int j = 0; j < valueSymbol.size(); ++j) {
//                if (j > i) {
//                    std::cout << '\n';
//                    break;
//                }
//                std::cout << valueSymbol[j] << '*' << valueSymbol[i] << '=';
//                auto &it = valueTable[i][j];
//                int index = static_cast<int>(it.size());
//                while (--index >= 0) {
//                    std::cout << it[index];
//                }
//                std::cout << '\t';
//            }
//        }
//        std::cout << std::endl;
//    }
//
//    void SymbolTableMul::retrieve_table() {
//        valueTable.clear();
//        const auto &list = valueSymbolList.list();
//        for (int i = 0; i < valueSymbol.size(); ++i) {
//            valueTable.emplace_back();
//            for (int j = 0; j < valueSymbol.size(); ++j) {
//                if (j > i) {
//                    valueTable[i].push_back(std::vector<char>{});
//                } else {
//                    int pos = retrieve_index(valueSymbol[i]) * retrieve_index(valueSymbol[j]);
//                    valueTable[i].push_back(list[pos]);
//                }
//            }
//        }
//    }

    std::vector<SymbolTable::exp> SymbolTableMul::retrieve_table_list() {
        std::vector<char> sym{};
        for (auto it: symbol()) {
            sym.push_back(it);
        }
        sym.push_back(symbol()[0]);
        std::vector<SymbolTable::exp> table_list;
        SymbolList symbolList;
        symbolList.symbol(symbol());
        auto list = symbolList.retrieve_list();
        for (auto lhs: symbol()) {
            auto lhs_index = retrieve_index(lhs);
            if (!lhs_index) {
                continue;
            }
            for (auto rhs: symbol()) {
                auto rhs_index = retrieve_index(rhs);
                if (!rhs_index) {
                    continue;
                }
                table_list.emplace_back(lhs, rhs, '*', list[lhs_index * rhs_index]);
                if (lhs_index <= rhs_index) {
                    break;
                }
            }
        }
        return table_list;
    }
}