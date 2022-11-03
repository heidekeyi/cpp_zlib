cmake_minimum_required(VERSION 3.23)
project(serial)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror -g -O0")

add_executable(serial
        main.cpp
        message.h message.cpp message_driver.h
        symbols.cpp symbols.h symbols_driver.h
        value.h value.cpp value_driver.h
        table.h table.cpp table_driver.h
        serial.h serial_driver.h
        )
