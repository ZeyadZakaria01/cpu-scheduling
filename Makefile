CC = g++ -g

all: scheduler custom_run

process.o: process.cpp
	$(CC) -c process.cpp

main.o: main.cpp
	$(CC) -c main.cpp

scheduler: clean main.o process.o
	$(CC) -o scheduler process.o main.o

custom_run:
	./scheduler < ./testcases/01a-input.txt

clean:
	rm -f *.o
