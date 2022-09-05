//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table.h"
#include <iostream>
#include "symbol_list.h"

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

    SymbolTable::Expression::Expression(char l, char r, char s, std::vector<char> v)
            : lhs(l), rhs(r), sym(s), value(std::move(v)) {}

    std::vector<SymbolTable::Expression> SymbolTable::retrieve_table_list() {
        std::vector<SymbolTable::Expression> table_list;
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
                switch (retrieve_action()) {
                    case Action::add:
                        table_list.emplace_back(lhs, rhs, '+', list[lhs_index + rhs_index]);
                        break;
                    case Action::sub:
                        std::cout << "sub is not impl" << std::endl;
                        break;
                    case Action::mul:
                        table_list.emplace_back(lhs, rhs, '*', list[lhs_index * rhs_index]);
                        break;
                    case Action::div:
                        std::cout << "div is not impl" << std::endl;
                        break;
                    default:
                        break;
                }
                if (lhs_index <= rhs_index) {
                    break;
                }
            }
        }
        return table_list;
    }
}