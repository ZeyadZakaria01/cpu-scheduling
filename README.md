# CPU Scheduling

This project is a scheduling simulator that implements a variety of scheduling algorithms. The makefile included in this project can be used to build and run the simulator.

## Dependencies

The simulator depends on the following libraries:
* `g++`
* `diff`
## Usage

To build the simulator, run the following command:
```
make
```
This will create an executable file called scheduler. To run the simulator, use the following command:
```
./scheduler <input_file>
```
The simulator will then run the scheduling algorithm and print the output to the console.

### Example Input File

The following is an example input file that can be used to test the simulator:
```
trace
1
20
5
A,0,3
B,2,6
C,4,4
D,6,5
E,8,2
```
This input file describes five processes, each of which has a unique name, arrival time, and burst time. The first process, A, arrives at time 0 and has a burst time of 3. The second process, B, arrives at time 2 and has a burst time of 6. The third process, C, arrives at time 4 and has a burst time of 4. The fourth process, D, arrives at time 6 and has a burst time of 5. The fifth process, E, arrives at time 8 and has a burst time of 2.

The ```trace``` keyword in the first line of the input file tells the simulator to print out a trace of the scheduling decisions that are made. The other lines in the input file describe the five processes.

Additional Notes

- The ```stats``` keyword can be used to print out statistics about the scheduling decisions that are made.

## Tests

The makefile also includes a target called test_all that can be used to run the simulator on a set of test cases. To run the tests, run the following command:
```
make test_all
```
This will run the simulator on all of the test cases in the testcases directory.
## Clean

To clean up the project, run the following command:
```
make clean
```
This will remove all of the object files, the executable file, and the output file.