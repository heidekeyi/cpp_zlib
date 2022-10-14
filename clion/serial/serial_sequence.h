//
// Created by 1213173752 on 2022/10/14.
//

#ifndef SERIAL_SERIAL_SEQUENCE_H
#define SERIAL_SERIAL_SEQUENCE_H

#include <vector>
#include <string>
#include "serial_value.h"
#include "serial_symbols.h"

namespace ZLIB {
    class SerialSequence {
    public:
        explicit SerialSequence(const char *s);

        SerialSequence(const char *s, size_t n);

        explicit SerialSequence(const std::string &s);

        SerialSequence(const std::string &s, size_t n);

        explicit SerialSequence(const std::vector<char> &s);

        SerialSequence(const std::vector<char> &s, size_t n);

    protected:
        [[nodiscard]] std::vector<SerialValue> all(size_t n) const;

        [[nodiscard]] std::vector<SerialValue> one(size_t n) const;

        void inc(std::vector<char> &vec) const;

    public:
        [[nodiscard]] std::vector<SerialValue> table() const;

        [[nodiscard]] const SerialSymbols &symbols() const;

        SerialSequence &symbols(const char *s);

        SerialSequence &symbols(const std::string &s);

        SerialSequence &symbols(const std::vector<char> &s);

        SerialSequence &number(size_t n);

    private:
        SerialSymbols serialSymbols;
        size_t num;
    };

    std::ostream &operator<<(std::ostream &os, const SerialSequence &o);
}

#endif //SERIAL_SERIAL_SEQUENCE_H
