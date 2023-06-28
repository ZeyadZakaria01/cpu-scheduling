CC = g++


cmake-build:
	@echo "Start Building..."
	@cd "./build/" && make 1> /dev/null 2> /dev/null # redirect stdout and stderr to /dev/null
	@cp ./build/lab4 ./lab4
	@echo "Success!"


test_all: cmake-build 
	@echo "Start Testing..."
	cat ./testcases/01a-input.txt | ./lab4 | diff ./testcases/01a-output.txt -
	cat ./testcases/01b-input.txt | ./lab4 | diff ./testcases/01b-output.txt -
	cat ./testcases/02a-input.txt | ./lab4 | diff ./testcases/02a-output.txt -
	cat ./testcases/02b-input.txt | ./lab4 | diff ./testcases/02b-output.txt -
	cat ./testcases/03a-input.txt | ./lab4 | diff ./testcases/03a-output.txt -
	cat ./testcases/03b-input.txt | ./lab4 | diff ./testcases/03b-output.txt -
	cat ./testcases/04a-input.txt | ./lab4 | diff ./testcases/04a-output.txt -
	cat ./testcases/04b-input.txt | ./lab4 | diff ./testcases/04b-output.txt -
	cat ./testcases/05a-input.txt | ./lab4 | diff ./testcases/05a-output.txt -
	cat ./testcases/05b-input.txt | ./lab4 | diff ./testcases/05b-output.txt -
	cat ./testcases/06a-input.txt | ./lab4 | diff ./testcases/06a-output.txt -
	cat ./testcases/06b-input.txt | ./lab4 | diff ./testcases/06b-output.txt -
	cat ./testcases/07a-input.txt | ./lab4 | diff ./testcases/07a-output.txt -
	cat ./testcases/07b-input.txt | ./lab4 | diff ./testcases/07b-output.txt -
	cat ./testcases/08a-input.txt | ./lab4 | diff ./testcases/08a-output.txt -
	cat ./testcases/08b-input.txt | ./lab4 | diff ./testcases/08b-output.txt -
	cat ./testcases/09a-input.txt | ./lab4 | diff ./testcases/09a-output.txt -
	cat ./testcases/09b-input.txt | ./lab4 | diff ./testcases/09b-output.txt -
	cat ./testcases/10a-input.txt | ./lab4 | diff ./testcases/10a-output.txt -
	cat ./testcases/10b-input.txt | ./lab4 | diff ./testcases/10b-output.txt -
	cat ./testcases/11a-input.txt | ./lab4 | diff ./testcases/11a-output.txt -
	cat ./testcases/12a-input.txt | ./lab4 | diff ./testcases/12a-output.txt -
	@echo "Success!"

test_new_all: cmake-build 
	@echo "Start Testing..."
	cat ./lab4-new-testcases/01a-input.txt | ./lab4 | diff ./lab4-new-testcases/01a-output.txt -
	cat ./lab4-new-testcases/01b-input.txt | ./lab4 | diff ./lab4-new-testcases/01b-output.txt -
	cat ./lab4-new-testcases/02a-input.txt | ./lab4 | diff ./lab4-new-testcases/02a-output.txt -
	cat ./lab4-new-testcases/02b-input.txt | ./lab4 | diff ./lab4-new-testcases/02b-output.txt -
	cat ./lab4-new-testcases/03a-input.txt | ./lab4 | diff ./lab4-new-testcases/03a-output.txt -
	cat ./lab4-new-testcases/03b-input.txt | ./lab4 | diff ./lab4-new-testcases/03b-output.txt -
	cat ./lab4-new-testcases/04a-input.txt | ./lab4 | diff ./lab4-new-testcases/04a-output.txt -
	cat ./lab4-new-testcases/04b-input.txt | ./lab4 | diff ./lab4-new-testcases/04b-output.txt -
	cat ./lab4-new-testcases/05a-input.txt | ./lab4 | diff ./lab4-new-testcases/05a-output.txt -
	cat ./lab4-new-testcases/05b-input.txt | ./lab4 | diff ./lab4-new-testcases/05b-output.txt -
	cat ./lab4-new-testcases/06a-input.txt | ./lab4 | diff ./lab4-new-testcases/06a-output.txt -
	cat ./lab4-new-testcases/06b-input.txt | ./lab4 | diff ./lab4-new-testcases/06b-output.txt -
	cat ./lab4-new-testcases/07a-input.txt | ./lab4 | diff ./lab4-new-testcases/07a-output.txt -
	cat ./lab4-new-testcases/07b-input.txt | ./lab4 | diff ./lab4-new-testcases/07b-output.txt -
	@echo "Success!"

clean:
	@echo Cleaning... 
	rm -f *.o *.out scheduler lab4
