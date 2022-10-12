//
// Created by 12131 on 2022/9/15.
//

#include "serial_table.h"
#include "serial_sequence.h"

namespace ZLIB {
    SerialTable::SerialTable(const char *symbols) : m_symbols{symbols} {}

    std::vector<std::vector<char>> SerialTable::addition() const {
        return {};
    }

    std::vector<std::vector<char>> SerialTable::multiplication() const {
        return std::vector<std::vector<char>>();
    }

    void SerialTable::display() const {

    }
}