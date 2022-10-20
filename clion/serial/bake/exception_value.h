//
// Created by 1213173752 on 2022/10/15.
//

#ifndef SERIAL_EXCEPTION_VALUE_H
#define SERIAL_EXCEPTION_VALUE_H
#include <exception>
namespace ZLIB {
    class ExceptionValue : std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override;
    };
}

#endif //SERIAL_EXCEPTION_VALUE_H
