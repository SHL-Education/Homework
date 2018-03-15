#include<stdio.h>
#include<stdlib.h>



typedef struct __id_card{           
	char *name;		    	
	char *id;			
	unsigned int age;
}id_card;




typedef struct __city{ //타입 변형 가능 타입 디프          함수 변경 가능 <<define (매크로) do while

	id_card *card;
	char city[30];
}city;

int main(void)
{
	int i;
	city info = {NULL , "Seoul"};       //값을 넣어줬을 때 
	info.card = (id_card *)malloc(sizeof(id_card));
	info.card->name = "Marth Kim";
	info.card->id = "800903-1012589" ; // 이것도 문자열이므로 %s로 출력,,
	info.card->age = 33;
	printf("city = %s , name = %s , id = %s , age = %d\n", 
		info.city,info.card->name,info.card->id,info.card->age);
	printf("%c\n" , info.city[0]);  // city[0]이 가르키는 문자 s가 나와야함
	free(info.card);
	return 0;
}
