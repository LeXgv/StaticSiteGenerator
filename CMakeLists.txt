cmake_minimum_required(VERSION 2.8)	
project(hello_world)
set(SOURCE_DIR src)
set(TEST_DIR tests)

if(${TEST_BUILD})
	set(MAIN_F ${TEST_DIR}/test_main.cpp)
else()
	set(MAIN_F ${SOURCE_DIR}/main.cpp)
endif()	

add_executable(prog ${MAIN_F}) 
