cmake_minimum_required(VERSION 3.23)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator main.cpp sequence_table.cpp sequence_table.h expression.cpp expression.h action.h accumulator.cpp accumulator.h)
