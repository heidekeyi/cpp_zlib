//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_DRIVER_SYMBOLS_H
#define SERIAL_DRIVER_SYMBOLS_H

#include <iostream>
#include "symbols.h"
#include "message.h"

namespace symbols{
    using ZLIB::Symbols;
    using ZLIB::Message;

    void length(const std::string &s) {
        try {
            Symbols symbols(s);
        } catch (const Message &o) {
            std::cout << "string: " << o << std::endl;
        }
    }

    void length() {
        length(std::string{"0"});
        length(std::string{"abcdefghijklmnopqrstuvwxyz0123456789"});
    }

    void unique() {
        std::string s{};
        try {
            s = std::string{};
            Symbols symbols(s);
        } catch (const Message &o) {
            std::cout << s << ": " << o << std::endl;
        }
    }

    void visibility() {
        const char *s = "";
        try {
            s = "\r\t\n";
            Symbols symbols(s);
        } catch (const Message &o) {
            std::cout << R"(\r\t\n)" << ": " << o << std::endl;
        }
    }

    void has() {
        Symbols symbols{std::string{"01"}};
        std::cout << (symbols.has('1') ? "" : "not") << " has" << std::endl;
        std::cout << (symbols.has('2') ? "" : "not") << " has" << std::endl;
    }

    int driver_symbols() {
        std::cout << "+++++++++" << std::endl;
        length();
        std::cout << "---------" << std::endl;
        std::cout << "+++++++++" << std::endl;
        unique();
        std::cout << "---------" << std::endl;
        std::cout << "+++++++++" << std::endl;
        visibility();
        std::cout << "---------" << std::endl;
        std::cout << "+++++++++" << std::endl;
        has();
        std::cout << "---------" << std::endl;
        return 0;
    }
    auto _ = driver_symbols();
}


#endif //SERIAL_DRIVER_SYMBOLS_H
