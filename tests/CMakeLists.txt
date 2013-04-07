# Includes
include_directories(${AIR_INCLUDE_DIRECTORIES})
include_directories(${AIR_3RD_PARTY_TDD_INCLUDE_DIRECTORIES})

# Executable file's name for tests
set(AIR_TDD_EXECUTABLE "unit-tests")

# Add each test file automatically
file(GLOB UNIT_TEST_SOURCES "test*.cpp")
add_executable(${AIR_TDD_EXECUTABLE} ${UNIT_TEST_SOURCES})

# Link with unit test framework
target_link_libraries(${AIR_TDD_EXECUTABLE} 
	${AIR_LIBRARIES}
	${AIR_3RD_PARTY_TDD_LIBRARIES}
)

# Add test
add_test(${AIR_TDD_EXECUTABLE} ${AIR_TDD_EXECUTABLE})
