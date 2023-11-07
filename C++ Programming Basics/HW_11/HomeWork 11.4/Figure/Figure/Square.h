#pragma once
#include <string>
#include "Rhombus.h"

namespace Figure {
    class Square : public Rhombus {
    public:
        FIGURE_API Square(int a, int b, int c, int d, int A, int B, int C, int D);
    };
}