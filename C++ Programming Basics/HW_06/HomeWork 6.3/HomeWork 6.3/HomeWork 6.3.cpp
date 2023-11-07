#include <iostream>
#include <cstring>
#include <Windows.h>
#include <vector>
#include "Figure.h"
#include "Triangle.h"
#include "Right_triangle.h"
#include "Isosceles_triangle.h"
#include "Equilateral_triangle.h"
#include "Quadrilateral.h"
#include "Parallelogram.h"
#include "Rectangl.h"
#include "Rhombus.h"
#include "Square.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Figure*> all_figure;

    all_figure.push_back(new Figure());
    all_figure.push_back(new Triangle(10, 20, 30, 50, 60, 70));
    all_figure.push_back(new Right_triangle(10, 20, 30, 50, 60));
    all_figure.push_back(new Right_triangle(10, 20, 30, 50, 40));
    all_figure.push_back(new Isosceles_triangle(10, 20, 50, 60));
    all_figure.push_back(new Equilateral_triangle(30, 60));
    all_figure.push_back(new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80));
    all_figure.push_back(new Rectangl(10, 20));
    all_figure.push_back(new Square(20));
    all_figure.push_back(new Parallelogram(20, 30, 30, 40));
    all_figure.push_back(new Rhombus(30, 30, 40));

    for (int i = 0; i < all_figure.size(); ++i) {
        all_figure[i]->print_info();
    }


    return 0;
}