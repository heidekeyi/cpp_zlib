#include "symbol_list.h"
#include "symbol_table_add.h"
#include "symbol_table_mul.h"

namespace ZLIB {
    void test() {
        const char *sym = "01234567";
        SymbolList symbolList;
        symbolList.symbol(sym).minNum(1).display();
        SymbolTableAdd symbolTableAdd;
        symbolTableAdd.symbol(sym).display();
        SymbolTableMul symbolTableMul;
        symbolTableMul.symbol(sym).display();
    }
}

int main() {
    ZLIB::test();
    return 0;
}
