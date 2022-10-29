//
// Created by 1213173752 on 2022/10/26.
//

#include "serial_message.h"

#include <utility>

namespace SERIAL_MESSAGE {
    SerialMessage::SerialMessage(std::string m, size_t num, const char *pathname)
            : m_serial_message{std::move(m) + std::to_string(num) + pathname} {}

    const char *SerialMessage::what() const noexcept {
        return m_serial_message.c_str();
    }

    std::ostream &operator<<(std::ostream &os, const SerialMessage &o) {
        os << o.what();
        return os;
    }
}