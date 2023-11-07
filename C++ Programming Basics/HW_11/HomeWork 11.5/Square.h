#pragma once
#include <string>
#include "Rhombus.h"

namespace Figure {
    class Square : public Rhombus {
    public:
        Square(int a, int b, int c, int d, int A, int B, int C, int D);
    };
}