#pragma once
#include <string>
#include "Triangle.h"

namespace Figure {
    class Isosceles_triangle :public Triangle {
    public:
        FIGURE_API Isosceles_triangle(int a, int b, int c, int A, int B, int C);
    };
}