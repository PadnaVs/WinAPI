#include "charger.h"

void charger::show(HDC& hdc) {
	RECT rt{0,0,0,0};

	Rectangle(hdc, x - width/2, y - height / 2, x + width / 2, y + height/2);

	int shift = 25;//отступ от края
	SelectObject(hdc, br);
	Rectangle(hdc, x - width / 2 + shift, y - height / 2 + shift, x + width / 2 - shift, y + height / 2 - shift);
};

void charger::move(int mx, int my) {
	int vx = mx - x;
	int vy = my - y;
	float lenDir = sqrt(pow(vx,2)+pow(vy,2));//получаем длинну вектора
	float nx = vx / lenDir;
	float ny = vy / lenDir;

	x += nx * speed;
	y += ny * speed;
};