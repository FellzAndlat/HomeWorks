#include "Right_triangle.h"

namespace Figure {
    Right_triangle::Right_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
        if (C != 90) {
            throw error::Creation_error("Ошибка создания фигуры. Причина: Один из углов должен быть равен 90");
        }
        else {
            name = "Прямоугольный треугольник: ";
        }
    }
}