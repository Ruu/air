# Google Mock and Test libraries
set(GMOCK_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/gmock-1.7.0)

# Set includes global variable
set(AIR_3RD_PARTY_TDD_INCLUDE_DIRECTORIES 
	${GMOCK_DIRECTORY}/include 
	${GMOCK_DIRECTORY}/gtest/include
	PARENT_SCOPE
)

# Set libraries global variable 
set(AIR_3RD_PARTY_TDD_LIBRARIES
	gmock 
	gmock_main 
	gtest 
	gtest_main
	PARENT_SCOPE
)

add_subdirectory(${GMOCK_DIRECTORY})
