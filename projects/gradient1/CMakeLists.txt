cmake_minimum_required(VERSION 3.0)

project(gradient1)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(gradient1 gradient1.cpp)
target_link_libraries(gradient1 ${OpenCV_LIBS})