//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include <string>
#include <vector>
#include "value.h"

namespace SERIAL {
    template<Pointer ptr>
    class Serial {
    public:
        explicit Serial(const Value<ptr> &s) : m_value{s} {}

        explicit Serial(const std::string &s) : m_value{s} {}

        explicit Serial(const std::vector<char> &s) : m_value{s} {}

    public:
        const Value<ptr> &value() const { return m_value; }

    public:
        Serial<ptr> &operator+=(const Serial<ptr> &rhs);

        Serial<ptr> &operator*=(const Serial<ptr> &rhs);

        Serial<ptr> operator+(const Serial<ptr> &rhs);

        Serial<ptr> operator*(const Serial<ptr> &rhs);

    private:
        Value<ptr> m_value;
    };

    template<Pointer ptr>
    Serial<ptr> &Serial<ptr>::operator+=(const Serial<ptr> &rhs) {
        return *this = operator+(rhs);
    }

    template<Pointer ptr>
    Serial<ptr> &Serial<ptr>::operator*=(const Serial<ptr> &rhs) {
        return *this = operator*(rhs);
    }

    template<Pointer ptr>
    Serial<ptr> Serial<ptr>::operator+(const Serial<ptr> &rhs) {
        return *this;
    }

    template<Pointer ptr>
    Serial<ptr> Serial<ptr>::operator*(const Serial<ptr> &rhs) {
        return *this;
    }

    template<Pointer ptr>
    std::ostream &operator<<(std::ostream &os, const Serial<ptr> &o) {
        return os << o.value();
    }
}

#endif //SERIAL_SERIAL_H
