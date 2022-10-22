//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_DRIVER_OPERAND_H
#define SERIAL_DRIVER_OPERAND_H

#include "operand.h"
#include "message.h"
#include <iostream>

namespace operand {
    using ZLIB::Operand;
    using ZLIB::Symbols;
    using ZLIB::Message;

    int test() {
        try {
            Operand o('a', Symbols{"0123456789"});
        } catch (const Message &message) {
            std::cout << message << std::endl;
        }
        Operand o('9', Symbols{"0123456789"});
        std::cout << "1st: " << o << std::endl;
        std::cout << "2st: " << o.operand() << std::endl;
        return 0;
    }

    auto _ = test();
}
#endif //SERIAL_DRIVER_OPERAND_H
