//
// Created by 12131 on 2022/9/5.
//

#ifndef CALCULATOR_EXPRESSION_H
#define CALCULATOR_EXPRESSION_H

#include <utility>
#include <vector>
#include "action.h"

namespace ZLIB {
    class Expression {
    public:
        Expression(char lhs, char rhs, Action action, std::vector<char> value);

        [[nodiscard]] char lhs() const;

        [[nodiscard]] char action() const;

        [[nodiscard]] char rhs() const;

        [[nodiscard]] const std::vector<char> &value() const;

        Expression &lhs(char l);

        Expression &rhs(char r);

        Expression &action(Action a);

        Expression &value(const std::vector<char> &v);

    private:
        char valueLhs;
        char valueRhs;
        Action valueAction;
        std::vector<char> valueValue;
    };
}


#endif //CALCULATOR_EXPRESSION_H
