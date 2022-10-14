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

        explicit SerialSequence(const std::string &s);

        explicit SerialSequence(const std::vector<char> &s);

    protected:
        [[nodiscard]] std::vector<SerialValue> all(size_t num) const;

        [[nodiscard]] std::vector<SerialValue> one(size_t num) const;

        void inc(std::vector<char> &vec) const;

    public:
        [[nodiscard]] std::vector<SerialValue> retrieve(size_t num) const;

    private:
        const SerialSymbols serialSymbols;
    };
}

#endif //SERIAL_SERIAL_SEQUENCE_H
