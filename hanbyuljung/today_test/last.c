void swap(int *a, int *b){

	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void){

	int num1 = 3, num2 = 7;
	swap(&num1, &num2);

	return 0;

}
