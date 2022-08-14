cmake_minimum_required(VERSION 3.23)
project(rand)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -g -O0")
add_executable(rand main.cpp rand.cpp rand.h practise.cpp practise.h)
