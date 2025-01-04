#include <stdio.h>
#include "../include/scheduler.h"

void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

void task3() {
    printf("Task 3 running...\n");
}

void task4() {
    printf("Task 4 running...\n");
}

void task5() {
    printf("Task 5 running...\n");
}

void task6() {
    printf("Task 6 running...\n");
}

int main() {
    init_scheduler();

    add_task(task1, 1); // Prioirity 1
    add_task(task2, 2); // Prioirity 2
    add_task(task3, 3); // Prioirity 3
    add_task(task4, 4); // Prioirity 4
    add_task(task5, 5); // Prioirity 5
    add_task(task6, 6); // Prioirity 6

    start_scheduler(); // start the RTOS loop


    return 0;
}
