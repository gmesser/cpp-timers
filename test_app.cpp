/* 
 * test_app.cpp
 *
 */

#include <cstdlib>
#include <unistd.h>
#include <stdio.h>

#include "CpuClock.h"
#include "RealtimeClock.h"
#include "WallClock.h"

using namespace std;

int main(int argc, char** argv) {

	CpuClock cpu;
	RealtimeClock rtc;
	WallClock wcc;
	double d;

	// Loop for some time - about 3 seconds on an i7 or i5.
	long num_loops = 1000000000;
	printf("\nEmpty loop delay - %ld loops...\n", num_loops);
	for(long l = 0; l < num_loops; l++) {
		d += l;
	}
	printf("CpuClock.elapsed      = %4.9g\n", cpu.elapsed());
	printf("RealtimeClock.elapsed = %4.9g\n", rtc.elapsed());
	printf("WallClock.elapsed     = %4.9g\n", wcc.elapsed());
	printf("All timers run while the program is active.\n");

	// Sleep for some time.
	int sleep_secs = 5;
	printf("\nSleep - sleeping %d seconds...\n", sleep_secs);
	sleep(sleep_secs);
	printf("CpuClock.elapsed      = %4.9g\n", cpu.elapsed());
	printf("RealtimeClock.elapsed = %4.9g\n", rtc.elapsed());
	printf("WallClock.elapsed     = %4.9g\n", wcc.elapsed());
	printf("The CPU clock does not run while the program is sleeping\nbecause it only measures CPU time used by the program.\n");
	printf("The real-time clock and the wall clock are always running.\n");

	return 0;
}

