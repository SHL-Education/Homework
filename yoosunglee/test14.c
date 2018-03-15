#include<stdio.h>
#include<malloc.h>

//이 헤더 파일은,동적 메모리 할당 라이브러리를 포함,
     
// malloc은 무엇을 하는가 ? Memory 구조상 heap에 data를 할당함
// data가 계속해서 들어올 경우 얼만큼의 data가 들어오는지 알 수 없음
// 들어올 때마다 동적으로 할당할 필요가 있음..
    
//free() 는 무엇을 하는가 ?
// memory 구조상 heap에 data 할당을 해제함 



int main(void){

	char *str_ptr = (char *)malloc(sizeof(char) * 20);
	
	printf("Input String:");
	scanf("%s",str_ptr);

	if(str_ptr != NULL)
		printf("string = %s\n" , str_ptr);
	
	free(str_ptr);

	return 0;
}

