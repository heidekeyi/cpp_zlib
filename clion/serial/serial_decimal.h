//
// Created by 1213173752 on 2022/10/15.
//

#ifndef SERIAL_SERIAL_DECIMAL_H
#define SERIAL_SERIAL_DECIMAL_H

#include <vector>
#include <string>
#include "serial.h"

namespace ZLIB {
    class SerialDecimal : public Serial {
    public:
        SerialDecimal();

        explicit SerialDecimal(const char *v);

        explicit SerialDecimal(const std::string &v);

        explicit SerialDecimal(const std::vector<char> &v);

        explicit SerialDecimal(const SerialValue &v);

    public:
        SerialDecimal &operator+(const SerialDecimal &rhs);

        SerialDecimal &operator*(const SerialDecimal &rhs);

        void operator+=(const SerialDecimal &rhs);

        void operator*=(const SerialDecimal &rhs);

    protected:
        [[nodiscard]] SerialSymbols symbols() const override;
    };
}

#endif //SERIAL_SERIAL_DECIMAL_H
