#include <messages.h>
#include <arch/memory.h>
#include <arch/idt.h>
#include <arch/pic.h>
#include <sched/task.h>
#include <tasks/tty.h>
#include <tasks/init.h>
#include <utils/kprint.h>

/*
 * Kernel entry point
 */
void kernel_start(void)
{
    /* init kernel */
	kclear();
    idt_init();
    pic_enable();
	kprint(MSG_KERNEL_START);

	/* create kernel tasks */
    sched_create_task(TID_INIT, task_init);
    sched_create_task(TID_TTY, task_tty);

    /* run kernel tasks */
    sched_run_task_by_id(TID_TTY);
    sched_run_task_by_id(TID_INIT);

    /* should never return */
	while(1);
}

