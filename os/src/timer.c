#include "os.h"
#define CLOCK_FREQ 10000000 // 10MHz
#define TICKS_PER_SEC 500   // 每秒500次时钟中断


/* 设置下次时钟中断的cnt值 */
void set_next_trigger()
{
    sbi_set_timer(r_mtime() + CLOCK_FREQ / TICKS_PER_SEC);
}

/* 开启S模式下的时钟中断 */
void timer_init()
{
   reg_t sstatus =r_sstatus();
   sstatus |= (1L << 1) ;
   w_sstatus(sstatus);
   reg_t sie = r_sie();
   sie |= SIE_STIE;
   w_sie(sie);
   set_next_trigger();
}


/* 计算从系统启动到现在已经过去了多少个时间片 */
uint64_t get_time_us()
{
    reg_t time =  r_mtime() / (CLOCK_FREQ / TICKS_PER_SEC);
    return time;
}