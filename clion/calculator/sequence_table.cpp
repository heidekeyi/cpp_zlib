//
// Created by 12131 on 2022/9/5.
//

#include "sequence_table.h"
#include <iostream>
#include "accumulator.h"

namespace ZLIB {
    std::vector<char> SequenceTable::convert(const std::string &str) {
        std::vector<char> v;
        for (auto it: str) {
            v.push_back(it);
        }
        return v;
    }

    std::vector<char> SequenceTable::convert(const char *str) {
        return convert(std::string(str));
    }

    std::vector<std::vector<char>> SequenceTable::table(const char *serial, int num) {
        return table(convert(serial), num);
    }

    std::vector<std::vector<char>> SequenceTable::table(const std::string &serial, int num) {
        return table(convert(serial), num);
    }

    std::vector<std::vector<char>> SequenceTable::table(const std::vector<char> &serial, int num) {
        std::vector<std::vector<char>> list;
        if (num < 0) {
            std::cout << "list size negative make no sense" << std::endl;
            return list;
        }
        for (auto ch: serial) {
            list.push_back(std::vector<char>{ch});
        }
        while (list.size() < num) {
            auto value = list[list.size() - 1];
            Accumulator::execute(value, 0, serial);
            list.push_back(value);
        }
        return list;
    }

    void SequenceTable::display(const char *serial, int num) {
        display(convert(serial), num);
    }

    void SequenceTable::display(const std::string &serial, int num) {
        display(convert(serial), num);
    }

    void SequenceTable::display(const std::vector<char> &serial, int num) {
        display(table(serial, num), static_cast<int>(serial.size()));
    }

    void SequenceTable::display(const std::vector<std::vector<char>> &table, int num) {
        int cnt = 0;
        for (auto &vec: table) {
            int index = static_cast<int>(vec.size());
            while (--index >= 0) {
                std::cout << vec[index];
            }
            ++cnt;
            if (cnt < num) {
                std::cout << '\t';
            } else {
                cnt = 0;
                std::cout << '\n';
            }
        }
    }
}