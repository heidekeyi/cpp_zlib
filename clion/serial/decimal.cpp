//
// Created by 1213173752 on 2022/10/20.
//

#include "decimal.h"

namespace ZLIB {
    Symbols Decimal::symbols() const {
        return Symbols{std::string{"0123456789"}};
    }

    Decimal Decimal::operator+(const Decimal &rhs) {
        return Decimal();
    }

    Decimal Decimal::operator*(const Decimal &rhs) {
        return Decimal();
    }

    Decimal &Decimal::operator*=(const Decimal &rhs) {
        return *this;
    }

    Decimal &Decimal::operator+=(const Decimal &rhs) {
        return *this;
    }
}