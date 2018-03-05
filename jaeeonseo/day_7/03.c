#include <stdio.h>

int (*aaa(void))[2]{

	static int a[2][2] = {10, };
 	printf("aaa called\n");
	return a;
}

int (*(*bbb(void))(void))[2]{
	printf("bbb called\n");
	return aaa;
}


int main(void)
{
	int (*ret)[2];
	int (*(*(*p[][2])(void))(void))[2] = {{bbb, bbb}, {bbb, bbb}};
	int (*(*(*(*p1)[2])(void))(void))[2] = p;	//함수포인터를 가리키는 함수포인터  생성(리턴고려)
	ret = (*(*(*(*p1)[2])))()();			
	
	printf("%d\n", *ret[0]);


	return 0;
}
