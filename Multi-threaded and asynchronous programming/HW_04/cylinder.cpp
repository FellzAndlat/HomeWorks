#define _USE_MATH_DEFINES
#include"cylinder.h"
#include<cmath>

Circle::Circle(int _x1, int _y1, double R) {
	x1 = _x1; y1 = _y1;
	radius = R;
	height = H;
}
Cylinder::get_square() {
	return M_PI * radius * radius + 2 * radius * height;
}
Cylinder::get_volume() {
	return M_PI * radius * radius * height;
}