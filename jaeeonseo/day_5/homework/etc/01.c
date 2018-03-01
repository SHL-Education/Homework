#include <stdio.h>

int main(void)
{
	int width;
	int height;
	int area;
	
	printf("삼각형 밑변의 길이 입력: ");
	scanf("%d", &width);

	printf("삼각형 높이의 길이 입력: ");
	scanf("%d", &height);
	
	printf("삼각형의 넓이: %d\n", width*height/2);
	

	return 0;
}
