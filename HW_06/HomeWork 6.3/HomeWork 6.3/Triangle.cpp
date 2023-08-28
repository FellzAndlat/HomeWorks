#include <iostream>
#include "Triangle.h"
void Triangle::print_info () {
    std::cout << name << '\n';
    if (check() == 1) {
        std::cout << "Правильная" << '\n';
    }
    else {
        std::cout << "Неправильная" << '\n';
    }
    std::cout << "Колчество сторон: " << size << '\n';
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
    std::cout << '\n';
}
bool Triangle::check () {
    bool x = 0;
    if (size == 3 && A + B + C == 180) {
        x = 1;
        return x;
    }
    return x;
}
Triangle::Triangle(int a, int b, int c, int A, int B, int C): Figure () {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    name = "Треугольник: ";
    size = 3;
}