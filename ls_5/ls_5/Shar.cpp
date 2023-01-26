#include "Shar.h"


void Shar::move(int xMove, int yMove) {
	pointMove.x = xMove;
	pointMove.y = yMove;
	vectorNaprav = pointMove - pointSrart;
	vectorNaprav.x = vectorNaprav.x / vectorNaprav.getLenght() * r;// - vectorNaprav.x / vectorNaprav.getLenght();
	vectorNaprav.y = vectorNaprav.y / vectorNaprav.getLenght() * r;// - vectorNaprav.y / vectorNaprav.getLenght();
};

void Shar::setCoordsStart(int ix, int iy) {
	pointSrart.x = ix;
	pointSrart.y = iy;

	//vectorNaprav.x = ix + r;
	//vectorNaprav.y = iy;
};

void Shar::showArrowNp(HDC& hdc) {
	POINT pt;
	MoveToEx(hdc, pointSrart.x, pointSrart.y, &pt);
	LineTo(hdc, (vectorNaprav.x + pointSrart.x), (vectorNaprav.y+pointSrart.y));
};

void Shar::show(HDC& hdc) {
	Ellipse(hdc, pointSrart.x - r, pointSrart.y - r, pointSrart.x + r, pointSrart.y + r);
	
	pointSrart.show(hdc);
	vectorNaprav.show(hdc);
	showArrowNp(hdc);
};