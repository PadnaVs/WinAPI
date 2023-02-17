#pragma once
#include "framework.h"
#include "energyBox.h"

class battery
{
private:
	void showEnergyBoxes(HDC&);

protected:
	int width = 200;
	int height = 400;

	std::vector<energyBox*> enegryBoxes;

public:
	int x = 0;
	int y = 0;

	battery(int ix, int iy) {
		x = ix;
		y = iy;

		for (int i = 0; i < 6; i++) {
			int num = i/2;
			energyBox* enb = new energyBox(num);
			enegryBoxes.push_back(enb);
		};
	};
	~battery() {
		for (int i = 0; i < 6; i++) {
			delete enegryBoxes[i];
		};
	};

	void show(HDC& hdc);

	void pushPow(float ie);//для зарядки
};

