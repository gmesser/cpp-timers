// RealtimeClock.cpp

//#include <sys/time.h>
#include <time.h>
#include "RealtimeClock.h"

#ifdef __MACH__
#include <mach/mach_time.h>
#endif // #ifdef __MACH__

using namespace std;

double RealtimeClock::current_time() {

	double ct;

#ifndef __MACH__

	// Linux
	struct timespec tp;
	int result = clock_gettime(CLOCK_MONOTONIC, &tp);
	if (result == 0) {
		ct = tp.tv_sec + (1.0e-9 * tp.tv_nsec);
	}
	else {
		// An error occurred while getting the time.
		ct = 0.0;
	}

#endif // #ifndef __MACH__
	
#ifdef __MACH__

	// Darwin - Apple OS X
	mach_timebase_info_data_t info;
	mach_timebase_info(&info);

	double conv_factor = (static_cast<double>(info.numer)) / (static_cast<double>(info.denom));
	ct = mach_absolute_time() * conv_factor * 1.0e-9;

#endif // #ifdef __MACH__

	return ct;
}
