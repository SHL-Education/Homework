#include<stdio.h>
void print_rom(void)
{
        int i, j;

        for(i = 2;i < 10; i++) 
        {
                for(j = 1; j < 10; j++)
                {
                        printf("%d x %d = %d\n", i, j, i * j);
                }
                
         
        }
}

int main(void)
{
        print_rom();
        return 0;
}
