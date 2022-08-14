//
// Created by 12131 on 2022/8/14.
//

#include "rand.h"

namespace ZLIB {
    std::default_random_engine rand::e;

    bool rand::exist(const std::vector<unsigned> &vec, unsigned val) {
        for (auto v: vec) {
            if (val == v) {
                return true;
            }
        }
        return false;
    }

    unsigned rand::u() {
        std::uniform_int_distribution<unsigned> ui(valueMin, valueMax);
        return ui(e);
    }

    rand &rand::max(unsigned int m) {
        valueMax = m;
        return *this;
    }

    rand &rand::min(unsigned int m) {
        valueMin = m;
        return *this;
    }

    std::vector<unsigned> rand::un(unsigned int n, bool repeat) {
        std::vector<unsigned int> vec;
        while (vec.size() < n) {
            auto v = u();
            if (!repeat && exist(vec, v)) {
                continue;
            }
            vec.push_back(v);
        }
        return vec;
    }
}


