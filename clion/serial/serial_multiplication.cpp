//
// Created by 1213173752 on 2022/10/15.
//

#include "serial_multiplication.h"

namespace ZLIB {

    SerialMultiplication::SerialMultiplication(const std::vector<char> &s)
            : SerialTable{s} {}

    SerialMultiplication::SerialMultiplication(const std::string &s)
            : SerialTable{s} {}

    SerialMultiplication::SerialMultiplication(const char *s)
            : SerialTable{s} {}

    std::vector<SerialFormula> SerialMultiplication::table() const {
        auto sym = symbols().retrieve();
        auto list = sequence().table();
        std::vector<SerialFormula> vec;
        for (int i = 0; i < sym.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                vec.emplace_back(sym[j], '*', sym[i], list[i * j]);
            }
        }
        return vec;
    }
}