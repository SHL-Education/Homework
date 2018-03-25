#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


void recursive_dir(char *dname);
void recursive_dir2(char *dname);
void mylR(char *dname);
void myaop(char *dname);
void nonop(char *dname);
void loption(char *dname);
void aloption(char *dname);
void myalR(char *dname);

void check_flag(int flag)
{
	int tmp = flag | flag;
	int t= flag | (~(flag));
		switch(tmp & t)
		{	
			

			case 1:
			
			printf("myls a option\n");
			myaop(".");
				break;
			case 2:
				printf("my l option\n");
				loption(".");	
				break;
			case 3:
				printf("my al option\n");
                                aloption(".");
				break;
			case 4:
				printf("myls R option\n");
				recursive_dir2(".");
				break;
			case 5:
				printf("myls aR option\n");
				recursive_dir(".");
				break;
			case 6:
				printf("my lR option\n");
				mylR(".");
				break;
			case 7:
				printf("alR\n");
				myalR(".");
				break;
			default :
				printf("nonoption\n");
				nonop(".");
				break;


		}
}

int main(int argc, char **argv)
{
	int i;
	int flag=0;
	int s = 0,cmd;
	DIR *dp;
	struct dirent *p;
	char name[1024];

	/* 7 개의 옵션: a, b, c, d, e, f, g */
	while((cmd = getopt(argc, argv, "alR")) > 0)
	{
		switch(cmd)
		{
			case 'a':
				flag |= 1 << 0;
				//printf("a option\n");
				break;
			case 'l':
				flag |= 1 << 1;
				//printf("b option\n");
				break;
			case 'R':
				flag |= 1 << 2;
				//printf("c option\n");
				break;
		}		
	}

	check_flag(flag);
      
	return 0;
}


void aloption(char *dname)
{
        struct stat buf;
        struct dirent *p;
        struct passwd *pw;
        struct group *gr;
        struct tm *tm;
        char ch;
        char perm[11] = "----------";
        char rwx[4] = "rwx";
        char sst[4]= "sst";
        int i;
        DIR *dp;

        dp = opendir(".");
        while(p= readdir(dp))
        {
                stat((p->d_name),&buf);
                if(S_ISDIR(buf.st_mode))
                perm[0]='d';
                if(S_ISREG(buf.st_mode))
                perm[0]='-';
                if(S_ISFIFO(buf.st_mode))
                perm[0]='p';
                if(S_ISSOCK(buf.st_mode))
                perm[0]='s';
                if(S_ISCHR(buf.st_mode))
                perm[0]='c';
                if(S_ISBLK(buf.st_mode))
                perm[0]='b';
                for(i=0;i<9;i++)
                if((buf.st_mode >> (8-i))&1)
                perm[i+1]=rwx[i%3];
                for(i=0;i<3;i++)
                if((buf.st_mode >> (11-i))&1)
                if(perm[(i+1)*3]=='-')
                perm[(i+1)*3]=sst[i]^0x20;
                else
                perm[(i+1)*3]=sst[i];
                printf("%s  ",perm);
                printf("%ld  ",buf.st_nlink);
                pw=getpwuid(buf.st_uid);
                printf("%s  ",pw->pw_name);
                gr=getgrgid(buf.st_gid);
                printf("%s  ",gr->gr_name);
                printf("%ld  ",buf.st_size);
                tm=localtime(&buf.st_mtime);
                printf("%d - %02d - %02d  %02d : %02d :",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);

                printf("%-16s", p->d_name);
                if((i+1) %1 ==0)
                printf("\n");
                   i++;
                }
                printf("\n");
    closedir(dp);

}


