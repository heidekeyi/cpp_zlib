//
// Created by 12131 on 2022/9/15.
//

#ifndef CALCULATOR_SERIAL_TABLE_H
#define CALCULATOR_SERIAL_TABLE_H

#include <vector>
#include <string>
namespace ZLIB {
    class SerialTable {
    public:
        SerialTable(const char *symbols);

        std::vector<std::vector<char>> addition() const;

        std::vector<std::vector<char>> multiplication() const;

        void display() const;
    private:
        const std::string m_symbols;
    };
}
#endif //CALCULATOR_SERIAL_TABLE_H
