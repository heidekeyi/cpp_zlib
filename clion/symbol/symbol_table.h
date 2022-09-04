//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_H
#define SYMBOL_SYMBOL_TABLE_H

#include <string>
#include <vector>
#include "symbol_base.h"

namespace ZLIB {
    class SymbolTable : public SymbolBase{
    protected:
        class exp {
        public:
            exp(char l, char r, char s, std::vector<char> v);
            char lhs;
            char rhs;
            char sym;
            std::vector<char> value;
        } ;

    public:
        virtual std::vector<exp> retrieve_table_list() = 0;
    public:
        void display() override;
    };
}


#endif //SYMBOL_SYMBOL_TABLE_H
