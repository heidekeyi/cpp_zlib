//
// Created by 12131 on 2022/8/8.
//

#ifndef CONTAINER_CONTAINER_H
#define CONTAINER_CONTAINER_H

#include <iostream>

namespace ZLIB {
    class container {
    public:
        virtual int operator[](std::size_t i) const = 0;

        virtual std::size_t size() const = 0;
        virtual void append(int value) = 0;
        virtual ~container() = default;;
    };
}

#endif //CONTAINER_CONTAINER_H
