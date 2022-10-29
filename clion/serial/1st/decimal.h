//
// Created by 1213173752 on 2022/10/24.
//

#ifndef SERIAL_DECIMAL_H
#define SERIAL_DECIMAL_H

#include <vector>
#include <string>
#include "../2ed/symbols.h"
#include "serial.h"

namespace ZLIB {
    class Decimal {
    private:
        static const Symbols ms_symbols;
    public:
        explicit Decimal(const std::string &serial);

        explicit Decimal(const std::vector<char> &serial);

        explicit Decimal(Serial serial);

    public:
        Decimal operator+(const Decimal &rhs) const;

        Decimal operator*(const Decimal &rhs) const;

        Decimal &operator+=(const Decimal &rhs);

        Decimal &operator*=(const Decimal &rhs);

    public:
        Decimal &serial(const std::vector<char> &s);

        Decimal &serial(const std::string &s);

        Decimal &serial(const Serial &s);

        [[nodiscard]] const Serial &serial() const;

    private:
        Serial m_serial;
    };
}
#endif //SERIAL_DECIMAL_H
