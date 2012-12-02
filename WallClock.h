// WallClock.h - implementation for system time clock

#ifndef WALLCLOCK_H
#define WALLCLOCK_H

#include <time.h>
#include "BaseClock.h"

class WallClock : public BaseClock {

public:

	WallClock() {
		reset();
		start();
	}

protected:

	virtual double current_time();
};

#endif /* WALLCLOCK_H */
