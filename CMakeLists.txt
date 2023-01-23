cmake_minimum_required(VERSION 3.0.2)
project(Sea_Scan_Echo_Marine_Sonic_Driver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(nmea_parser src/Command.cpp src/Reply.cpp)

set(SEA_SCAN_ECHO_DRIVER_HEADERS include)

# Detecting if project is included into another
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(MY_PROJECT_BUILD_EXAMPLES   "whether or not examples should be built" ON)

    if(MY_PROJECT_BUILD_EXAMPLES)
        add_subdirectory(examples)
    endif()
endif()