//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_DRIVER_SYMBOLS_H
#define SERIAL_DRIVER_SYMBOLS_H

#include <iostream>
#include "symbols.h"
#include "message.h"

namespace symbols {
    using SERIAL::Symbols;
    using SERIAL::Message;

    int driver_symbols() {
        try {
            Symbols symbols("1");
        } catch (const Message &o) {
            std::cout << "1st: " << o << std::endl;
        }
        try {
            Symbols symbols("abcdefghijklmnopqrstuvwxyz0123456789");
        } catch (const Message &o) {
            std::cout << "2ed: " << o << std::endl;
        }
        try {
            Symbols symbols("\n\t");
        } catch (const Message &o) {
            std::cout << "3rd: " << o << std::endl;
        }
        try {
            Symbols symbols("aa");
        } catch (const Message &o) {
            std::cout << "4th: " << o << std::endl;
        }
        Symbols symbols{"0123"};
        std::cout << "5th: " << symbols.has('2')
                  << "\n6th: " << symbols.has('a')
                  << "\n7th: " << symbols
                  << "\n8th: " << symbols.symbols()
                  << "\n9th: " << symbols.symbols("01")
                  << std::endl;
        return 0;
    }

    auto _ = driver_symbols();
}


#endif //SERIAL_DRIVER_SYMBOLS_H
