#pragma once
#include <string>
#include "Figure.h"

namespace Figure {
    class Triangle : public Figure {
    protected:
        int a, b, c;
        int A, B, C;
        std::string name;
    public:
        FIGURE_API void print_info();
        FIGURE_API Triangle(int a, int b, int c, int A, int B, int C);
    };
}