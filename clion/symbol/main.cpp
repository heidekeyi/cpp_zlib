#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void convert(int value, const std::string &map, std::vector<char> &v) {
    if (value < map.size()) {
        v.push_back(map[value]);
    } else {
        convert(static_cast<int>(value / map.size()), map, v);
        v.push_back(map[value % map.size()]);
    }
}

void test_symbol() {
    const std::string map = "201";
    std::vector<char> v;
    for (int i = 0; i < 100; ++i) {
        if (i && i % 3 == 0) {
            std::cout << std::endl;
        }
        convert(i, map, v);
        for (auto it: v) {
            std::cout << it;
        }
        v.clear();
        std::cout << '\t';
    }
    std::cout << std::endl;
}


void check(const char *map, const char *path) {
    std::fstream fs(path, std::ios_base::in);
    if (!fs.is_open()) {
        std::cout << "Bad gay" << std::endl;
    } else {
        std::cout << path << ": __^^__" << std::endl;
    }
    std::string str;
    std::vector<char> v;
    int index = 0;
    bool status = true;
    while (fs >> str) {
        convert(index, map, v);
        for (int i = 0; i < v.size() && i < str.size(); ++i) {
            if (v[i] != str[i]) {
                status = false;
                break;
            }
        }
        if (!status) {
            std::cout << "error" << index << '\t' << str << std::endl;
        };
        v.clear();
        ++index;
        status = true;
    }
}

//1100 1011 0101 0100 1110 1011 0101 0111 1011 0100 1010 1011
//C    B    5    4    E    B    5    7    B    4    A    B


//4    8    7    F    D    C    1    2    0    A    C    E    6    9    B    9    5    3    F    E
//0100 1000 0111 1111 1101 1100 0001 0010 0000 1010 1100 1110 0110 1001 1011 1001 0101 0011 1111 1110
int main() {
    check("01", "../bin");
    check("01234567", "../oct");
    return 0;
}
