CC = g++

.PHONY: all

all: scheduler custom_run

process.o: process.cpp process.hpp
	$(CC) -c process.cpp

fcfs.o: fcfs.cpp fcfs.hpp
	$(CC) -c fcfs.cpp

rr.o: rr.cpp rr.hpp
	$(CC) -c rr.cpp

spn.o: spn.cpp spn.hpp
	$(CC) -c spn.cpp

srt.o: srt.cpp srt.hpp
	$(CC) -c srt.cpp

aging.o: aging.cpp aging.hpp
	$(CC) -c aging.cpp

hrrn.o: hrrn.cpp hrrn.hpp
	$(CC) -c hrrn.cpp

fbi.o: fbi.cpp fbi.hpp
	$(CC) -c fbi.cpp

fb1.o: fb1.cpp fb1.hpp
	$(CC) -c fb1.cpp

utils.o: utils.cpp utils.hpp
	$(CC) -c utils.cpp

handlers: statshandler.cpp statshandler.hpp tracehandler.cpp tracehandler.hpp
	@echo Building handlers... | lolcat || @echo Building handlers...
	$(CC) -c tracehandler.cpp statshandler.cpp

main.o: main.cpp
	$(CC) -c main.cpp

scheduler: clean main.o process.o fcfs.o spn.o rr.o srt.o hrrn.o fbi.o fb1.o utils.o handlers
	@echo Building Executable... | lolcat || @echo Building Executable...
	$(CC) -o scheduler process.o fcfs.o rr.o spn.o srt.o hrrn.o fbi.o fb1.o utils.o tracehandler.o statshandler.o main.o

custom_run:
	./scheduler < testcases.txt

clean:
	@echo Cleaning... | lolcat || echo Cleaning..
	rm -f *.o *.out scheduler
