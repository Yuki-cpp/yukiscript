cmake_minimum_required(VERSION 2.6)
project(math)


set(CMAKE_CXX_COMPILER /usr/bin/g++-7)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")

add_subdirectory(src)
