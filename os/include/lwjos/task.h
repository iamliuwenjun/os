#ifndef LOS_TASK_H__
#define LOS_TASK_H__

#include <lwjos/os.h>

typedef enum TaskState
{
	UnInit, // 未初始化
    Ready, // 准备运行
    Running, // 正在运行
    Exited, // 已退出
}TaskState;

typedef struct TaskControlBlock
{
    TaskState task_state;       //任务状态
    TaskContext task_context;   //任务上下文
    u64 trap_cx_ppn;            //Trap 上下文所在物理地址
    u64  base_size;             //应用数据大小
    u64  kstack;                //应用内核栈的虚拟地址
    u64  ustack;                //应用用户栈的虚拟地址
    u64  entry;                 //应用程序入口地址
    PageTable pagetable;        //应用页表所在物理页
}TaskControlBlock;

/* 映射用户程序内核栈 */
void proc_mapstacks(PageTable* kpgtbl);


#endif
