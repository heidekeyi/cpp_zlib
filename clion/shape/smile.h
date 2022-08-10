//
// Created by 12131 on 2022/8/10.
//

#ifndef SHAPE_SMILE_H
#define SHAPE_SMILE_H

#include <vector>
#include "circle.h"

namespace ZLIB {
    class smile : public circle {
    public:
        smile(point pt, int r) : circle{pt, r}, mouth{nullptr} {}

        ~smile() {
            delete mouth;
            for (auto it: eyes) {
                delete it;
            }
        }

        void move(point pt) {}

        void draw() const {
            for (auto it: eyes) {
                it->draw();
            }
            mouth->draw();
        }

        void add_eyes(shape *s) { eyes.push_back(s); }

        void set_mouth(shape *s) { mouth = s; }

        virtual void wink(int i);

    private:
        std::vector<shape *> eyes;
        shape *mouth;
    };
}

#endif //SHAPE_SMILE_H
