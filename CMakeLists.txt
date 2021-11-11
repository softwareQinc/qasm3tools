cmake_minimum_required(VERSION 3.12)
project(qasmtools VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()


#### antlr4cpp library
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})


#### Headers
add_library(libqasmtools INTERFACE)
target_link_libraries(libqasmtools INTERFACE antlr4_static)
target_include_directories(libqasmtools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)
target_include_directories(libqasmtools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_generated/>)

#### parser executable
set(PARSER "parser")
add_executable(${PARSER} parser.cpp)
target_link_libraries(${PARSER} PUBLIC libqasmtools)

#### Unit testing
add_subdirectory(${CMAKE_SOURCE_DIR}/unit_tests/)
