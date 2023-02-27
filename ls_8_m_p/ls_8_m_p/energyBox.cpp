#include "energyBox.h"

void energyBox::setColor() {
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

	br = CreateSolidBrush(RGB(r, g, b));
};

void energyBox::show(HDC& hdc) {
	energyBox s = *this;
	if (energy) {
		RECT rt;
		SetRect(&rt, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
		FillRect(hdc, &rt, br);
	};
};

void energyBox::setCoords(int ix, int iy) {
	x = ix; y = iy;
};

void energyBox::low() {
	energy = 0;
};