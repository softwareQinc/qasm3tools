cmake_minimum_required(VERSION 3.12)
project(qasm3_interpreter)
set(CMAKE_CXX_STANDARD 17)

# Disable spurious Eigen warnings with MSVC (warning STL4007)
if (MSVC)
    add_compile_definitions(_SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING)
endif ()

# The line below is optional (uncomment if Quantum++ was installed in a
# non-standard location)

# set(CMAKE_PREFIX_PATH "/path/to/installed/qpp")

find_package(qpp REQUIRED)

set(INTERPRETER "interpreter")
add_executable(${INTERPRETER} interpreter.cpp)
target_link_libraries(${INTERPRETER} PUBLIC ${QPP_LINK_DEPS} libqpp libqasm3tools)
