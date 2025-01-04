#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef void (*TaskFunction) ();

void init_scheduler();
void add_task(TaskFunction task, int priority);
void start_scheduler();

#endif