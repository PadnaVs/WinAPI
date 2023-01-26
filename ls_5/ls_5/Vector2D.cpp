#include "Vector2D.h"

float Vector2D::getLenght() {
	lenght = sqrt(x*x + y*y);
	return lenght;
};

void Vector2D::show(HDC& hdc) {
	POINT pt;
	MoveToEx(hdc, 0, 0, &pt);
	LineTo(hdc, x, y);
};

Vector2D Vector2D::operator-(Vector2D v) {
	Vector2D res((x-v.x), (y-v.x));
	return res;
};