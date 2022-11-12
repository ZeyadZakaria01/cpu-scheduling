CC = g++

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

tracehandler.o: tracehandler.cpp tracehandler.hpp
	$(CC) -c tracehandler.cpp

main.o: main.cpp
	$(CC) -c main.cpp

scheduler: clean main.o process.o fcfs.o spn.o rr.o srt.o tracehandler.o
	$(CC) -o scheduler process.o fcfs.o rr.o spn.o srt.o tracehandler.o main.o

custom_run:
	./scheduler < testcases.txt

clean:
	rm -f *.o *.out scheduler
