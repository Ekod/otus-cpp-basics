cmake_minimum_required(VERSION 3.24)
project(hw_8)

add_executable(hw_8 main.cpp)

set(hw_8 PUBLIC CMAKE_CXX_STANDARD 17)
set_target_properties(hw_8 PROPERTIES CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(hw_8 PRIVATE
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
            )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(hw_8 PRIVATE
            /W4
            /WX
            )
endif ()

