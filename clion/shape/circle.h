//
// Created by 12131 on 2022/8/10.
//

#ifndef SHAPE_CIRCLE_H
#define SHAPE_CIRCLE_H

#include "shape.h"

namespace ZLIB {
    class circle : public shape {
    public:
        circle(point p, int r) : pt{p}, rad{r} {}

        point center() const { return pt; }

        void move(const point &to) { pt = to; }

        void draw() const{}

        void rotate(int angle) {}

    private:
        point pt;
        int rad;
    };
}

#endif //SHAPE_CIRCLE_H
