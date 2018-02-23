#include <stdio.h>
int main(){
char ch1 = 'A', ch2 = 'B',ch3 = 'C';

printf("A에 해당하는 숫자: %d\n",ch1);
printf("소문자: : %c\n",ch1^32);
printf("A-B+C : %c\n",ch1-ch2+ch3);
return 0;
}
