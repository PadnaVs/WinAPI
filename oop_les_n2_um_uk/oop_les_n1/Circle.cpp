#include "Circle.h"

void Circle::show(HDC& hdc) {
	Ellipse(hdc, fX-fR, fY-fR, fX+fR, fY+fR);
};