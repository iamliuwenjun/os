#include <lwjos/os.h>

int main()
{
    // 在父进程中创建子进程
    int pid = sys_fork();
    while (1)
    {
       if(pid > 0)
       {
            printf("father\n");
       }
       else if(pid == 0)
       {
            printf("child\n");
       }
       else
       {
            //失败
       }
    }
    
    return 0;
}
