cmake_minimum_required(VERSION 3.20)

project(taurus-view)

set(CMAKE_CXX_STANDARD 23)

add_executable(taurus-view src/main.cpp src/screens.cpp include/screens.h src/terminalFunctions.cpp include/terminalFunctions.h src/models/input/DataInput.cpp include/DataInput.h src/models/input/ConvertInput.cpp include/ConvertInput.h src/classes/Currencies.cpp include/Currencies.h src/classes/Currency.cpp include/Currency.h src/classes/AlphaVantageAPI.cpp include/AlphaVantageAPI.h src/models/output/ConvertOutput.cpp include/ConvertOutput.h src/models/output/DataOutput.cpp include/DataOutput.h src/processing.cpp include/processing.h src/minorFunctions.cpp include/minorFunctions.h)