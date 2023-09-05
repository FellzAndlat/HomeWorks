#include "Quadrilateral.h"
#include <iostream>

void Quadrilateral::print_info() {
    std::cout << name << '\n';
    std::cout << "��������� ������: " << size << '\n';
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
    std::cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << '\n';
    std::cout << '\n';
}
Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(0) {
    if (A + B + C + D != 360) {
        throw Creation_error("������ �������� ������. �������: ����� ����� �� ����� 360");
    }
    else {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        size = 4;
        name = "��������������:";
    }

}