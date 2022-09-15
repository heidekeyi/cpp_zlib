//
// Created by 12131 on 2022/9/14.
//

#ifndef CALCULATOR_SERIAL_H
#define CALCULATOR_SERIAL_H

#include <vector>
#include "serial_sequence.h"
#include "serial_table.h"

namespace ZLIB {
    class Serial {
    public:
        [[nodiscard]] virtual const char *symbols() const = 0;

    public:
        void display() const;

        [[nodiscard]] std::vector<char> value() const;

        [[nodiscard]] SerialSequence sequence() const;

        [[nodiscard]] SerialTable table() const;

    private:
        std::vector<char> m_value;
    };
}

#endif //CALCULATOR_SERIAL_H
