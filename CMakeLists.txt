cmake_minimum_required(VERSION 3.17)
project(hexjson)

set(CMAKE_CXX_STANDARD 20)

add_library(hexjson SHARED
        src/types.c
        src/json_element.cpp
        src/json_int.cpp
        src/json_double.cpp
        src/json_bool.cpp
        src/json_null.cpp src/hexjson.h src/json_array.cpp src/json_object.cpp src/scopes.c src/peeked_token.c)
