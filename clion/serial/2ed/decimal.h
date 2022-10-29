//
// Created by 1213173752 on 2022/10/25.
//

#ifndef SERIAL_DECIMAL_H
#define SERIAL_DECIMAL_H

#include "serial.h"

namespace SERIAL {
    using Decimal = Serial<[] { return "0123456789"; }>;
}
#endif //SERIAL_DECIMAL_H
