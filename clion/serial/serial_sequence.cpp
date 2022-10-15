//
// Created by 1213173752 on 2022/10/14.
//

#include "serial_sequence.h"

namespace ZLIB {
    SerialSequence::SerialSequence(const char *s, size_t n)
            : SerialList{s}, num{n} {}

    SerialSequence::SerialSequence(const std::string &s, size_t n)
            : SerialList{s}, num{n} {}

    SerialSequence::SerialSequence(const std::vector<char> &s, size_t n)
            : SerialList{s}, num{n} {}

    std::vector<SerialValue> SerialSequence::table() const {
        if (num == 0) {
            return {};
        }
        switch (symbols().retrieve().size()) {
            case 0:
                return {};
            case 1:
                return one(num);
            default:
                return all(num);
        }
    }

    std::vector<SerialValue> SerialSequence::one(size_t n) const {
        std::vector<SerialValue> vec;
        auto v = SerialValue{""}.retrieve();
        auto ch = symbols().retrieve()[0];
        for (auto sz = 0; sz < n; ++sz) {
            v.emplace_back(ch);
            vec.emplace_back(v);
        }
        return vec;
    }

    std::vector<SerialValue> SerialSequence::all(size_t n) const {
        auto vec = one(1);
        auto v = vec[0].retrieve();
        for (auto sz = 0; sz < n; ++sz) {
            inc(v);
            vec.emplace_back(v);
        }
        return vec;
    }

    void SerialSequence::inc(std::vector<char> &vec) const {
        auto pos = 0;
        const auto &sym = symbols().retrieve();
        while (pos < vec.size()) {
            auto index = 0;
            while (index < sym.size()) {
//                compare and index to next
                if (sym[index++] == vec[pos]) {
                    break;
                }
            }
            if (index >= sym.size()) {
//                set pos with first element
                vec[pos] = sym[0];
                ++pos;
            } else {
//                pos inc
                vec[pos] = sym[index];
                break;
            }
        }
//        last pos inc
        if (pos >= vec.size()) {
            vec.push_back(sym[1]);
        }
    }

    SerialSequence &SerialSequence::number(size_t n) {
        num = n;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const SerialSequence &o) {
        os << "++++++++++++\n";
        const auto &sym = o.symbols();
        os << "symbols: " << sym << '\n';
        auto sz = sym.retrieve().size();
        auto cnt = 1;
        for (const auto &it: o.table()) {
            if (cnt >= sz) {
                cnt = 1;
                os << it << '\n';
            } else {
                os << it << '\t';
                ++cnt;
            }
        }
        os << "\n------------" << std::endl;
        return os;
    }
}