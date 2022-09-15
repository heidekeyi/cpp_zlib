//
// Created by 12131 on 2022/9/15.
//

#include "serial_sequence.h"
#include <iostream>

namespace ZLIB {
    SerialSequence::SerialSequence(const char *symbols, std::size_t size) : m_symbols{symbols} {
        if (!m_symbols.empty()) {
            std::vector<char> v{m_symbols[0]};
            while (m_value.size() < size) {
                if (m_symbols.size() > 1 && !m_value.empty()) {
                    create(v, 0);
                }
                m_value.push_back(v);
            }
        }
    }

    void SerialSequence::display() const {
        display(m_symbols.size());
    }

    void SerialSequence::display(size_t num_per_line) const {
        size_t cnt = 0;
        size_t sum = 0;
        for (auto &v: m_value) {
            display(v);
            ++sum;
            if (m_value.size() == sum) {
                break;
            }
            ++cnt;
            if (cnt >= num_per_line) {
                cnt = 0;
                std::cout << '\n';
            } else {
                std::cout << '\t';
            }
        }
    }

    std::vector<std::vector<char>> SerialSequence::value() const {
        return m_value;
    }

    void SerialSequence::display(const std::vector<char> &value) {
        if (value.empty()) {
            return;
        }
        size_t pos = value.size();
        while (--pos > 0) {
            std::cout << value[pos];
        }
        std::cout << value[pos];
    }

    void SerialSequence::create(std::vector<char> &v, size_t pos) {
        if (pos >= v.size()) {
            v.push_back(m_symbols[1]);
            return;
        }
        size_t index = 0;
        auto ch = v[pos];
        for (auto c: m_symbols) {
            ++index;
            if (ch == c) {
                break;
            }
        }
        if (index >= m_symbols.size()) {
            v[pos] = m_symbols[0];
            create(v, pos + 1);
        } else {
            v[pos] = m_symbols[index];
        }
    }
}