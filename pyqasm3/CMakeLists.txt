cmake_minimum_required(VERSION 3.12)
project(pyqasm3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(qpp REQUIRED)

# antlr4cpp library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../antlr4cpp_runtime
                 ${CMAKE_CURRENT_SOURCE_DIR}/../dist EXCLUDE_FROM_ALL)
