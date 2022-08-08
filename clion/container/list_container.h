//
// Created by 12131 on 2022/8/8.
//

#ifndef CONTAINER_LIST_CONTAINER_H
#define CONTAINER_LIST_CONTAINER_H

#include <list>
#include "container.h"

namespace ZLIB {
    class list_container : public container {
    private:
        std::list<int> c;
    public:
        list_container(std::size_t s) : c{}{}

        ~list_container() = default;

        int operator[](std::size_t i) const;

        std::size_t size() const { return c.size(); };

        void append(int value) { c.push_back(value); };
    };
}

#endif //CONTAINER_LIST_CONTAINER_H
