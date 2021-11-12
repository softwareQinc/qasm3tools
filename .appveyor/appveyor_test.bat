@echo off
IF %COMPILER%==msvc2019 (
    cd build
    ctest
    cd ..
)
IF %COMPILER%==msys2 (
    cd build
    ctest
    cd ..
)
