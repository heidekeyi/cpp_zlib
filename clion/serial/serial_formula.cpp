//
// Created by 1213173752 on 2022/10/12.
//

#include "serial_formula.h"
#include <utility>

namespace ZLIB {
    SerialFormula::SerialFormula(char l, char o, char r, std::vector<char> v)
            : lhs{l}, op{o}, rhs{r}, serialValue{std::move(v)} {}

    SerialFormula::SerialFormula(char l, char o, char r, SerialValue v)
            : lhs{l}, op{o}, rhs{r}, serialValue{std::move(v)} {}

    std::ostream &operator<<(std::ostream &os, const SerialFormula &o) {
        return os << o.lhs << o.op << o.rhs << '=' << o.serialValue;
    }
}