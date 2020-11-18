enable_testing()

cmake_minimum_required(VERSION 3.16)
project(hexjson)

set(CMAKE_CXX_STANDARD 20)

add_library(hexjson SHARED
        src/flags.c
        src/element.h
        src/json_str.cpp
        src/json_number.cpp
        src/json_bool.cpp
        src/json_null.cpp
        src/hexjson.h
        src/json_array.cpp
        src/json_object.cpp
        src/token_o.c
        src/token_c.c
        src/sutils.h
        src/deserializer.cpp)

add_executable(main_test test/test.cpp)
target_link_libraries(main_test hexjson)
add_test(main_test main_test)
