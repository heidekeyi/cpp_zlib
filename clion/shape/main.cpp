#include <iostream>
#include "shape.h"
#include <vector>

void rotate(std::vector<ZLIB::shape *> &v, int angle) {
    for (auto it: v) {
        it->rotate(angle);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
