//
// Created by 1213173752 on 2022/10/31.
//
#ifndef SERIAL_TABLE_H
#define SERIAL_TABLE_H

#include <vector>
#include "symbols.h"
#include "value.h"

namespace SERIAL {
    class Table {
    public:
        explicit Table(CALLBACK callback);

    public:
        void display_list(size_t n) const;

        void display_table_addition() const;

        void display_table_multiplication() const;

    public:
        [[nodiscard]] std::vector<Value> retrieve_list(size_t n) const;

        [[nodiscard]] std::vector<Value> retrieve_table_addition() const;

        [[nodiscard]] std::vector<Value> retrieve_table_multiplication() const;

    protected:
        std::vector<Value> retrieve_table(size_t (*)(size_t, size_t)) const;

        void display_table(const std::vector<Value> &vec, char symbol) const;

    protected:
        static void inc(std::vector<char> &value, const Symbols &symbols, size_t pos);

    private:
        CALLBACK m_callback;
    };
}

#endif //SERIAL_TABLE_H
