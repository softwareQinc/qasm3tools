cmake_minimum_required(VERSION 3.15)
project(qasm3tools VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

#### Windows issues with Microsoft Visual Studio
if (MSVC)
    # Disable spurious warnings with MSVC (warning C4996)
    add_compile_definitions(_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
    add_compile_options(-bigobj)
    add_compile_definitions(NOMINMAX)
endif ()

#### qasm3tools root directory
add_compile_definitions(PROJECT_ROOT_DIR="${PROJECT_SOURCE_DIR}")

#### antlr4cpp library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_runtime EXCLUDE_FROM_ALL)
# antlr4cpp headers
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_runtime/runtime/src)

#### Libs
include_directories(SYSTEM libs)

#### Headers
add_library(libqasm3tools INTERFACE)
target_include_directories(libqasm3tools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/antlr4cpp_generated/>)
target_include_directories(libqasm3tools INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)
target_link_libraries(libqasm3tools INTERFACE antlr4_static)

#### parser executable
set(PARSER "parser")
add_executable(${PARSER} src/parser.cpp)
target_link_libraries(${PARSER} PUBLIC libqasm3tools)

#### interpreter
option(WITH_INTERPRETER "Build interpreter. Must have Quantum++ installed" OFF)
if (${WITH_INTERPRETER})
    include(cmake/interpreter.cmake)
endif ()

#### Unit testing
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/)
