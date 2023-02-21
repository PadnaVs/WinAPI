#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"

class chargeManager
{
	//��������� ������� ��� ������ ������������
	HWND hWnd = GetForegroundWindow();
	//tThrd tThs[6];
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
	chargeManager() {};

	chargeManager(HWND *ihWnd, int countBt) {
		//���������� ����������� ����
		{
			hWnd = *ihWnd;
		}
		//��������� �� ����� ��������� ����������
		chr = charger(cx, cy);
		//��������� �������
		typedef unsigned long(__stdcall* ThrdFunc) (void* arg);//��� ������� ������
		typedef void (chargeManager::* ClassMethod)();//��� ������

		//��� ������ �� ��� ������
		typedef union
		{
			ClassMethod Method;
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
			thread.Handle = CreateThread(NULL, 0, thread.Addr.Function, this, 0, &thread.Id);
			GetExitCodeThread(thread.Handle, &thread.ExitCode);
		};
	};

	void showElements(HDC&);
	void chooseEnergyBox();
};

