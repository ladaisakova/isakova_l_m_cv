cmake_minimum_required(VERSION 3.0)

project(jpeg9565)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(jpeg9565 jpeg9565.cpp)
target_link_libraries(jpeg9565 ${OpenCV_LIBS})