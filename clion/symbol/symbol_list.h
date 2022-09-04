//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_LIST_H
#define SYMBOL_SYMBOL_LIST_H

#include <string>
#include <vector>
#include "symbol_base.h"

namespace ZLIB {
    class SymbolList : public SymbolBase {
    public:
        std::vector<std::vector<char>> retrieve_list(int num = 108);

    public:
        void display() override;

        void display(int num = 108);

    protected:
        void add(std::vector<char> &value, const std::vector<char> &sym, int index);
    };
}

#endif //SYMBOL_SYMBOL_LIST_H
