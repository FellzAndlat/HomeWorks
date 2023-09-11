#include "Isosceles_triangle.h"

namespace Figure {
    Isosceles_triangle::Isosceles_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        if (A != C || a != c) {
            throw error::Creation_error("Ошибка создания фигуры. Причина: Стороны по парно не равны");
        }
        else {
            this->C = A;
            name = "Равнобедренный треугольник: ";
        }
    }
}