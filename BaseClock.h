// BaseClock - Abstract base class for clocks.

#ifndef BASECLOCK_H
#define BASECLOCK_H

class BaseClock {
private:

	// The current time when the clock was started.
	double _started;

	// The current time when the clock was stopped.
	double _stopped;

	// The last calculated elapsed time.
	double _elapsed;

	// The last calculated loop time;
	double _lastloop;

protected:

	/*
	 * diff()
	 * Calculate the difference between two time values.
	 */
	virtual double diff(double start, double end) {
		return(end - start);
	}

	/*
	 * current_time()
	 * Get the current time from the system.
	 *
	 * The method used to get the current time will be different for the
	 * timers derived from this base class, but each derived class will be
	 * expected to return a double value that is the current time in seconds.
	 * 
	 * It does not matter if the origin is a particular epoch or if it is the
	 * time when the program started, as long as the origin is consistent from
	 * call to call so that diff() can calculate the difference between two time
	 * values.
	 */
	virtual double current_time() = 0;

public:

	BaseClock() = default;

	virtual ~BaseClock() = default;

	virtual void init() {
		double ct = current_time();
		_lastloop = ct;
		_started = ct;
		_stopped = 0.0;
		_elapsed = 0.0;
	}

	virtual void restart() {
		double ct = current_time();
		double sd = diff(_stopped, ct);
		_started += sd;
		_lastloop += sd;
		_stopped = 0.0;
	}

	/*
	 * start()
	 * Either start the clock
	 * at the current time or restarts the
	 * clock at 0.0.
	 *
	 * Calling start() while the clock is
	 * running restarts it at 0.0.
	 *
	 * Calling start() while the clock is
	 * stopped effectively restarts it at the
	 * current time by adjusting the start
	 * and lastlap times by the amount of time
	 * that the clock was stopped.
	 */
	virtual double start() {
		if (_stopped) {
			restart();
		}
		else {
			init();
		}

		return elapsed();
	}

	/*
	 * stop()
	 * Record the time when the
	 * clock is stopped.  When stopped,
	 * the recorded value is used in the elapsed
	 * time calculation.  The clock
	 * remains stopped until the start()
	 * function is called to restart it.
	 */
	virtual double stop() {
		if (!_stopped) {
			_stopped = current_time();
		}

		return elapsed();
	}

	/*
	 * reset()
	 * Stop the clock and initialize all times to the
	 * current time.
	 * The start() function must be called to
	 * restart it.
	 */
	virtual double reset() {
		_lastloop = _started = _stopped = current_time();
		_elapsed = 0.0;

		return _elapsed;
	}

	/*
	 * loop()
	 * Return the number of seconds
	 * since loop() was last called.
	 * Resets the loop timer to zero.
	 */
	virtual double loop() {
		double dl; // difference from last loop

		if (_stopped) {
			dl = diff(_lastloop, _stopped);
			_lastloop = _stopped;
		}
		else {
			double ct = current_time();
			dl = diff(_lastloop, ct);
			_lastloop = ct;
		}

		return dl;
	}

	/*
	 * checkloop()
	 * Return the number of seconds
	 * since loop() was last called
	 * Does not reset the loop timer.
	 */
	virtual double check_loop() {
		double dl; // difference from last loop

		if (_stopped) {
			dl = diff(_lastloop, _stopped);
		}
		else {
			double ct = current_time();
			dl = diff(_lastloop, ct);
		}

		return dl;
	}

	/*
	 * elapsed()
	 * Returns the elapsed time in
	 * seconds that the clock has been
	 * running.
	 */
	virtual double elapsed() {
		if (_stopped) {
			_elapsed = diff(_started, _stopped);
		}
		else {
			_elapsed = diff(_started, current_time());
		}

		return _elapsed;
	}

	/*
	 * isstopped()
	 * Return non-zero if the
	 * clock is stopped, and zero if it
	 * is running.
	 */
	int isstopped() {
		if (_stopped)
			return 1;
		else
			return 0;
	}

	/*
	 * elapsedDHMS()
	 * Return the elapsed time in
	 * seconds that the clock has been
	 * running.  In addition, it breaks out
	 * the elapsed time into days, hours, minutes,
	 * and seconds.  Those are returned in the
	 * passed parameters.
	 *
	 * You can call this by specifying an elapsed time as the first argument, or
	 * not.  This allows you to pass in the result of a previous call to
	 * elapsed() so that the days, hours, minutes, and seconds match the passed
	 * elapsed time.
	 *
	 * When called without the elapsed_time parameter, the elapsed time is read
	 * and may differ from a previous call to elapsed by a few fractions of a
	 * second.
	 */
	virtual double elapsedDHMS(double elapsed_time, double &days, double &hours, double &mins, double &secs);
	virtual double elapsedDHMS(double &days, double &hours, double &mins, double &secs);
};

#endif /* BASECLOCK_H */
