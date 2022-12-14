//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_ADD_H
#define SYMBOL_SYMBOL_TABLE_ADD_H

#include <string>
#include <vector>
#include "symbol_table.h"

namespace ZLIB {
    class SymbolTableAdd : public SymbolTable {
    public:
        [[nodiscard]] Action retrieve_action()const override;
//        std::vector<Expression> retrieve_table_list() override;
    };
}

#endif //SYMBOL_SYMBOL_TABLE_ADD_H
