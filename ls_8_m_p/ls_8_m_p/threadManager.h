#pragma once
#include "framework.h"
#include "battery.h"

class threadManager
{
public:
	threadManager() {};

	void createTheard(const std::function<void()>);
	void createTheard(void (battery::*)(), battery*);
	void threadsJoin();
};				  

