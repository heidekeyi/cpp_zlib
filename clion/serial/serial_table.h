//
// Created by 1213173752 on 2022/10/12.
//

#ifndef SERIAL_SERIAL_TABLE_H
#define SERIAL_SERIAL_TABLE_H

#include <vector>
#include <string>
#include "serial_formula.h"
namespace ZLIB {
    class SerialTable {
    public:
        static std::vector<std::vector<char>> sequence(const char *symbols, size_t num);

        static std::vector<std::vector<char>> sequence(const std::string &symbols, size_t num);

        static std::vector<std::vector<char>> sequence(const std::vector<char> &symbols, size_t num);

        static std::vector<SerialFormula> addition(const char *symbols);

        static std::vector<SerialFormula> addition(const std::string &symbols);

        static std::vector<SerialFormula> addition(const std::vector<char> &symbols);

        static std::vector<SerialFormula> multiplication(const char *symbols);

        static std::vector<SerialFormula> multiplication(const std::string &symbols);

        static std::vector<SerialFormula> multiplication(const std::vector<char> &symbols);
    };
}
#endif //SERIAL_SERIAL_TABLE_H
