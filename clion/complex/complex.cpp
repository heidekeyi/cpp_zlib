//
// Created by 12131 on 2022/8/5.
//

#include "complex.h"

namespace ZLIB {
    complex &complex::operator+=(const complex &rhs) {
        re += rhs.re;
        im += rhs.im;
        return *this;
    }

    complex &complex::operator-=(const complex &rhs) {
        re -= rhs.re;
        im -= rhs.im;
        return *this;
    }

    complex &complex::operator*=(const complex &rhs) {
        re *= rhs.re;
        im *= rhs.im;
        return *this;
    }

    complex &complex::operator/=(const complex &rhs) {
        re /= rhs.re;
        im /= rhs.im;
        return *this;
    }

    complex operator+(const complex &lhs, const complex &rhs) {
        return complex{lhs.re + rhs.re, lhs.im + rhs.im};
    }

    complex operator-(const complex &lhs, const complex &rhs) {
        return complex{lhs.re - rhs.re, lhs.im - rhs.im};
    }

    complex operator*(const complex &lhs, const complex &rhs) {
        return complex{lhs.re * rhs.re, lhs.im * rhs.im};
    }

    complex operator/(const complex &lhs, const complex &rhs) {
        return complex{lhs.re / rhs.re, lhs.im / rhs.im};
    }

    complex operator-(const complex &rhs) {
        return complex{-rhs.re, -rhs.im};
    }

    bool operator==(const complex &lhs, const complex &rhs) {
        return lhs.re == rhs.re && lhs.im == rhs.im;
    }

    bool operator!=(const complex &lhs, const complex &rhs) {
        return !(lhs == rhs);
    }
}
