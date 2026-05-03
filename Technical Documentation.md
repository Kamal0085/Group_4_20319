# Technical Documentation

## Project Title

**Modeling and Comparing Basic Scheduling Algorithms**

## Project Overview

This project is a simple CPU Scheduling Simulator created for the CSCI 3510 Principles of Operating Systems course. The program simulates three basic CPU scheduling algorithms:

1. First Come First Served (FCFS)
2. Shortest Job First (SJF)
3. Round Robin (RR)

The goal of the project is to show how different scheduling algorithms affect process execution order, waiting time, turnaround time, and overall performance.

---

## Implementation Explanation

The project is implemented in the C programming language. The simulator takes process information from the user, including arrival time and burst time. For Round Robin, the user also enters a time quantum.

After receiving the input, the program runs the same set of processes through three scheduling algorithms. Each algorithm calculates the completion time, waiting time, turnaround time, average waiting time, and average turnaround time.

### FCFS Algorithm

FCFS stands for First Come First Served. In this algorithm, processes are executed in the order they arrive. The process that arrives first gets the CPU first.

This algorithm is simple and easy to understand, but it may cause long waiting times if a process with a long burst time arrives before shorter processes.

### SJF Algorithm

SJF stands for Shortest Job First. In this project, the non-preemptive version of SJF is used. The algorithm selects the available process with the shortest burst time.

SJF can reduce average waiting time compared to FCFS, but it may not always be fair to longer processes.

### Round Robin Algorithm

Round Robin gives each process a fixed amount of CPU time called a time quantum. If a process does not finish within its time quantum, it goes back to the queue and waits for another turn.

Round Robin is fair because each process gets CPU time in turns. However, the performance depends on the selected time quantum.

---

## Code Structure

The project is divided into multiple files to keep the code organized and easier to understand.

### `main.c`

This is the main file of the program. It handles user input and runs the scheduling algorithms.

Main responsibilities:

- Ask the user for the number of processes
- Read arrival time and burst time for each process
- Read the time quantum for Round Robin
- Call FCFS, SJF, and Round Robin functions
- Display the final results

### `process.h`

This header file defines the `Process` structure and declares process-related functions.

The `Process` structure stores:

- Process ID
- Arrival time
- Burst time
- Remaining time
- Completion time
- Waiting time
- Turnaround time

### `process.c`

This file contains helper functions for process handling.

Main responsibilities:

- Initialize process values
- Copy process data before each algorithm runs
- Sort processes by arrival time
- Print the process result table

### `scheduler.h`

This header file declares the scheduling functions used in the program.

It includes function declarations for:

- FCFS scheduling
- SJF scheduling
- Round Robin scheduling
- Average metric calculation

### `scheduler.c`

This file contains the main scheduling logic.

Main responsibilities:

- Implement FCFS
- Implement SJF
- Implement Round Robin
- Calculate waiting time
- Calculate turnaround time
- Print average waiting time and average turnaround time

### `Makefile`

The Makefile is used to compile the program more easily. Instead of typing the full `gcc` command every time, the user can simply type:

```bash
make
```

### `sample_input.txt`

This file contains sample input that can be used to test the program.

### `sample_output.txt`

This file contains example output from the simulator.

---

## Instructions for Execution

## Step 1: Open the Project Folder

Open a terminal and go to the folder where the source code files are located.

Example:

```bash
cd Team4_Phase2
```

## Step 2: Compile the Program

If `make` is available, compile the program using:

```bash
make
```

This will create an executable file named:

```bash
scheduler
```

If `make` is not available, compile manually using:

```bash
gcc main.c process.c scheduler.c -o scheduler
```

## Step 3: Run the Program

After compiling, run the program using:

```bash
./scheduler
```

On Windows, the command may be:

```bash
scheduler.exe
```

## Step 4: Enter Input

The program will ask for:

1. Number of processes
2. Arrival time for each process
3. Burst time for each process
4. Time quantum for Round Robin

Example input:

```text
Enter number of processes: 4

Enter details for Process P1
Arrival Time: 0
Burst Time: 5

Enter details for Process P2
Arrival Time: 1
Burst Time: 3

Enter details for Process P3
Arrival Time: 2
Burst Time: 8

Enter details for Process P4
Arrival Time: 3
Burst Time: 6

Enter time quantum for Round Robin: 2
```

## Step 5: Read the Output

The program displays results for each algorithm. The output includes:

- Execution order or execution timeline
- Completion time
- Waiting time
- Turnaround time
- Average waiting time
- Average turnaround time

---

## Sample Test Case

| Process | Arrival Time | Burst Time |
|--------|--------------|------------|
| P1 | 0 | 5 |
| P2 | 1 | 3 |
| P3 | 2 | 8 |
| P4 | 3 | 6 |

Time Quantum for Round Robin: `2`

---

## Expected Results

For the sample test case, the simulator produces the following average results:

| Algorithm | Average Waiting Time | Average Turnaround Time |
|----------|----------------------|--------------------------|
| FCFS | 5.75 | 11.25 |
| SJF | 5.25 | 10.75 |
| Round Robin | 9.75 | 15.25 |

Based on this test case, SJF performs the best because it has the lowest average waiting time and average turnaround time.

---

## Notes About the Implementation

- The project uses a simple command-line interface.
- The project is a simplified simulation of CPU scheduling concepts.
- The code is separated into multiple files for better organization.
- Comments are included in the code to make the logic easier to understand.

---

## Conclusion

This implementation successfully simulates FCFS, SJF, and Round Robin scheduling algorithms. It allows users to enter process data and compare how each algorithm performs. The project demonstrates basic CPU scheduling concepts in a simple and understandable way.
