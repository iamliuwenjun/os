#ifndef LOS_STACK_H__
#define LOS_STACK_H__

#include "os.h"

#define MAX_SIZE 10000

typedef struct {
    uint64_t data[MAX_SIZE];
    int top;    // 不能定义成无符号类型，不然会导致 -1 > 0
} Stack;

bool isEmpty(Stack *stack);
bool isFull(Stack *stack);
void push(Stack *stack, uint64_t value);
uint64_t pop(Stack *stack);
uint64_t top(Stack *stack);

#endif