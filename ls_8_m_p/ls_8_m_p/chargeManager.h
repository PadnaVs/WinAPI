#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"

class chargeManager
{
	//Установка хендела при пустом конструкторе
	HWND hWnd = GetForegroundWindow();
	//tThrd tThs[6];
	//зарядное устройство
	charger chr;
	int cx = 110;
	int cy = 200;

	//аккумуляторы
	std::vector<battery*> batterys;
	int sx = 110;//начало отриовки акумов
	int sy = 480;

	//текущи заряжающийся бокс
	int nChB = -1;
protected:
	
public:
	void startPowerConsumption();
	chargeManager() {};

	chargeManager(HWND *ihWnd, int countBt) {
		//Присвоедие дискриптора окна
		{
			hWnd = *ihWnd;
		}
		//Установка на экран зарядного устройства
		chr = charger(cx, cy);
		//Прототипы функции
		typedef unsigned long(__stdcall* ThrdFunc) (void* arg);//для функции потока
		typedef void (chargeManager::* ClassMethod)();//для класса

		//для ссылок на оба метода
		typedef union
		{
			ClassMethod Method;
			ThrdFunc Function;
		}tThrdAddr;

		// для гибкости использования храним все в одном месте
		typedef struct
		{
			void* Handle;              // хэндл потока
			tThrdAddr Addr;            // адрес
			unsigned long Id;          // ID потока
			unsigned long ExitCode;    // код выхода
		}tThrd;

		for (int i = 0; i < countBt; i++) {
			int nx = sx + 40*i + 200*i;
			int ny = sy;
			batterys.push_back(new battery(nx, ny));
			std::string str = "Поток: " + std::to_string(i);

			tThrd thread;
			thread.Addr.Method = &chargeManager::startPowerConsumption; // тут главная магия
			thread.Handle = CreateThread(NULL, 0, thread.Addr.Function, this, 0, &thread.Id);
			GetExitCodeThread(thread.Handle, &thread.ExitCode);
		};
	};

	void showElements(HDC&);
	void chooseEnergyBox();
};

