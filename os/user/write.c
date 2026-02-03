#include <lwjos/types.h>
#include <lwjos/syscall.h>
#include <lwjos/string.h>
int main()
{

    while (1)
    {
        char data = getchar();
        printf("%c",data);
    }
    return 0;
}
