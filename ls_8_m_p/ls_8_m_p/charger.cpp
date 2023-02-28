#include "charger.h"

void charger::show(HDC& hdc) {
	RECT rt{0,0,0,0};

	Rectangle(hdc, x - width/2, y - height / 2, x + width / 2, y + height/2);

	int shift = 25;//отступ от края
	SelectObject(hdc, br);
	Rectangle(hdc, x - width / 2 + shift, y - height / 2 + shift, x + width / 2 - shift, y + height / 2 - shift);
};

void charger::move(int mx, int my) {
	int vx = mx - x;
	int vy = my - y;
	float lenDir = sqrt(pow(vx,2)+pow(vy,2));//получаем длинну вектора
	float nx = vx / lenDir;
	float ny = vy / lenDir;

	x += nx * speed;
	y += ny * speed;
};

void charger::start() {
	int numBt = -1;
	while (true) {
		if (!energy) {
			setEnergy();
		} else if (energy && !connectedToBT && !moved) {
			numBt = setNumBt();
			moved = true;
		} else if (energy && !connectedToBT && moved) {
			moveToBT(numBt);
		}else{
			charge(numBt);
		};
		
	}
};

void charger::charge(int numBt) {
	int secCh = 1 + rand() % 3;
	std::this_thread::sleep_for(std::chrono::seconds(secCh));
	btrsInfo[numBt]->charge(energy);
	energy -= energy;
	connectedToBT = false;
};

void charger::moveToBT(int numBt) {
	if (x == btrsInfo[numBt]->x) {
		moved = false;
		connectedToBT = true;
		return;
	};

	move(btrsInfo[numBt]->x, y);
	std::this_thread::sleep_for(std::chrono::microseconds(36));
};

int charger::setNumBt() {
	int mBtMixE = 0;
	for (int i = 0; i < btrsInfo.size(); i++) {
		if (btrsInfo[i]->enegry >= btrsInfo[mBtMixE]->enegry) {
			mBtMixE = i;
		}
	};
	
	int sNumBt = rand() % 5;
	while(sNumBt == mBtMixE) {
		sNumBt = rand() % 5;
	};
    //нужно отсортировать по минимальному и из них выбрать случайное
	return sNumBt;
};

void charger::setEnergy() {
	srand(time(NULL));
	energy = 1 + rand() % 6;
};

