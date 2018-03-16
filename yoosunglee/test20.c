#include<stdio.h>

//구조체안의 값들을 변경,


typedef struct __data{

	int val;
	struct __data *data_ref;
}data;

int main(void)
{

	int i;
	data *data_p;  //data_p 라는 이름의 껍데기 아직 안생김 값을 넣어줘야 , ,메모리에 공간도 x

	data d1 = {3,NULL};
	data d2 = {7,NULL};

	d1.data_ref = &d2;
	d2.data_ref = &d1;

	data_p = &d1;// 이제 껍데기 생김 , 메모리에 공간도 할당,
	for(i =1; i <= 10 ; ,i++){

		printf("%3d" , data_p->val);
		(data_p->val)++;
		data_p = data_p->data_ref;
		if(!(i%2))
			printf("\t");

	}
	printf("\n");
	return 0 ;
}

