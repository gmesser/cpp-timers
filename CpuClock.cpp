// CpuClock.cpp

#include <time.h>
#include "CpuClock.h"

using namespace std;

double CpuClock::current_time() {
	clock_t ct = clock();
	return ct / (double) CLOCKS_PER_SEC;
}
