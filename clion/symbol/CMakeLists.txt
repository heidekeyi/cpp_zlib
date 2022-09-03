cmake_minimum_required(VERSION 3.23)
project(symbol)
set(CMAKE_CXX_STANDARD 17)
add_executable(
        symbol
        main.cpp
        parse.h parse.c
        symbol_list.cpp symbol_list.h
        symbol_table_add.cpp symbol_table_add.h
        symbol_table.cpp symbol_table.h
        symbol_table_mul.cpp symbol_table_mul.h
)
