//
// Created by 12131 on 2022/9/5.
//

#ifndef CALCULATOR_ACCUMULATOR_H
#define CALCULATOR_ACCUMULATOR_H

#include <vector>

namespace ZLIB {
    class Accumulator {
    public:
        static void execute(std::vector<char> &value, int index, const std::vector<char> &serial);

        static int find_symbol(const std::vector<char> &serial, char symbol);
    };
}

#endif //CALCULATOR_ACCUMULATOR_H
