#include "Figure.h"
#include <iostream>

namespace Figure {
    void Figure::print_info() {
        std::cout << name << '\n';
        std::cout << "Колчество сторон: " << size << '\n';
        std::cout << '\n';
    }
    Figure::Figure(int size) {
        if (size != 0) {
            throw error::Creation_error("Ошибка создания фигуры. Причина: у фигуры более или менее 0 сторон");
        }
        else {
            name = "Фигура: ";
            this->size = size;
        }
    }
}