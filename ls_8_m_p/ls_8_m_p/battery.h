#pragma once
#include "framework.h"
#include "energyBox.h"

class battery
{
	std::wstring idThread = L"Id Потока: ";

	int timeLow = 0;//время разряда батареи

	int width = 200;
	int height = 400;

	std::vector<energyBox*> enegryBoxes;

	void showEnergyBoxes(HDC&);

	~battery() {
		for (int i = 0; i < 6; i++) {
			delete enegryBoxes[i];
		};
	};

public:
	int x = 0;
	int y = 0;
	int enegry = 0;

	battery(int ix, int iy) {
		x = ix;
		y = iy;

		for (int i = 0; i < 6; i++) {
			int num = i/2;
			energyBox* enb = new energyBox(num);
			enegryBoxes.push_back(enb);

			if (enb->energy)
				enegry++;
		};
	};

	void show(HDC& hdc);

	void charge(int ie);//для зарядки
	void low();
	void setTimeLow();
};

