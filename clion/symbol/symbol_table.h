//
// Created by 12131 on 2022/9/3.
//

#ifndef SYMBOL_SYMBOL_TABLE_H
#define SYMBOL_SYMBOL_TABLE_H

#include <string>
#include <vector>
#include "symbol_base.h"

namespace ZLIB {
    class SymbolTable : public SymbolBase {
    protected:
        class Expression {
        public:
            Expression(char l, char r, char s, std::vector<char> v);

            char lhs;
            char rhs;
            char sym;
            std::vector<char> value;
        };

        enum class Action {
            add,
            sub,
            mul,
            div
        };
    protected:
        [[nodiscard]] virtual Action retrieve_action() const = 0;

    public:
        std::vector<Expression> retrieve_table_list();

    public:
        void display() override;
    };
}


#endif //SYMBOL_SYMBOL_TABLE_H
