//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_DRIVER_VALUE_H
#define SERIAL_DRIVER_VALUE_H

#include "value.h"
#include "message.h"
#include <iostream>

namespace value {
    using ZLIB::Value;
    using ZLIB::Symbols;
    using ZLIB::Message;

    void init() {
        try {
            Value v(std::vector<char>{'a'}, Symbols{"0123456789"});
        } catch (const Message &message) {
            std::cout << message << std::endl;
        }
    }

    void range() {
        try {
            Value v(std::vector<char>{'0'}, Symbols{"0123456789"});
            v[1] = '9';
        } catch (const Message &message) {
            std::cout << message << std::endl;
        }
        try {
            Value v(Symbols{"0123456789"});
            v.value(std::vector<char>{'a'});
        } catch (const Message &message) {
            std::cout << message << std::endl;
        }
    }

    void change() {
        Value v(std::vector<char>{'9', '6'}, Symbols{"0123456789"});
        std::cout << "1st: " << v << '\n';
        v[1] = '3';
        std::cout << "2ed: " << v << '\n';
        v.value(std::vector<char>{'0', '1', '2'});
        std::cout << "3rd: " << v << '\n';
    }

    int test() {
        std::cout << "+++++++++" << std::endl;
        init();
        std::cout << "---------" << std::endl;
        std::cout << "+++++++++" << std::endl;
        range();
        std::cout << "---------" << std::endl;
        std::cout << "+++++++++" << std::endl;
        change();
        std::cout << "---------" << std::endl;
        return 0;
    }

    auto _ = test();
}

#endif //SERIAL_DRIVER_VALUE_H
