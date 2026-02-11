#include <lwjos/types.h>
#include <lwjos/syscall.h>
#include <lwjos/string.h>

int main()
{
    int step = 0;
    while (1)
    {
       printf("test_exec:%d\n", step);
       step++;
       if(step > 1000){
            printf("exit!!!!!!!!!!!!!!!!\n");
            sys_exit(50);
       }
    }
    return 0;
}