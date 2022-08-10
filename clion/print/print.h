//
// Created by 12131 on 2022/8/9.
//

#ifndef PRINT_PRINT_H
#define PRINT_PRINT_H

#include <iostream>
#include <string>

namespace ZLIB {
    class print {
    private:
        static const char ch;
    public:
        print &inc(size_t n);

        print &dec(size_t n);

        print &row_col(size_t r, size_t c);

        print &pyramid(size_t r);

        print &mul();

        print &daf();

        print &fab(size_t n);

        print &bin(size_t val);

        print &dec(const char *ptr);

        print &reverse(const char *ptr);

        print &chicken();

        print &word(const char *ptr);

        print &str(std::string str);
    };
}

#endif //PRINT_PRINT_H
