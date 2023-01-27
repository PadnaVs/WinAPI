#include "Shar.h"

void Shar::move(int xMove, int yMove) {
	pointMove.x = (float)xMove;
	pointMove.y = (float)yMove;
	
	//if(!vectorNaprav.x and !vectorNaprav.y)
	   vectorNaprav = (pointMove - pointSrart).Normal();

	pointSrart.x += vectorNaprav.x * speed;
	pointSrart.y += vectorNaprav.y * speed;
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
	MoveToEx(hdc, pointSrart.x, pointSrart.y, &pt);
	LineTo(hdc, (vectorNaprav.x*r + pointSrart.x), (vectorNaprav.y*r+pointSrart.y));
};

void Shar::show(HDC& hdc) {
	Ellipse(hdc, pointSrart.x - r, pointSrart.y - r, pointSrart.x + r, pointSrart.y + r);
	showArrowNp(hdc);
};