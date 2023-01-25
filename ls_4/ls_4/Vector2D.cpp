#define _USE_MATH_DEFINES
#include "Vector2D.h"
#pragma once
#include "framework.h"

void Vector2D::setCoords(int ixS, int iyS, int ixE, int iyE) {
	xS = ixS;
	yS = iyS;
	xE = ixE;
	yE = iyE;
};

int Vector2D::getAngle() {
	return (atan2((double)(yE - yS), (double)(xE - xS))) * (180 / M_PI);
};

void Vector2D::show(HDC* hdc) {
	POINT pt;
	MoveToEx(*hdc, xS, yS, &pt);
	LineTo(*hdc, xE, yE);

	float as = this->getAngle();

	int lenArr = 30;
	int a = 0;

	if (xS < xE) {
		a = as - 165;
	}
	else {
		a = 165 + as;
	}

	int xP = 0 + cos((a) * M_PI / 180) * lenArr;
	int yP = 0 + sin((a) * M_PI / 180) * lenArr;

	MoveToEx(*hdc, xE, yE, &pt);
	LineTo(*hdc, xP+xE, yP+yE);

	a = xS < xE ? 165+as : -165+as;//angle 15c
	xP = 0 + cos((a)*M_PI / 180) * lenArr;
	yP = 0 + sin((a)*M_PI / 180) * lenArr;

	MoveToEx(*hdc, xE, yE, &pt);
	LineTo(*hdc, xP + xE, yP + yE);
};

Vector2D Vector2D::operator +(Vector2D v) {
	Vector2D res = Vector2D(this->xS+v.xS, this->yS + v.yS, this->xE + v.xE, this->yE + v.yE);
	return res;
}