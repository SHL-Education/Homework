#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct __student{
	char name[10];
	int grade;
}student;


void statis(student student[])
{
	int sum=0, sum1, i;
	double average, dev = 0;
	
	for(i=0;i<5;i++)
	{
		sum += student[i].grade;
	}
	
	average = sum/5;
	
	for(i=0;i<5;i++)
	{
		sum1 = (student[i].grade-average)*(student[i].grade-average);
		dev += sum1/10;
	}
 
 	dev = sqrt(dev);	
	
	printf("합 : %d, 평균 : %f, 표준편차 : %f\n",sum, average, dev);
}

void input_grade(student student[])
{	
	int i;
	for(i=0;i<5;i++)
	{
		scanf("%s %d",student[i].name, &student[i].grade);
	}
}

void sort(student student[])
{
	int i,j,tmp1;
	char tmp[10];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{	
			if(student[j].grade < student[j+1].grade)
			{
				tmp1 = student[j+1].grade;
				student[j+1].grade = student[j].grade;
				student[j].grade = tmp1;
				strcpy(tmp, student[j+1].name);
				strcpy(student[j+1].name, student[j].name);
				strcpy(student[j].name, tmp);
			}
		}
	}
	
	printf("\n");

	for(i=0;i<5;i++)
	{
		printf("%s,%d\n", student[i].name, student[i].grade);
	}
}

int main(void)
{
	student student[5];
	
	input_grade(student);
	sort(student);	

	return 0;
}
