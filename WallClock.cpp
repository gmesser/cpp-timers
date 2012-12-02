// Wallclock.cpp

#include <time.h>
#include "WallClock.h"

using namespace std;

double WallClock::current_time() {
	time_t ct = time(0);
	return static_cast<double>(ct);
}
