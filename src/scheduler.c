#include "../include/scheduler.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define TIME_SLICE_MS 200  // 500 ms time slice

#define MAX_TASKS 10

typedef void (*TaskFunction)();

typedef struct {
    TaskFunction task;
    int priority;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
int current_task = 0;

void switch_task(int signum);

void init_scheduler() {
    task_count = 0;
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));  // Initialize struct to avoid garbage values
    sa.sa_handler = &switch_task;
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = TIME_SLICE_MS * 3000;
    timer.it_interval = timer.it_value;

    setitimer(ITIMER_REAL, &timer, NULL);
}

void add_task(TaskFunction task, int priority) {
    if (task_count < MAX_TASKS) {
        task_list[task_count].task = task;
        task_list[task_count].priority = priority;
        task_count++;
    }
}

void start_scheduler() {
    int cycles = 11;
    while (cycles--) {
        pause();  // Wait until signal (timer interrupt)
    }
    printf("Cycle of 11 schedules finished!\n");
}

void switch_task(int signum) {
    if (task_count == 0) return;

    task_list[current_task].task();
    current_task = (current_task + 1) % task_count;
}
