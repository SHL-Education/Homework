#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>


typedef struct sockaddr_in	si;
typedef struct sockaddr *	sap;

#define BUF_SIZE		32

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

void read_routine(int sock , char *buf)
{
	for(;;){
		int str_len =read(sock , buf, BUF_SIZE);
		
		if(str_len == 0)
			return ;

		buf[str_len] = 0 ;
		printf("msg from server: %s", buf);
	}
}
void write_routine(int sock , char *buf)
{
	for(;;){
		fgets(buf, BUF_SIZE, stdin);
		if(!strcmp(buf, "q\n") || !strcmp(buf, "Q\n"))
		{
			shutdown(sock,SHUT_WR);
			return ;
		}
		write(sock, buf, strlen(buf));
	}
}
int main(int argc, char **argv)
{
	pid_t pid;
	int i, sock;
	si serv_addr;
	char buf[BUF_SIZE] = {0};

	if(argc != 3)
	{
		printf("use: %s <IP> <port>\n", argv[0]);
		exit(1);
	}


	if(sock == -1)
		err_handler("socket() error");

	sock = socket(PF_INET, SOCK_STREAM, 0);


	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	// 커넥트 하는 순간 어셉트가 동작한다.
	// 위에서 설정한 (포트와 주소 정보(serv_adr)) 를 가지고 connect를 시도한다.
	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");

	else
		puts("Connected .....");

	pid = fork();

	if(pid == 0)
		write_routine(sock , buf);
	else
		read_routine(sock, buf);

	close(sock);

	return 0;
}








