#include<stdio.h>
#include<string.h>


int main(void)
{
	char src[30] = "This is amazing";
	char *dst = src +3;

	printf("before memmove = %s\n",src);
	memcpy(dst, src, 3);
	printf("after memmove = %s\n", dst);
	return 0;
}
