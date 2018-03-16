#include <stdio.h>
#include <string.h>

int find_letter(char *arr, int start)
{	
	char src[11] = "Safety MCU";
	
	if(!strncmp(arr+start,src,10))
		return start+1;	
}

int find_S(char *arr)
{
	int i=0;

	while(*(arr+i) != 'S')
		i++;
	
	return i;
}


int main(void)
{
	char *arr = "TI Cortex-R5F Safety MCU is very good to Real-Time System";
	
	printf("%d\n", find_letter(arr,(find_S(arr))));
	return 0;
}
