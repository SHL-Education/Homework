#include "scanf.h"
//#include<stdio.h>


int my_scanf(char *buf , int size)
{
	int nr = read(0 , buf , size);
	return nr;
}

/*
int main(void)
{
	int nread;
	char buf[1024];
	int size = sizeof(buf);
	nread = my_scanf(buf, size);
	printf("%d\n", nread);

	return 0;
}
*/
