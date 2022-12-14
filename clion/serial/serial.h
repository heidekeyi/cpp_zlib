//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include <string>
#include <utility>
#include <vector>
#include "value.h"

namespace SERIAL {
    template<CALLBACK callback>
    class Serial {
    public:
        Serial() : m_value{callback}, m_callback{callback} {};

        explicit Serial(const std::string &s, bool asc = true)
                : m_value{callback, s, asc}, m_callback{callback} {}

        explicit Serial(const std::vector<char> &s, bool asc = true)
                : m_value{callback, s, asc}, m_callback{callback} {}

        explicit Serial(Value s)
                : m_value{std::move(s)}, m_callback{callback} {}

    public:
        [[nodiscard]] const Value &value() const { return m_value; }

    public:
        Serial &operator+=(const Serial &rhs) { return *this = operator+(rhs); }

        Serial &operator*=(const Serial &rhs) { return *this = operator*(rhs); }

        Serial operator+(const Serial &rhs) const;

        Serial operator*(const Serial &rhs) const;

    private:
        Value m_value;
        CALLBACK m_callback;
    private:

        void add(std::vector<char> &dest,
                 const std::vector<char> &src,
                 size_t pos,
                 const std::vector<Value> &table) const;

        void mul(std::vector<char> &dest, const std::vector<char> &src) const;

        [[nodiscard]] size_t find(const std::vector<Value> &vec, char lhs, char rhs) const;
    };

    template<CALLBACK callback>
    size_t Serial<callback>::find(const std::vector<Value> &vec, char lhs, char rhs) const {
        Symbols symbols{m_callback};
        size_t row = symbols.find(rhs);
        size_t col = symbols.find(lhs);
        size_t index = col;
        if (row < col) {
            index = row;
            row = col;
        }
        index += (1 + row) * row / 2;
        return index;
    }

    template<CALLBACK callback>
    Serial<callback> Serial<callback>::operator+(const Serial &rhs) const {
        auto dest = rhs.m_value.value();
        add(dest, m_value.value(), 0, Table{m_callback}.retrieve_table_addition());
        return Serial{dest, false};
    }

    template<CALLBACK callback>
    void Serial<callback>::add(std::vector<char> &dest,
                               const std::vector<char> &src,
                               size_t pos,
                               const std::vector<Value> &table
    ) const {
        while (pos < dest.size() && pos < src.size()) {
            auto index = find(table, dest[pos], src[pos]);
            auto v = table[index].value(pos);
            dest[pos] = v[pos];
            add(dest, v, pos + 1, table);
            ++pos;
        }
        while (pos < src.size()) {
            dest.push_back(src[pos]);
            ++pos;
        }
    }

    template<CALLBACK callback>
    Serial<callback> Serial<callback>::operator*(const Serial &rhs) const {
        auto dest = rhs.m_value.value();
        mul(dest, m_value.value());
        return Serial{dest, false};
    }

    template<CALLBACK callback>
    void Serial<callback>::mul(std::vector<char> &dest, const std::vector<char> &src) const {
        const auto table_mul = Table{callback}.retrieve_table_multiplication();
        std::vector<std::vector<char>> v;
        for (size_t i = 0; i < dest.size(); ++i) {
            for (size_t j = 0; j < src.size(); ++j) {
                auto index = find(table_mul, dest[i], src[j]);
                v.push_back(table_mul[index].value(i + j));
            }
        }
        dest = v[0];
        const auto table_add = Table{callback}.retrieve_table_addition();
        for (size_t i = 1; i < v.size(); ++i) {
            add(dest, v[i], 0, table_add);
        }
    }

    template<CALLBACK callback>
    std::ostream &operator<<(std::ostream &os, const Serial<callback> &o) {
        return os << o.value();
    }
}

#endif //SERIAL_SERIAL_H
