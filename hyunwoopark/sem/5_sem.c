#include"sem.h"

int main(void){

	int sid;
	sid = CreateSEM(0x777);

	printf("before\n");

	p(sid);
	printf("Enter Critical Section\n");

	getchar();

	v(sid);

	printf("after\n");

	return 0;
}
