#include <iostream>
#include "Triangle.h"

namespace Figure {
    void Triangle::print_info() {
        std::cout << name << '\n';
        std::cout << "Колчество сторон: " << size << '\n';
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
        std::cout << '\n';
    }
    Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure(0) {
        if (A + B + C != 180) {
            throw error::Creation_error("Ошибка создания фигуры. Причина: сумма углов не равна 180");
        }
        else {
            this->a = a;
            this->b = b;
            this->c = c;
            this->A = A;
            this->B = B;
            this->C = C;
            name = "Треугольник: ";
            size = 3;
        }
    }
}