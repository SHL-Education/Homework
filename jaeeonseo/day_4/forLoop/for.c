#include <stdio.h>

int main(void)
{
 int i, result = 'A';

 for(i=0; i < 10; i++, result++)
 {
	printf("%c\n", result);
 }

 return 0;
}

