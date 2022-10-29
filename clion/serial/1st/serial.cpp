//
// Created by 1213173752 on 2022/10/24.
//

#include "serial.h"
#include "../2ed/message.h"
#include <utility>

namespace ZLIB {
    Serial::Serial(Symbols symbols, const std::vector<char> &s)
            : m_symbols(std::move(symbols)) {
        serial(s);
    }

    Serial::Serial(Symbols symbols, const std::string &s)
            : m_symbols(std::move(symbols)) {
        serial(s);
    }

    Serial &Serial::serial(const std::string &s) {
        std::vector<char> v;
        for (auto ch: s) {
            v.push_back(ch);
        }
        return serial(v);
    }

    Serial &Serial::serial(const std::vector<char> &s) {
        if (s.empty()) {
            throw Message{"serial: serial is empty"};
        }
        for (auto ch: s) {
            if (!m_symbols.has(ch)) {
                throw Message{"serial: element of serial can not find in symbols"};
            }
        }
        m_serial = s;
        return *this;
    }

    std::vector<char> Serial::serial() const {
        return m_serial;
    }

    Serial Serial::operator+(const Serial &rhs) const {
        return *this;
    }

    Serial Serial::operator*(const Serial &rhs) const {
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Serial &o) {
        auto v = o.serial();
        auto index = v.size();
        while (index > 0) {
            os << v[--index];
        }
        return os;
    }
}