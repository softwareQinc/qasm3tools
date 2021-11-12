cmake_minimum_required(VERSION 3.12)
project(qasm3tools VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

#### qasm3tools root directory
add_compile_definitions(PROJECT_ROOT_DIR="${PROJECT_SOURCE_DIR}")

#### antlr4cpp library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_runtime EXCLUDE_FROM_ALL)
# antlr4cpp headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_runtime/runtime/src)


#### Headers
add_library(libqasm3tools INTERFACE)
target_include_directories(libqasm3tools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_generated/>)
target_include_directories(libqasm3tools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)
target_link_libraries(libqasm3tools INTERFACE antlr4_static)

#### parser executable
set(PARSER "parser")
add_executable(${PARSER} parser.cpp)
target_link_libraries(${PARSER} PUBLIC libqasm3tools)

#### Unit testing
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/)
