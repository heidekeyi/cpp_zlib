//
// Created by 1213173752 on 2022/10/20.
//

#include "message.h"

namespace ZLIB {
    Message::Message(const char *msg)
            : m_message{msg} {}

    const char *Message::what() const noexcept {
        return m_message;
    }

    std::ostream &operator<<(std::ostream &os, const Message &o) {
        os << o.what();
        return os;
    }
}

