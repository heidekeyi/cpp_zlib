//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_DRIVER_SYMBOLS_H
#define SERIAL_DRIVER_SYMBOLS_H

#include <iostream>
#include "symbols.h"
#include "message.h"

namespace {
    using ZLIB::Symbols;
    using ZLIB::Message;

    void length(const char *s) {
        try {
            Symbols symbols(s);
        } catch (const Message &o) {
            std::cout << "const char *: " << o << std::endl;
        }
    }

    void length(const std::string &s) {
        try {
            Symbols symbols(s);
        } catch (const Message &o) {
            std::cout << "string: " << o << std::endl;
        }
    }

    void length(const std::vector<char> &s) {
        try {
            Symbols symbols(s);
        } catch (const Message &o) {
            std::cout << "vector<char>: " << o << std::endl;
        }
    }

    void length() {
        length("0");
        length("abcdefghijklmnopqrstuvwxyz0123456789");
        length(std::string{"0"});
        length(std::string{"abcdefghijklmnopqrstuvwxyz0123456789"});
        length(std::vector<char>{'0'});
        length(std::vector<char>{
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
        });
    }

    void unique() {
        const char *s = "";
        try {
            s = "11";
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
        return 0;
    }

    auto v = driver_symbols();
}


#endif //SERIAL_DRIVER_SYMBOLS_H
