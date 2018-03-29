#include "sem.h"

int main(void)
{
	int sid=-1;
	// 키 값을 지정한다.
	sid = CreateSEM(0x777);

	printf("before\n");
	printf("%d\n",sid);
	p(sid);
	printf("Enter Critical Section\n");
	getchar();
	v(sid);
	printf("after\n");
	return 0;
}
