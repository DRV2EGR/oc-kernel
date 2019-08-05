#pragma once

#include <lib/stdtypes.h>
#include <sched/task.h>

#define TASK_QUOTA 18

/*
 * Api
 */
extern void sched_init();
extern void sched_schedule(size_t *ret_addr, size_t *reg_addr);
extern struct sched_task *sched_get_current_task();
extern void sched_yield();
