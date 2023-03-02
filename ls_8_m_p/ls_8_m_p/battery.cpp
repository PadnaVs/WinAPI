#include "battery.h"

void battery::show(HDC& hdc) {
	Rectangle(hdc, x-width/2, y-height/2, x+width/2, y+height/2);
	showEnergyBoxes(hdc);

	SIZE size;
	GetTextExtentPoint32(hdc, idThread.c_str(), idThread.size(), &size);
	TextOut(hdc, x-size.cx/2, y-size.cy/2 + height/2 + 15, idThread.c_str(), idThread.size());
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
	
	std::stringstream ss;
	ss << std::this_thread::get_id();
	int id = std::stoi(ss.str());
	idThread += std::to_wstring(id);
	
	while (true) {
		if (!enegry || isCharge) {
			continue;
		}
		int k = 0;
		for (int i = 0; i < 6; i++) {
			if (enegryBoxes[i]->energy)
				k++;
		};
		if (k != enegry) {
			int s = 0;
		};

		mt.lock();
		std::this_thread::sleep_for(std::chrono::seconds(timeLow));
		int numBox = 5 - (enegry - 1);
		enegryBoxes[numBox]->low();
		enegry--;
		mt.unlock();
	};
};

void battery::setTimeLow() {
	timeLow = 5 + rand() % 6;
};

void battery::charge(int ie) {
	int e = ie;
	for (int i = 5; i >= 0; i--) {
		if (!e) break;
		if (!enegryBoxes[i]->energy) {
			enegryBoxes[i]->energy = 1;
			e--;
		}
	};
	enegry = ie;	
};