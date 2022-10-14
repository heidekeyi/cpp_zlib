//
// Created by 1213173752 on 2022/10/12.
//

#ifndef SERIAL_SERIAL_TABLE_H
#define SERIAL_SERIAL_TABLE_H

#include <vector>
#include <string>
#include "serial_formula.h"

namespace ZLIB {
    class SerialTable {
    public:
        explicit SerialTable(const char *s);

        explicit SerialTable(const std::string &s);

        explicit SerialTable(const std::vector<char> &s);

        SerialTable(const SerialTable &rhs) = default;

    public:
        std::vector<SerialValue> sequence(size_t num);

        std::vector<SerialFormula> addition();

        std::vector<SerialFormula> multiplication();

    private:
        const std::vector<char> symbols;
    };

    std::ostream &operator<<(std::ostream &os, const std::vector<SerialFormula> &o);

    std::ostream &operator<<(std::ostream &os, const std::vector<SerialValue> &o);
}
#endif //SERIAL_SERIAL_TABLE_H
