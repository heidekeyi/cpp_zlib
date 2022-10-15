//
// Created by 1213173752 on 2022/10/15.
//

#ifndef SERIAL_SERIAL_MULTIPLICATION_H
#define SERIAL_SERIAL_MULTIPLICATION_H

#include "serial_table.h"

namespace ZLIB {
    class SerialMultiplication : public SerialTable {
    public:
        explicit SerialMultiplication(const SerialSymbols &s);

        explicit SerialMultiplication(const std::vector<char> &s);

        explicit SerialMultiplication(const std::string &s);

        explicit SerialMultiplication(const char *s);

    public:
        [[nodiscard]] std::vector<SerialFormula> table() const override;
    };
}
#endif //SERIAL_SERIAL_MULTIPLICATION_H
