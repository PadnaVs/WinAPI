#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"
#include "threadManager.h"

class chargeManager
{
	//Установка хендела при пустом конструкторе
	HWND hWnd = GetForegroundWindow();
	
	//Менеджер управления потоками
	threadManager tm;
	//зарядное устройство
	charger* chr;
	int cx = 110;
	int cy = 170;

	//аккумуляторы
	

	int sx = 110;//начало отриовки акумов
	int sy = 450;

	//текущи заряжающийся бокс
	int nChB = -1;

	std::vector<battery*> batterys;

protected:
	
public:
	chargeManager() {};

	int ts[6];

	chargeManager(int countBt) {
		//Установка на экран зарядного устройства
		chr = new charger(cx, cy);
		for (int i = 0; i < countBt; i++) {
			int nx = sx + 40 * i + 200 * i;
			int ny = sy;

			battery* bt = new battery(nx, ny);
			batterys.push_back(bt);
			tm.createTheard(&battery::low, bt);
			std::unique_lock<std::mutex>* ul = new std::unique_lock<std::mutex>();
			global::mts.push_back(ul);
		};
		
		chr->setBattery(batterys);
		tm.createTheard(&charger::start, chr);
	};

	~chargeManager() {
		for (int i = 0; i < batterys.size(); i++) {
			batterys.clear();
		};
	};
	void showElements(HDC&);
	void chooseEnergyBox();
};

