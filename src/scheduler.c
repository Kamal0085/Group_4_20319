#include <stdio.h>
#include <limits.h>
#include "scheduler.h"
#include "process.h"

static void calculate_metrics(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }
    }
}

void print_average_metrics(Process processes[], int n) {
    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void run_fcfs(Process processes[], int n) {
    sort_by_arrival_time(processes, n);

    int current_time = 0;

    printf("\n================ FCFS Scheduling ================\n");
    printf("Execution Order: ");

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        printf("P%d", processes[i].pid);
        if (i != n - 1) {
            printf(" -> ");
        }

        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;
    }

    printf("\n");
    calculate_metrics(processes, n);
    print_process_table(processes, n);
    print_average_metrics(processes, n);
}

void run_sjf(Process processes[], int n) {
    int completed = 0;
    int current_time = 0;
    int is_completed[n];

    for (int i = 0; i < n; i++) {
        is_completed[i] = 0;
    }

    printf("\n================ SJF Scheduling ================\n");
    printf("Execution Order: ");

    while (completed < n) {
        int selected_index = -1;
        int shortest_burst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !is_completed[i]) {
                if (processes[i].burst_time < shortest_burst) {
                    shortest_burst = processes[i].burst_time;
                    selected_index = i;
                }
                else if (processes[i].burst_time == shortest_burst) {
                    if (processes[i].arrival_time < processes[selected_index].arrival_time) {
                        selected_index = i;
                    }
                }
            }
        }

        if (selected_index == -1) {
            current_time++;
            continue;
        }

        printf("P%d", processes[selected_index].pid);
        completed++;
        if (completed != n) {
            printf(" -> ");
        }

        current_time += processes[selected_index].burst_time;
        processes[selected_index].completion_time = current_time;
        is_completed[selected_index] = 1;
    }

    printf("\n");
    calculate_metrics(processes, n);
    print_process_table(processes, n);
    print_average_metrics(processes, n);
}

void run_round_robin(Process processes[], int n, int time_quantum) {
    int completed = 0;
    int current_time = 0;
    int queue[1000];
    int front = 0;
    int rear = 0;
    int in_queue[n];
    int is_completed[n];

    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        in_queue[i] = 0;
        is_completed[i] = 0;
    }

    printf("\n================ Round Robin Scheduling ================\n");
    printf("Time Quantum: %d\n", time_quantum);
    printf("Execution Timeline: ");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !in_queue[i] && !is_completed[i]) {
                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        if (front == rear) {
            current_time++;
            continue;
        }

        int current_index = queue[front++];
        in_queue[current_index] = 0;

        int execution_time;
        if (processes[current_index].remaining_time > time_quantum) {
            execution_time = time_quantum;
        } else {
            execution_time = processes[current_index].remaining_time;
        }

        printf("P%d(%d-%d)", processes[current_index].pid, current_time, current_time + execution_time);

        current_time += execution_time;
        processes[current_index].remaining_time -= execution_time;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !in_queue[i] && !is_completed[i] && i != current_index) {
                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        if (processes[current_index].remaining_time > 0) {
            queue[rear++] = current_index;
            in_queue[current_index] = 1;
        } else {
            processes[current_index].completion_time = current_time;
            is_completed[current_index] = 1;
            completed++;
        }

        if (completed != n) {
            printf(" -> ");
        }
    }

    printf("\n");
    calculate_metrics(processes, n);
    print_process_table(processes, n);
    print_average_metrics(processes, n);
}
