cmake_minimum_required(VERSION 3.0.2)
project(Sea_Scan_Echo_Marine_Sonic_Driver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SEA_SCAN_ECHO_DRIVER_HEADERS include)

add_library(sea_scan_echo_driver src/Command.cpp src/Reply.cpp)
target_include_directories(sea_scan_echo_driver PUBLIC ${SEA_SCAN_ECHO_DRIVER_HEADERS})


# Detecting if project is included into another
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(MY_PROJECT_BUILD_EXAMPLES   "whether or not examples should be built" ON)

    if(MY_PROJECT_BUILD_EXAMPLES)
        add_subdirectory(examples)
    endif()
endif()