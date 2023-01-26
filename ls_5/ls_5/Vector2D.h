
#pragma once
#include "framework.h"

class Vector2D
{
	float lenght = 0.f;
public:
	float x = 0.f;
	float y = 0.f;

	Vector2D() {};
	Vector2D(float ix, float iy) {
		x = ix;
		y = iy;
	};

	float getLenght();
	void show(HDC& hdc);
	Vector2D operator-(Vector2D);
};

