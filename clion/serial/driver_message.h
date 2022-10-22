//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_DRIVER_MESSAGE_H
#define SERIAL_DRIVER_MESSAGE_H

#include "message.h"
#include <iostream>

namespace message{
    using ZLIB::Message;

    int test() {
        Message message{"hello world"};
        std::cout << "1st: " << message.what() << "\n"
                  << "2ed: " << message << std::endl;
        return 0;
    }

    auto _ = test();
}

#endif //SERIAL_DRIVER_MESSAGE_H
