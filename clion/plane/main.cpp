#include <iostream>
#include <vector>
#include <random>
#include "plane.h"

std::default_random_engine E;

std::vector<int> init(int from, int to, int num) {
    std::uniform_int_distribution<unsigned int> u(from, to);
    std::vector<int> vec;
    for (auto i = 0; i < num; ++i) {
        vec.push_back(u(E));
    }
    return vec;
}

void display(const std::vector<std::vector<int>> &vec) {
    for (auto &v: vec) {
        for (auto i: v) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> vec;
    const auto n{9};;
    for (auto i = 0; i < n; ++i) {
        vec.push_back(init(1000, 9999, n));
    }
    display(vec);
    display(ZLIB::max_4(vec));
    display(vec);
    display(ZLIB::max_8(vec));
    ZLIB::triangle(5);
    return 0;
}

//
//    1
//   1 1
//  1 2 1
// 1 3 3 1
//1 4 6 4 1
