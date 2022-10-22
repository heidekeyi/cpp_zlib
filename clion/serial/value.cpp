//
// Created by 1213173752 on 2022/10/22.
//

#include "value.h"

#include <utility>
#include "message.h"


namespace ZLIB {
    Value::Value(Symbols symbols)
            : m_symbols(std::move(symbols)) {}

    Value::Value(const std::vector<char> &value, Symbols symbols)
            : m_symbols{std::move(symbols)} {
        init(value);
    }

    void Value::value(const std::vector<char> &v) {
        init(v);
    }

    std::vector<char> Value::value() const {
        return m_value;
    }

    const char &Value::operator[](size_t pos) const {
        range(pos);
        return m_value[pos];
    }

    char &Value::operator[](size_t pos) {
        range(pos);
        return m_value[pos];
    }

    void Value::range(size_t index) const {
        if (index >= m_value.size()) {
            throw Message{"value: pos is out of range"};
        }
    }

    void Value::init(const std::vector<char> &v) {
        const auto &symbols = m_symbols.symbols();
        for (auto ch: v) {
            if (!m_symbols.has(ch)) {
                throw Message{"value: element of value can not find in symbols"};
            }
        }
        m_value = v;
    }

    std::ostream &operator<<(std::ostream &os, const Value &o) {
        auto v = o.value();
        auto index = v.size();
        while (index > 0) {
            os << v[--index];
        }
        return os;
    }
}