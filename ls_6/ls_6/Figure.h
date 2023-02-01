#pragma once
#include "Vector2D.h"

class Figure
{
protected:
	float r = 0.f;
	Vector2D pointStart;
	Vector2D vectorNaprav;//Вектор направления
	Vector2D pointMove;

	float speed = 5.f;

	void showArrowNp(HDC&);
	bool stuck = false;
public:
	Figure() {};
	Figure(int ix, int iy, int ir) {
		pointStart.x = (float)ix;
		pointStart.y = (float)iy;
		r = (float)ir;
	};

	virtual void show(HDC&);
	void setCoordsStart(int, int);//Во время создания обьекта на экране
	void move(Vector2D&);
	void reMove(Vector2D&);
	void changeDir();
};

