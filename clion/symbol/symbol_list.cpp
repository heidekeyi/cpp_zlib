//
// Created by 12131 on 2022/9/3.
//

#include "symbol_list.h"
#include <iostream>

namespace ZLIB {
    void SymbolList::display() {
        display(108);
    }

    void SymbolList::display(int num) {
        int cnt = 1;
        auto size = symbol().size();
        for (auto &it: retrieve_list(num)) {
            SymbolBase::display(it);
            if (cnt >= size) {
                std::cout << '\n';
                cnt = 1;
            } else {
                std::cout << '\t';
                ++cnt;
            }
        }
        std::cout << std::endl;
    }

    void SymbolList::add(std::vector<char> &value, const std::vector<char> &sym, int index) {
        //overflow, up 1 bit
        if (index >= value.size()) {
            value.push_back(sym[1]);
            return;
        }
        int pos = 0;
        //find next char
        while (value[index] != sym[pos++]);
        value[index] = sym[pos];
        if (sym[pos] == sym[0]) {
            add(value, sym, index + 1);
        }
    }

    std::vector<std::vector<char>> SymbolList::retrieve_list(int num) {
        std::vector<char> sym = symbol();
        auto sz = symbol().size();
        sym.push_back(symbol()[0]);
        auto size = sym.size();
        size *= size;
        if (size < num) {
            size = num;
        }
        std::vector<std::vector<char>> list;
        for (auto it: symbol()) {
            list.push_back(std::vector<char>{it});
        }
        while (list.size() < size) {
            auto value = list[list.size() - 1];
            add(value, sym, 0);
            list.push_back(value);
        }
        return list;
    }
}