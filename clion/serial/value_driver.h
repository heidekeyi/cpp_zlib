//
// Created by 1213173752 on 2022/10/29.
//

#ifndef SERIAL_VALUE_DRIVER_H
#define SERIAL_VALUE_DRIVER_H

#include <iostream>
#include "value.h"

namespace VALUE {
    using namespace SERIAL;
    using Dec = Value<POINTER::dec>;

    int test() {
        try {
            Dec dec{"a"};
        } catch (const Message &m) {
            std::cout << "1st: " << m << std::endl;
        }
        Dec dec{};
        std::cout << "2ed: " << dec
                  << "\n3rd: " << dec.value("9002")
                  << std::endl;
        return 0;
    }

    auto _{test()};
}

#endif //SERIAL_VALUE_DRIVER_H
