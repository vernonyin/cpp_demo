# cmake -Dfile=filename
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-g ")
project(test)
message( WARNING "input...." ${file})
#C++ 11支持
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x ")
add_executable(hello reverse.cpp)
#添加链接库
TARGET_LINK_LIBRARIES(hello pthread) 
