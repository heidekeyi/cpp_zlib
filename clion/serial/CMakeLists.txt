cmake_minimum_required(VERSION 3.23)
project(serial)

set(CMAKE_CXX_STANDARD 20)

add_executable(serial
        main.cpp
        decimal.cpp decimal.h
        symbols.cpp symbols.h
        serial.cpp serial.h
        message.cpp message.h driver_symbols.h


        operand.cpp operand.h value.cpp value.h formula.cpp formula.h driver_value.h driver_formula.h driver_message.h driver_operand.h action.cpp action.h driver_action.h)
