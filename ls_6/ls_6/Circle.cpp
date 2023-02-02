#include "Circle.h"

void Circle::show(HDC& hdc) {
	Ellipse(hdc, pointStart.x-r,pointStart.y-r, pointStart.x+r, pointStart.y+r);
};