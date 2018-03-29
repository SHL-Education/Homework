#include "shm.h"

int main(void)
{

	// 메모리 아이디
	int mid;
	// 쉐어드 메모리
	SHM_t *p;

	mid = OpenSHM(0x888);
	//쉐어드 메모리의 값을 얻어와라.
	p = GetPtrSHM(mid);

	//엔터를 치면
	getchar();
	// 아무개를 얻어옴 구조체의 공간을 가져온거임.
	strcpy(p->name,"아무개");
	// 
	p->score = 93;
	// 쉐어드 메모리 다 썼으니 해제 한다.
	FreePtrSHM(p);
	return 0;
}
