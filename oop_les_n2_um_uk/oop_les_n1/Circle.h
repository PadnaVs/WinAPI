#pragma once
#include "framework.h"
#include "figure.h"

class Circle : 
	public Figure
{
	float fR = 0.f;

	
public:
	~Circle() {
		sFigureInfo += L"\nЯ круг";
	};

	Circle(float iFX, float iFY, float iFR) : Figure(iFX, iFY) {
		fR = iFR;
	};

	void show(HDC&);
};

