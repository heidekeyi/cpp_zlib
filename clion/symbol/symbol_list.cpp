//
// Created by 12131 on 2022/9/3.
//

#include "symbol_list.h"
#include <iostream>

namespace ZLIB {
    int SymbolList::minNum() const {
        return valueMinNum;
    }

    SymbolList &SymbolList::minNum(int n) {
        valueMinNum = n;
        n = static_cast<int>(valueSymbol.size());
        n *= n;
        if (valueMinNum < n) {
            valueMinNum = n;
        }
        return *this;
    }

    void SymbolList::display() {
        list();
        int cnt = 0;
        auto sz = valueSymbol.size() -1;
        for (auto &it: valueList) {
            if (cnt && cnt % sz == 0) {
                std::cout << '\n';
            }
            cnt++;
            int index = static_cast<int>(it.size());
            if (index > 0) {
                while (--index >= 0) {
                    std::cout << it[index];
                }
                std::cout << '\t';
            }
        }
        std::cout << std::endl;
    }

    const std::vector<char> &SymbolList::symbol() const {
        return valueSymbol;
    }

    SymbolList &SymbolList::symbol(const std::string &sym) {
        valueSymbol.clear();
        for (auto ch: sym) {
            valueSymbol.push_back(ch);
        }
        valueSymbol.push_back(sym[0]);
        return *this;
    }

    SymbolList &SymbolList::symbol(const char *sym) {
        return symbol(std::string{sym});
    }

    void SymbolList::retrieve_list() {
        valueList.clear();
        valueList.push_back(std::vector<char>{valueSymbol[0]});
        while (valueList.size() < valueMinNum) {
            valueList.push_back(valueList[valueList.size() - 1]);
            add(0);
        }
    }

    void SymbolList::add(int index) {
        auto &it = valueList[valueList.size() - 1];
        if (index >= it.size()) {
            it.push_back(valueSymbol[1]);
            return;
        }
        int pos = 0;
        while (it[index] != valueSymbol[pos++]);
        it[index] = valueSymbol[pos];
        if (valueSymbol[pos] == valueSymbol[0]) {
            add(index + 1);
        }
    }

    const std::vector<std::vector<char>> &SymbolList::list() {
        retrieve_list();
        return valueList;
    }
}