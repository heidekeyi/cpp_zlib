//
// Created by 1213173752 on 2022/10/29.
//

#ifndef SERIAL_VALUE_H
#define SERIAL_VALUE_H

#include "symbols.h"
#include <vector>
#include <string>
#include <ostream>

namespace SERIAL {
    template<Pointer ptr>
    class Value {
    public:
        Value() { value(std::vector<char>{}); }

        explicit Value(const std::string &s) { value(s); }

        explicit Value(const std::vector<char> &s) { value(s); }

    public:
        [[nodiscard]] const std::vector<char> &value() const { return m_value; }

        Value<ptr> &value(const std::vector<char> &s);

        Value<ptr> &value(const std::string &s);

    private:
        std::vector<char> m_value;
    };

    template<Pointer ptr>
    Value<ptr> &Value<ptr>::value(const std::vector<char> &s) {
        Symbols<ptr> symbols{};
        for (auto ch: s) {
            if (symbols.find(ch) < 0) {
                throw Message{"value has unexpect char"};
            }
        }
        if (s.empty()) {
            m_value = {symbols.symbols()[0]};
        } else {
            m_value = s;
        }
        return *this;
    }

    template<Pointer ptr>
    Value<ptr> &Value<ptr>::value(const std::string &s) {
        return value(std::vector<char>(s.begin(), s.end()));
    }

    template<Pointer ptr>
    std::ostream &operator<<(std::ostream &os, const Value<ptr> &o) {
        auto v = o.value();
        auto index = v.size();
        while (index > 0) {
            os << v[--index];
        }
        return os;
    }
}

#endif //SERIAL_VALUE_H
