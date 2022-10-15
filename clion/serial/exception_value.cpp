//
// Created by 1213173752 on 2022/10/15.
//

#include "exception_value.h"

namespace ZLIB {
    const char *ExceptionValue::what() const noexcept {
        return "element of value not find on symbols";
    }
}