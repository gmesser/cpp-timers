// RealtimeClock.h - implementation for real-time clock

#ifndef REALTIMECLOCK_H
#define REALTIMECLOCK_H

#include "BaseClock.h"

class RealtimeClock : public BaseClock {

public:

	RealtimeClock() {
		reset();
		start();
	}

protected:

	virtual double current_time();
};

#endif	/* REALTIMECLOCK_H */
