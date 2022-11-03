//
// Created by 1213173752 on 2022/10/31.
//

#ifndef SERIAL_TABLE_DRIVER_H
#define SERIAL_TABLE_DRIVER_H

#include "table.h"
#include <iostream>

namespace TABLE {
    using namespace SERIAL;

    int test() {
        Table table{SYMBOLS_CALLBACK::dec};
        table.display_list(102);
        table.display_table_addition();
        table.display_table_multiplication();
        return 0;
    }

    auto _ = test();
}
#endif //SERIAL_TABLE_DRIVER_H
