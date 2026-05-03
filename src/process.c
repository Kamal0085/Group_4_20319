#include <stdio.h>
#include "process.h"

void initialize_processes(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void copy_processes(Process destination[], Process source[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

void sort_by_arrival_time(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void print_process_table(Process processes[], int n) {
    printf("\nProcess Table:\n");
    printf("------------------------------------------------------------\n");
    printf("PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }

    printf("------------------------------------------------------------\n");
}
