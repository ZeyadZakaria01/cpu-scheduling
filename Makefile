all:
	g++ main.cpp -o main && ./main < testcases/01a-input.txt

clean:
	rm -f main *.o