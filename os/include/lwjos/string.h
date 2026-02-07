#ifndef LOS_STRING_H__
#define LOS_STRING_H__

#include <lwjos/os.h>
size_t strlen(const char *str);
void* memcpy(void *dest, const void *src, size_t count);
void* memset(void *dest, int ch, size_t count);
int strcmp(const char *lhs, const char *rhs);

#endif