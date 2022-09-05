//
// Created by 12131 on 2022/9/5.
//

#include "expression.h"


namespace ZLIB {
    Expression::Expression(char lhs, char rhs, Action action, std::vector<char> value)
            : valueLhs{lhs}, valueRhs{rhs}, valueAction{action}, valueValue(std::move(value)) {}

    char Expression::lhs() const {
        return valueLhs;
    }

    char Expression::action() const {
        return static_cast<char>(valueAction);
    }

    char Expression::rhs() const {
        return valueRhs;
    }

    const std::vector<char> &Expression::value() const {
        return valueValue;
    }

    Expression &Expression::lhs(char l) {
        valueLhs = l;
        return *this;
    }

    Expression &Expression::rhs(char r) {
        valueRhs = r;
        return *this;
    }

    Expression &Expression::action(Action a) {
        valueAction = a;
        return *this;
    }

    Expression &Expression::value(const std::vector<char> &v) {
        valueValue = v;
        return *this;
    }
}