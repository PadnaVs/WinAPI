#define _USE_MATH_DEFINES
#include "Shar.h"
#include "Vector2D.h"
#pragma once
#include "framework.h"


void Shar::show(HDC* hdc) {
	Ellipse(*hdc, x, y, x+r, y+r);
	vectorN.show(hdc);
};