//
// Created by 1213173752 on 2022/10/25.
//

#ifndef SERIAL_DRIVER_CONTAINER_H
#define SERIAL_DRIVER_CONTAINER_H

#include "container.h"
#include <iostream>
#include "message.h"

namespace container {
    using namespace SERIAL;

    int test() {
        try {
            Symbols s{"0123456789"};
            Container c1{"012", s};
            std::cout << "1st: " << c1
                      << "\n2ed: " << c1.value("9002")
                      << std::endl;
            c1.value("");
        } catch (const Message &m) {
            std::cout << m << std::endl;
        }
        return 0;
    }

    auto _ = test();
}
#endif //SERIAL_DRIVER_CONTAINER_H
