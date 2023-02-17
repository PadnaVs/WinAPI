#include "battery.h"

void battery::show(HDC& hdc) {
	Rectangle(hdc, x-width, y-height, x+width, y+height);
};

void battery::showEnergyBoxes() {

};