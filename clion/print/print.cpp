//
// Created by 12131 on 2022/8/9.
//

#include "print.h"


namespace ZLIB {
    const char print::ch = '#';

    print &print::inc(size_t n) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j <= i; ++j) {
                std::cout << print::ch;
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::row_col(size_t r, size_t c) {
        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < c; ++j) {
                std::cout << print::ch;
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::dec(size_t n) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = n - i; j > 0; --j) {
                std::cout << print::ch;
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::pyramid(size_t r) {
        size_t n = 2 * r - 1;
        size_t m = n / 2;
        for (size_t i = 0; i < r; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (j >= m - i && j <= m + i) {
                    std::cout << ch;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::mul() {
        for (auto i = 1; i <= 9; i++) {
            for (auto j = 1; j <= i; ++j) {
                std::cout << j << '*' << i << '=' << i * j << '\t';
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::daf() {
        for (auto i = 100; i < 1000; ++i) {
            auto low = i % 10, mid = i / 10 % 10, high = i / 100;
            if (low * low * low + mid * mid * mid + high * high * high == i) {
                std::cout << i << '\t';
            }
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::fab(size_t n) {
        for (size_t i = 0, tmp = 0, prev = 0, next = 1; i < n; ++i) {
            std::cout << next << '\t';
            tmp = next;
            next += prev;
            prev = tmp;
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::bin(size_t val) {
        size_t n = sizeof(val) * 8;
        for (size_t i = 1; i <= n; ++i) {
            if ((val >> (n - i)) & 1) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::dec(const char *ptr) {
        auto sum = 0, beg = 1;
        const char *p = ptr;
        while (*p) {
            beg *= 2;
            ++p;
        }
        p = ptr;
        beg /= 2;
        while (*p) {
            if (*p == '1') {
                sum += beg;
            }
            beg /= 2;
            ++p;
        }
        std::cout << sum << std::endl;
        return *this;
    }

    print &print::reverse(const char *ptr) {
        const char *p = ptr;
        std::cout << "src: " << ptr << std::endl;
        while (*p) {
            ++p;
        }
        --p;
        std::cout << "des: ";
        while (p >= ptr) {
            std::cout << *p;
            --p;
        }
        std::cout << std::endl;
        return *this;
    }

    print &print::chicken() {
        const auto total = 1000;
        for (auto i = 0; i < total / 50; ++i) {
            for (auto j = 0; j < total / 30; ++j) {
                for (auto k = 0; k < total / 10; k += 3) {
                    if (i + j + k == 100 && i * 50 + j * 30 + k * 10 / 3 == 1000) {
                        std::cout << "big: " << i
                                  << "\tmid: " << j
                                  << "\tsma: " << k
                                  << std::endl;
                    }
                }
            }
        }
        return *this;
    }

    print &print::word(const char *ptr) {
        const char *p = ptr;
        auto sum = 0;
        bool flags = false;
        while (*p) {
            if (*p == ' ') {
                if (flags) {
                    ++sum;
                }
                flags = false;
            } else {
                flags = true;
            }
            ++p;
        }
        if (flags) {
            ++sum;
        }
        std::cout << "word count: " << sum << std::endl;
        return *this;
    }

    print &print::str(std::string str) {
        std::cout << str << std::endl;
        int sz = static_cast<int>(str.size());
        int mid = sz / 2;
        for (int i = 0; i <= mid; ++i) {
            char c = str[i];
            size_t ix = sz - i - 1;
            str[i] = str[ix];
            str[ix] = c;
        }
        std::cout << str << std::endl;
        auto pos = 0;
        while (pos < sz) {
            while (pos < sz && str[pos] == ' ') {
                ++pos;
            }
            if (pos >= sz) {
                break;
            }
            auto beg = pos;
            while (pos < sz && str[pos] != ' ') {
                ++pos;
            }
            auto end = pos - 1;
            while (beg < end) {
                auto c = str[beg];
                str[beg] = str[end];
                str[end] = c;
                beg++;
                end--;
            }
        }
        std::cout << str << std::endl;
        return *this;
    }
}