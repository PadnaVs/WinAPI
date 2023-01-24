#pragma once
#include "framework.h"
#include "Vector2D.h"

class Shar
{
	int x = 0;
	int y = 0;
	int r = 0;
	Vector2D vectorN;
public:
	Shar() {};
	Shar(int ix, int iy, int ir) {
		x = ix;
		y = iy;
		r = ir;
		vectorN.setCoords(x,y,x,y);
	};

	void show(HDC* hdc);
};

