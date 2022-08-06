//
// Created by 12131 on 2022/8/5.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

namespace ZLIB {
    class complex {
        friend complex operator+(const complex &lhs, const complex &rhs);

        friend complex operator-(const complex &lhs, const complex &rhs);

        friend complex operator*(const complex &lhs, const complex &rhs);

        friend complex operator/(const complex &lhs, const complex &rhs);

        friend complex operator-(const complex &rhs);

    public:
        friend bool operator==(const complex &lhs, const complex &rhs);

        friend bool operator!=(const complex &lhs, const complex &rhs);

    private:
        double re, im;
    public:
        complex() : re{0}, im{0} {}

        explicit complex(double r) : re{r}, im{0} {}

        explicit complex(double r, double i) : re{r}, im{i} {}

    public:
        double real() const { return re; }

        void real(double r) { re = r; }

        double imag() const { return im; };

        void imag(double i) { im = i; }

    public:
        complex &operator+=(const complex &rhs);

        complex &operator-=(const complex &rhs);

        complex &operator*=(const complex &rhs);

        complex &operator/=(const complex &rhs);
    };
}

#endif //COMPLEX_COMPLEX_H
