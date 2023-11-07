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
#include "CreationError.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Figure::Figure*> all_figure;

    try {
        all_figure.push_back(new Figure::Figure(1));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Triangle(10, 20, 30, 50, 60, 70));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Right_triangle(10, 20, 30, 20, 80, 80));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Right_triangle(10, 20, 30, 50, 40, 90));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Isosceles_triangle(10, 20, 10, 50, 80, 50));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Equilateral_triangle(10, 10, 10, 60, 60, 60));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Parallelogram(20, 30, 20, 30, 30, 150, 30, 150));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Rectangl(10, 20, 10, 20, 90, 90, 100, 80));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Rhombus(30, 30, 30, 30, 100, 80, 100, 80));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }
    try {
        all_figure.push_back(new Figure::Square(20, 20, 20, 20, 90, 90, 90, 90));
        all_figure[all_figure.size() - 1]->print_info();
    }
    catch (error::Creation_error& Figure) {
        std::cout << Figure.get_error() << '\n' << '\n';
    }

    for (int i = 0; i < all_figure.size(); ++i) {
        delete all_figure[i];
    }


    return 0;
}