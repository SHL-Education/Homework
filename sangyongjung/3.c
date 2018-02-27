#include <stdio.h>

int main(void)
{
    int i, n, sum;
    
    for(i = 0, n = 3, sum = 0; i <= 1000 ; i++)
       {
        if(i%n == 0)
    
        sum = sum + i;
       }
        printf("sum is %d\n", sum);
    
    return 0;
}


