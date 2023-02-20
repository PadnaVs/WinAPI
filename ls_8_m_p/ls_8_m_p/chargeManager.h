#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"

// объявляем необходимые типы
typedef unsigned long  (__stdcall* ThrdFunc)           (void* arg);          // прототип функции потока
//typedef unsigned long (ClassMethod)        ();                              // прототип метода класса
//     // прототип метода класса

// данное объединение позволяет решить несостыковку с типами


class chargeManager
{
	tThrd tThs[6];
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

	chargeManager(int countBt) {
		chr = charger(cx, cy);

		typedef union
		{
			(chargeManager::* startPowerConsumption) Method;
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
			//thread.Addr.Method = &chargeManager::startPowerConsumption; // тут главная магия
			//thread.Handle = CreateThread(NULL, 0, thread.Addr.Function, this, 0, &thread.Id);
			//GetExitCodeThread(thread.Handle, &thread.ExitCode);
			//auto f = [this] { this->startPowerConsumption(); };
			//_beginthreadex_proc_type pf = (_beginthreadex_proc_type)&f;
			//_beginthreadex(NULL, 0, pf, &str, 0, NULL);//потоки для разряда батарей.
		};
	};

	void showElements(HDC&);
	void chooseEnergyBox();
};

