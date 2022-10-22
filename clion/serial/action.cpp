//
// Created by 1213173752 on 2022/10/22.
//

#include "action.h"
#include "message.h"

namespace ZLIB {
    Action::Action(char action) : m_action{action} {
        init();
    }

    char Action::action() const {
        return m_action;
    }

    const char *Action::operations() const {
        return "+*";
    }

    void Action::init() const {
        auto op = operations();
        auto status = false;
        while (*op) {
            if (*op == m_action) {
                status = true;
                break;
            }
            ++op;
        }
        if (!status) {
            throw Message("action: value of action can not find in operations");
        }
    }

    std::ostream &operator<<(std::ostream &os, const Action &o) {
        return os << o.action();
    }
}