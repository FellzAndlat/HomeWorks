#pragma once
#include <string>
#include "CreationError.h"

namespace Figure {
    class Figure {
    protected:
        std::string name;
        int size;
    public:
        virtual void print_info();
        Figure(int size);
    };
}