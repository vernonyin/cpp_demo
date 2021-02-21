# cmake -Dfile=filename
cmake_minimum_required(VERSION 3.17)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-g ")
project(test)
#message( WARNING "input...." ${file})
#C++ 11支持
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ")
include_directories(./fbs)
include_directories(./liang/)
#add_executable(hello liang/main.cpp liang/FilterDirtyWord.cpp)

#add_executable(hello leetcode/sort/quick_sort.cpp)
add_executable(hello leetcode/string/string.cpp)

#leetcode/twostack.cpp
#添加链接库
TARGET_LINK_LIBRARIES(hello pthread) 
