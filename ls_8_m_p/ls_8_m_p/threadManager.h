#pragma once
#include "framework.h"
#include "battery.h"
#include "charger.h"

class threadManager
{
public:
	threadManager() {};

	void createTheard(void (battery::*)(), battery*);
	void createTheard(void (charger::*)(), charger*);
};				  

