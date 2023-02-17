#include "chargeManager.h"

void chargeManager::showElements(HDC& hdc) {
	for (int i = 0; i < batterys.size(); i++) {
		batterys[i]->show(hdc);
	};
};