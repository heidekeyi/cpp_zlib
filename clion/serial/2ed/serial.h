//
// Created by 1213173752 on 2022/10/25.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include "symbols.h"
#include "container.h"
#include <ostream>

namespace SERIAL {
    template<const char *(*fn)()>
    class Serial {
    public:
        explicit Serial(const std::vector<char> &c);

        explicit Serial(const std::string &c);

    public:
        Serial<fn> operator+(const Serial<fn> &rhs) const;

        Serial<fn> operator*(const Serial<fn> &rhs) const;

        Serial<fn> &operator+=(const Serial<fn> &rhs);

        Serial<fn> &operator*=(const Serial<fn> &rhs);

    public:
        [[nodiscard]] const Container &container() const;

    private:
        const Symbols m_symbols;
        Container m_container;
    };

    template<const char *(*fn)()>
    Serial<fn>::Serial(const std::string &c)
            :m_container(c, Symbols{fn()}), m_symbols(fn()) {}

    template<const char *(*fn)()>
    Serial<fn>::Serial(const std::vector<char> &c)
            :m_container(c, Symbols{fn()}), m_symbols(fn()) {}

    template<const char *(*fn)()>
    Serial<fn> Serial<fn>::operator+(const Serial<fn> &rhs) const {
        return rhs;
    }

    template<const char *(*fn)()>
    Serial<fn> Serial<fn>::operator*(const Serial<fn> &rhs) const {
        return rhs;
    }

    template<const char *(*fn)()>
    Serial<fn> &Serial<fn>::operator+=(const Serial<fn> &rhs) {
        return *this;
    }

    template<const char *(*fn)()>
    Serial<fn> &Serial<fn>::operator*=(const Serial<fn> &rhs) {
        return *this;
    }

    template<const char *(*fn)()>
    const Container &Serial<fn>::container() const {
        return m_container;
    }

    template<const char *(*fn)()>
    std::ostream &operator<<(std::ostream &os, const Serial<fn> &o) {
        return os << o.container();
    }
}
#endif //SERIAL_SERIAL_H
