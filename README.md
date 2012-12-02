cpp-timers is an abstract BaseClock base class and three implementation classes:

* CpuClock uses the C function clock() to get the CPU time that the program
  has used since it started.

* WallClock uses the C function time() to get the current system time in
  seconds.

* RealtimeClock uses OS-specific functions to get the system time in
  nanoseconds.  Linux and Apple OS X code are included.

The test program test_app tests the classes.

