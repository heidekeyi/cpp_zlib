//
// Created by 1213173752 on 2022/10/14.
//

#include "serial_sequence.h"

namespace ZLIB {
    SerialSequence::SerialSequence(const char *s)
            : serialSymbols{s} {}

    SerialSequence::SerialSequence(const std::string &s)
            : serialSymbols{s} {}

    SerialSequence::SerialSequence(const std::vector<char> &s)
            : serialSymbols{s} {}

    std::vector<SerialValue> SerialSequence::retrieve(size_t num) const {
        switch (serialSymbols.retrieve().size()) {
            case 0:
                return {};
            case 1:
                return one(num);
            default:
                return all(num);
        }
    }

    std::vector<SerialValue> SerialSequence::one(size_t num) const {
        std::vector<SerialValue> v;
        for (int sz = 0; sz < num; ++sz) {
            v.emplace_back(serialSymbols.retrieve()[0]);
        }
        return v;
    }

    std::vector<SerialValue> SerialSequence::all(size_t num) const {
        auto symbols = serialSymbols.retrieve();
        auto vec = one(1);
        auto v = vec[0].value;
        while (--num > 0) {
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
}