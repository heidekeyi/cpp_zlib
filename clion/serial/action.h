//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_ACTION_H
#define SERIAL_ACTION_H

#include <ostream>

namespace ZLIB {
    class Action {
    public:
        explicit Action(char action);

    public:
        [[nodiscard]] char action() const;

        [[nodiscard]] virtual const char *operations() const;

    private:
        void init() const;

    private:
        char m_action;
    };

    std::ostream &operator<<(std::ostream &os, const Action &o);
}
#endif //SERIAL_ACTION_H
