//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_mul.h"

namespace ZLIB {
    SymbolTable::Action SymbolTableMul::retrieve_action()const{
        return SymbolTable::Action::mul;
    }
}