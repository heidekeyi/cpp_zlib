//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table.h"
#include <iostream>
#include <utility>

namespace ZLIB {
    void SymbolTable::display() {
        int row = 1;
        int col = 1;
        for (auto &it: retrieve_table_list()) {
            std::cout << it.rhs << it.sym << it.lhs << '=';
            SymbolBase::display(it.value);
            if (col >= row) {
                col = 1;
                ++row;
                std::cout << '\n';
            } else {
                std::cout << '\t';
                ++col;
            }
        }
        std::cout << std::endl;
    }

    SymbolTable::exp::exp(char l, char r, char s, std::vector<char> v)
            : lhs(l), rhs(r), sym(s), value(std::move(v)) {}
}