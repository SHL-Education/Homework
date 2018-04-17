#include "shm.h"
#include <stdlib.h>

int main(void)
{
	int mid;
	SHM_t *p;	

	mid = OpenSHM(0x888);	

	p = GetPtrSHM(mid);	

	getchar();
	strcpy(p->name, "josephahn");
	p->score = 90;

	FreePtrSHM(p);	

	return 0;
}
