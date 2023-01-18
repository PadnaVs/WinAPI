#pragma once
#include "framework.h"

class TimerEllipce
{
	int x = 0;
	int y = 0;
	int r = 0;

public:
	TimerEllipce() {};
	TimerEllipce(int ix, int iy, int ir) {
		x = ix;
		y = iy;
		r = ir;
	};

	void CALLBACK tickTimer(HWND hWdn, UINT msg, UINT_PTR idTimer,	DWORD sec);
	void show(HWND* hWnd, HDC* hdc);
};

