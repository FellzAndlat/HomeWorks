#define _USE_MATH_DEFINES
#include "cube.h"

Cube::Cube(int _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8) {
						z1 = _z1;
						z2 = _z2; 
						z3 = _z3;
						z4 = _z4;
	x5 = _x5; y5 = _y5; z5 = _z5;
	x6 = _x6; y6 = _y6; z6 = _z6;
	x7 = _x7; y7 = _y7; z7 = _z7;
	x8 = _x8; y8 = _y8; z8 = _z8;
}
Cube::get_square() {
	return 2 * abs(x1 - x2) * abs(y1 - y2) + 2 * abs(x1 - x2) * abs(z1 - z2) + 2 * abs(y1 - y2) * abs(z1 - z2);
}
Cube::get_volume() {
	return abs(x1 - x2) * abs(y1 - y2) * abs(z1 - z2);
}