#pragma once
#include "shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	Circle(int _x1, int _y1, double R);
	virtual double get_square();
};