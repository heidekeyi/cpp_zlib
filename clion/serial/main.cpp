#include <iostream>
#include "serial_table.h"
#include "serial_formula.h"
#include "serial_value.h"

namespace ZLIB {
    void test();
}

int main() {
    ZLIB::test();
    return 0;
}

namespace ZLIB {
    void test() {
        std::cout << SerialTable::sequence("01", 18);
    }
}
