
#include "serial_sequence.h"
#include <iostream>
namespace ZLIB {
    void test() {
        SerialSequence sequence("abcdef", 39);
        for(auto v: sequence.value()){
            SerialSequence::display(v);
            std::cout << std::endl;
        }
//        sequence.display();
//        sequence.display(10);
    }
}

int main() {
    ZLIB::test();
    return 0;
}
