#define _USE_MATH_DEFINES
#include "Shar.h"

#pragma once
//#include "Vector2D.h"
#include "framework.h"

void Shar::move(int xMove, int yMove) {
	
};

void Shar::show(HDC* hdc) {
	Ellipse(*hdc, x-r/2, y-r/2, x+r/2, y+r/2);
	vectorN.show(hdc);
};