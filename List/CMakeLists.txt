cmake_minimum_required (VERSION 2.6)
project (List CXX)
#add_executable(testClass testClass.cpp testMain.cpp)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wshadow -std=c++11")
add_executable(List main.cpp List.h List.cpp)