cmake_minimum_required(VERSION 3.22.0)
project(HomeWork)
add_library(LeaverDinamicLib SHARED Leaver.h Leaver.cpp)
add_executable(HomeWork_11_3 HomeWork_11_3.cpp)
target_link_libraries(HomeWork_11_3 LeaverDinamicLib)