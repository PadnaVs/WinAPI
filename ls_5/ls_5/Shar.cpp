#define _USE_MATH_DEFINES
#include "Shar.h"

//#include "resource.h"
#include "framework.h"

void Shar::move(int xMove, int yMove) {
	pointMove.x = (float)xMove;
	pointMove.y = (float)yMove;

	vectorNaprav = (pointMove - pointSrart).Normal();
	vectorNaprav.getLenght();

	pointSrart += vectorNaprav * speed;
	//reMove(naprav);
};

/*void Shar::reMove(Vector2D& naprav) {
	int wWindow = 958;
	int hWindow = 988;
	int a = naprav.getAngle();
	if(wWindow || hWindow) {
		if (pointSrart.x > wWindow) {
			vectorNaprav.rotation(vectorNaprav.getAngle()*2);
		};	
	};
};*/

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
	lLine.rotation(vectorNaprav.getAngle() + 165);

	MoveToEx(hdc, xEM, yEM, &pt);
	LineTo(hdc, (xEM + lLine.x), (yEM+ lLine.y));

	Vector2D rLine(20, 0);
	rLine.rotation(vectorNaprav.getAngle() - 165);

	MoveToEx(hdc, xEM, yEM, &pt);
	LineTo(hdc, (xEM + rLine.x), (yEM + rLine.y));
};

void Shar::show(HDC& hdc) {
	Ellipse(hdc, pointSrart.x - r, pointSrart.y - r, pointSrart.x + r, pointSrart.y + r);
	showArrowNp(hdc);
};