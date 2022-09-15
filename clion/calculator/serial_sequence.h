//
// Created by 12131 on 2022/9/15.
//

#ifndef CALCULATOR_SERIAL_SEQUENCE_H
#define CALCULATOR_SERIAL_SEQUENCE_H

#include <vector>
#include <string>

namespace ZLIB {
    class SerialSequence {
    public:
        static void display(const std::vector<char> &value);

    public:
        SerialSequence(const char *symbols, std::size_t size);

        [[nodiscard]] std::vector<std::vector<char>> value() const;

        void display() const;

        void display(size_t num_per_line) const;

    private:
        void create(std::vector<char> &v, size_t pos);

    private:
        std::vector<std::vector<char>> m_value;
        const std::string m_symbols;
    };
}

#endif //CALCULATOR_SERIAL_SEQUENCE_H
