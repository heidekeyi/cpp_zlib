#include <iostream>
#include "accumulator.h"
#include <vector>
#include "sequence_table.h"

namespace ZLIB {
    void test() {
        SequenceTable::display("201", 108);
    }
}

int main() {
    ZLIB::test();
    return 0;
}
