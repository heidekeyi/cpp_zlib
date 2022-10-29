//
// Created by 1213173752 on 2022/10/24.
//

#ifndef SERIAL_DRIVER_SERIAL_H
#define SERIAL_DRIVER_SERIAL_H

#include <iostream>
#include "serial.h"

namespace serial {
    using namespace ZLIB;

    int test() {
        try {
            Symbols symbols{"0123456789"};
            Serial _{symbols, ""};
        } catch (const Message &m) {
            std::cout << "1st: " << m << std::endl;
        }
        try {
            Symbols symbols{"0123456789"};
            Serial s{symbols, "012"};
            std::cout << "2ed: " << s
                      << "\n3rd: " << s.serial("9002")
                      << std::endl;
            s.serial("abc");
        } catch (const Message &m) {
            std::cout << "4th: " << m << std::endl;
        }
        return 0;
    }

    auto _ = test();
}

#endif //SERIAL_DRIVER_SERIAL_H
