#include<stdio.h>

#define NAME_LEN	30
#define ID_LEN 		15

typedef struct __id_card{

		char name[NAME_LEN];
		char id[ID_LEN];
		unsigned int age;

}id_card;




int main(void)
{

		int i;
		id_card arr[2]={
			{"Marth kim", "800903-1012589",34},
			{"July Eun","830708-1023417",31}
		};
		for(i=0;i <2;i++)
		{
				printf("name= %s, id= %s, age = %d\n", arr[i].name, arr[i].id, arr[i].age);
		}

	return 0;

}

