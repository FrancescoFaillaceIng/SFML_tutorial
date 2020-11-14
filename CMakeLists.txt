cmake_minimum_required(VERSION 3.17)
project(SFML_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_tutorial main.cpp)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(SFML_tutorial sfml-graphics sfml-window sfml-system)