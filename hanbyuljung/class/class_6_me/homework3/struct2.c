#include<stdio.h>

typedef struct __id_card{
	char name[30];
	char id [15];
	unsigned int age;


}id_card;

typedef struct __city{
	id_card card;
	char city[30];
	
}city;


int main(void){
	int i;
	city info={{"Marth Kim ", "800903-1012589",34},"seoul"};

	printf("city = %s, name = %s, id = %s, age = %d\n",info.city, info.card.name,
					info.card.id, info.card.age);

	return 0;
}
