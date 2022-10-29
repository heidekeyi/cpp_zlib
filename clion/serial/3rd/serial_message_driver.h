//
// Created by 1213173752 on 2022/10/26.
//

#ifndef SERIAL_SERIAL_MESSAGE_DRIVER_H
#define SERIAL_SERIAL_MESSAGE_DRIVER_H

#include "serial_message.h"
#include <iostream>

namespace serial_message_driver {
    using namespace SERIAL_MESSAGE;

    auto _ = ([] {
        SerialMessage serialMessage{"hello world"};
        std::cout << "1st: " << serialMessage
                  << "\n2ed: " << serialMessage.what()
                  << std::endl;
        return 0;
    })();
}

#endif //SERIAL_SERIAL_MESSAGE_DRIVER_H
