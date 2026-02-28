cmake_minimum_required(VERSION 4.2)
project(DataStructures)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(main ${SOURCES})
