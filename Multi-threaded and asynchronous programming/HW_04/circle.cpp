#define _USE_MATH_DEFINES
#include "circle.h"

Circle::Circle(int type, int _x1, int _y1, double R) {
	x1 = _x1; y1 = _y1;
	radius = R;
}
Circle::get_square() {
	return M_PI * radius * radius;
}