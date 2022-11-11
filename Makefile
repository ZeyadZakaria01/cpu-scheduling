CC = g++ -g

all: scheduler custom_run

process.o: process.cpp
	$(CC) -c process.cpp

fcfs.o: fcfs.cpp
	$(CC) -c fcfs.cpp

rr.o: rr.cpp
	$(CC) -c rr.cpp

main.o: main.cpp
	$(CC) -c main.cpp

scheduler: clean main.o process.o fcfs.o rr.o
	$(CC) -o scheduler process.o fcfs.o rr.o main.o

custom_run:
	./scheduler < testcases.txt

clean:
	rm -f *.o *.out scheduler
