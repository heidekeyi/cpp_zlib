cmake_minimum_required(VERSION 3.23)
project(container)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -g -O0")

add_executable(container main.cpp container.h vector.cpp vector.h vector_container.h list_container.h list_container.cpp)
