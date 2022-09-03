#include "symbol_list.h"
#include "symbol_table_add.h"

namespace ZLIB {
    void test() {
        const char *sym = "0123456789";
        SymbolList symbolList;
        symbolList.symbol(sym).minNum(1).display();
        SymbolTableAdd symbolTableAdd;
        symbolTableAdd.symbol(sym).display();
    }
}

int main() {
    ZLIB::test();
    return 0;
}
