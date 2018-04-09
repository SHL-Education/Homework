#include "scanf.h"

int my_scaf(char *buf, int size)
{
	int nr = read(0,buf, size);
	return nr;
}

