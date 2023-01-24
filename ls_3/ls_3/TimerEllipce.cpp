#define _USE_MATH_DEFINES
#include "TimerEllipce.h"
#include "framework.h"

void TimerEllipce::show(HWND* hWnd, HDC* hdc) {
	Ellipse(*hdc, x - r, y - r, x + r, y + r);
	POINT pt;
	MoveToEx(*hdc, x, y, &pt);
	
	int xEL = x + cos((a+(s*6)) * M_PI / 180)*r;
	int yEL = y + sin((a+(s*6)) * M_PI / 180)*r;
	LineTo(*hdc, xEL, yEL);
};
