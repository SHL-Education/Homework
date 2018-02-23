#include <stdio.h>

int main(void)
{
	int num;
	printf("상담은 1, 사용 내역 조회는 2, 계약 해지는 3을 눌러주세요: ");
	scanf("%d", &num);

	switch(num)
	{
		case 1:
			printf("상담 센터에 연결중입니다.\n");
			break;
		case 2:
			printf("상담 내역을 조회합니다.\n");
			break;
		case 3:
			printf("계약 해지를 진행합니다.\n");
			break;
		default:
			printf("번호를 잘 못 누르셨습니다.\n");

	}

	return 0;

}
