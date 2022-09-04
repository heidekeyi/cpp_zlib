//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_add.h"
#include "symbol_list.h"

namespace ZLIB {
    std::vector<SymbolTable::exp> SymbolTableAdd::retrieve_table_list() {
        std::vector<char> sym{};
        for (auto it: symbol()) {
            sym.push_back(it);
        }
        sym.push_back(symbol()[0]);
        std::vector<SymbolTable::exp> table_list;
        auto list = SymbolList{}.symbol(symbol()).minNum(108).list();
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