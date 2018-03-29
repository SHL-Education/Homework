#include "scanf.h"

int main(void)
{
	int nread;
	char buf[1024];
	int size = sizeof(buf);
	nread = my_scanf(buf,size);
	printf("%d\n",nread);
	

	return 0;
}
