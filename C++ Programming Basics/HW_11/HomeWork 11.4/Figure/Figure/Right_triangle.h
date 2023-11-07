#pragma once
#include <string>
#include "Triangle.h"

namespace Figure {
    class Right_triangle :public Triangle {
    public:
        FIGURE_API Right_triangle(int a, int b, int c, int A, int B, int C);
    };
}