void loption(char *dname)
{	
	struct stat buf;
	struct dirent *p;
        struct passwd *pw;
        struct group *gr;
        struct tm *tm;
        char ch;
        char perm[11] = "----------";
        char rwx[4] = "rwx";
        char sst[4]= "sst";
        int i;
	DIR *dp;
	
	dp = opendir(".");
	while(p= readdir(dp))
        {
        	if(p->d_name[0]=='.')
                continue;
                stat((p->d_name),&buf);
                if(S_ISDIR(buf.st_mode))
                perm[0]='d';
                if(S_ISREG(buf.st_mode))
                perm[0]='-';
                if(S_ISFIFO(buf.st_mode))
                perm[0]='p';
                if(S_ISSOCK(buf.st_mode))
                perm[0]='s';
                if(S_ISCHR(buf.st_mode))
                perm[0]='c';
                if(S_ISBLK(buf.st_mode))
                perm[0]='b';
                for(i=0;i<9;i++)
                if((buf.st_mode >> (8-i))&1)
                perm[i+1]=rwx[i%3];
                for(i=0;i<3;i++)
                if((buf.st_mode >> (11-i))&1)
                if(perm[(i+1)*3]=='-')
                perm[(i+1)*3]=sst[i]^0x20;
                else
                perm[(i+1)*3]=sst[i];
                printf("%s  ",perm);
                printf("%ld  ",buf.st_nlink);
                pw=getpwuid(buf.st_uid);
                printf("%s  ",pw->pw_name);
                gr=getgrgid(buf.st_gid);
                printf("%s  ",gr->gr_name);
                printf("%ld  ",buf.st_size);
                tm=localtime(&buf.st_mtime);
                printf("%d - %02d - %02d  %02d : %02d :",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);

                printf("%-16s", p->d_name);
                if((i+1) %1 ==0)
                printf("\n");
                   i++;
                }
                printf("\n");
    closedir(dp);

}

