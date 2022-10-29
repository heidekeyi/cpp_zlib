cmake_minimum_required(VERSION 3.23)
project(serial)

set(CMAKE_CXX_STANDARD 20)

add_executable(serial
        main.cpp
        message.h message.cpp message_driver.h
        symbols.h symbols_driver.h
        value.h value_driver.h
        serial.h
        )
