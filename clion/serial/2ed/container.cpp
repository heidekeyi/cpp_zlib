//
// Created by 1213173752 on 2022/10/25.
//

#include "container.h"

#include <utility>
#include "message.h"

namespace SERIAL {

    Container::Container(const std::string &v, Symbols s)
            : m_symbols(std::move(s)) { value(v); }

    Container::Container(const std::vector<char> &v, Symbols s)
            : m_symbols(std::move(s)) { value(v); }

    const std::vector<char> &Container::value() const {
        return m_value;
    }

    Container &Container::value(const std::vector<char> &v) {
        if (v.empty()) {
            throw Message{"container: value is empty"};
        }
        for (auto ch: v) {
            if (!m_symbols.has(ch)) {
                throw Message("container: element of value can not find in symbols");
            }
        }
        m_value = v;
        return *this;
    }

    Container &Container::value(const std::string &v) {
        std::vector<char> s;
        for (auto ch: v) {
            s.push_back(ch);
        }
        return value(s);
    }

    std::ostream &operator<<(std::ostream &os, const Container &o) {
        auto v = o.value();
        auto index = v.size();
        while (index > 0) {
            os << v[--index];
        }
        return os;
    }
}