#define _USE_MATH_DEFINES
#include "Vector2D.h"
#pragma once
#include "framework.h"


void Vector2D::show(HWND* hWnd, HDC* hdc) {
	POINT pt;
	MoveToEx(*hdc, xS, yS, &pt);
	LineTo(*hdc, xE, yE);
	
	int as = atan(((double)yE - (double)yS) / ((double)xE - (double)xS)) * (180 / M_PI);

	int lenArr = 30;
	int a = 0;
	a = xS < xE ? as-165 : 15+as;//angle 15c
	int xP = 0 + cos((a) * M_PI / 180) * lenArr;
	int yP = 0 + sin((a) * M_PI / 180) * lenArr;

	MoveToEx(*hdc, xE, yE, &pt);
	LineTo(*hdc, xP+xE, yP+yE);

	a = xS < xE ? 165+as : -15+as;//angle 15c
	xP = 0 + cos((a)*M_PI / 180) * lenArr;
	yP = 0 + sin((a)*M_PI / 180) * lenArr;

	MoveToEx(*hdc, xE, yE, &pt);
	LineTo(*hdc, xP + xE, yP + yE);
};