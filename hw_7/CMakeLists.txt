cmake_minimum_required(VERSION 3.2)

project(07.homework)

add_subdirectory(test)

add_executable(
        testing_containers

        src/main.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
            testing_containers

            PRIVATE
            -g
            -Wall
            -Wextra
            -Werror
            -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(
            testing_containers

            PRIVATE
            /EHsc
            /W4
            /WX
    )
endif ()

target_compile_features(testing_containers PUBLIC cxx_std_17)
