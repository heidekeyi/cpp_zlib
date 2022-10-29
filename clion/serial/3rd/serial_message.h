//
// Created by 1213173752 on 2022/10/26.
//

#ifndef SERIAL_SERIAL_MESSAGE_H
#define SERIAL_SERIAL_MESSAGE_H

#include <exception>
#include <string>
#include <ostream>

namespace SERIAL_MESSAGE {
    class SerialMessage : public std::exception {
    public:
        explicit SerialMessage(std::string m, size_t num, const char *pathname = __FILE__);

        [[nodiscard]] const char *what() const noexcept override;

    private:
        const std::string m_serial_message;
    };

    std::ostream &operator<<(std::ostream &os, const SerialMessage &o);
}

#endif //SERIAL_SERIAL_MESSAGE_H
