#pragma once
#include "framework.h"

class energyBox
{
protected:
	int energy = 0;

	int width  = 180;
	int height = 60;

	int num = 0;
public:
	int x = 0;
	int y = 0;

	energyBox(int inum) { num = inum; };
	energyBox(int ix, int iy, int ie, int inum) {
		x = ix;
		y = iy;
		energy = ie;
		num = inum;
	};

	void show(HDC& hdc);
	void setCoords(int ix, int iy);
};

