#include "Shar.h"


void Shar::move(int xMove, int yMove) {
	pointMove.x = xMove;
	pointMove.y = yMove;
	vectorNaprav = pointMove - pointSrart;
	vectorNaprav.x += 0;
	vectorNaprav.y += 0;
	//Vector2D naprMove(((pointMove.x-pointSrart.x)/pointMove.getLenght()  / abs( (pointMove.y - pointSrart.y) / pointMove.getLenght())),
	//	              (pointMove.y - pointSrart.y)/pointMove.getLenght() / abs(((pointMove.y - pointSrart.y) / pointMove.getLenght()));
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
	LineTo(hdc, vectorNaprav.x+ pointSrart.x, vectorNaprav.y+ pointSrart.y);
};

void Shar::show(HDC& hdc) {
	Ellipse(hdc, pointSrart.x - r, pointSrart.y - r, pointSrart.x + r, pointSrart.y + r);
	
	pointSrart.show(hdc);
	//vectorNaprav.show(hdc);
	showArrowNp(hdc);
};