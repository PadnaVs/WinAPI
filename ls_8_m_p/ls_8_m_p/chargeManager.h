#pragma once
#include "framework.h"
#include "battery.h"

class chargeManager
{
	int sx = 110;
	int sy = 480;
	//зарядное устройство

	//аккумуляторы
	std::vector<battery*> batterys;
public:
	chargeManager(int countBt) {
		for (int i = 0; i < countBt; i++) {
			int nx = sx + 40*i + 200*i;
			int ny = sy;
			batterys.push_back(new battery(nx, ny));
		};
	};

	void showElements(HDC&);
};

