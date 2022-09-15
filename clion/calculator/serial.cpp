//
// Created by 12131 on 2022/9/14.
//

#include "serial.h"
#include <iostream>

namespace ZLIB {
    void Serial::display() const {
        auto val = value();
        if (val.empty()) {
            return;
        }
        auto index = val.size();
        while (--index > 0) {
            std::cout << val[index];
        }
        std::cout << val[index];
    }


    std::vector<char> Serial::value() const {
        return m_value;
    }

    SerialSequence Serial::sequence() const {
        return {"", 0};
    }

    SerialTable Serial::table() const {
        return {""};
    }
}