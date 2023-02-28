#include "threadManager.h"

void threadManager::createTheard(void (battery::* f)(), battery* bt)
{
	std::thread* th = new std::thread(f, bt);
};

void threadManager::createTheard(void (charger::* f)(), charger* ch)
{
	std::thread* th = new std::thread(f, ch);
};
