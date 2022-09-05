//
// Created by 12131 on 2022/9/3.
//

#include "symbol_table_add.h"

namespace ZLIB {
    SymbolTable::Action SymbolTableAdd::retrieve_action()const{
        return SymbolTable::Action::add;
    }
}