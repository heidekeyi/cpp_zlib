//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_DECIMAL_H
#define SERIAL_DECIMAL_H

#include "serial.h"

namespace ZLIB {
    class Decimal : public Serial {
    public:
        Decimal operator+(const Decimal &rhs);

        Decimal operator*(const Decimal &rhs);

        Decimal &operator*=(const Decimal &rhs);

        Decimal &operator+=(const Decimal &rhs);

    protected:
        [[nodiscard]] Symbols symbols() const override;
    };
}

#endif //SERIAL_DECIMAL_H
