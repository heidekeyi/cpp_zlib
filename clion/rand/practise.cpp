//
// Created by 12131 on 2022/8/14.
//

#include "practise.h"
#include <iostream>

std::string reverse(const std::string &str) {
    std::string s{str};
    int src = static_cast<int>(str.size() - 1);
    int des = 0;
    const int sz = sizeof("烦") - 1;
    while (src >= 0) {
        auto c = str[src];
        if (c > 127 || c < 0) {
            auto pos = src - sz + 1;
            while (pos <= src) {
                s[des++] = str[pos++];
            }
            src -= sz;
        } else {
            s[des++] = str[src--];
        }
    }
    return s;
}