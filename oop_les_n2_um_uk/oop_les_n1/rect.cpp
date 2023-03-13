#include "rect.h"

void Rect::show(HDC& hdc) {
	Rectangle(hdc, fX- fWidth /2, fY - fHeight / 2, fX + fWidth / 2, fY + fHeight / 2);
};