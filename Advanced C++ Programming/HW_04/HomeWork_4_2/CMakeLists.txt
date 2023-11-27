cmake_minimum_required(VERSION 3.20)
project(HomeWork_4_1)

add_subdirectory(../Catch2 Catch2-build)
add_executable(HomeWorkTest Test_main.cpp)
target_link_libraries(HomeWorkTest PRIVATE Catch2::Catch2)