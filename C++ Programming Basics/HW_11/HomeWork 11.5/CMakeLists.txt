cmake_minimum_required(VERSION 3.22.0)
project(HomeWork)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(CreationErrorLib SHARED CreationError.h CreationError.cpp)
add_library(FigureLib SHARED Figure.h Figure.cpp Equilateral_triangle.h Equilateral_triangle.cpp Isosceles_triangle.h Isosceles_triangle.cpp Parallelogram.h Parallelogram.cpp Quadrilateral.h Quadrilateral.cpp Rectangl.h Rectangl.cpp Rhombus.h Rhombus.cpp Right_triangle.h Right_triangle.cpp Square.h Square.cpp Triangle.h Triangle.cpp)
target_link_libraries(FigureLib CreationErrorLib)
add_executable(HomeWork_11_5 HomeWork_11_5.cpp)
target_link_libraries(HomeWork_11_5 FigureLib CreationErrorLib)