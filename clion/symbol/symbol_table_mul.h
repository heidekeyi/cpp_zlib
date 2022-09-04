//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_MUL_H
#define SYMBOL_SYMBOL_TABLE_MUL_H

#include "symbol_table.h"

namespace ZLIB {
    class SymbolTableMul : public SymbolTable {
    public:
        std::vector<exp> retrieve_table_list() override;

    protected:
        void retrieve_table();
    };
}

#endif //SYMBOL_SYMBOL_TABLE_MUL_H
