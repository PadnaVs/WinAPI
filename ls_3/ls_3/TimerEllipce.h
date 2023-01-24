#pragma once
#include "framework.h"

class TimerEllipce
{
	int x = 0;
	int y = 0;
	int r = 0;
	int a = -90;
	
public:
	int s = 0;
	int speed = 1;

	TimerEllipce() {};
	TimerEllipce(int ix, int iy, int ir) {
		x = ix;
		y = iy;
		r = ir;
	};

	
	void show(HWND* hWnd, HDC* hdc);
};

