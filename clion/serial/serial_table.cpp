//
// Created by 1213173752 on 2022/10/12.
//

#include "serial_table.h"
#include <exception>

namespace ZLIB {
    std::vector<char> toVector(const char *str);

    std::vector<char> toVector(const std::string &str);

    std::vector<char> toVector(const std::vector<char> &str);

    std::vector<std::vector<char>> sequenceOne(const std::vector<char> &symbols, size_t num);

    std::vector<std::vector<char>> sequenceAll(const std::vector<char> &symbols, size_t num);

    void sequenceInc(std::vector<char> &vec, const std::vector<char> &symbols);

    std::vector<std::vector<char>> SerialTable::sequence(const char *symbols, size_t num) {
        return sequence(toVector(symbols), num);
    }

    std::vector<std::vector<char>> SerialTable::sequence(const std::string &symbols, size_t num) {
        return sequence(toVector(symbols), num);
    }

    std::vector<std::vector<char>> SerialTable::sequence(const std::vector<char> &symbols, size_t num) {
        auto sym = toVector(symbols);
        switch (sym.size()) {
            case 0:
                return {};
            case 1:
                return sequenceOne(sym, num);
            default:
                return sequenceAll(sym, num);
        }
    }

    std::vector<SerialFormula> SerialTable::addition(const char *symbols) {
        return addition(toVector(symbols));
    }

    std::vector<SerialFormula> SerialTable::addition(const std::string &symbols) {
        return addition(toVector(symbols));
    }

    std::vector<SerialFormula> SerialTable::addition(const std::vector<char> &symbols) {
        auto sym = toVector(symbols);
        auto list = sequence(sym, sym.size() * sym.size() + 1);
        std::vector<SerialFormula> vec;
        for (int i = 0; i < sym.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                vec.emplace_back(sym[j], '+', sym[i], list[i + j]);
            }
        }
        return vec;
    }

    std::vector<SerialFormula> SerialTable::multiplication(const char *symbols) {
        return multiplication(toVector(symbols));
    }

    std::vector<SerialFormula> SerialTable::multiplication(const std::string &symbols) {
        return multiplication(toVector(symbols));
    }

    std::vector<SerialFormula> SerialTable::multiplication(const std::vector<char> &symbols) {
        auto sym = toVector(symbols);
        auto list = sequence(sym, sym.size() * sym.size() + 1);
        std::vector<SerialFormula> vec;
        for (int i = 0; i < sym.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                vec.emplace_back(sym[j], '*', sym[i], list[i * j]);
            }
        }
        return vec;
    }

    std::vector<char> toVector(const char *str) {
        std::vector<char> v;
        while (*str) {
            v.push_back(*str);
            ++str;
        }
        return v;
    }

    std::vector<char> toVector(const std::string &str) {
        std::vector<char> v;
        for (auto c: str) {
            v.push_back(c);
        }
        return v;
    }

    std::vector<char> toVector(const std::vector<char> &str) {
        std::vector<char> vec;
        for (auto item: str) {
            auto status = true;
            for (auto it: vec) {
                if (it == item) {
                    status = false;
                }
            }
            if (status) {
                vec.push_back(item);
            }
        }
        return vec;
    }

    std::vector<std::vector<char>> sequenceOne(const std::vector<char> &symbols, size_t num) {
        std::vector<std::vector<char>> v;
        for (int sz = 0; sz < num; ++sz) {
            v.push_back({symbols[0]});
        }
        return v;
    }

    std::vector<std::vector<char>> sequenceAll(const std::vector<char> &symbols, size_t num) {
        auto vec = sequenceOne(symbols, 1);
        auto v = vec[0];
        while (--num > 0) {
            sequenceInc(v, symbols);
            vec.push_back(v);
        }
        return vec;
    }

    void sequenceInc(std::vector<char> &vec, const std::vector<char> &symbols) {
        auto pos = 0;
        while (pos < vec.size()) {
            auto index = 0;
            while (index < symbols.size()) {
//                compare and index to next
                if (symbols[index++] == vec[pos]) {
                    break;
                }
            }
            if (index >= symbols.size()) {
//                set pos with first element
                vec[pos] = symbols[0];
                ++pos;
            } else {
//                pos inc
                vec[pos] = symbols[index];
                break;
            }
        }
//        last pos inc
        if (pos >= vec.size()) {
            vec.push_back(symbols[1]);
        }
    }
}