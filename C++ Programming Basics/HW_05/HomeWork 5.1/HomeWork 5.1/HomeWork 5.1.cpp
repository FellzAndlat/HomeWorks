#include <iostream>
#include <cstring>
#include <Windows.h>


class figure {
protected:
    std::string name;
    int sides_count;
public:
    figure() {
        sides_count = 0;
        name = "Фигура:";
        std::cout << name << " " << sides_count << std::endl;
    }
    figure(int i) {
        sides_count = i;
    }
};

class triangle : public figure {
public:
    triangle() : figure(3) {
        name = "Треугольник:";
        std::cout << name << " " << sides_count << std::endl;
    }
};

class quadrangle : public figure {
public:
    quadrangle() : figure(4) {
        name = "Четырехугольник:";
        std::cout << name << " " << sides_count << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Количество сторон:" << std::endl;

    figure figure;
    triangle triangle;
    quadrangle quadrangle;

    return 0;
}