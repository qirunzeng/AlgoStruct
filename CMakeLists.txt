cmake_minimum_required(VERSION 3.16)
project(structure)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)
