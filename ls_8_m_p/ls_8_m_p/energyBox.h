#pragma once
#include "framework.h"

class energyBox
{
	HBRUSH br;
	void setColor();
protected:
	

	int width  = 180;
	int height = 60;

	int num = 0;
public:
	int energy = 1;

	int x = 0;
	int y = 0;

	energyBox(int inum) { num = inum; setColor(); };
	energyBox(int ix, int iy, int ie, int inum) {
		x = ix;
		y = iy;
		energy = ie;
		num = inum;
		setColor();
	};

	~energyBox() {
		int i = 0;
	};

	void show(HDC& hdc);
	void setCoords(int ix, int iy);

	void low();
};

