cmake_minimum_required(VERSION 3.23)
project(serial)

set(CMAKE_CXX_STANDARD 20)

add_executable(serial
        main.cpp
        serial_symbols.cpp serial_symbols.h
        serial_value.cpp serial_value.h
        serial_formula.cpp serial_formula.h
        serial_list.cpp serial_list.h
        serial_sequence.cpp serial_sequence.h
        serial_table.cpp serial_table.h
        serial_addition.cpp serial_addition.h
        serial_multiplication.cpp serial_multiplication.h

        )
