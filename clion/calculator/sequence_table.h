//
// Created by 12131 on 2022/9/5.
//

#ifndef CALCULATOR_SEQUENCE_TABLE_H
#define CALCULATOR_SEQUENCE_TABLE_H

#include <vector>
#include <string>

namespace ZLIB {
    class SequenceTable {
    public:
        static std::vector<std::vector<char>> table(const char *serial, int num);

        static std::vector<std::vector<char>> table(const std::string &serial, int num);

        static std::vector<std::vector<char>> table(const std::vector<char> &serial, int num);

        static void display(const char *serial, int num);

        static void display(const std::string &serial, int num);

        static void display(const std::vector<char> &serial, int num);

        static void display(const std::vector<std::vector<char>> &table, int num);

    protected:
        static std::vector<char> convert(const std::string &str);

        static std::vector<char> convert(const char *str);
    };
}

#endif //CALCULATOR_SEQUENCE_TABLE_H
