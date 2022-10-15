//
// Created by 1213173752 on 2022/10/14.
//

#ifndef SERIAL_SERIAL_SEQUENCE_H
#define SERIAL_SERIAL_SEQUENCE_H

#include <vector>
#include <string>
#include "serial_value.h"
#include "serial_symbols.h"
#include "serial_list.h"

namespace ZLIB {
    class SerialSequence : public SerialList {
    public:
        explicit SerialSequence(const char *s, size_t n = 0);

        explicit SerialSequence(const std::string &s, size_t n = 0);

        explicit SerialSequence(const std::vector<char> &s, size_t n = 0);

    protected:
        [[nodiscard]] std::vector<SerialValue> all(size_t n) const;

        [[nodiscard]] std::vector<SerialValue> one(size_t n) const;

        void inc(std::vector<char> &vec) const;

    public:
        [[nodiscard]] std::vector<SerialValue> table() const;

        SerialSequence &number(size_t n);

    private:
        size_t num;
    };

    std::ostream &operator<<(std::ostream &os, const SerialSequence &o);
}

#endif //SERIAL_SERIAL_SEQUENCE_H
