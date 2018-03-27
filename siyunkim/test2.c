#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void sum(int num[32],char buf[1024],int cnt,int array[32]);

void sum2(int res[10],char buf4[32]);
void myaop(char *dname);


int main(int argc, char **argv)
{	
	int flag=0;
	int s= 0,cmd;
	DIR *dp;
	struct dirent *p;
	int fd,fd2,fd3;
	int nread;
	char buf[1024];
	int i=0,j=0;
	int num[32]={-1};
	int res=0;
	int cnt=0;
	int array[32]={0};
	char buf2[32];
	char buf3[32]="\n";
	char buf4[32];
	int res2[10]={0};

	fd = open("a.txt",O_RDONLY);
	fd2= open("b.txt",O_CREAT | O_WRONLY ,0644);
	while(nread = read(fd,buf,sizeof(buf)))
	{
		for(j=0;j<10;j++)
		{
			for(i=0;buf[i];i++){

				if(buf[i]=='\n')
				{
					res2[j]+=buf[i+(j+1)];

				}
			}	
		}
		for(i=0;buf[i];i++){		
			if(buf[i]==10){

				num[j+1]=i;
				j++;
				continue;}
		}
		sum(num,buf,cnt,array);
		for(i=0;i<array[i];i++)
		{	
			sprintf(buf2,"%d",array[i]);
			write(fd2,buf2,strlen(buf2));
			write(fd2,buf3,strlen(buf3));

		}
	sum2(res2,buf4);
	}
 while((cmd = getopt(argc, argv, "alR")) > 0)
        {
                switch(cmd)
                {
                        case 'a':
                                flag |= 1 << 0;
                                myaop(".");
                                break;
		}
	}
	return 0;
}

void sum2(int res2[10],char buf4[32])
{
	int fd3;
	fd3= open(".c.txt",O_CREAT | O_WRONLY ,0644);
	int i;
	char buf5[32]="\n";
	for(i=0;i<10;i++)
	{
	sprintf(buf4,"%d",res2[i]);
	write(fd3,buf4,strlen(buf4));
	write(fd3,buf5,strlen(buf5));
	}


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

void myaop(char *dname)
{
        int s = 0,cmd;
        DIR *dp;
        struct dirent *p;


        dp=opendir(".");
        while(p=readdir(dp))
        {
                printf("%-16s",p->d_name);
                if((s+1) % 5 ==0)
                printf("\n");
                      s++;
        }
        printf("\n");
        closedir(dp);

}

