cmake_minimum_required(VERSION 3.22)
project(Matrix)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set (SOURCES sources/main.cpp sources/matrix.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})