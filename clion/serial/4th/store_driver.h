//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_STORE_DRIVER_H
#define SERIAL_STORE_DRIVER_H

#include "store.h"
#include "../message.h"
#include <iostream>

namespace DRIVER::STORE {
    using namespace SERIAL::STORE;
    using namespace SERIAL::MESSAGE;

    const char *dec() {
        return "0123456789";
    }

    int test() {
        try {
            Store<dec> store{"a"};
        } catch (const Message &m) {
            std::cout << "1st: " << m << std::endl;
        }
        Store<dec> store{""};
        std::cout << "2ed: " << store
                  << "\n3rd: " << store.store("01")
                  << "\n4th: " << store.store("012")
                  << std::endl;
        return 0;
    }

    auto _{test()};
}
#endif //SERIAL_STORE_DRIVER_H
