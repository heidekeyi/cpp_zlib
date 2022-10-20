//
// Created by 1213173752 on 2022/10/20.
//

#ifndef SERIAL_SYMBOLS_H
#define SERIAL_SYMBOLS_H

#include <string>
#include <vector>
#include <ostream>

namespace ZLIB {
    class Symbols {
    public:
        explicit Symbols(const char *s);

        explicit Symbols(const std::string &s);

        explicit Symbols(const std::vector<char> &s);

    public:
        void symbols(const char *s);

        void symbols(const std::string &s);

        void symbols(const std::vector<char> &s);

        [[nodiscard]] const std::vector<char> &symbols() const;

    private:
        void init(const std::string &s);

        void init(const std::vector<char> &s);

    private:
        void visibility();

        void length();

        void unique();

    private:
        std::vector<char> m_symbols;
    };

    std::ostream &operator<<(std::ostream &os, const Symbols &o);
}


#endif //SERIAL_SYMBOLS_H
