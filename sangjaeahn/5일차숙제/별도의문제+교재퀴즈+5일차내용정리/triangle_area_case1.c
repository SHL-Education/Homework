#include <stdio.h>

int main(void)
{
	double height,baseline,area;
	
	printf("삼각형 밑변과 높이를 차례로 입력하세요.\n");
	scanf("%lf %lf",&height,&baseline);
	
	area = height*baseline/2;

	printf("삼각형 넓이는 %lf입니다.\n", area);
	return 0;
}
