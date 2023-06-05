@echo off
IF %COMPILER%==msvc2019 (
    @echo on
    CALL "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
    mkdir build
    cd build
    cmake ..
    msbuild -verbosity:minimal -m:8 unit_tests\unit_tests.vcxproj
    cd ..
)
IF %COMPILER%==msys2 (
    @echo on
    SET "PATH=C:\msys64\mingw64\bin;%PATH%"
    cd %APPVEYOR_BUILD_FOLDER%
    mkdir build
    cd build
    bash -lc "cmake .. -GNinja && ninja unit_tests"
    cd ..
)
