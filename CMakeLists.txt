cmake_minimum_required(VERSION 3.21)
project(NumberToWordR LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

# CMakeLists.txt Reference: https://stackoverflow.com/questions/21163188/most-simple-but-complete-cmake-example

#file(GLOB_RECURSE sources ./*.h ./*.c ./*.cpp)
file(GLOB sources ./*.h ./*.c ./*.cpp)
#file(sources *.h *.c *.cpp)
#file(GLOB_RECURSE sources_test src/test/*.cpp)
#file(GLOB_RECURSE data resources/*)

add_executable(NumberToWordR ${sources})
#add_executable(NumberToWordR NumberToWordR.c Main.cpp)

# this lets me include files relative to the root source directory with a <> pair
#target_include_directories(NumberToWordR PRIVATE .)
#target_link_libraries(NumberToWordR .)


#target_compile_options(NumberToWordR PUBLIC -Wall)




