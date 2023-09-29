cmake_minimum_required(VERSION 3.24)
project(hanoy_tower)

set(CMAKE_CXX_STANDARD 17)

add_executable(hanoy_tower main.cpp Line.cpp Line.h Position.cpp Position.h main.h)
