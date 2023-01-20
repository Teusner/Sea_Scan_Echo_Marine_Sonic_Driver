# List of examples
list(APPEND test_files
    test_parser.cpp
)

# Compile each example
foreach(filename ${test_files})
    get_filename_component(target_name ${filename} NAME_WE)
    add_executable(${target_name} ${filename})
    target_link_libraries(${target_name} PRIVATE nmea_parser)
    target_include_directories(${target_name} PUBLIC ${SEA_SCAN_ECHO_DRIVER_HEADERS})
endforeach()