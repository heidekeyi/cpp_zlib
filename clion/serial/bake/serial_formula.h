//
// Created by 1213173752 on 2022/10/12.
//

#ifndef SERIAL_SERIAL_FORMULA_H
#define SERIAL_SERIAL_FORMULA_H

#include <utility>
#include <vector>
#include <iostream>
#include "serial_value.h"

namespace ZLIB {
    class SerialFormula {
    public:
        SerialFormula(char l, char o, char r, std::vector<char> v);

        SerialFormula(char l, char o, char r, SerialValue v);

    public:
        const char lhs;
        const char rhs;
        const char op;
        const SerialValue serialValue;
    };

    std::ostream &operator<<(std::ostream &os, const SerialFormula &o);
}

#endif //SERIAL_SERIAL_FORMULA_H
