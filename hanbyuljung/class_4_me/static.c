#include<stdio.h>

void count_static_value(void){


	 static int count = 1;
	 printf("conut = %d\n", count);
	 count++;
}

int main(void)
{
	 int i;
	 for(i = 0; i<7;i++)
		 count_static_value();

	 printf("conut = %d\n", count);
	 return 0;
}


