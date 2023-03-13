#include "triangle.h"

void Triangle::setCentre() {
	for (int i = 0; i < 3; i++) {
		fX += points[i].x;
		fY += points[i].y;
	};

	fX /= 3;
	fY /= 3;
};

void Triangle::show(HDC& hdc) {
	MoveToEx(hdc, points[0].x, points[0].y, NULL);
	LineTo(hdc, points[1].x, points[1].y);
	MoveToEx(hdc, points[1].x, points[1].y, NULL);
	LineTo(hdc, points[2].x, points[2].y);
	MoveToEx(hdc, points[2].x, points[2].y, NULL);
	LineTo(hdc, points[0].x, points[0].y);

	MoveToEx(hdc, fX, fY, NULL);
	LineTo(hdc, fX, fY);
};