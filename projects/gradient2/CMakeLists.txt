cmake_minimum_required(VERSION 3.0)

project(gradient2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(gradient2 gradient2.cpp)
target_link_libraries(gradient2 ${OpenCV_LIBS})