# cmake -Dfile=filename
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-g ")
project(test)
message( WARNING "input...." ${file})
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x ")
add_executable(hello ${file})
