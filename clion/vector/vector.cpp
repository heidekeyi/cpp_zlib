//
// Created by 12131 on 2022/8/6.
//

#include "vector.h"

namespace ZLIB {
    void vector::append(int value) {
        auto e = elem;
        auto pos = ix;
        if (++pos >= sz) {
            sz *= 2;
            elem = new int[sz];
            for (auto i = 0; i < ix; ++i) {
                elem[i] = e[i];
            }
            delete[]e;
        }
        elem[ix++] = value;
    }

    vector::vector(std::initializer_list<int> list)
            : elem{new int[list.size()]}, sz{list.size()}, ix{list.size()} {
        std::copy(list.begin(), list.end(), elem);
    }
}

