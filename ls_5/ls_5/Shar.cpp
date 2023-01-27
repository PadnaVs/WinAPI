#define _USE_MATH_DEFINES
#include "Shar.h"

void Shar::move(int xMove, int yMove) {
	pointMove.x = (float)xMove;
	pointMove.y = (float)yMove;

	vectorNaprav = (pointMove - pointSrart).Normal();
	vectorNaprav.getLenght();

	pointSrart += vectorNaprav * speed;
};

void Shar::changeDir() {
	vectorNaprav.x = 0;
	vectorNaprav.y = 0;
};

void Shar::setCoordsStart(int ix, int iy) {
	pointSrart.x = ix;
	pointSrart.y = iy;
};

void Shar::showArrowNp(HDC& hdc) {
	POINT pt;
	
	float xEM = vectorNaprav.x * r + pointSrart.x;
	float yEM = vectorNaprav.y * r + pointSrart.y;

	MoveToEx(hdc, pointSrart.x, pointSrart.y, &pt);
	LineTo(hdc, (xEM), (yEM));

	Vector2D lLine(20, 0);
	lLine.rotation(-90);
};

void Shar::show(HDC& hdc) {
	Ellipse(hdc, pointSrart.x - r, pointSrart.y - r, pointSrart.x + r, pointSrart.y + r);
	showArrowNp(hdc);
};