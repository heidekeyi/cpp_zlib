//
// Created by 12131 on 2022/8/8.
//

#ifndef CONTAINER_VECTOR_CONTAINER_H
#define CONTAINER_VECTOR_CONTAINER_H

#include "vector.h"
#include "container.h"

namespace ZLIB {
    class vector_container : public container {
    private:
        vector c;
    public:
        vector_container(std::size_t s) : c(s) {}

        ~vector_container() = default;

        int operator[](std::size_t i) const { return c[i]; };

        std::size_t size() const { return c.size(); };

        void append(int value) { c.append(value); };
    };
}


#endif //CONTAINER_VECTOR_CONTAINER_H
