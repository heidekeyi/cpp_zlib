//
// Created by 1213173752 on 2022/10/28.
//

#include "message.h"

#include <utility>

namespace SERIAL {
    Message::Message(std::string s)
            : m_message{std::move(s)} {}

    const char *Message::what() const noexcept {
        return m_message.c_str();
    }

    std::ostream &operator<<(std::ostream &os, const Message &o) {
        os << o.what();
        return os;
    }
}