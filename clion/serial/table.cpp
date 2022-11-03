//
// Created by 1213173752 on 2022/10/31.
//

#include "table.h"
#include <iostream>

namespace SERIAL {
    Table::Table(CALLBACK callback) : m_callback{callback} {}

    std::vector<Value> Table::retrieve_list(size_t n) const {
        std::vector<Value> vec;
        if (0 == n) {
            return vec;
        }
        auto value = Value{m_callback};
        vec.push_back(value);
        auto v = value.value();
        Symbols symbols{m_callback};
        while (vec.size() < n) {
            inc(v, symbols, 0);
            vec.push_back(value.value(v, false));
        }
        return vec;
    }

    void Table::inc(std::vector<char> &value, const Symbols &symbols, size_t pos) {
        auto sym = symbols.symbols();
        if (pos >= value.size()) {
            value.push_back(sym[1]);
            return;
        }
        size_t index = symbols.find(value[pos]) + 1;
        if (index < sym.size()) {
            value[pos] = sym[index];
            return;
        }
        value[pos] = sym[0];
        inc(value, symbols, pos + 1);
    }

    std::vector<Value> Table::retrieve_table_addition() const {
        return retrieve_table([](size_t v1, size_t v2) { return v1 + v2; });
    }

    std::vector<Value> Table::retrieve_table_multiplication() const {
        return retrieve_table([](size_t v1, size_t v2) { return v1 * v2; });
    }

    std::vector<Value> Table::retrieve_table(size_t (*index_calculator)(size_t, size_t)) const {
        Symbols symbols{m_callback};
        const auto &sym = symbols.symbols();
        auto sz = sym.size() + 1;
        auto seq = retrieve_list(sz * sz);
        std::vector<Value> vec;
        for (size_t i = 0; i < sz; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                vec.push_back(seq[index_calculator(i, j)]);
            }
        }
        return vec;
    }

    void Table::display_list(size_t n) const {
        auto sz = Symbols{m_callback}.symbols().size();
        size_t cnt = 0;
        for (const auto &v: retrieve_list(n)) {
            ++cnt;
            std::cout << v;
            if (cnt >= sz) {
                cnt = 0;
                std::cout << '\n';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    void Table::display_table_addition() const {
        display_table(retrieve_table_addition(), '+');
    }

    void Table::display_table_multiplication() const {
        display_table(retrieve_table_multiplication(), '*');
    }

    void Table::display_table(const std::vector<Value> &vec, char symbol) const {
        auto symbols = Symbols{m_callback}.symbols();
        auto index = 0;
        for (auto row: symbols) {
            for (auto col: symbols) {
                std::cout << col << symbol << row << '=' << vec[index++];
                if (row == col) {
                    std::cout << '\n';
                    break;
                } else {
                    std::cout << ' ';
                }
            }
        }
        std::cout << std::endl;
    }
}
