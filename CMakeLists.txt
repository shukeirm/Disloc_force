cmake_minimum_required(VERSION 2.8)
 
project(MalikSuperStar)
 
# source files
file( GLOB_RECURSE source_files *.C)
 
# C++ compiler flags (si tu veux faire du C++11 – sinon tu peux enlever ces deux lignes)
# SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
# message(STATUS "flags are :" ${CMAKE_CXX_FLAGS})
 
# executable path and name
SET( EXECUTABLE_OUTPUT_PATH )
add_executable ( force.exe ${source_files} )
