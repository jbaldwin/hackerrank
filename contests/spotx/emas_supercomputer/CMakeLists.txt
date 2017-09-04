cmake_minimum_required(VERSION 3.6)
project(emas_supercomputer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")
set(CMAKE_BUILD_TYPE Release)

set(SOURCE_FILES
        src/main.cpp
)

add_executable(emas_supercomputer ${SOURCE_FILES})
