#include "battery.h"

void battery::show(HDC& hdc) {
	Rectangle(hdc, x-width/2, y-height/2, x+width/2, y+height/2);
	showEnergyBoxes(hdc);
};

void battery::showEnergyBoxes(HDC &hdc) {
	for (int i = 0; i < enegryBoxes.size(); i++) {
		int nx = x;
		int ny = y - height / 2+38 + 60*i + 5*i; //+ 36 + 60*i + 6*i;
		enegryBoxes[i]->setCoords(nx, ny);
		enegryBoxes[i]->show(hdc);
	};
};

void battery::low() {
	while (enegry) {
		std::this_thread::sleep_for(std::chrono::seconds(timeLow));
		int numBox = 5 - (enegry-1);
		enegryBoxes[numBox]->low();
		enegry--;
	};
};