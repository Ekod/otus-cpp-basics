cmake_minimum_required(VERSION 3.5)

project(05.homework)

add_executable(
        calculation

        src/main.cpp
)
set_target_properties(calculation PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_include_directories(calculation PRIVATE headers)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
            calculation

            PRIVATE
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(
            calculation

            PRIVATE
            /EHsc
            /W4
            /WX
    )
endif ()