#include <iostream>
#include <vector>
#include <string>
#include "serial_formula.h"
#include "serial_value.h"
#include "serial_symbols.h"
#include "serial_sequence.h"
#include "serial_addition.h"
#include "serial_multiplication.h"

namespace ZLIB {
    void test();
}

int main() {
    ZLIB::test();
    return 0;
}

namespace ZLIB {
    void test_symbols() {
        SerialSymbols serialSymbols1{""};
        SerialSymbols serialSymbols2{std::string{}};
        SerialSymbols serialSymbols3{std::vector<char>{}};
        SerialSymbols serialSymbols11{"1"};
        SerialSymbols serialSymbols22{std::string{'2'}};
        SerialSymbols serialSymbols33{std::vector<char>{'3'}};
        SerialSymbols serialSymbols111{"01"};
        SerialSymbols serialSymbols222{std::string{'0', '1'}};
        SerialSymbols serialSymbols333{std::vector<char>{'0', '1'}};
        SerialSymbols serialSymbols1111{"01010"};
        SerialSymbols serialSymbols2222{std::string{'0', '1', '0', '1', '0'}};
        SerialSymbols serialSymbols3333{std::vector<char>{'0', '1', '1', '0'}};
        std::cout << "symbols: " << serialSymbols1 << '\n'
                  << "symbols: " << serialSymbols2 << '\n'
                  << "symbols: " << serialSymbols3 << '\n'
                  << "symbols: " << serialSymbols11 << '\n'
                  << "symbols: " << serialSymbols22 << '\n'
                  << "symbols: " << serialSymbols33 << '\n'
                  << "symbols: " << serialSymbols111 << '\n'
                  << "symbols: " << serialSymbols222 << '\n'
                  << "symbols: " << serialSymbols333 << '\n'
                  << "symbols: " << serialSymbols1111 << '\n'
                  << "symbols: " << serialSymbols2222 << '\n'
                  << "symbols: " << serialSymbols3333 << '\n'
                  << std::endl;
    }

    void test_value() {
        SerialValue serialValue1('*');
        SerialValue serialValue2("011101");
        SerialValue serialValue3(std::vector<char>{'0', '1', '2'});
        std::cout << "value: " << serialValue1 << '\n'
                  << "value: " << serialValue2 << '\n'
                  << "value: " << serialValue3 << '\n'
                  << std::endl;
    }

    void test_formula() {
        SerialFormula serialFormula1{'3', '*', '6', std::vector<char>{'8', '1'}};
        SerialFormula serialFormula2{'8', '*', '9', std::vector<char>{'2', '7'}};
        std::cout << "formula: " << serialFormula1 << '\n'
                  << "formula: " << serialFormula2 << '\n'
                  << std::endl;
    }

    void test_sequence() {
        SerialSequence serialSequence1{"1", 3};
        SerialSequence serialSequence2{std::string{'0', '1'}, 3};
        SerialSequence serialSequence3{std::vector<char>{'0', '1', '0', '1', '1'}, 3};
        SerialSequence serialSequence11{"0123456789"};
        SerialSequence serialSequence111{"0123456789", 120};
        std::cout << serialSequence1
                  << serialSequence2
                  << serialSequence3
                  << serialSequence11
                  << serialSequence2.number(18)
                  << serialSequence111
                  << std::endl;
    }

    void test_addition() {
        SerialAddition serialAddition1{""};
        SerialAddition serialAddition2{"1"};
        SerialAddition serialAddition3{"0123456789"};
        std::cout << serialAddition1
                  << serialAddition2
                  << serialAddition3
                  << std::endl;
    }

    void test_multiplication() {
        SerialMultiplication serialMultiplication1{""};
        SerialMultiplication serialMultiplication2{"0"};
        SerialMultiplication serialMultiplication3{"01"};
        SerialMultiplication serialMultiplication11{"0123456789"};
        std::cout << serialMultiplication1
                  << serialMultiplication2
                  << serialMultiplication3
                  << serialMultiplication11
                  << std::endl;
    }

    void test() {
        test_symbols();
        test_value();
        test_formula();
        test_sequence();
        test_addition();
        test_multiplication();
    }
}
