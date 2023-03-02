#include "global.h"

namespace global {
	std::vector<std::unique_lock<std::mutex>*> mts;
}