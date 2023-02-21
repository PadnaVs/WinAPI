#include "chargeManager.h"

void chargeManager::showElements(HDC& hdc) {
	for (int i = 0; i < batterys.size(); i++) {
		batterys[i]->show(hdc);
	};
	chr.show(hdc);
};

void chargeManager::chooseEnergyBox() {
	nChB = rand() % (batterys.size()-1);
};

void chargeManager::startPowerConsumption() {
	MessageBox(hWnd, L"Запустился поток", NULL, NULL);
};