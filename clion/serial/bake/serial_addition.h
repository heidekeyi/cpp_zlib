//
// Created by 1213173752 on 2022/10/15.
//

#ifndef SERIAL_SERIAL_ADDITION_H
#define SERIAL_SERIAL_ADDITION_H

#include "serial_table.h"
#include <vector>
#include <string>

namespace ZLIB {
    class SerialAddition : public SerialTable {
    public:
        explicit SerialAddition(const char *s);

        explicit SerialAddition(const std::string &s);

        explicit SerialAddition(const std::vector<char> &s);

        explicit SerialAddition(const SerialSymbols &s);

    public:
        [[nodiscard]] std::vector<SerialFormula> table() const override;
    };
}

#endif //SERIAL_SERIAL_ADDITION_H
