//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_add.h"
#include "symbol_list.h"

namespace ZLIB {
    std::vector<SymbolTable::exp> SymbolTableAdd::retrieve_table_list() {
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
                table_list.emplace_back(lhs, rhs, '+', list[lhs_index + rhs_index]);
                if (lhs_index <= rhs_index) {
                    break;
                }
            }
        }
        return table_list;
    }
}