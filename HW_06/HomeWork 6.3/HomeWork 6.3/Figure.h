#pragma once
#include <string>
class Figure {
protected:
    std::string name;
    int size;
public:
    virtual void print_info();
    virtual bool check();
    Figure();

};