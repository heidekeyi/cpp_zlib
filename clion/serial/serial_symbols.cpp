//
// Created by 1213173752 on 2022/10/14.
//
#include <iostream>
#include "serial_symbols.h"

namespace ZLIB {
    SerialSymbols::SerialSymbols(const char *s)
            : value{convert(s)} {}

    SerialSymbols::SerialSymbols(const std::string &s)
            : value{convert(s)} {}

    SerialSymbols::SerialSymbols(const std::vector<char> &s)
            : value{convert(s)} {}

    const std::vector<char> &SerialSymbols::retrieve() const {
        return value;
    }

    std::vector<char> SerialSymbols::convert(const char *s) {
        std::vector<char> v;
        while (*s) {
            v.push_back(*s);
            ++s;
        }
        return convert(v);
    }

    std::vector<char> SerialSymbols::convert(const std::string &s) {
        std::vector<char> v;
        for (auto c: s) {
            v.push_back(c);
        }
        return convert(v);
    }

    std::vector<char> SerialSymbols::convert(const std::vector<char> &s) {
        std::vector<char> vec;
        for (auto item: s) {
            auto status = true;
            for (auto it: vec) {
                if (it == item) {
                    status = false;
                }
            }
            if (status) {
                vec.push_back(item);
            }
        }
        return vec;
    }

    std::ostream &operator<<(std::ostream &os, const SerialSymbols &o) {
        for (auto c: o.retrieve()) {
            os << c;
        }
        return os;
    }
}