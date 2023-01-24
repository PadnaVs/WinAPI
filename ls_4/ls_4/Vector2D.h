#include "framework.h"

class Vector2D
{
	int lenght = 0;
public:
	int xS = 0;
	int yS = 0;
	int xE = 0;
	int yE = 0;

	Vector2D() {};

	Vector2D(int ixS, int iyS, int ixE, int iyE, int iL = 0) {
		xS = ixS;
		yS = iyS;
		xE = ixE;
		yE = iyE;
		lenght = 0;
	}
	
	void show(HDC* hdc);
	void setCoords(int ixS, int iyS, int ixE, int iyE);
};

