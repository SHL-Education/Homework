#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main(void)
{
	int a[100]={0};
	int i;
	srand(time(NULL));
	

	for(i=0;i<100;i++){
		a[i]=rand()%4096+1;
		printf("%d ", a[i]);
		if(i%10 == 0)
			printf("\n");
	}
	printf("\n");
	return 0;
}



