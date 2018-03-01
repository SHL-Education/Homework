#include<stdio.h>
int main(void)
{
	int l =4, h=5, res;
	res = lectanglew(l,h);
	
	printf("밑변이 %d, 높이가 %d인 삼각형의 넓이는 = %d",l,h,res);
	return 0;
}
int lectanglew(int l, int h)
{
	int res = (l*h)/2;
	return res;
}
