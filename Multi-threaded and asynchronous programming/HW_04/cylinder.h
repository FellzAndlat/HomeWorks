#pragma once
#include "circle.h"

class Cylinder : public Circle {
private:
	double height;
public:
	Cylinder(int _x1, int _y1, double R, double H);
	double get_square();
	double get_volume();
};