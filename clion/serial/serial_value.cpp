//
// Created by 1213173752 on 2022/10/13.
//

#include "serial_value.h"

#include <utility>

namespace ZLIB {
    SerialValue::SerialValue(std::vector<char> v)
            : value{std::move(v)} {}

    SerialValue::SerialValue(char v) : value{v} {}

    SerialValue::SerialValue(const std::string &v) : value{convert(v)} {}

    std::vector<char> SerialValue::convert(const std::string &s) {
        std::vector<char> v;
        for (auto c: s) {
            v.push_back(c);
        }
        return v;
    }

    const std::vector<char> &SerialValue::retrieve() const {
        return value;
    }

    std::ostream &operator<<(std::ostream &os, const SerialValue &o) {
        auto v = o.retrieve();
        auto index = v.size();
        while (index > 0) {
            os << v[--index];
        }
        return os;
    }

}