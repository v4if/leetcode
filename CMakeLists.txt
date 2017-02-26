
project(leetcode)

#TODO: Make two seperate builds? One without code coverage

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")

include_directories(src)

add_subdirectory(src)
add_subdirectory(gtest)
