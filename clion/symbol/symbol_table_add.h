//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_ADD_H
#define SYMBOL_SYMBOL_TABLE_ADD_H

#include <string>
#include <vector>
#include "symbol_list.h"
namespace ZLIB {
    class SymbolTableAdd {
    public:
        SymbolTableAdd &symbol(const char *sym);

        SymbolTableAdd &symbol(const std::string &sym);

        const std::vector<char> &symbol() const;

    public:
        void display();

    protected:
        void retrieve_table();

        int retrieve_index(char ch);

    private:
        std::vector<char> valueSymbol;
        std::vector<std::vector<std::vector<char>>> valueTable;
        SymbolList valueSymbolList;
    };
}

#endif //SYMBOL_SYMBOL_TABLE_ADD_H
