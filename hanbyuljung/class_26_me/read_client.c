#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

typedef struct sockaddr_in si;
typedef struct sockaddr * sap;

void err_handler(char *msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char **argv)
{
	int sock;
	int str_len = 0;
	si serv_addr;
	char msg[32] = {0};
	int idx = 0, read_len = 0;

	if(argc != 3)
	{
		printf("use: %s <IP> <port> \n", argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
	{
		err_handler("socket() error");
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (sap)&serv_addr, sizeof(serv_addr)) == -1)
		err_handler("connect() error");
	// 데이터가 끊기지 않게 할려고 쓴다.
	// 중간에 데이터가 우회하는것은 그래프 알고리즘이다.
	while(read_len = read(sock, &msg[idx++], 1))
	{
		if(read_len == -1){
			err_handler("read() error!");
			idx--; // 추가한 코드. 
		}

		str_len += read_len;
	}
	printf("msg from serv : %s\n", msg);
	printf("read conut : %d\n", str_len);
	return 0;
}
