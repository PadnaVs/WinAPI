#define _USE_MATH_DEFINES
#include "Figure.h"
#include "framework.h"


void Figure::show(HDC& hdc) {
	showArrowNp(hdc);
};

void Figure::move(Vector2D &naprav) {
	pointMove = naprav;

	if(vectorNaprav.x == 0 and vectorNaprav.y == 0)
		vectorNaprav = (pointMove - pointStart).Normal();
	vectorNaprav.getLenght();

	pointStart += vectorNaprav * speed;
    reMove(naprav);
};

void Figure::reMove(Vector2D& naprav) {
	int wWindow = 958;
	int hWindow = 988;
	if(wWindow || hWindow) {
		if (pointStart.x+r > wWindow)
		{
			pointStart.x = wWindow-r;
			vectorNaprav.x *= -1;
		}
		if (pointStart.x-r < 0)
		{
			pointStart.x = r;
			vectorNaprav.x *= -1;
		}
		if (pointStart.y+r > hWindow)
		{
			pointStart.y = hWindow-r;
			vectorNaprav.y *= -1;
		}
		if (pointStart.y-r < 0)
		{
			pointStart.y = r;
			vectorNaprav.y *= -1;
		}
	};
};

void Figure::changeDir() {
	vectorNaprav.x = 0;
	vectorNaprav.y = 0;
};

void Figure::setCoordsStart(int ix, int iy) {
	pointStart.x = ix;
	pointStart.y = iy;
};

void Figure::showArrowNp(HDC& hdc) {
	POINT pt;
	
	float xEM = vectorNaprav.x * r + pointStart.x;
	float yEM = vectorNaprav.y * r + pointStart.y;

	MoveToEx(hdc, pointStart.x, pointStart.y, &pt);
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
