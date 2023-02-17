#include "energyBox.h"

void energyBox::show(HDC& hdc) {
	RECT rt;
	SetRect(&rt, x-width, y - height, x+width, y + height);

	int r = 0;
	int g = 0;
	int b = 0;

	switch (num)
	{
	case 1:
		r = 255;
		break;
	case 2:
		g = 255;
		b = 255;
		break;
	case 3:
		g = 255;
		break;
	default:
		break;
	}

	HBRUSH br = CreateSolidBrush(RGB(r, g, b));
};
