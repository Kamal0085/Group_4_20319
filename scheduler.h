#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

void run_fcfs(Process processes[], int n);
void run_sjf(Process processes[], int n);
void run_round_robin(Process processes[], int n, int time_quantum);
void print_average_metrics(Process processes[], int n);

#endif
