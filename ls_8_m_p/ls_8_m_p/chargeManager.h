#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"

// ��������� ����������� ����
typedef unsigned long  (__stdcall* ThrdFunc)           (void* arg);          // �������� ������� ������
//typedef unsigned long (ClassMethod)        ();                              // �������� ������ ������
//     // �������� ������ ������

// ������ ����������� ��������� ������ ������������ � ������


class chargeManager
{
	tThrd tThs[6];
	//�������� ����������
	charger chr;
	int cx = 110;
	int cy = 200;

	//������������
	std::vector<battery*> batterys;
	int sx = 110;//������ �������� ������
	int sy = 480;

	//������ ������������ ����
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

		// ��� �������� ������������� ������ ��� � ����� �����
		typedef struct
		{
			void* Handle;              // ����� ������
			tThrdAddr Addr;            // �����
			unsigned long Id;          // ID ������
			unsigned long ExitCode;    // ��� ������
		}tThrd;
		for (int i = 0; i < countBt; i++) {
			int nx = sx + 40*i + 200*i;
			int ny = sy;
			batterys.push_back(new battery(nx, ny));
			std::string str = "�����: " + std::to_string(i);

			tThrd thread;
			thread.Addr.Method = &chargeManager::startPowerConsumption; // ��� ������� �����
			//thread.Addr.Method = &chargeManager::startPowerConsumption; // ��� ������� �����
			//thread.Handle = CreateThread(NULL, 0, thread.Addr.Function, this, 0, &thread.Id);
			//GetExitCodeThread(thread.Handle, &thread.ExitCode);
			//auto f = [this] { this->startPowerConsumption(); };
			//_beginthreadex_proc_type pf = (_beginthreadex_proc_type)&f;
			//_beginthreadex(NULL, 0, pf, &str, 0, NULL);//������ ��� ������� �������.
		};
	};

	void showElements(HDC&);
	void chooseEnergyBox();
};

