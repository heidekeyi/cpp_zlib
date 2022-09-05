//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_MUL_H
#define SYMBOL_SYMBOL_TABLE_MUL_H

#include "symbol_table.h"

namespace ZLIB {
    class SymbolTableMul : public SymbolTable {
    public:
        [[nodiscard]] Action retrieve_action() const override;
//        std::vector<Expression> retrieve_table_list() override;
    };
}
#endif //SYMBOL_SYMBOL_TABLE_MUL_H
