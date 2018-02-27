#include <stdio.h>

int main (void)
{ 
    int i, sum;  
 
    for(i = 0, sum = 0; i <= 1000; i++)
    {
        if((i%4) == 1 || (i%6) == 1)
        sum = sum + i;
    }
    printf("sum is %d\n", sum); 
    return 0;
}

