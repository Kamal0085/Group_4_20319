#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void initialize_processes(Process processes[], int n);
void copy_processes(Process destination[], Process source[], int n);
void sort_by_arrival_time(Process processes[], int n);
void print_process_table(Process processes[], int n);

#endif
