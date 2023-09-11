#pragma once
#include <string>
#include "Parallelogram.h"

namespace Figure {
    class Rhombus : public Parallelogram {
    public:
        FIGURE_API Rhombus(int a, int b, int c, int d, int A, int B, int C, int D);
    };
}