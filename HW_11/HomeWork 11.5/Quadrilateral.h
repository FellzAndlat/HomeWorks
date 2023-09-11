#pragma once
#include <string>
#include "Figure.h"

namespace Figure {
    class Quadrilateral :public Figure {
    protected:
        int a, b, c, d;
        int A, B, C, D;
        std::string name;
    public:
        void print_info();

        Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    };
}