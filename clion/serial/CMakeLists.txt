cmake_minimum_required(VERSION 3.23)
project(serial)

set(CMAKE_CXX_STANDARD 20)

add_executable(serial
        main.cpp
        serial_table.cpp serial_table.h
        serial_formula.cpp serial_formula.h
        serial_value.cpp serial_value.h)
