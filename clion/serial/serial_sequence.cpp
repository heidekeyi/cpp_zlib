//
// Created by 1213173752 on 2022/10/14.
//

#include "serial_sequence.h"

namespace ZLIB {
    SerialSequence::SerialSequence(const char *s)
            : serialSymbols{s}, num{0} {
        auto sz = serialSymbols.retrieve().size();
        num = sz * sz;
    }

    SerialSequence::SerialSequence(const std::string &s)
            : serialSymbols{s}, num{s.size() * s.size()} {
        auto sz = serialSymbols.retrieve().size();
        num = sz * sz;
    }

    SerialSequence::SerialSequence(const std::vector<char> &s)
            : serialSymbols{s}, num{0} {
        auto sz = serialSymbols.retrieve().size();
        num = sz * sz;
    }

    SerialSequence::SerialSequence(const char *s, size_t n)
            : serialSymbols{s}, num{n} {}

    SerialSequence::SerialSequence(const std::string &s, size_t n)
            : serialSymbols{s}, num{n} {}

    SerialSequence::SerialSequence(const std::vector<char> &s, size_t n)
            : serialSymbols{s}, num{n} {}

    std::vector<SerialValue> SerialSequence::table() const {
        switch (serialSymbols.retrieve().size()) {
            case 0:
                return {};
            case 1:
                return one(num);
            default:
                return all(num);
        }
    }

    std::vector<SerialValue> SerialSequence::one(size_t n) const {
        std::vector<SerialValue> v;
        for (int sz = 0; sz < n; ++sz) {
            v.emplace_back(serialSymbols.retrieve()[0]);
        }
        return v;
    }

    std::vector<SerialValue> SerialSequence::all(size_t n) const {
        auto symbols = serialSymbols.retrieve();
        auto vec = one(1);
        auto v = vec[0].retrieve();
        while (--n > 0) {
            inc(v);
            vec.emplace_back(v);
        }
        return vec;
    }

    void SerialSequence::inc(std::vector<char> &vec) const {
        auto pos = 0;
        auto symbols = serialSymbols.retrieve();
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

    const SerialSymbols &SerialSequence::symbols() const {
        return serialSymbols;
    }

    SerialSequence &SerialSequence::symbols(const char *s) {
        serialSymbols = SerialSymbols{s};
        return *this;
    }

    SerialSequence &SerialSequence::symbols(const std::string &s) {
        serialSymbols = SerialSymbols{s};
        return *this;
    }

    SerialSequence &SerialSequence::symbols(const std::vector<char> &s) {
        serialSymbols = SerialSymbols{s};
        return *this;
    }

    SerialSequence &SerialSequence::number(size_t n) {
        num = n;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const SerialSequence &o) {
        const auto &s = o.symbols();
        os << "symbols: " << s << '\n';
        auto sz = s.retrieve().size();
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
        os << std::endl;
        return os;
    }
}