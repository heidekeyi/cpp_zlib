//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_CALCULATOR_H
#define SERIAL_CALCULATOR_H

#include "store.h"

namespace SERIAL::CALCULATOR {
    using namespace STORE;

    template<const char *(*fn)()>
    class Calculator {
    public:
        static Store<fn> add(const Store<fn> &lhs, const Store<fn> &rhs);

    public:
        explicit Calculator(const Store<fn> &s);

    public:
        Store<fn> inc() const;

    private:
        Store<fn> m_store;
    };

    template<const char *(*fn)()>
    Calculator<fn>::Calculator(const Store<fn> &s)
            : m_store{s} {}

    template<const char *(*fn)()>
    Store<fn> Calculator<fn>::inc() const {
        return m_store;
    }

    template<const char *(*fn)()>
    Store<fn> Calculator<fn>::add(const Store<fn> &lhs, const Store<fn> &rhs) {
        return Store<fn>();
    }
}

#endif //SERIAL_CALCULATOR_H
