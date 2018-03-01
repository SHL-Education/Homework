#include <stdio.h>

int main(void)
{


  int global_area = 1;

	 {

	    int local_area1 = 2;
	    printf("global_area = %d\n", global_area);
	    printf("global_area1 = %d\n", local_area1);
	 } //=> 스택프레임 해제

	{

	    int local_area2 = 3;
	    printf("global_area = %d\n", global_area);
	    printf("global_area1 = %d\n", local_area2);
	} //=> 스택프레임 해제

	printf("global_area = %d\n", global_area);
 	//printf("local_area1 = %d\n", local_area1); => 스택프레임 해제로 local_area1는 존재X
	//printf("local_area1 = %d\n", local_area2); => 스택프레임 해제 local_area1는 존재X

	return 0;
}

