cmake_minimum_required(VERSION 3.23)
project(complex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -g -O0")
add_executable(complex
        main.cpp
        complex.cpp complex.h )
