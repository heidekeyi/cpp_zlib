//
// Created by 1213173752 on 2022/10/25.
//

#ifndef SERIAL_CONTAINER_H
#define SERIAL_CONTAINER_H

#include <vector>
#include <string>
#include "symbols.h"

namespace SERIAL {
    class Container {
    public:
        explicit Container(const std::vector<char> &v, Symbols s);

        explicit Container(const std::string &v, Symbols s);

    public:
        [[nodiscard]] const std::vector<char> &value() const;

        Container &value(const std::vector<char> &v);

        Container &value(const std::string &v);

    private:
        std::vector<char> m_value;
        const Symbols m_symbols;
    };

    std::ostream &operator<<(std::ostream &os, const Container &o);
}
#endif //SERIAL_CONTAINER_H
