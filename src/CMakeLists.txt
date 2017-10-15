cmake_minimum_required (VERSION 2.6)
project (3DGame)
set (CMAKE_CXX_STANDARD 11)

include_directories("../include")
link_directories("../lib/irrlicht")

set(EXECUTABLE_OUTPUT_PATH ../bin/${CMAKE_BUILD_TYPE})

file(
	GLOB_RECURSE
	source_files
	../src/*
)

add_executable(start main.cpp)

target_link_libraries(start irrlicht)