//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_MESSAGE_H
#define SERIAL_MESSAGE_H

#include <exception>
#include <ostream>

namespace SERIAL {
    class Message : public std::exception {
    public:
        explicit Message(const char *msg);

        [[nodiscard]] const char *what() const noexcept override;

    private:
        const char *m_message;
    };

    std::ostream &operator<<(std::ostream &os, const Message &o);
}

#endif //SERIAL_MESSAGE_H