void nonop(char *dname)
{
        int s = 0,cmd;
        DIR *dp;
        struct dirent *p;


        dp=opendir(".");
        while(p=readdir(dp))
        {	
		if(p->d_name[0]=='.')
                    continue;

                printf("%-16s",p->d_name);
                if((s+1) % 5 ==0)
                printf("\n");
                      s++;
        }
        printf("\n");
        closedir(dp);

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

void recursive_dir(char *dname)
{
        struct dirent *p;
        struct stat buf;
        DIR *dp;
	int i;
        chdir(dname);
        dp = opendir(".");
        printf("\t%s : \n",dname);
        while(p= readdir(dp)){
        printf("%s\t",p->d_name);
	if((i+1) %3 ==0)
          printf("\n");
             i++;
}
	printf("\n");
        rewinddir(dp);
        while(p=readdir(dp))
        {
        stat(p->d_name,&buf);
        if(S_ISDIR(buf.st_mode))
        if(strcmp(p->d_name,".")&&strcmp(p->d_name,".."))
        recursive_dir(p->d_name);
        }
        chdir("..");
        closedir(dp);
        }


void recursive_dir2(char *dname)
{
        struct dirent *p;
        struct stat buf;
        DIR *dp;
	int i;
        chdir(dname);
        dp = opendir(".");
        printf("\t%s : \n",dname);
        while(p= readdir(dp))
	{if(p->d_name[0]=='.')
          continue;

        printf("%s\t",p->d_name);
	 if((i+1) %3 ==0)
          printf("\n");
             i++;
	}
	printf("\n");
        rewinddir(dp);
        while(p=readdir(dp))
        {

        stat(p->d_name,&buf);
        if(S_ISDIR(buf.st_mode))
        if(strcmp(p->d_name,".")&&strcmp(p->d_name,".."))
        recursive_dir2(p->d_name);
        }
        chdir("..");
        closedir(dp);
}


void mylR(char *dname)
{
        struct dirent *p;
        struct stat buf;
        DIR *dp;
        int i;
	struct passwd *pw;
	struct group *gr;
	struct tm *tm;
	char ch;
	char perm[11]="----------";
	char rwx[4]="rwx";
	char sst[4]="sst";
	
        chdir(dname);
        dp = opendir(".");
        printf("\t%s : \n",dname);
        while(p= readdir(dp))
        {if(p->d_name[0]=='.')
          continue;
	stat((p->d_name),&buf);

	if(S_ISDIR(buf.st_mode))
	perm[0]='d';
	if(S_ISREG(buf.st_mode))
	perm[0]='-';
	if(S_ISFIFO(buf.st_mode))
	perm[0]='p';
	if(S_ISSOCK(buf.st_mode))
	perm[0]='s';
	if(S_ISCHR(buf.st_mode))
	perm[0]='c';
	if(S_ISBLK(buf.st_mode))
	perm[0]='b';
			
	for(i=0;i<9;i++)
	if((buf.st_mode >> (8-i))&1)
	perm[i+1]=rwx[i%3];
	for(i=0;i<3;i++)
	if((buf.st_mode >> (11-i))&1)
	if(perm[(i+1)*3]=='-')
	perm[(i+1)*3]=sst[i]^0x20;
	else
	perm[(i+1)*3]=sst[i];

	printf("%s  ",perm);
	printf("%ld  ",buf.st_nlink);
	pw=getpwuid(buf.st_uid);
	printf("%s  ",pw->pw_name);
	gr=getgrgid(buf.st_gid);
	printf("%s  ",gr->gr_name);
	printf("%ld  ",buf.st_size);
	tm=localtime(&buf.st_mtime);
	printf("%d - %02d - %02d  %02d : %02d :",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);
        printf("%-16s\t",p->d_name);
         if((i+1) %1 ==0)
          printf("\n");
             i++;
        }
        printf("\n");
        rewinddir(dp);
        while(p=readdir(dp))
        {

        stat(p->d_name,&buf);
        if(S_ISDIR(buf.st_mode))
        if(strcmp(p->d_name,".")&&strcmp(p->d_name,".."))
        mylR(p->d_name);
        }
        chdir("..");
        closedir(dp);
}

void myalR(char *dname)
{
        struct dirent *p;
        struct stat buf;
        DIR *dp;
        int i;
        struct passwd *pw;
        struct group *gr;
        struct tm *tm;
        char ch;
        char perm[11]="----------";
        char rwx[4]="rwx";
        char sst[4]="sst";

        chdir(dname);
        dp = opendir(".");
        printf("\t%s : \n",dname);
        while(p= readdir(dp))
        {
        
        stat((p->d_name),&buf);

        if(S_ISDIR(buf.st_mode))
        perm[0]='d';
        if(S_ISREG(buf.st_mode))
        perm[0]='-';
        if(S_ISFIFO(buf.st_mode))
        perm[0]='p';
        if(S_ISSOCK(buf.st_mode))
        perm[0]='s';
        if(S_ISCHR(buf.st_mode))
        perm[0]='c';
        if(S_ISBLK(buf.st_mode))
        perm[0]='b';

        for(i=0;i<9;i++)
        if((buf.st_mode >> (8-i))&1)
        perm[i+1]=rwx[i%3];
        for(i=0;i<3;i++)
        if((buf.st_mode >> (11-i))&1)
        if(perm[(i+1)*3]=='-')
        perm[(i+1)*3]=sst[i]^0x20;
        else
        perm[(i+1)*3]=sst[i];

        printf("%s  ",perm);
        printf("%ld  ",buf.st_nlink);
        pw=getpwuid(buf.st_uid);
        printf("%s  ",pw->pw_name);
        gr=getgrgid(buf.st_gid);
        printf("%s  ",gr->gr_name);
        printf("%ld  ",buf.st_size);
        tm=localtime(&buf.st_mtime);
        printf("%d - %02d - %02d  %02d : %02d :",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);
        printf("%-16s\t",p->d_name);
         if((i+1) %1 ==0)
          printf("\n");
             i++;
        }
        printf("\n");
        rewinddir(dp);
        while(p=readdir(dp))
        {

        stat(p->d_name,&buf);
        if(S_ISDIR(buf.st_mode))
        if(strcmp(p->d_name,".")&&strcmp(p->d_name,".."))
        myalR(p->d_name);
        }
        chdir("..");
        closedir(dp);
}


