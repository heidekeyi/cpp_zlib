//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_VALUE_H
#define SERIAL_VALUE_H

#include <vector>
#include "symbols.h"

namespace ZLIB {
    class Value {
    public:
        explicit Value(Symbols symbols);

        Value(const std::vector<char> &value, Symbols symbols);

    public:
        [[nodiscard]] std::vector<char> value() const;

        void value(const std::vector<char> &v);

        const char &operator[](size_t pos) const;

        char &operator[](size_t pos);

    private:
        void range(size_t index) const;

        void init(const std::vector<char> &v);

    private:
        std::vector<char> m_value;
        Symbols m_symbols;
    };

    std::ostream &operator<<(std::ostream &os, const Value &o);
}

#endif //SERIAL_VALUE_H
