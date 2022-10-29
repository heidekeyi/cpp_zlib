//
// Created by 1213173752 on 2022/10/25.
//

#ifndef SERIAL_DRIVER_DECIMAL_H
#define SERIAL_DRIVER_DECIMAL_H

#include "decimal.h"
#include <iostream>

namespace decimal {
    using namespace SERIAL;

    int test() {
        Decimal d1{"012"};
        std::cout << "1st: " << d1
                  << "\n2ed: " << d1.container()
                  << std::endl;
        return 0;
    }

    auto _ = test();
}
#endif //SERIAL_DRIVER_DECIMAL_H
