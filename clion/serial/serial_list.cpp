//
// Created by 1213173752 on 2022/10/15.
//

#include "serial_list.h"

#include <utility>

namespace ZLIB {
    SerialList::SerialList(const char *s)
            : serialSymbols{s} {}

    SerialList::SerialList(const std::string &s)
            : serialSymbols{s} {}

    SerialList::SerialList(const std::vector<char> &s)
            : serialSymbols{s} {}

    SerialList::SerialList(SerialSymbols s)
            : serialSymbols{std::move(s)} {}

    const SerialSymbols &SerialList::symbols() const {
        return serialSymbols;
    }

    SerialList &SerialList::symbols(const char *s) {
        serialSymbols = SerialSymbols{s};
        return *this;
    }

    SerialList &SerialList::symbols(const std::string &s) {
        serialSymbols = SerialSymbols{s};
        return *this;
    }

    SerialList &SerialList::symbols(const std::vector<char> &s) {
        serialSymbols = SerialSymbols{s};
        return *this;
    }

    SerialList &SerialList::symbols(const SerialSymbols &s) {
        serialSymbols = s;
        return *this;
    }
}