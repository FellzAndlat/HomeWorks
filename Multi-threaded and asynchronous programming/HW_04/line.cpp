#define _USE_MATH_DEFINES
#include "line.h"

Line::Line(int _type, int _x1, int _y1, int _x2, int _y2) {
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;

	type = _type
}