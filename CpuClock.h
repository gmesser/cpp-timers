// CpuClock.h - implementation for CPU-time clock

#ifndef CPUCLOCK_H
#define CPUCLOCK_H

#include "BaseClock.h"

class CpuClock : public BaseClock {

public:

	CpuClock() {
		reset();
		start();
	}

protected:

	virtual double current_time();
};

#endif /* CPUCLOCK_H */
