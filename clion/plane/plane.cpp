//
// Created by 12131 on 2022/8/13.
//

#include "plane.h"
#include <iostream>

namespace ZLIB {
    std::vector<std::vector<int>> max_4(const std::vector<std::vector<int>> &vec) {
        auto v = vec;
        const auto sz = static_cast<int>(v.size() - 1);
        for (auto i = 1; i < sz; ++i) {
            auto it = vec[i];
            for (auto j = 1; j < sz; ++j) {
                auto d = it[j];
                if (d > vec[i][j - 1]
                    && d > vec[i][j + 1]
                    && d > vec[i - 1][j]
                    && d > vec[i + 1][j]) {
                    v[i][j] = -1;
                }
            }
        }
        for (auto &i: v) {
            for (int &j: i) {
                j = j < 0 ? 1 : 0;
            }
        }
        return v;
    }

    std::vector<std::vector<int>> max_8(const std::vector<std::vector<int>> &vec) {
        auto v = vec;
        const auto sz = static_cast<int>(v.size() - 1);
        for (auto i = 1; i < sz; ++i) {
            auto it = vec[i];
            for (auto j = 1; j < sz; ++j) {
                auto d = it[j];
                if (d > vec[i][j - 1]
                    && d > vec[i][j + 1]
                    && d > vec[i - 1][j]
                    && d > vec[i + 1][j]
                    && d > vec[i + 1][j + 1]
                    && d > vec[i + 1][j - 1]
                    && d > vec[i - 1][j + 1]
                    && d > vec[i - 1][j - 1]) {
                    v[i][j] = -1;
                }
            }
        }
        for (auto &i: v) {
            for (int &j: i) {
                j = j < 0 ? 1 : 0;
            }
        }
        return v;
    }

    void triangle(int n) {
        std::vector<std::vector<int>> vec1;
        for (auto i = 0; i < n; ++i) {
            vec1.emplace_back(n);
        }
        vec1[0][0] = 1;
        for (auto i = 1; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (j - 1 < 0) {
                    vec1[i][j] = 1;
                } else {
                    vec1[i][j] = vec1[i - 1][j - 1] + vec1[i - 1][j];
                }
            }
        }
        for (auto &v: vec1) {
            for (auto i: v) {
                std::cout << i << ' ';
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        const auto sz = n + n - 1;
        std::vector<std::vector<int>> vec2;
        for (auto i = 0; i < n; ++i) {
            vec2.emplace_back(sz);
        }
        for (auto i = 0; i < n; ++i) {
            const auto v1 = vec1[i];
            auto &v2 = vec2[i];
            for (auto j1 = 0, j2 = sz - n - i; j2 < sz && v1[j1]; j2 += 2, ++j1) {
                v2[j2] = v1[j1];
            }
        }
        for (auto &v: vec2) {
            for (auto i: v) {
                if (i > 0) {
                    std::cout << i;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }
}

//000010000
//000101000
//001020100
//010303010
//104060401