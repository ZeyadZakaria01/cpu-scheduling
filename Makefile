CC = g++ -g

all: scheduler custom_run

process.o: process.cpp
	$(CC) -c process.cpp

fcfs.o: fcfs.cpp
	$(CC) -c fcfs.cpp

rr.o: rr.cpp
	$(CC) -c rr.cpp

spn.o: spn.cpp
	$(CC) -c spn.cpp

tracehandler.o: tracehandler.cpp
	$(CC) -c tracehandler.cpp

main.o: main.cpp
	$(CC) -c main.cpp

scheduler: clean main.o process.o fcfs.o spn.o rr.o tracehandler.o
	$(CC) -o scheduler process.o fcfs.o rr.o spn.o tracehandler.o main.o

custom_run:
	./scheduler < ./testcases/01a-input.txt

clean:
	rm -f *.o *.out scheduler
