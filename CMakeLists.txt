#Main

cmake_minimum_required(VERSION 2.15)
project(math)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")

add_subdirectory(src)
