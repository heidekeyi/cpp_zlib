//
// Created by 1213173752 on 2022/10/13.
//

#ifndef SERIAL_SERIAL_VALUE_H
#define SERIAL_SERIAL_VALUE_H

#include <vector>
#include <string>
#include <iostream>

namespace ZLIB {
    class SerialValue {
    public:
        static std::vector<char> convert(const std::string &s);

    public:
        explicit SerialValue(std::vector<char> v);

        explicit SerialValue(const std::string &v);

        explicit SerialValue(char v);

    public:
        [[nodiscard]] const std::vector<char> &retrieve() const;

    private:
        const std::vector<char> value;
    };

    std::ostream &operator<<(std::ostream &os, const SerialValue &ob);
}

#endif //SERIAL_SERIAL_VALUE_H
