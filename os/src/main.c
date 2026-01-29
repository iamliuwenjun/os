#include <lwjos/os.h>

extern void frame_allocator_test();
void os_main()
{
   printk("hello timer os!\n");
   
   frame_allocator_test();

   trap_init();

   task_init();

   timer_init();
   
   run_first_task();
}