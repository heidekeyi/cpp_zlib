//
// Created by 1213173752 on 2022/10/29.
//

#ifndef SERIAL_VALUE_H
#define SERIAL_VALUE_H

#include <vector>
#include <string>
#include <ostream>
#include "symbols.h"

namespace SERIAL {
    class Value {
    public:
        explicit Value(CALLBACK callback, bool asc = true);

        Value(CALLBACK callback, const std::string &s, bool asc = true);

        Value(CALLBACK callback, const std::vector<char> &s, bool asc = true);

    public:
        [[nodiscard]] const std::vector<char> &value() const;

        [[nodiscard]] std::vector<char> value(size_t n) const;

        Value &value(const std::string &s, bool asc = true);

        Value &value(const std::vector<char> &s, bool asc = true);

    private:
        std::vector<char> m_value;
        CALLBACK m_callback;
    };

    std::ostream &operator<<(std::ostream &os, const Value &o);
}

#endif //SERIAL_VALUE_H
