#include "Figure.h"
#include <iostream>
void Figure::print_info() {
    std::cout << name << '\n';
    if (check() == 1) {
        std::cout << "Правильная" << '\n';
    }
    else {
        std::cout << "Неправильная" << '\n';
    }
    std::cout << "Колчество сторон: " << size << '\n';
    std::cout << '\n';
}
bool Figure::check() {
    bool x = 0;
    if (size == 0) {
        x = 1;
        return x;
    }
    return x;
}
Figure::Figure() {
    name = "Фигура: ";
    size = 0;
}