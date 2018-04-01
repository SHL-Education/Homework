#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<fcntl.h>


typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE		1024
#define RLT_SIZE		4	
#define OPSZ			4


void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int i , sock, result,idx, nread;
	int str_len = 0;
	char opmsg[BUF_SIZE]= {0};
	char buf[BUF_SIZE] = {0};
	si serv_addr;
	if(argc != 3)
	{
		printf("use:%s <IP> <port>\n", argv[0]);
	}
	
	sock = socket(PF_INET , SOCK_STREAM, 0);

	if(sock == -1)
		err_handler("socket() error");

//	if( fcntl( sock, F_SETFL, O_NONBLOCK) == -1 ) 
//		 return -1;

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler(" connect() error");
	else
		puts("start button is 1, exit q");

	fcntl(sock, F_SETFL, O_NONBLOCK);

	for(;;)
	{
		// get은 write
		fgets(buf, BUF_SIZE, stdin);
		//read(1, buf, BUF_SIZE -1);
		
		
		if(!strcmp(buf, "q\n") || !strcmp(buf, "g\n"))
			break;
		
		write(sock, buf, strlen(buf));
		// read에서 블럭이 걸려버린다... 이걸 풀어주어야한다...
		nread = read(sock, buf, sizeof(buf));

		//if(nread == -1)
		//	err_handler("read() error!");

		//write(1, buf, strlen(buf));
		printf("msg from serv: %s\n", buf);
		// put은 read
		write(1, buf, strlen(buf));
		fputs("Input msg(q to quit) : \n", stdout);
	}

	close(sock);
	return 0;
}

