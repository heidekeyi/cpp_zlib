//
// Created by 1213173752 on 2022/10/12.
//

#ifndef SERIAL_SERIAL_FORMULA_H
#define SERIAL_SERIAL_FORMULA_H

#include <utility>
#include <vector>

namespace ZLIB {
    class SerialFormula {
    public:
        SerialFormula(char l, char o, char r, std::vector<char> v)
                : lhs{l}, op{o}, rhs{r}, value{std::move(v)} {}

    public:
        char rhs;
        char lhs;
        char op;
        std::vector<char> value;
    };
}

#endif //SERIAL_SERIAL_FORMULA_H
