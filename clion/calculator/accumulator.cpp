//
// Created by 12131 on 2022/9/5.
//

#include "accumulator.h"
#include <iostream>

namespace ZLIB {
    int Accumulator::find_symbol(const std::vector<char> &serial, char symbol) {
        int index = -1;
        for (auto it: serial) {
            ++index;
            if (it == symbol) {
                break;
            }
        }
        return index;
    }

    void Accumulator::execute(std::vector<char> &value, int index, const std::vector<char> &serial) {
        if (value.empty()) {
            std::cout << "value is empty" << std::endl;
            return;
        }
        if (serial.size() < 2) {
            std::cout << "serial size too short, make no sense" << std::endl;
            return;
        }
        if (index < 0) {
            std::cout << "index is negative, make no sense" << std::endl;
            return;
        }
        if (index >= serial.size()) {
            value.push_back(serial[1]);
            return;
        }
        int pos = find_symbol(serial, value[index]);
        if (pos + 1 == serial.size()) {
            value[index] = serial[0];
            execute(value, index + 1, serial);
        } else {
            value[index] = serial[pos + 1];
        }
    }
}