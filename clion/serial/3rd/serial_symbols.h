//
// Created by 1213173752 on 2022/10/26.
//

#ifndef SERIAL_SERIAL_SYMBOLS_H
#define SERIAL_SERIAL_SYMBOLS_H

#include <ostream>
#include <vector>
#include <string>

namespace SERIAL_SYMBOLS {
    class SerialSymbols {
    public:
        explicit SerialSymbols(const std::string &s);

    public:
        SerialSymbols &symbols(const std::string &s);

        [[nodiscard]]  const std::string &symbols() const;

        [[nodiscard]] bool has(char ch) const;

    private:
        std::string m_serial_symbols;
    };

    std::ostream &operator<<(std::ostream &os, const SerialSymbols &o);
}

#endif //SERIAL_SERIAL_SYMBOLS_H
