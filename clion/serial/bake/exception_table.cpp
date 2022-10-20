//
// Created by 1213173752 on 2022/10/15.
//

#include "exception_table.h"

namespace ZLIB {
    const char *ExceptionTable::what() const noexcept {
        return "lhs && rhs not find on table";
    }
}