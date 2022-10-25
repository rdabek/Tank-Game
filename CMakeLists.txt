cmake_minimum_required(VERSION 3.13)

IF (WIN32)
    set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
ELSE()
    # Do Nothing, linux is smarter...
ENDIF()

project(UE02 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tankgame)