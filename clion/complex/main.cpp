#include <iostream>
#include "complex.h";

void display(const ZLIB::complex &c) {
    std::cout << "real: " << c.real()
              << "\timag: " << c.imag()
              << std::endl;
}

void test_construct() {
    ZLIB::complex c1;
    std::cout << "+++default construct+++" << std::endl;
    display(c1);
    std::cout << "---default construct---" << std::endl;

    ZLIB::complex c2{2, -2};
    std::cout << "+++two parameter construct+++" << std::endl;
    display(c2);
    std::cout << "---two parameter construct---" << std::endl;

    ZLIB::complex c3{3};
    std::cout << "+++only one parameter construct+++" << std::endl;
    display(c3);
    std::cout << "---only one parameter construct---" << std::endl;
}

void test_set() {
    ZLIB::complex c;
    std::cout << "+++todo+++" << std::endl;
    display(c);
    std::cout << "---todo---" << std::endl;
    c.real(11);
    std::cout << "+++set real+++" << std::endl;
    display(c);
    std::cout << "---set real---" << std::endl;
    c.imag(-11);
    std::cout << "+++set imag+++" << std::endl;
    display(c);
    std::cout << "---set imag---" << std::endl;
}

void test_binary() {
    ZLIB::complex rhs{9, -9};
    ZLIB::complex lhs{999, 999};
    std::cout << "+++init+++" << std::endl;
    std::cout << "+lhs+" << std::endl;
    display(lhs);
    std::cout << "-lhs-" << std::endl;
    std::cout << "+rhs+" << std::endl;
    display(rhs);
    std::cout << "-rhs-" << std::endl;
    std::cout << "---init---" << std::endl;
    std::cout << "+++lhs - rhs+++" << std::endl;
    display(lhs - rhs);
    std::cout << "---lhs - rhs---" << std::endl;
    std::cout << "+++lhs + rhs+++" << std::endl;
    display(lhs + rhs);
    std::cout << "---lhs + rhs---" << std::endl;
    std::cout << "+++lhs * rhs+++" << std::endl;
    display(lhs * rhs);
    std::cout << "---lhs * rhs---" << std::endl;
    std::cout << "+++lhs / rhs+++" << std::endl;
    display(lhs / rhs);
    std::cout << "---lhs / rhs---" << std::endl;
}

void test_unary() {
    ZLIB::complex c{9, -9};
    std::cout << "+++todo+++" << std::endl;
    display(c);
    std::cout << "---todo---" << std::endl;
    std::cout << "+++done+++" << std::endl;
    display(-c);
    std::cout << "---done---" << std::endl;
}

ZLIB::complex test_init() {
    return ZLIB::complex{9, 9};
}

void test_composite() {
    auto init = test_init();
    std::cout << "+++init+++" << std::endl;
    display(init);
    std::cout << "---init---" << std::endl;
    init += ZLIB::complex(3, -6);
    std::cout << "+=(3,-6)" << std::endl;
    display(init);
    std::cout << "+=(3,-6)" << std::endl;
    init -= ZLIB::complex(3, -6);
    std::cout << "-=(3,-6)" << std::endl;
    display(init);
    std::cout << "-=(3,-6)" << std::endl;
    init *= ZLIB::complex(3, -6);
    std::cout << "*=(3,-6)" << std::endl;
    display(init);
    std::cout << "*=(3,-6)" << std::endl;
    init /= ZLIB::complex(3, -6);
    std::cout << "/=(3,-6)" << std::endl;
    display(init);
    std::cout << "/=(3,-6)" << std::endl;
}

void test_compare() {
    ZLIB::complex rhs{9, -9};
    ZLIB::complex lhs{-9, 9};
    std::cout << "*not equal test*" << std::endl;
    std::cout << "+lhs+" << std::endl;
    display(lhs);
    std::cout << "-lhs-" << std::endl;
    std::cout << "+rhs+" << std::endl;
    display(rhs);
    std::cout << "-rhs-" << std::endl;
    if (lhs != rhs) {
        std::cout << "lhs != rhs" << std::endl;
    }else{
        std::cout << "lhs == rhs" << std::endl;
    }
    std::cout << "*not equal test*" << std::endl;
    lhs = rhs;
    std::cout << "*equal test*" << std::endl;
    std::cout << "+lhs+" << std::endl;
    display(lhs);
    std::cout << "-lhs-" << std::endl;
    std::cout << "+rhs+" << std::endl;
    display(rhs);
    std::cout << "-rhs-" << std::endl;
    if (lhs == rhs) {
        std::cout << "lhs == rhs" << std::endl;
    }else{
        std::cout << "lhs != rhs" << std::endl;
    }
    std::cout << "*equal test*" << std::endl;
}

int main() {
    std::cout << "***没有考虑溢出,也没有考虑/0***" << std::endl;
//    test_construct();
//    test_set();
//    test_binary();
//    test_unary();
//    test_composite();
    test_compare();
    std::cout << "***没有考虑溢出,也没有考虑/0***" << std::endl;
    return 0;
}
