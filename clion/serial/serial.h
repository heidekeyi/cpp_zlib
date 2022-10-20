//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_SERIAL_H
#define SERIAL_SERIAL_H

#include "symbols.h"

namespace ZLIB {
    class Serial {
    protected:
        [[nodiscard]] virtual Symbols symbols() const = 0;
    };
}

#endif //SERIAL_SERIAL_H
