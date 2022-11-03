//
// Created by 1213173752 on 2022/10/29.
//

#ifndef SERIAL_VALUE_DRIVER_H
#define SERIAL_VALUE_DRIVER_H

#include <iostream>
#include "value.h"

namespace VALUE {
    using namespace SERIAL;

    int test() {
        auto fn = SYMBOLS_CALLBACK::dec;
        try {
            Value v(fn, std::string{"a"});
        } catch (const Message &m) {
            std::cout << "1st: " << m << std::endl;
        }
        Value v{fn};
        std::cout << "2ed: " << v
                  << "\n3rd: " << v.value("2009")
                  << "\n4th: " << v.value("2009", false)
                  << std::endl;
        return 0;
    }

    auto _{test()};
}

#endif //SERIAL_VALUE_DRIVER_H
