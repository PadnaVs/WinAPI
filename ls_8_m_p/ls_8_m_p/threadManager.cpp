#include "threadManager.h"

void threadManager::createTheard(const std::function<void()> f)
{
	std::thread* th = new std::thread(f);
	//threads.push_back(th);
	//th.join();
};

void threadManager::threadsJoin() {
	//for (int i = 0; i < threads.size(); i++) {
	//	threads[i]->join();
	//};
};
