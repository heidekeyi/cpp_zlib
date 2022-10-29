//
// Created by 1213173752 on 2022/10/25.
//

#include <string>
#include <iostream>

const char *bin() { return "01"; }

const char *dec() { return "012...9"; }

const char *hex() { return "abcdef"; }

template<const char *(*str)()>
class T {
public:
    T() : m_s{str()}, m_value{((reinterpret_cast<size_t> (&dec))) % 1000} {}

    const char *s() { return m_s; }

    size_t operator+(const T &rhs) { return m_value + rhs.m_value; };

    [[nodiscard]] size_t value() const { return m_value; }

private:
    const char *m_s;
    size_t m_value;
};

using Hex = T<hex>;

int main() {
    std::cout << "dec: " << T<dec>{}.s() << std::endl;
    std::cout << "bin: " << T<bin>{}.s() << std::endl;
    T<dec> d1;
    Hex h1, h2;
    std::cout << "+: " << h1 + h2 << std::endl;
    return 0;
}