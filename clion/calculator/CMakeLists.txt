cmake_minimum_required(VERSION 3.23)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator
        main.cpp
        serial.cpp serial.h
        serial_ten.cpp serial_ten.h
        serial_sequence.cpp serial_sequence.h
        serial_table.cpp serial_table.h serial_formula.cpp serial_formula.h)
