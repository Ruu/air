include_directories(${AIR_INCLUDE_DIRECTORIES})

add_executable("example-01" "example-01.cpp")
target_link_libraries("example-01" ${AIR_LIBRARIES})

add_executable("example-02" "example-02.cpp")
target_link_libraries("example-02" ${AIR_LIBRARIES})
