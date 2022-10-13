//
// Created by 1213173752 on 2022/10/13.
//

#include "serial_value.h"

#include <utility>

namespace ZLIB {
    SerialValue::SerialValue(std::vector<char> v)
            : value{std::move(v)} {}

    SerialValue::SerialValue(char ch) : value{ch} {}

    std::ostream &operator<<(std::ostream &os, const SerialValue &ob) {
        auto index = ob.value.size();
        while (index > 0) {
            os << ob.value[--index];
        }
        return os;
    }
}