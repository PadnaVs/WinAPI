#pragma once
#include "framework.h"
#include "battery.h"

class charger
{
	std::vector<battery*> btrsInfo;
	std::wstring idThread = L"Id Потока: ";

	int energy = 0;
	bool connectedToBT = false;
	bool moved = false;

	int width  = 120;
	int height = 120;
	HBRUSH br = CreateSolidBrush(RGB(0, 0, 0));

public:
	int x     = 0;
	int y     = 0;
	float speed = 5.f;

	charger() {};
	charger(int ix, int iy) {
		x = ix;
		y = iy;
	};

	void setBattery(std::vector<battery*> iBtrs) {
		btrsInfo = iBtrs;
	};

	void show(HDC& hdc);
	void move(int x, int y);
	void moveToBT(int numBt);

	void start();
	int setNumBt();
	void setEnergy();
	
	void charge(int numBt);
};

