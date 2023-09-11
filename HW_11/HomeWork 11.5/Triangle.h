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
        void print_info();
        Triangle(int a, int b, int c, int A, int B, int C);
    };
}