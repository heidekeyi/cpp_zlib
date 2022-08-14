//
// Created by 12131 on 2022/8/14.
//

#ifndef RANDOM_RAND_H
#define RANDOM_RAND_H

#include <random>
#include <vector>

namespace ZLIB {
    class rand {
    private:
        static std::default_random_engine e;
    private:
        static bool exist(const std::vector<unsigned> &vec, unsigned val);

    private:
        unsigned valueMax{0}, valueMin{0};
    public:
        rand &max(unsigned m);

        rand &min(unsigned m);

        unsigned u();

        std::vector<unsigned> un(unsigned n, bool repeat);
    };
}

#endif //RANDOM_RAND_H
