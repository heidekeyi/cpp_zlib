//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_MESSAGE_DRIVER_H
#define SERIAL_MESSAGE_DRIVER_H

#include "message.h"
#include <iostream>

namespace MESSAGE {
    using namespace SERIAL;

    int test() {
        std::cout << "1st: " << Message{"hello world!"} << std::endl;
        return 0;
    }

    auto _{test()};
}

#endif //SERIAL_MESSAGE_DRIVER_H
