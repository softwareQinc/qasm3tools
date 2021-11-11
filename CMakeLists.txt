cmake_minimum_required(VERSION 3.12)
project(qasmtools VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()


#### antlr4cpp library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_runtime)
set_target_properties(antlr4_shared PROPERTIES EXCLUDE_FROM_ALL True)
# antlr4cpp headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_runtime/runtime/src)


#### Headers
add_library(libqasmtools INTERFACE)
target_include_directories(libqasmtools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_generated/>)
target_include_directories(libqasmtools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)
target_link_libraries(libqasmtools INTERFACE antlr4_static)

#### parser executable
set(PARSER "parser")
add_executable(${PARSER} parser.cpp)
target_link_libraries(${PARSER} PUBLIC libqasmtools)

#### Unit testing
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/)
