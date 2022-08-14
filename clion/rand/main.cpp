#include <iostream>
#include "rand.h"
#include "practise.h"

void display(const std::vector<unsigned> &vec) {
    for (auto v: vec) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main() {
    ZLIB::rand r;
    r.min(0).max(32);
    unsigned cnt = 99;
    std::vector<unsigned> vec(33);
    while (cnt > 0) {
        --cnt;
        for (auto v: r.un(6, false)) {
            ++vec[v];
        }
    }
    display(vec);
    const std::string str{"b我a不是c你的人a"};
    std::cout << str << '\n' << reverse(str) << std::endl;
    return 0;
}
