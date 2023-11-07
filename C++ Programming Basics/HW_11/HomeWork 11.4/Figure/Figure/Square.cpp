#include "Square.h"

namespace Figure {
    Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) : Rhombus(a, b, c, d, A, B, C, D) {
        if (a != b || b != c || c != d || d != a || A != B || B != C || C != D || D != A) {
            throw error::Creation_error("Ошибка создания фигуры. Причина: Стороны или углы не равны");
        }
        else {
            name = "Квадрат: ";
        }
    }
}