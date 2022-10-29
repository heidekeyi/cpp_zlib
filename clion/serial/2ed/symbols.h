//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_SYMBOLS_H
#define SERIAL_SYMBOLS_H

#include <string>
#include <vector>
#include <ostream>

namespace SERIAL {
    class Symbols {
    public:
        explicit Symbols(const std::string &s);

    public:
        Symbols &symbols(const std::string &s);

        [[nodiscard]]  const std::string &symbols() const;

        [[nodiscard]] bool has(char ch) const;

    private:
        std::string m_symbols;
    };

    std::ostream &operator<<(std::ostream &os, const Symbols &o);
}


#endif //SERIAL_SYMBOLS_H
