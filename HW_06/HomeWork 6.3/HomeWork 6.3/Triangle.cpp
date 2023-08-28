#include <iostream>
#include "Triangle.h"
void Triangle::print_info () {
    std::cout << name << '\n';
    if (check() == 1) {
        std::cout << "����������" << '\n';
    }
    else {
        std::cout << "������������" << '\n';
    }
    std::cout << "��������� ������: " << size << '\n';
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << '\n';
    std::cout << "����: A=" << A << " B=" << B << " C=" << C << '\n';
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
    name = "�����������: ";
    size = 3;
}