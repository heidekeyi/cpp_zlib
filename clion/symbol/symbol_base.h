//
// Created by 12131 on 2022/9/4.
//

#ifndef SYMBOL_SYMBOL_BASE_H
#define SYMBOL_SYMBOL_BASE_H

#include <vector>
#include <string>

namespace ZLIB {
    class SymbolBase {
    public:
        virtual void display() = 0;

    protected:
        static void display(const std::vector<char> &vec);

    public:
        SymbolBase &symbol(const char *sym);

        SymbolBase &symbol(const std::string &sym);

        [[nodiscard]] const std::vector<char> &symbol() const;

    protected:
        [[nodiscard]] int retrieve_index(char ch) const;

    protected:
        std::vector<char> valueSymbol;
    };
}
#endif //SYMBOL_SYMBOL_BASE_H
