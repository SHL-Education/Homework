#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void sum(int num[32],char buf[1024],int cnt,int array[32]);

int main(int argc, char **argv)
{
	int fd,fd2;
	int nread;
	char buf[1024];
	int i=0,j=0;
	int num[32]={-1};
	int res=0;
	int cnt=0;
	int array[32]={0};
	char buf2[32];

	fd = open("a.txt",O_RDONLY);
	fd2= open("b.txt",O_CREAT | O_WRONLY ,0644);
	while(nread = read(fd,buf,sizeof(buf)))
	{
		for(i=0;buf[i];i++){
			
			 if(buf[i]==10){
			
				num[j+1]=i;
				j++;
			continue;}
					}
				sum(num,buf,cnt,array);
				for(i=0;i<array[i];i++)
				{
				printf("array= %d \n",array[i]);
				sprintf(buf2,"%d",array[i]);
				write(fd2,buf2,strlen(buf2));
				}

	}
	return 0;
}

void sum(int num[32],char buf[1024],int cnt,int array[32])
{
	int j=0;
	int res=0;
		for(cnt=0;cnt<7;cnt++)
		{
			for(j=(num[cnt]+1);j<num[cnt+1];j++)
			{
				res += buf[j];
			}
				array[cnt]=res;
				res=0;
								}

}
