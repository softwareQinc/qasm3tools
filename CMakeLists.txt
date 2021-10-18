cmake_minimum_required(VERSION 3.12)
project(qasmtools VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

#### Headers
add_library(libqasmtools INTERFACE)
target_include_directories(libqasmtools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)

#### Unit testing
add_subdirectory(${CMAKE_SOURCE_DIR}/unit_tests/)
