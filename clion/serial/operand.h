//
// Created by 1213173752 on 2022/10/22.
//

#ifndef SERIAL_OPERAND_H
#define SERIAL_OPERAND_H

#include "symbols.h"
#include <ostream>

namespace ZLIB {
    class Operand {
    public:
        Operand(char ch, Symbols symbols);

    public:
        [[nodiscard]] char operand() const;

    private:
        Symbols m_symbols;
        char m_operand;
    };

    std::ostream &operator<<(std::ostream &os, const Operand &o);
}
#endif //SERIAL_OPERAND_H
