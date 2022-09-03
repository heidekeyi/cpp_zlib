//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_H
#define SYMBOL_SYMBOL_TABLE_H

#include <string>
#include <vector>
#include "symbol_list.h"


namespace ZLIB {
    class SymbolTable {
    public:
        SymbolTable &symbol(const char *sym);

        SymbolTable &symbol(const std::string &sym);

        const std::vector<char> &symbol() const;

    public:
        virtual void display() = 0;

    protected:
        int retrieve_index(char ch);

    protected:
        std::vector<char> valueSymbol;
        std::vector<std::vector<std::vector<char>>> valueTable;
        SymbolList valueSymbolList;
    };
}


#endif //SYMBOL_SYMBOL_TABLE_H
