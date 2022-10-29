//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_SERIAL_DRIVER_H
#define SERIAL_SERIAL_DRIVER_H

#include "store.h"
#include "../serial.h"
#include "../message.h"
#include <iostream>


using namespace SERIAL::SERIAL;
using namespace SERIAL::MESSAGE;

namespace DRIVER::SERIAL {
    const char *dec() {
        return "0123456789";
    }

    int test() {
        try {
            Serial<dec> serial{"a"};
        } catch (const Message &m) {
            std::cout << "1st: " << m << std::endl;
        }
        Serial<dec> store;
        std::cout << "2ed: " << store << std::endl;
        return 0;
    }

    auto _{test()};
}

#endif //SERIAL_SERIAL_DRIVER_H
