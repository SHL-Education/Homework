#include<stdio.h>
#include<string.h>

//memory move 합성어 

// 메모리의 값을 복사할 때 사용함

// memmove(목적지 ,원본, 길이); 로 사용함

//memcpy 보다 느리지만 안정적임

//memcpy는 공간에 겹치는 부분이 없을 경우 사용 = 겹치는 부분이 없다면 성능에 좋음


int main(void)
{
	char src[30] = "This is amazing";
	char *dst = src +3;
	printf("before memmove = %s\n",src);
	

	memmove(dst,src,3); // memmove(목적지 , 원본, 길이);
	printf("after memmove =%s\n",dst);

	return 0;
}

