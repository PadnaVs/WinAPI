#include "energyBox.h"

void energyBox::show(HDC& hdc) {
	RECT rt;
	SetRect(&rt, x-width/2, y - height/2, x+width/2, y + height/2);

	int r = 0;
	int g = 0;
	int b = 0;

	switch (num)
	{
	case 2:
		r = 255;
		break;
	case 1:
		g = 255;
		r = 255;
		break;
	case 0:
		g = 255;
		break;
	}

	HBRUSH br = CreateSolidBrush(RGB(r, g, b));

	FillRect(hdc, &rt, br);
};

void energyBox::setCoords(int ix, int iy) {
	x = ix; y = iy;
};
