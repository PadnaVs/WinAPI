#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"
#include "threadManager.h"

class chargeManager
{
	//��������� ������� ��� ������ ������������
	HWND hWnd = GetForegroundWindow();
	
	//�������� ���������� ��������
	threadManager tm;
	//�������� ����������
	charger* chr;
	int cx = 110;
	int cy = 170;

	//������������
	std::vector<battery*> batterys;
	int sx = 110;//������ �������� ������
	int sy = 450;

	//������ ������������ ����
	int nChB = -1;
protected:
	
public:
	chargeManager() {};

	int ts[6];

	chargeManager(HWND *ihWnd, int countBt) {
		//��������� �� ����� ��������� ����������
		chr = new charger(cx, cy);
		for (int i = 0; i < countBt; i++) {
			int nx = sx + 40 * i + 200 * i;
			int ny = sy;

			battery* bt = new battery(nx, ny);
			batterys.push_back(bt);

			tm.createTheard(&battery::low, bt);	
		};
		
		chr->setBattery(batterys);
		tm.createTheard(&charger::start, chr);
	};

	void showElements(HDC&);
	void chooseEnergyBox();
};

