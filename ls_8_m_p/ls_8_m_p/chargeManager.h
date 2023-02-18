#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"

class chargeManager
{
	//�������� ����������
	charger chr;
	int cx = 110;
	int cy = 200;

	//������������
	std::vector<battery*> batterys;
	int sx = 110;//������ �������� ������
	int sy = 480;

	//������ ������������ ����
	int cb = -1;
public:
	chargeManager(int countBt) {
		chr = charger(cx, cy);
		for (int i = 0; i < countBt; i++) {
			int nx = sx + 40*i + 200*i;
			int ny = sy;
			batterys.push_back(new battery(nx, ny));
		};
	};

	void showElements(HDC&);
	
	void chooseEnergyBox();
};

