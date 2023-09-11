#pragma once
#include <string>
#include "Quadrilateral.h"

namespace Figure {
    class Parallelogram : public Quadrilateral {
    public:
        Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D);
    };
}