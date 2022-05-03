cmake_minimum_required(VERSION 3.21)
project(date_formatter_challenge)

find_package(GTest REQUIRED)
include(GoogleTest)

add_subdirectory("tests")

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp src/Utils.cpp)

set(COMPILE_FLAGS_CUSTOM -Weverything -Wall -Wextra -Wpedantic -std=c++17 -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-newline-eof -Wno-padded -Wno-exit-time-destructors -Wno-global-constructors -Wno-constant-conversion)
target_compile_options(${PROJECT_NAME} INTERFACE ${COMPILE_FLAGS_CUSTOM})
