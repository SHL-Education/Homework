#include<stdio.h>
#include<stdlib.h>
typedef struct __id_card{
	char *name;
	char *id;
	unsigned int age;


}id_card;

typedef struct __city{
	id_card *card;
	char city[30];
	
}city;


int main(void){
	int i;
	city info={NULL,"seoul"};
	info.card = (id_card*)malloc(sizeof(id_card));

	info.card -> name = "MArth Kim";
	info.card -> id = "800903-1012589";
	info.card -> age = 33;

	printf("city = %s, name = %s, id = %s, age = %d\n",
					info.city, info.card->name, info.card->id, info.card->age);
	free(info.card);

	return 0;
}
