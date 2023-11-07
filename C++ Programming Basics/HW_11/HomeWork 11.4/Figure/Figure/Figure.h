#pragma once
#ifdef FIGURE_EXPORTS
#define FIGURE_API __declspec(dllexport)
#else
#define FIGURE_API __declspec(dllimport)
#endif
#include <string>
#include "CreationError.h"

namespace Figure {
    class Figure {
    protected:
        std::string name;
        int size;
    public:
        FIGURE_API virtual void print_info();
        FIGURE_API Figure(int size);
    };
}