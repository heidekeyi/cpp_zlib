//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_DRIVER_ACTION_H
#define SERIAL_DRIVER_ACTION_H

#include "action.h"
#include "message.h"
#include <iostream>

using ZLIB::Action;
using ZLIB::Message;
namespace action {
    int test() {
        try {
            Action o('-');
        } catch (const Message &message) {
            std::cout << message << std::endl;
        }
        Action o('*');
        std::cout << "1st: " << o << std::endl;
        std::cout << "2st: " << o.action() << std::endl;
        return 0;
    }

    auto _ = test();
}
#endif //SERIAL_DRIVER_ACTION_H
