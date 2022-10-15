//
// Created by 1213173752 on 2022/10/12.
//

#ifndef SERIAL_SERIAL_TABLE_H
#define SERIAL_SERIAL_TABLE_H

#include <vector>
#include <string>
#include <iostream>
#include "serial_formula.h"
#include "serial_list.h"
#include "serial_sequence.h"

namespace ZLIB {
    class SerialTable : public SerialList {
    public:
        explicit SerialTable(const char *s);

        explicit SerialTable(const std::string &s);

        explicit SerialTable(const std::vector<char> &s);

    public:
        [[nodiscard]] virtual std::vector<SerialFormula> table() const = 0;

        [[nodiscard]] SerialSequence sequence() const;
    };

    std::ostream &operator<<(std::ostream &os, const SerialTable &o);
}
#endif //SERIAL_SERIAL_TABLE_H
