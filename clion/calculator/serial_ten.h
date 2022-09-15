//
// Created by 12131 on 2022/9/14.
//

#ifndef CALCULATOR_SERIAL_TEN_H
#define CALCULATOR_SERIAL_TEN_H

#include "serial.h"

namespace ZLIB {
    class SerialTen : public Serial {
    public:
        [[nodiscard]] const char * symbols() const override;
    };
}

#endif //CALCULATOR_SERIAL_TEN_H
