CC = g++ -g

all: scheduler custom_run

process.o: process.cpp
	$(CC) -c process.cpp

fcfs.o: fcfs.cpp
	$(CC) -c fcfs.cpp

main.o: main.cpp
	$(CC) -c main.cpp

scheduler: clean main.o process.o fcfs.o
	$(CC) -o scheduler process.o fcfs.o main.o

custom_run:
	./scheduler < ./testcases/01a-input.txt

clean:
	rm -f *.o *.out scheduler
