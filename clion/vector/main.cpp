#include <iostream>
#include "vector.h"

void display(const ZLIB::vector &vec) {
    std::cout << "size:" << vec.size() << " element:[";
    for (std::size_t i = 0, sz = vec.size(); i < sz; ++i) {
        std::cout << vec[i];
        if (i + 1 < sz) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

void test_construct() {
    ZLIB::vector v1(12);
    v1.append(3);
    v1.append(9);
    v1.append(6);
    display(v1);
    ZLIB::vector v2{1, 2, 3};
    display(v2);
}


int main() {
    std::cout << "下标越界没有检测" << std::endl;
    test_construct();
    std::cout << "下标越界没有检测" << std::endl;
    return 0;
}
