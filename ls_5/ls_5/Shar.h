#pragma once
#include "Vector2D.h"

class Shar
{
	int r = 0.f;
	Vector2D pointSrart;
	Vector2D vectorNaprav;//������ �����������
	Vector2D pointMove;

	float speed = 0.f;

	void showArrowNp(HDC&);
public:
	Shar() {};
	Shar(int ix, int iy, int ir) {
		pointSrart.x = ix;
		pointSrart.y = iy;
		r = ir;
	};

	void show(HDC&);
	void setCoordsStart(int, int);//�� ����� �������� ������� �� ������
	void move(int, int);
};

