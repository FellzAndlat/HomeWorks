#pragma once
#include <string>
#include "Quadrilateral.h"

namespace Figure {
    class Rectangl : public Quadrilateral {
    public:
        FIGURE_API Rectangl(int a, int b, int c, int d, int A, int B, int C, int D);
    };
}