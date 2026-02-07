#ifndef LOS_OS_H__
#define LOS_OS_H__

#include <stdarg.h>
#include <lwjos/types.h>
#include <lwjos/address.h>
#include <lwjos/assert.h>
#include <lwjos/context.h>
#include <lwjos/loader.h>
#include <lwjos/riscv.h>
#include <lwjos/sbi.h>
#include <lwjos/stack.h>
#include <lwjos/stdio.h>
#include <lwjos/string.h>
#include <lwjos/syscall.h>
#include <lwjos/task.h>

/* trap.c */
extern void trap_init();
extern void trap_handler();
extern void trap_return();
extern void set_kernel_trap_entry();

/* kerneltrap.S*/
extern void __alltraps(void);
extern void __restore(TrapContext *next);


/* switch.S */
extern void __switch(TaskContext *current_task_cx_ptr,TaskContext* next_task_cx_ptr );

/* app.c */
extern void task_init();

/* timer.c */
void sbi_set_timer(uint64_t stime_value);
void timer_init();
void set_next_trigger();
extern uint64_t get_time_us();
#endif /* __OS_H__ */