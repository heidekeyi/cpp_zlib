//
// Created by 1213173752 on 2022/10/15.
//

#include "serial.h"
#include "exception_table.h"
#include "exception_value.h"

namespace ZLIB {
    Serial::Serial(const char *v)
            : serialValue{convert(std::string{v})} {}

    Serial::Serial(const std::string &v)
            : serialValue{convert(v)} {}

    Serial::Serial(const std::vector<char> &v)
            : serialValue{convert(v)} {}

    Serial::Serial(const SerialValue &v)
            : serialValue{convert(v)} {}

    SerialMultiplication Serial::multiplication() const {
        return SerialMultiplication(symbols());
    }

    SerialAddition Serial::addition() const {
        return SerialAddition(symbols());
    }

    SerialValue Serial::addition(const SerialValue &value) const {
        auto pos = 0;
        auto v = serialValue.retrieve();
        auto table = SerialAddition{symbols()}.table();
        for (auto ch: value.retrieve()) {
            addition(table, v, ch, pos);
            ++pos;
        }
        return SerialValue{v};
    }

    void Serial::addition(const std::vector<SerialFormula> &table, std::vector<char> &vec, char ch, size_t pos) const {
        const auto &sym = symbols();
        if (pos >= vec.size()) {
            vec.push_back(ch);
            return;
        }
        auto d = find(table, ch, vec[pos]).retrieve();
        vec[pos] = d[0];
        if (d.size() > 1) {
            addition(table, vec, d[1], pos + 1);
        }
    }

    const SerialValue &Serial::find(const std::vector<SerialFormula> &v, char v1, char v2) {
        for (const auto &it: v) {
            if ((it.rhs == v1 && it.lhs == v2)
                || (it.rhs == v2 && it.lhs == v1)) {
                return it.serialValue;
            }
        }
        throw ExceptionTable{};
    }

    SerialValue Serial::convert(const std::string &v) {
        return convert(SerialValue{v});
    }

    SerialValue Serial::convert(const std::vector<char> &v) {
        return convert(SerialValue{v});
    }

    SerialValue Serial::convert(const SerialValue &v) {
        auto sym = symbols().retrieve();
        for (auto ch: v.retrieve()) {
            bool status = false;
//            value in symbols
            for (auto c: sym) {
                if (c == ch) {
                    status = true;
                    break;
                }
            }
            if (!status) {
                throw ExceptionValue{};
            }
        }
        return v;
    }
}

