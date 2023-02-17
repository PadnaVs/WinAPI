#pragma once
#include "framework.h"

class energyBox
{
protected:
	int energy = 0;

	int width  = 80;
	int height = 30;

	int num = 0;
public:
	int x = 0;
	int y = 0;

	energyBox() {};
	energyBox(int ix, int iy, int ie, int inum) {
		x = ix;
		y = iy;
		energy = ie;
		num = inum;
	};

	void show(HDC& hdc);
};

