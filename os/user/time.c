#include <lwjos/os.h>

int main()
{
    uint64_t current_timer = 0;
    while (1)
    {
        current_timer = sys_gettime();
        //printf("current_timer:%x\n",current_timer);
    }   
    return 0;
}
