cmake_minimum_required(VERSION 3.16)

project(scheduler)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE sources src/*.cpp)

add_executable(${PROJECT_NAME} ${sources})
