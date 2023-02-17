#pragma once
#include "framework.h"
#include "energyBox.h"

class battery
{
private:
	void showEnergyBoxes();

protected:
	int width = 100;
	int height = 200;

	std::vector<energyBox*> enegryBoxes;

public:
	int x = 0;
	int y = 0;

	battery(int ix, int iy) {
		x = ix;
		y = iy;

		for (int i = 0; i < 6; i++) {
			energyBox* enb = new energyBox();
			enegryBoxes.push_back(enb);
		};
	};
	~battery() {
		for (int i = 0; i < 6; i++) {
			delete enegryBoxes[i];
		};
	};

	void show(HDC& hdc);
	void pushPow(float ie);
};

