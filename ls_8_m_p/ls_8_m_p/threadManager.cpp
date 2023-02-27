#include "threadManager.h"


void threadManager::createTheard(void (battery::*f)(), battery* bt)
{
	std::thread* th = new std::thread(f, bt);
};

void threadManager::createTheard(const std::function<void()> f)
{
	std::thread* th = new std::thread(f);
};

void threadManager::threadsJoin() {
	//for (int i = 0; i < threads.size(); i++) {
	//	threads[i]->join();
	//};
};
