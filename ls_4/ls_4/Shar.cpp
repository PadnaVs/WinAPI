#define _USE_MATH_DEFINES
#include "Shar.h"

#pragma once
//#include "Vector2D.h"
#include "framework.h"

void Shar::move(int xMove, int yMove) {
	//if (abs(x-xMove) < 15 && abs(y-yMove) < 15) {
	//	x = xMove;
	//	y = yMove;
	//	as = 0;
	//	//return;
	//};
	
	Vector2D vectorNMove = Vector2D(x, y, xMove, yMove);
	as = vectorNMove.getAngle();//угол вектора направления
	

	if (vectorN.yS > vectorN.yE) {
		as += 360;
	};
	
	int xP = x + cos((as)* M_PI / 180) * speed;
	int yP = y + sin((as)* M_PI / 180) * speed;

	vectorN.setCoords(x, y, xP, yP);

	Vector2D stepMove = vectorN;
	
	xP = x + cos((as)*M_PI / 180) * (r-35);
	yP = y + sin((as)*M_PI / 180) * (r-35);
	showVector.setCoords(x,y, xP, yP);

	x = stepMove.xE;
	y = stepMove.yE;
};

void Shar::show(HDC* hdc) {
	Ellipse(*hdc, x-r/2, y-r/2, x+r/2, y+r/2);
	showVector.show(hdc);
};