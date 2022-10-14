#include <iostream>
#include <vector>
#include <string>
#include "serial_table.h"
#include "serial_formula.h"
#include "serial_value.h"
#include "serial_symbols.h"

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

    void test() {
        test_symbols();
        test_value();
        test_formula();
    }
}
