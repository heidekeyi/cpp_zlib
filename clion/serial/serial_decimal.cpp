//
// Created by 1213173752 on 2022/10/15.
//

#include "serial_decimal.h"

namespace ZLIB {
    SerialDecimal::SerialDecimal()
            : Serial("") {}

    SerialDecimal::SerialDecimal(const char *v)
            : Serial{v} {}

    SerialDecimal::SerialDecimal(const std::string &v)
            : Serial{v} {}

    SerialDecimal::SerialDecimal(const std::vector<char> &v)
            : Serial{v} {}

    SerialDecimal::SerialDecimal(const SerialValue &v)
            : Serial{v} {}

    SerialSymbols SerialDecimal::symbols() const {
        return SerialSymbols{"0123456789"};
    }

    SerialDecimal &SerialDecimal::operator+(const SerialDecimal &rhs) {
        return *this;
    }

    SerialDecimal &SerialDecimal::operator*(const SerialDecimal &rhs) {
        return *this;
    }

    void SerialDecimal::operator+=(const SerialDecimal &rhs) {
        serialValue = addition(rhs.serialValue);
    }

    void SerialDecimal::operator*=(const SerialDecimal &rhs) {

    }
}