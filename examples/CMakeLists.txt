# List of examples
list(APPEND test_files
    test_commands.cpp
    test_replies.cpp
)

# Compile each example
foreach(filename ${test_files})
    get_filename_component(target_name ${filename} NAME_WE)
    add_executable(${target_name} ${filename})
    target_link_libraries(${target_name} PRIVATE sea_scan_echo_driver)
    target_include_directories(${target_name} PUBLIC include)
endforeach()