#pragma once
#include "shape.h"

class Sqr : public Shape {
public:
	Sqr(int _type, int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
	virtual double get_square();
};