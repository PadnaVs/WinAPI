#pragma once
#include "framework.h"

class threadManager
{
	std::vector<std::thread*> threads;
public:
	threadManager() {};

	void createTheard(const std::function<void()> t);
	void threadsJoin();
};				  

