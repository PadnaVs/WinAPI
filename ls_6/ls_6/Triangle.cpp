#include "Triangle.h"

void Triangle::show(HDC& hdc) {
	int x1 = pointStart.x - r;
	int y1 = pointStart.y + r;

	int x2 = pointStart.x;
	int y2 = pointStart.y + r*3;

	int x3 = pointStart.x + r*2;
	int y3 = pointStart.y + r*2;

	POINT pt;
	MoveToEx(hdc, x1, y1, &pt);
	LineTo(hdc, x2, y2);

	MoveToEx(hdc, x2, y2, &pt);
	LineTo(hdc, x3, y3);

	MoveToEx(hdc, x3, y3, &pt);
	LineTo(hdc, x1, y1);
};