# CPU Scheduling Simulator

Final implementation for the CSCI 3510 Operating Systems project.
The program simulates and compares three CPU scheduling algorithms:

1. First Come First Served (FCFS)
2. Shortest Job First (SJF - non-preemptive)
3. Round Robin (RR)

## Files

- `main.c` - Handles user input and runs all scheduling algorithms.
- `Makefile` - Compiles the program.
- `process.c` - Contains helper functions for initializing, copying, sorting, and printing processes.
- `process.h` - Defines the Process structure and process-related functions.
- `sample_input.txt` - Example input for testing.
- `sample_output.txt` - Example output from the program.
- `scheduler.c` - Contains the FCFS, SJF, and Round Robin implementations.
- `scheduler.h` - Defines scheduling function declarations.





## Compile

Using Makefile:

```bash
make
```

Or manually:

```bash
gcc main.c process.c scheduler.c -o scheduler
```

## Run

```bash
./scheduler
```

## Sample Test Case

Number of processes: 4

| Process | Arrival Time | Burst Time |
|--------|--------------|------------|
| P1     | 0            | 5          |
| P2     | 1            | 3          |
| P3     | 2            | 8          |
| P4     | 3            | 6          |

Round Robin time quantum: 2

## Output Metrics

For each algorithm, the simulator displays:

- Execution order or timeline
- Completion time
- Waiting time
- Turnaround time
- Average waiting time
- Average turnaround time
