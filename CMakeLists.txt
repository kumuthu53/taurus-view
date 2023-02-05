cmake_minimum_required(VERSION 3.20)

project(taurus-view)

set(CMAKE_CXX_STANDARD 23)

add_executable(taurus-view src/main.cpp src/screens.cpp include/screens.h src/terminalFunctions.cpp include/terminalFunctions.h src/models/input/DataInput.cpp include/DataInput.h src/models/input/ConvertInput.cpp include/ConvertInput.h)