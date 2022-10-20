//
// Created by 1213173752 on 2022/10/15.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include <vector>
#include "serial_sequence.h"
#include "serial_addition.h"
#include "serial_multiplication.h"
#include "serial_value.h"
#include "serial_symbols.h"

namespace ZLIB {
    class Serial {
    public:
        explicit Serial(const char *v);

        explicit Serial(const std::string &v);

        explicit Serial(const std::vector<char> &v);

        explicit Serial(const SerialValue &v);

    protected:
        static const SerialValue &find(const std::vector<SerialFormula> &table, char v1, char v2);

    protected:
        [[nodiscard]] virtual SerialSymbols symbols() const = 0;

    protected:
        SerialValue convert(const std::string &v);

        SerialValue convert(const std::vector<char> &v);

        SerialValue convert(const SerialValue &v);

        [[nodiscard]] SerialMultiplication multiplication() const;

        [[nodiscard]] SerialAddition addition() const;

        [[nodiscard]] SerialValue addition(const SerialValue &value) const;

        void addition(const std::vector<SerialFormula> &table, std::vector<char> &vec, char ch, size_t pos) const;

    protected:
        SerialValue serialValue;
    };
}

#endif //SERIAL_SERIAL_H
