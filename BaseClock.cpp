// BaseClock.cpp

#include <cmath>
#include "BaseClock.h"

using namespace std;

double BaseClock::elapsedDHMS(double &days, double &hours, double &minutes, double &seconds) {
	double elapsed_time = BaseClock::elapsed();
	return BaseClock::elapsedDHMS(elapsed_time, days, hours, minutes, seconds);
}

double BaseClock::elapsedDHMS(double elapsed_time, double &days, double &hours, double &minutes, double &seconds) {
	double seconds_in_day = 60.0 * 60.0 * 24.0;
	double seconds_in_hour = 60.0 * 60.0;
	double seconds_in_minute = 60.0;

	double work_time = elapsed_time;

	if(work_time >= seconds_in_day) {
		days = fabs(work_time / seconds_in_day);
		work_time -= days * seconds_in_day;
	}

	if(work_time >= seconds_in_hour) {
		hours = fabs(work_time / seconds_in_hour);
		work_time -= hours * seconds_in_hour;
	}

	if(work_time >= seconds_in_minute) {
		minutes = fabs(work_time / seconds_in_minute);
		work_time -= minutes * seconds_in_minute;
	}

	seconds = work_time;

	return elapsed_time;
}
