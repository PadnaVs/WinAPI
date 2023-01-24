#pragma once
#include "framework.h"
#include "Vector2D.h"

class Shar
{
	int r = 0;
	Vector2D vectorN;
	int speed = 15;
public:
	int x = 0;
	int y = 0;
	Shar() {};
	Shar(int ix, int iy, int ir) {
		x = ix;
		y = iy;
		r = ir;
		vectorN.setCoords(x,y,x,y);
	};

	void show(HDC* hdc);
	void move(int xMove, int yMove);
};

