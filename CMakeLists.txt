cmake_minimum_required(VERSION 3.17)
project(hexjson)

set(CMAKE_CXX_STANDARD 20)

add_library(hexjson SHARED
        src/json_type.c
        src/json_element.cpp
        src/json_int.cpp
        src/json_double.cpp
        src/json_bool.cpp
        src/json_null.cpp src/hexjson.h)
