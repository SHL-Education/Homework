#include<stdio.h>
int main(void)
{

	int num;
	printf("정수를 입렬하세요:");
	scanf("%d",&num);

	if(num == 0)
		printf("입력된 수는 %d\n", num);
	else if( num > 0)
		printf("입력된 수는 양수 %d\n", num);
	else
		printf("입력된 수는 음수 %d\n", num);

	return 0;

}
