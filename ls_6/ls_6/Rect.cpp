#include "Rect.h"

void Rect::show(HDC& hdc) {
	Rectangle(hdc, pointStart.x - r, pointStart.y - r, pointStart.x+r, pointStart.y+r);
};