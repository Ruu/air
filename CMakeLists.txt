cmake_minimum_required(VERSION 2.8)
project(airlog)

# Global variables
set(AIR_LIBRARIES)
set(AIR_INCLUDE_DIRECTORIES)

set(AIR_3RD_PARTY_TDD_LIBRARIES)
set(AIR_3RD_PARTY_TDD_INCLUDE_DIRECTORIES)

# Compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

# Subdirectories
add_subdirectory("3rd_party")
add_subdirectory("include")
add_subdirectory("src")
add_subdirectory("tests")
add_subdirectory("examples")

# Enable tests
enable_testing()
