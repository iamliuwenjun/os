#ifndef LOS_RISCV_H__
#define LOS_RISCV_H__

#include "os.h"

/* 读取 sepc 寄存器的值 */
static inline reg_t r_sepc()
{
  reg_t x;
  asm volatile("csrr %0, sepc" : "=r" (x) );
  return x;
}

/* scause 记录了异常原因 */
static inline reg_t r_scause()
{
  reg_t x;
  asm volatile("csrr %0, scause" : "=r" (x) );
  return x;
}

// stval 记录了trap发生时的地址
static inline reg_t r_stval()
{
  reg_t x;
  asm volatile("csrr %0, stval" : "=r" (x) );
  return x;
}

/* sstatus记录S模式下处理器内核的运行状态*/
static inline reg_t r_sstatus()
{
  reg_t x;
  asm volatile("csrr %0, sstatus" : "=r" (x) );
  return x;
}


static inline void  w_sstatus(reg_t x)
{
  asm volatile("csrw sstatus, %0" : : "r" (x));
}

/* stvec寄存器 */
static inline void  w_stvec(reg_t x)
{
  asm volatile("csrw stvec, %0" : : "r" (x));
}

static inline reg_t r_stvec()
{
  reg_t x;
  asm volatile("csrr %0, stvec" : "=r" (x) );
  return x;
}

// Supervisor Interrupt Enable
#define SIE_SEIE (1L << 9) // external
#define SIE_STIE (1L << 5) // timer
#define SIE_SSIE (1L << 1) // software

static inline reg_t r_sie()
{
  reg_t x;
  asm volatile("csrr %0, sie" : "=r" (x) );
  return x;
}

static inline void w_sie(reg_t x)
{
  asm volatile("csrw sie, %0" : : "r" (x));
}

static inline reg_t r_mtime()
{
  reg_t x;
  asm volatile("rdtime %0" : "=r"(x));
  // asm volatime("csrr %0, 0x0C01" : "=r" (x) )
  return x;
}


// supervisor address translation and protection;
// holds the address of the page table.
static inline void w_satp(reg_t x)
{
  asm volatile("csrw satp, %0" : : "r" (x));
}

static inline reg_t r_satp()
{
  reg_t x;
  asm volatile("csrr %0, satp" : "=r" (x) );
  return x;
}

// 刷新 TLB.
static inline void sfence_vma()
{
  // the zero, zero means flush all TLB entries.
  asm volatile("sfence.vma zero, zero");
}

// M-status寄存器相关宏
#define MSTATUS_SPP (1 << 8)    // 上一次特权级（0=U-mode，1=S-mode）
#define MSTATUS_MPIE (1 << 7)   // M-mode中断使能（前）
#define MSTATUS_SPIE (1 << 5)   // S-mode中断使能（前）
#define MSTATUS_MIE (1 << 3)    // M-mode中断使能（当前）

// MIE寄存器相关宏
#define MIE_MEIE (1 << 11)      // M-mode外部中断
#define MIE_MTIE (1 << 7)       // M-mode时钟中断
#define MIE_MSIE (1 << 3)       // M-mode软件中断

// 读取/写入mstatus/mepc/mie寄存器
static inline uint64_t r_mstatus(void) {
    uint64_t val;
    asm volatile("csrr %0, mstatus" : "=r"(val));
    return val;
}

static inline void w_mstatus(uint64_t val) {
    asm volatile("csrw mstatus, %0" : : "r"(val));
}

static inline uint64_t r_mepc(void) {
    uint64_t val;
    asm volatile("csrr %0, mepc" : "=r"(val));
    return val;
}

static inline void w_mepc(uint64_t val) {
    asm volatile("csrw mepc, %0" : : "r"(val));
}

static inline uint64_t r_mie(void) {
    uint64_t val;
    asm volatile("csrr %0, mie" : "=r"(val));
    return val;
}

static inline void w_mie(uint64_t val) {
    asm volatile("csrw mie, %0" : : "r"(val));
}

#endif