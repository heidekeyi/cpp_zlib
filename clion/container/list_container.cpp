//
// Created by 12131 on 2022/8/8.
//

#include "list_container.h"
#include <exception>

namespace ZLIB {
    int list_container::operator[](std::size_t ix) const {
        size_t i = 0;
        for (auto it: c) {
            if (i == ix) {
                return it;
            }
            ++i;
        }
        throw std::out_of_range("list container");
    }
}