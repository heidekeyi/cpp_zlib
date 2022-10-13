//
// Created by 1213173752 on 2022/10/13.
//

#ifndef SERIAL_SERIAL_VALUE_H
#define SERIAL_SERIAL_VALUE_H

#include <vector>
#include <iostream>

namespace ZLIB {
    class SerialValue {
    public:
        explicit SerialValue(std::vector<char> v);

        explicit SerialValue(char ch);

        SerialValue(const SerialValue &rhs) = default;

    public:
        const std::vector<char> value;
    };

    std::ostream &operator<<(std::ostream &os, const SerialValue &ob);
}

#endif //SERIAL_SERIAL_VALUE_H
