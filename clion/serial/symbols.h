//
// Created by 1213173752 on 2022/10/31.
//

#ifndef SERIAL_SYMBOLS_H
#define SERIAL_SYMBOLS_H

#include <string>
#include "message.h"

namespace SERIAL {
    using CALLBACK = const char *(*)();
    namespace SYMBOLS_CALLBACK {
        const char *dec();

        const char *bin();

        const char *hex();
    }
    class Symbols {
    public:
        explicit Symbols(CALLBACK callback);

        [[nodiscard]]  const std::string &symbols() const;

        [[nodiscard]] int find(char ch) const;

        [[nodiscard]] char first() const;

    private:
        std::string m_symbols;
    };

    std::ostream &operator<<(std::ostream &os, const Symbols &o);
}

#endif //SERIAL_SYMBOLS_H
