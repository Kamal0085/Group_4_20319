#include <stdio.h>
#include "process.h"
#include "scheduler.h"

#define MAX_PROCESSES 100

int main() {
    Process original_processes[MAX_PROCESSES];
    Process working_processes[MAX_PROCESSES];
    int n;
    int time_quantum;

    printf("CPU Scheduling Simulator\n");
    printf("Algorithms: FCFS, SJF, Round Robin\n");
    printf("------------------------------------------------------------\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes. Please enter a value from 1 to %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        original_processes[i].pid = i + 1;

        printf("\nEnter details for Process P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &original_processes[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &original_processes[i].burst_time);

        if (original_processes[i].arrival_time < 0 || original_processes[i].burst_time <= 0) {
            printf("Invalid input. Arrival time must be >= 0 and burst time must be > 0.\n");
            return 1;
        }
    }

    printf("\nEnter time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    if (time_quantum <= 0) {
        printf("Invalid time quantum. It must be greater than 0.\n");
        return 1;
    }

    initialize_processes(original_processes, n);

    copy_processes(working_processes, original_processes, n);
    run_fcfs(working_processes, n);

    copy_processes(working_processes, original_processes, n);
    run_sjf(working_processes, n);

    copy_processes(working_processes, original_processes, n);
    run_round_robin(working_processes, n, time_quantum);

    printf("\nSimulation completed successfully.\n");

    return 0;
}
