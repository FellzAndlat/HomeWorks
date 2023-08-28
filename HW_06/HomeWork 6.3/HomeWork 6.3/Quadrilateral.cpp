#include "Quadrilateral.h"
#include <iostream>

void Quadrilateral::print_info() {
    std::cout << name << '\n';
    if (check() == 1) {
        std::cout << "Правильная" << '\n';
    }
    else {
        std::cout << "Неправильная" << '\n';
    }
    std::cout << "Колчество сторон: " << size << '\n';
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << '\n';
    std::cout << '\n';
}
bool Quadrilateral::check() {
    bool x = 0;
    if (size == 4 && A + B + C + D == 360) {
        x = 1;
        return x;
    }
    return x;
}
Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure() {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    size = 4;
    name = "Четырёхугольник:";
}