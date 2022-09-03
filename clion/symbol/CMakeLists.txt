cmake_minimum_required(VERSION 3.23)
project(symbol)
set(CMAKE_CXX_STANDARD 17)
add_executable(symbol main.cpp parse.h parse.c symbol.cpp symbol.h symbol_list.cpp symbol_list.h symbol_table_add.cpp symbol_table_add.h)
