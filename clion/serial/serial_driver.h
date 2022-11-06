//
// Created by 1213173752 on 2022/10/30.
//

#ifndef SERIAL_SERIAL_DRIVER_H
#define SERIAL_SERIAL_DRIVER_H

#include "serial.h"
#include <iostream>

namespace DRIVER {
    using namespace SERIAL;

    int test() {
        const auto &fn = SYMBOLS_CALLBACK::dec;
        Serial<fn> s1{"1927"};
        Serial<fn> s2{"1198"};
        std::cout << "1st: " << s1 + s2
                  << "\n2nd: " << s1 * s2
                  << std::endl;
        return 0;
    }

    auto _ = test();
}
#endif //SERIAL_SERIAL_DRIVER_H
