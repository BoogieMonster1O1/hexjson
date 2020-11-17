cmake_minimum_required(VERSION 3.17)
project(hexjson)

set(CMAKE_CXX_STANDARD 20)

add_library(hexjson SHARED src/library.cpp src/library.h)
