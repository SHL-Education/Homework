#include<stdio.h>

typedef struct __data{

		int val;
		struct __data *data_ref;
}data;


int main(void)
{
		int i;
		data *data_p;

		data d1 = {3,NULL};
		data d2 = {7,NULL};

		d1.data_ref = &d2;
		d2.data_ref = &d1;

		data_p = &d1;
		for(i = 1;i<=10;i++)
		{
			printf("%3d", data_p->val);
			(data_p->val)++;

			data_p = data_p->data_ref;
			if(!(i%2))
					printf("\t");
		}
		printf("\n");
		return 0;
}

				
