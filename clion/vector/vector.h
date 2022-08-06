//
// Created by 12131 on 2022/8/6.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>

namespace ZLIB {
    class vector {
    private:
        int *elem;
        std::size_t sz;
        size_t ix;
    public:
        explicit vector(std::size_t s) : elem{new int[s]}, sz{s}, ix{0} {}

        vector(std::initializer_list<int> list);

        ~vector() { delete[]elem; }

    public:
        int operator[](std::size_t i) { return elem[i]; }
        int operator[](std::size_t i)const { return elem[i]; }

        std::size_t size() const { return ix; }

    public:
        void append(int value);

    public:
    };
}

#endif //VECTOR_VECTOR_H
