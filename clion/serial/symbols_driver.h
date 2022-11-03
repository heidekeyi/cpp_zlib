//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_SYMBOLS_DRIVER_H
#define SERIAL_SYMBOLS_DRIVER_H

#include "message.h"
#include <iostream>
#include "symbols.h"

namespace SYMBOLS {
    using namespace SERIAL;

    const char *empty() {
        return "";
    }

    const char *one() {
        return "0";
    }

    const char *repeat() {
        return "hello";
    }

    int test() {
        try {
            Symbols symbols{empty};
        } catch (const Message &m) {
            std::cout << "1st: " << m << std::endl;
        }
        try {
            Symbols symbols{one};
        } catch (const Message &m) {
            std::cout << "2nd: " << m << std::endl;
        }
        try {
            Symbols symbols{repeat};
        } catch (const Message &m) {
            std::cout << "3rd: " << m << std::endl;
        }
        Symbols symbols{SYMBOLS::SYMBOLS_CALLBACK::hex};
        std::cout << "4th: " << symbols
                  << "\n5th: " << symbols.find('9')
                  << "\n6th: " << symbols.find('.')
                  << std::endl;
        return 0;
    }

    auto _{test()};
}
#endif //SERIAL_SYMBOLS_DRIVER_H
