#pragma once
#include <string>
#include "Creation_error.h"
class Figure {
protected:
    std::string name;
    int size;
public:
    virtual void print_info();
    Figure(int size);

};