#pragma once
#include "framework.h"

namespace global {
	extern std::vector<std::unique_lock<std::mutex>*> mts;
}