# The makefile for the C++ timers.

CC = g++
CFLAGS += -Wall -std=c++11
linux_libs = -lrt
darwin_libs =

uname = $(shell uname)

ifeq ($(uname), Linux)
   libs_req = $(linux_libs)
else ifeq ($(uname), Darwin)
   libs_req = $(darwin_libs)
endif

all : test_app

BaseClock.o : BaseClock.cpp BaseClock.h
	$(CC) $(CFLAGS) -c -o BaseClock.o BaseClock.cpp

CpuClock.o :CpuClock.cpp BaseClock.h CpuClock.h
	$(CC) $(CFLAGS) -c -o CpuClock.o CpuClock.cpp

RealtimeClock.o : RealtimeClock.cpp BaseClock.h RealtimeClock.h
	$(CC) $(CFLAGS) -c -o RealtimeClock.o RealtimeClock.cpp

WallClock.o : WallClock.cpp BaseClock.h WallClock.h
	$(CC) $(CFLAGS) -c -o WallClock.o WallClock.cpp

test_app : test_app.cpp BaseClock.h CpuClock.h RealtimeClock.h BaseClock.o CpuClock.o RealtimeClock.o WallClock.o
	$(CC) $(CFLAGS) -o test_app test_app.cpp BaseClock.o CpuClock.o RealtimeClock.o WallClock.o $(libs_req)

clean : 
	rm -f *.o test_app

