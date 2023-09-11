#include "Figure.h"
#include <iostream>
void Figure::print_info() {
    std::cout << name << '\n';
    std::cout << "��������� ������: " << size << '\n';
    std::cout << '\n';
}
Figure::Figure(int size) {
    if (size != 0) {
        throw Creation_error("������ �������� ������. �������: � ������ ����� ��� ����� 0 ������");
    }
    else {
        name = "������: ";
        this->size = size;
    }
}