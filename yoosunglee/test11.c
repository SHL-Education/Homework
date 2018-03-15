#include<stdio.h>

typedef int INT[5];

// typedef는 무엇인가 자료형에 새로운 이름을 부여하고자 할 때,,
// 주로 구조체나 함수 포인터에 사용함...

int main(void){

	int i;
	INT arr = {1,2,3,4,5};
	for(i= 0 ; i <5; i++){

		printf(" arr[%d] = %d\n",i,arr[i]);

	}

	return 0;
}
