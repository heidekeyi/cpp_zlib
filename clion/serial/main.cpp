#include <iostream>
#include "serial_table.h"
#include "serial_formula.h"


namespace ZLIB {
    void test_sequence();

    void test_addition();

    void test_multiplication();
}

int main() {
    ZLIB::test_sequence();
    ZLIB::test_addition();
    ZLIB::test_multiplication();
    return 0;
}

namespace ZLIB {
    void test_sequence_empty();

    void test_sequence_one();

    void test_sequence_all();

    void display(const std::vector<char> &vec);

    void display(const std::vector<std::vector<char>> &vec);

    void display(const SerialFormula &serialFormula);

    void display(const std::vector<SerialFormula> &vec);

    void test_sequence() {
        test_sequence_empty();
        test_sequence_one();
        test_sequence_all();
    }

    void test_sequence_all() {
        std::cout << "***all***" << std::endl;
        const char *s1 = "10";
        display(SerialTable::sequence(s1, 1));
        display(SerialTable::sequence(s1, 3));
        const std::string s2{'A', 'B', 'C', 'D', 'E', 'F'};
        display(SerialTable::sequence(s2, 1));
        display(SerialTable::sequence(s2, 9));
        const std::vector<char> s3{'A', 'B', 'C', 'D', 'E', 'F'};
        display(SerialTable::sequence(s3, 1));
        display(SerialTable::sequence(s3, 33));
        display(SerialTable::sequence(s1, 16));
        std::cout << "***all***" << std::endl;
    }

    void test_sequence_one() {
        std::cout << "***one***" << std::endl;
        const char *s1 = "x";
        std::string s2{"y"};
        std::vector<char> s3{'z'};
        display(SerialTable::sequence(s1, 1));
        display(SerialTable::sequence(s1, 3));
        display(SerialTable::sequence(s2, 1));
        display(SerialTable::sequence(s2, 3));
        display(SerialTable::sequence(s3, 1));
        display(SerialTable::sequence(s3, 3));
        std::cout << "***one***" << std::endl;
    }

    void test_sequence_empty() {
        std::cout << "***empty***" << std::endl;
        const char *s1 = "";
        std::string s2;
        std::vector<char> s3;
        display(SerialTable::sequence(s1, 1));
        display(SerialTable::sequence(s1, 3));
        display(SerialTable::sequence(s2, 1));
        display(SerialTable::sequence(s2, 3));
        display(SerialTable::sequence(s3, 1));
        display(SerialTable::sequence(s3, 3));
        std::cout << "***empty***" << std::endl;
    }

    void display(const std::vector<char> &vec) {
        auto sz = vec.size();
        while (sz-- > 0) {
            std::cout << vec[sz];
        }
    }

    void display(const std::vector<std::vector<char>> &vec) {
        std::cout << "size vec: " << vec.size() << std::endl;
        for (auto index = 0; index < vec.size(); ++index) {
            const auto &v = vec[index];
            std::cout << "--size v " << index + 1 << ": " << v.size()
                      << "\n--value v " << index + 1 << ": ";
            display(v);
            std::cout << std::endl;
        }
    }

    void display(const SerialFormula &serialFormula) {
        std::cout << serialFormula.lhs
                  << serialFormula.op
                  << serialFormula.rhs
                  << '=';
        display(serialFormula.value);
    }

    void display(const std::vector<SerialFormula> &vec) {
        auto index = 0;
        auto times = 1;
        auto cnt = 0;
        while (index < vec.size()) {
            if (cnt++ >= times) {
                std::cout << std::endl;
                cnt = 1;
                ++times;
            }
            display(vec[index]);
            std::cout << '\t';
            ++index;
        }
        std::cout << std::endl;
    }

    void test_addition_empty();

    void test_addition_one();

    void test_addition_all();

    void test_addition() {
        test_addition_empty();
        test_addition_one();
        test_addition_all();
    }

    void test_addition_empty() {
        std::cout << "***empty***" << std::endl;
        const char *s1 = "";
        std::string s2;
        std::vector<char> s3;
        display(SerialTable::addition(s1));
        display(SerialTable::addition(s2));
        display(SerialTable::addition(s3));
        std::cout << "***empty***" << std::endl;
    }

    void test_addition_one() {
        std::cout << "***one***" << std::endl;
        const char *s1 = "x";
        std::string s2{"y"};
        std::vector<char> s3{'z'};
        display(SerialTable::addition(s1));
        display(SerialTable::addition(s2));
        display(SerialTable::addition(s3));
        std::cout << "***one***" << std::endl;
    }

    void test_addition_all() {
        std::cout << "***all***" << std::endl;
        const char *s1 = "01";
        display(SerialTable::addition(s1));
        const std::string s2{'A', 'B', 'C', 'D', 'E', 'F'};
        display(SerialTable::addition(s2));
        const std::vector<char> s3{'0', '1', '2', '3', '4', '5', '6', '7'};
        display(SerialTable::addition(s3));
        std::cout << "***all***" << std::endl;
    }
    void test_multiplication_empty();

    void test_multiplication_one();

    void test_multiplication_all();

    void test_multiplication() {
        test_multiplication_empty();
        test_multiplication_one();
        test_multiplication_all();
    }

    void test_multiplication_empty() {
        std::cout << "***empty***" << std::endl;
        const char *s1 = "";
        std::string s2;
        std::vector<char> s3;
        display(SerialTable::multiplication(s1));
        display(SerialTable::multiplication(s2));
        display(SerialTable::multiplication(s3));
        std::cout << "***empty***" << std::endl;
    }

    void test_multiplication_one() {
        std::cout << "***one***" << std::endl;
        const char *s1 = "x";
        std::string s2{"y"};
        std::vector<char> s3{'z'};
        display(SerialTable::multiplication(s1));
        display(SerialTable::multiplication(s2));
        display(SerialTable::multiplication(s3));
        std::cout << "***one***" << std::endl;
    }

    void test_multiplication_all() {
        std::cout << "***all***" << std::endl;
        const char *s1 = "01";
        display(SerialTable::multiplication(s1));
        const std::string s2{'A', 'B', 'C', 'D', 'E', 'F'};
        display(SerialTable::multiplication(s2));
        const std::vector<char> s3{'0', '1', '2', '3', '4', '5', '6', '7'};
        display(SerialTable::multiplication(s3));
        const char *s{"0123456789"};
        display(SerialTable::multiplication(s));
        std::cout << "***all***" << std::endl;
    }
}
