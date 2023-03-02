#include "charger.h"

void charger::show(HDC& hdc) {
	RECT rt{0,0,0,0};

	Rectangle(hdc, x - width/2, y - height / 2, x + width / 2, y + height/2);

	int shift = 25;//отступ от внешнего края для внутреннего квадрата
	SelectObject(hdc, br);
	Rectangle(hdc, x - width / 2 + shift, y - height / 2 + shift, x + width / 2 - shift, y + height / 2 - shift);
	
	SIZE size;
	GetTextExtentPoint32(hdc, idThread.c_str(), idThread.size(), &size);
	TextOut(hdc, x - size.cx / 2, y - size.cy / 2 - height / 2 + 15, idThread.c_str(), idThread.size());
	
	if (connectedToBT) {
		HPEN hPen = CreatePen(PS_SOLID, 5, BLACK_PEN);
		SelectObject(hdc, hPen);
		MoveToEx(hdc, x - width / 2 - 40, y+height/2 + 20, NULL);
		LineTo(hdc, x - width / 2 - 40, y - height+ 40);

		MoveToEx(hdc, x - width / 2 - 40, y - height + 40, NULL);
		LineTo(hdc, x + width - 20, y - height + 40);

		MoveToEx(hdc, x + width / 2 + 40, y + height / 2 + 20, NULL);
		LineTo(hdc, x + width / 2 + 40, y - height + 40);


		int rw = 10;
		int rh = 20;
		hPen = CreatePen(PS_SOLID, 0, BLACK_PEN);
		HBRUSH hbr = CreateSolidBrush(RGB(255, 69, 0));
		SelectObject(hdc, hbr);
		SelectObject(hdc, hPen);
		int shift = -10;
		Rectangle(hdc, x - rw / 2 + shift, y + height / 2, x + rw / 2 + shift, y + rh + height / 2);
		shift = 10;
		Rectangle(hdc, x - rw / 2 + shift, y + height / 2, x + rw / 2 + shift, y + rh + height / 2);
	}
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
	std::stringstream ss;
	ss << std::this_thread::get_id();
	int id = std::stoi(ss.str());

	idThread += std::to_wstring(id);

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
	std::mutex mt;
	int secCh = 1 + rand() % 2;
	std::this_thread::sleep_for(std::chrono::seconds(secCh));
	btrsInfo[numBt]->setTimeLow();

	mt.lock();
	btrsInfo[numBt]->charge(energy);
	energy -= energy;
	mt.unlock();

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
	int numMinEl = -1;
	battery* pBt = btrsInfo[0];
	for (int i = 0; i < btrsInfo.size(); i++) {
		if (pBt->enegry >= btrsInfo[i]->enegry) {
			pBt = btrsInfo[i];
			numMinEl = i;
		}
	};

	int countMinNums = 1;
	for (int i = 1; i < btrsInfo.size(); i++) {
		int en1 = btrsInfo[numMinEl]->enegry;
		int en2 = btrsInfo[i]->enegry;

		if (en1 == en2) {
			countMinNums++;
		};
	};
	int* numsMinEl = new int[countMinNums];
	int j = 0;
	for (int i = 0; i < btrsInfo.size(); i++) {
		if (btrsInfo[numMinEl]->enegry == btrsInfo[i]->enegry) {
			numsMinEl[j] = i;
			j++;
		};
	};

	int rndNumBt = 0;
	if (countMinNums!=1) {
		rndNumBt = rand() % (countMinNums-1);
	}

	int sNumBt = numsMinEl[rndNumBt];

	delete[] numsMinEl;
	return sNumBt;
};

void charger::setEnergy() {
	srand(time(NULL));
	energy = 1 + rand() % 6;
};

