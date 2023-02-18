#pragma once
#include "framework.h"

class charger
{
protected:
	int width  = 120;
	int height = 120;
	HBRUSH br = CreateSolidBrush(RGB(0, 0, 0));
public:
	int x     = 0;
	int y     = 0;
	float speed = 15.f;

	charger() {};
	charger(int ix, int iy) {
		x = ix;
		y = iy;
	};

	void show(HDC& hdc);
	void move(int x, int y);
};

