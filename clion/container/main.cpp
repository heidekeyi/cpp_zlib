#include <iostream>
#include "vector_container.h"
#include "list_container.h"

void use(const ZLIB::container &c) {
    std::cout << "[";
    for (std::size_t i = 0, sz = c.size(); i < sz; ++i) {
        std::cout << c[i];
        if (i + 1 < sz) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "没处理空的情况(size=0)" << std::endl;
    ZLIB::vector_container c1{12};
    c1.append(1);
    c1.append(11);
    c1.append(111);
    use(c1);
    std::cout << "没处理空的情况(size=0)" << std::endl;
    ZLIB::list_container c2{9};
    c2.append(111);
    c2.append(11);
    c2.append(1);
    use(c2);
    return 0;
}
