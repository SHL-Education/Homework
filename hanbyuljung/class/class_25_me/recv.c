#include "shm.h"

int main(void)
{
	int mid;
	SHM_t *p;

	// 쉐어드 메모리를 만들어준다. 키를 저렇게 받아서 만듬.
	// 읽어옴.
	mid = CreateSHM(0x888);
	p= GetPtrSHM(mid);

	// 엔터
	getchar();
	// 프린트를 한다.
	printf("이름 : [%s],점수 : [%d]\n", p->name, p->score);
	// 공간을 해제 한다.
	FreePtrSHM(p);
	return 0;
}
