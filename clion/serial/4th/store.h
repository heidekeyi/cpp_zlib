//
// Created by 1213173752 on 2022/10/28.
//

#ifndef SERIAL_STORE_H
#define SERIAL_STORE_H

#include "../symbols.h"
#include "../message.h"
#include <vector>
#include <string>
#include <ostream>

namespace SERIAL::STORE {
    using namespace SYMBOLS;
    using namespace MESSAGE;

    template<const char *(*fn)()>
    class Store {
    private:
        [[nodiscard]] Symbols createSymbols() const;

    public:
        Store();

        explicit Store(const std::string &s);

        explicit Store(const std::vector<char> &s);

    public:
        [[nodiscard]] const std::vector<char> &store() const;

        [[nodiscard]] const Symbols &symbols() const;

        Store<fn> &store(const std::vector<char> &s);

        Store<fn> &store(const std::string &s);

    private:
        Symbols m_symbols;
        std::vector<char> m_store;
    };

    template<const char *(*fn)()>
    Symbols Store<fn>::createSymbols() const {
        return Symbols(fn());
    }

    template<const char *(*fn)()>
    Store<fn>::Store()
            : m_symbols{createSymbols()} {
        store("");
    }

    template<const char *(*fn)()>
    Store<fn>::Store(const std::string &s)
            : m_symbols{createSymbols()} {
        store(s);
    }

    template<const char *(*fn)()>
    Store<fn>::Store(const std::vector<char> &s)
            : m_symbols{createSymbols()} {
        store(s);
    }

    template<const char *(*fn)()>
    const Symbols &Store<fn>::symbols() const {
        return m_symbols;
    }

    template<const char *(*fn)()>
    const std::vector<char> &Store<fn>::store() const {
        return m_store;
    }

    template<const char *(*fn)()>
    Store<fn> &Store<fn>::store(const std::vector<char> &s) {
        for (auto ch: s) {
            if (!m_symbols.any(ch)) {
                throw Message{"store has unexpect char"};
            }
        }
        if (s.empty()) {
            m_store = {m_symbols.symbols()[0]};
        } else {
            m_store = s;
        }
        return *this;
    }

    template<const char *(*fn)()>
    Store<fn> &Store<fn>::store(const std::string &s) {
        std::vector<char> v;
        for (auto ch: s) {
            v.push_back(ch);
        }
        return store(v);
    }

    template<const char *(*fn)()>
    std::ostream &operator<<(std::ostream &os, const Store<fn> &o) {
        auto v = o.store();
        auto index = v.size();
        while (index > 0) {
            os << v[--index];
        }
        return os;
    }
}

#endif //SERIAL_STORE_H
