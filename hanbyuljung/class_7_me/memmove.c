#include <stdio.h>
#include <string.h>

int main(void)
{
	int i = 0;
	int src[5] = {1,2,3,4,5};
	int dst[5];

	memmove(dst, src, sizeof(src));

	for(i = 0; i<5; i++)
			printf("dst[%d] = %d \n", i, dst[i]);

	return 0;
}
