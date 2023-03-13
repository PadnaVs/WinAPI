#pragma once
#include "framework.h"

class Figure
{
protected:
	float fX = 0.f;
	float fY = 0.f;
	std::wstring sFigureInfo = L"";

public:
	virtual ~Figure() {
		HWND hWnd = GetDesktopWindow();
		MessageBox(hWnd, sFigureInfo.c_str(), L"Информация о фигуре", MB_OK | MB_ICONINFORMATION);
	};

	Figure() {	};
	Figure(float fix, float fiy) {
		fX = fix;
		fY = fiy;
		sFigureInfo = L"Удалена фигура.\nX: " + std::to_wstring(fX) + L" Y: " + std::to_wstring(fY);
	};
	
	virtual void show(HDC& hdc) = 0;
};

