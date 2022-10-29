//
// Created by 1213173752 on 2022/10/24.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include <ostream>
#include <vector>
#include <string>
#include "../2ed/symbols.h"

namespace ZLIB {
    class Serial {
    public:
        Serial(Symbols symbols, const std::vector<char> &s);

        Serial(Symbols symbols, const std::string &s);

    public:
        Serial &serial(const std::vector<char> &s);

        Serial &serial(const std::string &s);

        [[nodiscard]] std::vector<char> serial() const;

    public:
        Serial operator+(const Serial &rhs) const;

        Serial operator*(const Serial &rhs) const;

    private:
        Symbols m_symbols;
        std::vector<char> m_serial;
    };

    std::ostream &operator<<(std::ostream &os, const Serial &o);
}

#endif //SERIAL_SERIAL_H
