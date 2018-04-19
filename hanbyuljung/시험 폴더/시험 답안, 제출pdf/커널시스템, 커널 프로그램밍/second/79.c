#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void error_label(int flag)
{
    if(flag == 1)
        longjmp(env, 1);
}

int main(void)
{
    int ret;
    int error_flag = 1;
    if(ret = setjmp(env) == 0)
        error_label(error_flag);
    else
        printf("Error\n");
    return 0;
}
