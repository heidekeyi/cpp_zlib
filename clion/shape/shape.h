//
// Created by 12131 on 2022/8/10.
//

#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H

namespace ZLIB {
    struct point {
        double x;
        double y;
    };

    class shape {
    public:
        virtual point center() const = 0;

        virtual void move(const point &to) = 0;

        virtual void rotate(int angle) = 0;

        virtual void draw() const;

        virtual ~shape() = default;
    };
}

#endif //SHAPE_SHAPE_H
