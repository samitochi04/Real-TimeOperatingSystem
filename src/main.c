#include <stdio.h>
#include "../include/scheduler.h"

void task1() {
    printf("Task 1 running...");
}

void task2() {
    printf("Task 2 running...");
}

int main() {
    init_scheduler();

    add_task(task1, 1); // Prioirity 1
    add_task(task2, 2); // Prioirity 2

    start_scheduler(); // start the RTOS loop


    return 0;
}
