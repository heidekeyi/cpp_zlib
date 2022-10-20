//
// Created by 1213173752 on 2022/10/14.
//

#ifndef SERIAL_SERIAL_SYMBOLS_H
#define SERIAL_SERIAL_SYMBOLS_H

#include <vector>
#include <string>
#include <ostream>
#include "serial_value.h"

namespace ZLIB {
    class SerialSymbols {
    private:
        static std::vector<char> convert(const char *s);

        static std::vector<char> convert(const std::vector<char> &s);

        static std::vector<char> convert(const std::string &s);

    public:
        explicit SerialSymbols(const char *s);

        explicit SerialSymbols(const std::string &s);

        explicit SerialSymbols(const std::vector<char> &s);

    public:
        [[nodiscard]] const std::vector<char> &retrieve() const;

    private:
        std::vector<char> value;
    };

    std::ostream &operator<<(std::ostream &os, const SerialSymbols &o);
}

#endif //SERIAL_SERIAL_SYMBOLS_H
