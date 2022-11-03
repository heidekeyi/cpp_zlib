//
// Created by 1213173752 on 2022/10/31.
//

#include "value.h"

namespace SERIAL {
    Value::Value(CALLBACK callback, bool asc)
            : m_callback{callback} {
        value(std::vector<char>{}, asc);
    }

    Value::Value(CALLBACK callback, const std::string &s, bool asc)
            : m_callback{callback} {
        value(s, asc);
    }

    Value::Value(CALLBACK callback, const std::vector<char> &s, bool asc)
            : m_callback{callback} {
        value(s, asc);
    }

    const std::vector<char> &Value::value() const {
        return m_value;
    }

    std::vector<char> Value::value(size_t n) const {
        std::vector<char> v;
        Symbols symbols{m_callback};
        while (n > 0) {
            v.push_back(symbols.first());
            --n;
        }
        for (auto ch: m_value) {
            v.push_back(ch);
        }
        return v;
    }

    Value &Value::value(const std::string &s, bool asc) {
        return value(std::vector<char>(s.begin(), s.end()), asc);
    }

    Value &Value::value(const std::vector<char> &s, bool asc) {
        Symbols symbols{m_callback};
        for (auto ch: s) {
            if (symbols.find(ch) < 0) {
                throw Message{"value has unexpect char"};
            }
        }
        m_value = s.empty()
                  ? std::vector<char>{symbols.first()}
                  : s;
        if (asc) {
            std::reverse(m_value.begin(), m_value.end());
        }
        return *this;
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

