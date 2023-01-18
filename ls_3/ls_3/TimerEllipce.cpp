#include "TimerEllipce.h"
#include "framework.h"

void TimerEllipce::show(HWND* hWnd, HDC* hdc) {
	SetTimer(*hWnd, 1, 1000, (TIMERPROC)&tickTimer);
	Ellipse(*hdc, x - r, y - r, x + r, y + r);
};

void CALLBACK TimerEllipce::tickTimer(HWND hWdn, UINT msg, UINT_PTR idTimer, DWORD sec) {

};
