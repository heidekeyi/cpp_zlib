//
// Created by 1213173752 on 2022/10/12.
//

#include "serial_table.h"
#include <exception>

namespace ZLIB {
    std::vector<char> convert(const char *s);

    std::vector<char> convert(const std::string &str);

    std::vector<char> convert(const std::vector<char> &s);

    std::vector<SerialValue> sequenceOne(const std::vector<char> &symbols, size_t num);

    std::vector<SerialValue> sequenceAll(const std::vector<char> &symbols, size_t num);

    void sequenceInc(std::vector<char> &vec, const std::vector<char> &symbols);

    std::vector<SerialValue> SerialTable::sequence(size_t num) {
        switch (symbols.size()) {
            case 0:
                return {};
            case 1:
                return sequenceOne(symbols, num);
            default:
                return sequenceAll(symbols, num);
        }
    }

    std::vector<SerialFormula> SerialTable::addition(const std::vector<char> &symbols) {
        auto sym = convert(symbols);
        auto list = sequence(sym.size() * sym.size() + 1);
        std::vector<SerialFormula> vec;
        for (int i = 0; i < sym.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                vec.emplace_back(sym[j], '+', sym[i], list[i + j]);
            }
        }
        return vec;
    }

    std::vector<SerialFormula> SerialTable::multiplication(const char *symbols) {
        return multiplication(convert(symbols));
    }

    std::vector<SerialFormula> SerialTable::multiplication(const std::string &symbols) {
        return multiplication(convert(symbols));
    }

    std::vector<SerialFormula> SerialTable::multiplication(const std::vector<char> &symbols) {
        auto sym = convert(symbols);
        auto list = sequence(sym, sym.size() * sym.size() + 1);
        std::vector<SerialFormula> vec;
        for (int i = 0; i < sym.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                vec.emplace_back(sym[j], '*', sym[i], list[i * j]);
            }
        }
        return vec;
    }

    std::vector<char> convert(const char *str) {
        std::vector<char> v;
        while (*str) {
            v.push_back(*str);
            ++str;
        }
        return v;
    }

    std::vector<char> convert(const std::string &str) {
        std::vector<char> v;
        for (auto c: str) {
            v.push_back(c);
        }
        return v;
    }

    std::vector<char> convert(const std::vector<char> &str) {
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

    std::vector<SerialValue> sequenceOne(const std::vector<char> &symbols, size_t num) {
        std::vector<SerialValue> v;
        for (int sz = 0; sz < num; ++sz) {
            v.emplace_back(symbols[0]);
        }
        return v;
    }

    std::vector<SerialValue> sequenceAll(const std::vector<char> &symbols, size_t num) {
        auto vec = sequenceOne(symbols, 1);
        auto v = vec[0].value;
        while (--num > 0) {
            sequenceInc(v, symbols);
            vec.emplace_back(v);
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

    std::ostream &operator<<(std::ostream &os, const std::vector<SerialFormula> &o) {
        auto times = 1;
        auto cnt = 0;
        for (const auto &item: o) {
            os << item;
            if (cnt < times) {
                os << '\t';
                ++cnt;
            } else {
                os << '\n';
                cnt = 0;
                ++times;
            }
        }
        os << std::endl;
        return os;
    }
}