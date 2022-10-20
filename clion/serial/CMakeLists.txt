cmake_minimum_required(VERSION 3.23)
project(serial)

set(CMAKE_CXX_STANDARD 20)

add_executable(serial
        main.cpp
        decimal.cpp decimal.h
        symbols.cpp symbols.h
        serial.cpp serial.h
        message.cpp message.h driver_symbols.h


        )
