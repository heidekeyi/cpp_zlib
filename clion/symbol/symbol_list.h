//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_LIST_H
#define SYMBOL_SYMBOL_LIST_H

#include <string>
#include <vector>

namespace ZLIB {
    class SymbolList {
    public:
        SymbolList &symbol(const std::string &sym);

        SymbolList &symbol(const char *sym);

        const std::vector<char> &symbol() const;

        int minNum() const;

        SymbolList &minNum(int n);

        const std::vector<std::vector<char>> &list();

    public:
        void display();

    protected:
        void retrieve_list();

        void add(int index);

    protected:
        std::vector<char> valueSymbol;
        int valueMinNum;
        std::vector<std::vector<char>> valueList;
    };
}

#endif //SYMBOL_SYMBOL_LIST_H
