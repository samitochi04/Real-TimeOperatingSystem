#include "../include/scheduler.h"
#include <stdio.h>

#define MAX_TASKS 5

typedef struct {
    TaskFunction task;
    int priority;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void init_scheduler() {
    task_count = 0;
}

void add_task(TaskFunction task, int priority) {
    if (task_count < MAX_TASKS) {
        task_list[task_count].task = task;
        task_list[task_count].priority = priority;
        task_count++;
    }
}

void start_scheduler() {
    while (1) {
        for (int i = 0; i < task_count; i++) {
            task_list[i].task();
        }
    }
}