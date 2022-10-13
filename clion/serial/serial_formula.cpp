//
// Created by 1213173752 on 2022/10/12.
//

#include "serial_formula.h"

namespace ZLIB {
    SerialFormula::SerialFormula(char l, char o, char r, std::vector<char> v)
            : lhs{l}, op{o}, rhs{r}, serialValue{std::move(v)} {}

    std::ostream &operator<<(std::ostream &out, const SerialFormula &ob) {
        return std::cout << ob.lhs << ob.op << ob.rhs << ob.serialValue;
    }
}