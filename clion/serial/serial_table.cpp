//
// Created by 1213173752 on 2022/10/12.
//

#include "serial_table.h"


namespace ZLIB {
    SerialTable::SerialTable(const char *s)
            : SerialList(s) {}

    SerialTable::SerialTable(const std::string &s)
            : SerialList(s) {}

    SerialTable::SerialTable(const std::vector<char> &s)
            : SerialList(s) {}

    SerialSequence SerialTable::sequence() const {
        auto sz = symbols().retrieve().size();
        return SerialSequence(symbols().retrieve(), sz * sz + 1);
    }

    std::ostream &operator<<(std::ostream &os, const SerialTable &o) {
        os << "++++++++++++\n";
        const auto &sym = o.symbols();
        os << "symbols: " << sym << '\n';
        auto times = 1;
        auto cnt = 1;
        for (const auto &formula: o.table()) {
            os << formula;
            if (cnt < times) {
                os << '\t';
                ++cnt;
            } else {
                os << '\n';
                cnt = 1;
                ++times;
            }
        }
        os << "\n------------" << std::endl;
        return os;
    }
}