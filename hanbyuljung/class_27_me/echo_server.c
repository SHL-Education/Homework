#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>



typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

#define BUF_SIZE	1024

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int i , str_len;
	int serv_sock, clnt_sock;

	char msg[BUF_SIZE];

	si serv_addr, clnt_addr;
	socklen_t clnt_addr_size;

	if(argc != 2)
	{
		printf("use:%s <port>\n", argv[0]);
		exit(1);
	}
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
		err_handler("socket(0 error");

	memset(&serv_addr , 0 , sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port= htons(atoi(argv[1]));

	if(bind(serv_sock, (sap) &serv_addr, sizeof(serv_addr)) == -1)
		err_handler("bind() error");
	// 받을 사람 수.
	if(listen(serv_sock, 5) == -1)
		err_handler("lister() error");

	clnt_addr_size = sizeof(clnt_addr);

	for(i = 0 ; i<5; i ++)
	{	// 실질적인 클라이언트  승인
		clnt_sock = accept(serv_sock , (struct sockaddr *)&clnt_addr, &clnt_addr_size);
		if(clnt_sock == -1)
			err_handler("accept() error");
		else
			printf("Connected Clinet %d\n", i +1);
		// read가 블록킹이라 글자가 전달이 안된다.
		while((str_len = read(clnt_sock, msg, BUF_SIZE)) !=0)
			write(clnt_sock , msg, str_len);
		
		close(clnt_sock);

	}
	close(serv_sock);

	return 0;
}
	






