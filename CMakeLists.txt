cmake_minimum_required(VERSION 3.14)
include_directories(.)

add_subdirectory(BrezenhamLib)

find_package(OpenCV REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(BrezenhamTest BrezenhamTest.cpp)

target_link_libraries(BrezenhamTest PRIVATE opencv_core opencv_highgui BrezenhamLib nlohmann_json::nlohmann_json)
