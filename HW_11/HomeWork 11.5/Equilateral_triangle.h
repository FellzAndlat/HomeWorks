#pragma once
#include <string>
#include "Isosceles_triangle.h"

namespace Figure {
    class Equilateral_triangle :public Isosceles_triangle {
    public:
        Equilateral_triangle(int a, int b, int c, int A, int B, int C);
    };
}