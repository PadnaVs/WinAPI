#pragma once
#include "Vector2D.h"

class Shar
{
	float r = 0.f;
	Vector2D pointSrart;
	Vector2D vectorNaprav;//Вектор направления
	Vector2D pointMove;

	float speed = 5.f;

	void showArrowNp(HDC&);
	bool stuck = false;
public:
	Shar() {};
	Shar(int ix, int iy, int ir) {
		pointSrart.x = (float)ix;
		pointSrart.y = (float)iy;
		r = (float)ir;
	};

	void show(HDC&);
	void setCoordsStart(int, int);//Во время создания обьекта на экране
	void move(Vector2D&);
	void reMove(Vector2D&);
	void changeDir();
};

