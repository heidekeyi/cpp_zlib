//
// Created by 1213173752 on 2022/10/15.
//

#ifndef SERIAL_SERIAL_LIST_H
#define SERIAL_SERIAL_LIST_H

#include <vector>
#include <string>
#include "serial_symbols.h"

namespace ZLIB {
    class SerialList {
    public:
        explicit SerialList(const char *s);

        explicit SerialList(const std::string &s);

        explicit SerialList(const std::vector<char> &s);

    public:
        SerialList &symbols(const char *s);

        SerialList &symbols(const std::string &s);

        SerialList &symbols(const std::vector<char> &s);

        [[nodiscard]] const SerialSymbols &symbols() const;

    private:
        SerialSymbols serialSymbols;
    };
}

#endif //SERIAL_SERIAL_LIST_H
