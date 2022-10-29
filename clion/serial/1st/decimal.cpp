//
// Created by 1213173752 on 2022/10/24.
//

#include "decimal.h"

#include <utility>

namespace ZLIB {
    const Symbols Decimal::ms_symbols = Symbols("0123456789");

    Decimal::Decimal(const std::string &serial)
            : m_serial(ms_symbols, serial) {}

    Decimal::Decimal(const std::vector<char> &serial)
            : m_serial(ms_symbols, serial) {}

    Decimal::Decimal(Serial serial)
            : m_serial(std::move(serial)) {}

    Decimal Decimal::operator+(const Decimal &rhs) const {
        return Decimal{m_serial + rhs.m_serial};
    }

    Decimal Decimal::operator*(const Decimal &rhs) const {
        return Decimal{m_serial * rhs.m_serial};
    }

    Decimal &Decimal::operator+=(const Decimal &rhs) {
        return *this = operator+(rhs);
    }

    Decimal &Decimal::operator*=(const Decimal &rhs) {
        return *this = operator*(rhs);
    }

    Decimal &Decimal::serial(const std::vector<char> &s) {
        return serial(Serial{ms_symbols, s});
    }

    Decimal &Decimal::serial(const std::string &s) {
        return serial(Serial{ms_symbols, s});
    }

    Decimal &Decimal::serial(const Serial &s) {
        m_serial = s;
        return *this;
    }

    const Serial &Decimal::serial() const {
        return m_serial;
    }
}